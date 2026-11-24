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


extern uint32_t dword_121FD4;
extern uint32_t off_121FC4;
extern uint32_t off_121FC8;
extern uint32_t off_121FCC;
extern uint32_t off_121FD0;
extern uint32_t off_121FDC;

// rf_set_rx_mode @ 0x121f1c, size 168 bytes
int  rf_set_rx_mode(int a1, int a2)
{
  int v3; // r3
  int v4; // r2
  uint16_t *v5; // r3
  int result; // r0
  volatile unsigned int v7; // r1
  uint8_t *v8; // r3
  uint32_t *v9; // r0

  if ( (a2 & 0x800000) != 0 )
  {
    *(uint8_t *)(a1 + 128) = 0;
    v7 = (*(volatile uint32_t *)0x40501010u);
    v8 = off_121FD0;
    v9 = (uint32_t *)((char *)off_121FD0 + 12);
    *((uint16_t *)off_121FD0 + 14) = 1793;
    v8[36] = 0;
    *((uint32_t *)v8 + 5) = a1;
    result = mem_copy_util(v9, v7 + 10000);
    *(uint8_t *)(a1 + 115) = 0;
  }
  else
  {
    v3 = (uint8_t)(*(uint8_t *)(a1 + 115) + 1);
    v4 = *(uint32_t *)off_121FC4;
    *(uint8_t *)(a1 + 115) = v3;
    if ( *(uint8_t *)(v4 + 1) == v3 )
    {
      *(uint8_t *)(a1 + 115) = 0;
      check_feature_flag(1024, aSleepLinkloss);
      return (int)rf_read_reg(a1);
    }
    else if ( *(uint8_t *)(a1 + 108) )
    {
      return get_bt_device_state(*(uint8_t *)(a1 + 107), off_121FDC, a1);
    }
    else
    {
      if ( *((uint8_t *)off_121FC8 + 2) )
        *(uint32_t *)off_121FCC &= ~0x80000000;
      v5 = off_121FD0;
      if ( *((uint8_t *)off_121FD0 + 8) )
        --*((uint8_t *)off_121FD0 + 8);
      v5[14] = 1;
      result = mem_set_util((uint32_t *)dword_121FD4);
      *(uint32_t *)(a1 + 4) &= ~0x200u;
    }
  }
  return result;
}
