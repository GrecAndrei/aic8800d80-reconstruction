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


extern uint32_t dword_13BF54;
extern uint32_t dword_13BF58;
extern uint32_t off_13BF5C;

// ke_event_handler_1 @ 0x13be74, size 222 bytes
int  ke_event_handler_1(int a1, int a2, uint16_t a3)
{
  uint16_t v6; // r0
  char v7; // r11
  int v8; // r4
  uint16_t v9; // r6
  char v10; // r0
  uint16_t v11; // r12
  int v12; // r2
  int v13; // zf
  uint16_t v14; // r0
  int v15; // r7
  volatile unsigned int v16; // r2
  uint16_t v17; // r6
  volatile unsigned int v18; // r3

  v6 = ke_get_state_1(a1, a2);
  v7 = v6;
  if ( (uint8_t)v6 == 33 )
    return 3;
  v8 = dword_13BF54 + 32 * (uint8_t)v6;
  v9 = v6;
  *(uint8_t *)(v8 + 22) = a2;
  *(uint8_t *)(v8 + 16) = a1;
  v10 = hash32();
  v12 = dword_13BF58;
  *(uint8_t *)(v8 + 23) = v10;
  v13 = (*(uint32_t *)(v12 + 696 * a1 + 4) & 0x20) == 0;
  v14 = *(uint16_t *)(*(uint32_t *)off_13BF5C + 2);
  *(uint8_t *)(v8 + 18) = 1;
  *(uint8_t *)(v8 + 17) = 1;
  *(uint32_t *)(v8 + 4) = 0;
  v15 = v12 + 696 * a1 + 12 * a2;
  if ( !v13 )
    v11 = 256;
  v16 = (*(volatile uint32_t *)0x40501010u);
  if ( v13 )
    v11 = 64;
  *(uint16_t *)(v8 + 20) = v11;
  *(uint16_t *)(v8 + 14) = v14;
  *(uint32_t *)(v8 + 8) = v16;
  *(uint16_t *)(v8 + 12) = a3;
  *(uint8_t *)(v15 + 453) = v7;
  init_state_table(a1, v8, 2, 0, 0, 0x27u, 0);
  v17 = (v9 << 8) | 8;
  init_state_table(a1, v8, 0, 0, 0, 0, 0);
  v18 = (*(volatile uint32_t *)0x40501010u);
  *(uint32_t *)(v15 + 444) = v18;
  ke_event_handler(0x2000, v17, 0x7D000u);
  hci_cmd_preprocess(v17, 2);
  return 0;
}
