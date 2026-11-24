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


extern uint32_t dword_1117FC;
extern uint32_t off_1117CC;
extern uint32_t off_1117D0;
extern uint32_t off_1117D4;
extern uint32_t off_1117D8;
extern uint32_t off_1117E0;
extern uint32_t off_1117E4;
extern uint32_t off_1117E8;
extern uint32_t off_1117F0;
extern uint32_t off_1117F4;
extern uint32_t off_1117F8;

// ke_send_event @ 0x1116c0, size 262 bytes
int  ke_send_event(int a1, int a2)
{
  uint8_t *v4; // r6
  int v5; // r7
  char *v6; // r0
  int v7; // r1
  uint32_t *v8; // r4
  uint32_t *v9; // r3
  uint8_t *v11; // r7
  int v12; // r0
  int v13; // r1
  uint32_t *v14; // r3
  void ( *v15)(int); // r2

  dispatch_event_handler_1("open:%d/%d\n", 0, a2);
  if ( !a1 )
    return 1;
  if ( !*(uint32_t *)a1 || !*(uint32_t *)(a1 + 4) || !*(uint32_t *)(a1 + 8) || !*(uint32_t *)(a1 + 20) )
    return 2;
  v4 = off_1117CC;
  if ( *(uint8_t *)off_1117CC )
    return 3;
  v5 = off_1117D0;
  v6 = (char *)off_1117D4;
  *(uint8_t *)off_1117CC = 1;
  memcpy_large(v6, (char *)a1, 0x50u);
  v7 = *(uint32_t *)(v5 + 0x184);
  if ( v7 )
  {
    dispatch_event_handler_1("usb sftdiscon delay %d\n", v7);
    write_timer_reg(*(uint32_t *)(v5 + 0x184));
  }
  v8 = off_1117D8;
  if ( (*((uint32_t *)off_1117D8 + 512) & 0x7F0) != 0 )
  {
    v11 = off_1117F0;
    *((uint32_t *)off_1117F0 + 1) = 0;
    *((uint32_t *)v11 + 2) = 0;
    *v11 = 0;
    *v4 = 4;
    v12 = timer_set_alarm();
    v13 = *(uint32_t *)off_1117F4;
    v14 = *(uint32_t **)off_1117F8;
    *v14 = dword_1117FC;
    v14[1] = v13;
    v8[709] = v14;
    v8[706] = v8[706];
    v15 = *(void ( **)(int))&((uint32_t *)(uintptr_t)off_1117D4)[76];
    v8[704] |= 0x84000000;
    *v11 = 1;
    if ( v15 )
      v15(v12);
  }
  else
  {
    if ( (*((uint32_t *)off_1117D8 + 2) & 1) != 0 )
    {
      *((uint32_t *)off_1117D8 + 2) &= ~1u;
      v8[513] |= 2u;
    }
    timer_start();
  }
  dispatch_event_handler_1(aEnableIrq);
  v9 = off_1117E8;
  *(uint32_t *)(*((uint32_t *)off_1117E0 + 2) + 320) = off_1117E4;
  v9[2] = 1;
  if ( a2 == 1 )
  {
    while ( *v4 != 4 )
      ;
  }
  dispatch_event_handler_1(aOpenDone);
  return 0;
}
