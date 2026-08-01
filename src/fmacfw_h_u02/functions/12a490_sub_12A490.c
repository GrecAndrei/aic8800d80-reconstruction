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

extern uint32_t dword_12A4B0;

// lll_conn_get @ 0x12a490, size 30 bytes
uint8_t * lll_conn_get(uint8_t *result)
{
  if ( result[1224] )
    return rsn_parse_ie((uint8_t *)(dword_12A4B0 + 140 * result[1225]));
  return result;
}

