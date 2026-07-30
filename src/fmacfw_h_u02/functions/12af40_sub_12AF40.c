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

extern uint32_t dword_12AFC0;
extern uint32_t off_12AFC4;
extern uint32_t dword_12AFD0;
extern uint32_t dword_12AFCC;
extern uint32_t off_12AFC8;

// sub_12AF40 @ 0x12af40, size 124 bytes
int  sub_12AF40(int a1, int a2, int a3, int a4)
{
  int16_t v4; // r6
  uint8_t *v6; // r4
  uint8_t *v7; // r2

  v4 = a4;
  v6 = (uint8_t *)sub_12C7EC(2049, a4, a3, 1);
  sub_12CD48(2);
  sub_12EB90(4, dword_12AFC0);
  if ( sub_12CD48(2) )
  {
    *v6 = 8;
    sub_12C84C(v6);
    return 0;
  }
  else
  {
    if ( **(int16_t **)off_12AFC4 < 0 && !*(uint8_t *)(a2 + 367) )
      sub_12F32C(dword_12AFD0, dword_12AFCC, 73);
    v7 = off_12AFC8;
    *v6 = 0;
    *(uint32_t *)v7 = a2;
    v7[10] = 0;
    *((uint16_t *)v7 + 4) = v4;
    sub_12B138(a2);
    sub_12C84C(v6);
    return 1;
  }
}

