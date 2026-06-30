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

extern uint32_t dword_10FF44;
extern uint32_t off_10FF3C;
extern uint32_t dword_10FF54;
extern uint32_t dword_10FF48;
extern uint32_t off_10FF40;
extern uint32_t dword_10FF50;
extern uint32_t dword_10FF4C;

// log_free_dispatch_2 @ 0x10fe60, size 218 bytes
// Doc: log_free_dispatch [util]: Free log dispatch buffer entry
// log_free_dispatch [util]: Free log dispatch buffer entry
int  log_free_dispatch_2(uint32_t *a1)
{
  int result; // r0
  int v3; // r2
  int v4; // r3
  int v5; // r3

  result = log_ptr_in_range((unsigned int)a1);
  if ( !result )
  {
    result = log_printf(dword_10FF44, a1);
    v5 = **(uint8_t **)off_10FF3C;
    if ( v5 != 1 )
    {
      if ( v5 == 2 )
        return log_free_pool_d(a1);
      if ( v5 != 3 )
      {
LABEL_11:
        if ( !log_ptr_in_range((unsigned int)a1) )
          log_printf(dword_10FF54, a1);
        return sub_10FB38(dword_10FF48, a1);
      }
      if ( **(int16_t **)off_10FF40 < 0 )
        return sub_12F694(dword_10FF50, dword_10FF4C, 204);
      return result;
    }
    return sub_110318(a1);
  }
  v3 = *((uint8_t *)a1 - 4);
  v4 = **(uint8_t **)off_10FF3C;
  if ( v4 == 1 )
  {
    if ( v3 == 3 )
      return sub_1101E8(a1);
    if ( v3 == 2 )
      return sub_110288(a1);
    if ( *((uint8_t *)a1 - 4) )
      return result;
    return sub_110318(a1);
  }
  if ( v4 != 2 )
  {
    if ( v4 == 3 )
    {
      if ( **(int16_t **)off_10FF40 >= 0 )
      {
        if ( v3 != 3 )
          return result;
        return patch_apply_nd0(a1);
      }
      if ( v3 == 3 )
        return patch_apply_nd0(a1);
      return sub_12F694(dword_10FF50, dword_10FF4C, 204);
    }
    goto LABEL_11;
  }
  if ( v3 == 3 )
    return sub_113760(a1);
  if ( !*((uint8_t *)a1 - 4) )
    return log_free_pool_d(a1);
  return result;
}

