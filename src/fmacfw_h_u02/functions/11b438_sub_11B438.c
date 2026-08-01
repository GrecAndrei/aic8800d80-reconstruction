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

extern uint32_t off_11B684;
extern uint32_t off_11B66C;
extern uint32_t dword_11B670;
extern uint32_t dword_11B680;
extern uint32_t off_11B674;
extern uint32_t off_11B678;
extern uint32_t dword_11B67C;

// save_rx_packet @ 0x11b438, size 562 bytes
int  save_rx_packet(int a1)
{
  uint32_t *v1; // r8
  char *v2; // r6
  int v3; // r2
  int v5; // r3
  int16_t v6; // r4
  int v7; // r0
  unsigned int v8; // r1
  int v9; // r0
  int v10; // r4
  unsigned int v11; // r0
  int v12; // r5
  char *v13; // r1
  int v14; // r6
  unsigned int *v15; // r12
  char *v16; // r2
  char *v17; // r9
  int v18; // lr
  int16_t v19; // r3
  unsigned int v20; // r3
  unsigned int v21; // t1
  int v22; // r2
  int v23; // r0
  int16_t v24; // r2
  uint32_t *v25; // r4
  uint32_t *v26; // r3
  int result; // r0
  int v28; // r3
  int v29; // r2
  uint32_t *v30; // r0
  uint32_t *v31; // r4
  int v32; // r2
  uint32_t *v33; // r1
  int v34; // r4
  int16_t v35; // r0
  unsigned int v36; // [sp+4h] [bp-8h]

  v1 = off_11B684;
  v2 = (char *)off_11B66C;
  v3 = *((uint32_t *)off_11B684 + 4);
  v5 = *(uint32_t *)a1 + 38;
  *((uint32_t *)off_11B66C + 18) = *(uint32_t *)v5;
  v6 = *(uint16_t *)(v5 + 4);
  v7 = *(uint32_t *)(v3 + 100);
  v8 = *(uint16_t *)(a1 + 18);
  LOWORD(v3) = *(uint16_t *)(v3 + 104);
  *(uint32_t *)(v2 + 78) = v7;
  v9 = *(uint32_t *)v5;
  LOWORD(v5) = *(uint16_t *)(v5 + 4);
  *((uint16_t *)v2 + 38) = v6;
  v10 = 0;
  *((uint32_t *)v2 + 21) = v9;
  *((uint16_t *)v2 + 41) = v3;
  *((uint16_t *)v2 + 44) = v5;
  *((uint32_t *)v2 + 275) = 0;
  *((uint32_t *)v2 + 276) = 0;
  *((uint32_t *)v2 + 6) = 0;
  v11 = align_alloc_size((int)(v2 + 92), v8);
  v12 = *((uint32_t *)v2 + 6);
  v13 = v2;
  v14 = (uint16_t)(((*((uint16_t *)v2 + 58) + 3) & 0xFFFC) + 4 + 4 * v11);
  v15 = (unsigned int *)(36 * *(uint8_t *)(*(uint32_t *)a1 + 35) + 8248 + dword_11B670);
  v36 = v11 << 9;
  v16 = v13 + 92;
  v17 = v13;
  v18 = 2621440;
  while ( 1 )
  {
    v21 = *v15++;
    v20 = v21;
    if ( v21 )
      break;
LABEL_4:
    ++v10;
    v16 += 92;
    if ( v10 == 9 )
      goto LABEL_12;
  }
  if ( (unsigned int)(v14 + v12) <= *(uint32_t *)(a1 + 8) )
  {
    if ( v20 <= 0x3F0 )
    {
      v19 = ((uint16_t)((v20 + 15) >> 4) << 7) | 0x30;
    }
    else if ( v20 <= 0x400 )
    {
      v19 = 8240;
    }
    else if ( v20 > 0x4300 )
    {
      if ( v20 > 0x4400 )
      {
        if ( v20 <= 0x23C00 )
        {
          v19 = ((uint8_t)((v20 - 15361) >> 11) << 7) | 0x4030;
        }
        else if ( v20 <= 0x24400 )
        {
          v19 = 24624;
        }
        else if ( v20 > dword_11B680 )
        {
          v35 = 32560;
          if ( v20 == -1 )
            v35 = 32688;
          v19 = v35;
        }
        else
        {
          v19 = ((uint8_t)((v20 - 115713) >> 15) << 7) | 0x6030;
        }
      }
      else
      {
        v19 = 16432;
      }
    }
    else
    {
      v19 = ((uint8_t)((v20 - 1009) >> 4) << 7) | 0x2030;
    }
    *((uint32_t *)v16 + 9) = 0;
    *((uint32_t *)v16 + 14) = v36 | v18;
    *((uint32_t *)v16 + 15) = 0;
    *((uint16_t *)v16 + 44) = v19 | v10;
    *((uint32_t *)v17 + 2) = v16;
    v12 = *((uint32_t *)v13 + 6) + v14;
    *((uint32_t *)v13 + 6) = v12;
    v17 = v16;
    v18 = 3145728;
    goto LABEL_4;
  }
LABEL_12:
  v1[52] |= 2u;
  if ( v12 )
  {
    v22 = *((uint32_t *)v17 + 14);
    *((uint32_t *)v17 + 2) = 0;
    if ( (v22 & 0x380000) == 0x280000 )
    {
      v32 = *((uint32_t *)v17 + 15);
      result = (int)off_11B674;
      v33 = off_11B678;
      v34 = dword_11B67C;
      *((uint32_t *)v17 + 1) = 0;
      *((uint8_t *)v1 + 200) = 0;
      *((uint32_t *)v17 + 15) = v32 & 0xFF00;
      *((uint32_t *)v17 + 14) = 256;
      *((uint32_t *)v17 + 9) = v34;
      *(uint32_t *)result = v17;
      *v33 = 0x2000;
    }
    else
    {
      *((uint32_t *)v17 + 14) = v22 | 0x380000;
      v23 = *((uint32_t *)v13 + 14);
      v24 = *((uint32_t *)v13 + 15);
      *((uint32_t *)v13 + 1) = 0;
      *((uint8_t *)v1 + 200) = 0;
      v25 = off_11B674;
      v26 = off_11B678;
      *((uint32_t *)v13 + 14) = v23 | 0x100;
      *((uint32_t *)v13 + 15) = v24 & 0xFF00;
      *v25 = v13;
      *v26 = 0x2000;
      return 0x2000;
    }
  }
  else
  {
    v28 = *((uint32_t *)v13 + 38);
    v29 = dword_11B67C;
    v30 = off_11B674;
    v31 = off_11B678;
    *((uint32_t *)v13 + 25) = 0;
    *((uint32_t *)v13 + 38) = v28 & 0xFF00;
    *((uint32_t *)v13 + 24) = 0;
    *((uint8_t *)v1 + 200) = 0;
    *v30 = v29 - 996;
    *v31 = 0x2000;
    *((uint16_t *)v13 + 90) = 48;
    *((uint32_t *)v13 + 37) = 256;
    *((uint32_t *)v13 + 32) = v29;
    return 48;
  }
  return result;
}

