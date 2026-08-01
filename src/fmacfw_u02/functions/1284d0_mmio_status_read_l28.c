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

extern uint32_t off_12851C;

// wlc_get_ops_alt @ 0x1284d0, size 74 bytes
// Doc: wlc_get_ops_alt [mmio]: Read status field at offset 0x28 from sysctl base
// wlc_get_ops_alt [mmio]: Read status field at offset 0x28 from sysctl base
BOOL  wlc_get_ops_alt(int a1)
{
  int v1; // r3
  unsigned int v2; // r1

  v1 = *((uint32_t *)off_12851C + 10);
  if ( !v1 )
    return 0;
  v2 = *(uint8_t *)(v1 + 24);
  if ( v2 <= 2 )
    return *(uint32_t *)(a1 + 72) == v1;
  if ( *(uint32_t *)(a1 + 72) && !*(uint8_t *)(a1 + 1224) && v2 == 4 )
    return wlc_get_ops(a1);
  return *(uint8_t *)(v1 + 26) == *(uint8_t *)(a1 + 107);
}

