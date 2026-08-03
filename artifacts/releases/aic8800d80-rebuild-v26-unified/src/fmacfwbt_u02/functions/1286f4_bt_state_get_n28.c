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

extern uint32_t off_128740;

// bt_state_get_n28 @ 0x1286f4, size 74 bytes
// Doc: bt_state_get_n28 [bt]: Read BT state field at offset 0x28 from global control block
// bt_state_get_n28 [bt]: Read BT state field at offset 0x28 from global control block
BOOL  bt_state_get_n28(int a1)
{
  int v1; // r3
  unsigned int v2; // r1

  v1 = *((uint32_t *)off_128740 + 10);
  if ( !v1 )
    return 0;
  v2 = *(uint8_t *)(v1 + 24);
  if ( v2 <= 2 )
    return *(uint32_t *)(a1 + 72) == v1;
  if ( *(uint32_t *)(a1 + 72) && !*(uint8_t *)(a1 + 1224) && v2 == 4 )
    return sub_1286B4(a1);
  return *(uint8_t *)(v1 + 26) == *(uint8_t *)(a1 + 107);
}

