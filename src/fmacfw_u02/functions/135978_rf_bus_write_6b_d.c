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

extern uint32_t off_1359F0;
extern uint32_t dword_1359FC;
extern uint32_t dword_1359F8;
extern uint32_t dword_1359F4;

// bt_send_ack_message @ 0x135978, size 120 bytes
// Doc: bt_send_ack_message [rf]: Write 6-byte value with tag 0xd to RF bus
// bt_send_ack_message [rf]: Write 6-byte value with tag 0xd to RF bus
int  bt_send_ack_message(char a1, int a2, unsigned int a3)
{
  unsigned int v3; // r4
  int v6; // r0
  int16_t **v7; // r3
  int16_t *v8; // r3
  int v9; // r5
  int v10; // r3
  unsigned int v11; // r4

  v3 = a3;
  v6 = ke_msg_alloc(6152, 13, 6, (uint16_t)(a3 + 4));
  v7 = (int16_t **)off_1359F0;
  *(uint8_t *)v6 = a1;
  v8 = *v7;
  *(uint16_t *)(v6 + 2) = v3;
  v9 = v6;
  if ( *v8 < 0 )
  {
    if ( v3 >= get_dma_ring_bytes() - 4 )
      mmio_clear_register(dword_1359FC, dword_1359F8, 1444);
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
  rx_phy_status_parse(6u, 7);
  ke_task_create(6154, 6, dword_1359F4);
  return ke_msg_send(v9);
}

