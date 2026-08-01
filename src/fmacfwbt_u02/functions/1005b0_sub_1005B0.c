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

extern uint32_t off_100634;
extern uint32_t off_100638;
extern uint32_t dword_100640;
extern uint32_t dword_10063C;

// timer_read @ 0x1005b0, size 132 bytes
int  timer_read(int a1)
{
  unsigned int v2; // r6
  unsigned int v3; // r5
  int v4; // r7
  int v5; // r0
  int v6; // r6
  int v7; // r5

  v2 = *(uint32_t *)off_100634;
  v3 = *(uint32_t *)off_100634;
  v4 = return_one();
  v5 = sys_status_get_bit21();
  v6 = (v2 >> 8) & 0xF;
  v7 = (v3 >> 27) & 1;
  if ( a1 == 1 )
  {
    if ( v5 )
    {
      return 11;
    }
    else if ( v6 == 1 )
    {
      return 2;
    }
    else if ( v4 )
    {
      return 9;
    }
    else
    {
      return 3;
    }
  }
  else if ( a1 == 2 )
  {
    if ( v6 == 1 )
    {
      if ( v7 )
        return 7;
      else
        return 4;
    }
    else
    {
      return v7 + 5;
    }
  }
  else if ( a1 )
  {
    if ( **(int16_t **)off_100638 < 0 )
      mmio_irq_clear(dword_100640, dword_10063C, 434);
    return 0;
  }
  else if ( v5 )
  {
    return 10;
  }
  else if ( v7 )
  {
    return 8;
  }
  else
  {
    return v6 != 1;
  }
}

