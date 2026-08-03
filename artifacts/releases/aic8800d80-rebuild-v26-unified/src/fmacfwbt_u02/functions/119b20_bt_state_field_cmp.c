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

extern uint32_t dword_119CA0;
extern uint32_t dword_119CB0;
extern uint32_t off_119CA8;
extern uint32_t off_119CA4;
extern uint32_t off_119CAC;

// bt_state_field_cmp @ 0x119b20, size 384 bytes
// Doc: bt_state_field_cmp [bt]: Compare state/version byte fields between two contexts
// bt_state_field_cmp [bt]: Compare state/version byte fields between two contexts
int  bt_state_field_cmp(int a1, int a2, int a3)
{
  unsigned int v3; // r7
  int result; // r0
  int v7; // r3
  int v8; // r6
  int v9; // nf
  int16_t v10; // r3
  int v11; // r1
  int v12; // r9
  int v13; // r7
  int v14; // r2
  int v15; // r8
  int v16; // r10
  int v17; // r0
  int v18; // r3
  int v19; // r2
  int v20; // r1
  int v21; // r1
  uint32_t *v22; // r2
  int16_t v23; // r3
  int v24; // r2
  char v25; // r3

  if ( *(uint8_t *)(a1 + 29) != *(uint8_t *)(a2 + 29)
    || *(uint8_t *)(a1 + 27) != *(uint8_t *)(a2 + 27) )
  {
    return 0;
  }
  v7 = *(uint32_t *)(a1 + 36);
  v8 = *(uint32_t *)(a2 + 68);
  v9 = (v7 & 0x200000) != 0;
  if ( (v7 & 0x200000) != 0 )
    v7 = *(uint32_t *)(a1 + 68);
  else
    v3 = *(uint16_t *)(a1 + 80);
  if ( v9 )
    v3 = *(uint16_t *)(v7 + 10);
  v10 = *(uint16_t *)(v8 + 8);
  if ( (v10 & 6) == 4 )
    return 0;
  if ( v3 <= 0xE78 )
  {
    result = v10 & 2;
    if ( (v10 & 2) == 0 )
    {
      v11 = *(uint32_t *)(v8 + 264);
      if ( v11 )
      {
        if ( *(uint32_t *)(v11 + 16) != dword_119CA0 || (int)(v3 + *(uint16_t *)(v8 + 10)) <= 3704 )
          return result;
        goto LABEL_16;
      }
      return 0;
    }
  }
LABEL_16:
  result = v10 & 1;
  if ( (v10 & 1) != 0 )
  {
    result = *(uint16_t *)(*(uint32_t *)(v8 + 324) + 82) & 1;
    if ( result )
    {
      *(uint16_t *)(v8 + 8) = v10 | 6;
      return 1;
    }
  }
  else
  {
    v12 = dword_119CB0;
    v13 = dword_119CB0 + 84 * a3;
    v14 = *(uint8_t *)(v13 + 77);
    if ( v14 != 1 )
    {
      v15 = *(uint32_t *)(v13 + 52);
      if ( (*(uint16_t *)(v15 + 82) & 1) != 0 )
      {
        if ( (*(uint32_t *)off_119CA8 & 0x3F) > *(uint8_t *)(*(uint32_t *)off_119CA4 + 62)
                                            + *(uint8_t *)(*(uint32_t *)off_119CA4 + 63) )
        {
          v16 = *(uint32_t *)(v15 + 76);
          *(uint8_t *)(v16 + 1) = v14;
          v17 = *(uint32_t *)(v13 + 48);
          *(uint32_t *)(v15 + 36) |= 0x380000u;
          *(uint32_t *)(v8 + 324) = v15;
          sub_11C990(v17);
          v18 = *(uint8_t *)(*(uint32_t *)off_119CAC + 1);
          if ( *(uint8_t *)(*(uint32_t *)off_119CAC + 1) )
          {
            sub_1197FC(
              v8,
              *(uint16_t *)(v15 + 34),
              *(uint8_t *)(v8 + 12),
              *(uint8_t *)(v8 + 13),
              *(uint8_t *)(v13 + 78));
            *(uint32_t *)(v16 + 20) = v8 + 84;
          }
          else
          {
            v19 = *(uint32_t *)(a1 + 76);
            *(uint32_t *)(v8 + 20) = v18;
            v20 = *(uint32_t *)(v19 + 68) << 10;
            *(uint32_t *)(v16 + 16) = v18;
            *(uint32_t *)(v16 + 20) = v18;
            if ( v20 >= 0 )
            {
              v21 = v8 + 16;
              *(uint32_t *)(v19 + 16) = v8 + 16;
            }
            else
            {
              v21 = v8 + 16;
              *(uint32_t *)(*(uint32_t *)(a1 + 68) + 20) = v8 + 16;
            }
            v22 = (uint32_t *)(v12 + 84 * a3);
            *v22 = v16 + 12;
            v22[1] = v21;
            v22[2] = 1;
          }
          v23 = *(uint16_t *)(v8 + 8);
          *(uint32_t *)(v16 + 68) = *(uint32_t *)(v15 + 36) | 0x100;
          if ( (v23 & 2) != 0 )
            *(uint32_t *)(*(uint32_t *)(v8 + 52) + 20) = *(uint32_t *)(v8 + 4);
          *(uint16_t *)(v8 + 8) = v23 | 0xF;
          list_push_tail(v12 + 84 * a3 + 28);
          v24 = v12 + 84 * a3;
          v25 = *(uint8_t *)(v24 + 80);
          *(uint32_t *)(v24 + 44) = 0;
          *(uint8_t *)(v24 + 80) = v25 + 1;
          return 1;
        }
      }
      else
      {
        return 0;
      }
    }
  }
  return result;
}

