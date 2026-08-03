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

// rf_phy_field_clear_n_23c @ 0x11f120, size 76 bytes
// Doc: rf_phy_field_clear_n_23c [rf]: Clears/resets a 32-bit PHY field at struct offset 0x23c
// rf_phy_field_clear_n_23c [rf]: Clears/resets a 32-bit PHY field at struct offset 0x23c
int * rf_phy_field_clear_n_23c(int a1)
{
  int v2; // r5
  int v3; // r0
  int *result; // r0
  int v5; // r3

  v2 = a1 + 572;
  while ( *(uint32_t *)(a1 + 572) )
  {
    v3 = sub_12D4F8(v2);
    sub_11913C(v3, 1);
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

