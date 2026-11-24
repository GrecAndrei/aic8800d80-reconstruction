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


extern uint32_t dword_10D0C8;
extern uint32_t dword_10D0D0;
extern uint32_t dword_10D0D4;
extern uint32_t dword_10D188;
extern uint32_t dword_10D18C;
extern uint32_t off_10D0A4;
extern uint32_t off_10D0A8;
extern uint32_t off_10D0AC;
extern uint32_t off_10D0B0;
extern uint32_t off_10D0B4;
extern uint32_t off_10D0B8;
extern uint32_t off_10D0BC;
extern uint32_t off_10D0C0;
extern uint32_t off_10D0C4;
extern uint32_t off_10D0CC;
extern uint32_t off_10D180;
extern uint32_t off_10D184;

// rx_state_process @ 0x10cdd4, size 936 bytes
uint32_t * rx_state_process(int a1)
{
  uint8_t **v1; // r7
  uint8_t *v2; // r2
  int v3; // r3
  int v5; // r8
  int v6; // r6
  uint32_t *v7; // r5
  uint32_t *v8; // r9
  unsigned int v9; // r2
  int v10; // r3
  uint32_t *v11; // r6
  uint32_t *v12; // r3
  int v13; // r0
  int v14; // r1
  uint16_t v15; // lr
  uint8_t *v16; // r6
  unsigned int v17; // r2
  uint16_t v18; // r12
  int v19; // r8
  int *v20; // r3
  int v21; // r10
  int v22; // r3
  int v23; // r0
  char v24; // r2
  int *v25; // r6
  int v26; // r0
  int v27; // r3
  int v28; // r2
  uint32_t *v29; // r0
  uint16_t v30; // r2
  uint16_t v32; // r1
  uint16_t v33; // r2
  uint8_t *v34; // r3
  int *v35; // r6
  int v36; // r0
  int v37; // r3
  int v38; // r2
  uint32_t *v39; // r5
  uint32_t *v40; // r0
  int v41; // r3
  int v42; // r3
  int *v43; // r5
  int v44; // r0
  int v45; // r2
  int v46; // r1
  int v47; // r0
  int v48; // [sp+0h] [bp-8h]
  int v49; // [sp+4h] [bp-4h]

  v1 = (uint8_t **)off_10D0A4;
  v2 = *(uint8_t **)off_10D0A4;
  v3 = **(uint8_t **)off_10D0A4;
  if ( v3 != 3 )
  {
    v5 = 0;
    v6 = 0;
    goto LABEL_3;
  }
  v39 = off_10D0AC;
  while ( !*(uint32_t *)off_10D0AC )
    ;
  if ( !*(uint32_t *)(((uint32_t *)(uintptr_t)off_10D0B0)[0] + 516) )
  {
    v42 = **(uint16_t **)off_10D0A8;
    *(uint32_t *)off_10D0AC = 1;
    if ( v42 >= 0 )
    {
      v6 = 4;
      v5 = 4;
      goto LABEL_50;
    }
    goto LABEL_71;
  }
  v40 = mem_word_load(((uint32_t *)(uintptr_t)off_10D0B0)[0] + 516);
  v41 = **(uint16_t **)off_10D0A8;
  *v39 = 1;
  if ( v41 < 0 )
  {
    if ( v40 )
    {
      v5 = (int)(v40 + 1);
      if ( v40 == (uint32_t *)-4 )
      {
        mmio_clear_register((int)aHostMsgBuf0, (int)aIpcEmbKmsgFwd, 1567);
        v6 = v5;
        v2 = *v1;
        goto LABEL_50;
      }
      goto LABEL_49;
    }
LABEL_71:
    v6 = 4;
    mmio_clear_register((int)aHostmsgbuf0, (int)aIpcEmbHostmsgb, 973);
    v5 = 4;
    v2 = *v1;
    goto LABEL_50;
  }
  v5 = (int)(v40 + 1);
LABEL_49:
  v2 = *v1;
  v6 = v5;
LABEL_50:
  *(uint32_t *)(v6 + 8) = dword_10D0D0;
  v3 = *v2;
LABEL_3:
  if ( v3 == 1 )
  {
    if ( *(uint16_t *)(a1 + 10) <= 0x6Cu )
      v7 = is_hold_mode();
    else
      v7 = (uint32_t *)(*(int ( **)(uint32_t))(*(uint32_t *)(*(uint32_t *)off_10D0CC + 8) + 16))(*(uint32_t *)(*(uint32_t *)off_10D0CC + 4));
    if ( !v7 )
      goto LABEL_59;
    v32 = *(uint16_t *)(a1 + 6);
    v33 = *(uint16_t *)(a1 + 8);
    v7[3] = dword_10D0D0;
    v34 = *v1;
    *((uint16_t *)v7 + 3) = v32;
    *((uint16_t *)v7 + 4) = v33;
    v6 = (int)(v7 + 1);
    if ( *v34 != 2 )
      goto LABEL_5;
  }
  else
  {
    v7 = nullptr;
    if ( v3 != 2 )
    {
LABEL_5:
      v8 = nullptr;
      goto LABEL_6;
    }
  }
  if ( *(uint16_t *)(a1 + 10) <= 0x6Cu )
    v7 = error_trap();
  else
    v7 = (uint32_t *)(*(int ( **)(uint32_t))(*(uint32_t *)(*(uint32_t *)off_10D0CC + 8) + 16))(*(uint32_t *)(*(uint32_t *)off_10D0CC + 4));
  if ( !v7 )
  {
LABEL_59:
    log_printf(
      "ipc_emb_kmsg_fwd: no buffer msgid=%x,srcid=%x,dstid=%x\r\n",
      *(uint16_t *)(a1 + 4),
      *(uint16_t *)(a1 + 8),
      *(uint16_t *)(a1 + 6));
    return branch_to_12cbc8((char *)a1);
  }
  if ( !*((uint32_t *)off_10D0B8 + 2057) )
  {
    if ( (__get_CPSR() & 1) == 0 )
    {
      __disable_irq();
      *(uint32_t *)off_10D180 = 1;
    }
    v43 = (int *)off_10D184;
    ++*(uint32_t *)off_10D184;
    v44 = check_init_flag();
    if ( *v43 )
    {
      v45 = *v43 - 1;
      v46 = *(uint32_t *)off_10D180;
      *v43 = v45;
      if ( !v45 )
      {
        if ( v46 )
          __enable_irq();
      }
    }
    v49 = v44;
    v48 = read_u32((uint32_t **)dword_10D188);
    v47 = read_u32((uint32_t **)dword_10D18C);
    log_printf("err!!! ipc msg no buffer for usb in %d, free %d, %d\r\n", v48, v47, v49);
    return branch_to_12cbc8((char *)a1);
  }
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_10D0C0 = 1;
  }
  v35 = (int *)off_10D0C4;
  v36 = dword_10D0D4;
  ++*(uint32_t *)off_10D0C4;
  v8 = mem_word_load(v36);
  if ( *v35 )
  {
    v37 = *v35 - 1;
    v38 = *(uint32_t *)off_10D0C0;
    *v35 = v37;
    if ( !v37 )
    {
      if ( v38 )
        __enable_irq();
    }
  }
  *(uint16_t *)v7 = *(uint16_t *)(a1 + 10) + 12;
  *((uint8_t *)v7 + 2) = 17;
  *((uint8_t *)v7 + 3) = 0;
  v6 = (int)(v7 + 1);
LABEL_6:
  v9 = *(uint16_t *)(a1 + 10);
  *(uint16_t *)v6 = *(uint16_t *)(a1 + 4);
  *(uint16_t *)(v6 + 6) = v9;
  if ( v9 )
  {
    if ( **(uint16_t **)off_10D0A8 < 0 && v9 > 0x400 )
    {
      mmio_clear_register((int)aKmsgSrcParamLe, (int)aIpcEmbKmsgFwd, 1671);
      v9 = *(uint16_t *)(a1 + 10);
    }
    memcpy((char *)(v6 + 12), (char *)(a1 + 12), v9);
    v10 = **v1;
    if ( v10 != 3 )
    {
LABEL_8:
      if ( v10 != 2 )
        goto LABEL_9;
LABEL_16:
      v13 = *(uint16_t *)(a1 + 10);
      if ( (v13 & 3) != 0 )
      {
        v15 = (uint8_t)(4 - (v13 & 3));
        v14 = (uint8_t)(4 - (v13 & 3));
      }
      else
      {
        v14 = 0;
        v15 = 0;
      }
      v16 = off_10D0B8;
      v17 = *((uint16_t *)off_10D0B8 + 4122);
      if ( v17 > 0x186 )
      {
        v19 = 0;
        LOWORD(v17) = 0;
        v18 = 1;
      }
      else
      {
        v18 = v17 + 1;
        v19 = 8 * v17;
      }
      v20 = (int *)off_10D0BC;
      *((uint16_t *)v8 + 6) = v17;
      v21 = *v20;
      v22 = v13 + 16;
      v23 = v21 + v19;
      *(uint32_t *)(v23 + 4) = v7;
      *(uint16_t *)(v21 + v19) = v15 + v22;
      *(uint8_t *)(v23 + 3) = *(uint8_t *)(v21 + v19 + 3) & 0x31 | 4;
      v24 = v16[3074];
      *((uint16_t *)v16 + 4122) = v18;
      v16[3074] = v24 + 1;
      v8[1] = v21 + v19;
      v8[2] = v22 + v14;
      *((uint8_t *)v8 + 14) = 1;
      *v8 = 0;
      if ( (__get_CPSR() & 1) == 0 )
      {
        __disable_irq();
        *(uint32_t *)off_10D0C0 = 1;
      }
      v25 = (int *)off_10D0C4;
      v26 = dword_10D0C8;
      ++*(uint32_t *)off_10D0C4;
      cmd_handler_a(v26, v8);
      check_init_flag();
      if ( *v25 )
      {
        v27 = *v25 - 1;
        v28 = *(uint32_t *)off_10D0C0;
        *v25 = v27;
        if ( !v27 )
        {
          if ( v28 )
            __enable_irq();
        }
      }
      if ( **v1 != 1 )
        return branch_to_12cbc8((char *)a1);
      goto LABEL_27;
    }
  }
  else
  {
    v10 = **v1;
    if ( v10 != 3 )
      goto LABEL_8;
  }
  v11 = off_10D0AC;
  while ( !*(uint32_t *)off_10D0AC )
    ;
  cmd_handler_a(((uint32_t *)(uintptr_t)off_10D0B0)[0] + 524, (uint32_t *)(v5 - 4));
  v12 = off_10D0B4;
  *v11 = 1;
  *v12 = 2;
  v10 = **v1;
  if ( v10 == 2 )
    goto LABEL_16;
LABEL_9:
  if ( v10 != 1 )
    return branch_to_12cbc8((char *)a1);
LABEL_27:
  v29 = is_scan_enabled();
  if ( !v29 )
  {
    log_printf(aSendMsgCfgToHo);
    return branch_to_12cbc8((char *)a1);
  }
  *(uint16_t *)v7 = *(uint16_t *)(a1 + 10) + 12;
  *((uint8_t *)v7 + 2) = 17;
  *((uint8_t *)v7 + 3) = 0;
  v30 = *(uint16_t *)(a1 + 10);
  v29[1] = 0;
  *v29 = v7;
  v29[2] = (uint16_t)(v30 + 16) | 0x80000000;
  unknown_3((int)v29);
  return branch_to_12cbc8((char *)a1);
}
