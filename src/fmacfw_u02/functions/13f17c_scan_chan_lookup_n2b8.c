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

extern uint32_t off_13F240;
extern uint32_t dword_13F22C;
extern uint32_t dword_13F234;
extern uint32_t dword_13F230;
extern uint32_t dword_13F23C;
extern uint32_t dword_13F238;

// ble_ll_conn_sm_get_by_handle @ 0x13f17c, size 174 bytes
// Doc: ble_ll_conn_sm_get_by_handle [scan]: Lookup channel entry from 0x2b8-stride table
// ble_ll_conn_sm_get_by_handle [scan]: Lookup channel entry from 0x2b8-stride table
int  ble_ll_conn_sm_get_by_handle(int a1, unsigned int a2, unsigned int a3)
{
  int16_t **v3; // r8
  int v4; // r3
  int result; // r0
  uint8_t *v7; // r4
  int16_t *v10; // r3

  v3 = (int16_t **)off_13F240;
  v4 = dword_13F22C + 696 * a1;
  result = **(int16_t **)off_13F240;
  v7 = *(uint8_t **)(v4 + 340);
  if ( result < 0 && !v7 )
    result = mmio_clear_register(dword_13F234, dword_13F230, 3326);
  if ( (uint8_t)v7[179] != a2 || (uint8_t)v7[180] != a3 )
  {
    v10 = *v3;
    v7[179] = a2;
    if ( *v10 < 0 && a2 > 3 )
    {
      result = mmio_clear_register(dword_13F23C, dword_13F230, 3332);
      v10 = *v3;
    }
    v7[180] = a3;
    if ( *v10 < 0 && a3 > 7 )
      result = mmio_clear_register(dword_13F238, dword_13F230, 3334);
    if ( (v7[166] & 0x20) != 0 )
      v7[166] |= 0x80u;
    else
      return ble_ll_conn_sm_get(a1);
  }
  return result;
}

