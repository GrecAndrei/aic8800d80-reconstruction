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

extern uint32_t dword_138B44;
extern uint32_t dword_138B40;

// phy_config_set @ 0x138aa8, size 152 bytes
// Doc: phy_config_set [rf]: RF message handler: set flag, bump counter, invoke callback
// phy_config_set [rf]: RF message handler: set flag, bump counter, invoke callback
int  phy_config_set(uint8_t *a1, uint32_t *a2, char *a3, int a4)
{
  char v5; // r2
  int v6; // r4
  char *v7; // r3
  int v10; // r7
  int v12; // r9
  int v13; // r7

  v5 = a3[1];
  v6 = a4;
  if ( a4 )
    v6 = 2;
  if ( (v5 & 0x40) != 0 )
    v6 = (uint8_t)(v6 + 8);
  v7 = &a3[v6];
  if ( a3[v6 + 30] != 8 )
    return 0;
  if ( v7[31] != 6 )
    return 0;
  v10 = (uint8_t)v7[38];
  if ( v7[38] )
    return 0;
  v12 = (uint8_t)v7[39];
  if ( v12 == 1 )
  {
    v13 = ((uint8_t)v7[58] << 16)
        | ((uint8_t)v7[59] << 24)
        | (uint8_t)v7[56]
        | ((uint8_t)v7[57] << 8);
    check_status_bits(128, dword_138B44, v13, *a2);
    if ( v13 == *a2 )
      bt_get_acl_by_ble(*a1, (int)&a3[v6 + 40], a3);
    return 1;
  }
  else if ( v12 == 2 )
  {
    check_status_bits(128, dword_138B40);
  }
  return v10;
}

