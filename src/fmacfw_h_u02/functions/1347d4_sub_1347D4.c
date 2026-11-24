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


extern uint32_t off_134910;
extern uint32_t off_134918;
extern uint32_t off_13491C;
extern uint32_t off_134920;
extern uint32_t off_134924;
extern uint32_t off_134928;

// ble_load_defaults @ 0x1347d4, size 314 bytes
int ble_load_defaults()
{
  uint16_t *v0; // r6
  int v1; // r4
  int v2; // r5
  uint16_t v3; // r7
  int *v4; // r3
  int v5; // r1
  unsigned int v6; // r2
  int result; // r0
  uint32_t *v8; // r1
  int *v9; // r2
  uint32_t *v10; // r12
  int *v11; // r0

  v0 = off_134910;
  v1 = *((uint32_t *)off_134910 + 2);
  check_feature_flag(256, aSmDisconnectFi);
  v2 = tx_send_pdu(6149, 13, 6, 6);
  if ( *((uint8_t *)v0 + 4) )
    v3 = 0;
  else
    v3 = v0[6];
  *(uint8_t *)(v1 + 149) = 0;
  mem_set_util((uint32_t *)(v1 + 152));
  v4 = *((int **)off_134918 + 2);
  if ( !v4 )
  {
LABEL_14:
    bt_set_address(0);
    goto LABEL_15;
  }
  v5 = 0;
  while ( 1 )
  {
    while ( 1 )
    {
      if ( !*((uint8_t *)v4 + 106) )
      {
        if ( !*((uint8_t *)v4 + 108) )
          goto LABEL_8;
        ++v5;
        if ( (int *)v1 == v4 )
          goto LABEL_8;
        break;
      }
      if ( (int *)v1 == v4 )
        goto LABEL_8;
      if ( *((uint8_t *)v4 + 108) )
        break;
      v4 = (int *)*v4;
      if ( !v4 )
      {
LABEL_13:
        if ( *(int *)off_13491C < 0 && v5 == 1 )
        {
          v8 = off_134924;
          *((uint8_t *)off_134920 + 2) = (uint8_t)v4;
          v9 = (int *)off_134928;
          *v8 |= 0x80000000;
          *v9 = (HIWORD(*v9) << 16) | 0x5DC;
        }
        goto LABEL_14;
      }
    }
    v6 = *((uint16_t *)v4 + 208);
    if ( v6 <= 0x1387 )
      break;
LABEL_8:
    v4 = (int *)*v4;
    if ( !v4 )
      goto LABEL_13;
  }
  if ( *(int *)off_13491C < 0 && v5 == 1 )
  {
    v10 = off_134924;
    *((uint8_t *)off_134920 + 2) = 0;
    v11 = (int *)off_134928;
    *v10 |= 0x80000000;
    *v11 = (HIWORD(*v11) << 16) | 0x5DC;
    bt_set_address(v6 | (*((uint8_t *)v4 + 413) << 16) | 0x80000000);
  }
  else
  {
    bt_set_address(v6 | (*((uint8_t *)v4 + 413) << 16) | 0x80000000);
  }
LABEL_15:
  check_non_null((int *)v1, 0, 0);
  result = hci_send_cmd_1419(v1);
  *(uint16_t *)v2 = v3;
  *(uint8_t *)(v2 + 2) = *(uint8_t *)(v1 + 107);
  *(uint8_t *)(v2 + 4) = *((uint8_t *)v0 + 33);
  *(uint32_t *)v0 = v2 - 12;
  return result;
}
