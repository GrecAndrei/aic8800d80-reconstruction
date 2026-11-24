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


extern uint32_t off_11D730;
extern uint32_t off_11D734;
extern uint32_t off_11D738;

// rf_cmd_set @ 0x11d5e4, size 330 bytes
int rf_cmd_set()
{
  int v0; // r4
  int result; // r0

  v0 = *(uint32_t *)off_11D730 & *(uint32_t *)off_11D734;
  result = v0 << 29;
  *(uint32_t *)((char *)off_11D730 + 0xFFFFFFFC) = v0;
  if ( (v0 & 4) != 0 )
    result = rf_read_rssi();
  if ( (v0 & 8) != 0 )
    result = rf_irq_handler_2();
  if ( **(uint16_t **)off_11D738 < 0 )
  {
    if ( (v0 & 0x400000) != 0 )
    {
      return ke_int_lock_1((int)aGenirqPendingN_0, (int)aHalMachwGenHan, 847);
    }
    else if ( (v0 & 0x200000) != 0 )
    {
      return ke_int_lock_1((int)aGenirqPendingN_1, (int)aHalMachwGenHan, 848);
    }
    else if ( (v0 & 0x40) != 0 )
    {
      return ke_int_lock_1((int)aGenirqPendingN_2, (int)aHalMachwGenHan, 849);
    }
    else if ( (v0 & 0x100) != 0 )
    {
      return ke_int_lock_1((int)aGenirqPendingN_3, (int)aHalMachwGenHan, 850);
    }
    else if ( (v0 & 0x1000) != 0 )
    {
      return ke_int_lock_1((int)aGenirqPendingN_4, (int)aHalMachwGenHan, 851);
    }
    else if ( (v0 & 0x2000) != 0 )
    {
      return ke_int_lock_1((int)aGenirqPendingN_5, (int)aHalMachwGenHan, 852);
    }
    else if ( (v0 & 0x4000) != 0 )
    {
      return ke_int_lock_1((int)aGenirqPendingN_6, (int)aHalMachwGenHan, 853);
    }
    else if ( (v0 & 0x8000) != 0 )
    {
      return ke_int_lock_1((int)aGenirqPendingN_7, (int)aHalMachwGenHan, 854);
    }
    else if ( (v0 & 0x10000) != 0 )
    {
      return ke_int_lock_1((int)aGenirqPendingN_8, (int)aHalMachwGenHan, 855);
    }
    else if ( (v0 & 0x20000) != 0 )
    {
      return ke_int_lock_1((int)aGenirqPendingN_9, (int)aHalMachwGenHan, 856);
    }
    else
    {
      result = v0 << 7;
      if ( (v0 & 0x1000000) != 0 )
      {
        return ke_int_lock_1((int)aGenirqPendingN_10, (int)aHalMachwGenHan, 857);
      }
      else if ( (v0 & 0x2000000) != 0 )
      {
        return ke_int_lock_1((int)aGenirqPendingN_11, (int)aHalMachwGenHan, 858);
      }
      else if ( (v0 & 0x100000) != 0 )
      {
        return ke_int_lock_1((int)aGenirqPendingN_12, (int)aHalMachwGenHan, 859);
      }
      else if ( (v0 & 0x8000000) != 0 )
      {
        return ke_int_lock_1((int)aGenirqPendingN, (int)aHalMachwGenHan, 860);
      }
    }
  }
  return result;
}
