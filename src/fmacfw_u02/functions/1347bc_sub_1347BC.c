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

extern uint32_t dword_1347F0;
extern uint32_t off_1347F4;
extern uint32_t dword_1347FC;
extern uint32_t dword_1347F8;

// bt_is_controller_ready @ 0x1347bc, size 52 bytes
int bt_is_controller_ready()
{
  uint32_t *v0; // r0
  uint32_t *v1; // r4

  v0 = mem_word_load(dword_1347F0);
  v1 = v0;
  if ( **(int16_t **)off_1347F4 < 0 && !v0 )
    mmio_clear_register(dword_1347FC, dword_1347F8, 766);
  return ke_msg_send((int)(v1 + 3));
}

