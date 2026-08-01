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

extern uint32_t off_13759C;
extern uint32_t off_1375CC;
extern uint32_t off_1375A0;
extern uint32_t off_1375A4;
extern uint32_t dword_1375AC;
extern uint32_t dword_1375A8;
extern uint32_t off_1375B4;
extern uint32_t off_1375B8;
extern uint32_t off_1375B0;
extern uint32_t off_1375C0;
extern uint32_t off_1375C8;
extern uint32_t off_1375C4;
extern uint32_t off_1375BC;

// hci_cmd_process @ 0x1374c8, size 212 bytes
uint32_t * hci_cmd_process(int a1)
{
  uint16_t *v2; // r4
  uint8_t **v3; // r7
  int16_t v4; // r0
  uint8_t *v5; // r5
  int *v6; // r2
  uint16_t *v7; // r0
  int v8; // r1
  int v9; // r0
  uint32_t *v11; // r3

  if ( *(uint8_t *)off_13759C )
    write_phy_config(*((uint8_t *)off_1375CC + 9));
  v2 = off_1375A0;
  v3 = (uint8_t **)off_1375A4;
  if ( *((uint8_t *)off_1375A0 + 3850) == 1 )
    v4 = 4099;
  else
    v4 = 4097;
  v5 = (uint8_t *)ke_msg_alloc(v4, *((uint16_t *)off_1375A0 + 1924), 4, 3u);
  check_status_bits(
    8,
    dword_1375AC,
    dword_1375A8,
    *(uint8_t *)(*(uint32_t *)v2 + 366),
    *((uint8_t *)v2 + 3850),
    a1);
  v6 = (int *)off_1375B4;
  v7 = (uint16_t *)off_1375B8;
  *(uint32_t *)off_1375B0 &= ~4u;
  v8 = *v7;
  v9 = *(uint32_t *)v2;
  *v6 = (HIWORD(*v6) << 16) | v8;
  *v5 = *(uint8_t *)(v9 + 366);
  v5[1] = a1;
  v5[2] = v2[2];
  if ( **v3 == 1 && *((uint8_t *)off_1375C0 + 189) )
  {
    v11 = off_1375C8;
    *(uint32_t *)off_1375C4 &= 0xFC0FFFFF;
    *v11 |= 0x400000u;
    *v11 |= 0x200000u;
  }
  branch_to_12cbc8(v9 - 12);
  *(uint32_t *)v2 = 0;
  ke_msg_send((int)v5);
  *((uint32_t *)off_1375BC + 1) &= ~0x20u;
  return rx_phy_status_parse(4u, 0);
}

