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

extern uint32_t off_114808;
extern uint32_t dword_114814;
extern uint32_t off_114810;
extern uint32_t dword_114818;
extern uint32_t dword_114834;
extern uint32_t dword_114838;
extern uint32_t dword_11483C;
extern uint32_t dword_11481C;
extern uint32_t dword_114820;
extern uint32_t dword_114824;
extern uint32_t dword_114828;
extern uint32_t dword_11482C;

// load_multiple_globals @ 0x114748, size 190 bytes
void __noreturn load_multiple_globals()
{
  void *v0; // r5
  int v1; // r4
  unsigned int CPSR; // r1
  unsigned int v3; // r2
  unsigned int v4; // r5
  unsigned int v5; // r4
  int v6; // r1
  int v7; // r2
  int v8; // r1
  int v9; // r2
  int v10; // r1
  int v11; // r2
  int v12; // r0
  unsigned int v13; // r4
  unsigned int v14; // r5
  int v15; // r1

  v0 = off_114808;
  v1 = *(uint32_t *)(*(uint32_t *)off_114808 + 16);
  event_dispatch(dword_114814, v1, *(uint32_t *)off_114810);
  if ( (v1 & 1) != 0 )
    *(uint32_t *)(*(uint32_t *)v0 + 12) = 1;
  CPSR = __get_CPSR();
  v3 = __get_CPSR();
  v4 = __get_CPSR();
  v5 = __get_CPSR();
  __get_CPSR();
  event_dispatch(dword_114818, CPSR, v3);
  if ( v4 )
  {
    event_dispatch(dword_114834, v6, v7);
    if ( !v5 )
      goto LABEL_5;
  }
  else if ( !v5 )
  {
    goto LABEL_5;
  }
  v13 = v5 & 0xFFFFFFF0;
  v14 = (dword_114838 - v13) >> 2;
  event_dispatch(dword_11483C, v6, v7);
  v15 = v14;
  if ( v14 >= 0x100 )
    v15 = 256;
  send_msg(v13, v15, 4, 0);
LABEL_5:
  event_dispatch(dword_11481C, v6, v7);
  send_msg(dword_114820, 8, 4, 0);
  event_dispatch(dword_114824, v8, v9);
  send_msg(dword_114828, 8, 4, 0);
  event_dispatch(dword_11482C, v10, v11);
  v12 = send_msg(rf_fault_clear_ne8, 16, 4, 0);
  patch_init(v12);
}

