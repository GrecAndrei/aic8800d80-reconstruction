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

extern uint32_t off_121AD8;
extern uint32_t off_121ADC;
extern uint32_t off_121AE0;
extern uint32_t dword_121AE4;

// patch_check_enabled_ctx @ 0x121a84, size 82 bytes
void  patch_check_enabled_ctx(int a1)
{
  int v2; // r0
  int v3; // r5
  uint32_t *v4; // r4

  if ( **(uint8_t **)off_121AD8 == 3 )
  {
    v2 = poll_hw_status();
    v3 = v2;
    if ( v2 )
    {
      *(uint32_t *)(a1 + 24) = 49374;
      memcpy_large(v2, a1, 28);
      v4 = off_121ADC;
      while ( !*(uint32_t *)off_121ADC )
        ;
      check_kernel_state(*(uint32_t *)off_121AE0 + 540, (uint32_t *)(v3 - 4));
      *v4 = 1;
      rf_enable();
    }
    else
    {
      dispatch_event_handler(dword_121AE4);
    }
  }
}

