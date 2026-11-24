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


extern uint32_t dword_1140E0;
extern uint32_t off_1140D8;
extern uint32_t off_1140DC;

// init_hw_timers @ 0x114090, size 72 bytes
uint32_t *init_hw_timers()
{
  int *v0; // r5
  void *v1; // r7
  uint32_t *result; // r0
  int v3; // r6
  int v4; // r4
  uint32_t *v5; // r0

  v0 = (int *)off_1140D8;
  v1 = off_1140DC;
  zero_struct((uint32_t *)(((uint32_t *)(uintptr_t)off_1140D8)[0] + 564));
  result = zero_struct((uint32_t *)(*v0 + 572));
  if ( *(uint16_t *)(*(uint32_t *)v1 + 8) )
  {
    v3 = dword_1140E0;
    v4 = 0;
    do
    {
      v5 = rx_process_item(v3, 0x6B8u);
      result = (uint32_t *)check_abort_flag(*v0 + 564, v5);
      ++v4;
    }
    while ( *(uint16_t *)(*(uint32_t *)v1 + 8) > (unsigned int)(uint16_t)v4 );
  }
  return result;
}
