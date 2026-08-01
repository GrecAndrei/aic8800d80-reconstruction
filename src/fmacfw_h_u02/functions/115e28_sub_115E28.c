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

extern uint32_t off_115EB0;
extern uint32_t dword_115EAC;
extern uint32_t off_115EB4;
extern uint32_t off_115EB8;
extern uint32_t dword_115EBC;
extern uint32_t dword_115EC0;
extern uint32_t off_115EC4;

// rssi_sample @ 0x115e28, size 132 bytes
int rssi_sample()
{
  int **v0; // r5
  uint32_t *v1; // r6
  int *v2; // r0
  void *v3; // r8
  int v4; // r7
  uint16_t v5; // r9
  int result; // r0

  v0 = (int **)off_115EB0;
  clear_stats_buf(dword_115EAC);
  if ( **(int16_t **)off_115EB4 < 0 )
  {
    v2 = *v0;
    v1 = off_115EB8;
    if ( !*v0 || !*(uint32_t *)off_115EB8 )
    {
      irq_disable_mmio_write(dword_115EBC, dword_115EC0, 90);
      v2 = *v0;
    }
  }
  else
  {
    v1 = off_115EB8;
    v2 = *v0;
  }
  v3 = off_115EC4;
  v4 = dword_115EAC;
  sub_100200(v2, 0, 88 * *(uint16_t *)(*(uint32_t *)off_115EC4 + 8) + 88);
  v5 = 0;
  do
  {
    (*v0)[22 * v5 + 19] = *v1 + 80 * v5;
    result = wlan_ioctl_handler_1(v4);
    ++v5;
  }
  while ( *(uint16_t *)(*(uint32_t *)v3 + 8) >= (unsigned int)v5 );
  return result;
}

