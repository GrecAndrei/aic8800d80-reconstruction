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


extern uint32_t dword_104F9C;
extern float flt_104F94;

// sub_104CC8 @ 0x104cc8, size 710 bytes
unsigned int  sub_104CC8(int *a1, int a2, unsigned int a3, int a4, uint64_t *a5)
{
  int v6; // r0
  float v7; // r0
  unsigned int *v8; // r11
  uint64_t v9; // r2
  uint64_t v10; // d9
  uint64_t v11; // r0
  int v12; // r0
  uint64_t v13; // r2
  uint64_t v14; // d13
  int v15; // r6
  uint64_t v16; // r0
  int v17; // r0
  uint64_t v18; // r4
  uint64_t v19; // r2
  int v20; // r8
  uint64_t v21; // r0
  int v22; // r0
  uint64_t v23; // d8
  uint64_t v24; // r2
  uint64_t v25; // r0
  int v26; // r0
  uint64_t v27; // r2
  int v28; // r6
  uint64_t v29; // r0
  int v30; // r0
  int v31; // r7
  uint64_t v32; // r2
  int v33; // r6
  uint64_t v34; // r0
  int v35; // r0
  unsigned int *v36; // r10
  uint64_t v37; // d11
  uint64_t v38; // r6
  uint64_t v39; // r0
  uint64_t v40; // r8
  uint64_t v41; // r6
  uint64_t v42; // r0
  uint64_t v43; // d10
  uint64_t v44; // r6
  uint64_t v45; // r0
  uint64_t v46; // r6
  uint64_t v47; // r0
  uint64_t v48; // r6
  uint64_t v49; // r0
  uint64_t v50; // d12
  uint64_t v51; // r6
  uint64_t v52; // r0
  uint64_t v53; // r6
  uint64_t v54; // r0
  uint64_t v55; // r0
  uint64_t v56; // r8
  uint64_t v57; // r0
  uint64_t v58; // r6
  uint64_t v59; // r0
  uint64_t v60; // r6
  uint64_t v61; // r0
  uint64_t v62; // r0
  uint64_t v63; // r2
  uint64_t v64; // r0
  uint64_t v65; // r0
  unsigned int result; // r0
  unsigned int v67; // t1
  uint64_t v68; // r8
  uint64_t v69; // [sp+0h] [bp-1Ch]
  uint64_t v70; // [sp+8h] [bp-14h]
  uint64_t v71; // [sp+10h] [bp-Ch]

  v6 = sub_142E9C(*(uint64_t *)&a3);
  sub_12E948("temp_delta=%d\n", v6);
  v7 = COERCE_FLOAT(sub_10DE08());
  v8 = (unsigned int *)a1;
  sub_12E948("tmp*100=%d\n", (int)(float)(v7 * flt_104F94));
  HIDWORD(v9) = dword_104F9C;
  v10 = a5[2];
  LODWORD(v9) = 0;
  v11 = sub_142968(v10, v9);
  v12 = sub_142E9C(v11);
  HIDWORD(v13) = dword_104F9C;
  v14 = a5[1];
  v15 = v12;
  LODWORD(v13) = 0;
  v16 = sub_142968(v14, v13);
  v17 = sub_142E9C(v16);
  v18 = *a5;
  HIDWORD(v19) = dword_104F9C;
  LODWORD(v19) = 0;
  v20 = v17;
  v21 = sub_142968(*a5, v19);
  v22 = sub_142E9C(v21);
  v23 = a5[5];
  v71 = a5[4];
  v70 = a5[3];
  sub_12E948("x[0]*1000=%3d,x[1]*1000=%3d,x[2]*1000=%3d\n", v22, v20, v15);
  HIDWORD(v24) = dword_104F9C;
  LODWORD(v24) = 0;
  v25 = sub_142968(v23, v24);
  v26 = sub_142E9C(v25);
  HIDWORD(v27) = dword_104F9C;
  v28 = v26;
  LODWORD(v27) = 0;
  v29 = sub_142968(v71, v27);
  v30 = sub_142E9C(v29);
  v31 = v28;
  HIDWORD(v32) = dword_104F9C;
  LODWORD(v32) = 0;
  v33 = v30;
  v34 = sub_142968(v70, v32);
  v35 = sub_142E9C(v34);
  sub_12E948("y[0]*1000=%3d,y[1]*1000=%3d,y[2]*1000=%3d\n", v35, v33, v31);
  v36 = v8 + 32;
  do
  {
    v67 = *v8++;
    v68 = sub_1428B8(v67);
    if ( sub_142E74(v18, v68) )
    {
      v63 = v70;
    }
    else if ( sub_142E38(v14, v68) )
    {
      v63 = v71;
    }
    else if ( sub_142E60(v10, v68) )
    {
      v63 = v23;
    }
    else
    {
      v37 = sub_1425F8(v68, v14);
      v38 = sub_1425F8(v68, v10);
      v39 = sub_1425F8(v68, v18);
      v40 = v38;
      v41 = v39;
      v42 = sub_142968(v70, v37);
      v43 = v41;
      v44 = sub_142968(v42, v40);
      v45 = sub_1425F8(v18, v14);
      v46 = sub_142BBC(v44, v45);
      v47 = sub_1425F8(v18, v10);
      v48 = sub_142BBC(v46, v47);
      v49 = sub_142968(v71, v43);
      v50 = v48;
      v51 = sub_142968(v49, v40);
      v52 = sub_1425F8(v14, v18);
      v53 = sub_142BBC(v51, v52);
      v54 = sub_1425F8(v14, v10);
      v55 = sub_142BBC(v53, v54);
      v56 = sub_1425FC(v50, v55);
      v57 = sub_142968(v23, v43);
      v58 = sub_142968(v57, v37);
      v59 = sub_1425F8(v10, v18);
      v60 = sub_142BBC(v58, v59);
      v61 = sub_1425F8(v10, v14);
      v62 = sub_142BBC(v60, v61);
      v63 = sub_1425FC(v56, v62);
    }
    v69 = v63;
    v64 = sub_1428B8(v8[63]);
    v65 = sub_142968(v64, v69);
    result = sub_142F2C(v65);
    v8[31] = result;
  }
  while ( v8 != v36 );
  return result;
}
