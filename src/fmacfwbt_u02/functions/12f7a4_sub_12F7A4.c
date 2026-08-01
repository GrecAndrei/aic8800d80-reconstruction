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

extern uint32_t off_12F7F8;
extern uint32_t off_12F7FC;
extern uint32_t off_12F800;
extern uint32_t dword_12F804;

// dispatch_if_ready @ 0x12f7a4, size 82 bytes
void  dispatch_if_ready(int a1)
{
  int v2; // r0
  int v3; // r5
  uint32_t *v4; // r4

  if ( **(uint8_t **)off_12F7F8 == 3 )
  {
    v2 = pmu_isr_214();
    v3 = v2;
    if ( v2 )
    {
      *(uint32_t *)(a1 + 24) = 49374;
      memcpy_aligned(v2, a1, 28);
      v4 = off_12F7FC;
      while ( !*(uint32_t *)off_12F7FC )
        ;
      check_abort_flag(*(uint32_t *)off_12F800 + 540, (uint32_t *)(v3 - 4));
      *v4 = 1;
      pmu_ctrl_write_128();
    }
    else
    {
      ke_event_schedule(dword_12F804);
    }
  }
}

