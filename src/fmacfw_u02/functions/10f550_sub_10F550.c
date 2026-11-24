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


extern uint32_t dword_10F844;
extern uint32_t off_10F834;
extern uint32_t off_10F838;
extern uint32_t off_10F83C;
extern uint32_t off_10F840;
extern uint32_t off_10F860;

// os_task_init @ 0x10f550, size 740 bytes
int os_task_init()
{
  int result; // r0
  int *v1; // r9
  uint32_t *v2; // r0
  int v3; // r2
  int *v4; // r3
  int v5; // r3
  int v6; // r11
  uint16_t **v7; // r6
  int v8; // r5
  int v9; // r8
  int v10; // r7
  uint32_t *v11; // r0
  unsigned int v12; // r8
  unsigned int v13; // r4
  unsigned int v14; // r2
  int v15; // r1
  int v16; // r10
  uint8_t *v17; // r3
  uint32_t *v18; // r8
  int v19; // r2
  int v20; // r1
  uint32_t *v21; // r0
  int v22; // r3
  int v23; // r2
  uint32_t *v24; // r0
  int v25; // [sp+0h] [bp-Ch]
  int v26; // [sp+0h] [bp-Ch]
  int a1; // [sp+4h] [bp-8h]

  result = unknown_func_12d14c(512);
  a1 = *((uint32_t *)off_10F834 + 2);
  if ( !a1 )
    return result;
  v1 = (int *)off_10F860;
  while ( 2 )
  {
    result = isr_flag_dispatch(a1);
    if ( !result && *(uint8_t *)(a1 + 108) )
      goto LABEL_4;
    for ( ; *(uint32_t *)(a1 + 1312); result = ll_conn_state_dispatch((unsigned int)v2, 3) )
    {
      if ( (__get_CPSR() & 1) == 0 )
      {
        __disable_irq();
        *(uint32_t *)off_10F838 = 1;
      }
      ++*v1;
      v2 = mem_word_load(a1 + 1312);
      v3 = *v1 - 1;
      if ( *v1 )
      {
        v4 = (int *)off_10F838;
        *v1 = v3;
        v5 = *v4;
        if ( !v3 )
        {
          if ( v5 )
            __enable_irq();
        }
      }
    }
    if ( *((uint8_t *)off_10F83C + 511) )
      goto LABEL_4;
    v6 = a1;
    v7 = (uint16_t **)off_10F840;
    v8 = dword_10F844;
    v9 = 4;
    if ( *(uint32_t *)(a1 + 1304) )
    {
LABEL_16:
      v10 = (uint8_t)v9;
      v25 = v9;
      while ( 1 )
      {
        while ( 1 )
        {
          v11 = mem_word_load(v6 + 1304);
          v12 = *((uint8_t *)v11 + 29);
          v13 = (unsigned int)v11;
          if ( **v7 < 0 && v12 > 0x1F )
          {
            mmio_clear_register((int)aTxdescTmpHostS, (int)aReplenishSend, 374);
            v12 = *(uint8_t *)(v13 + 29);
          }
          v14 = v8 + 696 * v12;
          if ( *(uint8_t *)(v14 + 37) || (*(uint16_t *)(v13 + 30) & 8) != 0 )
            break;
          event_dispatch("sta invalid:%d\n", *(uint8_t *)(v14 + 35));
          ll_conn_event_prepare(v13, v10, 0x80000000);
          if ( !*(uint32_t *)(v6 + 1304) )
          {
LABEL_25:
            v9 = v25;
            goto LABEL_26;
          }
        }
        if ( *(uint8_t *)(v8 + 696 * v12 + 36) != 1 )
        {
          ll_conn_state_dispatch(v13, v10);
          goto LABEL_24;
        }
        if ( **v7 < 0 )
        {
          if ( (*(uint16_t *)(v13 + 30) & 1) != 0 )
          {
LABEL_56:
            cmd_handler_a(v8 + 8 * (87 * (uint16_t)v12 + v25 + 78), (uint32_t *)v13);
            goto LABEL_23;
          }
          mmio_clear_register((int)aTxdescTmpHostF, (int)aReplenishSend, 383);
        }
        if ( (*(uint16_t *)(v13 + 30) & 1) != 0 )
          goto LABEL_56;
LABEL_23:
        event_dispatch("push rt sta:%d\r\n", *(uint8_t *)(v8 + 696 * v12 + 35));
LABEL_24:
        if ( !*(uint32_t *)(v6 + 1304) )
          goto LABEL_25;
      }
    }
    while ( 2 )
    {
      v10 = (uint8_t)v9;
LABEL_26:
      v15 = *(uint32_t *)(v6 + 1264);
      if ( !v15 )
        goto LABEL_39;
      v26 = v9;
      while ( 1 )
      {
        while ( 1 )
        {
          v16 = *(uint8_t *)(v15 + 29);
          v17 = (uint8_t *)(v8 + 696 * v16);
          if ( v17[37] )
            break;
          event_dispatch("sta invalid:%d\n", v17[35]);
          v24 = mem_word_load(v6 + 1264);
          ll_conn_event_prepare((int)v24, v10, 0x80000000);
          v15 = *(uint32_t *)(v6 + 1264);
          if ( !v15 )
          {
LABEL_38:
            v9 = v26;
            goto LABEL_39;
          }
        }
        if ( v17[36] != 1 )
          break;
        if ( (__get_CPSR() & 1) == 0 )
        {
          __disable_irq();
          *(uint32_t *)off_10F838 = 1;
        }
        ++*v1;
        v18 = mem_word_load(v6 + 1264);
        event_dispatch("push sta:%d\r\n", *(uint8_t *)(v8 + 696 * v16 + 35));
        if ( *v1 )
        {
          v19 = *v1 - 1;
          v20 = *(uint32_t *)off_10F838;
          *v1 = v19;
          if ( !v19 )
          {
            if ( v20 )
              __enable_irq();
          }
        }
        cmd_handler_a(v8 + 8 * (87 * (uint16_t)v16 + v26 + 73), v18);
LABEL_37:
        v15 = *(uint32_t *)(v6 + 1264);
        if ( !v15 )
          goto LABEL_38;
      }
      if ( lookup_interface_info(v16, *(uint8_t *)(v15 + 27)) )
      {
        if ( (__get_CPSR() & 1) == 0 )
        {
          __disable_irq();
          *(uint32_t *)off_10F838 = 1;
        }
        ++*v1;
        v21 = mem_word_load(v6 + 1264);
        if ( *v1 )
        {
          v22 = *v1 - 1;
          v23 = *(uint32_t *)off_10F838;
          *v1 = v22;
          if ( !v22 )
          {
            if ( v23 )
              __enable_irq();
          }
        }
        ll_conn_state_dispatch((unsigned int)v21, v10);
        goto LABEL_37;
      }
      v9 = v26;
      *((uint8_t *)off_10F83C + 512) = 1;
LABEL_39:
      --v9;
      result = test_flag(v10);
      v6 -= 8;
      if ( v9 != -1 )
      {
        if ( *(uint32_t *)(v6 + 1304) )
          goto LABEL_16;
        continue;
      }
      break;
    }
LABEL_4:
    a1 = *(uint32_t *)a1;
    if ( a1 )
      continue;
    return result;
  }
}
