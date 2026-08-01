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

extern uint32_t off_12B488;
extern uint32_t off_12B48C;
extern uint32_t dword_12B490;
extern uint32_t off_12B498;
extern uint32_t dword_12B494;

// bt_get_link_state @ 0x12b3c8, size 192 bytes
int bt_get_link_state()
{
  uint32_t *v0; // r6
  int v1; // r7
  int v2; // r5
  int v3; // r4
  char v4; // r8
  int v5; // r1
  int v6; // r3
  int v7; // r2
  int v8; // r1
  int v10; // r1

  v0 = off_12B488;
  v1 = *(uint32_t *)off_12B488;
  v2 = *(uint32_t *)off_12B488 + 6 * *((uint8_t *)off_12B488 + 10);
  v3 = 6 * *((uint8_t *)off_12B488 + 10);
  v4 = *(uint8_t *)(v2 + 3);
  if ( (v4 & 5) != 0 )
  {
    v5 = *(uint32_t *)(*(uint32_t *)off_12B48C + 20);
    if ( !v5 )
    {
      v5 = dword_12B490;
      goto LABEL_4;
    }
  }
  else
  {
    v5 = bt_check_vendor_cmd((uint16_t *)(*(uint32_t *)off_12B488 + 6 * *((uint8_t *)off_12B488 + 10)));
    if ( !v5 )
    {
      v5 = 30000;
      goto LABEL_4;
    }
  }
  if ( (v4 & 1) == 0 && *((uint8_t *)off_12B498 + 3850) == 1 )
    v5 += 170000;
LABEL_4:
  acl_send_packet((int16_t *)v2, v5, *(uint8_t *)(v1 + 366));
  v6 = v0[1];
  if ( v6 )
  {
    v7 = *(uint8_t *)(v2 + 2);
    v8 = *(uint16_t *)(v1 + v3);
    if ( *(uint8_t *)(v2 + 2) )
    {
      if ( v7 == 1 && (v10 = v8 - 4992, (uint16_t)(v10 - 13) <= 0x370u) )
        *(uint8_t *)(v6 + 2) = (unsigned int)(((unsigned int)dword_12B494 * (unsigned uint64_t)(unsigned int)(v10 - 8)) >> 32) >> 2;
      else
        *(uint8_t *)(v6 + 2) = 0;
    }
    else
    {
      if ( (unsigned int)(v8 - 2412) <= 0x48 )
      {
        if ( v8 == 2484 )
        {
          *(uint8_t *)(v6 + 2) = 14;
          return hci_cmd_send(2);
        }
        LOBYTE(v7) = (unsigned int)(((unsigned int)dword_12B494 * (unsigned uint64_t)(unsigned int)(v8 - 2407)) >> 32) >> 2;
      }
      *(uint8_t *)(v6 + 2) = v7;
    }
  }
  return hci_cmd_send(2);
}

