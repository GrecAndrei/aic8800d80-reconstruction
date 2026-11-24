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


extern uint32_t dword_114820;
extern uint32_t dword_114828;
extern uint32_t dword_114838;
extern uint32_t off_114808;
extern uint32_t off_11480C;
extern uint32_t off_114810;

// load_multiple_globals @ 0x114748, size 190 bytes
void  load_multiple_globals()
{
  unsigned int v0; // r5
  int v1; // r4
  int v2; // lr
  unsigned int CPSR; // r1
  unsigned int v4; // r2
  unsigned int v5; // r5
  unsigned int v6; // r4
  unsigned int v7; // r4
  unsigned int v8; // r5
  int v9; // r1

  v0 = off_114808;
  v1 = *(uint32_t *)(*(uint32_t *)off_114808 + 16);
  event_dispatch("\nINT:%x,%x,%x", v1, *(uint32_t *)off_114810, *(uint32_t *)off_11480C);
  if ( (v1 & 1) != 0 )
    *(uint32_t *)(*(uint32_t *)v0 + 12) = 1;
  CPSR = __get_CPSR();
  v4 = __get_CPSR();
  v5 = __get_CPSR();
  v6 = __get_CPSR();
  event_dispatch(aControl08xXpsr_0, CPSR, v4, v5, v6, __get_CPSR(), v2);
  if ( v5 )
  {
    event_dispatch(aWrongPsp);
    if ( !v6 )
      goto LABEL_5;
  }
  else if ( !v6 )
  {
    goto LABEL_5;
  }
  v7 = v6 & 0xFFFFFFF0;
  v8 = (dword_114838 - v7) >> 2;
  event_dispatch(aDumpmsp_0);
  v9 = v8;
  if ( v8 >= 0x100 )
    v9 = 256;
  send_msg(v7, v9, 4, 0);
LABEL_5:
  event_dispatch(aIser);
  send_msg(dword_114820, 8, 4, 0);
  event_dispatch(aIspr);
  send_msg(dword_114828, 8, 4, 0);
  event_dispatch(aTim2);
  send_msg((int)REG_4050_1000, 16, 4, 0);
  patch_init();
}
