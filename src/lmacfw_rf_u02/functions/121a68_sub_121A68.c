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

extern uint32_t off_121A7C;

// sub_121A68 @ 0x121a68, size 18 bytes
// Doc: rf_cmd_dispatch_n_4da [rf]: RF command dispatch table lookup (variant 4da)
// rf_cmd_dispatch_n_4da [rf]: RF command dispatch table lookup (variant 4da)
int sub_121A68()
{
  if ( **(uint8_t **)off_121A7C == 3 )
    return sub_10CEC0();
  else
    return 1;
}

