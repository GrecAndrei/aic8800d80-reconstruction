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

extern uint32_t off_115FF0;
extern uint32_t dword_115FEC;
extern uint32_t off_115FF4;
extern uint32_t off_115FF8;
extern uint32_t dword_115FFC;
extern uint32_t dword_116000;
extern uint32_t off_116004;

// kernel_event_wait @ 0x115f68, size 132 bytes
// Doc: kernel_event_wait [rf]: Reads RF fault status flag and dispatches accordingly
// kernel_event_wait [rf]: Reads RF fault status flag and dispatches accordingly
int kernel_event_wait()
{
  int **v0; // r5
  uint32_t *v1; // r6
  int *v2; // r0
  void *v3; // r8
  int v4; // r7
  uint16_t v5; // r9
  int result; // r0

  v0 = (int **)off_115FF0;
  zero_8_bytes(dword_115FEC);
  if ( **(int16_t **)off_115FF4 < 0 )
  {
    v2 = *v0;
    v1 = off_115FF8;
    if ( !*v0 || !*(uint32_t *)off_115FF8 )
    {
      mmio_clear_register(dword_115FFC, dword_116000, 90);
      v2 = *v0;
    }
  }
  else
  {
    v1 = off_115FF8;
    v2 = *v0;
  }
  v3 = off_116004;
  v4 = dword_115FEC;
  memset(v2, 0, 88 * *(uint16_t *)(*(uint32_t *)off_116004 + 8) + 88);
  v5 = 0;
  do
  {
    (*v0)[22 * v5 + 19] = *v1 + 80 * v5;
    result = cmd_handler_a(v4);
    ++v5;
  }
  while ( *(uint16_t *)(*(uint32_t *)v3 + 8) >= (unsigned int)v5 );
  return result;
}

