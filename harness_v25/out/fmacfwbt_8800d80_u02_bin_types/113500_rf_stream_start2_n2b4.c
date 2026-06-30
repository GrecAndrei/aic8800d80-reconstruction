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

// rf_stream_start2_n2b4 @ 0x113500, size 14 bytes
// Doc: rf_stream_start2_n2b4 [rf]: Looks up RF stream handler by stream id and starts it.
// rf_stream_start2_n2b4 [rf]: Looks up RF stream handler by stream id and starts it.
int  rf_stream_start2_n2b4(unsigned int a1)
{
  if ( a1 > 7 )
    return 0;
  else
    return *(uint32_t *)(rf_stream_start2_n2c4 + 4 * a1);
}

