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

extern uint32_t off_10FFFC;

// log_alloc @ 0x10ffbc, size 62 bytes
// Doc: log_alloc [util]: Logs allocation event based on debug flag
// log_alloc [util]: Logs allocation event based on debug flag
uint32_t * log_alloc(char a1)
{
  uint32_t *v2; // r4

  if ( **(uint8_t **)off_10FFFC == 1 )
    v2 = (uint32_t *)sub_110480();
  else
    v2 = sub_10FB28(log_free_pool_dispatch2_n320, 0x7Cu);
  if ( !v2 )
    return v2;
  if ( sub_10FF34((unsigned int)v2) )
  {
    *((uint8_t *)v2 - 1) = a1;
    return v2;
  }
  sub_10DC24(rf_fault_dump_n3cc, v2);
  return v2;
}

