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

extern uint32_t off_112078;
extern uint32_t off_112080;

// hw_status_update @ 0x112030, size 66 bytes
// Doc: rf_bus_setup_n30c [rf]: Setup RF bus with branch-out to sub-init
// rf_bus_setup_n30c [rf]: Setup RF bus with branch-out to sub-init
int hw_status_update()
{
  uint8_t *v0; // r4
  int v1; // r0
  int ( *v3)(uint32_t); // r3

  v0 = patch_apply_n_224;
  v1 = *((uint16_t *)patch_apply_n_224 + 7);
  *(uint16_t *)off_112078 = v1;
  if ( v1 )
  {
    v3 = *((int ( **)(uint32_t))off_112080 + 5);
    if ( v3 && v3((uint8_t)v1) )
    {
      *(uint8_t *)patch_apply_n24 = 4;
      *v0 = 7;
      if ( !is_rf_calib_running() )
        log_and_handle(0);
      return 1;
    }
    else
    {
      return 0;
    }
  }
  else
  {
    *(uint8_t *)patch_apply_n24 = 3;
    return 1;
  }
}

