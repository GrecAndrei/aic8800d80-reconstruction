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

extern uint32_t dword_13BFD0;
extern uint32_t dword_13BFD4;

// rf_validate_freq @ 0x13bf64, size 108 bytes
int  rf_validate_freq(int a1, int a2)
{
  int v3; // r7
  int v5; // r4

  if ( a2 == 255 )
    return 2;
  v3 = dword_13BFD0;
  v5 = *(uint8_t *)(696 * (uint8_t)a1 + 12 * (uint8_t)a2 + dword_13BFD0 + 453);
  return v5 == 33
      || hci_cmd_handler((v5 << 8) | 8) != 1
      || *(uint16_t *)(dword_13BFD4 + 32 * v5 + 20) > ((*(uint16_t *)(v3 + 2 * (a2 + 348 * a1) + 316)
                                                              - *(uint16_t *)(*(uint32_t *)(dword_13BFD4 + 32 * v5 + 28) + 4))
                                                             & 0xFFFu);
}

