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

// sub_11E888 @ 0x11e888, size 42 bytes
// Doc: sdio_buffer_prepare_n_32a [tx]: Validate/prepare SDIO buffer descriptor
// sdio_buffer_prepare_n_32a [tx]: Validate/prepare SDIO buffer descriptor
uint32_t * sub_11E888(uint32_t *result, uint32_t *a2, uint32_t *a3)
{
  uint32_t **v3; // r3

  if ( !a2 )
    return (uint32_t *)list_push_tail((int)result, a3);
  v3 = (uint32_t **)*result;
  if ( (uint32_t *)*result == a2 )
    return (uint32_t *)sub_11E76C((int)result, a3);
  if ( v3 )
  {
    while ( 1 )
    {
      result = *v3;
      if ( *v3 == a2 )
        break;
      v3 = (uint32_t **)*v3;
      if ( !result )
        return result;
    }
    *a3 = a2;
    *v3 = a3;
  }
  return result;
}

