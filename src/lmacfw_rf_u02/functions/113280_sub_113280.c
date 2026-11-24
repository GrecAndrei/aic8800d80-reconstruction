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


extern uint32_t dword_1132B8;
extern uint32_t dword_1132BC;
extern uint32_t off_1132B4;

// tx_event_handler @ 0x113280, size 52 bytes
uint32_t *tx_event_handler()
{
  void *v0; // r5
  uint32_t *result; // r0
  int v2; // r7
  int v3; // r6
  int v4; // r4
  uint32_t *v5; // r0

  v0 = off_1132B4;
  result = list_init_1((uint32_t *)dword_1132B8);
  if ( *(uint16_t *)(*(uint32_t *)v0 + 4) )
  {
    v2 = dword_1132BC;
    v3 = dword_1132B8;
    v4 = 0;
    do
    {
      v5 = list_iterate(v2, 0x7Cu);
      result = (uint32_t *)check_kernel_state(v3, v5);
      ++v4;
    }
    while ( *(uint16_t *)(*(uint32_t *)v0 + 4) > (unsigned int)(uint16_t)v4 );
  }
  return result;
}
