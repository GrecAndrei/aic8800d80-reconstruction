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


extern uint32_t dword_1045C0;
extern uint32_t dword_1045C4;
extern uint32_t dword_1045D0;
extern uint32_t dword_1045D4;
extern uint32_t off_1045B4;
extern uint32_t off_1045B8;
extern uint32_t off_1045BC;
extern uint32_t off_1045C8;
extern uint32_t off_1045CC;
extern uint32_t off_1045E4;

// start_arm_boot @ 0x1044e0, size 212 bytes
int start_arm_boot()
{
  int *v0; // r1
  uint32_t *v1; // r3
  int v2; // r0
  int v3; // r5
  uint32_t *v4; // r6
  int *v5; // r4
  int result; // r0
  uint32_t *v7; // r3
  uint32_t *v8; // r1

  v0 = (int *)off_1045B4;
  v1 = off_1045BC;
  v2 = dword_1045C0;
  v3 = *(uint32_t *)off_1045B8;
  *(uint32_t *)off_1045B8 = dword_1045C4;
  *v0 = v2;
  v4 = off_1045C8;
  v5 = (int *)off_1045CC;
  *v1 = *v1 & 0xFC000FFF | 0x333000;
  *v1 &= 0x3FFFFFFFu;
  *v1 |= 0xC000000u;
  *v1 = ~(~(*v1 >> 12) << 12);
  v0[29] = v0[29] & 0xFFFFFF0F | 0xA0;
  *v1 |= 0x10000000u;
  timer_delay(10);
  *v4 = dword_1045D0;
  timer_delay(125);
  *v4 = dword_1045D4;
  while ( *v5 < 0 )
    timer_delay(1);
  check_status_bits(1, "end_addr=%x\n", *(uint32_t *)off_1045CC);
  *(uint32_t *)off_1045C8 = 0;
  check_status_bits(1, aDumpFinish);
  *(uint32_t *)off_1045B8 = v3;
  select_fuse_bank();
  result = check_status_bits(1, "** dump tone typ3   r 00100000 %d**\n", 0x4000);
  v7 = off_1045BC;
  v8 = off_1045E4;
  *(uint32_t *)off_1045BC &= 0xF3FFFFFF;
  *v8 |= 0xF0u;
  *v7 &= ~0x10000000u;
  *v7 &= 0x3FFFFFFFu;
  return result;
}
