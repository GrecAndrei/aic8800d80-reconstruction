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

extern uint32_t dword_104A80;
extern uint32_t dword_104A88;
extern uint32_t dword_104A8C;
extern uint32_t dword_104A90;
extern uint32_t dword_104A94;

// heap_calloc @ 0x1047b8, size 710 bytes
// Doc: heap_calloc [rf]: RF PHY processing routine with VFP context save and dispatch
// heap_calloc [rf]: RF PHY processing routine with VFP context save and dispatch
int  heap_calloc(int *a1, int a2, int a3, int a4, uint64_t *a5)
{
  int v6; // r0
  int v8; // r0
  float v9; // r0
  int *v10; // r11
  uint64_t v11; // d9
  uint64_t v12; // r0
  uint64_t v13; // d13
  uint64_t v14; // r0
  uint64_t v15; // r4
  uint64_t v16; // r0
  int v17; // r0
  uint64_t v18; // d8
  uint64_t v19; // r0
  uint64_t v20; // r0
  uint64_t v21; // r0
  int v22; // r0
  int *v23; // r10
  uint64_t v24; // d11
  uint64_t v25; // r6
  uint64_t v26; // r0
  uint64_t v27; // r8
  uint64_t v28; // r6
  uint64_t v29; // r0
  uint64_t v30; // d10
  uint64_t v31; // r6
  uint64_t v32; // r0
  uint64_t v33; // r6
  uint64_t v34; // r0
  uint64_t v35; // r6
  uint64_t v36; // r0
  uint64_t v37; // d12
  uint64_t v38; // r6
  uint64_t v39; // r0
  uint64_t v40; // r6
  uint64_t v41; // r0
  uint64_t v42; // r0
  uint64_t v43; // r8
  uint64_t v44; // r0
  uint64_t v45; // r6
  uint64_t v46; // r0
  uint64_t v47; // r6
  uint64_t v48; // r0
  uint64_t v49; // r0
  uint64_t v50; // r2
  uint64_t v51; // r0
  int v52; // r0
  int result; // r0
  int v54; // t1
  uint64_t v55; // r8
  uint64_t v56; // [sp+0h] [bp-1Ch]
  uint64_t v57; // [sp+8h] [bp-14h]
  uint64_t v58; // [sp+10h] [bp-Ch]

  v6 = double_to_float(a3, a4);
  v8 = dispatch_event_handler(dword_104A80, v6);
  v9 = gpio_port_init(v8);
  v10 = a1;
  dispatch_event_handler(dword_104A88, (int)(float)(v9 * flt_104A84));
  v11 = a5[2];
  v12 = aeabi_dadd(*((uint32_t *)a5 + 4), *((uint32_t *)a5 + 5), 0, dword_104A8C);
  double_to_float(v12, HIDWORD(v12));
  v13 = a5[1];
  v14 = aeabi_dadd(*((uint32_t *)a5 + 2), *((uint32_t *)a5 + 3), 0, dword_104A8C);
  double_to_float(v14, HIDWORD(v14));
  v15 = *a5;
  v16 = aeabi_dadd(*(uint32_t *)a5, *((uint32_t *)a5 + 1), 0, dword_104A8C);
  v17 = double_to_float(v16, HIDWORD(v16));
  v18 = a5[5];
  v58 = a5[4];
  v57 = a5[3];
  dispatch_event_handler(dword_104A90, v17);
  v19 = aeabi_dadd(v18, HIDWORD(v18), 0, dword_104A8C);
  double_to_float(v19, HIDWORD(v19));
  v20 = aeabi_dadd(v58, HIDWORD(v58), 0, dword_104A8C);
  double_to_float(v20, HIDWORD(v20));
  v21 = aeabi_dadd(v57, HIDWORD(v57), 0, dword_104A8C);
  v22 = double_to_float(v21, HIDWORD(v21));
  dispatch_event_handler(dword_104A94, v22);
  v23 = v10 + 32;
  do
  {
    v54 = *v10++;
    v55 = aeabi_d2f(v54);
    if ( double_ge(v15, HIDWORD(v15), v55, HIDWORD(v55)) )
    {
      v50 = v57;
    }
    else if ( double_eq(v13, HIDWORD(v13), v55, HIDWORD(v55)) )
    {
      v50 = v58;
    }
    else if ( double_le(v11, HIDWORD(v11), v55, HIDWORD(v55)) )
    {
      v50 = v18;
    }
    else
    {
      v24 = double_subtract(v55, HIDWORD(v55), v13, HIDWORD(v13));
      v25 = double_subtract(v55, HIDWORD(v55), v11, HIDWORD(v11));
      v26 = double_subtract(v55, HIDWORD(v55), v15, HIDWORD(v15));
      v27 = v25;
      v28 = v26;
      v29 = aeabi_dadd(v57, HIDWORD(v57), v24, HIDWORD(v24));
      v30 = v28;
      v31 = aeabi_dadd(v29, HIDWORD(v29), v27, HIDWORD(v27));
      v32 = double_subtract(v15, HIDWORD(v15), v13, HIDWORD(v13));
      v33 = aeabi_dsub(v31, HIDWORD(v31), v32, HIDWORD(v32));
      v34 = double_subtract(v15, HIDWORD(v15), v11, HIDWORD(v11));
      v35 = aeabi_dsub(v33, HIDWORD(v33), v34, HIDWORD(v34));
      v36 = aeabi_dadd(v58, HIDWORD(v58), v30, HIDWORD(v30));
      v37 = v35;
      v38 = aeabi_dadd(v36, HIDWORD(v36), v27, HIDWORD(v27));
      v39 = double_subtract(v13, HIDWORD(v13), v15, HIDWORD(v15));
      v40 = aeabi_dsub(v38, HIDWORD(v38), v39, HIDWORD(v39));
      v41 = double_subtract(v13, HIDWORD(v13), v11, HIDWORD(v11));
      v42 = aeabi_dsub(v40, HIDWORD(v40), v41, HIDWORD(v41));
      v43 = double_add(v37, HIDWORD(v37), v42, HIDWORD(v42));
      v44 = aeabi_dadd(v18, HIDWORD(v18), v30, HIDWORD(v30));
      v45 = aeabi_dadd(v44, HIDWORD(v44), v24, HIDWORD(v24));
      v46 = double_subtract(v11, HIDWORD(v11), v15, HIDWORD(v15));
      v47 = aeabi_dsub(v45, HIDWORD(v45), v46, HIDWORD(v46));
      v48 = double_subtract(v11, HIDWORD(v11), v13, HIDWORD(v13));
      v49 = aeabi_dsub(v47, HIDWORD(v47), v48, HIDWORD(v48));
      v50 = double_add(v43, HIDWORD(v43), v49, HIDWORD(v49));
    }
    v56 = v50;
    v51 = aeabi_d2f(v10[63]);
    v52 = aeabi_dadd(v51, HIDWORD(v51), v56, HIDWORD(v56));
    result = aeabi_dmul(v52);
    v10[31] = result;
  }
  while ( v10 != v23 );
  return result;
}

