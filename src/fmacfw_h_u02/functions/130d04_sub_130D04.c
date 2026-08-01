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

// addba_request_ack @ 0x130d04, size 18 bytes
uint8_t * addba_request_ack(uint8_t *a1, int a2, int a3)
{
  uint8_t *result; // r0

  result = test_arg2_one_12db20(a1, a2);
  if ( result )
    result = (uint8_t *)(uint8_t)result[2];
  *(uint8_t *)(a3 + 216) = (uint8_t)result;
  return result;
}

