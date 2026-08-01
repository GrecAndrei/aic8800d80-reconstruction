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

extern uint32_t off_11CBC0;
extern uint32_t off_11CBC4;

// aes_encrypt @ 0x11cb84, size 60 bytes
// Doc: aes_encrypt [rf]: init RF power table from offset 0x168/0x16c
// aes_encrypt [rf]: init RF power table from offset 0x168/0x16c
int  aes_encrypt(int a1)
{
  char *v1; // r4
  uint32_t *v2; // r6
  int result; // r0

  v1 = (char *)off_11CBC0;
  v2 = off_11CBC4;
  memcpy_large(off_11CBC0, *(uint32_t *)(a1 + 360), *(uint16_t *)(a1 + 364));
  v2[1] = memchr(v1, *(uint16_t *)(*v2 + 364));
  result = queue_remove();
  *(uint32_t *)&v1[-8] = *(uint32_t *)&v1[-12] - 1 + *(uint16_t *)(a1 + 364);
  *((uint32_t *)v1 - 1) = 0;
  return result;
}

