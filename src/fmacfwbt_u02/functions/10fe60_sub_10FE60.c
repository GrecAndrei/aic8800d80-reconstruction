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

// memory_pool_free @ 0x10fe60, size 218 bytes
int  memory_pool_free(uint32_t *a1)
{
  int result; // r0
  int v3; // r2
  int v4; // r3
  int v5; // r3

  result = is_address_in_heap((unsigned int)a1);
  if ( !result )
  {
    result = printf_wrapper(dword_10FF44, a1);
    v5 = **(uint8_t **)off_10FF3C;
    if ( v5 != 1 )
    {
      if ( v5 == 2 )
        return critical_section_enter_no_set(a1);
      if ( v5 != 3 )
      {
LABEL_11:
        if ( !is_address_in_heap((unsigned int)a1) )
          printf_wrapper(dword_10FF54, a1);
        return list_insert(dword_10FF48, a1);
      }
      if ( **(int16_t **)off_10FF40 < 0 )
        return mmio_irq_clear(dword_10FF50, dword_10FF4C, 204);
      return result;
    }
    return critical_enter_7(a1);
  }
  v3 = *((uint8_t *)a1 - 4);
  v4 = **(uint8_t **)off_10FF3C;
  if ( v4 == 1 )
  {
    if ( v3 == 3 )
      return critical_enter_3(a1);
    if ( v3 == 2 )
      return critical_enter_5(a1);
    if ( *((uint8_t *)a1 - 4) )
      return result;
    return critical_enter_7(a1);
  }
  if ( v4 != 2 )
  {
    if ( v4 == 3 )
    {
      if ( **(int16_t **)off_10FF40 >= 0 )
      {
        if ( v3 != 3 )
          return result;
        return set_busy_flag(a1);
      }
      if ( v3 == 3 )
        return set_busy_flag(a1);
      return mmio_irq_clear(dword_10FF50, dword_10FF4C, 204);
    }
    goto LABEL_11;
  }
  if ( v3 == 3 )
    return critical_section_enter(a1);
  if ( !*((uint8_t *)a1 - 4) )
    return critical_section_enter_no_set(a1);
  return result;
}

