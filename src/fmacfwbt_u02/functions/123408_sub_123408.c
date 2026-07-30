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

extern uint32_t off_123508;
extern uint32_t dword_12350C;
extern uint32_t dword_123514;
extern uint32_t dword_123518;
extern uint32_t dword_12351C;
extern uint32_t dword_123520;
extern uint32_t dword_123510;

// sub_123408 @ 0x123408, size 254 bytes
// Doc: sub_1223408 [util]: Allocates 0x88-byte context, fills it from arguments and calls sub-function
// sub_1223408 [util]: Allocates 0x88-byte context, fills it from arguments and calls sub-function
int  sub_123408(int a1, int *a2, int a3, int a4)
{
  int v5; // r6
  int v6; // r0
  int v7; // r2
  int v8; // r4
  int v9; // r1
  int v10; // r0
  int result; // r0
  int v12; // r2
  int v13; // r0
  int v14; // r1
  uint32_t *v15; // r6
  int v16; // r3
  int v17; // r1
  int v18; // r2
  int v19; // r0
  uint8_t *v20; // r5
  char n590; // r0
  int v22; // r1
  uint32_t *v23; // r5
  int v24; // r0
  int v25; // r0
  int v26; // r1

  v5 = *a2;
  v6 = rf_bus_setup_n3a8(136, a4, a3, 8);
  v8 = v6;
  *(uint32_t *)v6 = v5;
  switch ( v5 )
  {
    case 0:
      v9 = *((uint8_t *)a2 + 4);
      *((uint8_t *)off_123508 + 373) = v9;
      v10 = dword_12350C;
      *(uint8_t *)(v8 + 4) = v9;
      sub_12ECB0(v10, v9, v7);
      goto LABEL_3;
    case 1:
      v15 = off_123508;
      v16 = *((uint8_t *)a2 + 4);
      v17 = *((uint8_t *)off_123508 + 363);
      *((uint8_t *)off_123508 + 363) = v16;
      v18 = a2[2];
      v15[91] = v18;
      if ( v16 != v17 )
      {
        if ( v16 )
        {
          v19 = sub_130714(v6);
          sub_1307D0(v19);
        }
        else
        {
          bt_fmac_init_n_42e();
        }
        v17 = *((uint8_t *)v15 + 363);
      }
      *(uint8_t *)(v8 + 4) = v17;
      sub_12ECB0(dword_123514, v17, v18);
      sub_12CBB4(v8);
      result = 0;
      break;
    case 2:
      v20 = (uint8_t *)off_123508;
      *(uint8_t *)(v6 + 4) = *((uint8_t *)off_123508 + 363);
      n590 = rf_temp_read_n590();
      *(uint8_t *)(v8 + 5) = n590;
      sub_12ECB0(dword_123518, v20[363], n590);
      sub_12CBB4(v8);
      result = 0;
      break;
    case 3:
      v22 = a2[1];
      v23 = off_123508;
      v24 = dword_12351C;
      *((uint32_t *)off_123508 + 98) = v22;
      sub_12ECB0(v24, v22, v7);
      *(uint32_t *)(v8 + 4) = v23[98];
      sub_12CBB4(v8);
      result = 0;
      break;
    case 4:
      v25 = dword_123520;
      v26 = *((uint32_t *)off_123508 + 98);
      *(uint32_t *)(v8 + 4) = v26;
      sub_12ECB0(v25, v26, v7);
      sub_12CBB4(v8);
      result = 0;
      break;
    case 5:
      v12 = *((uint32_t *)off_123508 + 98);
      v13 = dword_123510;
      v14 = (a2[2] ^ v12) & a2[1] ^ v12;
      *((uint32_t *)off_123508 + 98) = v14;
      *(uint32_t *)(v8 + 4) = v14;
      sub_12ECB0(v13, v14, v12);
      sub_12CBB4(v8);
      result = 0;
      break;
    default:
LABEL_3:
      sub_12CBB4(v8);
      result = 0;
      break;
  }
  return result;
}

