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

extern uint32_t off_1146C8;
extern uint32_t dword_1146D4;
extern uint32_t off_1146D0;
extern uint32_t dword_1146D8;
extern uint32_t dword_1146F4;
extern uint32_t dword_1146F8;
extern uint32_t dword_1146FC;
extern uint32_t dword_1146DC;
extern uint32_t dword_1146E0;
extern uint32_t dword_1146E4;
extern uint32_t dword_1146E8;
extern uint32_t dword_1146EC;
extern uint32_t dword_1146F0;

// timeout_handler @ 0x114608, size 190 bytes
void __noreturn timeout_handler()
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

  v0 = off_1146C8;
  v1 = *(uint32_t *)(*(uint32_t *)off_1146C8 + 16);
  alloc_tx_event(dword_1146D4, v1, *(uint32_t *)off_1146D0);
  if ( (v1 & 1) != 0 )
    *(uint32_t *)(*(uint32_t *)v0 + 12) = 1;
  CPSR = __get_CPSR();
  v3 = __get_CPSR();
  v4 = __get_CPSR();
  v5 = __get_CPSR();
  __get_CPSR();
  alloc_tx_event(dword_1146D8, CPSR, v3);
  if ( v4 )
  {
    alloc_tx_event(dword_1146F4, v6, v7);
    if ( !v5 )
      goto LABEL_5;
  }
  else if ( !v5 )
  {
    goto LABEL_5;
  }
  v13 = v5 & 0xFFFFFFF0;
  v14 = (dword_1146F8 - v13) >> 2;
  alloc_tx_event(dword_1146FC, v6, v7);
  v15 = v14;
  if ( v14 >= 0x100 )
    v15 = 256;
  process_packet_params(v13, v15, 4, 0);
LABEL_5:
  alloc_tx_event(dword_1146DC, v6, v7);
  process_packet_params(dword_1146E0, 8, 4, 0);
  alloc_tx_event(dword_1146E4, v8, v9);
  process_packet_params(dword_1146E8, 8, 4, 0);
  alloc_tx_event(dword_1146EC, v10, v11);
  v12 = process_packet_params(dword_1146F0, 16, 4, 0);
  log_boot_message(v12);
}

