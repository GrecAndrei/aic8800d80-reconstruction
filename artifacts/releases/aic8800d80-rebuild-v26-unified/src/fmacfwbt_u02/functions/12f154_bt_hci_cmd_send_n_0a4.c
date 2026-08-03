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

extern uint32_t dword_12F19C;

// bt_hci_cmd_send_n_0a4 @ 0x12f154, size 72 bytes
// Doc: bt_hci_cmd_send_n_0a4 [bt]: Build and send HCI-like command (0x401) to lower layer
// bt_hci_cmd_send_n_0a4 [bt]: Build and send HCI-like command (0x401) to lower layer
int  bt_hci_cmd_send_n_0a4(int a1, int *a2, int16_t a3, int16_t a4)
{
  int v5; // r0
  uint32_t *v6; // r1
  uint32_t *v7; // r4
  int v9; // r0

  v5 = rf_bus_setup_n3a8(1025, a4, a3, 8u);
  v6 = (uint32_t *)*a2;
  v7 = (uint32_t *)v5;
  if ( (((unsigned int)*a2 >> 20) & 0xFFFFFDFF) == 0x500 )
  {
    v9 = sub_10EBDC(*a2, 1);
    v6 = (uint32_t *)*a2;
    v7[1] = v9;
  }
  else
  {
    *(uint32_t *)(v5 + 4) = *v6;
  }
  *v7 = v6;
  sub_12ECB0(dword_12F19C);
  sub_12CBB4((int)v7);
  return 0;
}

