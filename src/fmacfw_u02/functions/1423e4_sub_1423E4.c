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

extern uint32_t off_1424AC;
extern uint32_t dword_1424B0;
extern uint32_t dword_1424B4;

// llcp_rx_process @ 0x1423e4, size 198 bytes
int  llcp_rx_process(int a1, uint8_t *a2, int16_t a3, int16_t a4)
{
  int v6; // r7
  int v8; // r11
  int v9; // r4
  int v10; // r0
  char v11; // r2
  uint8_t *v12; // r0
  int v14; // r4
  int v15; // r10
  int v16; // r1
  uint8_t v17; // [sp+4h] [bp-8h]
  int v18; // [sp+4h] [bp-8h]

  if ( !*(uint8_t *)off_1424AC )
    goto LABEL_7;
  v6 = *a2;
  if ( *a2 )
    goto LABEL_7;
  v8 = a2[3];
  if ( !a2[1] )
  {
    v9 = dword_1424B0;
    v17 = a2[2];
    v10 = scan_slot_find_free(*(uint8_t *)(dword_1424B0 + 1320 * v8 + 116), v8, v17);
    if ( v10 )
    {
      conn_context_clear(v10);
      v11 = v17;
LABEL_6:
      LOBYTE(v6) = conn_context_reset(a2[3], *(uint8_t *)(v9 + 1320 * v8 + 116), v11) == 0;
      goto LABEL_8;
    }
LABEL_7:
    LOBYTE(v6) = 1;
    goto LABEL_8;
  }
  v14 = dword_1424B4;
  v15 = dword_1424B4 + 576;
  v16 = dword_1424B0 + 1320 * v8;
  do
  {
    if ( (*(uint16_t *)v14 & 1) != 0
      && *(uint8_t *)(v14 + 46) == *(uint8_t *)(v16 + 116)
      && *(uint8_t *)(v14 + 47) == a2[3] )
    {
      v18 = v16;
      v6 = 1;
      conn_context_clear(v14);
      v16 = v18;
    }
    v14 += 72;
  }
  while ( v14 != v15 );
  if ( v6 )
  {
    v9 = dword_1424B0;
    v11 = 0x80;
    goto LABEL_6;
  }
LABEL_8:
  v12 = (uint8_t *)ke_msg_alloc(12292, a4, a3, 1u);
  *v12 = v6;
  ke_msg_send((int)v12);
  return 0;
}

