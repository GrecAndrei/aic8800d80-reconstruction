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

extern uint32_t dword_10C178;
extern uint32_t off_10C17C;
extern uint32_t off_10C180;
extern uint32_t off_10C184;
extern uint32_t off_10C18C;
extern uint32_t off_10C188;
extern uint32_t dword_10C168;
extern uint32_t dword_10C158;
extern uint32_t dword_10C190;
extern uint32_t dword_10C194;
extern uint32_t off_10C1B0;
extern uint32_t off_10C198;
extern uint32_t dword_10C1A0;
extern uint32_t dword_10C19C;
extern uint32_t off_10C170;
extern uint32_t off_10C174;
extern uint32_t off_10C1A8;
extern uint32_t dword_10C1A4;
extern uint32_t dword_10C1AC;

// parse_packet_control @ 0x10bf28, size 546 bytes
// Doc: parse_packet_control [tx]: Configure TX PHY parameters from descriptor fields
// parse_packet_control [tx]: Configure TX PHY parameters from descriptor fields
uint32_t * parse_packet_control(uint32_t *result, unsigned int a2, int a3, int a4)
{
  int v4; // r6
  int v7; // r7
  int v8; // r3
  int v9; // r10
  int v10; // r0
  unsigned int v11; // r3
  unsigned int v12; // r3
  int v13; // r1
  void *v14; // r2
  int v15; // r3
  unsigned int v16; // r0
  int v17; // r0
  uint64_t v18; // r8
  double v19; // d8
  uint64_t v20; // r0
  uint64_t v21; // r0
  uint64_t v22; // r0
  uint64_t v23; // r0
  int v24; // r8
  uint64_t v25; // r0
  int v26; // r2
  int v27; // r0
  int v28; // r8
  int v29; // r0
  int v30; // r1
  int v31; // r2
  int v32; // r3
  uint16_t *v33; // r6
  int v34; // r1
  int v35; // r2
  int v36; // r5
  uint64_t v37; // r0
  int v38; // r2
  int v39; // r3
  uint64_t v40; // r0
  int v41; // r2
  int v42; // r3
  int v43; // r2
  int v44; // r3
  int v45; // r0
  int v46; // r1
  int v47; // r2
  int v48; // r3
  int v49; // [sp+0h] [bp-64h]
  int v50; // [sp+0h] [bp-64h]
  int v51; // [sp+0h] [bp-64h]
  int v52; // [sp+Ch] [bp-58h]
  int v53[3]; // [sp+24h] [bp-40h] BYREF
  uint64_t v54; // [sp+30h] [bp-34h] BYREF
  int v55; // [sp+38h] [bp-2Ch]
  int v56; // [sp+3Ch] [bp-28h]
  uint64_t v57; // [sp+40h] [bp-24h]
  int v58; // [sp+48h] [bp-1Ch]
  int v59; // [sp+4Ch] [bp-18h]
  int v60; // [sp+50h] [bp-14h]
  int v61; // [sp+54h] [bp-10h]
  int v62; // [sp+58h] [bp-Ch]
  int v63; // [sp+5Ch] [bp-8h]

  v4 = *result;
  v7 = (uint8_t)*result >> 6;
  if ( !a3 )
  {
    if ( !a4 )
      return result;
    goto LABEL_3;
  }
  v9 = result[1];
  v10 = check_interrupt_flag(0x2000, dword_10C178, *result, v9);
  v11 = a2 - 2;
  do
  {
    *(uint16_t *)(v11 + 2) = -32640;
    v11 += 2;
  }
  while ( a2 + 30 != v11 );
  *(uint32_t *)(a2 + 32) = 0;
  *(uint32_t *)(a2 + 36) = 0;
  v12 = a2 + 36;
  v13 = a2 + 100;
  do
  {
    *(uint32_t *)(v12 + 4) = 0;
    v12 += 4;
  }
  while ( v13 != v12 );
  v14 = off_10C17C;
  do
    v15 = *(uint32_t *)off_10C17C;
  while ( !*(uint32_t *)off_10C17C );
  if ( v7 )
  {
    v16 = (*(uint32_t *)off_10C180 >> 5) & 0x1F;
    if ( (*(uint32_t *)off_10C180 & 0x400) != 0 )
      v16 *= 2;
    if ( (*(uint32_t *)off_10C184 & 0x80000) != 0 && (*(uint32_t *)off_10C184 & 0x40000) != 0 )
      v16 >>= 1;
    v17 = *(uint8_t *)off_10C18C * v16;
    *(uint32_t *)off_10C188 &= ~1u;
    if ( (uint8_t)v4 >> 7 )
    {
      v18 = *(uint64_t *)&dword_10C168;
      v19 = dbl_10C160;
    }
    else
    {
      v18 = *(uint64_t *)&dword_10C158;
      v19 = dbl_10C150;
    }
    v20 = aeabi_i2d(v17);
    v21 = aeabi_dadd(v20, HIDWORD(v20), 0, dword_10C190);
    v22 = aeabi_dsub(v18, HIDWORD(v18), v21, HIDWORD(v21));
    v23 = aeabi_dadd(v22, HIDWORD(v22), 0, dword_10C194);
    v24 = parse_data_field(v23, HIDWORD(v23));
    v25 = aeabi_dsub(LODWORD(v19), HIDWORD(v19), 0, dword_10C190);
    v26 = parse_data_field(v25, HIDWORD(v25));
    v27 = v24;
    v28 = v26;
    *(uint32_t *)off_10C1B0 = aeabi_d2iz(v27) & 0x7FFFFFFF;
    v10 = aeabi_d2iz(v28);
    v14 = off_10C198;
    v13 = *(uint32_t *)off_10C198 & dword_10C1A0;
    v15 = dword_10C19C & (v10 << 13) | v13;
    *(uint32_t *)off_10C198 = v15;
  }
  poll_rf_status(v10, v13, (int)v14, v15, v49);
  v29 = read_radio_status((uint8_t)v4, a2, v9, (uint16_t)v4 >> 12, BYTE1(v4) & 0xF, 0);
  result = (uint32_t *)configure_bb_clock(v29, v30, v31, v32, v50);
  *(uint32_t *)off_10C17C = 1;
  if ( a4 )
  {
LABEL_3:
    v8 = *(uint32_t *)off_10C170;
    if ( (*(uint32_t *)off_10C170 & 0x8000000) == 0
      || (v8 = *(uint32_t *)off_10C174 << 21, (*(uint32_t *)off_10C174 & 0x400) != 0) )
    {
      if ( !v7 )
      {
        v33 = (uint16_t *)off_10C1A8;
        v34 = *(uint32_t *)(dword_10C1A4 + 4);
        v35 = *(uint32_t *)(dword_10C1A4 + 8);
        v36 = dword_10C1A4 + 72;
        v53[0] = *(uint32_t *)dword_10C1A4;
        v53[1] = v34;
        v53[2] = v35;
        poll_rf_status(v53[0], v34, v35, v8, v49);
        v37 = *(uint64_t *)v36;
        v38 = *(uint32_t *)(v36 + 8);
        v39 = *(uint32_t *)(v36 + 12);
        v36 += 16;
        v54 = v37;
        v55 = v38;
        v56 = v39;
        v40 = *(uint64_t *)v36;
        v41 = *(uint32_t *)(v36 + 8);
        v42 = *(uint32_t *)(v36 + 12);
        v36 += 16;
        v57 = v40;
        v58 = v41;
        v59 = v42;
        HIDWORD(v40) = *(uint32_t *)(v36 + 4);
        v43 = *(uint32_t *)(v36 + 8);
        v44 = *(uint32_t *)(v36 + 12);
        v60 = *(uint32_t *)v36;
        v61 = HIDWORD(v40);
        v62 = v43;
        v63 = v44;
        *((uint8_t *)v33 + 4) = 0;
        LODWORD(v40) = dword_10C1AC;
        *((uint8_t *)v33 + 12) = 0;
        *((uint8_t *)v33 + 20) = 0;
        *((uint8_t *)v33 + 28) = 0;
        *((uint8_t *)v33 + 36) = 0;
        *((uint8_t *)v33 + 44) = 0;
        *((uint8_t *)v33 + 52) = 0;
        configure_dma_regs((unsigned int *)v40, (uint8_t *)(a2 + 125), (int)v33);
        v45 = apply_dsp_transform(v53, dword_10C1AC, a2 + 104, a2 + 125, v33, 6, 1, v52, 0, 0, &v54);
        *((uint8_t *)v33 + 4) = 0;
        *((uint8_t *)v33 + 12) = 0;
        *((uint8_t *)v33 + 20) = 0;
        *((uint8_t *)v33 + 28) = 0;
        *((uint8_t *)v33 + 36) = 0;
        *((uint8_t *)v33 + 44) = 0;
        *((uint8_t *)v33 + 52) = 0;
        return (uint32_t *)configure_bb_clock(v45, v46, v47, v48, v51);
      }
    }
  }
  return result;
}

