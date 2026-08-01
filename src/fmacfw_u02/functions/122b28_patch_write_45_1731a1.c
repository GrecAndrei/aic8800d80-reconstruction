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

extern uint32_t dword_122B44;

// log_message @ 0x122b28, size 28 bytes
// Doc: log_message [patch]: Call patch helper with marker 0x1731a1 and value 0x45
// log_message [patch]: Call patch helper with marker 0x1731a1 and value 0x45
int  log_message(int a1, int a2, int a3, int a4)
{
  memcpy(dword_122B44, a2, 69);
  ke_msg_send_no_param(120, a4, a3);
  return 0;
}

