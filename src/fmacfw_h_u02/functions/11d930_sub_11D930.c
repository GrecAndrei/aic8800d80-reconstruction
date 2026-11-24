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


extern uint32_t dword_11DAC0;
extern uint32_t off_11DA94;
extern uint32_t off_11DA98;
extern uint32_t off_11DA9C;
extern uint32_t off_11DAA4;
extern uint32_t off_11DAA8;
extern uint32_t off_11DAAC;
extern uint32_t off_11DAB4;
extern uint32_t off_11DAB8;
extern uint32_t off_11DABC;
extern uint32_t off_11DAC4;
extern uint32_t off_11DAC8;

// dma_ring_init @ 0x11d930, size 356 bytes
int  dma_ring_init(int a1)
{
  uint32_t *v1; // r7
  int *v2; // r9
  int v3; // r8
  uint32_t *v4; // r11
  uint32_t *v5; // r10
  int i; // r5
  int v8; // r2
  BOOL v9; // r0
  int v10; // r3
  unsigned int v11; // r4
  int result; // r0
  void ( *v13)(uint32_t); // r2
  BOOL v14; // r0
  uint32_t *v15; // r5
  int v16; // [sp+14h] [bp-8h]

  v1 = off_11DA94;
  v2 = (int *)off_11DAB4;
  v3 = dword_11DAC0;
  v4 = off_11DAC4;
  v5 = off_11DAC8;
  for ( i = 0; ; ++i )
  {
    v11 = check_fw_rom_signature();
    *v1 = 0x10000;
    result = irq_disable_global_3(0x80000);
    if ( !v11 )
      break;
    if ( !a1 )
    {
      if ( *((uint8_t *)v2 + 192) )
      {
        if ( *(uint32_t *)off_11DA98 > 0x80000u || i > 31 )
          return irq_disable_global_2(0x80000);
      }
      else if ( i > 3 )
      {
        return irq_disable_global_2(0x80000);
      }
    }
    if ( !phy_mode_check_1() || !is_rate_valid() )
    {
      *((uint8_t *)off_11DAAC + 69) = 1;
      v14 = is_rate_valid();
      return check_feature_flag(1024, "no host buffer:%d\r\n", !v14);
    }
    v8 = *(uint32_t *)(v11 + 20);
    if ( v8 != v3 )
      alloc_tx_event(
        "rxbuf1 %08x,%08x: start %08x, end %08x, read %08x, wrptr %08x, rdptr %08x\r\n",
        v11,
        v8,
        *(uint32_t *)off_11DA9C,
        *((uint32_t *)off_11DA9C + 1),
        *((uint32_t *)off_11DA9C + 2),
        *v4,
        *v5);
    read_chip_revision(v11);
    v9 = tx_80211_frame(v11);
    if ( v9 )
    {
      if ( !v9 )
        goto LABEL_10;
    }
    else if ( dpc_handler(v11) )
    {
      goto LABEL_10;
    }
    tx_packet_kick(v11);
LABEL_10:
    v10 = **(uint8_t **)off_11DAA4;
    switch ( v10 )
    {
      case 2:
        goto LABEL_22;
      case 4:
        if ( !*(uint32_t *)off_11DAA8 || *(uint32_t *)(*(uint32_t *)off_11DAA8 + 12) != v11 || (*(uint8_t *)(v11 + 16) & 1) == 0 )
        {
LABEL_22:
          dma_ring_alloc_2();
          continue;
        }
        v16 = *(uint32_t *)off_11DAA8;
        list_pop(off_11DAA8);
        v13 = *(void ( **)(uint32_t))(v16 + 4);
        *(uint8_t *)(v16 + 16) = 0;
        if ( v13 )
          v13(*(uint32_t *)(v16 + 8));
        phy_rate_get(v11);
        break;
      case 3:
        dma_ring_alloc_1();
        break;
    }
  }
  if ( LOBYTE(((uint32_t *)(uintptr_t)off_11DAB4)[48]) )
  {
    v15 = off_11DAB8;
    if ( *((uint8_t *)off_11DAB8 + 33) )
    {
      result = memmove(*((uint32_t *)off_11DAB8 + 4), *((uint32_t *)off_11DAB8 + 5), *((uint32_t *)off_11DAB8 + 6));
      v15[5] = 0;
      v15[7] = 0;
      v15[4] = 0;
      v15[6] = 0;
      *((uint8_t *)v15 + 33) = 0;
    }
  }
  *(uint32_t *)off_11DABC |= 0x10000u;
  return result;
}
