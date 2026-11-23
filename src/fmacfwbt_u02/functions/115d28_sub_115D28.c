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


extern uint32_t dword_115E84;
extern uint32_t dword_115E88;
extern uint32_t dword_115E8C;
extern uint32_t dword_115E90;
extern uint32_t dword_115E94;
extern uint32_t dword_115E98;
extern uint32_t dword_115EA0;
extern uint32_t dword_115EA4;
extern uint32_t dword_115EA8;
extern uint32_t dword_115EAC;
extern uint32_t dword_115EB0;
extern uint32_t dword_115EB4;
extern uint32_t dword_115EB8;
extern uint32_t dword_115EBC;
extern uint32_t dword_115EC0;
extern uint32_t dword_115EC4;
extern uint32_t dword_115EC8;

// mac_status_check @ 0x115d28, size 346 bytes
uint32_t * mac_status_check(int a1, int a2)
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
  int v25; // r6
  int v26; // r2
  volatile unsigned int v27; // r3

  v2 = **(uint16_t **)dword_115E84;
  if ( (v2 & 1) != 0 )
    sub_12F3BC(a1, a2, v2 << 31);
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)dword_115E88 = 1;
  }
  v3 = (int *)dword_115E8C;
  v4 = dword_115E90;
  v5 = dword_115E94;
  ++*(uint32_t *)dword_115E8C;
  sub_12EEF8(1024, v5, v4);
  v6 = sub_12D374(0x80000000);
  v7 = sub_12BD74(v6);
  v8 = (uint32_t *)dword_115E98;
  *(uint32_t *)dword_115E98 &= 0xFFFFFFu;
  *v8 |= 0x10u;
  v9 = (*(volatile uint32_t *)0x40501010u);
  v10 = v9 + 100;
  do
    v11 = v10 - (*(volatile uint32_t *)0x40501010u);
  while ( v11 >= 0 );
  v12 = (uint32_t *)dword_115EA0;
  *(uint32_t *)dword_115EA0 |= 0x111u;
  v13 = sub_117FFC(v7);
  *(uint32_t *)dword_115E98 &= ~0x10u;
  *v12 &= 0xFFFFFEEE;
  sub_1213EC(v13);
  if ( !sub_12D0B0(0) )
    sub_12D374(0x2000000);
  v14 = dword_115EA4;
  sub_11FACC();
  if ( *(uint8_t *)v14 && !*(uint8_t *)dword_115EA8 && *(uint8_t *)(v14 + 6) )
  {
    v25 = *(char *)(v14 + 7) + (char)(*(uint8_t *)(v14 + 5) + (*(uint8_t *)dword_115EC4 & 3));
    if ( v25 >= *(char *)(v14 + 4) )
      LOBYTE(v25) = *(uint8_t *)(v14 + 4);
    sub_1029F8((char)v25);
    v26 = *(uint16_t *)(v14 + 8);
    v27 = (*(volatile uint32_t *)0x40501010u);
    *(uint8_t *)(v14 + 7) = v25;
    *(uint8_t *)(v14 + 0xB) = 1;
    sub_124F60(v14 + 12, v27 + 60000 * v26);
    sub_12ECB0(dword_115EC8);
  }
  v16 = dword_115EAC;
  *(uint8_t *)(v14 + 6) = 0;
  v17 = sub_12EEF8(1024, v16, v15);
  if ( sub_11EF38(v17) )
    sub_12D32C(0x80000);
  v18 = (uint32_t *)dword_115EB8;
  v19 = (uint32_t *)dword_115EBC;
  v20 = *(uint64_t *)(*(uint32_t *)dword_115EB0 + 8);
  *(uint32_t *)dword_115EB4 = v20;
  *v18 = HIDWORD(v20) + v20 - 4;
  *v19 = v20;
  v18[2] = v20;
  result = (uint32_t *)dword_115EC0;
  v22 = *v3;
  *(uint32_t *)(dword_115EC0 + 0x14) = v20;
  result[3] = v20;
  result[4] = HIDWORD(v20) + v20;
  if ( v22 )
  {
    v23 = v22 - 1;
    v24 = *(uint32_t *)dword_115E88;
    *v3 = v23;
    if ( !v23 )
    {
      if ( v24 )
        __enable_irq();
    }
  }
  return result;
}
