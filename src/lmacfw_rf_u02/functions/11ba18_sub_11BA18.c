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

extern uint32_t off_11BA44;
extern uint32_t off_11BA48;

// timer_countdown @ 0x11ba18, size 44 bytes
int  timer_countdown(int result)
{
  char v1; // r3
  void *v2; // r2

  if ( *((uint8_t *)off_11BA44 + 89) )
  {
    v1 = *((uint8_t *)off_11BA44 + 89) - 1;
    *((uint8_t *)off_11BA44 + 89) = v1;
    if ( !v1 )
    {
      v2 = off_11BA48;
      if ( *(uint8_t *)off_11BA48 == 1 )
      {
        *(uint8_t *)off_11BA48 = 0;
        rf_state_process(result, 1, (int)v2);
        return state_flag_check();
      }
    }
  }
  return result;
}

