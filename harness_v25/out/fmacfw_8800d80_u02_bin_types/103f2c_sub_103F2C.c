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

extern uint32_t off_103F88;
extern uint32_t off_103F84;
extern uint32_t dword_103F8C;
extern uint32_t dword_103F90;
extern uint32_t off_103F98;
extern uint32_t dword_103F9C;
extern uint32_t off_103FA0;
extern uint32_t off_103F94;
extern uint32_t dword_103FA4;

// sub_103F2C @ 0x103f2c, size 86 bytes
int sub_103F2C()
{
  int v0; // r2
  int *v1; // r4
  int v2; // r0
  int v3; // r1
  int v4; // r2
  int *v5; // r3
  int v6; // r1
  uint32_t *v7; // r2
  int v8; // r0

  v0 = 777;
  v1 = (int *)off_103F88;
  *(uint32_t *)off_103F84 = 777;
  while ( *v1 < 0 )
    delay_us_0644(1);
  msg_parse(dword_103F8C, *(uint32_t *)off_103F88, v0);
  v2 = dword_103F90;
  *(uint32_t *)off_103F84 = 0;
  msg_parse(v2, v3, v4);
  v5 = (int *)off_103F98;
  v6 = dword_103F9C;
  v7 = off_103FA0;
  *(uint32_t *)off_103F94 = 0;
  *v5 = v6;
  v8 = dword_103FA4;
  *v7 &= 0xFF00FFFF;
  return msg_parse(v8, 0x4000, v7);
}

