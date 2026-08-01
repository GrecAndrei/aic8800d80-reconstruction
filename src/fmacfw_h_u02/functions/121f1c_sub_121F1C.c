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

extern uint32_t off_121FD8;
extern uint32_t off_121FD0;
extern uint32_t off_121FC4;
extern uint32_t dword_121FE0;
extern uint32_t off_121FDC;
extern uint32_t off_121FC8;
extern uint32_t off_121FCC;
extern uint32_t dword_121FD4;

// rf_set_rx_mode @ 0x121f1c, size 168 bytes
int  rf_set_rx_mode(int a1, int a2)
{
  int v3; // r3
  int v4; // r2
  uint16_t *v5; // r3
  int result; // r0
  uint32_t *v7; // r3
  int v8; // r1
  uint8_t *v9; // r3
  char *v10; // r0

  if ( (a2 & 0x800000) != 0 )
  {
    v7 = off_121FD8;
    *(uint8_t *)(a1 + 128) = 0;
    v8 = v7[4];
    v9 = off_121FD0;
    v10 = (char *)off_121FD0 + 12;
    *((uint16_t *)off_121FD0 + 14) = 1793;
    v9[36] = 0;
    *((uint32_t *)v9 + 5) = a1;
    result = mem_copy_util(v10, v8 + 10000);
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
      check_feature_flag(1024, dword_121FE0);
      return rf_read_reg(a1);
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
      result = mem_set_util(dword_121FD4);
      *(uint32_t *)(a1 + 4) &= ~0x200u;
    }
  }
  return result;
}

