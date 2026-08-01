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

extern uint32_t dword_11AC2C;
extern uint32_t dword_11AC44;
extern uint32_t off_11AC30;
extern uint32_t dword_11AC34;
extern uint32_t dword_11AC70;
extern uint32_t off_11AC4C;
extern uint32_t dword_11AC40;
extern uint32_t dword_11AC38;
extern uint32_t dword_11AC3C;
extern uint32_t dword_11AC48;

// parse_rx_frame @ 0x11a940, size 814 bytes
int  parse_rx_frame(int a1, int a2)
{
  int v2; // r10
  int v3; // r4
  int16_t v4; // r2
  int v5; // r6
  int v6; // r3
  int v7; // r5
  int v8; // r0
  int v9; // r3
  int v11; // r0
  int v12; // r7
  int v13; // r1
  int v14; // r4
  int16_t **v15; // r11
  int v16; // r0
  unsigned int v17; // r2
  int16_t v18; // r3
  int v19; // r6
  unsigned int v20; // r0
  unsigned int v21; // r9
  int v22; // r12
  int v23; // r8
  int v24; // r5
  unsigned int v25; // r1
  unsigned int v26; // r4
  unsigned int v27; // r2
  int v28; // r5
  int inited; // r0
  int v30; // r3
  int v31; // r2
  int *v32; // r4
  int v33; // r2
  int v34; // r2
  int v35; // r2
  int *v36; // r3
  int v37; // r2
  int *v38; // r10
  int v39; // t1
  int v40; // r1
  unsigned int v41; // r2
  unsigned int v42; // r3
  int v43; // r8
  int v44; // r4
  int v45; // r7
  int16_t **v46; // r8
  int v47; // r6
  int v48; // r3
  int v49; // r9
  int v50; // r0
  int v52; // [sp+4h] [bp-38h]
  int v53; // [sp+8h] [bp-34h]
  uint32_t *v54; // [sp+Ch] [bp-30h]
  uint8_t v55[40]; // [sp+14h] [bp-28h] BYREF

  v2 = *(uint32_t *)(a1 + 68);
  v3 = dword_11AC2C;
  v4 = *(uint16_t *)(v2 + 8);
  v5 = v4 & 1;
  v52 = *(uint8_t *)(dword_11AC2C + *(uint8_t *)(v2 + 13));
  if ( (v4 & 1) == 0 )
    return v5;
  v6 = *(uint32_t *)(a1 + 36) & 0x380000;
  v7 = a1;
  if ( v6 == 3670016 )
  {
    ++*(uint8_t *)(dword_11AC44 + 84 * v52 + 80);
    inited = tx_queue_init(a1, 0);
    v30 = *(uint16_t *)(v2 + 8) << 21;
    v5 = inited;
    *(uint32_t *)a2 = inited;
    if ( v30 < 0 )
    {
      cmd_handler_a(*(uint32_t *)(v2 + 340));
      return *(uint32_t *)a2;
    }
    return v5;
  }
  if ( v6 != 3145728 )
  {
    v8 = *(uint8_t *)(*(uint32_t *)off_11AC30 + 1);
LABEL_5:
    *(uint16_t *)(v2 + 8) = 3;
    if ( v8 )
      v9 = v2 + 84;
    else
      v9 = *(uint32_t *)(*(uint32_t *)(v2 + 324) + 76) + 12;
    v5 = v2 + 16;
    *(uint32_t *)a2 = v9;
    return v5;
  }
  *(uint16_t *)(v2 + 8) = v4 & 0xFBFF;
  v53 = v4 & 0x400;
  if ( (v4 & 0x400) != 0 )
  {
    v13 = v52;
    v12 = v2;
  }
  else
  {
    v11 = mem_word_load(dword_11AC34 + 8 * v52);
    v12 = v11;
    if ( !v11 )
    {
      v43 = dword_11AC70;
      goto LABEL_41;
    }
    memcpy(v11, v2, 360);
    v13 = *(uint8_t *)(v3 + *(uint8_t *)(v12 + 13));
  }
  v14 = *(uint32_t *)(v7 + 76);
  v15 = (int16_t **)off_11AC4C;
  rf_get_rssi(v12, v13, (int)v55);
  v16 = *(uint32_t *)(v14 + 36);
  v17 = *(uint32_t *)(v7 + 36);
  v18 = *(uint16_t *)(v7 + 80);
  *(uint32_t *)(v7 + 68) = v12;
  v19 = *(uint32_t *)v7;
  *(uint32_t *)(v12 + 268) = v7;
  *(uint32_t *)(v12 + 56) = 0;
  *(uint32_t *)(v12 + 60) = 0;
  v20 = (uint16_t)(((v16 + 3) & 0xFFFC) + 4 * ((v17 >> 9) & 0x3FF) + 4);
  *(uint16_t *)(v12 + 10) = v18;
  *(uint32_t *)(v12 + 64) = 0;
  v21 = 0;
  v22 = v7;
  v23 = 1;
  v54 = (uint32_t *)v7;
  while ( 1 )
  {
    v24 = *(uint32_t *)(v19 + 76);
    v25 = *(uint32_t *)(v19 + 36);
    v26 = (uint16_t)(((*(uint32_t *)(v24 + 36) + 3) & 0xFFFC) + 4 * ((v25 >> 9) & 0x3FF) + 4) + v20;
    if ( v26 <= *(uint32_t *)&v55[4 * v21 + 12] )
      goto LABEL_20;
    if ( v55[34] > v21 )
      break;
    if ( **v15 < 0 )
    {
      mmio_clear_register(dword_11AC40, dword_11AC38, 721);
      v25 = *(uint32_t *)(v19 + 36);
    }
LABEL_20:
    *(uint16_t *)(v12 + 10) += *(uint16_t *)(v19 + 80);
    v23 = (uint8_t)(v23 + 1);
    *(uint32_t *)(v19 + 68) = v12;
    if ( (v25 & 0x380000) == 0x380000 )
    {
      v31 = *(uint32_t *)(v19 + 76);
      *(uint32_t *)(v12 + 40) = v26;
      v32 = (int *)off_11AC30;
      *(uint8_t *)(v31 + 1) = v23;
      v33 = *v32;
      *(uint32_t *)(v12 + 324) = v19;
      v8 = *(uint8_t *)(v33 + 1);
      if ( *(uint8_t *)(v33 + 1) )
        *(uint32_t *)(v24 + 20) = v12 + 84;
      else
        *(uint32_t *)(v24 + 20) = v8;
      v34 = dword_11AC44 + 84 * v52;
      ++*(uint8_t *)(v34 + 80);
      if ( !v53 )
      {
        read_word(v34 + 28, v2, v12);
        v8 = *(uint8_t *)(*v32 + 1);
      }
      v35 = v54[18];
      if ( v35 )
      {
        v36 = (int *)(v2 + 272);
        v37 = v35 + 40;
        v38 = (int *)(v2 + 324);
        do
        {
          v39 = *v36++;
          *(uint32_t *)(v37 + 4) = v39;
          v37 += 4;
        }
        while ( v36 != v38 );
      }
      v40 = v54[19];
      v41 = v54[9] & 0xFFE7FFFF;
      v42 = *(uint32_t *)(v40 + 68) & 0xFFC7FFFF;
      *(uint32_t *)(v12 + 24) = v40 + 12;
      *(uint32_t *)(v12 + 76) = 0;
      *(uint32_t *)(v12 + 52) = v12 + 272;
      v2 = v12;
      v54[9] = v41 | 0x280000;
      *(uint32_t *)(v40 + 68) = v42 | 0x280000;
      goto LABEL_5;
    }
    v28 = *(uint32_t *)v19;
    if ( **v15 < 0 && !v28 )
      mmio_clear_register(dword_11AC3C, dword_11AC38, 744);
    v22 = v19;
    v20 = v26;
    v19 = v28;
  }
  if ( v23 != 1 && v26 <= *(uint32_t *)&v55[4 * v21 + 16] )
  {
    v27 = v12 + 4 * v21;
    *(uint32_t *)(v27 + 328) = v22;
    *(uint32_t *)(v27 + 56) = v20;
    v21 = (uint8_t)(v21 + 1);
    goto LABEL_20;
  }
  v7 = (int)v54;
  if ( v53 )
  {
    v43 = dword_11AC70;
    cmd_handler_c(84 * (int16_t)v52 + 28 + dword_11AC70, v12);
  }
  else
  {
    v43 = dword_11AC44;
  }
  cmd_handler_a(*(uint32_t *)(v12 + 340));
LABEL_41:
  v44 = 0;
  v45 = v43 + 84 * v52;
  v46 = (int16_t **)off_11AC4C;
  v47 = 0;
  while ( 2 )
  {
    v48 = *(uint32_t *)(v7 + 36);
    ++*(uint8_t *)(v45 + 80);
    v49 = v48 & 0x380000;
    v50 = tx_queue_init(v7, 0);
    if ( !v50 )
    {
LABEL_45:
      if ( v49 == 3670016 )
        break;
      goto LABEL_46;
    }
    if ( v44 )
    {
      *(uint32_t *)(v44 + 4) = v50;
      v44 = v50;
      goto LABEL_45;
    }
    v44 = v50;
    v47 = v50;
    if ( v49 != 3670016 )
    {
LABEL_46:
      v7 = *(uint32_t *)v7;
      if ( **v46 < 0 && !v7 )
        mmio_clear_register(dword_11AC3C, dword_11AC48, 3509);
      continue;
    }
    break;
  }
  *(uint32_t *)a2 = v44;
  return v47;
}

