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

extern uint32_t dword_136854;
extern uint32_t off_136858;
extern uint32_t dword_136860;
extern uint32_t dword_13685C;

// bt_ready_check @ 0x136820, size 50 bytes
int bt_ready_check()
{
  uint32_t *v0; // r0
  uint32_t *v1; // r4

  v0 = mem_word_load(dword_136854);
  v1 = v0;
  if ( **(int16_t **)off_136858 < 0 && !v0 )
    mmio_clear_register(dword_136860, dword_13685C, 210);
  return ke_msg_send((int)(v1 + 3));
}

