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

extern uint32_t off_1387A4;
extern uint32_t off_1387A8;
extern uint32_t off_1387AC;
extern uint32_t off_1387B0;
extern uint32_t off_1387B4;
extern uint32_t off_1387B8;
extern uint32_t off_1387DC;
extern uint32_t off_1387E4;
extern uint32_t dword_1387E0;
extern uint32_t off_1387BC;
extern uint32_t dword_1387D8;
extern uint32_t dword_1387C4;
extern uint32_t dword_1387C0;
extern uint32_t off_1387CC;
extern uint32_t off_1387D0;
extern uint32_t off_1387C8;
extern uint32_t dword_1387D4;

// ll_task_run @ 0x138668, size 316 bytes
// Doc: sub_1238668 [unknown]: Check flag byte and branch based on result
// sub_1238668 [unknown]: Check flag byte and branch based on result
uint32_t *ll_task_run()
{
  uint32_t *v0; // r6
  uint16_t *v1; // r4
  uint32_t *v2; // r5
  int v3; // r6
  char *v4; // r3
  char *v5; // r0
  uint32_t *v6; // r3
  uint8_t *v7; // r1
  BOOL v8; // r2
  BOOL v9; // r0
  int *v10; // r2
  uint16_t *v11; // r0
  int v12; // r1
  unsigned int v13; // r2
  int v15; // r1
  uint32_t *v16; // r2
  int v17; // r3
  int v18; // r2

  if ( *(uint8_t *)off_1387A4 )
    write_phy_config(0xC2u);
  if ( **(uint8_t **)off_1387A8 == 1 )
    *(uint32_t *)off_1387AC &= ~0x200000u;
  v0 = off_1387B0;
  v1 = off_1387B4;
  v2 = off_1387B8;
  if ( (*(uint32_t *)off_1387B0 & 4) != 0 )
  {
    v15 = *(uint16_t *)(*(uint32_t *)off_1387DC + 54);
    v16 = off_1387E4;
    v17 = dword_1387E0 + 1320 * *(uint8_t *)(*(uint32_t *)off_1387B4 + 366);
    *((uint8_t *)off_1387B8 + 29) = 3;
    v18 = v16[4];
    v2[5] = v17;
    unknown_worker((int)(v2 + 3), v15 + v18);
    *((uint8_t *)v2 + 28) = 1;
    *v0 &= ~4u;
  }
  v3 = *((uint8_t *)v1 + 3850);
  if ( !*((uint8_t *)v1 + 3850) )
  {
    v4 = (char *)off_1387B4;
    v5 = (char *)off_1387B4 + 3840;
    do
    {
      v4[8] = v3;
      v4[64] = 0x80;
      v4 += 60;
    }
    while ( v5 != v4 );
    v6 = off_1387BC;
    v1[2] = v3;
    v6[1] = v3;
  }
  v7 = *(uint8_t **)v1;
  if ( *(uint8_t *)(*(uint32_t *)v1 + 368) == 1 && v7[252] == 7 )
  {
    v9 = memcmp(v7 + 253, dword_1387D8, 7) == 0;
    v7 = *(uint8_t **)v1;
    v3 = *((uint8_t *)v1 + 3850);
    v8 = v9;
  }
  else
  {
    v8 = 0;
    LOBYTE(v9) = 0;
  }
  *((uint8_t *)v1 + 3898) = v9;
  check_status_bits(8, dword_1387C4, dword_1387C0, (uint8_t)v7[366], v3, v8, (uint8_t)v7[367]);
  v10 = (int *)off_1387CC;
  v11 = off_1387D0;
  *(uint32_t *)off_1387C8 |= 4u;
  *v11 = *v10;
  *v10 = (HIWORD(*v10) << 16) | 0x5DC;
  v2[1] |= 0x20u;
  rx_phy_status_parse(4u, 1);
  v12 = *(uint32_t *)(*(uint32_t *)v1 + 360);
  if ( v12 )
  {
    v13 = *(uint16_t *)(*(uint32_t *)v1 + 364);
    if ( v13 <= 0xC8 )
      memcpy(dword_1387D4, v12, v13);
  }
  return ll_state_machine();
}

