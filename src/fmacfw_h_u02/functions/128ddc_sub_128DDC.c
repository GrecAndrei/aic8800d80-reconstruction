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

extern uint32_t off_128E10;
extern uint32_t off_128E14;

// mfp_key_get_status @ 0x128ddc, size 50 bytes
int mfp_key_get_status()
{
  uint32_t *v0; // r4
  uint32_t *v1; // r3

  v0 = off_128E10;
  if ( !*(uint8_t *)off_128E10 && !bt_ll_flow_control_check() )
    return 0;
  if ( v0[1] )
    return 0;
  v1 = *((uint32_t **)off_128E14 + 2);
  if ( v1 )
  {
    while ( !v1[1] )
    {
      v1 = (uint32_t *)*v1;
      if ( !v1 )
        return 1;
    }
    return 0;
  }
  return 1;
}

