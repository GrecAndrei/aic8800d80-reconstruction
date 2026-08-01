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

extern uint32_t off_12A188;
extern uint32_t dword_12A194;
extern uint32_t dword_12A190;
extern uint32_t dword_12A18C;

// bt_runtime_check @ 0x12a140, size 72 bytes
// Doc: sub_122A140 [unknown]: Wrapper checking global flag before operation
// sub_122A140 [unknown]: Wrapper checking global flag before operation
unsigned int  bt_runtime_check(int a1, uint32_t *a2, uint32_t *a3)
{
  int v6; // r3
  int v7; // r0

  if ( **(int16_t **)off_12A188 < 0 && !*(uint8_t *)(a1 + 1224) )
    mmio_clear_register(dword_12A194, dword_12A190, 1311);
  v6 = dword_12A18C + 140 * *(uint8_t *)(a1 + 1225);
  *a2 = *(uint32_t *)(v6 + 128);
  v7 = *(uint32_t *)(v6 + 124);
  *a3 = v7;
  return (unsigned int)(v7 - *a2) >> 31;
}

