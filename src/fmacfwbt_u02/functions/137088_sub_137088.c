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

extern uint32_t dword_1370A4;
extern uint32_t off_1370A0;

// rf_state_update @ 0x137088, size 22 bytes
int  rf_state_update(int a1, int a2, int a3, int a4)
{
  state_check_feature(8, dword_1370A4, a4, *((uint16_t *)off_1370A0 + 1924));
  return 2;
}

