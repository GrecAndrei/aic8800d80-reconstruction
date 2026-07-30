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

extern uint32_t off_1153E8;
extern uint32_t dword_1153F0;
extern uint32_t dword_1153EC;

// sub_11538C @ 0x11538c, size 90 bytes
int  sub_11538C(int result)
{
  uint64_t v1; // kr00_8
  int v2; // r2
  int v3; // r3
  int v4; // r2
  unsigned int v5; // r3
  int v6; // r3

  v1 = *(uint64_t *)(result + 28);
  v2 = *(uint32_t *)(HIDWORD(v1) + 24);
  v3 = *(uint32_t *)(v1 + 96);
  *(uint32_t *)(HIDWORD(v1) + 60) = v3;
  *(uint32_t *)(HIDWORD(v1) + 44) = v1 + 44;
  if ( !v2 )
  {
    v4 = *(uint32_t *)(HIDWORD(v1) + 20);
    if ( **(int16_t **)off_1153E8 < 0 && !v4 )
    {
      result = rf_cmd_send_n264(dword_1153F0, dword_1153EC, 525);
      v4 = *(uint32_t *)(HIDWORD(v1) + 20);
      v3 = *(uint32_t *)(HIDWORD(v1) + 60);
    }
    v2 = *(uint32_t *)(v4 + 8);
  }
  v5 = v3 & 0xFFFFF9FF;
  *(uint32_t *)(HIDWORD(v1) + 60) = v5;
  if ( (*(uint8_t *)(v2 + 4) & 1) == 0 )
    *(uint32_t *)(HIDWORD(v1) + 60) = v5 | 0x200;
  v6 = *(uint32_t *)(v1 + 48);
  *(uint32_t *)(HIDWORD(v1) + 40) = *(uint32_t *)(v1 + 100);
  *(uint32_t *)(v1 + 48) = v6 | 2;
  return result;
}

