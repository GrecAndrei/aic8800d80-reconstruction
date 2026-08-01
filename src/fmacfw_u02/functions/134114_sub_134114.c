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

extern uint32_t off_134350;
extern uint32_t dword_13435C;
extern uint32_t dword_134358;
extern uint32_t dword_134360;
extern uint32_t dword_134364;
extern uint32_t off_134354;

// complex_state_handler @ 0x134114, size 570 bytes
int  complex_state_handler(int a1, uint8_t *a2)
{
  int v3; // r5
  int v4; // r8
  int v5; // r11
  int v6; // r6
  int v7; // r9
  uint32_t *v8; // r12
  int v9; // r0
  int v10; // r1
  int v11; // r2
  int v12; // r3
  int v13; // lr
  uint32_t *v14; // r3
  int *v15; // r12
  int v16; // r0
  int v17; // r1
  int v18; // r2
  int v19; // r3
  uint32_t *v20; // r10
  int v21; // r0
  int v22; // r1
  int v23; // r2
  int v24; // r3
  int v25; // r1
  int v26; // r2
  int v27; // r3
  int v28; // r1
  int v29; // r2
  int v30; // r3
  int v31; // r1
  int v32; // r2
  int v33; // r3
  int v34; // r1
  int v35; // r1
  int v36; // r2
  uint32_t *v37; // r3
  int v38; // r2
  uint8_t *v39; // r7
  uint8_t *v40; // r12
  char *v41; // r10
  int v42; // r4
  char *v43; // r1
  uint8_t *v44; // r2
  char v45; // r0
  char v46; // t1
  unsigned int v47; // r3
  uint32_t *i; // r3
  int v49; // r2
  int v51; // [sp+0h] [bp-2Ch]
  int v52; // [sp+8h] [bp-24h]
  int v53; // [sp+8h] [bp-24h]
  uint32_t *v54; // [sp+Ch] [bp-20h]
  uint32_t v55[3]; // [sp+10h] [bp-1Ch] BYREF
  uint32_t v56[4]; // [sp+1Ch] [bp-10h] BYREF

  if ( **(int16_t **)off_134350 < 0 && rx_rate_field_parse(6u) != 3 )
    mmio_clear_register(dword_13435C, dword_134358, 481);
  v3 = *a2;
  if ( *a2 )
  {
    bt_setup_conn_profile(1);
    return 0;
  }
  else
  {
    v4 = dword_134360;
    v5 = dword_134364;
    v51 = a2[1];
    v6 = dword_134360 + 696 * v51;
    v7 = *(uint8_t *)(v6 + 34);
    v8 = (uint32_t *)(dword_134364 + 1320 * v7);
    v9 = v8[106];
    v10 = v8[107];
    v11 = v8[108];
    v12 = v8[109];
    *(uint32_t *)(v6 + 192) = v9;
    *(uint32_t *)(v6 + 196) = v10;
    *(uint32_t *)(v6 + 200) = v11;
    v13 = v8[118];
    *(uint8_t *)(v6 + 204) = v12;
    if ( (v13 & 0x10) != 0 )
      *(uint32_t *)(v6 + 4) |= 0x40u;
    if ( (v13 & 1) != 0 )
      *(uint32_t *)(v4 + 696 * v51 + 4) |= 1u;
    if ( (v13 & 2) != 0 )
    {
      v14 = (uint32_t *)(v5 + 1320 * v7);
      v15 = v14 + 62;
      v54 = v14;
      v16 = v14[62];
      v17 = v14[63];
      v18 = v14[64];
      v19 = v14[65];
      v15 += 4;
      v20 = (uint32_t *)(v4 + 696 * v51);
      v20[52] = v16;
      v20[53] = v17;
      v20[54] = v18;
      v20[55] = v19;
      v21 = *v15;
      v22 = v15[1];
      v23 = v15[2];
      v24 = v15[3];
      v52 = v20[1];
      v20[1] = v52 | 2;
      v20[56] = v21;
      v20[57] = v22;
      v20[58] = v23;
      v20[59] = v24;
      if ( (v13 & 8) != 0 )
      {
        v25 = v54[74];
        v26 = v54[75];
        v27 = v54[76];
        v20[63] = v54[73];
        v20[64] = v25;
        v20[65] = v26;
        v20[66] = v27;
        v28 = v54[78];
        v29 = v54[79];
        v30 = v54[80];
        v20[67] = v54[77];
        v20[68] = v28;
        v20[69] = v29;
        v20[70] = v30;
        v31 = v54[82];
        v32 = v54[83];
        v33 = v54[84];
        v20[71] = v54[81];
        v20[72] = v31;
        v20[73] = v32;
        v20[74] = v33;
        v34 = v54[86];
        v20[75] = v54[85];
        v20[76] = v34;
        v20[1] = v52 | 0x22;
      }
      if ( (v13 & 4) != 0 )
      {
        v35 = *(uint32_t *)(v5 + 1320 * v7 + 284);
        v36 = *(uint32_t *)(v5 + 1320 * v7 + 288);
        v37 = (uint32_t *)(v4 + 696 * v51);
        v37[60] = *(uint32_t *)(v5 + 1320 * v7 + 280);
        v37[61] = v35;
        v37[62] = v36;
        v37[1] |= 4u;
      }
      v9 = rf_check_status(v6, v5 + 1320 * v7 + 248);
    }
    bt_get_profile_ctx(v9);
    if ( *(uint8_t *)off_134354 )
    {
      v38 = *(uint8_t *)(v4 + 696 * v51 + 192);
      memset(v55, 0, sizeof(v55));
      memset(v56, 0, 12);
      if ( v38 )
      {
        v39 = v55;
        v40 = (uint8_t *)v56;
        v53 = (uint8_t)(v38 - 1);
        v41 = (char *)v55 + v53 + 1;
        v42 = 696 * v51 + 192 + v4;
        v43 = (char *)v55;
        v44 = v56;
        do
        {
          while ( 1 )
          {
            v46 = *(uint8_t *)++v42;
            v45 = v46;
            v47 = (uint8_t)((v46 & 0x7F) - 2);
            if ( v47 <= 9 && ((1 << v47) & 0x205) != 0 )
              break;
            *v43++ = v45;
            *v44++ = 1;
            if ( v43 == v41 )
              goto LABEL_20;
          }
          *v43++ = v45;
          *v44++ = 0;
        }
        while ( v43 != v41 );
LABEL_20:
        for ( i = (uint32_t *)((char *)v56 + 1); ; i = (uint32_t *)((char *)i + 1) )
        {
          v49 = *v40;
          v40 = (uint8_t *)i;
          if ( v49 )
          {
            *(uint8_t *)(v4 + 696 * v51 + v3 + 193) = *v39;
            v3 = (uint8_t)(v3 + 1);
          }
          ++v39;
          if ( i == (uint32_t *)((char *)v56 + v53 + 1) )
            break;
        }
      }
      else
      {
        LOBYTE(v3) = 0;
      }
      *(uint8_t *)(v4 + 696 * v51 + 192) = v3;
    }
    stub_ret(v6);
    return 0;
  }
}

