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


extern uint32_t dword_11284C;
extern uint32_t dword_112850;
extern uint32_t dword_112854;
extern uint32_t dword_112868;
extern uint32_t dword_11286C;
extern uint32_t dword_112870;
extern uint32_t dword_112874;
extern uint32_t off_112848;
extern uint32_t off_11285C;
extern uint32_t off_112860;
extern uint32_t off_112864;

// mmio_read_irq_status @ 0x1125f4, size 594 bytes
int mmio_read_irq_status()
{
  uint32_t *v0; // r3
  int v1; // r2
  int v2; // r4
  uint64_t v3; // r0
  int v4; // r10
  int v5; // r2
  int v6; // r8
  int v7; // r11
  uint32_t *v8; // r6
  int v9; // r5
  unsigned int v10; // r2
  int v11; // r4
  int v12; // r9
  char *v13; // r3
  int v14; // r1
  int ( *v15)(int, int, BOOL); // r3
  uint32_t *v16; // r5
  int v17; // r6
  int v18; // r9
  int v19; // r7
  int i; // r4
  char *v21; // r3
  int v22; // r2
  uint64_t v23; // r0
  int v24; // r3
  int v25; // r3
  int v26; // r3
  uint32_t *v27; // r3
  uint32_t *v28; // r4
  int *v29; // r0
  int v30; // r1
  int v31; // r4
  int ( *v32)(int, int, uint32_t); // r3
  BOOL v34; // [sp+4h] [bp-10h]
  int v35; // [sp+4h] [bp-10h]
  int v36; // [sp+8h] [bp-Ch]
  int v37; // [sp+8h] [bp-Ch]
  int v38; // [sp+Ch] [bp-8h]
  int v39; // [sp+Ch] [bp-8h]

  v0 = off_112848;
  v1 = *((uint32_t *)off_112848 + 5);
  *((uint32_t *)off_112848 + 5) = v1;
  v2 = v0[6] & v1;
  LODWORD(v3) = v2 << 19;
  if ( (v2 & 0x1000) != 0 )
  {
    LODWORD(v3) = rf_init_1();
    v4 = v2 & 0x2000;
    if ( (v2 & 0x2000) == 0 )
      return v3;
    v7 = 0;
    v6 = 0;
    v5 = 0;
  }
  else
  {
    v4 = v2 & dword_112870;
    v5 = v2 & 0x40000;
    v6 = v2 & 0x80000;
    v7 = v2 & 0x800;
    if ( (v2 & 0x2000) == 0 )
      goto LABEL_3;
  }
  v26 = *((uint32_t *)off_112848 + 514);
  if ( (v26 & 6) != 0 && (v26 & 2) != 0 )
    *(uint32_t *)off_11285C = 1;
  v27 = off_112848;
  v28 = off_112860;
  v29 = (int *)off_112864;
  v30 = dword_112868;
  *((uint32_t *)off_112848 + 576) = dword_112868;
  v27[704] = v30;
  HIDWORD(v3) = *v28;
  v31 = *v29;
  LODWORD(v3) = dword_11286C;
  *(uint32_t *)HIDWORD(v3) = dword_11286C;
  *(uint32_t *)(HIDWORD(v3) + 4) = v31;
  v27[709] = HIDWORD(v3);
  v27[706] = v27[706];
  v27[704] |= 0x84000000;
LABEL_3:
  if ( v5 )
  {
    v8 = off_112848;
    v9 = dword_11284C;
    v10 = *((uint32_t *)off_112848 + 518);
    v11 = 0;
    v12 = v10 & *((uint32_t *)off_112848 + 519);
    while ( 1 )
    {
      LODWORD(v3) = 1;
      if ( ((1 << v11) & v12) != 0 )
      {
        if ( !v11 )
        {
          HIDWORD(v3) = v8[578];
          v8[578] = HIDWORD(v3);
          v25 = v8[516] & HIDWORD(v3);
          if ( (v25 & 0x18) != 0 )
          {
            v8[516] &= ~0x10u;
            rf_channel_get_flag(0, 0x200000, 0);
          }
          else if ( (v25 & 1) != 0 )
          {
            util_check_flags(v3, (uint32_t *)v10);
          }
          goto LABEL_14;
        }
        v13 = (char *)&v8[8 * v11 - 8];
        v10 = *((uint32_t *)v13 + 586);
        *((uint32_t *)v13 + 586) = v10;
        v14 = v8[516] & v10;
        if ( (v14 & 9) != 0 )
        {
          if ( *(uint8_t *)(v9 - 5) )
          {
            v36 = *(uint32_t *)(v9 - 12);
            v38 = *(uint32_t *)(v9 - 16);
            v34 = (v10 & 1) == 0;
            if ( (v10 & 1) == 0 )
              rf_enable_tx_patch(1, (uint8_t)v11);
            LODWORD(v3) = memset_thunk((int *)(v9 - 16), 0, 0x10u);
            v15 = *(int ( **)(int, int, BOOL))(dword_112850 + 4 * v11 + 52);
            if ( v15 )
              LODWORD(v3) = v15(v38, v36, v34);
          }
        }
        else
        {
          LODWORD(v3) = log_printf("irq %x\r\n", v14);
        }
      }
      if ( (uint8_t)v11 == 5 )
        break;
LABEL_14:
      ++v11;
      v9 += 16;
    }
  }
  if ( v6 )
  {
    v16 = off_112848;
    v17 = dword_112854;
    v18 = dword_112874;
    v19 = *((uint32_t *)off_112848 + 518) & *((uint32_t *)off_112848 + 519);
    for ( i = 0; ; ++i )
    {
      if ( ((0x10000 << i) & v19) != 0 )
      {
        if ( !i )
        {
          HIDWORD(v23) = v16[706];
          v16[706] = HIDWORD(v23);
          v24 = v16[517] & HIDWORD(v23);
          if ( (v24 & 0x10) != 0 )
          {
            v16[517] &= ~0x10u;
            LODWORD(v3) = rf_channel_set_flag(0, 0x200000, 0);
          }
          else if ( (v24 & 0x29) != 0 )
          {
            LODWORD(v23) = 0;
            LODWORD(v3) = util_check_flags(v23, (uint32_t *)(v24 << 27));
          }
          goto LABEL_19;
        }
        v21 = (char *)&v16[8 * i - 8];
        v22 = *((uint32_t *)v21 + 714);
        *((uint32_t *)v21 + 714) = v22;
        if ( (v16[517] & v22 & 1) != 0 )
        {
          if ( *(uint8_t *)(v17 - 8) )
          {
            v37 = **(uint16_t **)(v18 + 4 * i);
            v35 = *(uint32_t *)(v17 - 12);
            v39 = *(uint32_t *)(v17 - 16);
            LODWORD(v3) = memset_thunk((int *)(v17 - 16), 0, 0x10u);
            v32 = *(int ( **)(int, int, uint32_t))(4 * i + dword_112850 + 32);
            if ( v32 )
              LODWORD(v3) = v32(v39, v35 - v37, 0);
          }
        }
      }
      if ( (uint8_t)i == 5 )
        break;
LABEL_19:
      v17 += 16;
    }
  }
  if ( v7 )
  {
    LODWORD(v3) = ke_poll_event_a();
    if ( v4 >= 0 )
      return v3;
  }
  else if ( v4 >= 0 )
  {
    return v3;
  }
  LODWORD(v3) = ke_poll_event_b();
  return v3;
}
