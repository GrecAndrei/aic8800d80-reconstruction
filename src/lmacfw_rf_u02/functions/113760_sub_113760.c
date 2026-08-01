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

extern uint32_t off_1137A8;
extern uint32_t off_1137AC;
extern uint32_t dword_1137B0;

// controller_state_machine @ 0x113760, size 72 bytes
int controller_state_machine()
{
  uint32_t *v0; // r5
  void *v1; // r7
  int result; // r0
  int v3; // r6
  int v4; // r4

  v0 = off_1137A8;
  v1 = off_1137AC;
  list_init(*(uint32_t *)off_1137A8 + 580);
  result = list_init(*v0 + 588);
  if ( *(uint16_t *)(*(uint32_t *)v1 + 8) )
  {
    v3 = dword_1137B0;
    v4 = 0;
    do
    {
      list_iterate(v3, 0x6B8u);
      result = check_kernel_state(*v0 + 580);
      ++v4;
    }
    while ( *(uint16_t *)(*(uint32_t *)v1 + 8) > (unsigned int)(uint16_t)v4 );
  }
  return result;
}

