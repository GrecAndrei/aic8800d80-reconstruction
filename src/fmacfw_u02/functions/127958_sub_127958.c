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

extern uint32_t dword_127A18;
extern uint32_t off_127A14;

// sta_get_flags @ 0x127958, size 186 bytes
int  sta_get_flags(int result, int16_t a2)
{
  int v2; // r8
  int v3; // r7
  int v4; // r5
  int v5; // r9
  int v6; // r4
  int v8; // r2
  uint16_t v9; // r3
  int v10; // r3
  int v11; // r2
  int v12; // r7
  char v13; // r2

  v2 = dword_127A18;
  v3 = *(uint8_t *)(result + 86);
  v4 = dword_127A18 + 1320 * v3;
  v5 = *(uint8_t *)(v4 + 85) & 0x60;
  if ( (*(uint8_t *)(v4 + 85) & 0x60) == 0 )
  {
    v6 = result;
    result = bt_runtime_check2(dword_127A18 + 1320 * v3, *(uint8_t *)(result + 87));
    v8 = *(uint32_t *)(v6 + 92);
    v9 = abs16(v8 - (result - a2));
    *(uint16_t *)(v6 + 96) = v8 - (result - a2);
    if ( v9 > 0x7D0u )
    {
      *(uint8_t *)(v4 + 85) = *(uint8_t *)(v4 + 85) & 0xAF | 0x10;
      return result;
    }
    if ( v9 > 0xC8u )
    {
      v10 = *((uint32_t *)off_127A14 + 2);
      if ( !v10 )
      {
LABEL_16:
        v12 = v2 + 1320 * v3;
        v13 = *(uint8_t *)(v12 + 85);
        *(uint32_t *)(v12 + 88) = v10;
        *(uint8_t *)(v12 + 85) = v13 | 0x40;
        return result;
      }
      result = 0;
      do
      {
        if ( *(uint8_t *)(v10 + 86) == *(uint8_t *)(v4 + 107) )
        {
          v11 = *(int16_t *)(v10 + 96);
          if ( result >= v11 )
            result = *(int16_t *)(v10 + 96);
          if ( v5 < v11 )
            v5 = *(int16_t *)(v10 + 96);
        }
        v10 = *(uint32_t *)v10;
      }
      while ( v10 );
      if ( !result )
      {
        v10 = v5 >> 1;
        goto LABEL_16;
      }
      if ( !v5 )
      {
        v10 = result / 2;
        goto LABEL_16;
      }
    }
  }
  return result;
}

