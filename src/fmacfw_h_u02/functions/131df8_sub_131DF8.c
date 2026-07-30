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

extern uint32_t off_131F40;
extern uint32_t dword_131F44;
extern uint32_t dword_131F48;

// sub_131DF8 @ 0x131df8, size 328 bytes
int  sub_131DF8(int a1, int a2, int16_t a3, int16_t a4)
{
  uint8_t *v4; // r4
  int v8; // r1
  int v9; // r2
  int v10; // r3
  int v11; // r1
  int v12; // r2
  int v13; // r3
  uint32_t *v14; // r3
  int v15; // r1
  int v16; // r2
  int v17; // r3
  int16_t v18; // r1
  int v19; // r2
  char v20; // r2
  uint32_t *v22; // r6
  int v23; // r1
  int v24; // r2
  int v25; // r3
  int v26; // r1
  int v27; // r2
  int v28; // r3
  int v29; // r1
  int v30; // r2
  int v31; // r3
  int v32; // r1
  uint8_t *v33; // r0
  int v34; // r0
  int v35; // r3
  unsigned int v36; // r2
  int v37; // cc
  int v38; // r3

  v4 = off_131F40;
  *((uint8_t *)off_131F40 + 374) = 0;
  if ( *(uint8_t *)(a2 + 103) )
  {
    v4[374] = 1;
    v8 = *(uint32_t *)(a2 + 4);
    v9 = *(uint32_t *)(a2 + 8);
    v10 = *(uint32_t *)(a2 + 12);
    *((uint32_t *)v4 + 3) = *(uint32_t *)a2;
    *((uint32_t *)v4 + 4) = v8;
    *((uint32_t *)v4 + 5) = v9;
    *((uint32_t *)v4 + 6) = v10;
    v11 = *(uint32_t *)(a2 + 20);
    v12 = *(uint32_t *)(a2 + 24);
    v13 = *(uint32_t *)(a2 + 28);
    *((uint32_t *)v4 + 7) = *(uint32_t *)(a2 + 16);
    *((uint32_t *)v4 + 8) = v11;
    *((uint32_t *)v4 + 9) = v12;
    *((uint32_t *)v4 + 10) = v13;
  }
  if ( *(uint8_t *)(a2 + 104) )
  {
    v14 = (uint32_t *)dword_131F44;
    v4[374] |= 2u;
    v15 = *(uint32_t *)(a2 + 36);
    v16 = *(uint32_t *)(a2 + 40);
    *v14 = *(uint32_t *)(a2 + 32);
    v14[1] = v15;
    v14[2] = v16;
  }
  if ( sub_114A44() )
  {
    *(uint8_t *)(a2 + 105) = 0;
    *(uint8_t *)(a2 + 106) = 0;
  }
  else
  {
    if ( *(uint8_t *)(a2 + 105) )
    {
      v22 = (uint32_t *)dword_131F48;
      v4[374] |= 4u;
      v23 = *(uint32_t *)(a2 + 48);
      v24 = *(uint32_t *)(a2 + 52);
      v25 = *(uint32_t *)(a2 + 56);
      *v22 = *(uint32_t *)(a2 + 44);
      v22[1] = v23;
      v22[2] = v24;
      v22[3] = v25;
      v22 += 4;
      v26 = *(uint32_t *)(a2 + 64);
      v27 = *(uint32_t *)(a2 + 68);
      v28 = *(uint32_t *)(a2 + 72);
      *v22 = *(uint32_t *)(a2 + 60);
      v22[1] = v26;
      v22[2] = v27;
      v22[3] = v28;
      v22 += 4;
      v29 = *(uint32_t *)(a2 + 80);
      v30 = *(uint32_t *)(a2 + 84);
      v31 = *(uint32_t *)(a2 + 88);
      *v22 = *(uint32_t *)(a2 + 76);
      v22[1] = v29;
      v22[2] = v30;
      v22[3] = v31;
      v22 += 4;
      v32 = *(uint32_t *)(a2 + 96);
      *v22 = *(uint32_t *)(a2 + 92);
      v22[1] = v32;
    }
    if ( *(uint8_t *)(a2 + 106) )
      v4[374] |= 8u;
  }
  v4[373] = *(uint8_t *)(a2 + 102);
  sub_12C8D0(5121, a4, a3);
  if ( (v4[374] & 1) != 0 )
  {
    v34 = sub_101A18();
    v35 = (uint8_t)v4[374] << 29;
    v4[372] = (v34 + 1) >> 1;
    if ( v35 < 0 )
    {
      v36 = (uint8_t)v4[373];
      v37 = v36 > 2;
      if ( v36 > 2 )
        v36 = (uint8_t)v4[73];
      v38 = (uint8_t)v4[68] >> 2;
      if ( v37 )
        v38 &= v36 >> 6;
      v4[116] = v38 & 1;
    }
  }
  else
  {
    v4[372] = 0;
  }
  v17 = *(uint8_t *)(a2 + 107);
  v18 = *(uint16_t *)(a2 + 100);
  v4[375] = v17;
  v19 = *(uint8_t *)(a2 + 109);
  *((uint16_t *)v4 + 22) = v18;
  if ( v19 )
    v20 = 2;
  else
    v20 = 1;
  v4[376] = v20;
  if ( v17 )
  {
    *((uint16_t *)v4 + 4) = 255;
    v33 = (uint8_t *)sub_12C7EC(49, 0, 5, 1u);
    *v33 = v4[376];
    sub_12C84C((int)v33);
    sub_12CBF4(5u, 1);
  }
  return 0;
}

