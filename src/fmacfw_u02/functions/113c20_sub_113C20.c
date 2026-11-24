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


extern uint32_t off_113C3C;
extern uint32_t off_113C40;
extern uint32_t off_113C44;

// sub_113C20 @ 0x113c20, size 28 bytes
int  sub_113C20(int a1)
{
  uint8_t *v1; // r2
  char v2; // r3

  sub_113ABC(a1);
  v1 = off_113C44;
  v2 = ((uint32_t *)(uintptr_t)off_113C3C)[88];
  *(uint8_t *)off_113C40 = BYTE2(((uint32_t *)(uintptr_t)off_113C3C)[81]);
  *v1 = v2;
  return 1;
}
