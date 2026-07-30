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

extern uint32_t off_123A24;
extern uint32_t dword_123A20;
extern uint32_t dword_123A1C;

// sub_123954 @ 0x123954, size 182 bytes
void  __noreturn sub_123954(int a1, int a2, int a3)
{
  int v3; // r0
  int v4; // [sp+10h] [bp-18h]
  int v5; // [sp+14h] [bp-14h]
  int v6; // [sp+18h] [bp-10h]
  int v7; // [sp+1Ch] [bp-Ch]
  int v8; // [sp+20h] [bp-8h]
  int v9; // [sp+24h] [bp-4h]

  v3 = **(int16_t **)off_123A24;
  v4 = 0;
  v5 = 0;
  v6 = 0;
  v7 = 0;
  v8 = 0;
  v9 = 0;
  if ( v3 < 0 )
  {
    if ( sub_12CD48(a3) )
      sub_12F32C(dword_123A20, dword_123A1C, 337);
  }
  sub_102934();
}

