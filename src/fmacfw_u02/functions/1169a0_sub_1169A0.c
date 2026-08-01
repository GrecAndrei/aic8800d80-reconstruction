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

extern uint32_t dword_116AAC;
extern uint32_t dword_116A98;
extern uint32_t off_116A9C;
extern uint32_t dword_116AA8;
extern uint32_t dword_116AA4;
extern uint32_t off_116AB0;
extern uint32_t off_116AA0;

// radio_channel_validate @ 0x1169a0, size 248 bytes
int  radio_channel_validate(int result, int a2, int a3)
{
  int v4; // r6
  int *v6; // r5
  int v7; // r2
  int v8; // r3
  void *v9; // r8
  int v10; // r3
  int v11; // r2
  int v12; // r2

  v4 = result;
  if ( a3 == 5 )
    v6 = (int *)dword_116AAC;
  else
    v6 = (int *)(dword_116A98 + 84 * a3);
  v7 = *v6;
  v8 = **(int16_t **)off_116A9C;
  if ( v8 < 0 && v7 == result )
    return bad_func_0x12f408(dword_116AA8, dword_116AA4, 1972, v8);
  if ( v7 )
  {
    v9 = off_116AB0;
    v10 = *(uint8_t *)(*(uint32_t *)off_116AB0 + 1);
    if ( *(uint8_t *)(*(uint32_t *)off_116AB0 + 1) || !v6[2] )
      *(uint32_t *)(v7 + 4) = result;
    else
      *(uint32_t *)(v6[1] + 4) = result;
    if ( a3 == 5
      || !*((uint8_t *)off_116AA0 + 28 * a3 + 46)
      && ((v11 = *((uint32_t *)off_116AA0 + 52), result = v11 << 31, (v11 & 1) == 0)
       || *((uint8_t *)off_116AA0 + 190) != a3) )
    {
      result = dispatch_config_command(a3);
      v10 = *(uint8_t *)(*(uint32_t *)v9 + 1);
    }
  }
  else if ( a3 != 5
         && ((v8 = (int)off_116AA0, v7 = 8 * a3, *((uint8_t *)off_116AA0 + 28 * a3 + 46))
          || (result = *((uint8_t *)off_116AA0 + 190), (*((uint32_t *)off_116AA0 + 52) & 1) != 0) && a3 == result) )
  {
    v12 = *(uint32_t *)off_116AB0;
    *((uint32_t *)off_116AA0 + 7 * a3 + 9) = v4;
    v10 = *(uint8_t *)(v12 + 1);
  }
  else
  {
    result = radio_band_validate(v4, a3, v7, v8);
    v10 = *(uint8_t *)(*(uint32_t *)off_116AB0 + 1);
  }
  if ( !v10 )
  {
    if ( (*(uint32_t *)(a2 + 56) & 0x200000) != 0 )
    {
      v6[1] = v4;
      v6[2] = 1;
    }
    else
    {
      v6[1] = 0;
      v6[2] = 0;
    }
  }
  *(uint32_t *)(dword_116A98 + 84 * a3) = a2;
  return result;
}

