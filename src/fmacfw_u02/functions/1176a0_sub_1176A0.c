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

extern uint32_t dword_11788C;
extern uint32_t off_117888;
extern uint32_t dword_1178C0;
extern uint32_t off_117890;
extern uint32_t dword_117894;
extern uint32_t off_117898;
extern uint32_t off_11789C;
extern uint32_t dword_1178BC;
extern uint32_t off_1178A0;
extern uint32_t off_1178A4;
extern uint32_t off_1178A8;
extern uint32_t off_1178AC;
extern uint32_t off_1178B0;
extern uint32_t off_1178B4;
extern uint32_t dword_1178B8;

// phy_radio_init @ 0x1176a0, size 488 bytes
// Doc: sub_12176A0 [unknown]: Dispatch handler on r1 opcode (cases up to 5)
// sub_12176A0 [unknown]: Dispatch handler on r1 opcode (cases up to 5)
int  phy_radio_init(int a1, int a2)
{
  char *v4; // r7
  int v5; // r10
  int v6; // r8
  int v7; // r11
  int v8; // r9
  int v10; // r3
  int16_t v11; // r1
  int v12; // r6
  int v13; // r3
  int *v14; // r6
  int v15; // r2
  char v16; // r3
  int v17; // r0
  int v18; // r1
  uint8_t *v19; // r3
  int v20; // r3
  int v21; // r2
  int v22; // r2
  int v23; // r1
  int16_t v24; // r3
  int *v25; // r3
  int v26; // r3
  int v27; // r2
  int v28; // r3
  int v29; // r2
  uint32_t *v30; // r3
  int v31; // [sp+4h] [bp-8h]

  if ( a2 == 5 )
    v4 = (char *)dword_11788C;
  else
    v4 = (char *)off_117888 + 84 * a2;
  v5 = *(uint8_t *)(a1 + 28);
  v6 = dword_1178C0;
  v7 = *(uint32_t *)(a1 + 76);
  v8 = dword_1178C0 + 1320 * v5;
  if ( isr_flag_dispatch(v8)
    && ((v10 = *(uint8_t *)(a1 + 28), *(uint8_t *)(v6 + 1320 * v10 + 106))
     || *(uint8_t *)(a1 + 29) > 0x23u
     || *(uint16_t *)(a1 + 4)
     || (v11 = *(uint16_t *)(*(uint32_t *)(a1 + 72) + 108), (uint8_t)v11 != 192)
     && (uint8_t)v11 != 176
     && (v11 & 0xDF) != 0
     || (v12 = *((uint32_t *)off_117890 + 10)) == 0
     || *(uint8_t *)(v12 + 24) <= 2u
     || (v13 = *(uint32_t *)(v6 + 1320 * v10 + 72)) == 0
     || (v31 = v13, event_dispatch(dword_117894, v12 == v13, (uint8_t)v11), v12 == v31))
    && bt_is_link_active(a1) )
  {
    *(uint32_t *)(v7 + 68) |= 0x100u;
    if ( (__get_CPSR() & 1) == 0 )
    {
      __disable_irq();
      *(uint32_t *)off_117898 = 1;
    }
    v14 = (int *)off_11789C;
    v15 = *((uint32_t *)v4 + 11);
    v16 = v4[80] + 1;
    ++*(uint32_t *)off_11789C;
    v4[80] = v16;
    if ( v15 )
      rate_get_config(a2);
    if ( !*((uint32_t *)v4 + 5) )
    {
      v30 = *(uint32_t **)(a1 + 72);
      v30[4] = dword_1178BC;
      v30[2] = a1;
      v30[3] = a1;
    }
    v17 = cmd_handler_a(v4 + 12);
    v18 = *((uint32_t *)off_1178A0 + 8);
    ++*((uint32_t *)off_117888 + 126);
    if ( v18 )
    {
      v19 = *(uint8_t **)off_1178A4;
      v17 = 0x80000000;
      *(uint32_t *)off_1178A8 = 0x80000000;
      if ( *v19 == 3 && v18 == v8 )
        *(uint32_t *)(v6 + 1320 * v5 + 120) = *((uint32_t *)off_1178AC + 4);
    }
    if ( **(uint8_t **)off_1178B0 == 2 && (*(uint32_t *)off_1178B4 & dword_1178B8) == 0 )
      process_global_167204(v17, v18, *(uint32_t *)off_1178B4);
    if ( *v14 )
    {
      v20 = *v14 - 1;
      v21 = *(uint32_t *)off_117898;
      *v14 = v20;
      if ( !v20 )
      {
        if ( v21 )
          __enable_irq();
      }
    }
    if ( (__get_CPSR() & 1) == 0 )
    {
      __disable_irq();
      *(uint32_t *)off_117898 = 1;
    }
    v22 = *v14;
    v23 = *v14 + 1;
    v24 = *(uint16_t *)(a1 + 82) | 1;
    *v14 = v23;
    *(uint16_t *)(a1 + 82) = v24;
    if ( v23 )
    {
      v25 = (int *)off_117898;
      *v14 = v22;
      v26 = *v25;
      if ( !v22 )
      {
        if ( v26 )
          __enable_irq();
      }
    }
    if ( (__get_CPSR() & 1) == 0 )
    {
      __disable_irq();
      *(uint32_t *)off_117898 = 1;
    }
    v27 = *(uint32_t *)(a1 + 72);
    ++*v14;
    mac_flags_set(a1, a1, v27, a2);
    if ( *v14 )
    {
      v28 = *v14 - 1;
      v29 = *(uint32_t *)off_117898;
      *v14 = v28;
      if ( !v28 )
      {
        if ( v29 )
          __enable_irq();
      }
    }
    return 1;
  }
  else if ( *(uint8_t *)(a1 + 29) == 255 )
  {
    scan_control(a1, 0);
    return 0;
  }
  else
  {
    phy_ctx_get_by_index((uint8_t *)a1, a2);
    return 1;
  }
}

