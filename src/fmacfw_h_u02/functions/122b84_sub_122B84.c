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

extern uint32_t off_122B98;

// ipc_mbox_write @ 0x122b84, size 20 bytes
int  ipc_mbox_write(int a1, uint32_t *a2, int a3, int a4)
{
  *(uint32_t *)off_122B98 = *a2;
  mac_write_header_word(114, a4, a3);
  return 0;
}

