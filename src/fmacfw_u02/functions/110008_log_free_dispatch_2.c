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

extern uint32_t dword_1100FC;
extern uint32_t dword_1100F0;

// log_free_dispatch_2 @ 0x110008, size 218 bytes
// Doc: log_free_pool_dispatch2 [util]: Dispatch log free pool entry and check log level
// log_free_pool_dispatch2 [util]: Dispatch log free pool entry and check log level
int  log_free_dispatch_2(uint32_t *a1)
{
  int result; // r0
  int v3; // r2
  int v4; // r3
  int v5; // r3

  result = sub_10FF34((unsigned int)a1);
  if ( !result )
  {
    result = sub_10DC24(log_free_pool_dispatch2_n40c, a1);
    v5 = **(uint8_t **)log_free_pool_dispatch2_n404;
    if ( v5 != 1 )
    {
      if ( v5 == 2 )
        return log_free_pool_d_3a48(a1);
      if ( v5 != 3 )
      {
LABEL_11:
        if ( !sub_10FF34((unsigned int)a1) )
          sub_10DC24(dword_1100FC, a1);
        return sub_10FCE0(dword_1100F0, a1);
      }
      if ( **(int16_t **)log_free_dispatch_ne0 < 0 )
        return sub_12F46C(log_free_dispatch_nf0, log_free_dispatch_nec, 204);
      return result;
    }
    return log_free_pool_c(a1);
  }
  v3 = *((uint8_t *)a1 - 4);
  v4 = **(uint8_t **)log_free_pool_dispatch2_n404;
  if ( v4 == 1 )
  {
    if ( v3 == 3 )
      return log_free_pool_a(a1);
    if ( v3 == 2 )
      return log_free_pool_b(a1);
    if ( *((uint8_t *)a1 - 4) )
      return result;
    return log_free_pool_c(a1);
  }
  if ( v4 != 2 )
  {
    if ( v4 == 3 )
    {
      if ( **(int16_t **)log_free_dispatch_ne0 >= 0 )
      {
        if ( v3 != 3 )
          return result;
        return log_free_pool_e_428c(a1);
      }
      if ( v3 == 3 )
        return log_free_pool_e_428c(a1);
      return sub_12F46C(log_free_dispatch_nf0, log_free_dispatch_nec, 204);
    }
    goto LABEL_11;
  }
  if ( v3 == 3 )
    return log_free_pool_f_904(a1);
  if ( !*((uint8_t *)a1 - 4) )
    return log_free_pool_d_3a48(a1);
  return result;
}

