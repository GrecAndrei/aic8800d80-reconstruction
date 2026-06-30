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

// obj_read_field_23c @ 0x11eda4, size 76 bytes
// Doc: obj_read_field_23c [util]: Read 32-bit field at offset 0x23c from object handle
// obj_read_field_23c [util]: Read 32-bit field at offset 0x23c from object handle
int * obj_read_field_23c(int a1)
{
  int v2; // r5
  int v3; // r0
  int *result; // r0
  int v5; // r3

  v2 = a1 + 572;
  while ( *(uint32_t *)(a1 + 572) )
  {
    v3 = rf_bus_mark_n100_d2d0(v2);
    sub_118CFC(v3, 1);
  }
  result = memset_thunk((int *)a1, 0, 0x2B8u);
  v5 = a1;
  do
  {
    *(uint8_t *)(v5 + 452) = 33;
    *(uint8_t *)(v5 + 453) = 33;
    v5 += 12;
  }
  while ( v5 != a1 + 108 );
  *(uint8_t *)(a1 + 34) = -1;
  return result;
}

