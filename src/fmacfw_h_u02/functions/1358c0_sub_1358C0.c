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

// ke_msg_handler @ 0x1358c0, size 124 bytes
int  ke_msg_handler(uint16_t *a1)
{
  uint16_t *v1; // r6
  int v3; // r5
  int result; // r0
  int v5; // r3
  int v6; // r3

  v1 = a1 + 6;
  invalid_handler_12c5fc((char *)0x180A, 6);
  v3 = v1[2];
  result = check_feature_flag(256, "auth_handler:%d\r\n", v3);
  if ( v3 )
    return assert_trace(v3);
  v5 = a1[6];
  if ( !a1[6] )
    return mac_dma_setup();
  if ( v5 != 1 )
  {
    if ( v5 == 2 )
      return ke_msg_alloc(*((uint8_t *)a1 + 8), (int)(a1 + 9), (uint16_t)(*a1 - 6));
    return result;
  }
  v6 = v1[1];
  if ( v6 == 4 )
  {
    crypto_read_status(0xBB8u);
    return mac_dma_setup();
  }
  if ( v6 == 2 && *a1 > 0x22u )
    return ll_evt_schedule(3, (int)(a1 + 10));
  return result;
}
