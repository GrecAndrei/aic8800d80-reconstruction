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

extern uint32_t dword_122A60;
extern uint32_t off_122A50;
extern uint32_t dword_122A5C;
extern uint32_t dword_122A58;
extern uint32_t dword_122A54;

// sub_1229BC @ 0x1229bc, size 148 bytes
int  sub_1229BC(int a1, int a2, int a3, int a4)
{
  int v4; // r9
  int v6; // r5
  int v9; // r8
  char v10; // r1
  int v11; // r2

  v4 = dword_122A60;
  v6 = *(uint8_t *)(a2 + 5);
  if ( **(int16_t **)off_122A50 < 0 && *(uint8_t *)(dword_122A60 + 1320 * v6 + 106) )
    sub_12F46C(dword_122A5C, dword_122A58, 2660);
  v9 = v4 + 1320 * v6;
  v10 = *(uint8_t *)(a2 + 4);
  v11 = *(uint8_t *)(v9 + 149);
  *(uint32_t *)(v9 + 1228) = *(uint32_t *)a2;
  *(uint8_t *)(v9 + 1227) = v10;
  if ( v11 == 1 )
  {
    timestamp_remove(1320 * v6 + 152 + v4);
    *(uint8_t *)(v9 + 149) = 0;
  }
  feature_guard_check(256, dword_122A54);
  sub_12CA10(98, a4, a3);
  return 0;
}

