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

extern uint32_t off_114810;
extern uint32_t dword_114818;
extern uint32_t dword_114834;
extern uint32_t dword_11481C;
extern uint32_t dword_114820;
extern uint32_t dword_114828;
extern uint32_t dword_114830;

// load_multiple_globals @ 0x114748, size 190 bytes
// Doc: rf_fault_dump_n9e [rf]: Dump RF fault state with bounded size cap of 0x100 entries
// rf_fault_dump_n9e [rf]: Dump RF fault state with bounded size cap of 0x100 entries
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
  int eb18; // r0
  unsigned int v13; // r4
  unsigned int v14; // r5
  int v15; // r1

  v0 = rf_fault_dump_nc0;
  v1 = *(uint32_t *)(*(uint32_t *)rf_fault_dump_nc0 + 16);
  event_dispatch(rf_fault_dump_ncc, v1, *(uint32_t *)off_114810);
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
      goto rf_fault_dump_n4c;
  }
  else if ( !v5 )
  {
    goto rf_fault_dump_n4c;
  }
  v13 = v5 & 0xFFFFFFF0;
  v14 = (rf_fault_dump_nf0 - v13) >> 2;
  event_dispatch(rf_fault_handler_nf4, v6, v7);
  v15 = v14;
  if ( v14 >= 0x100 )
    v15 = 256;
  send_msg(v13, v15, 4, 0);
rf_fault_dump_n4c:
  event_dispatch(dword_11481C, v6, v7);
  send_msg(dword_114820, 8, 4, 0);
  event_dispatch(rf_fault_dump_ndc, v8, v9);
  send_msg(dword_114828, 8, 4, 0);
  event_dispatch(rf_fault_dump_ne4, v10, v11);
  eb18 = send_msg(dword_114830, 16, 4, 0);
  patch_init(eb18);
}

