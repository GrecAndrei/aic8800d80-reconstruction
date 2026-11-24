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


extern uint32_t dword_125B7C;
extern uint32_t dword_125B88;
extern uint32_t dword_125B8C;
extern uint32_t dword_125B94;
extern uint32_t dword_125BA0;
extern uint32_t dword_125BA4;
extern uint32_t dword_125BAC;
extern uint32_t dword_125BB0;
extern uint32_t dword_125BC0;
extern uint32_t dword_125BC4;
extern uint32_t dword_125BC8;
extern uint32_t dword_125BCC;
extern uint32_t dword_125BD0;
extern uint32_t off_125B78;
extern uint32_t off_125B80;
extern uint32_t off_125B84;
extern uint32_t off_125B90;
extern uint32_t off_125B98;
extern uint32_t off_125B9C;
extern uint32_t off_125BB8;
extern uint32_t off_125BBC;

// bt_state_machine_dispatch @ 0x125ad8, size 158 bytes
unsigned int  bt_state_machine_dispatch(unsigned int result)
{
  unsigned int v1; // r4
  int v2; // r3
  int v3; // r1
  int *v4; // r3
  int v5; // r2
  int *v6; // r3
  int v7; // r2
  int *v8; // r3
  int v9; // r2
  uint32_t *v10; // r3
  int v11; // r2
  uint64_t v12; // [sp+0h] [bp-8h] BYREF

  if ( result )
  {
    v1 = result;
    if ( result <= 2 )
    {
      mac_time_get(&v12, 0);
      v2 = off_125B78;
      v3 = BYTE1(v12);
      *(uint32_t *)off_125B78 = dword_125B7C;
      if ( v1 == 1 )
      {
        if ( v3 )
        {
          v10 = off_125BBC;
          *(uint32_t *)off_125BB8 = 2047;
          *v10 = 341;
        }
        else
        {
          v11 = dword_125BD0;
          *(uint32_t *)off_125B80 = dword_125BCC;
          *(uint32_t *)(v2 + 0xFFFFFF74) = v11;
        }
        *(uint32_t *)off_125B90 = dword_125BC0;
      }
      else
      {
        if ( v3 )
        {
          v4 = (int *)off_125BBC;
          v5 = dword_125BC8;
          *(uint32_t *)off_125BB8 = dword_125BC4;
        }
        else
        {
          v4 = (int *)off_125B84;
          v5 = dword_125B8C;
          *(uint32_t *)off_125B80 = dword_125B88;
        }
        *v4 = v5;
        *(uint32_t *)off_125B90 = dword_125B94;
      }
      v6 = (int *)off_125B9C;
      v7 = dword_125BA0;
      *(uint32_t *)off_125B98 = dword_125BA4;
      *v6 = v7;
      return dispatch_event_handler_1(aSetPapr);
    }
  }
  else
  {
    v8 = (int *)off_125B9C;
    v9 = dword_125BAC;
    *(uint32_t *)off_125B78 = dword_125BB0;
    *v8 = v9;
    return dispatch_event_handler_1(aUnsetPapr);
  }
  return result;
}
