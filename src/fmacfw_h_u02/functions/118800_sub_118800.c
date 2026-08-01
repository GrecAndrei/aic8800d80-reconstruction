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

extern uint32_t off_1188AC;
extern uint32_t dword_1188B0;
extern uint32_t dword_1188B4;

// phy_dispatch @ 0x118800, size 172 bytes
int  phy_dispatch(int a1, int a2, int a3)
{
  int16_t **v3; // r8
  int v4; // r10
  int v5; // r9
  int v9; // r4
  int v10; // r1

  v3 = (int16_t **)off_1188AC;
  v4 = dword_1188B0;
  v5 = dword_1188B4;
  while ( 1 )
  {
    v9 = list_pop(a2);
    if ( !v9 )
      break;
    while ( 1 )
    {
      v10 = *(uint32_t *)(v9 + 76);
      if ( *(uint32_t *)(v9 + 68) )
      {
        *(uint32_t *)(v10 + 4) = 2080374784;
      }
      else if ( *(int *)(v10 + 4) >= 0 )
      {
        *(uint32_t *)(v10 + 4) = 0x40000000;
      }
      if ( *(uint16_t *)(v9 + 4) )
        break;
      set_string_0x1882c0(v9);
      v9 = list_pop(a2);
      if ( !v9 )
        return alloc_dma_buf();
    }
    *(uint32_t *)(v10 + 4) |= 0x800000u;
    check_cal_status(v9, (uint32_t *)(v10 + 4));
    conn_handle_get(v9);
    if ( phy_switch_radio(v9, 1) )
    {
      if ( **v3 < 0 && !a3 )
        irq_disable_mmio_write(v5, v4, 1105);
      wlan_ioctl_handler_1(a3);
    }
    else
    {
      unknown_12f4b4(a1, v9);
    }
  }
  return alloc_dma_buf();
}

