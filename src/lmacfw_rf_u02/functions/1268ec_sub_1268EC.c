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

extern uint32_t dword_126BC4;
extern uint32_t dword_126BC8;
extern uint32_t off_126BD0;
extern uint32_t off_126BD4;
extern uint32_t off_126BD8;
extern uint32_t off_126BCC;
extern uint32_t off_126D3C;
extern uint32_t off_126D40;
extern uint32_t off_126D44;
extern uint32_t dword_126D48;
extern uint32_t dword_126D4C;
extern uint32_t off_126D24;
extern uint32_t off_126D30;
extern uint32_t dword_126D58;
extern uint32_t dword_126D5C;
extern uint32_t off_126D2C;
extern uint32_t dword_126D50;
extern uint32_t dword_126D54;
extern uint32_t off_126D28;
extern uint32_t off_126C04;
extern uint32_t dword_126C0C;
extern uint32_t dword_126C08;
extern uint32_t off_126C10;
extern uint32_t off_126BDC;
extern uint32_t dword_126D34;
extern uint32_t dword_126D38;
extern uint32_t dword_126C14;
extern uint32_t dword_126C18;
extern uint32_t off_126BE4;
extern uint32_t off_126BE0;
extern uint32_t off_126BE8;
extern uint32_t dword_126C38;
extern uint32_t dword_126C3C;
extern uint32_t dword_126BEC;
extern uint32_t dword_126BF0;
extern uint32_t off_126BF4;
extern uint32_t off_126C40;
extern uint32_t off_126C1C;
extern uint32_t dword_126C20;
extern uint32_t off_126C24;
extern uint32_t off_126C28;
extern uint32_t off_126BFC;
extern uint32_t off_126C2C;
extern uint32_t dword_126C30;
extern uint32_t dword_126BF8;
extern uint32_t off_126C34;
extern uint32_t off_126C00;

// init_with_stack @ 0x1268ec, size 1078 bytes
unsigned int * init_with_stack(int a1)
{
  unsigned int *result; // r0
  int v3; // r6
  unsigned int v4; // r5
  uint32_t *v5; // r1
  uint32_t *v6; // r2
  uint32_t *v7; // r2
  int *v8; // r3
  int v9; // r2
  uint32_t *v10; // r3
  uint32_t *v11; // r3
  uint32_t *v12; // r5
  uint32_t *v13; // r4
  uint32_t *v14; // r1
  uint32_t *v15; // r1
  int *v16; // r3
  int v17; // r2
  unsigned int *v18; // r4
  uint32_t *v19; // r2
  int v20; // r2
  uint32_t *v21; // r8
  unsigned int v22; // r6
  unsigned int v23; // r7
  int v24; // r5
  uint32_t *v25; // r4
  uint32_t *v26; // r0
  unsigned int *v27; // r3
  int v28; // r2
  uint32_t *v29; // r2
  uint32_t *v30; // r5
  int *v31; // r3
  int v32; // r2
  unsigned int v33; // r4
  int *v34; // r1
  int *v35; // r5
  int v36; // r6
  int v37; // r4
  int v38; // r2
  uint32_t *v39; // r2
  int *v40; // r3
  int v41; // r2
  uint32_t *v42; // r1
  int *v43; // r3
  unsigned int *v44; // r0
  int v45; // r4
  int v46; // r2
  uint32_t *v47; // r2
  int v48; // r2
  int *v49; // r3
  int v50; // r2
  uint64_t v51; // [sp+8h] [bp-8h] BYREF

  if ( a1 )
  {
    if ( a1 != 1 )
    {
      if ( (unsigned int)(a1 - 2) > 1 )
        return (unsigned int *)dispatch_event_handler(dword_126BC4, a1);
      mac_time_get(&v51, 0);
      v3 = BYTE1(v51);
      v4 = WORD1(v51);
      dispatch_event_handler(dword_126BC8, a1, WORD2(v51), WORD1(v51), BYTE1(v51));
      result = (unsigned int *)off_126BD0;
      v5 = off_126BD4;
      v6 = off_126BD8;
      *(uint32_t *)off_126BD0 = *(uint32_t *)off_126BCC & 0xFFFFBFFF;
      *v5 |= 0x80000000;
      *v6 |= 0x8000u;
      if ( a1 == 3 )
      {
        v6[80] |= 0x1000u;
        if ( v3 )
        {
          if ( v3 == 1 )
          {
            v42 = off_126D3C;
            v43 = (int *)off_126D40;
            v44 = (unsigned int *)off_126D44;
            v45 = dword_126D48;
            v46 = dword_126D4C;
            *(uint32_t *)off_126D3C = dword_126D48;
            *v43 = v46;
            v47 = off_126D24;
            *v44 = *v44 & 0xFFFFFF00 | 1;
            *v44 = *v44 & 0xFFFF00FF | 0x7F00;
            *(uint32_t *)(v45 + 1174608113) = *(uint32_t *)(v45 + 1174608113) & 0xC000FFFF | 0x1490000;
            v42[5] = v42[5] & 0xFFFFF0FF | 0x100;
            result = v44 - 146;
            *v47 &= ~0x80000000;
            *result &= ~0x80000000;
            if ( v4 == 2412 )
            {
              v49 = (int *)off_126D30;
              result = (unsigned int *)dword_126D58;
              v50 = dword_126D5C;
              *(uint32_t *)off_126D2C = dword_126D58;
              *v49 = v50;
            }
            else if ( v4 == 2472 )
            {
              result = (unsigned int *)dword_126D50;
              v48 = dword_126D54;
              *(uint32_t *)off_126D2C = dword_126D50;
              REG_4034_2088 = v48;
            }
          }
          else
          {
            v39 = off_126D28;
            *(uint32_t *)off_126D24 &= ~0x80000000;
            *v39 &= ~0x80000000;
          }
        }
        else
        {
          v15 = v5 - 101;
          v16 = (int *)off_126C04;
          v17 = dword_126C0C;
          *v15 = dword_126C08;
          *v16 = v17;
          v18 = (unsigned int *)off_126C10;
          v19 = off_126BDC;
          result[21] = result[21] & 0xFFFFFF00 | 1;
          result[21] = result[21] & 0xFFFF00FF | 0x7F00;
          *v18 = *v18 & 0xC000FFFF | 0x390000;
          v15[5] = v15[5] & 0xFFFFF0FF | 0x100;
          result -= 125;
          *v19 &= ~0x80000000;
          *result &= ~0x80000000;
          if ( v4 == 2412 )
          {
            v40 = (int *)off_126D30;
            result = (unsigned int *)dword_126D34;
            v41 = dword_126D38;
            *(uint32_t *)off_126D2C = dword_126D34;
            *v40 = v41;
          }
          else if ( v4 == 2472 )
          {
            result = (unsigned int *)dword_126C14;
            v20 = dword_126C18;
            *(uint32_t *)off_126BE4 = dword_126C14;
            REG_4034_2088 = v20;
          }
        }
      }
      else
      {
        v7 = off_126BE0;
        *(uint32_t *)off_126BDC &= ~0x80000000;
        *v7 &= ~0x80000000;
        if ( v3 )
        {
          if ( v3 == 1 )
          {
            v31 = (int *)off_126BE8;
            result = (unsigned int *)dword_126C38;
            v32 = dword_126C3C;
            *(uint32_t *)off_126BE4 = dword_126C38;
            *v31 = v32;
          }
        }
        else
        {
          v8 = (int *)off_126BE8;
          result = (unsigned int *)dword_126BEC;
          v9 = dword_126BF0;
          *(uint32_t *)off_126BE4 = dword_126BEC;
          *v8 = v9;
        }
      }
      v10 = off_126BF4;
LABEL_10:
      *v10 |= 2u;
      *v10 |= 1u;
      return result;
    }
    v21 = off_126C40;
    v22 = (*(uint32_t *)off_126C1C >> 11) & 7;
    v23 = *(uint32_t *)off_126C1C & 0x7F;
    v24 = (*(uint32_t *)off_126C1C >> 7) & 3;
    mac_validate_rate(v22, v23, v24);
    if ( !*v21 )
    {
      mac_time_get(&v51, 0);
      v33 = WORD1(v51);
      result = (unsigned int *)dispatch_event_handler(dword_126C20, WORD2(v51), WORD1(v51), BYTE1(v51));
      if ( v33 == 2412 )
      {
        v34 = (int *)off_126D28;
        v35 = (int *)off_126D2C;
        result = (unsigned int *)off_126D30;
        v36 = dword_126D34;
        v37 = dword_126D38;
        *(uint32_t *)off_126D24 &= ~0x80000000;
        v38 = *v34;
      }
      else
      {
        if ( v33 != 2472 )
          return result;
        v34 = (int *)off_126BE0;
        v35 = (int *)off_126BE4;
        result = (unsigned int *)off_126BE8;
        v36 = dword_126C14;
        v37 = dword_126C18;
        *(uint32_t *)off_126BDC &= ~0x80000000;
        v38 = *v34;
      }
      v10 = off_126BF4;
      *v34 = v38 & 0x7FFFFFFF;
      *v35 = v36;
      *result = v37;
      goto LABEL_10;
    }
    dispatch_event_handler(dword_126C20, v22, v23, v24);
    result = (unsigned int *)tx_descriptor_config(a1);
    if ( !*(uint8_t *)off_126C24 && *(uint32_t *)off_126C28 )
    {
      v25 = off_126BD8;
      v26 = off_126BFC;
      v27 = (unsigned int *)off_126C2C;
      v28 = dword_126C30;
      *(uint32_t *)off_126BD8 |= 0x4000u;
      *v26 |= 0x10000u;
      *v27 = v28 & ((*v21 - 1) << 16) | *v27 & 0x8000FFFF;
      *v27 |= 0x60u;
      *v27 |= 1u;
      result = v26 + 2071;
      v25[79] = v25[79] & 0xFFFFFF | 0xA0000000;
      *result = *result & 0xFF87FFFF | 0x700000;
    }
  }
  else
  {
    result = (unsigned int *)dispatch_event_handler(dword_126BF8);
    v11 = off_126BFC;
    if ( (*(uint32_t *)off_126BFC & 0x10000) != 0 )
    {
      v29 = off_126C2C;
      v30 = off_126C34;
      *(uint32_t *)off_126BD8 &= ~0x4000u;
      *v11 &= ~0x10000u;
      *v29 &= ~1u;
      *v29 &= 0xFFFFFF9F;
      *v30 &= 0xFF87FFFF;
      result = (unsigned int *)tx_descriptor_config(0);
    }
    if ( *(int *)off_126BDC >= 0 )
    {
      v12 = off_126BE0;
      v13 = off_126BD4;
      result = (unsigned int *)off_126BD8;
      v14 = off_126C00;
      *(uint32_t *)off_126BDC |= 0x80000000;
      *v12 |= 0x80000000;
      *v13 &= ~0x80000000;
      *result &= ~0x8000u;
      *v14 &= ~0x1000u;
    }
  }
  return result;
}

