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

extern uint32_t off_10395C;
extern uint32_t off_103958;
extern uint32_t dword_103960;
extern uint32_t dword_103964;
extern uint32_t off_10396C;
extern uint32_t dword_103970;
extern uint32_t off_103974;
extern uint32_t off_103968;
extern uint32_t dword_103978;

// sub_103900 @ 0x103900, size 86 bytes
int sub_103900()
{
  int *v0; // r4
  int v1; // r0
  int v2; // r1
  int *v3; // r3
  int v4; // r1
  uint32_t *v5; // r2
  int v6; // r0

  v0 = (int *)off_10395C;
  *(uint32_t *)off_103958 = 777;
  while ( *v0 < 0 )
    sub_100560(1);
  sub_11F504(dword_103960, *(uint32_t *)off_10395C);
  v1 = dword_103964;
  *(uint32_t *)off_103958 = 0;
  sub_11F504(v1, v2);
  v3 = (int *)off_10396C;
  v4 = dword_103970;
  v5 = off_103974;
  *(uint32_t *)off_103968 = 0;
  *v3 = v4;
  v6 = dword_103978;
  *v5 &= 0xFF00FFFF;
  return sub_11F504(v6, 0x4000);
}

