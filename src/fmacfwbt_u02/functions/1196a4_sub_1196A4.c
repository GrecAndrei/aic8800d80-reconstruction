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

extern uint32_t dword_1197D0;
extern uint32_t off_1197BC;
extern uint32_t dword_1197CC;
extern uint32_t dword_1197C8;
extern uint32_t dword_1197D8;
extern uint32_t off_1197C0;
extern uint32_t dword_1197C4;
extern uint32_t dword_1197D4;

// rx_state_check @ 0x1196a4, size 278 bytes
// Doc: sub_12196A4 [unknown]: Push context and branch on state byte field 0x6a
// sub_12196A4 [unknown]: Push context and branch on state byte field 0x6a
int  rx_state_check(int a1, int a2, int a3)
{
  int v3; // r3
  int v4; // r3
  int v7; // r3
  BOOL v8; // r0
  int v9; // r8
  int v10; // r0
  int v11; // r2
  int v12; // r6
  int v13; // r5
  uint16_t *v14; // r2
  int16_t v15; // r3
  int16_t v16; // r1
  int v17; // r0

  v3 = *(uint8_t *)(a1 + 106);
  if ( v3 != 2 )
  {
    ke_event_schedule(dword_1197D0, v3, a3);
    return 1;
  }
  v4 = *(uint32_t *)(a1 + 72);
  if ( v4 )
  {
    v7 = *(uint8_t *)(v4 + 4);
    if ( **(int16_t **)off_1197BC >= 0 || v7 != 2 )
    {
      v8 = (v7 | *(uint8_t *)(a1 + 1224)) != 0;
      goto LABEL_5;
    }
  }
  else if ( **(int16_t **)off_1197BC >= 0 )
  {
    goto LABEL_9;
  }
  mmio_irq_clear(dword_1197CC, dword_1197C8, 520);
LABEL_9:
  v8 = 1;
LABEL_5:
  v9 = dword_1197D8;
  v10 = event_notify(v8, *(uint16_t *)(dword_1197D8 + 2 * *(uint8_t *)(a1 + 107)));
  v12 = v10;
  if ( v10 )
  {
    scan_done_check(a1, v10);
    v13 = *(uint32_t *)(v12 + 72);
    *(uint8_t *)(v13 + 108) = 80;
    *(uint8_t *)(v13 + 109) = 0;
    *(uint8_t *)(v13 + 110) = 0;
    *(uint8_t *)(v13 + 111) = 0;
    memcpy_aligned(v13 + 112, a2, 6);
    v14 = off_1197C0;
    v15 = *((uint16_t *)off_1197C0 + 254);
    v16 = *(uint16_t *)(a1 + 104);
    *(uint32_t *)(v13 + 118) = *(uint32_t *)(a1 + 100);
    ++v15;
    v17 = *(uint32_t *)(a1 + 100);
    *(uint16_t *)(v13 + 122) = v16;
    *(uint32_t *)(v13 + 124) = v17;
    *(uint16_t *)(v13 + 128) = v16;
    v14[254] = v15;
    *(uint16_t *)(v13 + 130) = 16 * v15;
    memcpy_aligned(
      v13 + 132,
      dword_1197C4 + (*(uint8_t *)(a1 + 107) << 9),
      *(uint16_t *)(v9 + 2 * *(uint8_t *)(a1 + 107)) - 24);
    *(uint32_t *)(v12 + 88) = 0;
    *(uint32_t *)(v12 + 92) = 0;
    *(uint8_t *)(v12 + 28) = *(uint8_t *)(a1 + 107);
    *(uint8_t *)(v12 + 29) = -1;
    ble_event_dispatch(v12, 5);
    return 0;
  }
  else
  {
    ke_event_schedule(dword_1197D4, *(uint16_t *)(v9 + 2 * *(uint8_t *)(a1 + 107)), v11);
    return 1;
  }
}

