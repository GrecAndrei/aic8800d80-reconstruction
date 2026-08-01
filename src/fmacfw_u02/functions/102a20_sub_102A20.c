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

extern uint32_t dword_102AC8;
extern uint32_t dword_102ACC;
extern uint32_t off_102AB8;
extern uint32_t off_102AC0;
extern uint32_t off_102ABC;
extern uint32_t dword_102AD0;

// rf_enable @ 0x102a20, size 152 bytes
int  rf_enable(uint16_t *a1, int a2)
{
  uint8_t *v3; // r0
  int v4; // r1
  int v5; // r1
  int v6; // r2
  int v7; // r2
  int v8; // r0
  int v9; // r1

  if ( a2 )
  {
    v7 = a2;
    v8 = dword_102AC8;
    v9 = dword_102ACC;
  }
  else
  {
    if ( *(uint8_t *)off_102AB8 )
      goto LABEL_4;
    v3 = (uint8_t *)off_102AC0;
    v4 = *((uint16_t *)off_102AC0 + 18);
    *(uint32_t *)off_102ABC &= ~0x200u;
    if ( v4 != *a1 )
      goto LABEL_4;
    v5 = a1[1];
    if ( v3[45] != *((uint8_t *)a1 + 9) )
    {
      v6 = a1[2];
      goto LABEL_5;
    }
    v6 = a1[2];
    if ( *((uint16_t *)v3 + 19) != v5
      || *((uint16_t *)v3 + 20) != v6
      || *((uint16_t *)v3 + 21) != a1[3] )
    {
LABEL_5:
      tx_packet_handler(*(uint8_t *)a1, v5, v6, *((uint8_t *)a1 + 1));
    }
    if ( rx_rate_field_parse(7) == 1 || rx_rate_field_parse(6) == 3 )
    {
LABEL_4:
      v5 = a1[1];
      v6 = a1[2];
      goto LABEL_5;
    }
    v9 = dword_102ACC;
    v8 = dword_102AD0;
  }
  return event_dispatch(v8, v9, v7);
}

