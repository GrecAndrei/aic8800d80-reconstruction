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


extern uint32_t dword_111DB4;
extern uint32_t off_111D84;
extern uint32_t off_111D88;
extern uint32_t off_111D8C;
extern uint32_t off_111D90;
extern uint32_t off_111D98;
extern uint32_t off_111D9C;
extern uint32_t off_111DA0;
extern uint32_t off_111DA8;
extern uint32_t off_111DAC;
extern uint32_t off_111DB0;

// wlan_set_band @ 0x111c78, size 262 bytes
int  wlan_set_band(int a1, int a2)
{
  uint8_t *v4; // r6
  int *v5; // r7
  char *v6; // r0
  int v7; // r1
  uint32_t *v8; // r4
  uint32_t *v9; // r3
  uint8_t *v11; // r7
  int v12; // r0
  int v13; // r1
  uint32_t *v14; // r3
  void ( *v15)(int); // r2

  alloc_tx_event("open:%d/%d\n", 0, a2);
  if ( !a1 )
    return 1;
  if ( !*(uint32_t *)a1 || !*(uint32_t *)(a1 + 4) || !*(uint32_t *)(a1 + 8) || !*(uint32_t *)(a1 + 20) )
    return 2;
  v4 = off_111D84;
  if ( *(uint8_t *)off_111D84 )
    return 3;
  v5 = (int *)off_111D88;
  v6 = (char *)off_111D8C;
  *(uint8_t *)off_111D84 = 1;
  memcpy_1(v6, (char *)a1, 0x50u);
  v7 = v5[97];
  if ( v7 )
  {
    alloc_tx_event("usb sftdiscon delay %d\n", v7);
    mmio_read32(v5[97]);
  }
  v8 = off_111D90;
  if ( (*((uint32_t *)off_111D90 + 512) & 0x7F0) != 0 )
  {
    v11 = off_111DA8;
    *((uint32_t *)off_111DA8 + 1) = 0;
    *((uint32_t *)v11 + 2) = 0;
    *v11 = 0;
    *v4 = 4;
    v12 = update_packet_buffer();
    v13 = *(uint32_t *)off_111DAC;
    v14 = *(uint32_t **)off_111DB0;
    *v14 = dword_111DB4;
    v14[1] = v13;
    v8[709] = v14;
    v8[706] = v8[706];
    v15 = *((void ( **)(int))off_111D8C + 19);
    v8[704] |= 0x84000000;
    *v11 = 1;
    if ( v15 )
      v15(v12);
  }
  else
  {
    if ( (*((uint32_t *)off_111D90 + 2) & 1) != 0 )
    {
      *((uint32_t *)off_111D90 + 2) &= ~1u;
      v8[513] |= 2u;
    }
    mmio_set_bit_2();
  }
  alloc_tx_event(aEnableIrq);
  v9 = off_111DA0;
  *(uint32_t *)(*((uint32_t *)off_111D98 + 2) + 320) = off_111D9C;
  v9[2] = 1;
  if ( a2 == 1 )
  {
    while ( *v4 != 4 )
      ;
  }
  alloc_tx_event(aOpenDone);
  return 0;
}
