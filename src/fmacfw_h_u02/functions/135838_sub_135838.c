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

extern uint32_t off_1358B0;
extern uint32_t dword_1358BC;
extern uint32_t dword_1358B8;
extern uint32_t dword_1358B4;

// ke_msg_alloc @ 0x135838, size 120 bytes
int  ke_msg_alloc(char a1, int a2, unsigned int a3)
{
  unsigned int v3; // r4
  int v6; // r0
  int16_t **v7; // r3
  int16_t *v8; // r3
  int v9; // r5
  int v10; // r3
  unsigned int v11; // r4

  v3 = a3;
  v6 = tx_send_pdu(6152, 13, 6, (uint16_t)(a3 + 4));
  v7 = (int16_t **)off_1358B0;
  *(uint8_t *)v6 = a1;
  v8 = *v7;
  *(uint16_t *)(v6 + 2) = v3;
  v9 = v6;
  if ( *v8 < 0 )
  {
    if ( v3 >= get_buffer_size() - 4 )
      irq_disable_mmio_write(dword_1358BC, dword_1358B8, 1444);
    v3 = *(uint16_t *)(v9 + 2);
  }
  if ( v3 )
  {
    v10 = v9 + 3;
    v11 = v3 + v9 + 3;
    do
    {
      *(uint8_t *)(v10 + 1) = *(uint8_t *)(a2 - 3 - v9 + v10);
      ++v10;
    }
    while ( v10 != v11 );
  }
  hci_cmd_preprocess(6u, 7);
  ke_event_handler(6154, 6, dword_1358B4);
  return rx_process_packet(v9);
}

