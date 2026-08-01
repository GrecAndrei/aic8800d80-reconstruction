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

extern uint32_t dword_1316DC;
extern uint32_t off_1316E4;
extern uint32_t off_1316E0;
extern uint32_t off_131714;
extern uint32_t off_1316F4;
extern uint32_t off_1316F0;
extern uint32_t off_131708;
extern uint32_t off_13170C;
extern uint32_t off_1316F8;
extern uint32_t off_131704;
extern uint32_t off_131700;
extern uint32_t dword_131710;
extern uint32_t off_1316FC;
extern uint32_t off_1316EC;
extern uint32_t off_1316E8;
extern uint32_t off_13171C;
extern uint32_t off_131718;
extern uint32_t off_131720;
extern uint32_t off_131724;
extern uint32_t off_13172C;
extern uint32_t off_131730;
extern uint32_t off_131728;

// rf_config_band @ 0x1314f4, size 486 bytes
int  rf_config_band(int a1, uint8_t *a2, int16_t a3, int16_t a4)
{
  int v7; // r1
  uint8_t *v8; // r3
  uint32_t *v10; // r1
  uint32_t *v11; // r2
  uint32_t *v12; // r0
  uint32_t *v13; // r7
  int v14; // r4
  uint32_t *v15; // r2
  int v16; // r3
  int v17; // r1
  uint32_t *v18; // r2
  uint32_t *v19; // r0
  int v20; // r4
  uint32_t *v21; // r7
  uint8_t *v22; // r2
  int *v23; // r4
  int v24; // r3
  int v25; // r1
  int v26; // r0
  uint32_t *v27; // r2
  uint32_t *v28; // r0
  uint32_t *v29; // r4
  uint32_t *v30; // r2
  uint32_t *v31; // r7
  uint32_t *v32; // r0
  uint32_t *v33; // r3
  unsigned int *v34; // r1
  uint32_t *v35; // r2

  state_check_feature(2, dword_1316DC, *a2, a2[1]);
  v7 = *a2;
  v8 = off_1316E4;
  **(uint8_t **)off_1316E0 = v7;
  v8[412] = a2[1];
  if ( v7 == 1 )
  {
    if ( v8[189] )
    {
      v27 = off_131714;
      v28 = off_1316F4;
      *(uint32_t *)off_1316F0 &= ~0x2000000u;
      *v27 |= 0x200000u;
      *v28 = 36;
    }
    else
    {
      v18 = off_1316F0;
      v19 = off_131708;
      v20 = *((uint8_t *)off_131708 + 18);
      v21 = off_1316F4;
      *(uint32_t *)off_1316F0 |= 0x2000000u;
      *v21 = 4;
      if ( !v20 )
      {
        *(uint32_t *)off_13170C = 1;
        v18[8202] &= 0xFFFBFFFE;
      }
      v22 = off_1316F8;
      if ( *((uint8_t *)off_1316F8 + 28) )
      {
        if ( !*((uint8_t *)off_1316F8 + 29) )
        {
          v23 = (int *)v19[2];
          if ( v23 )
          {
            while ( !*((uint8_t *)v23 + 108) || *((uint8_t *)v23 + 106) )
            {
              v23 = (int *)*v23;
              if ( !v23 )
                goto LABEL_21;
            }
            v24 = *((uint32_t *)off_131704 + 4);
            v25 = *(uint16_t *)(*(uint32_t *)off_131700 + 54);
            v26 = dword_131710;
            *((uint32_t *)off_1316F8 + 5) = v23;
            v22[29] = 4;
            ke_event_lock(v26, v25 + v24);
            v23[1] |= 0x200u;
          }
        }
      }
    }
LABEL_21:
    *((uint32_t *)off_1316FC + 20) |= 0x40000u;
  }
  else if ( v7 == 2 )
  {
    v10 = off_1316EC;
    v11 = off_1316F0;
    v12 = off_1316F4;
    v13 = off_1316F8;
    *(uint32_t *)off_1316EC |= 0x10000u;
    v14 = v13[8];
    *v11 &= ~0x2000000u;
    *v12 = 63;
    v15 = off_1316FC;
    v10[10] &= ~1u;
    v15[20] &= ~0x40000u;
    if ( v14 && *(uint8_t *)(v14 + 108) )
    {
      v16 = *((uint32_t *)off_131704 + 4);
      v17 = *(uint16_t *)(*(uint32_t *)off_131700 + 54);
      v13[5] = v14;
      *((uint8_t *)v13 + 29) = 4;
      ke_event_lock((int)(v13 + 3), v17 + v16);
      *(uint32_t *)(v14 + 4) |= 0x200u;
      ke_event_set_lock(v14 + 24);
    }
  }
  else if ( !v7 && **(uint8_t **)off_1316E8 == 3 )
  {
    v29 = off_1316EC;
    v30 = off_1316F0;
    v31 = off_1316F4;
    *(uint32_t *)off_1316EC &= ~0x10000u;
    *v30 |= 0x2000000u;
    *v31 = 0;
    v32 = off_1316FC;
    v29[10] |= 1u;
    v32[20] |= 0x40000u;
    if ( (*v30 & 4) != 0 )
    {
      if ( v8[190] )
      {
        v33 = off_13171C;
        *(uint32_t *)off_131718 &= ~0x200u;
        *v33 &= ~1u;
        *v33 &= ~0x80u;
      }
      *(uint32_t *)off_131720 = 48;
      sleep_critical_exit();
      mm_beacon_irq();
    }
    if ( !*((uint8_t *)off_131724 + 36) )
    {
      v34 = (unsigned int *)off_13172C;
      v35 = off_131730;
      *(uint32_t *)off_131728 &= ~0x40000u;
      *v34 = *v34 & 0xFFFFFFF0 | 8;
      *v35 |= 1u;
    }
  }
  hci_evt_alloc_send(5142, a4, a3);
  return 0;
}

