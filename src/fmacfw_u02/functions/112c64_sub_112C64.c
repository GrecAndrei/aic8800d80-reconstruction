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


extern uint32_t off_112C8C;
extern uint32_t off_112C94;

// get_state_byte @ 0x112c64, size 40 bytes
int get_state_byte()
{
  int result; // r0

  if ( (((uint32_t *)(uintptr_t)off_112C8C)[44] & 0x40000000) != 0 )
    result = (int)read_memory_byte(aUsbSusp_0);
  else
    result = event_dispatch(aUsbSusp);
  *(uint8_t *)off_112C94 = 1;
  return result;
}
