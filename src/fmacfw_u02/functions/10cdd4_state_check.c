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

extern uint32_t off_10D0A4;
extern uint32_t off_10D0AC;
extern uint32_t off_10D0B0;
extern uint32_t off_10D0A8;
extern uint32_t dword_10D19C;
extern uint32_t dword_10D198;
extern uint32_t dword_10D1A4;
extern uint32_t dword_10D1A0;
extern uint32_t dword_10D0D0;
extern uint32_t off_10D0CC;
extern uint32_t dword_10D17C;
extern uint32_t off_10D0B8;
extern uint32_t off_10D180;
extern uint32_t off_10D184;
extern uint32_t dword_10D188;
extern uint32_t dword_10D18C;
extern uint32_t dword_10D190;
extern uint32_t off_10D0C0;
extern uint32_t off_10D0C4;
extern uint32_t dword_10D0D4;
extern uint32_t dword_10D0DC;
extern uint32_t dword_10D0D8;
extern uint32_t off_10D0BC;
extern uint32_t dword_10D0C8;
extern uint32_t off_10D0B4;
extern uint32_t dword_10D194;

// rx_state_process @ 0x10cdd4, size 936 bytes
// Doc: rx_state_process [mac]: Validates current state machine state
// rx_state_process [mac]: Validates current state machine state
int  rx_state_process(uint16_t *a1)
{
  uint8_t **v1; // r7
  uint8_t *v2; // r2
  int v3; // r3
  int v5; // r6
  int v6; // r5
  int v7; // r9
  unsigned int v8; // r2
  int v9; // r3
  uint32_t *v10; // r6
  uint32_t *v11; // r3
  int v12; // r0
  int v13; // r1
  int16_t v14; // lr
  uint8_t *v15; // r6
  unsigned int v16; // r2
  int16_t v17; // r12
  int v18; // r8
  int *v19; // r3
  int v20; // r10
  int v21; // r3
  int v22; // r0
  char v23; // r2
  int *v24; // r6
  int v25; // r0
  int v26; // r0
  int v27; // r3
  int v28; // r2
  int *v29; // r0
  int v30; // r1
  int v31; // r2
  uint16_t v32; // r2
  uint16_t v34; // r1
  uint16_t v35; // r2
  uint8_t *v36; // r3
  int *v37; // r6
  int v38; // r0
  int v39; // r3
  int v40; // r2
  uint32_t *v41; // r5
  int v42; // r0
  int v43; // r3
  int v44; // r8
  int v45; // r3
  int *v46; // r5
  int v47; // r1
  int v48; // r2
  int v49; // r1
  int v50; // r0
  int v51; // [sp+0h] [bp-8h]

  v1 = (uint8_t **)off_10D0A4;
  v2 = *(uint8_t **)off_10D0A4;
  v3 = **(uint8_t **)off_10D0A4;
  if ( v3 != 3 )
  {
    v5 = 0;
    goto LABEL_3;
  }
  v41 = off_10D0AC;
  while ( !*(uint32_t *)off_10D0AC )
    ;
  if ( !*(uint32_t *)(*(uint32_t *)off_10D0B0 + 516) )
  {
    v45 = **(int16_t **)off_10D0A8;
    *(uint32_t *)off_10D0AC = 1;
    if ( v45 >= 0 )
    {
      v5 = 4;
      goto LABEL_50;
    }
    goto LABEL_71;
  }
  v42 = mem_word_load(*(uint32_t *)off_10D0B0 + 516);
  v43 = **(int16_t **)off_10D0A8;
  *v41 = 1;
  if ( v43 < 0 )
  {
    if ( v42 )
    {
      v44 = v42 + 4;
      if ( v42 == -4 )
      {
        mmio_clear_register(dword_10D19C, dword_10D198, 1567);
        v5 = v44;
        v2 = *v1;
        goto LABEL_50;
      }
      goto LABEL_49;
    }
LABEL_71:
    v5 = 4;
    mmio_clear_register(dword_10D1A4, dword_10D1A0, 973);
    v2 = *v1;
    goto LABEL_50;
  }
  v44 = v42 + 4;
LABEL_49:
  v2 = *v1;
  v5 = v44;
LABEL_50:
  *(uint32_t *)(v5 + 8) = dword_10D0D0;
  v3 = *v2;
LABEL_3:
  if ( v3 == 1 )
  {
    if ( a1[5] <= 0x6Cu )
      v6 = is_hold_mode();
    else
      v6 = (*(int ( **)(uint32_t))(*(uint32_t *)(*(uint32_t *)off_10D0CC + 8) + 16))(*(uint32_t *)(*(uint32_t *)off_10D0CC + 4));
    if ( !v6 )
      goto LABEL_59;
    v34 = a1[3];
    v35 = a1[4];
    *(uint32_t *)(v6 + 12) = dword_10D0D0;
    v36 = *v1;
    *(uint16_t *)(v6 + 6) = v34;
    *(uint16_t *)(v6 + 8) = v35;
    v5 = v6 + 4;
    if ( *v36 != 2 )
      goto LABEL_5;
  }
  else
  {
    v6 = 0;
    if ( v3 != 2 )
    {
LABEL_5:
      v7 = 0;
      goto LABEL_6;
    }
  }
  if ( a1[5] <= 0x6Cu )
    v6 = error_trap();
  else
    v6 = (*(int ( **)(uint32_t))(*(uint32_t *)(*(uint32_t *)off_10D0CC + 8) + 16))(*(uint32_t *)(*(uint32_t *)off_10D0CC
                                                                                                 + 4));
  if ( !v6 )
  {
LABEL_59:
    log_printf(dword_10D17C, a1[2], a1[4]);
    return branch_to_12cbc8(a1);
  }
  if ( !*((uint32_t *)off_10D0B8 + 2057) )
  {
    if ( (__get_CPSR() & 1) == 0 )
    {
      __disable_irq();
      *(uint32_t *)off_10D180 = 1;
    }
    v46 = (int *)off_10D184;
    ++*(uint32_t *)off_10D184;
    ((void (*)(void))check_init_flag)();
    if ( *v46 )
    {
      v48 = *v46 - 1;
      v47 = *(uint32_t *)off_10D180;
      *v46 = v48;
      if ( !v48 )
      {
        if ( v47 )
          __enable_irq();
      }
    }
    v51 = read_u32(dword_10D188, v47);
    v50 = read_u32(dword_10D18C, v49);
    log_printf(dword_10D190, v51, v50);
    return branch_to_12cbc8(a1);
  }
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_10D0C0 = 1;
  }
  v37 = (int *)off_10D0C4;
  v38 = dword_10D0D4;
  ++*(uint32_t *)off_10D0C4;
  v7 = mem_word_load(v38);
  if ( *v37 )
  {
    v39 = *v37 - 1;
    v40 = *(uint32_t *)off_10D0C0;
    *v37 = v39;
    if ( !v39 )
    {
      if ( v40 )
        __enable_irq();
    }
  }
  *(uint16_t *)v6 = a1[5] + 12;
  *(uint8_t *)(v6 + 2) = 17;
  *(uint8_t *)(v6 + 3) = 0;
  v5 = v6 + 4;
LABEL_6:
  v8 = a1[5];
  *(uint16_t *)v5 = a1[2];
  *(uint16_t *)(v5 + 6) = v8;
  if ( v8 )
  {
    if ( **(int16_t **)off_10D0A8 < 0 && v8 > 0x400 )
    {
      mmio_clear_register(dword_10D0DC, dword_10D0D8, 1671);
      v8 = a1[5];
    }
    memcpy(v5 + 12, a1 + 6, v8);
    v9 = **v1;
    if ( v9 != 3 )
    {
LABEL_8:
      if ( v9 != 2 )
        goto LABEL_9;
LABEL_16:
      v12 = a1[5];
      if ( (v12 & 3) != 0 )
      {
        v14 = (uint8_t)(4 - (v12 & 3));
        v13 = (uint8_t)(4 - (v12 & 3));
      }
      else
      {
        v13 = 0;
        v14 = 0;
      }
      v15 = off_10D0B8;
      v16 = *((uint16_t *)off_10D0B8 + 4122);
      if ( v16 > 0x186 )
      {
        v18 = 0;
        LOWORD(v16) = 0;
        v17 = 1;
      }
      else
      {
        v17 = v16 + 1;
        v18 = 8 * v16;
      }
      v19 = (int *)off_10D0BC;
      *(uint16_t *)(v7 + 12) = v16;
      v20 = *v19;
      v21 = v12 + 16;
      v22 = v20 + v18;
      *(uint32_t *)(v22 + 4) = v6;
      *(uint16_t *)(v20 + v18) = v14 + v21;
      *(uint8_t *)(v22 + 3) = *(uint8_t *)(v20 + v18 + 3) & 0x31 | 4;
      v23 = v15[3074];
      *((uint16_t *)v15 + 4122) = v17;
      v15[3074] = v23 + 1;
      *(uint32_t *)(v7 + 4) = v20 + v18;
      *(uint32_t *)(v7 + 8) = v21 + v13;
      *(uint8_t *)(v7 + 14) = 1;
      *(uint32_t *)v7 = 0;
      if ( (__get_CPSR() & 1) == 0 )
      {
        __disable_irq();
        *(uint32_t *)off_10D0C0 = 1;
      }
      v24 = (int *)off_10D0C4;
      v25 = dword_10D0C8;
      ++*(uint32_t *)off_10D0C4;
      v26 = cmd_handler_a(v25);
      check_init_flag(v26);
      if ( *v24 )
      {
        v27 = *v24 - 1;
        v28 = *(uint32_t *)off_10D0C0;
        *v24 = v27;
        if ( !v27 )
        {
          if ( v28 )
            __enable_irq();
        }
      }
      if ( **v1 != 1 )
        return branch_to_12cbc8(a1);
      goto LABEL_27;
    }
  }
  else
  {
    v9 = **v1;
    if ( v9 != 3 )
      goto LABEL_8;
  }
  v10 = off_10D0AC;
  while ( !*(uint32_t *)off_10D0AC )
    ;
  cmd_handler_a(*(uint32_t *)off_10D0B0 + 524);
  v11 = off_10D0B4;
  *v10 = 1;
  *v11 = 2;
  v9 = **v1;
  if ( v9 == 2 )
    goto LABEL_16;
LABEL_9:
  if ( v9 != 1 )
    return branch_to_12cbc8(a1);
LABEL_27:
  v29 = (int *)is_scan_enabled();
  if ( !v29 )
  {
    log_printf(dword_10D194, v30, v31);
    return branch_to_12cbc8(a1);
  }
  *(uint16_t *)v6 = a1[5] + 12;
  *(uint8_t *)(v6 + 2) = 17;
  *(uint8_t *)(v6 + 3) = 0;
  v32 = a1[5];
  v29[1] = 0;
  *v29 = v6;
  v29[2] = (uint16_t)(v32 + 16) | 0x80000000;
  unknown_3();
  return branch_to_12cbc8(a1);
}

