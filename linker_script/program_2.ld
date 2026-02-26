ENTRY(entry_program2)

MEMORY {                                             
  flash(rx) : ORIGIN = 0x08008000, LENGTH = 1M
  SRAM(rwx) : ORIGIN = 0x20000000, LENGTH = 300K
}

PROVIDE(__app_start__ = ORIGIN(flash));
PROVIDE(__app_vector__ = ORIGIN(flash));

_estack = ORIGIN(SRAM) + LENGTH(SRAM);

SECTIONS {
  .isr_vector :
  {
    KEEP(*(.isr_vector))
  } > flash

  .text : ALIGN(4) {
    *(.literal*) 
    *(.text*)
  } > flash

  .data : ALIGN(4) {
    _sdata = .;
    *(.data*)
    _edata = .;
  } > SRAM

  .bss : ALIGN(4) {
    _sbss = .;
    *(.bss*)
    *(COMMON)
    _ebss = .;
  } > SRAM
}
