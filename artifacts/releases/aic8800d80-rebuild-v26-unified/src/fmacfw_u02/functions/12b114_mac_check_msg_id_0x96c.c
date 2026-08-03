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

extern uint32_t off_12B16C;

// mac_check_msg_id_0x96c @ 0x12b114, size 88 bytes
// Doc: mac_check_msg_id_0x96c [mac]: Check incoming message id against 0x96c and dispatch via context
// mac_check_msg_id_0x96c [mac]: Check incoming message id against 0x96c and dispatch via context
int  mac_check_msg_id_0x96c(uint16_t *a1)
{
  int v1; // r3
  int result; // r0

  v1 = *a1;
  result = *(uint32_t *)(*(uint32_t *)off_12B16C + 16);
  if ( v1 == 2412
    || v1 == 2437
    || v1 == 2462
    || v1 == 2472
    || v1 == 5180
    || v1 == 5220
    || v1 == 5765
    || v1 == 5785
    || v1 == 5805 )
  {
    result += 20000;
  }
  return result;
}

