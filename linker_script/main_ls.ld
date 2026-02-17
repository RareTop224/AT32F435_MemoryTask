ENTRY(entry_program2)

MEMORY {                                             
  flash (rx) : ORIGIN = 0x08000000, LENGTH = 1M
  SRAM (rwx) : ORIGIN = 0x20000000, LENGTH = 300K
}

_estack = LENGTH(SRAM) + ORIGIN(SRAM);

SECTIONS {
  .isr_vector : {
  KEEP(*(.isr_vector))
  } > flash

  .text : ALIGN(4) {
    *(.literal*) 
    *(.text*)
  } > flash

  .data : ALIGN(4) {
    *(.data*)
  } > SRAM AT > flash

  .bss : ALIGN(4) {
    *(.bss*)
  } > SRAM 
}
