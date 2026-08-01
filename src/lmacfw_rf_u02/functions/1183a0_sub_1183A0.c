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

extern uint32_t off_118428;
extern uint32_t off_11842C;
extern uint32_t off_118430;
extern uint32_t off_118434;
extern uint32_t off_118438;

// poll_hw_status @ 0x1183a0, size 134 bytes
int poll_hw_status()
{
  int result; // r0
  uint32_t *v1; // r1
  uint16_t *v2; // r3
  unsigned int v3; // r2
  int16_t v4; // r2
  uint32_t *v5; // r1
  int16_t v6; // r2
  uint32_t *v7; // r1

  if ( (uint16_t)(*(uint32_t *)off_118428 >> 12) && (uint16_t)(*(uint32_t *)off_118428 >> 12) <= 0x96u )
    result = (uint16_t)(*(uint32_t *)off_118428 >> 12);
  else
    result = 150;
  v1 = off_11842C;
  v2 = off_118430;
  v3 = *(uint32_t *)off_11842C;
  *((uint16_t *)off_118430 + 4) = result;
  if ( (uint16_t)(v3 >> 12) && (uint16_t)(*v1 >> 12) <= 0x96u )
    v4 = *v1 >> 12;
  else
    v4 = 150;
  v5 = off_118434;
  v2[5] = v4;
  if ( (uint16_t)(*v5 >> 12) && (uint16_t)(*v5 >> 12) <= 0x96u )
    v6 = *v5 >> 12;
  else
    v6 = 150;
  v7 = off_118438;
  v2[6] = v6;
  if ( (uint16_t)(*v7 >> 12) && (uint16_t)(*v7 >> 12) <= 0x96u )
    v2[7] = *v7 >> 12;
  else
    v2[7] = 150;
  return result;
}

