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

extern uint32_t off_10C7C4;
extern uint32_t dword_10C7C8;
extern uint32_t dword_10C7CC;
extern uint32_t off_10C7D0;
extern uint32_t off_10C7D4;
extern uint32_t off_10C7D8;

// clear_context_182b48 @ 0x10c750, size 114 bytes
int *clear_context_182b48()
{
  int v0; // r4
  int v1; // zf
  uint8_t v2; // r1
  int **v3; // r4

  v0 = *((uint32_t *)off_10C7C4 + 23);
  memset_byte((int *)dword_10C7C8, 0, 0x28u);
  memset_byte((int *)dword_10C7CC, 0, 0x1E6Cu);
  if ( (*(uint32_t *)off_10C7D0 & 8) != 0 )
  {
    while ( (*(uint32_t *)off_10C7D0 & 0x10) == 0 )
      ;
    v3 = (int **)off_10C7D4;
  }
  else
  {
    v2 = v0 & 3;
    v1 = (v0 & 3) == 0;
    v3 = (int **)off_10C7D4;
    *(uint32_t *)off_10C7D0 |= 8u;
    if ( v1 )
      memset_byte(*v3, v2, 0x248u);
    *(uint32_t *)off_10C7D0 |= 0x10u;
  }
  (*v3)[145] = *(uint32_t *)off_10C7D8;
  return pmu_clock_config();
}

