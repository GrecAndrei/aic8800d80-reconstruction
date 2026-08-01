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

extern uint32_t off_1337B0;
extern uint32_t dword_1337B8;
extern uint32_t dword_1337B4;

// patch_handle_data @ 0x13376c, size 68 bytes
uint32_t * patch_handle_data(int a1)
{
  int v1; // r5
  unsigned int v2; // r2
  uint32_t *v4; // r0
  int *v5; // r1

  v1 = *(uint32_t *)(a1 + 8);
  v2 = *(uint8_t *)(a1 + 12);
  if ( **(int16_t **)off_1337B0 < 0 && v2 > 3 )
  {
    mmio_clear_register(dword_1337B8, dword_1337B4, 321);
    LOBYTE(v2) = *(uint8_t *)(a1 + 12);
  }
  v4 = crypto_mix_round((uint32_t *)a1, (int *)(a1 + 4), (90 << (8 * v2)) | v1);
  return crypto_mix_round(v4, v5, 0);
}

