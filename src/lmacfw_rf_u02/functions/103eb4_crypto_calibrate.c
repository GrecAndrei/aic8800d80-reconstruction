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

extern uint32_t off_103F88;
extern uint32_t off_103F90;
extern uint32_t dword_103F94;
extern uint32_t off_103F8C;
extern uint32_t dword_103F98;
extern uint32_t off_103F9C;
extern uint32_t off_103FA0;
extern uint32_t dword_103FA4;
extern uint32_t dword_103FA8;
extern uint32_t dword_103FAC;
extern uint32_t dword_103FB0;
extern uint32_t dword_103FB4;
extern uint32_t off_103FB8;

// load_patch_data @ 0x103eb4, size 212 bytes
// Doc: rf_init_hw_regs [patch]: Initialize RF hardware MMIO registers at boot
// rf_init_hw_regs [patch]: Initialize RF hardware MMIO registers at boot
int load_patch_data()
{
  int *v0; // r1
  uint32_t *v1; // r3
  int v2; // r0
  int v3; // r5
  uint32_t *v4; // r6
  int *v5; // r4
  void *v6; // r3
  int v7; // r1
  int v8; // r3
  int result; // r0
  uint32_t *v10; // r3
  uint32_t *v11; // r1

  v0 = (int *)off_103F88;
  v1 = off_103F90;
  v2 = dword_103F94;
  v3 = *(uint32_t *)off_103F8C;
  *(uint32_t *)off_103F8C = dword_103F98;
  *v0 = v2;
  v4 = off_103F9C;
  v5 = (int *)off_103FA0;
  *v1 = *v1 & 0xFC000FFF | 0x333000;
  *v1 &= 0x3FFFFFFFu;
  *v1 |= 0xC000000u;
  *v1 = ~(~(*v1 >> 12) << 12);
  v0[29] = v0[29] & 0xFFFFFF0F | 0xA0;
  *v1 |= 0x10000000u;
  write_timer_reg(10);
  *v4 = dword_103FA4;
  write_timer_reg(125);
  *v4 = dword_103FA8;
  while ( *v5 < 0 )
    write_timer_reg(1);
  check_interrupt_flag(1, dword_103FAC, *(uint32_t *)off_103FA0, off_103FA0);
  v6 = off_103F9C;
  v7 = dword_103FB0;
  *(uint32_t *)off_103F9C = 0;
  check_interrupt_flag(1, v7, 0, v6);
  *(uint32_t *)off_103F8C = v3;
  wait_rf_ready();
  result = check_interrupt_flag(1, dword_103FB4, 0x4000, v8);
  v10 = off_103F90;
  v11 = off_103FB8;
  *(uint32_t *)off_103F90 &= 0xF3FFFFFF;
  *v11 |= 0xF0u;
  *v10 &= ~0x10000000u;
  *v10 &= 0x3FFFFFFFu;
  return result;
}

