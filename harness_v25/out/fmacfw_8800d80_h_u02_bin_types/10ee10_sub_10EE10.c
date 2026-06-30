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

extern uint32_t dword_10EFC0;
extern uint32_t dword_10EFC4;
extern uint32_t dword_10EFD0;
extern uint32_t dword_10EFCC;
extern uint32_t dword_10EFC8;
extern uint32_t dword_10EFD4;
extern uint32_t dword_10EFD8;
extern uint32_t dword_10EFDC;
extern uint32_t dword_10EFE0;
extern uint32_t dword_10EFE4;
extern uint32_t dword_10EFE8;
extern uint32_t dword_10EFEC;
extern uint32_t dword_10EFF0;
extern uint32_t dword_10EFF4;
extern uint32_t dword_10EFF8;
extern uint32_t dword_10F004;
extern uint32_t dword_10F000;
extern uint32_t dword_10EFFC;
extern uint32_t dword_10F008;
extern uint32_t dword_10F00C;
extern uint32_t dword_10F010;
extern uint32_t dword_10F014;
extern uint32_t dword_10F018;
extern uint32_t dword_10F01C;
extern uint32_t off_10F020;
extern uint32_t dword_10F028;
extern uint32_t dword_10F024;
extern uint32_t dword_10F030;
extern uint32_t dword_10F02C;
extern uint32_t dword_10F034;
extern uint32_t off_10F038;
extern uint32_t dword_10F03C;

// sub_10EE10 @ 0x10ee10, size 430 bytes
int sub_10EE10()
{
  int result; // r0

  sub_10ECEC(1879048192, 256, 264, 1);
  sub_10ECEC(dword_10EFC0, 0x8000000, 0x8000000, 1);
  sub_10ECEC(dword_10EFC4, 21, 31, 1);
  sub_10ECEC(dword_10EFD0, dword_10EFCC, dword_10EFC8, 1);
  sub_10ECEC(dword_10EFD4, 2560, 2560, 1);
  sub_10ECEC(dword_10EFD8, 255, 255, 1);
  sub_10ECEC(dword_10EFDC, 0, 100663296, 1);
  sub_10ECEC(dword_10EFE0, 0, 983040, 1);
  sub_10ECEC(dword_10EFE4, 96, 96, 1);
  sub_10ECEC(dword_10EFE8, 256, 256, 1);
  sub_10ECEC(dword_10EFEC, 469762048, 469762048, 1);
  sub_10ECEC(dword_10EFF0, 104, 252, 1);
  sub_10ECEC(dword_10EFF4, 6, 102, 1);
  sub_10ECEC(dword_10EFF8, 320, 992, 1);
  sub_10ECEC(dword_10F004, dword_10F000, dword_10EFFC, 1);
  sub_10ECEC(dword_10F008, 0x400000, 15728640, 1);
  sub_10ECEC(dword_10F00C, 16, 63, 1);
  sub_10ECEC(dword_10F010, 0, 60, 1);
  sub_10ECEC(dword_10F014, 0, 256, 1);
  sub_10ECEC(dword_10F018, 2048, 16128, 1);
  result = sub_10ECEC(dword_10F01C, 1, 1, 1);
  if ( **(uint8_t **)off_10F020 == 1 )
  {
    sub_10EC98(dword_10F028, dword_10F024, 1);
    sub_10EC98(dword_10F030, dword_10F02C, 1);
    sub_10ECEC(dword_10F01C, 0x100000, 0x100000, 1);
    result = sub_10ECEC(dword_10F034, 2, 31, 1);
    if ( !*((uint8_t *)off_10F038 + 375) )
    {
      sub_10ECEC(dword_10F03C, 1, 1, 1);
      sub_10ECEC(dword_10F014, 256, 256, 1);
      sub_10ECEC(dword_10F018, 0x2000, 16128, 1);
      sub_10ECEC(dword_10EFDC, 2359296, 16515072, 1);
      return sub_10ECEC(dword_10F01C, 256, 256, 1);
    }
  }
  return result;
}

