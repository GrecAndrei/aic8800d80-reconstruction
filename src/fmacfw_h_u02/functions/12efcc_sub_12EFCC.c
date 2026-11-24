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

// send_mcu_cmd_0x40e @ 0x12efcc, size 116 bytes
int  send_mcu_cmd_0x40e(int a1, int *a2, int a3, int a4)
{
  int v5; // r0
  int v6; // r3
  uint32_t *v7; // r4
  int v9; // r5
  int v10; // r0

  v5 = tx_send_pdu(1038, a4, a3, 4);
  v6 = a2[1];
  v7 = (uint32_t *)v5;
  switch ( v6 )
  {
    case 1:
      alloc_tx_event("\x9D\x81Auto boot to 0x%08x\r\n", *(uint32_t *)(*a2 + 4));
      break;
    case 2:
      alloc_tx_event("\x9D\x81Custom boot to 0x%08x\r\n", *a2);
      break;
    case 3:
      v9 = *a2;
      v10 = alloc_tx_event("delay %d\r\n", v9);
      if ( !v9 )
        event_sync(v10);
      ke_event_handler(1068, 1, v9 << 10);
      break;
    default:
      alloc_tx_event(aInvalidBootTyp);
      break;
  }
  *v7 = (uint8_t)call_patch_1fc_0(15);
  alloc_tx_event(asc_14ADBC);
  rx_process_packet_1((int)v7);
  return 0;
}
