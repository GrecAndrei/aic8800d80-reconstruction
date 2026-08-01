#include <stdint.h>
#include <stddef.h>
#include <stdarg.h>
#include <inttypes.h>

#define LOBYTE(x) ((uint8_t)((x) & 0xFF))
#define HIBYTE(x) ((uint8_t)(((x) >> 8) & 0xFF))
#define LOWORD(x) ((uint16_t)((x) & 0xFFFF))
#define HIWORD(x) ((uint16_t)(((x) >> 16) & 0xFFFF))
#define LODWORD(x) ((uint32_t)(x))
#define HIDWORD(x) ((uint32_t)(((uint64_t)(x) >> 32)))

extern uint32_t dword_10EF58;
extern uint32_t dword_10EF5C;
extern uint32_t dword_10EF68;
extern uint32_t dword_10EF64;
extern uint32_t dword_10EF60;
extern uint32_t dword_10EF6C;
extern uint32_t dword_10EF70;
extern uint32_t dword_10EF74;
extern uint32_t dword_10EF78;
extern uint32_t dword_10EF7C;
extern uint32_t dword_10EF80;
extern uint32_t dword_10EF84;
extern uint32_t dword_10EF88;
extern uint32_t dword_10EF8C;
extern uint32_t dword_10EF90;
extern uint32_t dword_10EF9C;
extern uint32_t dword_10EF98;
extern uint32_t dword_10EF94;
extern uint32_t dword_10EFA0;
extern uint32_t dword_10EFA4;
extern uint32_t dword_10EFA8;
extern uint32_t dword_10EFAC;
extern uint32_t dword_10EFB0;
extern uint32_t dword_10EFB4;
extern uint32_t off_10EFB8;
extern uint32_t dword_10EFC0;
extern uint32_t dword_10EFBC;
extern uint32_t dword_10EFC8;
extern uint32_t dword_10EFC4;
extern uint32_t dword_10EFCC;
extern uint32_t off_10EFD0;
extern uint32_t dword_10EFD4;

// periph_enable @ 0x10eda8, size 430 bytes
int periph_enable()
{
  int result; // r0

  atomic_reg_write(1879048192, 256, 264, 1);
  atomic_reg_write(dword_10EF58, 0x8000000, 0x8000000, 1);
  atomic_reg_write(dword_10EF5C, 21, 31, 1);
  atomic_reg_write(dword_10EF68, dword_10EF64, dword_10EF60, 1);
  atomic_reg_write(dword_10EF6C, 2560, 2560, 1);
  atomic_reg_write(dword_10EF70, 255, 255, 1);
  atomic_reg_write(dword_10EF74, 0, 100663296, 1);
  atomic_reg_write(dword_10EF78, 0, 983040, 1);
  atomic_reg_write(dword_10EF7C, 96, 96, 1);
  atomic_reg_write(dword_10EF80, 256, 256, 1);
  atomic_reg_write(dword_10EF84, 469762048, 469762048, 1);
  atomic_reg_write(dword_10EF88, 104, 252, 1);
  atomic_reg_write(dword_10EF8C, 6, 6, 1);
  atomic_reg_write(dword_10EF90, 320, 992, 1);
  atomic_reg_write(dword_10EF9C, dword_10EF98, dword_10EF94, 1);
  atomic_reg_write(dword_10EFA0, 0x400000, 15728640, 1);
  atomic_reg_write(dword_10EFA4, 16, 63, 1);
  atomic_reg_write(dword_10EFA8, 0, 60, 1);
  atomic_reg_write(dword_10EFAC, 0, 256, 1);
  atomic_reg_write(dword_10EFB0, 2048, 16128, 1);
  result = atomic_reg_write(dword_10EFB4, 1, 1, 1);
  if ( **(uint8_t **)off_10EFB8 == 1 )
  {
    atomic_reg_read_alt(dword_10EFC0, dword_10EFBC, 1);
    atomic_reg_read_alt(dword_10EFC8, dword_10EFC4, 1);
    atomic_reg_write(dword_10EFB4, 0x100000, 0x100000, 1);
    result = atomic_reg_write(dword_10EFCC, 2, 31, 1);
    if ( !*((uint8_t *)off_10EFD0 + 375) )
    {
      atomic_reg_write(dword_10EFD4, 1, 1, 1);
      atomic_reg_write(dword_10EFAC, 256, 256, 1);
      atomic_reg_write(dword_10EFB0, 0x2000, 16128, 1);
      atomic_reg_write(dword_10EF74, 2359296, 16515072, 1);
      return atomic_reg_write(dword_10EFB4, 256, 256, 1);
    }
  }
  return result;
}

