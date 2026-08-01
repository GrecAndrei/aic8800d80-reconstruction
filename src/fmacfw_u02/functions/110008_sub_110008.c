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

extern uint32_t dword_1100EC;
extern uint32_t off_1100E4;
extern uint32_t dword_1100FC;
extern uint32_t dword_1100F0;
extern uint32_t off_1100E8;
extern uint32_t dword_1100F8;
extern uint32_t dword_1100F4;

// is_controller_mode @ 0x110008, size 218 bytes
int  is_controller_mode(uint32_t *a1)
{
  int result; // r0
  int v3; // r2
  int v4; // r3
  int v5; // r3

  result = check_controller_mode((unsigned int)a1);
  if ( !result )
  {
    result = log_printf(dword_1100EC, a1);
    v5 = **(uint8_t **)off_1100E4;
    if ( v5 != 1 )
    {
      if ( v5 == 2 )
        return assert_error(a1);
      if ( v5 != 3 )
      {
LABEL_11:
        if ( !check_controller_mode((unsigned int)a1) )
          log_printf(dword_1100FC, a1);
        return util_is_nonnull(dword_1100F0, a1);
      }
      if ( **(int16_t **)off_1100E8 < 0 )
        return mmio_clear_register(dword_1100F8, dword_1100F4, 204);
      return result;
    }
    return is_park_mode(a1);
  }
  v3 = *((uint8_t *)a1 - 4);
  v4 = **(uint8_t **)off_1100E4;
  if ( v4 == 1 )
  {
    if ( v3 == 3 )
      return is_connected_flag(a1);
    if ( v3 == 2 )
      return is_sniff_mode(a1);
    if ( *((uint8_t *)a1 - 4) )
      return result;
    return is_park_mode(a1);
  }
  if ( v4 != 2 )
  {
    if ( v4 == 3 )
    {
      if ( **(int16_t **)off_1100E8 >= 0 )
      {
        if ( v3 != 3 )
          return result;
        return sub_11428c(a1);
      }
      if ( v3 == 3 )
        return sub_11428c(a1);
      return mmio_clear_register(dword_1100F8, dword_1100F4, 204);
    }
    goto LABEL_11;
  }
  if ( v3 == 3 )
    return assert_fault(a1);
  if ( !*((uint8_t *)a1 - 4) )
    return assert_error(a1);
  return result;
}

