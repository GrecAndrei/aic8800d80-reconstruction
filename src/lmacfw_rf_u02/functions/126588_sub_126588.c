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


extern uint32_t off_12672C;
extern uint32_t off_126730;
extern uint32_t off_126734;
extern uint32_t off_126738;
extern uint32_t off_12673C;
extern uint32_t off_126740;
extern uint32_t off_126744;
extern uint32_t off_126750;
extern uint32_t off_126754;
extern uint32_t off_126758;
extern uint32_t off_126760;

// sub_126588 @ 0x126588, size 418 bytes
int sub_126588()
{
  int v0; // r3
  uint8_t *v1; // r5
  uint8_t *v2; // r6
  char *v3; // r4
  int v4; // r7
  char *v5; // r3
  int v6; // r7
  int v7; // r10
  float v8; // r3
  unsigned int v9; // r9
  uint64_t v10; // r0
  uint64_t v11; // r0
  unsigned int v12; // r2
  uint64_t v13; // r8
  uint64_t v14; // r0
  uint64_t v15; // r2
  uint64_t v16; // r0
  uint64_t v17; // r8
  char *v18; // r4
  char v19; // r0
  int v20; // r2
  int v21; // r3
  volatile unsigned int *v22; // r1
  uint32_t *v23; // r2
  volatile unsigned int v24; // r3
  uint8_t *v25; // r4
  int v26; // r6
  uint64_t v27; // r0
  unsigned int v28; // r2
  uint64_t v29; // r6
  uint64_t v30; // r0
  uint64_t v31; // r0
  unsigned int v32; // r0
  uint64_t v33; // r0
  uint64_t v34; // r0
  uint64_t v36; // r8
  uint64_t v37; // r0
  uint64_t v38; // r0
  uint32_t *v39; // r3

  v0 = *(uint8_t *)off_12672C;
  v1 = off_126734;
  *(uint16_t *)off_126730 = 0;
  if ( v0 )
  {
    if ( *v1 == 2 )
    {
      v25 = off_12673C;
      v26 = *(uint16_t *)off_12673C;
      if ( *(uint16_t *)off_12673C )
      {
        v27 = sub_12754C(*(uint32_t *)off_126758);
        v28 = v27;
        LODWORD(v27) = v26;
        v29 = __PAIR64__(HIDWORD(v27), v28);
        v30 = sub_12754C(v27);
        v31 = sub_127874(v29, v30);
        v32 = sub_127BE4(v31);
        v33 = sub_127570(v32);
      }
      else
      {
        v33 = 0;
      }
      v34 = sub_127194(v33);
      v25[5] = sub_127B54(v34);
      *v1 = 3;
      sub_11F504("cob state -> %d\n", 3);
      return sub_11E5E0(0x2000);
    }
    else
    {
      return sub_12632C();
    }
  }
  else if ( *v1 )
  {
    v2 = (uint8_t *)off_126738;
    v3 = (char *)off_12673C;
    v4 = *(uint8_t *)off_126738 - 1;
    v5 = (char *)off_12673C + 8 * v4;
    v6 = 8 * v4;
    v7 = (uint8_t)v5[2];
    if ( v5[2] )
    {
      v36 = sub_12754C(*(uint32_t *)off_126758);
      v37 = sub_12754C(v7);
      v38 = sub_127874(v36, v37);
      v9 = sub_127BE4(v38);
      v8 = *(float *)off_126740 / (float)v7;
      *(float *)off_126740 = v8;
    }
    else
    {
      v8 = *(float *)off_126740;
      v9 = 0;
    }
    v10 = sub_127570(LODWORD(v8));
    v11 = sub_127194(v10);
    v12 = v11;
    LODWORD(v11) = v9;
    v13 = __PAIR64__(HIDWORD(v11), v12);
    v14 = sub_127570(v11);
    v15 = sub_127194(v14);
    v16 = v13;
    v17 = v15;
    v18 = &v3[v6];
    v18[4] = sub_127B54(v16);
    v19 = sub_127B54(v17);
    v20 = (uint8_t)*v2;
    v21 = *(uint8_t *)off_126744;
    v18[3] = v19;
    if ( v20 == v21 )
    {
      *v1 = 4;
      sub_11F504("cob state -> %d\n", 4);
    }
    else
    {
      *v1 = 2;
      sub_11F504("cob state -> %d\n", 2);
      v22 = (volatile unsigned int *)off_126750;
      v23 = off_126754;
      ++*v2;
      v24 = REG_4032_0120;
      *v22 = v24;
      *v23 = v24 + 1000000;
    }
    return sub_11E5E0(0x2000);
  }
  else
  {
    sub_11F504(aCobGoldenStart);
    *v1 = 1;
    sub_11F504("cob state -> %d\n", 1);
    v39 = off_126760;
    *(uint32_t *)off_126760 |= 0x100u;
    *v39 |= 0x200u;
    *v39 |= 0x400u;
    return sub_11E5E0(0x2000);
  }
}
