ENTRY(entry_program3)

MEMORY {                                             
  code (rx) : ORIGIN = 0x10050000, LENGTH = 0x10000
  sram  (rx) : ORIGIN = 0x20040000, LENGTH = 0x20000
  peripherals (rx) : ORIGIN = 0x40012000, LENGTH = 0x1000

}

SECTIONS {
  .text : ALIGN(4) {
    *(.literal*) 
    *(.text*)
  } > code

  .data : ALIGN(4) {
    *(.data*)
  } > sram
}
