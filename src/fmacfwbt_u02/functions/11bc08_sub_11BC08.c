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

extern uint32_t off_11BC74;
extern uint32_t off_11BC78;
extern uint32_t off_11BC70;
extern uint32_t off_11BC6C;
extern uint32_t off_11BC7C;
extern uint32_t off_11BC80;
extern uint32_t off_11BC84;
extern uint32_t off_11BC88;

// crypto_aes_setup @ 0x11bc08, size 100 bytes
uint32_t * crypto_aes_setup(uint32_t *result)
{
  uint32_t *v1; // r2
  int v2; // r5
  uint32_t *v3; // r4
  uint32_t *v4; // r2
  uint32_t *v5; // r3
  uint32_t *v6; // r6
  int v7; // r4
  int v8; // r1
  uint32_t *v9; // r5

  v1 = off_11BC74;
  v2 = result[9];
  v3 = off_11BC78;
  *(uint32_t *)off_11BC70 = *(uint32_t *)off_11BC6C + 20000;
  *v1 = 64;
  v4 = off_11BC7C;
  v5 = off_11BC80;
  v6 = off_11BC84;
  *v3 |= 0x40u;
  v5[275] = *(uint32_t *)(v2 + 12);
  v7 = v4[52];
  v8 = result[15];
  v5[276] = *(uint32_t *)(v2 + 16);
  v4[52] = v7 | 1;
  v9 = off_11BC88;
  result[9] = v5 + 272;
  result[15] = v8 & 0xFF00;
  result[1] = 0;
  *((uint8_t *)v4 + 200) = 0;
  *v6 = result;
  *v9 = 0x2000;
  return result;
}

