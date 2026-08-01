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

extern uint32_t off_12B588;
extern uint32_t off_12B594;
extern uint32_t dword_12B59C;
extern uint32_t dword_12B598;
extern uint32_t off_12B58C;
extern uint32_t off_12B590;

// read_cal_value @ 0x12b540, size 72 bytes
// Doc: sub_122B540 [unknown]: Compares signed halfword from global state to zero
// sub_122B540 [unknown]: Compares signed halfword from global state to zero
int read_cal_value()
{
  uint32_t *v0; // r4
  unsigned int v1; // r2
  int result; // r0

  if ( **(int16_t **)off_12B588 < 0 && *(uint32_t *)off_12B594 << 28 )
    return bad_func_0x12f408(dword_12B59C, dword_12B598, 105, *(uint32_t *)off_12B594);
  if ( (*(uint32_t *)off_12B58C & 0x80) != 0 )
  {
    v0 = off_12B590;
    v1 = *((uint32_t *)off_12B590 + 1) & 0xFFFFFFFB;
    *(uint32_t *)off_12B58C &= ~0x80u;
    v0[1] = v1;
    return unknown_func_12d104(0x2000000);
  }
  return result;
}

