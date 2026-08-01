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

extern uint32_t dword_139C2C;
extern uint32_t dword_139C30;
extern uint32_t dword_139C34;
extern uint32_t dword_139C38;
extern uint32_t dword_139C3C;
extern uint32_t dword_139C40;
extern uint32_t dword_139C44;
extern uint32_t dword_139C4C;
extern uint32_t dword_139C50;
extern uint32_t off_139C48;

// wlc_init_hw @ 0x139bb4, size 118 bytes
int wlc_init_hw()
{
  uint32_t *v0; // r6
  int v1; // r4
  int v2; // r5
  uint32_t *v3; // r1
  int v4; // r3
  int result; // r0
  int v6; // r1

  v0 = (uint32_t *)(dword_139C2C + 16);
  clear_stats_buf((uint32_t *)dword_139C2C);
  v1 = dword_139C30;
  clear_stats_buf(v0);
  v2 = v1 + 4672;
  do
  {
    v3 = (uint32_t *)v1;
    v1 += 292;
    wlan_ioctl_handler_1((int)v0, v3);
  }
  while ( v1 != v2 );
  clear_stats_buf((uint32_t *)dword_139C34);
  clear_stats_buf((uint32_t *)dword_139C38);
  wlan_ioctl_handler_1(dword_139C34, (uint32_t *)dword_139C3C);
  wlan_ioctl_handler_1(dword_139C34, (uint32_t *)dword_139C40);
  wlan_ioctl_handler_1(dword_139C34, (uint32_t *)dword_139C44);
  v4 = dword_139C4C;
  result = dword_139C50;
  *((uint16_t *)off_139C48 + 51) = -1;
  v6 = v4 + 15360;
  do
  {
    *(uint8_t *)(v4 - 52) = 0;
    *(uint16_t *)(v4 + 8) = 0;
    *(uint32_t *)(v4 - 64) = result;
    *(uint32_t *)(v4 - 60) = v4;
    *(uint32_t *)(v4 - 48) = v4;
    v4 += 80;
  }
  while ( v6 != v4 );
  return result;
}

