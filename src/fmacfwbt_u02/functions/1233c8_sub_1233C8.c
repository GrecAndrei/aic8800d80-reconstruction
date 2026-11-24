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


extern uint32_t dword_123400;

// rf_reg_write_85 @ 0x1233c8, size 56 bytes
int  rf_reg_write_85(int a1, int a2, uint16_t a3, uint16_t a4)
{
  uint8_t *v4; // r4
  unsigned int v5; // r0
  int v6; // r3

  v4 = (uint8_t *)bt_buf_alloc(133, a4, a3, 1);
  v5 = atomic_reg_read(dword_123400, 1);
  v6 = (BYTE2(v5) ^ 1) & 1;
  *v4 = v6;
  ke_event_schedule_1("read reg =%x, wifi disable regbit = %d, cfm->wifi_disable=%d\n", v5, HIWORD(v5) & 1, v6);
  hci_evt_send((int)v4);
  return 0;
}
