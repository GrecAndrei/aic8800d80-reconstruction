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

extern uint32_t off_12D708;
extern uint32_t dword_12D718;
extern uint32_t dword_12D70C;
extern uint32_t dword_12D710;
extern uint32_t dword_12D714;

// check_abort_flag_4 @ 0x12d688, size 126 bytes
int  check_abort_flag_4(int result, uint32_t *a2, uint32_t *a3)
{
  int16_t **v3; // r7
  uint32_t *v4; // r6

  v3 = (int16_t **)off_12D708;
  v4 = (uint32_t *)result;
  if ( **(int16_t **)off_12D708 < 0 )
  {
    if ( result || (result = mmio_irq_clear(dword_12D718, dword_12D70C, 384), **v3 < 0) )
    {
      if ( a2 )
      {
        if ( (uint32_t *)*a2 != a3 )
        {
          result = mmio_irq_clear(dword_12D710, dword_12D70C, 385);
          if ( **v3 >= 0 )
            goto LABEL_3;
        }
        if ( a3 )
          goto LABEL_3;
      }
      else if ( a3 )
      {
        goto LABEL_14;
      }
      result = mmio_irq_clear(dword_12D714, dword_12D70C, 386);
    }
  }
  if ( a2 )
  {
LABEL_3:
    *a2 = *a3;
    goto LABEL_4;
  }
LABEL_14:
  *v4 = *a3;
LABEL_4:
  if ( (uint32_t *)v4[1] == a3 )
    v4[1] = a2;
  *a3 = 0;
  return result;
}

