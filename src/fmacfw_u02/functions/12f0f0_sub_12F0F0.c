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

// log_event_1068 @ 0x12f0f0, size 22 bytes
void  log_event_1068()
{
  char *v0; // r0

  event_dispatch(aReboot);
  v0 = ke_int_lock((char *)0x42C, 1);
  read_state_flag_1((int)v0);
}
