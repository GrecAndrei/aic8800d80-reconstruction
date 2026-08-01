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

extern uint32_t off_1416BC;
extern uint32_t dword_1416A8;
extern uint32_t dword_1416B8;
extern uint32_t dword_1416AC;
extern uint32_t dword_1416B4;
extern uint32_t dword_1416B0;

// ll_event_process @ 0x1415ec, size 186 bytes
int ll_event_process()
{
  int16_t **v0; // r8
  int v1; // r5
  int v2; // r4
  int v3; // r6
  int v4; // r7
  int result; // r0

  v0 = (int16_t **)off_1416BC;
  v1 = dword_1416A8;
  v2 = *(uint32_t *)(dword_1416A8 + 6480);
  if ( **(int16_t **)off_1416BC >= 0 || v2 < 0 && (result = mmio_clear_register(dword_1416B8, dword_1416AC, 1734), **v0 >= 0) )
  {
    v3 = 16 * v2;
    if ( *(uint8_t *)(v1 + 136 * v2 + 6339) > 1u )
      return result;
    return ble_ll_adv_reset(v1 + 8 * (v2 + v3) + 6336, 0);
  }
  v4 = v1 + 136 * v2;
  v3 = 16 * v2;
  if ( *(uint8_t *)(v4 + 6338) == 5 )
  {
    if ( *(uint8_t *)(v4 + 6339) <= 1u )
      return ble_ll_adv_reset(v1 + 8 * (v2 + v3) + 6336, 0);
    return mmio_clear_register(dword_1416B4, dword_1416AC, 1744);
  }
  result = mmio_clear_register(dword_1416B0, dword_1416AC, 1735);
  if ( *(uint8_t *)(v4 + 6339) <= 1u )
    return ble_ll_adv_reset(v1 + 8 * (v2 + v3) + 6336, 0);
  if ( **v0 < 0 )
    return mmio_clear_register(dword_1416B4, dword_1416AC, 1744);
  return result;
}

