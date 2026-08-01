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

extern uint32_t off_129180;
extern uint32_t off_12918C;
extern uint32_t off_129188;
extern uint32_t dword_129190;
extern uint32_t off_129184;

// mfp_get_active @ 0x1290c8, size 184 bytes
void  mfp_get_active(uint16_t *a1, int16_t a2, int a3)
{
  uint8_t *v3; // r5
  uint16_t v4; // r6
  int v6; // r3
  int v7; // r1
  int v8; // r3
  int v9; // r3
  int v10; // r1

  v3 = off_129180;
  if ( *(uint8_t *)off_129180 )
  {
    v4 = *a1;
    if ( (a1[2] & 1) != 0 )
    {
      if ( *((uint8_t *)off_129180 + 29) == 5 )
      {
        mem_set_util((int)off_129180 + 12);
        v3[29] = 0;
      }
      if ( (v4 & 0x2000) == 0 || *(uint8_t *)(a3 + 114) )
      {
        *(uint32_t *)(a3 + 4) &= ~2u;
      }
      else
      {
        *(uint32_t *)(a3 + 4) |= 2u;
        if ( !v3[29] )
        {
          v9 = *((uint32_t *)off_12918C + 4);
          v10 = *(uint16_t *)(*(uint32_t *)off_129188 + 56);
          *((uint32_t *)v3 + 5) = a3;
          v3[29] = 5;
          mem_copy_util(dword_129190, v10 + v9);
        }
      }
    }
    else if ( *(uint8_t *)off_129184 )
    {
      adv_type_validate(a3, *a1, a1);
    }
    else if ( (a2 & 0x200) == 0 )
    {
      v6 = *((uint32_t *)off_12918C + 4);
      v7 = *(uint16_t *)(*(uint32_t *)off_129188 + 54);
      *((uint32_t *)off_129180 + 5) = a3;
      v3[29] = 2;
      mem_copy_util((int)(v3 + 12), v7 + v6);
      v8 = *(uint32_t *)(a3 + 4);
      if ( (v4 & 0x2000) != 0 )
      {
        if ( (v8 & 4) == 0 )
          *(uint32_t *)(a3 + 4) = v8 | 4;
        mfp_get_config();
      }
      else
      {
        *(uint32_t *)(a3 + 4) = v8 & 0xFFFFFFFB;
      }
    }
  }
}

