ENTRY(entry_program2)

MEMORY {                                             
  code (rx) : ORIGIN = 0x10000000, LENGTH = 0x10000
  sram  (rx) : ORIGIN = 0x20000000, LENGTH = 0x20000
  peripherals (rx) : ORIGIN = 0x40010000, LENGTH = 0x1000

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
