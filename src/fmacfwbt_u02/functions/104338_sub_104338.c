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

extern uint32_t off_10440C;
extern uint32_t off_104414;
extern uint32_t dword_104418;
extern uint32_t off_104410;
extern uint32_t dword_10441C;
extern uint32_t off_104420;
extern uint32_t off_104424;
extern uint32_t dword_104428;
extern uint32_t dword_10442C;
extern uint32_t dword_104430;
extern uint32_t dword_104434;
extern uint32_t dword_104438;
extern uint32_t off_10443C;

// rf_power_on_reset @ 0x104338, size 212 bytes
int rf_power_on_reset()
{
  int *v0; // r1
  uint32_t *v1; // r3
  int v2; // r0
  int v3; // r5
  uint32_t *v4; // r6
  int *v5; // r4
  int v6; // r1
  int result; // r0
  uint32_t *v8; // r3
  uint32_t *v9; // r1

  v0 = (int *)off_10440C;
  v1 = off_104414;
  v2 = dword_104418;
  v3 = *(uint32_t *)off_104410;
  *(uint32_t *)off_104410 = dword_10441C;
  *v0 = v2;
  v4 = off_104420;
  v5 = (int *)off_104424;
  *v1 = *v1 & 0xFC000FFF | 0x333000;
  *v1 &= 0x3FFFFFFFu;
  *v1 |= 0xC000000u;
  *v1 = ~(~(*v1 >> 12) << 12);
  v0[29] = v0[29] & 0xFFFFFF0F | 0xA0;
  *v1 |= 0x10000000u;
  timer_set(10);
  *v4 = dword_104428;
  timer_set(125);
  *v4 = dword_10442C;
  while ( *v5 < 0 )
    timer_set(1);
  state_check_feature(1, dword_104430);
  v6 = dword_104434;
  *(uint32_t *)off_104420 = 0;
  state_check_feature(1, v6);
  *(uint32_t *)off_104410 = v3;
  util_get_buf_addr();
  result = state_check_feature(1, dword_104438);
  v8 = off_104414;
  v9 = off_10443C;
  *(uint32_t *)off_104414 &= 0xF3FFFFFF;
  *v9 |= 0xF0u;
  *v8 &= ~0x10000000u;
  *v8 &= 0x3FFFFFFFu;
  return result;
}

