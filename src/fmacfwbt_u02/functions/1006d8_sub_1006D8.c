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


extern uint32_t dword_100728;

// clock_start @ 0x1006d8, size 78 bytes
int clock_start()
{
  volatile unsigned int v0; // r0
  unsigned int v1; // r0
  int v3; // r2
  volatile unsigned int v4; // r1
  int result; // r0
  unsigned int v6; // r1
  int v8; // r3
  int v9; // [sp+0h] [bp-Ch]
  int v10; // [sp+4h] [bp-8h]

  *(uint32_t *)dword_100728 = 17;
  v0 = (*(volatile uint32_t *)0x40501010u);
  v1 = v0 + 10;
  do
  {
    v9 = 32;
    while ( v9-- )
      ;
    v3 = (*(volatile uint32_t *)0x40501010u) - v1;
  }
  while ( v3 < 0 );
  *(uint32_t *)dword_100728 = 0;
  v4 = (*(volatile uint32_t *)0x40501010u);
  result = 32;
  v6 = v4 + 10;
  do
  {
    v10 = 32;
    while ( v10-- )
      ;
    v8 = (*(volatile uint32_t *)0x40501010u) - v6;
  }
  while ( v8 < 0 );
  return result;
}
