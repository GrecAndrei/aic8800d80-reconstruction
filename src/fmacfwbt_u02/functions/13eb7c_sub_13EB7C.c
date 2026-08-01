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

// check_radio_irq_status @ 0x13eb7c, size 42 bytes
// Doc: bitfield_pack_u16_to_u32 [util]: Pack u16 bitfield into u32 with bit extraction
// bitfield_pack_u16_to_u32 [util]: Pack u16 bitfield into u32 with bit extraction
unsigned int  check_radio_irq_status(unsigned int result)
{
  unsigned int v1; // r2

  v1 = *(uint32_t *)(*(uint32_t *)(result + 76) + 4);
  if ( (v1 & 0x810000) != 0 )
    return alloc_send_packet(result, BYTE1(v1) + 1, (HIWORD(v1) & 1) + BYTE1(v1), 0, 0);
  return result;
}

