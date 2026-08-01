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

extern uint32_t dword_1314C0;

// parse_adv_report @ 0x131408, size 182 bytes
int  parse_adv_report(int a1, uint8_t *a2, int16_t a3, int16_t a4)
{
  int v5; // r5
  int v6; // r8
  char v9; // r2
  int v10; // r3
  int v11; // r1
  int v12; // r3
  char v13; // r2
  int v14; // r0
  int v15; // r5
  char v16; // r3

  v5 = *a2;
  v6 = dword_1314C0;
  if ( !a2[2] )
  {
    v12 = dword_1314C0 + 696 * v5;
    if ( a2[1] )
      v13 = *(uint8_t *)(v12 + 53) | 1;
    else
      v13 = *(uint8_t *)(v12 + 53) & 0xFE;
    *(uint8_t *)(v12 + 53) = v13;
    goto LABEL_9;
  }
  if ( a2[1] )
    v9 = *(uint8_t *)(dword_1314C0 + 696 * v5 + 53) | 4;
  else
    v9 = *(uint8_t *)(dword_1314C0 + 696 * v5 + 53) & 0xFB;
  v10 = dword_1314C0 + 696 * v5;
  v11 = *(uint8_t *)(v10 + 310);
  *(uint8_t *)(v10 + 53) = v9;
  if ( v11 == 15 )
  {
LABEL_9:
    v14 = tx_send_pdu(65, 0, 5, 4u);
    v15 = v6 + 696 * v5;
    v16 = *(uint8_t *)(v15 + 34);
    *(uint16_t *)v14 = *(uint16_t *)(v15 + 32);
    *(uint8_t *)(v14 + 3) = v16;
    *(uint8_t *)(v14 + 2) = a2[1];
    rx_process_packet(v14);
  }
  mac_write_header_word(5133, a4, a3);
  return 0;
}

