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

// handle_state_change @ 0x129e84, size 56 bytes
uint8_t * handle_state_change(uint8_t *result)
{
  int v1; // r3
  uint8_t *v2; // r4
  int v3; // r1

  v1 = result[114];
  v2 = result;
  if ( v1 == 1 )
  {
    result[114] = 0;
    return state_machine_step(result);
  }
  else if ( v1 == 2 )
  {
    v3 = *((uint32_t *)result + 29);
    result[114] = 1;
    ke_event_lock((int)(result + 96), v3);
    return state_machine_step(v2);
  }
  return result;
}

