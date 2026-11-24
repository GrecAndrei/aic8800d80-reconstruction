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


extern uint32_t dword_121898;
extern uint32_t off_121890;
extern uint32_t off_12189C;
extern uint32_t off_1218A0;
extern uint32_t off_1218AC;
extern uint32_t off_1218B0;
extern uint32_t off_1218B4;
extern uint32_t off_1218B8;
extern uint32_t off_1218BC;
extern uint32_t off_1218C4;
extern uint32_t off_1218C8;
extern uint32_t off_1218D0;

// rx_handle_frame @ 0x121678, size 534 bytes
int  rx_handle_frame(char *a1, int a2, int a3, int a4)
{
  unsigned int v4; // r7
  int v5; // r5
  int v7; // r6
  uint32_t *v8; // r2
  uint16_t *v9; // r7
  uint32_t *v10; // r3
  uint8_t *v11; // r3
  uint32_t *v12; // r3
  int v13; // r0
  int v14; // r1
  uint32_t *v15; // r3
  uint32_t *v16; // r2
  char v18; // r6
  uint32_t *v19; // r2
  uint32_t *v20; // r3
  uint32_t *v21; // r3
  uint32_t *v22; // r3
  uint32_t *v23; // r3
  uint32_t *v24; // r3
  int v25; // r5

  v4 = (uint8_t)a1[1];
  v5 = (uint8_t)a1[41];
  if ( v4 == 255 )
  {
    if ( a1[40] == 5 )
    {
      v25 = HIBYTE(*(uint32_t *)off_1218C8) - 3 + (uint8_t)*a1 + 2 * v5;
      v7 = (uint8_t)v25;
      wlc_phy_chanspec_set((uint8_t *)a1, v25);
      return v7;
    }
    v18 = *a1;
    v19 = off_1218A0;
    *(uint32_t *)off_12189C = -1;
    *v19 = -1;
    v7 = (uint8_t)(v18 + 4 * v5);
    state_check_feature(256, "add gtk:%d,%d\r\n", (uint8_t)a1[41], (uint8_t)a1[40]);
    wlc_phy_chanspec_set((uint8_t *)a1, v7);
  }
  else
  {
    if ( **(uint16_t **)off_121890 < 0 && v4 > 0x23 )
      mmio_irq_clear((int)aStaIdxStaMax, (int)aMmSecMachwkeyW, 1424);
    v7 = (uint8_t)(v4 + 16);
    state_check_feature(256, "add ptk:%d,%d\r\n", v4, (uint8_t)a1[40]);
    wlc_phy_radio_set((int)a1, v4 + 16);
    v8 = off_1218A0;
    v9 = (uint16_t *)(dword_121898 + 696 * v4);
    *(uint32_t *)off_12189C = v9[19] | (v9[20] << 16);
    *v8 = v9[21];
  }
  switch ( a1[40] )
  {
    case 0:
      v20 = off_1218AC;
      *(uint32_t *)off_1218AC = *((uint32_t *)a1 + 2);
      v20[1] = *((uint32_t *)a1 + 3);
      v20[2] = *((uint32_t *)a1 + 4);
      v20[3] = *((uint32_t *)a1 + 5);
      v13 = 256;
      v14 = 0;
      break;
    case 1:
      v10 = off_1218AC;
      *(uint32_t *)off_1218AC = *((uint32_t *)a1 + 2);
      v10[1] = *((uint32_t *)a1 + 3);
      v10[2] = *((uint32_t *)a1 + 4);
      v11 = *(uint8_t **)off_1218B0;
      *(uint32_t *)off_1218B4 = *((uint32_t *)a1 + 5);
      if ( (*v11 & 1) != 0 )
      {
        v12 = off_1218B8;
        *(uint32_t *)off_1218B8 = *((uint32_t *)a1 + 6);
        v12[1] = *((uint32_t *)a1 + 7);
        v12[2] = *((uint32_t *)a1 + 8);
        v12[3] = *((uint32_t *)a1 + 9);
      }
      else
      {
        *(uint32_t *)off_1218C4 &= ~1u;
      }
      v13 = 512;
      v14 = 4096;
      break;
    case 2:
      v15 = off_1218AC;
      *(uint32_t *)off_1218AC = *((uint32_t *)a1 + 2);
      v15[1] = *((uint32_t *)a1 + 3);
      v15[2] = *((uint32_t *)a1 + 4);
      v15[3] = *((uint32_t *)a1 + 5);
      v13 = 768;
      v14 = 0;
      break;
    case 3:
      v13 = 256;
      v14 = 4096;
      goto LABEL_22;
    case 4:
      v24 = off_1218AC;
      *(uint32_t *)off_1218AC = *((uint32_t *)a1 + 2);
      v24[1] = *((uint32_t *)a1 + 3);
      v24[2] = *((uint32_t *)a1 + 4);
      v24[3] = *((uint32_t *)a1 + 5);
      v13 = 1024;
      v14 = 4096;
      goto LABEL_20;
    case 6:
      v13 = 1280;
      v14 = 0;
      goto LABEL_22;
    case 7:
      v13 = 1280;
      goto LABEL_19;
    case 8:
      v13 = 768;
LABEL_19:
      v21 = off_1218AC;
      *(uint32_t *)off_1218AC = *((uint32_t *)a1 + 2);
      v21[1] = *((uint32_t *)a1 + 3);
      v21[2] = *((uint32_t *)a1 + 4);
      v21[3] = *((uint32_t *)a1 + 5);
      v14 = 0x2000;
LABEL_20:
      v22 = off_1218B8;
      *(uint32_t *)off_1218B8 = *((uint32_t *)a1 + 6);
      v22[1] = *((uint32_t *)a1 + 7);
      v22[2] = *((uint32_t *)a1 + 8);
      v22[3] = *((uint32_t *)a1 + 9);
      break;
    default:
      if ( **(uint16_t **)off_121890 < 0 )
        mmio_irq_clear(off_1218D0, (int)aMmKeyRamParamG, 159);
      v13 = 0;
      v14 = 4096;
LABEL_22:
      v23 = off_1218AC;
      *(uint32_t *)off_1218AC = *((uint32_t *)a1 + 2);
      v23[1] = *((uint32_t *)a1 + 3);
      v23[2] = *((uint32_t *)a1 + 4);
      v23[3] = *((uint32_t *)a1 + 5);
      break;
  }
  v16 = off_1218BC;
  *(uint32_t *)off_1218BC = (16 * v5) | (4 * (uint8_t)a1[42]) | v13 | (v7 << 16) | v14 | 0x40000000;
  while ( (*v16 & 0x40000000) != 0 )
    ;
  return v7;
}
