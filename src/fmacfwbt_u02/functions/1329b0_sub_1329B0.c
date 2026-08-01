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

extern uint32_t off_132A30;
extern uint32_t dword_132A34;
extern uint32_t dword_132A38;

// llm_decrypt_adv_payload @ 0x1329b0, size 128 bytes
int  llm_decrypt_adv_payload(uint8_t *a1, int a2)
{
  int v2; // r11
  int16_t **v3; // r8
  int v4; // r10
  int v5; // r9
  uint8_t *v8; // r4
  int v9; // r7
  char v10; // r0
  int v11; // r0

  v2 = *a1;
  if ( *a1 )
  {
    v3 = (int16_t **)off_132A30;
    v4 = dword_132A34;
    v5 = dword_132A38;
    v8 = a1;
    v9 = 0;
    while ( 1 )
    {
      if ( a2 )
      {
        v10 = v8[1];
        if ( v10 >= 0 )
          goto LABEL_7;
      }
      else
      {
        v10 = v8[1];
      }
      v11 = util_validate_name_char(v10);
      if ( **v3 < 0 )
        break;
      if ( v11 <= 11 )
        goto LABEL_12;
LABEL_7:
      if ( ++v8 - a1 >= v2 )
        return v9;
    }
    if ( v11 > 11 )
    {
      mmio_field_update(v5, v4, 598);
      v2 = *a1;
      goto LABEL_7;
    }
LABEL_12:
    v9 = (uint16_t)(v9 | (1 << v11));
    goto LABEL_7;
  }
  return *a1;
}

