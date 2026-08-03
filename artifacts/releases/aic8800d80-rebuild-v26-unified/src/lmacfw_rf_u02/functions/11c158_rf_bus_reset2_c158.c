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

extern uint32_t off_11C260;
extern uint32_t dword_11C268;
extern uint32_t off_11C264;

// rf_bus_reset2_c158 @ 0x11c158, size 264 bytes
// Doc: rf_bus_reset2_c158 [rf]: Tear down RF bus state and trigger secondary reset sequence
// rf_bus_reset2_c158 [rf]: Tear down RF bus state and trigger secondary reset sequence
int  rf_bus_reset2_c158(int result)
{
  void *v1; // r5
  int v2; // r4
  int v3; // r3
  int v4; // r6
  int v5; // r7
  char v6; // r3
  char v7; // r2
  int v8; // r8
  int v9; // r2
  int v10; // r3
  char v11; // r2

  v1 = off_11C260;
  v2 = result;
  v3 = *(uint8_t *)(result + 85);
  if ( *((uint8_t *)off_11C260 + 90) <= 1u )
  {
    if ( (v3 & 2) != 0 )
    {
      v3 &= 0xFDu;
      *(uint8_t *)(result + 85) = v3;
      v11 = *((uint8_t *)v1 + 91) - 1;
      *((uint8_t *)v1 + 91) = v11;
      if ( !v11 && (*((uint8_t *)v1 + 88) & 0x40) != 0 )
      {
        rf_mailbox_post_n44(*((uint32_t *)v1 + 20));
        v3 = *(uint8_t *)(v2 + 85);
      }
    }
    if ( (v3 & 4) != 0 )
    {
      v3 &= 0xFBu;
      *(uint8_t *)(v2 + 85) = v3;
    }
    result = v3 << 26;
    if ( (v3 & 0x20) != 0 )
      *(uint8_t *)(v2 + 85) = v3 & 0xDF;
  }
  else
  {
    v4 = v3 & 4;
    v5 = *(uint32_t *)(result + 36);
    if ( (v3 & 4) != 0 )
    {
      if ( (v3 & 1) == 0 )
      {
        result = rf_cal_or_init_handler(result, *(uint32_t *)(result + 36), 0);
        LOBYTE(v3) = *(uint8_t *)(v2 + 85);
      }
      *(uint8_t *)(v2 + 85) = v3 & 0xFB;
    }
    else if ( (v3 & 2) != 0 )
    {
      v6 = v3 & 0xFD;
      *(uint8_t *)(result + 85) = v6;
      v7 = *((uint8_t *)v1 + 91) - 1;
      *((uint8_t *)v1 + 91) = v7;
      if ( !v7 )
      {
        if ( (*((uint8_t *)v1 + 88) & 0x40) != 0 )
        {
          result = rf_mailbox_post_n44(*((uint32_t *)v1 + 20));
          v6 = *(uint8_t *)(v2 + 85);
        }
        else
        {
          v4 = 1;
        }
      }
      v8 = *(uint32_t *)(v2 + 80);
      if ( (v6 & 8) != 0 )
      {
        v9 = *(uint8_t *)(v2 + 94);
        *(uint8_t *)(v2 + 85) = v6 & 0xF7;
        if ( v9 )
          v10 = 102400;
        else
          v10 = *(uint32_t *)(dword_11C268 + 152 * *(uint8_t *)(v2 + 102) + 8);
        v8 -= v10;
      }
      else
      {
        result = rf_cal_or_init_handler(v2, v5, 0);
      }
      if ( v4 )
      {
        if ( !*((uint32_t *)v1 + 11) )
          return sub_11B088(v2, *((uint32_t *)off_11C264 + 4), *((uint32_t *)off_11C264 + 4) - v8);
      }
    }
  }
  return result;
}

