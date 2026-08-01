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

extern uint32_t off_121A8C;
extern uint32_t dword_121AC0;
extern uint32_t dword_121ABC;
extern uint32_t dword_121A90;
extern uint32_t off_121A94;
extern uint32_t off_121AC4;
extern uint32_t off_121A98;
extern uint32_t off_121A9C;
extern uint32_t dword_121AB8;
extern uint32_t off_121AA4;
extern uint32_t off_121AA8;
extern uint32_t off_121AA0;
extern uint32_t off_121AAC;
extern uint32_t off_121AB0;
extern uint32_t off_121AB4;

// ke_evt_handler @ 0x1219a4, size 230 bytes
int ke_evt_handler()
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

  if ( **(int16_t **)off_121A8C < 0 && hci_cmd_handler(0) == 4 )
    irq_disable_mmio_write(dword_121AC0, dword_121ABC, 1799);
  check_feature_flag(4, dword_121A90);
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_121A94 = 1;
  }
  v0 = (int *)off_121AC4;
  v1 = (int *)off_121A98;
  v2 = off_121A9C;
  ++*(uint32_t *)off_121AC4;
  v3 = *v1;
  *v1 = 0;
  v4 = v2[4];
  v5 = v3 & 0xF;
  while ( *v1 << 28 )
  {
    radio_irq_clear();
    if ( (unsigned int)(v2[4] - v4) > 0x7530 )
      check_feature_flag(4, dword_121AB8);
  }
  v6 = off_121AA4;
  v7 = off_121AA8;
  v8 = *(uint32_t *)off_121AA4;
  *((uint32_t *)off_121AA0 + 1) &= ~4u;
  if ( v5 && (*v7 & v8 & 4) == 0 )
  {
    while ( (*v7 & *v6 & 4) == 0 )
      ;
  }
  v9 = *((uint8_t *)off_121AAC + 90);
  *(uint32_t *)off_121AB0 = 4;
  if ( v9 )
    critical_section_enter();
  result = hci_cmd_preprocess(0);
  v11 = *v0;
  *((uint16_t *)off_121AB4 + 9) = 0;
  if ( v11 )
  {
    v12 = v11 - 1;
    v13 = *(uint32_t *)off_121A94;
    *v0 = v12;
    if ( !v12 )
    {
      if ( v13 )
        __enable_irq();
    }
  }
  return result;
}

