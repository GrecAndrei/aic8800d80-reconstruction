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

extern uint32_t off_11E5B8;
extern uint32_t off_11E5BC;
extern uint32_t dword_11E5C0;
extern uint32_t dword_11E5C4;
extern uint32_t dword_11E5D4;
extern uint32_t off_11E5C8;
extern uint32_t dword_11E5DC;
extern uint32_t dword_11E5D8;
extern uint32_t dword_11E5D0;
extern uint32_t off_11E5CC;

// sub_11E4D8 @ 0x11e4d8, size 222 bytes
int sub_11E4D8()
{
  int *v0; // r5
  int v1; // r0
  int result; // r0
  uint16_t *v3; // r4
  int v4; // r3
  int v5; // r2
  int ( *v6)(uint32_t, uint16_t *, uint32_t, uint32_t); // r6
  int v7; // r2
  int v8; // r3
  int v9; // r3
  int v10; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_11E5B8 = 1;
  }
  v0 = (int *)off_11E5BC;
  v1 = dword_11E5C0;
  ++*(uint32_t *)off_11E5BC;
  result = sub_11E7AC(v1);
  v3 = (uint16_t *)result;
  if ( *v0 )
  {
    v4 = *v0 - 1;
    v5 = *(uint32_t *)off_11E5B8;
    *v0 = v4;
    if ( !v4 )
    {
      if ( v5 )
        __enable_irq();
    }
  }
  if ( result )
  {
    v6 = (int ( *)(uint32_t, uint16_t *, uint32_t, uint32_t))sub_11E3FC(
                                                                           *(uint16_t *)(result + 4),
                                                                           *(uint16_t *)(result + 6));
    msg_parse(dword_11E5C4, v3[2]);
    if ( v6 )
    {
      result = v6(v3[2], v3 + 6, v3[3], v3[4]);
      if ( result == 1 )
        goto LABEL_12;
      if ( result == 2 )
      {
        result = list_push_tail(dword_11E5D4);
        goto LABEL_12;
      }
      if ( result )
      {
        if ( **(int16_t **)off_11E5C8 < 0 )
          result = rf_cmd_send_n264(dword_11E5DC, dword_11E5D8, 360);
        goto LABEL_12;
      }
    }
    else
    {
      msg_parse(dword_11E5D0, v3[2]);
    }
    result = sub_11DEE8((int)v3);
  }
LABEL_12:
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_11E5B8 = 1;
  }
  v7 = *((uint32_t *)off_11E5CC + 1);
  v8 = *v0 + 1;
  *v0 = v8;
  if ( !v7 )
  {
    result = sub_11E628(0x4000000);
    v8 = *v0;
  }
  if ( v8 )
  {
    v9 = v8 - 1;
    v10 = *(uint32_t *)off_11E5B8;
    *v0 = v9;
    if ( !v9 )
    {
      if ( v10 )
        __enable_irq();
    }
  }
  return result;
}

