ENTRY(entry_program3)

MEMORY {                                             
  code (rx) : ORIGIN = 0x10050000, LENGTH = 0x10000
  sram  (rwx) : ORIGIN = 0x20040000, LENGTH = 0x20000
}

SECTIONS {
  .text : ALIGN(4) {
    *(.literal*) 
    *(.text*)
  } > code

  .data : ALIGN(4) {
    *(.data*)
  } > sram

  .bss : ALIGN(4) {
    *(.bss*)
  } > sram
}
