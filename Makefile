ASM=nasm 
SRC_DIR=./src
BUILD_DIR=./build
LINKER=x86_64-elf-ld
CC=x86_64-elf-gcc
CPPC=x86_64-elf-g++

all-roo:
	@make clean
	@make bootloader
	@make kernel
	@make link
	@make merge

bootloader:
	@echo "Building bootloader..."
	@${ASM} -f bin ${SRC_DIR}/bootloader/boot.asm  -o ${BUILD_DIR}/boot.bin -i ${SRC_DIR}/bootloader
	@echo "Bootloader built."

run:
	@echo "Running..."
	@qemu-system-x86_64 -fda ${BUILD_DIR}/os.bin -serial file:${BUILD_DIR}/serial.log -soundhw pcspk

debug:
	@echo "Running..."
	@qemu-system-x86_64 -s -S -fda ${BUILD_DIR}/os.bin -serial file:${BUILD_DIR}/serial.log -soundhw pcspk

kernel:
	@echo "Building kernel..."
	@${CC} -ffreestanding -c ${SRC_DIR}/kernel/kernel.c -o ${BUILD_DIR}/obj/kernel_main.o
	@${CC} -ffreestanding -c ${SRC_DIR}/kernel/drivers/screen.c -o ${BUILD_DIR}/obj/screen_driver.o
	@${CC} -ffreestanding -c ${SRC_DIR}/kernel/drivers/mem.c -o ${BUILD_DIR}/obj/mem_driver.o 
	@${CC} -ffreestanding -c ${SRC_DIR}/kernel/drivers/port.c -o ${BUILD_DIR}/obj/port_driver.o
	@${CC} -ffreestanding -c ${SRC_DIR}/kernel/interrupt/idt.c -o ${BUILD_DIR}/obj/idt.o
	@${CC} -ffreestanding -c ${SRC_DIR}/kernel/lib/ctypes.c -o ${BUILD_DIR}/obj/lib_ctypes.o   
	@${CC} -ffreestanding -c ${SRC_DIR}/kernel/drivers/sound.c -o ${BUILD_DIR}/obj/sound_driver.o   
	@${ASM} ${SRC_DIR}/kernel/kernel_entry.asm -f elf64 -o ${BUILD_DIR}/obj/kernel_entry.o -i ${SRC_DIR}/kernel
	@echo "Kernel built."

clean:
	@echo "Cleaning..."
	@rm -rf ${BUILD_DIR}/
	@mkdir ${BUILD_DIR}/
	@mkdir ${BUILD_DIR}/obj/
	@echo "Cleaned."

link:	
	@echo "Linking..."
	@${LINKER} -T"linker.ld" 
	@echo "Linked."

merge:
	@echo "Merging binaries..."
	@cat ${BUILD_DIR}/boot.bin ${BUILD_DIR}/kernel.bin > ${BUILD_DIR}/os.bin
	@echo "Binaries merged."

dump_kernel:
	@echo "Dumping kernel..."
	@ndisasm -b 32 ${BUILD_DIR}/kernel.bin
	@echo "Kernel dumped."

dump_bootsector:
	@echo "Dumping bootsector..."
	@ndisasm -b 32 ${BUILD_DIR}/boot.bin
	@echo "bootsector dumped."

dump_all:
	@echo "Dumping All..."
	@ndisasm -b 32 ${BUILD_DIR}/os.bin
	@echo "All dumped."
