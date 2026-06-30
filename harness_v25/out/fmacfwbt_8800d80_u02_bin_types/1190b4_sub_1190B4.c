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

extern uint32_t off_119114;
extern uint32_t dword_11911C;
extern uint32_t dword_119118;

// sub_1190B4 @ 0x1190b4, size 94 bytes
int  sub_1190B4(int a1, int a2)
{
  uint64_t v2; // kr00_8
  int v3; // r2
  int v6; // r12
  int v7; // r3
  char v8; // r2

  v2 = *(uint64_t *)(a1 + 72);
  v3 = *(uint32_t *)(HIDWORD(v2) + 28);
  if ( **(int16_t **)off_119114 < 0 && (v3 & 1) != 0 )
  {
    sub_12F694(dword_11911C, dword_119118, 389);
    v3 = *(uint32_t *)(HIDWORD(v2) + 28);
  }
  v6 = *(uint32_t *)(HIDWORD(v2) + 44);
  *(uint32_t *)(HIDWORD(v2) + 68) &= 0xFF87FFFF;
  v7 = 0;
  *(uint64_t *)(HIDWORD(v2) + 16) = 0;
  v8 = *(uint8_t *)(v3 + 4);
  *(uint32_t *)(HIDWORD(v2) + 72) = 0;
  if ( (v8 & 1) == 0 )
    v7 = 512;
  *(uint32_t *)(HIDWORD(v2) + 64) = v7;
  *(uint32_t *)(v2 + 96) = v7;
  *(uint32_t *)(v2 + 100) = v6;
  return cmd_dispatch_handler(a1, a2);
}

