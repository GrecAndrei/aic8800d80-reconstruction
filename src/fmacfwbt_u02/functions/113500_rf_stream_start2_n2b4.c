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

// table_index_lookup @ 0x113500, size 14 bytes
// Doc: table_index_lookup [rf]: Looks up RF stream handler by stream id and starts it.
// table_index_lookup [rf]: Looks up RF stream handler by stream id and starts it.
int  table_index_lookup(unsigned int a1)
{
  if ( a1 > 7 )
    return 0;
  else
    return *(uint32_t *)(rf_stream_start2_n2c4 + 4 * a1);
}

