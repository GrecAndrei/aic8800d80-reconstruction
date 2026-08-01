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

extern uint32_t off_13BF60;
extern uint32_t dword_13BF54;
extern uint32_t dword_13BF58;
extern uint32_t off_13BF5C;

// ke_event_handler @ 0x13be74, size 222 bytes
int  ke_event_handler(int a1, int a2, int16_t a3)
{
  int v6; // r0
  char v7; // r11
  uint32_t *v8; // r8
  int v9; // r4
  int16_t v10; // r6
  char v11; // r0
  int16_t v12; // r12
  int v13; // r2
  int v14; // zf
  int16_t v15; // r0
  int v16; // r7
  int v17; // r2
  uint16_t v18; // r6

  v6 = ke_get_state();
  v7 = v6;
  if ( (uint8_t)v6 == 33 )
    return 3;
  v8 = off_13BF60;
  v9 = dword_13BF54 + 32 * (uint8_t)v6;
  v10 = v6;
  *(uint8_t *)(v9 + 22) = a2;
  *(uint8_t *)(v9 + 16) = a1;
  v11 = hash32(v6);
  v13 = dword_13BF58;
  *(uint8_t *)(v9 + 23) = v11;
  v14 = (*(uint32_t *)(v13 + 696 * a1 + 4) & 0x20) == 0;
  v15 = *(uint16_t *)(*(uint32_t *)off_13BF5C + 2);
  *(uint8_t *)(v9 + 18) = 1;
  *(uint8_t *)(v9 + 17) = 1;
  *(uint32_t *)(v9 + 4) = 0;
  v16 = v13 + 696 * a1 + 12 * a2;
  if ( !v14 )
    v12 = 256;
  v17 = v8[4];
  if ( v14 )
    v12 = 64;
  *(uint16_t *)(v9 + 20) = v12;
  *(uint16_t *)(v9 + 14) = v15;
  *(uint32_t *)(v9 + 8) = v17;
  *(uint16_t *)(v9 + 12) = a3;
  *(uint8_t *)(v16 + 453) = v7;
  init_state_table(a1, v9, 2, 0, 0, 39, 0);
  v18 = (v10 << 8) | 8;
  init_state_table(a1, v9, 0, 0, 0, 0, 0);
  *(uint32_t *)(v16 + 444) = v8[4];
  ke_event_handler(0x2000, v18, 0x7D000u);
  hci_cmd_preprocess(v18, 2);
  return 0;
}

