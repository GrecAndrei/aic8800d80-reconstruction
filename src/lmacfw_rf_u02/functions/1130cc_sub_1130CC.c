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

extern uint32_t off_113148;
extern uint32_t dword_11314C;
extern uint32_t off_11315C;
extern uint32_t off_113150;
extern uint32_t dword_113160;
extern uint32_t dword_113164;
extern uint32_t off_113168;
extern uint32_t dword_113158;
extern uint32_t dword_113154;

// timer_event_handler @ 0x1130cc, size 124 bytes
int timer_event_handler()
{
  void *v0; // r7
  int result; // r0
  uint16_t *v2; // r9
  uint16_t *v3; // r6
  int v4; // r8
  int v5; // r11
  int16_t **v6; // r10
  uint16_t v7; // r5
  unsigned int v8; // r1

  v0 = off_113148;
  result = list_init(dword_11314C);
  if ( *(uint16_t *)(*(uint32_t *)v0 + 8) )
  {
    v2 = off_11315C;
    v3 = off_113150;
    v4 = dword_113160;
    v5 = dword_113164;
    v6 = (int16_t **)off_113168;
    v7 = 0;
    do
    {
      if ( !list_iterate(v4, (uint16_t)(v2[153] - 4)) )
      {
        dispatch_event_handler(v5, v7);
        if ( **v6 < 0 )
          flash_ctrl_init(dword_113158, dword_113154, 495);
      }
      result = check_kernel_state(dword_11314C);
      v8 = *(uint16_t *)(*(uint32_t *)v0 + 8);
      ++v7;
      ++*v3;
    }
    while ( v8 > v7 );
  }
  return result;
}

