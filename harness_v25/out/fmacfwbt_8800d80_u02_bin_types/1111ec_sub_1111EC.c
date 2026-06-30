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

extern uint32_t dword_1116A8;
extern uint32_t off_1116D4;
extern uint32_t dword_1116D0;
extern uint32_t dword_1116BC;
extern uint32_t dword_111478;
extern uint32_t off_11148C;
extern uint32_t off_111688;
extern uint32_t dword_111698;
extern uint32_t off_111694;
extern uint32_t dword_1116A0;
extern uint32_t off_1114A4;
extern uint32_t off_1114A8;
extern uint32_t off_1116C4;
extern uint32_t dword_111678;

// sub_1111EC @ 0x1111ec, size 1160 bytes
// Doc: rf_bus_mark_n_426 [rf]: Marks RF bus slot/entry with ownership and lookup metadata
// rf_bus_mark_n_426 [rf]: Marks RF bus slot/entry with ownership and lookup metadata
int sub_1111EC()
{
  int v0; // r4
  int v1; // r2
  int v2; // r2
  int v3; // r1
  uint32_t *v4; // r2
  int v5; // r1
  int v6; // r2
  uint8_t *v7; // r6
  unsigned int v8; // r1
  unsigned int v9; // r2
  int v10; // r5
  unsigned int v11; // r2
  char *v12; // r3
  uint32_t *v13; // r7
  uint32_t *v14; // r0
  int v15; // r3
  char *v16; // r1
  uint32_t *v17; // r0
  uint8_t *v18; // r5
  unsigned int v19; // r1
  unsigned int v20; // r2
  int result; // r0
  uint8_t *v22; // r5
  int v23; // r2
  uint8_t *v24; // r0
  unsigned int v25; // r1
  unsigned int v26; // r2
  uint32_t *v27; // r3
  uint8_t *v28; // r5
  int v29; // r2
  uint32_t *v30; // r0
  unsigned int v31; // r2
  uint32_t *v32; // r3
  unsigned int v33; // r3
  uint32_t *v34; // r7
  unsigned int v35; // r3
  char *v36; // r2
  uint32_t *v37; // r5
  int v38; // r6
  int v39; // r7
  unsigned int v40; // r3
  char *v41; // r2
  int v42; // r0
  int v43; // r5
  int v44; // r0
  int v45; // r1
  int v46; // r0
  int v47; // r1
  uint32_t *v48; // r2
  int v49; // r5
  int v50; // r1
  int v51; // r1
  uint8_t *v52; // r6
  int v53; // r1
  int v54; // r1
  uint32_t *v55; // r2
  int v56; // r1

  v0 = *(uint32_t *)rf_bus_reset2;
  if ( **(int16_t **)rf_bus_reset2_n_3e8 < 0 && !v0 )
  {
    sub_12F6C4(rf_bus_write_n_33c, rf_bus_write2_n_3f8, 39);
    goto rf_bus_mark_n_499_0;
  }
  v1 = v0 << 18;
  if ( (v0 & 0x2000) != 0 )
  {
    v48 = rf_bus_write_n_330;
    v49 = *(uint32_t *)rf_bus_mark_shift;
    *(uint32_t *)rf_bus_mark_shift = *(uint32_t *)rf_bus_mark_shift;
    v50 = dword_1116A8;
    *v48 &= ~0x20u;
    feature_guard_sdio(2, v50);
    if ( (v49 & 4) != 0 )
    {
      v53 = rf_bus_write2_n_3ab;
      *(uint8_t *)rf_bus_reset2_n_1a8 = 1;
      feature_guard_sdio(2, v53);
    }
    if ( (v49 & 1) != 0 )
    {
      v52 = rf_bus_reset2_n_1a8;
      *(uint32_t *)rf_bus_write_n_314 = 16;
      if ( *v52 )
      {
        feature_guard_sdio(2, rf_bus_write_n_2e4);
        *v52 = 0;
      }
      if ( *(uint8_t *)rf_bus_mark_n_2c )
      {
        v55 = off_1116D4;
        *((uint8_t *)rf_bus_mark_n_2c + 1) = 1;
        v56 = rf_bus_write2_n_3a0_16d8;
        *v55 |= 1u;
        feature_guard_sdio(2, v56);
      }
      v1 = 0;
      *(uint8_t *)rf_bus_reset2_n_19f = 0;
    }
    if ( (v49 & 2) != 0 )
    {
      v54 = dword_1116D0;
      *(uint8_t *)rf_bus_reset2_n_19f = 1;
      feature_guard_sdio(2, v54);
    }
    if ( (v49 & 8) != 0 )
      sub_12ECB0(dword_1116BC, v51, v1);
  }
  if ( (v0 & 1) != 0 )
  {
    sub_12ECB0(dword_111478, v0 << 31, v1);
    *(uint32_t *)rf_bus_mark_from_stack_args = 1;
  }
  v2 = v0 << 26;
  if ( (v0 & 0x20) != 0 )
  {
    mmio_field_extract_n1168(*(uint32_t *)rf_bus_mark_n_260_1480);
    v2 = 32;
    *(uint32_t *)rf_bus_mark_from_stack_args = 32;
  }
  if ( (v0 & 0x4000) != 0 )
  {
    v3 = *(uint32_t *)rf_bus_mark_n_25c;
    v4 = off_11148C;
    *(uint32_t *)rf_bus_mark_n_25c = *(uint32_t *)rf_bus_mark_n_25c;
    sub_12ECB0(rf_bus_mark_n_250_1490, v3, *v4);
  }
  if ( (v0 & 0x8000) == 0 )
    goto rf_bus_mark_n_499_0;
  v42 = rf_bus_mark_n_54;
  v43 = *(uint32_t *)off_111688;
  *(uint32_t *)off_111688 = *(uint32_t *)off_111688;
  sub_12ECB0(v42, v43, v2);
  if ( (v43 & 4) != 0 )
  {
    v2 = (int)rf_bus_write_n_330;
    *(uint32_t *)rf_bus_write_n_330 &= ~1u;
  }
  if ( (v43 & 8) == 0 )
  {
rf_bus_mark_n_499_0:
    v5 = v0 << 9;
    if ( (v0 & 0x400000) == 0 )
      goto rf_bus_mark_n_323_124c;
rf_bus_mark_n_144:
    v44 = dword_111698;
    v45 = *(uint32_t *)off_111694;
    *(uint32_t *)off_111694 = *(uint32_t *)off_111694;
    sub_12ECB0(v44, v45, v2);
    v6 = v0 << 8;
    if ( (v0 & 0x800000) == 0 )
      goto rf_bus_mark_n_48d;
    goto rf_bus_mark_n_131;
  }
  v2 = (int)rf_bus_write_n_330;
  v5 = v0 << 9;
  *(uint32_t *)rf_bus_write_n_330 &= ~4u;
  if ( (v0 & 0x400000) != 0 )
    goto rf_bus_mark_n_144;
rf_bus_mark_n_323_124c:
  v6 = v0 << 8;
  if ( (v0 & 0x800000) == 0 )
    goto rf_bus_mark_n_48d;
rf_bus_mark_n_131:
  v46 = dword_1116A0;
  v47 = *(uint32_t *)rf_bus_write_n_324;
  *(uint32_t *)rf_bus_write_n_324 = *(uint32_t *)rf_bus_write_n_324;
  sub_12ECB0(v46, v47, v6);
rf_bus_mark_n_48d:
  if ( (v0 & 0x400) != 0 )
  {
    v7 = rf_bus_mark_n_24c;
    v8 = *((uint8_t *)rf_bus_mark_n_24c + 1621);
    v9 = *((uint8_t *)rf_bus_mark_n_24c + 1622);
    if ( v8 >= v9 )
    {
      sub_12ECB0(rf_bus_reset2_n_18f, v8, v9);
    }
    else
    {
      v10 = *(uint32_t *)rf_bus_reset2_n_3bc;
      v11 = *((uint8_t *)rf_bus_mark_n_24c + 1620)
          + 1
          - 81
          * ((unsigned int)(((unsigned int)rf_bus_mark_0
                           * (unsigned uint64_t)((unsigned int)*((uint8_t *)rf_bus_mark_n_24c + 1620) + 1)) >> 32) >> 6);
      v12 = (char *)rf_bus_mark_n_24c + 20 * v11;
      v13 = off_1114A4;
      *((uint32_t *)v12 + 1) = *(uint32_t *)rf_bus_reset2_n_3b8;
      v7[1621] = v8 + 1;
      v14 = off_1114A8;
      *((uint32_t *)v12 + 2) = *v13;
      v12[12] = v10;
      v7[1620] = v11;
      v12[13] = BYTE1(v10) & 7;
      *v14 = 16;
      do
        v15 = *v14 & 0x20;
      while ( v15 );
      v16 = &v7[20 * v11];
      if ( (v16[13] & 4) == 0 )
        v15 = *(uint32_t *)(*((uint32_t *)v16 + 2) + 4);
      v17 = rf_bus_reset2_n_3a8_14b0;
      *(uint32_t *)rf_bus_mark_n_234 = v15;
      *v17 = 16;
      list_push_tail(rf_bus_mark_n_22c);
      irq_nesting_or(256);
    }
    v6 = 1024;
    *(uint32_t *)rf_bus_mark_from_stack_args = 1024;
  }
  if ( (v0 & 0x200) != 0 )
  {
    sub_12ECB0(rf_stream_start2_n_1a8, v5, v6);
    *(uint32_t *)off_1116C4 = 512;
  }
  if ( (v0 & 0x100) != 0 )
  {
    v18 = rf_bus_mark_n_24c;
    v19 = *((uint8_t *)rf_bus_mark_n_24c + 2433);
    v20 = *((uint8_t *)rf_bus_mark_n_24c + 2434);
    if ( v19 < v20 )
    {
      v38 = *(uint32_t *)rf_bus_reset2_167c;
      v39 = *(uint32_t *)rf_bus_write2_n_404;
      v40 = *((uint8_t *)rf_bus_mark_n_24c + 2432)
          + 1
          - 40
          * ((unsigned int)(((unsigned int)dword_111678
                           * (unsigned uint64_t)((unsigned int)*((uint8_t *)rf_bus_mark_n_24c + 2432) + 1)) >> 32) >> 5);
      v41 = (char *)rf_bus_mark_n_24c + 20 * v40;
      *((uint8_t *)rf_bus_mark_n_24c + 2432) = v40;
      v41[1645] = BYTE1(v38) & 7;
      *((uint32_t *)v41 + 409) = v39;
      *((uint32_t *)v41 + 410) = v39;
      v41[1644] = v38;
      v18[2433] = v19 + 1;
      list_push_tail(v18 + 2436);
      irq_nesting_or(0x400000);
    }
    else
    {
      sub_12ECB0(rf_bus_mark_n_228, v19, v20);
    }
    *(uint32_t *)rf_bus_mark_from_stack_args = 256;
  }
  result = v0 << 19;
  if ( (v0 & 0x1000) != 0 )
  {
    if ( *(uint8_t *)rf_bus_reset2_n_39b )
    {
      v22 = rf_bus_write_14c0;
      v23 = *((uint8_t *)rf_bus_write_14c0 + 369);
      *(uint8_t *)rf_bus_reset2_n_39b = 0;
      if ( v23 )
        irq_enable(1);
      else
        sub_10DB6C(1);
      if ( v22[374] == 1 )
        timestamp_remove_058(rf_bus_write_n_4fc);
    }
    v24 = rf_bus_write_4c8;
    v25 = *((uint8_t *)rf_bus_write_4c8 + 3074);
    v26 = *((uint8_t *)rf_bus_write_4c8 + 3073);
    if ( v25 < v26 )
    {
      v35 = *((uint8_t *)rf_bus_write_4c8 + 3072)
          + 1
          - 192
          * ((unsigned int)(((unsigned int)rf_bus_reset2_n_377
                           * (unsigned uint64_t)((unsigned int)*((uint8_t *)rf_bus_write_4c8 + 3072) + 1)) >> 32) >> 7);
      v36 = (char *)rf_bus_write_4c8 + 16 * v35;
      *((uint32_t *)v36 + 1) = *(uint32_t *)rf_bus_mark_n_1f0;
      v37 = rf_bus_write_n_4cb;
      v24[3072] = v35;
      *((uint16_t *)v36 + 4) = *v37;
      v24[3074] = v25 + 1;
      list_push_tail(v24 + 3080);
      result = irq_nesting_or(128);
    }
    else
    {
      result = sub_12ECB0(rf_bus_write_n_4f3, v25, v26);
    }
    v27 = rf_bus_mark_n_210;
    *(uint32_t *)rf_bus_mark_from_stack_args = 4096;
    if ( !*v27 )
      *(uint8_t *)rf_bus_mark_n_20c &= ~1u;
  }
  if ( (v0 & 0x800) != 0 )
  {
    if ( *(uint8_t *)rf_bus_reset2_n_39b )
    {
      v28 = rf_bus_write_14c0;
      v29 = *((uint8_t *)rf_bus_write_14c0 + 369);
      *(uint8_t *)rf_bus_reset2_n_39b = 0;
      if ( v29 )
        irq_enable(1);
      else
        sub_10DB6C(1);
      if ( v28[374] == 1 )
        timestamp_remove_058(rf_bus_write_n_4fc);
    }
    v30 = rf_bus_write_4c8;
    v31 = *((uint8_t *)rf_bus_write_4c8 + 6162);
    if ( *((uint8_t *)rf_bus_write_4c8 + 6161) > v31 )
    {
      v33 = *((uint8_t *)rf_bus_write_4c8 + 6160)
          + 1
          - 192
          * ((unsigned int)(((unsigned int)rf_bus_reset2_n_377
                           * (unsigned uint64_t)((unsigned int)*((uint8_t *)rf_bus_write_4c8 + 6160) + 1)) >> 32) >> 7);
      v34 = rf_bus_reset2_n_374_14e4;
      *((uint8_t *)rf_bus_write_4c8 + 6160) = v33;
      v30[4 * v33 + 773] = *v34;
      LOWORD(v30[4 * v33 + 774]) = *(uint32_t *)rf_bus_write_14e8;
      *((uint8_t *)v30 + 6162) = v31 + 1;
      list_push_tail(rf_bus_write_4ec);
      result = irq_nesting_or(64);
    }
    else
    {
      result = sub_12ECB0(rf_bus_reset2_n_37f, v31, v31);
    }
    v32 = rf_bus_mark_n_204;
    *(uint32_t *)rf_bus_mark_from_stack_args = 2048;
    if ( !*v32 )
      *(uint8_t *)rf_bus_mark_n_20c &= ~2u;
  }
  if ( (v0 & 4) != 0 )
    *(uint32_t *)rf_bus_mark_from_stack_args = 4;
  if ( (v0 & 8) != 0 )
    *(uint32_t *)rf_bus_mark_from_stack_args = 8;
  return result;
}

