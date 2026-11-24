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


extern uint32_t dword_1351FC;
extern uint32_t dword_135208;
extern uint32_t off_1351F8;
extern uint32_t off_13520C;
extern uint32_t off_135210;
extern uint32_t off_135214;
extern uint32_t off_13521C;
extern uint32_t off_135220;

// ll_evt_schedule @ 0x135028, size 462 bytes
int  ll_evt_schedule(int a1, int a2)
{
  uint8_t *v2; // r7
  int v3; // r5
  int v4; // r6
  int v5; // r11
  uint8_t *v6; // r4
  int v9; // r10
  int v10; // r0
  uint32_t *v11; // r4
  int v12; // r5
  int v13; // r3
  uint16_t *v14; // r12
  int v15; // r2
  uint16_t v16; // r1
  int v17; // t1
  int v18; // lr
  uint16_t v19; // r0
  int v20; // r1
  int v21; // r10
  int v22; // r11
  int v23; // r11
  uint32_t *v24; // r1
  void *v25; // r5
  int v26; // r0
  unsigned int v28; // r0
  char *v29; // r1
  char *v30; // r0
  char *v31; // r2
  char v32; // t1
  unsigned int a3; // [sp+Ch] [bp-8h]

  v2 = off_1351F8;
  v3 = dword_1351FC;
  v4 = *((uint32_t *)off_1351F8 + 4);
  v5 = *(uint8_t *)(v4 + 61);
  v6 = (uint8_t *)(dword_1351FC + 1320 * v5);
  v9 = v6[116];
  check_feature_flag(256, "%s\r\n", aSmAuthSend);
  if ( !v6[1224] )
  {
    v10 = v6[412];
    if ( v6[412] )
      v10 = 1;
    v11 = lock_acquire(v10, 512);
    if ( v11 )
      goto LABEL_5;
    return assert_trace(1);
  }
  v11 = lock_acquire(1, 512);
  if ( !v11 )
    return assert_trace(1);
LABEL_5:
  v12 = v3 + 1320 * v5;
  get_status_flag_c5(v12, (int)v11);
  v13 = v11[18];
  v14 = off_135220;
  v15 = dword_135208 + 696 * v9;
  v16 = *((uint16_t *)off_135220 + 254);
  v17 = *(uint32_t *)(v15 + 38);
  v15 += 38;
  *(uint32_t *)(v13 + 112) = v17;
  *(uint8_t *)(v13 + 108) = -80;
  *(uint16_t *)(v13 + 116) = *(uint16_t *)(v15 + 4);
  *(uint32_t *)(v13 + 118) = *(uint32_t *)(v12 + 100);
  v18 = *(uint32_t *)v15;
  *(uint16_t *)(v13 + 122) = *(uint16_t *)(v12 + 104);
  ++v16;
  *(uint16_t *)(v13 + 128) = *(uint16_t *)(v15 + 4);
  *(uint32_t *)(v13 + 124) = v18;
  *(uint8_t *)(v13 + 109) = 0;
  *(uint8_t *)(v13 + 110) = 0;
  *(uint8_t *)(v13 + 111) = 0;
  v19 = 16 * v16;
  v14[254] = v16;
  LOBYTE(v16) = *(uint8_t *)(v12 + 107);
  *(uint16_t *)(v13 + 130) = v19;
  *((uint8_t *)v11 + 28) = v16;
  *((uint8_t *)v11 + 29) = *(uint8_t *)(v12 + 116);
  *((uint8_t *)v11 + 51) = 0;
  *((uint8_t *)v11 + 53) = 0;
  v20 = *(uint8_t *)(v4 + 59);
  v21 = v13 + 108;
  if ( v20 == 1 && a1 == 3 )
  {
    get_config_flag((int)v11, (uint16_t *)(v13 + 108), 24);
    LOWORD(v20) = *(uint8_t *)(v4 + 59);
    v22 = *((uint8_t *)v11 + 51) + 24;
  }
  else
  {
    v22 = 24;
  }
  v23 = v22 + store_four_halfwords(v21 + v22, v20, a1, 0, (char *)a2);
  if ( *(uint8_t *)(v4 + 59) == 2 )
  {
    v28 = *(uint16_t *)(v4 + 54);
    if ( 512 - v23 < v28 )
    {
      if ( **(uint16_t **)off_135214 < 0 )
        mmio_write_field(off_13521C, (int)aSmAuthSend_0, 1015);
    }
    else
    {
      v29 = (char *)(v4 + 64);
      if ( *(uint16_t *)(v4 + 54) )
      {
        v30 = &v29[v28];
        do
        {
          v31 = v29 - 64;
          v32 = *v29++;
          v31[v21 + v23 - v4] = v32;
        }
        while ( v29 != v30 );
        v28 = *(uint16_t *)(v4 + 54);
      }
      v23 += v28;
    }
  }
  v24 = (uint32_t *)v11[19];
  v25 = off_135210;
  v26 = *((uint8_t *)v11 + 53) + v23;
  a3 = *(uint32_t *)(*(uint32_t *)off_13520C + 12);
  v24[8] = v24[7] - 1 + v26;
  v24[9] = v26 + 4;
  v11[22] = v25;
  v11[23] = v11;
  sec_check((int)v11, 5);
  v2[34] = 1;
  ke_event_handler(6154, 6, a3);
  return hci_cmd_preprocess(6u, 5);
}
