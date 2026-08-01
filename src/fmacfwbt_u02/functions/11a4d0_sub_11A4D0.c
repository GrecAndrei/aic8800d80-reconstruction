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

extern uint32_t dword_11A708;
extern uint32_t dword_11A70C;

// llc_rx_llcp_handler @ 0x11a4d0, size 566 bytes
int  llc_rx_llcp_handler(int a1, int a2)
{
  int v2; // r7
  int v3; // r8
  int v4; // r5
  int v5; // r2
  int v8; // r9
  int v9; // r3
  unsigned int v10; // r0
  unsigned int v11; // r1
  int v12; // lr
  unsigned int v13; // r12
  unsigned int v14; // r10
  unsigned int v15; // r0
  unsigned int v16; // r11
  unsigned int v17; // r1
  int v18; // r0
  int v19; // r7
  unsigned int v20; // r5
  char v21; // r0
  unsigned int v22; // r3
  unsigned int v23; // r0
  int v25; // r0
  int v26; // r10
  uint32_t *v27; // r5
  unsigned int v28; // r2
  unsigned int v29; // r0
  int v30; // r2
  int v31; // r1
  unsigned int v32; // r1
  int v33; // r3
  unsigned int v34; // r0
  int v35; // r6
  unsigned int v36; // r3
  int v37; // r12
  int v38; // r0
  int v39; // r3
  int v40; // [sp+0h] [bp-1Ch]
  int v41; // [sp+4h] [bp-18h]
  char v42; // [sp+8h] [bp-14h]
  char v43; // [sp+Ch] [bp-10h]
  int v44; // [sp+10h] [bp-Ch]
  int v45; // [sp+14h] [bp-8h]

  v2 = dword_11A708;
  v3 = *(uint32_t *)(a1 + 76);
  v4 = dword_11A708 + 84 * a2;
  v5 = *(uint32_t *)(v4 + 44);
  v42 = *(uint8_t *)(a1 + 27);
  v43 = *(uint8_t *)(a1 + 29);
  v8 = v3 + 12;
  if ( v5 )
  {
    while ( 1 )
    {
      v9 = *(uint32_t *)(a1 + 36);
      if ( (v9 & 0x200000) != 0
        && (v9 & 0x380000) != 0x280000
        && *(uint8_t *)(v5 + 12) == *(uint8_t *)(a1 + 29)
        && *(uint8_t *)(v5 + 13) == *(uint8_t *)(a1 + 27) )
      {
        v10 = *(uint16_t *)(v4 + 72);
        v11 = (uint16_t)(((*(uint32_t *)(v3 + 36) + 3) & 0xFFFC) + 4);
        if ( v10 > v11 )
        {
          v37 = (uint16_t)(v10 - v11) + 3;
          v45 = v37 >> 2;
          v13 = (unsigned int)v37 >> 2;
          v12 = 4 * v45;
        }
        else
        {
          v12 = 0;
          v45 = 0;
          LOWORD(v13) = 0;
        }
        v41 = *(uint32_t *)(v5 + 40);
        v40 = *(uint32_t *)(v4 + 52);
        v14 = *(uint8_t *)(v4 + 79);
        v15 = 21 * a2 + v14;
        v44 = *(uint32_t *)(v40 + 76);
        v16 = *(uint32_t *)(v2 + 4 * v15 + 56);
        *(uint16_t *)(v4 + 74) = v13;
        v17 = v41 + v12 + v11;
        if ( v17 <= v16 )
          goto LABEL_15;
        if ( *(uint8_t *)(v4 + 78) > v14 && *(uint8_t *)(v4 + 77) != 1 && v17 <= *(uint32_t *)(v2 + 4 * v15 + 60) )
          break;
      }
      llc_tx_llcp_handler(a2);
      v5 = *(uint32_t *)(v4 + 44);
      if ( !v5 )
        goto LABEL_17;
    }
    v18 = v5 + 4 * v14;
    *(uint32_t *)(v18 + 328) = v40;
    *(uint32_t *)(v18 + 56) = v41;
    *(uint8_t *)(v4 + 79) = v14 + 1;
LABEL_15:
    v19 = v2 + 84 * a2;
    v20 = *(uint8_t *)(v19 + 76);
    v21 = *(uint8_t *)(v19 + 77);
    *(uint32_t *)(a1 + 68) = v5;
    v22 = (v9 | (v45 << 9)) & 0xFF87FFFF | 0x700000;
    *(uint32_t *)(a1 + 36) = v22;
    v23 = (uint8_t)(v21 + 1);
    *(uint32_t *)(v3 + 68) = v22;
    *(uint32_t *)(v44 + 20) = v8;
    *(uint32_t *)(v5 + 40) = v17;
    *(uint32_t *)(v19 + 52) = a1;
    *(uint8_t *)(v19 + 77) = v23;
    if ( v20 <= v23 )
      llc_tx_llcp_handler(a2);
  }
  else
  {
LABEL_17:
    if ( (*(uint32_t *)(a1 + 36) & 0x200000) != 0 && ((*(uint32_t *)(a1 + 40) >> 11) & 6) != 0 )
    {
      v25 = list_pop_front(dword_11A70C + 8 * a2);
      v26 = v2 + 84 * a2;
      v27 = (uint32_t *)v25;
      *(uint32_t *)(v26 + 44) = v25;
      if ( v25 )
      {
        *(uint8_t *)(v25 + 12) = v43;
        *(uint8_t *)(v25 + 13) = v42;
        *(uint8_t *)(v25 + 14) = 1;
        v28 = *(uint32_t *)(a1 + 40);
        *(uint32_t *)(v25 + 268) = a1;
        *(uint64_t *)(v25 + 4) = v28;
        *(uint32_t *)(v25 + 264) = 0;
        *(uint8_t *)(v25 + 344) = *(uint8_t *)(a1 + 54);
        rx_descriptor_process(v25, a2, v2 + 84 * a2 + 44);
        v29 = *(uint16_t *)(v26 + 72);
        v30 = (uint16_t)(((*(uint32_t *)(v3 + 36) + 3) & 0xFFFC) + 4);
        v27[10] = v30;
        v31 = *(uint32_t *)(v3 + 36);
        v27[6] = v8;
        v32 = (uint16_t)(((v31 + 3) & 0xFFFC) + 4);
        v33 = 0;
        v27[14] = 0;
        v27[15] = 0;
        v27[19] = 0;
        v27[7] = 0;
        v27[16] = 0;
        *(uint8_t *)(v26 + 77) = 1;
        if ( v29 > v32 )
        {
          v38 = (uint16_t)(v29 - v32) + 3;
          v39 = v38 >> 2;
          v30 += 4 * (v38 >> 2);
          v34 = (unsigned int)v38 >> 2;
          v33 = v39 << 9;
        }
        else
        {
          LOWORD(v34) = 0;
        }
        v35 = v2 + 84 * a2;
        v36 = (v33 | *(uint32_t *)(a1 + 36)) & 0xFF87FFFF | 0x680000;
        *(uint16_t *)(v35 + 74) = v34;
        v27[10] = v30;
        *(uint32_t *)(v35 + 48) = a1;
        *(uint32_t *)(v35 + 52) = a1;
        *(uint32_t *)(a1 + 36) = v36;
        *(uint32_t *)(a1 + 68) = v27;
        *(uint32_t *)(v3 + 68) = v36;
      }
      else
      {
        *(uint32_t *)(a1 + 36) = 0;
        ++*(uint8_t *)(v26 + 80);
      }
    }
    else
    {
      ++*(uint8_t *)(v2 + 84 * a2 + 80);
    }
  }
  return 0;
}

