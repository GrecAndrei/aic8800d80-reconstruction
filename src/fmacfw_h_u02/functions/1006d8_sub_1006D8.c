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

// mmio_write_cmd @ 0x1006d8, size 78 bytes
void  mmio_write_cmd()
{
  volatile unsigned int v0; // r0
  unsigned int v1; // r0
  int v3; // r2
  volatile unsigned int v4; // r1
  unsigned int v5; // r1
  int v7; // r3
  int v8; // [sp+0h] [bp-Ch]
  int v9; // [sp+4h] [bp-8h]

  *(uint32_t *)dword_100728 = 17;
  v0 = (*(volatile uint32_t *)0x40501010u);
  v1 = v0 + 10;
  do
  {
    v8 = 32;
    while ( v8-- )
      ;
    v3 = (*(volatile uint32_t *)0x40501010u) - v1;
  }
  while ( v3 < 0 );
  *(uint32_t *)dword_100728 = 0;
  v4 = (*(volatile uint32_t *)0x40501010u);
  v5 = v4 + 10;
  do
  {
    v9 = 32;
    while ( v9-- )
      ;
    v7 = (*(volatile uint32_t *)0x40501010u) - v5;
  }
  while ( v7 < 0 );
}
