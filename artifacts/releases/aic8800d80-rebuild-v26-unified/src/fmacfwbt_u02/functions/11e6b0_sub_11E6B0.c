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

extern uint32_t off_11E700;
extern uint32_t off_11E704;

// sub_11E6B0 @ 0x11e6b0, size 80 bytes
// Doc: sub_121E6B0 [util]: Helper reading byte offset 0x21 from global state struct
// sub_121E6B0 [util]: Helper reading byte offset 0x21 from global state struct
int  sub_11E6B0(int a1)
{
  uint32_t *v1; // r4
  int result; // r0
  unsigned int v3; // r3
  int v4; // r1
  int v5; // r2

  v1 = off_11E700;
  if ( *((uint8_t *)off_11E700 + 33) )
    *(uint32_t *)(*((uint32_t *)off_11E700 + 6) + 4) = a1;
  else
    *((uint32_t *)off_11E700 + 4) = a1;
  result = *((uint8_t *)off_11E704 + 193);
  v3 = v1[7] + v1[3];
  v4 = v1[5] + v1[1];
  v5 = v1[2];
  v1[5] = v4;
  v1[7] = v3;
  *((uint8_t *)v1 + 33) = 1;
  v1[6] = v5;
  if ( v3 >= result << 9 )
  {
    result = log_queue_push2(v1[4], v4, v5);
    v1[4] = 0;
    v1[5] = 0;
    v1[6] = 0;
    v1[7] = 0;
    *((uint8_t *)v1 + 33) = 0;
  }
  return result;
}

