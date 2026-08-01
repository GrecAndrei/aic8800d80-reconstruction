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

extern uint32_t off_132814;
extern uint32_t dword_132818;
extern uint32_t dword_13281C;

// bt_process_msg @ 0x132794, size 128 bytes
// Doc: bt_process_msg [util]: critical task entry; saves context and checks first byte of arg
// bt_process_msg [util]: critical task entry; saves context and checks first byte of arg
int  bt_process_msg(uint8_t *a1, int a2)
{
  int v2; // r11
  int16_t **v3; // r8
  int v4; // r10
  int v5; // r9
  uint8_t *v8; // r4
  int v9; // r7
  int v10; // r0

  v2 = *a1;
  if ( *a1 )
  {
    v3 = (int16_t **)off_132814;
    v4 = dword_132818;
    v5 = dword_13281C;
    v8 = a1;
    v9 = 0;
    while ( 1 )
    {
      if ( a2 && (v8[1] & 0x80u) == 0 )
        goto LABEL_6;
      is_valid_rate_code();
      if ( **v3 < 0 )
        break;
      if ( v10 <= 11 )
        goto LABEL_11;
LABEL_6:
      if ( ++v8 - a1 >= v2 )
        return v9;
    }
    if ( v10 > 11 )
    {
      call_shared_handler(v5, v4, 598);
      v2 = *a1;
      goto LABEL_6;
    }
LABEL_11:
    v9 = (uint16_t)(v9 | (1 << v10));
    goto LABEL_6;
  }
  return *a1;
}

