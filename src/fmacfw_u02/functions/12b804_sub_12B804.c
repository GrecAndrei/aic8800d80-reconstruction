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

extern uint32_t off_12B87C;
extern uint32_t off_12B898;
extern uint32_t dword_12B8A4;
extern uint32_t dword_12B8A0;
extern uint32_t off_12B880;
extern uint32_t off_12B888;
extern uint32_t off_12B88C;
extern uint32_t off_12B890;
extern uint32_t off_12B894;
extern uint32_t off_12B884;
extern uint32_t off_12B89C;

// read_cal_trim @ 0x12b804, size 120 bytes
// Doc: sub_122B804 [util]: Check global flag value and branch on sign
// sub_122B804 [util]: Check global flag value and branch on sign
int read_cal_trim()
{
  uint32_t *v0; // r1
  int v1; // r6
  int *v2; // r4
  uint32_t *v3; // r2
  uint32_t *v4; // r5
  uint32_t *v5; // r7
  int v6; // r3
  int result; // r0
  uint32_t *v8; // r4
  int v9; // r3
  int *v10; // r3
  int v11; // r3

  if ( **(int16_t **)off_12B87C < 0 && !(*(uint32_t *)off_12B898 << 28) )
    return bad_func_0x12f408(dword_12B8A4, dword_12B8A0, 213, *(uint32_t *)off_12B898);
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_12B880 = 1;
  }
  v0 = off_12B888;
  v1 = *(uint32_t *)off_12B888;
  v2 = (int *)off_12B88C;
  v3 = off_12B890;
  v4 = off_12B894;
  v5 = off_12B898;
  v6 = *(uint32_t *)off_12B884 + 25000;
  result = *(uint32_t *)off_12B888 + 1;
  *(uint32_t *)off_12B888 = result;
  *v2 = v6;
  v8 = off_12B89C;
  *v3 = 128;
  v9 = v8[1] | 4;
  *v4 |= 0x80u;
  v8[1] = v9;
  *v5 = 0;
  if ( result )
  {
    v10 = (int *)off_12B880;
    *v0 = v1;
    v11 = *v10;
    if ( !v1 )
    {
      if ( v11 )
        __enable_irq();
    }
  }
  return result;
}

