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


extern uint32_t off_119ACC;

// sub_1199CC @ 0x1199cc, size 254 bytes
int  sub_1199CC(int a1, int *a2, uint16_t a3, uint16_t a4)
{
  int v5; // r6
  int v6; // r0
  int v7; // r4
  int v8; // r1
  int result; // r0
  int v10; // r1
  int v11; // r6
  int v12; // r3
  int v13; // r1
  int v14; // r5
  char v15; // r0
  int v16; // r1
  int v17; // r5
  int v18; // r1

  v5 = *a2;
  v6 = sub_11DDF0(136, a4, a3, 8);
  v7 = v6;
  *(uint32_t *)v6 = v5;
  switch ( v5 )
  {
    case 0:
      v8 = *((uint8_t *)a2 + 4);
      *(uint8_t *)(off_119ACC + 0x175) = v8;
      *(uint8_t *)(v6 + 4) = v8;
      sub_11F504("tim_bcmc_ign:%x\n", v8);
      goto LABEL_3;
    case 1:
      v11 = off_119ACC;
      v12 = *((uint8_t *)a2 + 4);
      v13 = *(uint8_t *)(off_119ACC + 0x16B);
      *(uint8_t *)(off_119ACC + 0x16B) = v12;
      *(uint32_t *)(v11 + 0x16C) = a2[2];
      if ( v12 != v13 )
      {
        if ( v12 )
        {
          sub_12704C();
          sub_127108();
        }
        else
        {
          sub_12716C();
        }
        v13 = *(uint8_t *)(v11 + 0x16B);
      }
      *(uint8_t *)(v7 + 4) = v13;
      sub_11F504("temp_comp_en:%x\n", v13);
      sub_11DE50(v7);
      result = 0;
      break;
    case 2:
      v14 = off_119ACC;
      *(uint8_t *)(v6 + 4) = *(uint8_t *)(off_119ACC + 0x16B);
      v15 = sub_126E54();
      *(uint8_t *)(v7 + 5) = v15;
      sub_11F504("temp_comp_en:%x,t=%d\n", *(uint8_t *)(v14 + 0x16B), v15);
      sub_11DE50(v7);
      result = 0;
      break;
    case 3:
      v16 = a2[1];
      v17 = off_119ACC;
      *(uint32_t *)(off_119ACC + 0x188) = v16;
      sub_11F504("set ext_flags:0x%x\n", v16);
      *(uint32_t *)(v7 + 4) = *(uint32_t *)(v17 + 0x188);
      sub_11DE50(v7);
      result = 0;
      break;
    case 4:
      v18 = *(uint32_t *)(off_119ACC + 0x188);
      *(uint32_t *)(v6 + 4) = v18;
      sub_11F504("get ext_flags:0x%x\n", v18);
      sub_11DE50(v7);
      result = 0;
      break;
    case 5:
      v10 = (a2[2] ^ *(uint32_t *)(off_119ACC + 0x188)) & a2[1] ^ *(uint32_t *)(off_119ACC + 0x188);
      *(uint32_t *)(off_119ACC + 0x188) = v10;
      *(uint32_t *)(v6 + 4) = v10;
      sub_11F504("mask set ext_flags:0x%x\n", v10);
      sub_11DE50(v7);
      result = 0;
      break;
    default:
LABEL_3:
      sub_11DE50(v7);
      result = 0;
      break;
  }
  return result;
}
