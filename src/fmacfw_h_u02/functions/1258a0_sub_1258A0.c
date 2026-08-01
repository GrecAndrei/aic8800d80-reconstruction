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

extern uint32_t off_125900;

// ipc_trace_send @ 0x1258a0, size 94 bytes
int  ipc_trace_send(int a1)
{
  int *v1; // r5
  int v2; // r6
  int v4; // r2
  int v5; // r3
  int v6; // r6
  int v7; // r2

  v1 = (int *)off_125900;
  v2 = *(uint32_t *)off_125900;
  mac_write_header_word(64, *(uint16_t *)(*(uint32_t *)off_125900 - 4), 0);
  tx_pkt_complete(a1, *v1);
  v4 = *v1;
  *(uint8_t *)(a1 + 231) = 0;
  v5 = *(uint8_t *)(v4 + 10);
  *(uint8_t *)(a1 + 232) = v5;
  *(uint8_t *)(a1 + 233) = *(uint8_t *)(v4 + 11);
  v6 = v2 - 12;
  if ( v5 )
    *(uint8_t *)(a1 + 231) = *(uint8_t *)(*(uint32_t *)(*(uint32_t *)(a1 + 192) + 28) + v5) + 1;
  v7 = *((uint8_t *)v1 + 8);
  *((uint8_t *)v1 + 9) = 0;
  if ( v7 )
    patch_check_enable();
  *v1 = 0;
  return tx_process_jump(v6);
}

