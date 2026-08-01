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

extern uint32_t dword_1194F0;

// phy_channel_validate @ 0x1194cc, size 36 bytes
// Doc: sub_12194CC [ipc]: Indexed lookup into 0x2b8-sized element array, shift-test field
// sub_12194CC [ipc]: Indexed lookup into 0x2b8-sized element array, shift-test field
int  phy_channel_validate(int a1, int a2, int a3)
{
  if ( (*(uint32_t *)(dword_1194F0 + 696 * a1 + 4) & 0x20) != 0 )
    return ble_acl_handle(a1, 7, a2, a3);
  else
    return ble_conn_get(a1, a2, a3);
}

