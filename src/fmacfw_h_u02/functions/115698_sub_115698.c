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


extern uint32_t dword_1157F4;
extern uint32_t dword_1157F8;
extern uint32_t dword_1157FC;
extern uint32_t dword_115800;
extern uint32_t dword_115804;
extern uint32_t dword_115808;
extern uint32_t dword_115810;
extern uint32_t dword_115814;
extern uint32_t dword_115818;
extern uint32_t dword_11581C;
extern uint32_t dword_115820;
extern uint32_t dword_115824;
extern uint32_t dword_115828;
extern uint32_t dword_11582C;
extern uint32_t dword_115830;
extern uint32_t dword_115834;
extern uint32_t dword_115838;

// rx_packet_pending @ 0x115698, size 346 bytes
uint32_t * rx_packet_pending(int a1, int a2)
{
  int v2; // r3
  int *v3; // r4
  unsigned int v4; // r2
  unsigned int v5; // r1
  int v6; // r0
  int v7; // r0
  uint32_t *v8; // r3
  volatile unsigned int v9; // r1
  unsigned int v10; // r1
  int v11; // r3
  uint32_t *v12; // r5
  int v13; // r0
  unsigned int v14; // r5
  int v15; // r2
  unsigned int v16; // r1
  int v17; // r0
  uint32_t *v18; // r1
  uint32_t *v19; // r0
  uint64_t v20; // kr00_8
  uint32_t *result; // r0
  int v22; // r1
  int v23; // r1
  int v24; // r3
  int v25; // r7
  int v26; // r6
  int v27; // r2
  volatile unsigned int v28; // r3
  int v29; // r3

  v2 = **(uint16_t **)dword_1157F4;
  if ( (v2 & 1) != 0 )
    sub_12F054(a1, a2, v2 << 31);
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)dword_1157F8 = 1;
  }
  v3 = (int *)dword_1157FC;
  v4 = dword_115800;
  v5 = dword_115804;
  ++*(uint32_t *)dword_1157FC;
  feature_guard_sdio(1024, v5, v4);
  v6 = sub_12D00C(0x80000000);
  v7 = sub_12BA0C(v6);
  v8 = (uint32_t *)dword_115808;
  *(uint32_t *)dword_115808 &= 0xFFFFFFu;
  *v8 |= 0x10u;
  v9 = (*(volatile uint32_t *)0x40501010u);
  v10 = v9 + 100;
  do
    v11 = v10 - (*(volatile uint32_t *)0x40501010u);
  while ( v11 >= 0 );
  v12 = (uint32_t *)dword_115810;
  *(uint32_t *)dword_115810 |= 0x111u;
  v13 = sub_117A7C(v7);
  *(uint32_t *)dword_115808 &= ~0x10u;
  *v12 &= 0xFFFFFEEE;
  sub_120F74(v13);
  if ( !sub_12CD48(0) )
    sub_12D00C(0x2000000);
  v14 = dword_115814;
  sub_11F654();
  if ( *(uint8_t *)v14 && !*(uint8_t *)dword_115818 && *(uint8_t *)(v14 + 6) )
  {
    v25 = (char)(*(uint8_t *)(v14 + 5) + (*(uint8_t *)dword_115834 & 3));
    v26 = *(char *)(v14 + 7) + v25;
    if ( v26 >= *(char *)(v14 + 4) )
      LOBYTE(v26) = *(uint8_t *)(v14 + 4);
    sub_102AD0((char)v26);
    v27 = *(uint16_t *)(v14 + 8);
    v28 = (*(volatile uint32_t *)0x40501010u);
    *(uint8_t *)(v14 + 7) = v26;
    *(uint8_t *)(v14 + 0xB) = 1;
    sub_124BFC(v14 + 12, v28 + 60000 * v27);
    msg_parse(dword_115838, (char)v26, v25, v29);
  }
  v16 = dword_11581C;
  *(uint8_t *)(v14 + 6) = 0;
  v17 = feature_guard_sdio(1024, v16, v15);
  if ( sub_11E9B8(v17) )
    sub_12CFC4(0x80000);
  v18 = (uint32_t *)dword_115828;
  v19 = (uint32_t *)dword_11582C;
  v20 = *(uint64_t *)(*(uint32_t *)dword_115820 + 8);
  *(uint32_t *)dword_115824 = v20;
  *v18 = HIDWORD(v20) + v20 - 4;
  *v19 = v20;
  v18[2] = v20;
  result = (uint32_t *)dword_115830;
  v22 = *v3;
  *(uint32_t *)(dword_115830 + 0x14) = v20;
  result[3] = v20;
  result[4] = HIDWORD(v20) + v20;
  if ( v22 )
  {
    v23 = v22 - 1;
    v24 = *(uint32_t *)dword_1157F8;
    *v3 = v23;
    if ( !v23 )
    {
      if ( v24 )
        __enable_irq();
    }
  }
  return result;
}
