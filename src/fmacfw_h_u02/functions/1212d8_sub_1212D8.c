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


extern uint32_t dword_1214F8;
extern uint32_t off_1214F0;
extern uint32_t off_1214FC;
extern uint32_t off_121500;
extern uint32_t off_12150C;
extern uint32_t off_121510;
extern uint32_t off_121514;
extern uint32_t off_121518;
extern uint32_t off_12151C;
extern uint32_t off_121524;
extern uint32_t off_121528;
extern uint32_t off_121530;

// ll_parse_pdu @ 0x1212d8, size 534 bytes
int  ll_parse_pdu(char *a1, int a2, int a3, int a4)
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
      v25 = HIBYTE(*(uint32_t *)off_121528) - 3 + (uint8_t)*a1 + 2 * v5;
      v7 = (uint8_t)v25;
      get_bss_by_channel((uint8_t *)a1, v25);
      return v7;
    }
    v18 = *a1;
    v19 = off_121500;
    *(uint32_t *)off_1214FC = -1;
    *v19 = -1;
    v7 = (uint8_t)(v18 + 4 * v5);
    check_feature_flag(256, "add gtk:%d,%d\r\n", (uint8_t)a1[41], (uint8_t)a1[40]);
    get_bss_by_channel((uint8_t *)a1, v7);
  }
  else
  {
    if ( **(uint16_t **)off_1214F0 < 0 && v4 > 0x23 )
      irq_disable_mmio_write((int)aStaIdxStaMax, (int)aMmSecMachwkeyW, 1424);
    v7 = (uint8_t)(v4 + 16);
    check_feature_flag(256, "add ptk:%d,%d\r\n", v4, (uint8_t)a1[40]);
    set_connection_flag((int)a1, v4 + 16);
    v8 = off_121500;
    v9 = (uint16_t *)(dword_1214F8 + 696 * v4);
    *(uint32_t *)off_1214FC = v9[19] | (v9[20] << 16);
    *v8 = v9[21];
  }
  switch ( a1[40] )
  {
    case 0:
      v20 = off_12150C;
      *(uint32_t *)off_12150C = *((uint32_t *)a1 + 2);
      v20[1] = *((uint32_t *)a1 + 3);
      v20[2] = *((uint32_t *)a1 + 4);
      v20[3] = *((uint32_t *)a1 + 5);
      v13 = 256;
      v14 = 0;
      break;
    case 1:
      v10 = off_12150C;
      *(uint32_t *)off_12150C = *((uint32_t *)a1 + 2);
      v10[1] = *((uint32_t *)a1 + 3);
      v10[2] = *((uint32_t *)a1 + 4);
      v11 = *(uint8_t **)off_121510;
      *(uint32_t *)off_121514 = *((uint32_t *)a1 + 5);
      if ( (*v11 & 1) != 0 )
      {
        v12 = off_121518;
        *(uint32_t *)off_121518 = *((uint32_t *)a1 + 6);
        v12[1] = *((uint32_t *)a1 + 7);
        v12[2] = *((uint32_t *)a1 + 8);
        v12[3] = *((uint32_t *)a1 + 9);
      }
      else
      {
        *(uint32_t *)off_121524 &= ~1u;
      }
      v13 = 512;
      v14 = 4096;
      break;
    case 2:
      v15 = off_12150C;
      *(uint32_t *)off_12150C = *((uint32_t *)a1 + 2);
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
      v24 = off_12150C;
      *(uint32_t *)off_12150C = *((uint32_t *)a1 + 2);
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
      v21 = off_12150C;
      *(uint32_t *)off_12150C = *((uint32_t *)a1 + 2);
      v21[1] = *((uint32_t *)a1 + 3);
      v21[2] = *((uint32_t *)a1 + 4);
      v21[3] = *((uint32_t *)a1 + 5);
      v14 = 0x2000;
LABEL_20:
      v22 = off_121518;
      *(uint32_t *)off_121518 = *((uint32_t *)a1 + 6);
      v22[1] = *((uint32_t *)a1 + 7);
      v22[2] = *((uint32_t *)a1 + 8);
      v22[3] = *((uint32_t *)a1 + 9);
      break;
    default:
      if ( **(uint16_t **)off_1214F0 < 0 )
        irq_disable_mmio_write(off_121530, (int)aMmKeyRamParamG, 159);
      v13 = 0;
      v14 = 4096;
LABEL_22:
      v23 = off_12150C;
      *(uint32_t *)off_12150C = *((uint32_t *)a1 + 2);
      v23[1] = *((uint32_t *)a1 + 3);
      v23[2] = *((uint32_t *)a1 + 4);
      v23[3] = *((uint32_t *)a1 + 5);
      break;
  }
  v16 = off_12151C;
  *(uint32_t *)off_12151C = (16 * v5) | (4 * (uint8_t)a1[42]) | v13 | (v7 << 16) | v14 | 0x40000000;
  while ( (*v16 & 0x40000000) != 0 )
    ;
  return v7;
}
