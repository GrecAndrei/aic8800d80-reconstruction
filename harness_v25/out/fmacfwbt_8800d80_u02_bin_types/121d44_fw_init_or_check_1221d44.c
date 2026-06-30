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

extern uint32_t off_121E2C;
extern uint32_t dword_121E60;
extern uint32_t dword_121E5C;
extern uint32_t dword_121E30;
extern uint32_t off_121E34;
extern uint32_t off_121E64;
extern uint32_t off_121E38;
extern uint32_t off_121E3C;
extern uint32_t dword_121E58;
extern uint32_t off_121E44;
extern uint32_t off_121E48;
extern uint32_t off_121E40;
extern uint32_t off_121E4C;
extern uint32_t off_121E50;
extern uint32_t off_121E54;

// fw_init_or_check_1221d44 @ 0x121d44, size 230 bytes
// Doc: fw_init_or_check_1221d44 [util]: Firmware init/version check via shared flag pointer
// fw_init_or_check_1221d44 [util]: Firmware init/version check via shared flag pointer
int fw_init_or_check_1221d44()
{
  int *v0; // r8
  int *v1; // r4
  uint32_t *v2; // r5
  int v3; // r3
  int v4; // r7
  int v5; // r9
  uint32_t *v6; // r0
  uint32_t *v7; // r1
  int v8; // r4
  int v9; // r3
  int result; // r0
  int v11; // r3
  int v12; // r3
  int v13; // r2

  if ( **(int16_t **)off_121E2C < 0 && msg_get_value(0) == 4 )
    sub_12F694(dword_121E60, dword_121E5C, 1799);
  feature_guard_sdio(4, dword_121E30);
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_121E34 = 1;
  }
  v0 = (int *)off_121E64;
  v1 = (int *)off_121E38;
  v2 = off_121E3C;
  ++*(uint32_t *)off_121E64;
  v3 = *v1;
  *v1 = 0;
  v4 = v2[4];
  v5 = v3 & 0xF;
  while ( *v1 << 28 )
  {
    phy_reg_mask_check();
    if ( (unsigned int)(v2[4] - v4) > 0x7530 )
      feature_guard_sdio(4, dword_121E58);
  }
  v6 = off_121E44;
  v7 = off_121E48;
  v8 = *(uint32_t *)off_121E44;
  *((uint32_t *)off_121E40 + 1) &= ~4u;
  if ( v5 && (*v7 & v8 & 4) == 0 )
  {
    while ( (*v7 & *v6 & 4) == 0 )
      ;
  }
  v9 = *((uint8_t *)off_121E4C + 90);
  *(uint32_t *)off_121E50 = 4;
  if ( v9 )
    bitfield_pack_n_214();
  result = rf_bus_mark_n_3b7(0);
  v11 = *v0;
  *((uint16_t *)off_121E54 + 9) = 0;
  if ( v11 )
  {
    v12 = v11 - 1;
    v13 = *(uint32_t *)off_121E34;
    *v0 = v12;
    if ( !v12 )
    {
      if ( v13 )
        __enable_irq();
    }
  }
  return result;
}

