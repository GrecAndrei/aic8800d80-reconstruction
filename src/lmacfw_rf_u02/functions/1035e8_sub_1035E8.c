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

extern uint32_t off_103630;
extern uint32_t off_103634;
extern uint32_t off_103638;
extern uint32_t off_10362C;
extern uint32_t dword_10363C;

// configure_bb_clock @ 0x1035e8, size 66 bytes
int  configure_bb_clock(int a1, int a2, int a3, int a4, int a5)
{
  uint32_t *v5; // r0
  uint32_t *v6; // r1
  uint32_t *v7; // r2
  int v8; // r2
  int v9; // r3

  v5 = off_103630;
  v6 = off_103634;
  v7 = off_103638;
  *(uint32_t *)off_10362C &= 0xFFFFFA53;
  *v5 &= ~0x20000u;
  *v6 &= ~0x1000000u;
  *v7 &= 0xFFE7FFFF;
  write_timer_reg(10);
  return check_interrupt_flag(0x2000, dword_10363C, v8, v9, a5);
}

