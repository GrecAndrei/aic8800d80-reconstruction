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


extern uint32_t dword_1146E0;
extern uint32_t dword_1146E8;
extern uint32_t dword_1146F8;
extern uint32_t off_1146C8;
extern uint32_t off_1146CC;
extern uint32_t off_1146D0;

// timeout_handler @ 0x114608, size 190 bytes
void  timeout_handler()
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

  v0 = off_1146C8;
  v1 = *(uint32_t *)(*(uint32_t *)off_1146C8 + 16);
  alloc_tx_event("\nINT:%x,%x,%x", v1, *(uint32_t *)off_1146D0, *(uint32_t *)off_1146CC);
  if ( (v1 & 1) != 0 )
    *(uint32_t *)(*(uint32_t *)v0 + 12) = 1;
  CPSR = __get_CPSR();
  v4 = __get_CPSR();
  v5 = __get_CPSR();
  v6 = __get_CPSR();
  alloc_tx_event(aControl08xXpsr_0, CPSR, v4, v5, v6, __get_CPSR(), v2);
  if ( v5 )
  {
    alloc_tx_event(aWrongPsp);
    if ( !v6 )
      goto LABEL_5;
  }
  else if ( !v6 )
  {
    goto LABEL_5;
  }
  v7 = v6 & 0xFFFFFFF0;
  v8 = (dword_1146F8 - v7) >> 2;
  alloc_tx_event(aDumpmsp_0);
  v9 = v8;
  if ( v8 >= 0x100 )
    v9 = 256;
  process_packet_params(v7, v9, 4, 0);
LABEL_5:
  alloc_tx_event(aIser);
  process_packet_params(dword_1146E0, 8, 4, 0);
  alloc_tx_event(aIspr);
  process_packet_params(dword_1146E8, 8, 4, 0);
  alloc_tx_event(aTim2);
  process_packet_params((int)&REG_4050_1000, 16, 4, 0);
  log_boot_message();
}
