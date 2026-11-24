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


extern uint32_t dword_1112E8;

// mutex_lock @ 0x111270, size 118 bytes
int  mutex_lock(char a1, char *a2, unsigned int a3, int a4)
{
  uint32_t *v7; // r0
  uint32_t *v8; // r4
  uint32_t *v9; // r6
  int v10; // r2
  int v11; // r3

  v7 = is_hci_initialized(4);
  if ( !v7 )
    return log_printf(aErrNoMsgPkt);
  v8 = v7;
  v9 = is_scan_enabled();
  if ( v9 )
  {
    *(uint8_t *)v8 = a3;
    *((uint8_t *)v8 + 1) = BYTE1(a3) & 0xF;
    *((uint8_t *)v8 + 2) = a1;
    *((uint8_t *)v8 + 3) = 0;
    memcpy((char *)v8 + 4, a2, a3);
    v10 = v9[2];
    v11 = dword_1112E8;
    v9[1] = 0;
    *v9 = v8;
    v9[2] = (uint16_t)(a3 + 4) | v11 & v10 | 0x80000000;
    return unknown_3((int)v9);
  }
  else
  {
    log_printf(aErrSendMsgCfgT);
    return is_controller_mode(v8);
  }
}
