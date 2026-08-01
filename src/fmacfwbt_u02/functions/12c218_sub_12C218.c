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

extern uint32_t off_12C3AC;
extern uint32_t off_12C3B0;
extern uint32_t dword_12C3B4;
extern uint32_t dword_12C3B8;
extern uint32_t off_12C3C8;
extern uint32_t off_12C3CC;
extern uint32_t off_12C3D0;
extern uint32_t off_12C3BC;
extern uint32_t dword_12C3D4;
extern uint32_t dword_12C3C0;
extern uint32_t dword_12C3D8;
extern uint32_t dword_12C3DC;
extern uint32_t dword_12C3E0;
extern uint32_t dword_12C3E4;
extern uint32_t dword_12C3E8;
extern uint32_t dword_12C3EC;
extern uint32_t dword_12C3F0;
extern uint32_t dword_12C3F4;
extern uint32_t dword_12C3F8;
extern uint32_t dword_12C3FC;
extern uint32_t dword_12C400;
extern uint32_t dword_12C404;
extern uint32_t dword_12C3C4;

// mac_irq_status @ 0x12c218, size 402 bytes
int  mac_irq_status(int result, int a2, int a3, int a4)
{
  int v4; // r1
  int v5; // r4
  int v6; // r3
  int v7; // r5

  v4 = *(uint32_t *)off_12C3AC;
  v5 = *(uint32_t *)off_12C3B0 & *(uint32_t *)off_12C3AC;
  v6 = dword_12C3B4 & v5;
  *((uint32_t *)off_12C3AC + 1) = v5;
  if ( v6 )
    result = set_system_flag_1(0x1000000);
  if ( (dword_12C3B8 & v5) != 0 )
    result = set_system_flag_1(0x800000);
  if ( (v5 & 4) != 0 )
    result = rf_read_irq_status();
  if ( (v5 & 8) != 0 )
    result = power_state_read(result, v4);
  if ( (v5 & 0x10000000) != 0 )
  {
    v7 = *(uint32_t *)off_12C3C8;
    *((uint8_t *)off_12C3CC + 30) |= *(uint8_t *)off_12C3C8 & 0x3F;
    result = set_system_flag_1(0x40000);
    *(uint32_t *)off_12C3D0 = v7;
  }
  if ( **(int16_t **)off_12C3BC < 0 )
  {
    if ( (v5 & 0x400000) != 0 )
    {
      return ke_int_lock(dword_12C3D4, dword_12C3C0, 847, a4);
    }
    else if ( (v5 & 0x200000) != 0 )
    {
      return ke_int_lock(dword_12C3D8, dword_12C3C0, 848, a4);
    }
    else if ( (v5 & 0x40) != 0 )
    {
      return ke_int_lock(dword_12C3DC, dword_12C3C0, 849, a4);
    }
    else if ( (v5 & 0x100) != 0 )
    {
      return ke_int_lock(dword_12C3E0, dword_12C3C0, 850, a4);
    }
    else if ( (v5 & 0x1000) != 0 )
    {
      return ke_int_lock(dword_12C3E4, dword_12C3C0, 851, a4);
    }
    else if ( (v5 & 0x2000) != 0 )
    {
      return ke_int_lock(dword_12C3E8, dword_12C3C0, 852, a4);
    }
    else if ( (v5 & 0x4000) != 0 )
    {
      return ke_int_lock(dword_12C3EC, dword_12C3C0, 853, a4);
    }
    else if ( (v5 & 0x8000) != 0 )
    {
      return ke_int_lock(dword_12C3F0, dword_12C3C0, 854, a4);
    }
    else if ( (v5 & 0x10000) != 0 )
    {
      return ke_int_lock(dword_12C3F4, dword_12C3C0, 855, a4);
    }
    else if ( (v5 & 0x20000) != 0 )
    {
      return ke_int_lock(dword_12C3F8, dword_12C3C0, 856, a4);
    }
    else
    {
      result = v5 << 7;
      if ( (v5 & 0x1000000) != 0 )
      {
        return ke_int_lock(dword_12C3FC, dword_12C3C0, 857, a4);
      }
      else if ( (v5 & 0x2000000) != 0 )
      {
        return ke_int_lock(dword_12C400, dword_12C3C0, 858, a4);
      }
      else if ( (v5 & 0x100000) != 0 )
      {
        return ke_int_lock(dword_12C404, dword_12C3C0, 859, a4);
      }
      else if ( (v5 & 0x8000000) != 0 )
      {
        return ke_int_lock(dword_12C3C4, dword_12C3C0, 860, a4);
      }
    }
  }
  return result;
}

