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
extern uint32_t dword_11D73C;
extern uint32_t dword_11D744;
extern uint32_t dword_11D748;
extern uint32_t dword_11D74C;
extern uint32_t dword_11D750;
extern uint32_t dword_11D754;
extern uint32_t dword_11D758;
extern uint32_t dword_11D75C;
extern uint32_t dword_11D760;
extern uint32_t dword_11D764;
extern uint32_t dword_11D768;
extern uint32_t dword_11D76C;
extern uint32_t dword_11D770;
extern uint32_t dword_11D774;
extern uint32_t dword_11D740;

// rf_cmd_set @ 0x11d5e4, size 330 bytes
int rf_cmd_set()
{
  int v0; // r4
  int result; // r0
  int v2; // r3
  int v3; // r1
  int v4; // r0
  int v5; // r2

  v0 = *(uint32_t *)off_11D730 & *(uint32_t *)off_11D734;
  result = v0 << 29;
  *(uint32_t *)((char *)off_11D730 + 0xFFFFFFFC) = v0;
  if ( (v0 & 4) != 0 )
    result = rf_read_rssi();
  if ( (v0 & 8) != 0 )
    result = rf_irq_handler();
  v2 = **(int16_t **)off_11D738;
  if ( v2 < 0 )
  {
    if ( (v0 & 0x400000) != 0 )
    {
      v3 = dword_11D73C;
      v4 = dword_11D744;
      v5 = 847;
    }
    else
    {
      v2 = v0 << 10;
      if ( (v0 & 0x200000) != 0 )
      {
        v3 = dword_11D73C;
        v4 = dword_11D748;
        v5 = 848;
      }
      else if ( (v0 & 0x40) != 0 )
      {
        v3 = dword_11D73C;
        v4 = dword_11D74C;
        v5 = 849;
      }
      else if ( (v0 & 0x100) != 0 )
      {
        v3 = dword_11D73C;
        v4 = dword_11D750;
        v5 = 850;
      }
      else if ( (v0 & 0x1000) != 0 )
      {
        v3 = dword_11D73C;
        v4 = dword_11D754;
        v5 = 851;
      }
      else
      {
        v2 = v0 << 18;
        if ( (v0 & 0x2000) != 0 )
        {
          v3 = dword_11D73C;
          v4 = dword_11D758;
          v5 = 852;
        }
        else if ( (v0 & 0x4000) != 0 )
        {
          v3 = dword_11D73C;
          v4 = dword_11D75C;
          v5 = 853;
        }
        else if ( (v0 & 0x8000) != 0 )
        {
          v3 = dword_11D73C;
          v4 = dword_11D760;
          v5 = 854;
        }
        else if ( (v0 & 0x10000) != 0 )
        {
          v3 = dword_11D73C;
          v4 = dword_11D764;
          v5 = 855;
        }
        else
        {
          v2 = v0 << 14;
          if ( (v0 & 0x20000) != 0 )
          {
            v3 = dword_11D73C;
            v4 = dword_11D768;
            v5 = 856;
          }
          else
          {
            result = v0 << 7;
            if ( (v0 & 0x1000000) != 0 )
            {
              v3 = dword_11D73C;
              v4 = dword_11D76C;
              v5 = 857;
            }
            else if ( (v0 & 0x2000000) != 0 )
            {
              v3 = dword_11D73C;
              v4 = dword_11D770;
              v5 = 858;
            }
            else if ( (v0 & 0x100000) != 0 )
            {
              v3 = dword_11D73C;
              v4 = dword_11D774;
              v5 = 859;
            }
            else
            {
              v2 = 16 * v0;
              if ( (v0 & 0x8000000) == 0 )
                return result;
              v3 = dword_11D73C;
              v4 = dword_11D740;
              v5 = 860;
            }
          }
        }
      }
    }
    return ke_int_lock(v4, v3, v5, v2);
  }
  return result;
}

