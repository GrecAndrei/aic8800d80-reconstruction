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

extern uint32_t off_13745C;
extern uint32_t off_13748C;
extern uint32_t off_137460;
extern uint32_t off_137464;
extern uint32_t dword_13746C;
extern uint32_t dword_137468;
extern uint32_t off_137474;
extern uint32_t off_137478;
extern uint32_t off_137470;
extern uint32_t off_137480;
extern uint32_t off_137488;
extern uint32_t off_137484;
extern uint32_t off_13747C;

// util_hex_convert @ 0x137388, size 212 bytes
uint32_t * util_hex_convert(int a1)
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

  if ( *(uint8_t *)off_13745C )
    rf_reg_write_byte(*((uint8_t *)off_13748C + 9));
  v2 = off_137460;
  v3 = (uint8_t **)off_137464;
  if ( *((uint8_t *)off_137460 + 3850) == 1 )
    v4 = 4099;
  else
    v4 = 4097;
  v5 = (uint8_t *)tx_send_pdu(v4, *((uint16_t *)off_137460 + 1924), 4, 3u);
  check_feature_flag(
    8,
    dword_13746C,
    dword_137468,
    *(uint8_t *)(*(uint32_t *)v2 + 366),
    *((uint8_t *)v2 + 3850),
    a1);
  v6 = (int *)off_137474;
  v7 = (uint16_t *)off_137478;
  *(uint32_t *)off_137470 &= ~4u;
  v8 = *v7;
  v9 = *(uint32_t *)v2;
  *v6 = (HIWORD(*v6) << 16) | v8;
  *v5 = *(uint8_t *)(v9 + 366);
  v5[1] = a1;
  v5[2] = v2[2];
  if ( **v3 == 1 && *((uint8_t *)off_137480 + 189) )
  {
    v11 = off_137488;
    *(uint32_t *)off_137484 &= 0xFC0FFFFF;
    *v11 |= 0x400000u;
    *v11 |= 0x200000u;
  }
  tx_process_jump(v9 - 12);
  *(uint32_t *)v2 = 0;
  rx_process_packet((int)v5);
  *((uint32_t *)off_13747C + 1) &= ~0x20u;
  return hci_cmd_preprocess(4u, 0);
}

