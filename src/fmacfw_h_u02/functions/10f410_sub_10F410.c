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


extern uint32_t dword_10F704;
extern uint32_t off_10F6F4;
extern uint32_t off_10F6F8;
extern uint32_t off_10F6FC;
extern uint32_t off_10F700;
extern uint32_t off_10F720;

// rf_calibration_2 @ 0x10f410, size 740 bytes
int rf_calibration_2()
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

  result = irq_disable_global_3(512);
  a1 = *((uint32_t *)off_10F6F4 + 2);
  if ( !a1 )
    return result;
  v1 = (int *)off_10F720;
  while ( 2 )
  {
    result = phy_lock(a1);
    if ( !result && *(uint8_t *)(a1 + 108) )
      goto LABEL_4;
    for ( ; *(uint32_t *)(a1 + 1312); result = phy_txpower_calc((unsigned int)v2, 3) )
    {
      if ( (__get_CPSR() & 1) == 0 )
      {
        __disable_irq();
        *(uint32_t *)off_10F6F8 = 1;
      }
      ++*v1;
      v2 = list_pop(a1 + 1312);
      v3 = *v1 - 1;
      if ( *v1 )
      {
        v4 = (int *)off_10F6F8;
        *v1 = v3;
        v5 = *v4;
        if ( !v3 )
        {
          if ( v5 )
            __enable_irq();
        }
      }
    }
    if ( *((uint8_t *)off_10F6FC + 511) )
      goto LABEL_4;
    v6 = a1;
    v7 = (uint16_t **)off_10F700;
    v8 = dword_10F704;
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
          v11 = list_pop(v6 + 1304);
          v12 = *((uint8_t *)v11 + 29);
          v13 = (unsigned int)v11;
          if ( **v7 < 0 && v12 > 0x1F )
          {
            irq_disable_mmio_write((int)aTxdescTmpHostS, (int)aReplenishSend, 374);
            v12 = *(uint8_t *)(v13 + 29);
          }
          v14 = v8 + 696 * v12;
          if ( *(uint8_t *)(v14 + 37) || (*(uint16_t *)(v13 + 30) & 8) != 0 )
            break;
          alloc_tx_event("sta invalid:%d\n", *(uint8_t *)(v14 + 35));
          phy_set_channel_1(v13, v10, 0x80000000);
          if ( !*(uint32_t *)(v6 + 1304) )
          {
LABEL_25:
            v9 = v25;
            goto LABEL_26;
          }
        }
        if ( *(uint8_t *)(v8 + 696 * v12 + 36) != 1 )
        {
          phy_txpower_calc(v13, v10);
          goto LABEL_24;
        }
        if ( **v7 < 0 )
        {
          if ( (*(uint16_t *)(v13 + 30) & 1) != 0 )
          {
LABEL_56:
            wlan_ioctl_handler_1(v8 + 8 * (87 * (uint16_t)v12 + v25 + 78), (uint32_t *)v13);
            goto LABEL_23;
          }
          irq_disable_mmio_write((int)aTxdescTmpHostF, (int)aReplenishSend, 383);
        }
        if ( (*(uint16_t *)(v13 + 30) & 1) != 0 )
          goto LABEL_56;
LABEL_23:
        alloc_tx_event("push rt sta:%d\r\n", *(uint8_t *)(v8 + 696 * v12 + 35));
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
          alloc_tx_event("sta invalid:%d\n", v17[35]);
          v24 = list_pop(v6 + 1264);
          phy_set_channel_1((int)v24, v10, 0x80000000);
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
          *(uint32_t *)off_10F6F8 = 1;
        }
        ++*v1;
        v18 = list_pop(v6 + 1264);
        alloc_tx_event("push sta:%d\r\n", *(uint8_t *)(v8 + 696 * v16 + 35));
        if ( *v1 )
        {
          v19 = *v1 - 1;
          v20 = *(uint32_t *)off_10F6F8;
          *v1 = v19;
          if ( !v19 )
          {
            if ( v20 )
              __enable_irq();
          }
        }
        wlan_ioctl_handler_1(v8 + 8 * (87 * (uint16_t)v16 + v26 + 73), v18);
LABEL_37:
        v15 = *(uint32_t *)(v6 + 1264);
        if ( !v15 )
          goto LABEL_38;
      }
      if ( rf_validate_freq(v16, *(uint8_t *)(v15 + 27)) )
      {
        if ( (__get_CPSR() & 1) == 0 )
        {
          __disable_irq();
          *(uint32_t *)off_10F6F8 = 1;
        }
        ++*v1;
        v21 = list_pop(v6 + 1264);
        if ( *v1 )
        {
          v22 = *v1 - 1;
          v23 = *(uint32_t *)off_10F6F8;
          *v1 = v22;
          if ( !v22 )
          {
            if ( v23 )
              __enable_irq();
          }
        }
        phy_txpower_calc((unsigned int)v21, v10);
        goto LABEL_37;
      }
      v9 = v26;
      *((uint8_t *)off_10F6FC + 512) = 1;
LABEL_39:
      --v9;
      result = invalid_handler(v10);
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
