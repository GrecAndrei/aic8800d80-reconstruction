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

extern uint32_t off_115264;
extern uint32_t off_115268;

// check_status_flags @ 0x115234, size 42 bytes
// Doc: patch_apply_n_2a2 [patch]: Write patch entry to MMIO base and flag completion
// patch_apply_n_2a2 [patch]: Write patch entry to MMIO base and flag completion
void check_status_flags()
{
  int *v0; // r4

  v0 = (int *)patch_apply_n_288;
  if ( !*(uint32_t *)patch_apply_n_288 )
    *v0 = enter_critical_set_flag();
  if ( !*(uint32_t *)off_115264 )
    *(uint32_t *)off_115264 = *v0 + 67092480;
  *(uint32_t *)off_115268 = 1;
}

