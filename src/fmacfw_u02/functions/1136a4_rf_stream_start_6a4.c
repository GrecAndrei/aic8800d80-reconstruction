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

// lookup_channel_table @ 0x1136a4, size 14 bytes
// Doc: lookup_channel_table [rf]: start RF data stream
// lookup_channel_table [rf]: start RF data stream
int  lookup_channel_table(unsigned int a1)
{
  if ( a1 > 7 )
    return 0;
  else
    return *(uint32_t *)(rf_stream_start_6b4 + 4 * a1);
}

