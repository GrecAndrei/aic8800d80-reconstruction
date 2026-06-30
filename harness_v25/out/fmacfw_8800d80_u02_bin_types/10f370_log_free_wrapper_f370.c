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

// log_free_wrapper_f370 @ 0x10f370, size 12 bytes
// Doc: log_free_wrapper_f370 [util]: Releases a log buffer (size 0x50) and signals completion
// log_free_wrapper_f370 [util]: Releases a log buffer (size 0x50) and signals completion
int  log_free_wrapper_f370(int a1, int a2)
{
  log_free_dispatch_2(a2);
  return 1;
}

