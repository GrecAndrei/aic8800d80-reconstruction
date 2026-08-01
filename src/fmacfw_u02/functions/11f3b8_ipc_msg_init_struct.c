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

// llm_conn_reset_state @ 0x11f3b8, size 18 bytes
// Doc: llm_conn_reset_state [ipc]: Initialize IPC/control struct fields to zero/one
// llm_conn_reset_state [ipc]: Initialize IPC/control struct fields to zero/one
int  llm_conn_reset_state(int result)
{
  *(uint8_t *)(result + 52) = 1;
  *(uint8_t *)(result + 163) = 0;
  *(uint32_t *)(result + 184) = 0;
  return result;
}

