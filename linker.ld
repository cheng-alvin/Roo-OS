OUTPUT_FORMAT(binary)

ENTRY (_start)

INPUT
(
   ./build/obj/kernel_main.o  
   ./build/obj/idt.o 
   ./build/obj/sound_driver.o 
   ./build/obj/port_driver.o  
   ./build/obj/lib_ctypes.o  
   ./build/obj/screen_driver.o
   ./build/obj/kernel_entry.o 
)

OUTPUT
(
  ./build/kernel.bin
)

SECTIONS
{
    . = 0x1000;
    .text : ALIGN(0x1000)
    {
      .text = 0x1000;
    }

    .idt BLOCK(0x1000) : ALIGN(0x1000)
    {
      _idt = .;
      
    }
      .data : ALIGN(0x1000)
    {
      *(.data)
    }
}