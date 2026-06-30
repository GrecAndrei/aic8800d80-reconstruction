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

extern uint32_t off_138FDC;
extern uint32_t off_138FE0;
extern uint32_t dword_138FD4;
extern uint32_t dword_138FD0;
extern uint32_t dword_138FD8;

// fmac_msg_handler_n3a4 @ 0x138da4, size 554 bytes
// Doc: fmac_msg_handler_n3a4 [mac]: FMAC message handler with frame context
// fmac_msg_handler_n3a4 [mac]: FMAC message handler with frame context
int  fmac_msg_handler_n3a4(unsigned int a1, int a2, int a3, int a4)
{
  uint32_t *v4; // r8
  unsigned int v5; // r4
  int v8; // r5
  uint32_t *v9; // r6
  int v10; // r1
  int v11; // r1
  int16_t v12; // r2
  int v13; // r0
  unsigned int v14; // r5
  unsigned int v15; // r4
  int v16; // cc
  int v17; // r1
  int16_t **v18; // r10
  int16_t **v19; // r12
  char *v20; // r0
  int v21; // r1
  uint64_t v22; // r2
  int16_t v23; // r5
  int16_t v24; // lr
  signed int v25; // r3
  uint8_t *v26; // r2
  int v27; // r3
  int v28; // r10
  uint8_t *v29; // r5
  int v30; // lr
  uint8_t *v32; // r5
  char *v33; // r3
  char *v34; // r2
  int v35; // r6
  uint8_t *v36; // r3
  char *v37; // r2
  uint8_t *v38; // r5
  int v39; // r0
  int v40; // r1
  int v41; // r2
  uint64_t v42; // r4
  int v43; // t1
  int v44; // [sp+Ch] [bp-10h]
  uint64_t v45; // [sp+10h] [bp-Ch] BYREF

  v4 = off_138FDC;
  v5 = a1;
  if ( a3 )
  {
    sub_1335E4(
      a2,
      (uint32_t *)(*((uint32_t *)off_138FDC + 8) + 88),
      (int)off_138FDC + 36,
      (uint16_t *)off_138FDC + 21,
      *((uint8_t *)off_138FDC + 7));
    v11 = *((uint8_t *)v4 + 8);
    v9 = *(uint32_t **)(v5 + 28);
    LOWORD(v5) = *(uint16_t *)(v5 + 48) - v11;
    v12 = *((uint8_t *)v4 + 8);
  }
  else
  {
    v8 = *((uint8_t *)off_138FDC + 8);
    v9 = *(uint32_t **)(a1 + 28);
    v5 = (uint16_t)(*(uint16_t *)(a1 + 48) - v8);
    v10 = a2 + 16;
    if ( a4 && v5 <= 7 )
    {
      v44 = v10;
      v32 = (uint8_t *)(v8 + v9[2]);
      fmac_data_unpack_n_630((uint32_t *)a2, v10, v5);
      v33 = (char *)&v45;
      v34 = (char *)&v45 + (uint8_t)(8 - v5);
      do
      {
        *v33 = v33[v44 + v5 - (uint32_t)&v45];
        ++v33;
      }
      while ( v34 != v33 );
      v35 = 8 - (uint8_t)(8 - v5);
      if ( v35 )
      {
        v36 = v32;
        v37 = (char *)(v34 - v32);
        v38 = &v32[v35];
        do
        {
          v36[(uint32_t)v37] = *v36;
          ++v36;
        }
        while ( v38 != v36 );
      }
      goto LABEL_36;
    }
    fmac_data_unpack_n_630((uint32_t *)a2, v10, 8u);
    v11 = *((uint8_t *)v4 + 8);
    v12 = *((uint8_t *)v4 + 8);
  }
  v13 = v9[2];
  v14 = (uint16_t)(v5 - 8);
  v15 = (uint16_t)(v9[3] + 1 - v13);
  v16 = (int)(v11 + v14) <= (int)v15;
  v17 = v11 + v13;
  if ( v16 )
  {
    v15 = (uint16_t)(v12 + v14);
LABEL_11:
    fmac_data_unpack_n_630((uint32_t *)a2, v17, v14);
  }
  else
  {
    v18 = (int16_t **)off_138FE0;
    while ( 1 )
    {
      v14 = (uint16_t)(v14 + v12 - v15);
      fmac_data_unpack_n_630((uint32_t *)a2, v17, (uint16_t)(v15 - v12));
      v12 = 0;
      if ( !(uint16_t)v14 )
        break;
      v9 = (uint32_t *)v9[1];
      if ( **v18 < 0 && !v9 )
      {
        fmac_phy_op_handler(dword_138FD4, dword_138FD0, 963);
        return 0;
      }
      v17 = v9[2];
      v15 = (uint16_t)(v9[3] + 1 - v17);
      if ( v15 >= (uint16_t)v14 )
      {
        v15 = (uint16_t)v14;
        goto LABEL_11;
      }
    }
  }
  v19 = (int16_t **)off_138FE0;
  v20 = (char *)&v45;
  v21 = 8;
  while ( 1 )
  {
    v22 = *((uint64_t *)v9 + 1);
    v23 = v22;
    v24 = WORD2(v22) + 1;
    v25 = (uint16_t)(WORD2(v22) + 1 - v22);
    v26 = (uint8_t *)(v22 + v15);
    if ( (int)(v21 + v15) <= v25 )
      break;
    v27 = (uint16_t)(v25 - v15);
    v28 = v27 - 1;
    if ( v27 )
    {
      v21 = (uint16_t)(v21 + v15 + v23 - v24);
      goto LABEL_16;
    }
    v21 = (uint16_t)(v23 + v21 + v15 - v24);
LABEL_19:
    v9 = (uint32_t *)v9[1];
    v15 = 0;
    if ( **v19 < 0 && !v9 )
    {
      fmac_phy_op_handler(dword_138FD4, dword_138FD0, 1005);
      return 0;
    }
  }
  v27 = v21;
  v28 = v21 - 1;
  v21 = 0;
LABEL_16:
  v29 = &v26[v28 + 1];
  v30 = v20 - v26;
  do
  {
    v26[v30] = *v26;
    ++v26;
  }
  while ( v26 != v29 );
  v20 += v27;
  if ( v21 )
    goto LABEL_19;
  if ( !a4 )
  {
    *(uint64_t *)(a2 + 16) = v45;
    return 1;
  }
LABEL_36:
  sub_13376C(a2);
  if ( v45 == *(uint64_t *)a2 )
    return 1;
  v39 = sub_12C92C(5126, 13, 5, 0x18u);
  v40 = v4[6];
  v41 = dword_138FD8 + 696 * *((uint8_t *)v4 + 9);
  v42 = *((uint64_t *)v4 + 2);
  v43 = *(uint32_t *)(v41 + 38);
  *(uint16_t *)(v39 + 4) = *(uint16_t *)(v41 + 42);
  *(uint64_t *)(v39 + 8) = v42;
  *(uint32_t *)v39 = v43;
  *(uint8_t *)(v39 + 18) = *((uint8_t *)v4 + 10);
  *(uint8_t *)(v39 + 16) = (v40 & 0x400) != 0;
  *(uint8_t *)(v39 + 17) = *(uint8_t *)(v4[8] + 97);
  sdio_buffer_prepare_n_4e8(v39);
  return 0;
}

