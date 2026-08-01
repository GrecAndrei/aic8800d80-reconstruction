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

extern uint32_t dword_12EE68;

// msg_alloc_0x40c @ 0x12ee14, size 82 bytes
int  msg_alloc_0x40c(int a1, uint32_t *a2, int16_t a3, int16_t a4)
{
  uint32_t *v5; // r5
  int v6; // r0
  int v7; // zf
  int v8; // r2

  v5 = (uint32_t *)ke_msg_alloc(1036, a4, a3, 4u);
  v6 = *a2;
  v7 = *a2 << 30 == 0;
  v8 = a2[1];
  *v5 = 0;
  if ( !v7 )
    *v5 = 255;
  if ( v8 << 30 )
    *v5 = 1;
  memcpy(v6, a2 + 2, v8);
  event_dispatch(dword_12EE68, *a2, a2[1] + *a2, a2[2], *v5);
  ke_msg_send((int)v5);
  return 0;
}

