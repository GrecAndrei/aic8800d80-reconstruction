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

// bt_msg_send_if_allocated @ 0x125e0c, size 10 bytes
int  bt_msg_send_if_allocated(uint8_t **a1, uint8_t *a2)
{
  if ( a2 )
    return util_list_find(a1, a2);
  else
    return 0;
}

