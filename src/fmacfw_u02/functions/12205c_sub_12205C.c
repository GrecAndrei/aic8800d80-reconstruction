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


extern uint32_t dword_122114;
extern uint32_t off_122104;
extern uint32_t off_122108;
extern uint32_t off_12210C;
extern uint32_t off_122110;
extern uint32_t off_12211C;

// test_23bit_flag @ 0x12205c, size 168 bytes
int  test_23bit_flag(int a1, int a2)
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
    v8 = off_122110;
    v9 = (uint32_t *)((char *)off_122110 + 12);
    *((uint16_t *)off_122110 + 14) = 1793;
    v8[36] = 0;
    *((uint32_t *)v8 + 5) = a1;
    result = unknown_worker(v9, v7 + 10000);
    *(uint8_t *)(a1 + 115) = 0;
  }
  else
  {
    v3 = (uint8_t)(*(uint8_t *)(a1 + 115) + 1);
    v4 = *(uint32_t *)off_122104;
    *(uint8_t *)(a1 + 115) = v3;
    if ( *(uint8_t *)(v4 + 1) == v3 )
    {
      *(uint8_t *)(a1 + 115) = 0;
      check_status_bits(1024, aSleepLinkloss);
      return (int)send_fw_cmd(a1);
    }
    else if ( *(uint8_t *)(a1 + 108) )
    {
      return link_get_connection_info(*(uint8_t *)(a1 + 107), off_12211C, a1);
    }
    else
    {
      if ( *((uint8_t *)off_122108 + 2) )
        *(uint32_t *)off_12210C &= ~0x80000000;
      v5 = off_122110;
      if ( *((uint8_t *)off_122110 + 8) )
        --*((uint8_t *)off_122110 + 8);
      v5[14] = 1;
      result = fault_handler((uint32_t *)dword_122114);
      *(uint32_t *)(a1 + 4) &= ~0x200u;
    }
  }
  return result;
}
