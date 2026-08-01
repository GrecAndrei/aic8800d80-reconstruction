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

extern uint32_t off_1351F8;
extern uint32_t dword_1351FC;
extern uint32_t dword_135204;
extern uint32_t dword_135200;
extern uint32_t off_135220;
extern uint32_t dword_135208;
extern uint32_t off_135214;
extern uint32_t dword_13521C;
extern uint32_t dword_135218;
extern uint32_t dword_135210;
extern uint32_t off_13520C;

// ll_evt_schedule @ 0x135028, size 462 bytes
void  ll_evt_schedule(
        int a1,
        char *a2,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13)
{
  uint8_t *v13; // r7
  int v14; // r5
  int v15; // r6
  int v16; // r11
  uint8_t *v17; // r4
  int v20; // r10
  int v21; // r0
  int v22; // r1
  int v23; // r2
  int v24; // r3
  int v25; // r4
  int v26; // r5
  int v27; // r3
  uint16_t *v28; // r12
  int v29; // r2
  int16_t v30; // r1
  int v31; // t1
  int v32; // lr
  int16_t v33; // r0
  int v34; // r1
  int v35; // r10
  int v36; // r11
  int v37; // r11
  uint32_t *v38; // r1
  int v39; // r5
  int v40; // r0
  unsigned int v41; // r0
  char *v42; // r1
  char *v43; // r0
  char *v44; // r2
  char v45; // t1
  unsigned int v46; // [sp+Ch] [bp-8h]

  v13 = off_1351F8;
  v14 = dword_1351FC;
  v15 = *((uint32_t *)off_1351F8 + 4);
  v16 = *(uint8_t *)(v15 + 61);
  v17 = (uint8_t *)(dword_1351FC + 1320 * v16);
  v20 = v17[116];
  check_feature_flag(256, dword_135204, dword_135200);
  if ( !v17[1224] )
  {
    v21 = v17[412];
    if ( v17[412] )
      v21 = 1;
    v25 = lock_acquire(v21, 512);
    if ( v25 )
      goto LABEL_5;
LABEL_10:
    assert_trace(1, v22, v23, v24, a5, a6, a7, a8, a9, a10, a11, a12, a13);
    return;
  }
  v25 = lock_acquire(1, 512);
  if ( !v25 )
    goto LABEL_10;
LABEL_5:
  v26 = v14 + 1320 * v16;
  get_status_flag_c5(v26, v25);
  v27 = *(uint32_t *)(v25 + 72);
  v28 = off_135220;
  v29 = dword_135208 + 696 * v20;
  v30 = *((uint16_t *)off_135220 + 254);
  v31 = *(uint32_t *)(v29 + 38);
  v29 += 38;
  *(uint32_t *)(v27 + 112) = v31;
  *(uint8_t *)(v27 + 108) = -80;
  *(uint16_t *)(v27 + 116) = *(uint16_t *)(v29 + 4);
  *(uint32_t *)(v27 + 118) = *(uint32_t *)(v26 + 100);
  v32 = *(uint32_t *)v29;
  *(uint16_t *)(v27 + 122) = *(uint16_t *)(v26 + 104);
  ++v30;
  *(uint16_t *)(v27 + 128) = *(uint16_t *)(v29 + 4);
  *(uint32_t *)(v27 + 124) = v32;
  *(uint8_t *)(v27 + 109) = 0;
  *(uint8_t *)(v27 + 110) = 0;
  *(uint8_t *)(v27 + 111) = 0;
  v33 = 16 * v30;
  v28[254] = v30;
  LOBYTE(v30) = *(uint8_t *)(v26 + 107);
  *(uint16_t *)(v27 + 130) = v33;
  *(uint8_t *)(v25 + 28) = v30;
  *(uint8_t *)(v25 + 29) = *(uint8_t *)(v26 + 116);
  *(uint8_t *)(v25 + 51) = 0;
  *(uint8_t *)(v25 + 53) = 0;
  v34 = *(uint8_t *)(v15 + 59);
  v35 = v27 + 108;
  if ( v34 == 1 && a1 == 3 )
  {
    get_config_flag(v25, v27 + 108, 24);
    LOWORD(v34) = *(uint8_t *)(v15 + 59);
    v36 = *(uint8_t *)(v25 + 51) + 24;
  }
  else
  {
    v36 = 24;
  }
  v37 = v36 + store_four_halfwords(v35 + v36, v34, a1, 0, a2);
  if ( *(uint8_t *)(v15 + 59) == 2 )
  {
    v41 = *(uint16_t *)(v15 + 54);
    if ( 512 - v37 < v41 )
    {
      if ( **(int16_t **)off_135214 < 0 )
        mmio_write_field(dword_13521C, dword_135218, 1015);
    }
    else
    {
      v42 = (char *)(v15 + 64);
      if ( *(uint16_t *)(v15 + 54) )
      {
        v43 = &v42[v41];
        do
        {
          v44 = v42 - 64;
          v45 = *v42++;
          v44[v35 + v37 - v15] = v45;
        }
        while ( v42 != v43 );
        v41 = *(uint16_t *)(v15 + 54);
      }
      v37 += v41;
    }
  }
  v38 = *(uint32_t **)(v25 + 76);
  v39 = dword_135210;
  v40 = *(uint8_t *)(v25 + 53) + v37;
  v46 = *(uint32_t *)(*(uint32_t *)off_13520C + 12);
  v38[8] = v38[7] - 1 + v40;
  v38[9] = v40 + 4;
  *(uint32_t *)(v25 + 88) = v39;
  *(uint32_t *)(v25 + 92) = v25;
  sec_check(v25, 5);
  v13[34] = 1;
  ke_event_handler(6154, 6, v46);
  hci_cmd_preprocess(6u, 5);
}

