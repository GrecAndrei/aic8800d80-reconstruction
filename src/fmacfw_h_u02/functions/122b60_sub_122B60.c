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

extern uint32_t dword_122B80;

// ipc_send_command @ 0x122b60, size 32 bytes
int  ipc_send_command(int a1, int a2, int a3, int a4)
{
  *(uint16_t *)(dword_122B80 + 1320 * *(uint8_t *)(a2 + 2) + 1222) = *(uint16_t *)a2;
  mac_write_header_word(112, a4, a3);
  return 0;
}

