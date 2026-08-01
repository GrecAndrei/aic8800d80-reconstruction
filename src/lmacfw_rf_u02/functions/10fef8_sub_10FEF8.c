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

extern uint32_t dword_10FFDC;
extern uint32_t off_10FFD4;
extern uint32_t dword_10FFEC;
extern uint32_t dword_10FFE0;
extern uint32_t off_10FFD8;
extern uint32_t dword_10FFE8;
extern uint32_t dword_10FFE4;

// mem_free @ 0x10fef8, size 218 bytes
int  mem_free(uint32_t *a1)
{
  int result; // r0
  int v3; // r2
  int v4; // r3
  int v5; // r3

  result = mem_is_in_heap((unsigned int)a1);
  if ( !result )
  {
    result = log_printf(dword_10FFDC, a1);
    v5 = **(uint8_t **)off_10FFD4;
    if ( v5 != 1 )
    {
      if ( v5 == 2 )
        return lock_acquire(a1);
      if ( v5 != 3 )
      {
LABEL_11:
        if ( !mem_is_in_heap((unsigned int)a1) )
          log_printf(dword_10FFEC, a1);
        return sorted_list_search(dword_10FFE0, a1);
      }
      if ( **(int16_t **)off_10FFD8 < 0 )
        return flash_ctrl_init(dword_10FFE8, dword_10FFE4, 204);
      return result;
    }
    return irq_disable_set_flag_preserve_2(a1);
  }
  v3 = *((uint8_t *)a1 - 4);
  v4 = **(uint8_t **)off_10FFD4;
  if ( v4 == 1 )
  {
    if ( v3 == 3 )
      return irq_disable_set(a1);
    if ( v3 == 2 )
      return irq_disable_set_flag_preserve(a1);
    if ( *((uint8_t *)a1 - 4) )
      return result;
    return irq_disable_set_flag_preserve_2(a1);
  }
  if ( v4 != 2 )
  {
    if ( v4 == 3 )
    {
      if ( **(int16_t **)off_10FFD8 >= 0 )
      {
        if ( v3 != 3 )
          return result;
        return enter_critical_section(a1);
      }
      if ( v3 == 3 )
        return enter_critical_section(a1);
      return flash_ctrl_init(dword_10FFE8, dword_10FFE4, 204);
    }
    goto LABEL_11;
  }
  if ( v3 == 3 )
    return critical_section_enter_arg(a1);
  if ( !*((uint8_t *)a1 - 4) )
    return lock_acquire(a1);
  return result;
}

