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

extern uint32_t off_12D4E0;
extern uint32_t dword_12D4F0;
extern uint32_t dword_12D4E4;
extern uint32_t dword_12D4E8;
extern uint32_t dword_12D4EC;

// sub_12D460 @ 0x12d460, size 126 bytes
int  sub_12D460(int result, uint32_t *a2, uint32_t *a3)
{
  int16_t **v3; // r7
  uint32_t *v4; // r6

  v3 = (int16_t **)off_12D4E0;
  v4 = (uint32_t *)result;
  if ( **(int16_t **)off_12D4E0 < 0 )
  {
    if ( result || (result = sub_12F46C(dword_12D4F0, dword_12D4E4, 384), **v3 < 0) )
    {
      if ( a2 )
      {
        if ( (uint32_t *)*a2 != a3 )
        {
          result = sub_12F46C(dword_12D4E8, dword_12D4E4, 385);
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
      result = sub_12F46C(dword_12D4EC, dword_12D4E4, 386);
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

