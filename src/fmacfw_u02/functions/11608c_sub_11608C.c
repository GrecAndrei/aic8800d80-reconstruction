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

// call_delayed_callback @ 0x11608c, size 18 bytes
// Doc: sub_121608C [mac]: Fetch context pointer at offset 0x48 from object
// sub_121608C [mac]: Fetch context pointer at offset 0x48 from object
uint32_t * call_delayed_callback(int a1)
{
  uint32_t *result; // r0

  result = *(uint32_t **)(a1 + 72);
  if ( result )
  {
    result = (uint32_t *)is_controller_mode(result);
    *(uint32_t *)(a1 + 72) = 0;
  }
  return result;
}

