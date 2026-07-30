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

extern uint32_t off_116610;

// bt_flag_check_init @ 0x1165b4, size 92 bytes
// Doc: bt_flag_check_init [bt]: Checks global BT flag state and dispatches init flow
// bt_flag_check_init [bt]: Checks global BT flag state and dispatches init flow
int * bt_flag_check_init(int a1, int a2, int a3, int a4)
{
  int *result; // r0
  char *v7; // r4
  int v8; // r5
  char v9; // t1
  uint8_t v10[8]; // [sp+8h] [bp-14h] BYREF
  char v11; // [sp+10h] [bp-Ch] BYREF

  if ( (**(uint8_t **)off_116610 & 1) != 0 )
    return memset_thunk((int *)(a3 + a4), 0, 8u);
  v7 = v10;
  rf_msg_dispatch_3800(v10, a2, a1 + 12, a1 + 18, *(uint8_t *)(a1 + 27));
  sub_13384C(v10, a3, a4);
  sub_133988(v10);
  v8 = a4 + a3;
  do
  {
    result = (int *)(v7 - v10);
    v9 = *v7++;
    *((uint8_t *)result + v8) = v9;
  }
  while ( v7 != &v11 );
  return result;
}

