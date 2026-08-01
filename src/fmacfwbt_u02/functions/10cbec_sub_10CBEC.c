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

extern uint32_t off_10CC1C;
extern uint32_t off_10CC20;
extern uint32_t off_10CC24;
extern uint32_t off_10CC28;

// pmu_isr_extra @ 0x10cbec, size 48 bytes
int pmu_isr_extra()
{
  uint32_t *v0; // r4
  int *v1; // r7
  uint32_t *v2; // r6
  int v3; // r0
  int result; // r0

  v0 = off_10CC1C;
  if ( (*(uint32_t *)off_10CC1C & 2) != 0 )
  {
    v1 = (int *)off_10CC20;
    v2 = off_10CC24;
    do
    {
      v3 = *v1;
      *v2 = 2;
      pkt_buf_alloc((uint16_t *)(v3 + 4));
    }
    while ( (*v0 & 2) != 0 );
  }
  result = set_system_flag_2(0x8000000);
  *(uint32_t *)off_10CC28 = 2;
  return result;
}

