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

// sub_11E964 @ 0x11e964, size 242 bytes
float  sub_11E964(unsigned int a1)
{
  unsigned int v1; // r3
  int v2; // s15
  int v3; // r0
  float v4; // s15
  float v6; // s15
  float v7; // s13
  float v8; // s14
  uint8_t vars0[3]; // [sp+4h] [bp+0h]

  v1 = *(uint32_t *)vars0 & 0x7FFFFF;
  v2 = *(uint32_t *)vars0 & 0x7FFFFF;
  v3 = (uint8_t)(a1 >> 23);
  if ( (*(uint32_t *)vars0 & 0x7FFFFFu) >= 0x100000 )
  {
    if ( v1 >= 0x200000 )
    {
      if ( v1 < 0x300000 )
      {
        v4 = (float)((float)v2 * flt_11EA74) + flt_11EA78;
      }
      else if ( v1 >= 0x400000 )
      {
        v6 = (float)(unsigned int)v2;
        if ( v1 < 0x500000 )
        {
          v4 = (float)(v6 * sdio_buffer_prepare_n_130) + sdio_buffer_prepare_n_12c;
        }
        else if ( v1 >= 0x600000 )
        {
          if ( v1 >= 0x700000 )
            v7 = sdio_buffer_prepare_v2;
          else
            v7 = sdio_buffer_prepare_n_128;
          if ( v1 >= 0x700000 )
            v8 = rf_cmd_send_n_426_ea98;
          else
            v8 = sdio_buffer_prepare_n_120;
          v4 = (float)(v6 * v7) + v8;
        }
        else
        {
          v4 = (float)(v6 * flt_11EA7C) + sdio_buffer_prepare_n_134;
        }
      }
      else
      {
        v4 = (float)((float)v2 * flt_11EA6C) + flt_11EA70;
      }
    }
    else
    {
      v4 = (float)((float)v2 * flt_11EA64) + flt_11EA68;
    }
  }
  else
  {
    v4 = (float)((float)v2 * flt_11EA58) + flt_11EA5C;
  }
  return (float)(v3 - 127) + (float)(v4 * flt_11EA60);
}

