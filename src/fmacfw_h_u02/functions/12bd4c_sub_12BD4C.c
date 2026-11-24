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


extern uint32_t off_12BE64;
extern uint32_t off_12BE68;
extern uint32_t off_12BE6C;
extern uint32_t off_12BE70;
extern uint32_t off_12BE74;
extern uint32_t off_12BE78;
extern uint32_t off_12BE90;
extern uint32_t off_12BE94;

// rf_sync_status @ 0x12bd4c, size 280 bytes
int rf_sync_status()
{
  int v0; // r4
  int result; // r0
  int *v2; // r4
  int v3; // r1

  v0 = *(uint32_t *)off_12BE64;
  *(uint32_t *)off_12BE68 = *(uint32_t *)off_12BE64;
  result = v0 << 21;
  if ( (v0 & 0x400) != 0 )
  {
    alloc_tx_event(aErrorThereIsNo_0);
    while ( 1 )
      ;
  }
  if ( (v0 & 0x100) == 0 )
  {
    if ( (v0 & 0x200) == 0 )
      goto LABEL_4;
LABEL_13:
    alloc_tx_event(aErrorThereIsNo);
    while ( 1 )
      ;
  }
  result = seq_num_read();
  if ( (v0 & 0x200) != 0 )
    goto LABEL_13;
LABEL_4:
  if ( (v0 & 0x10) != 0 )
  {
    mmio_modify_bit(4);
    result = phy_get_cfg_ptr(4u);
  }
  if ( (v0 & 0x2F) != 0 )
  {
    if ( *(uint8_t *)off_12BE6C )
    {
      v2 = (int *)off_12BE90;
      rf_reg_write_byte(HIBYTE(((uint32_t *)(uintptr_t)off_12BE90)[102]));
      v3 = *((char *)v2 + 411);
      *((uint8_t *)off_12BE94 + 9) = v3;
      return alloc_tx_event("update:%d\n", v3);
    }
    if ( *(uint8_t *)off_12BE70 )
    {
      result = *(uint32_t *)off_12BE74 << 28;
      if ( result )
        *((uint8_t *)off_12BE70 + 6) = 1;
    }
  }
  if ( **(uint16_t **)off_12BE78 < 0 )
  {
    if ( (v0 & 1) != 0 )
    {
      return unknown_12f2c8((int)aTimerPendingHa_0, (int)aHalMachwAbsTim, 760);
    }
    else if ( (v0 & 2) != 0 )
    {
      return unknown_12f2c8((int)aTimerPendingHa_5, (int)aHalMachwAbsTim, 761);
    }
    else if ( (v0 & 4) != 0 )
    {
      return unknown_12f2c8((int)aTimerPendingHa_4, (int)aHalMachwAbsTim, 762);
    }
    else
    {
      result = v0 << 28;
      if ( (v0 & 8) != 0 )
      {
        return unknown_12f2c8((int)aTimerPendingHa_3, (int)aHalMachwAbsTim, 763);
      }
      else if ( (v0 & 0x80) != 0 )
      {
        return unknown_12f2c8((int)aTimerPendingHa_2, (int)aHalMachwAbsTim, 765);
      }
      else if ( (v0 & 0x40) != 0 )
      {
        return unknown_12f2c8((int)aTimerPendingHa_1, (int)aHalMachwAbsTim, 767);
      }
      else if ( (v0 & 0x20) != 0 )
      {
        return unknown_12f2c8((int)aTimerPendingHa, (int)aHalMachwAbsTim, 769);
      }
    }
  }
  return result;
}
