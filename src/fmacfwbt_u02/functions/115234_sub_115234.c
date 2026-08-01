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

extern uint32_t off_115260;
extern uint32_t off_115264;
extern uint32_t off_115268;

// check_status_flags @ 0x115234, size 42 bytes
void check_status_flags()
{
  int *v0; // r4

  v0 = (int *)off_115260;
  if ( !*(uint32_t *)off_115260 )
    *v0 = enter_critical_set_flag();
  if ( !*(uint32_t *)off_115264 )
    *(uint32_t *)off_115264 = *v0 + 67092480;
  *(uint32_t *)off_115268 = 1;
}

