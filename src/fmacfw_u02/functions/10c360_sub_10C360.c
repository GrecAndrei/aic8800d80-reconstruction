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

extern uint32_t dword_10C5B0;
extern uint32_t off_10C5B4;
extern uint32_t off_10C5B8;
extern uint32_t off_10C5BC;
extern uint32_t off_10C5C4;
extern uint32_t off_10C5C0;
extern uint32_t dword_10C5A0;
extern uint32_t dword_10C590;
extern uint32_t dword_10C5C8;
extern uint32_t dword_10C5CC;
extern uint32_t off_10C5E8;
extern uint32_t off_10C5D0;
extern uint32_t dword_10C5D4;
extern uint32_t dword_10C5D8;
extern uint32_t off_10C5A8;
extern uint32_t off_10C5AC;
extern uint32_t off_10C5E0;
extern uint32_t dword_10C5DC;
extern uint32_t dword_10C5E4;

// rx_header_decode @ 0x10c360, size 546 bytes
int * rx_header_decode(int *result, unsigned int a2, int a3, int a4)
{
  int v4; // r6
  int v7; // r7
  int v8; // r10
  unsigned int v9; // r3
  unsigned int v10; // r3
  unsigned int v11; // r0
  int v12; // r0
  uint64_t v13; // r8
  double v14; // d8
  uint64_t v15; // r0
  uint64_t v16; // r0
  uint64_t v17; // r0
  int v18; // r0
  int v19; // r8
  int v20; // r0
  int v21; // r2
  int v22; // r0
  int v23; // r8
  uint16_t *v24; // r6
  int v25; // r1
  int v26; // r2
  int v27; // r5
  uint64_t v28; // r0
  int v29; // r2
  int v30; // r3
  uint64_t v31; // r0
  int v32; // r2
  int v33; // r3
  int v34; // r2
  int v35; // r3
  int v36; // [sp+Ch] [bp-58h]
  uint32_t v37[3]; // [sp+24h] [bp-40h] BYREF
  uint64_t v38; // [sp+30h] [bp-34h] BYREF
  int v39; // [sp+38h] [bp-2Ch]
  int v40; // [sp+3Ch] [bp-28h]
  uint64_t v41; // [sp+40h] [bp-24h]
  int v42; // [sp+48h] [bp-1Ch]
  int v43; // [sp+4Ch] [bp-18h]
  int v44; // [sp+50h] [bp-14h]
  int v45; // [sp+54h] [bp-10h]
  int v46; // [sp+58h] [bp-Ch]
  int v47; // [sp+5Ch] [bp-8h]

  v4 = *result;
  v7 = (uint8_t)*result >> 6;
  if ( !a3 )
  {
    if ( !a4 )
      return result;
    goto LABEL_3;
  }
  v8 = result[1];
  check_status_bits(0x2000, dword_10C5B0);
  v9 = a2 - 2;
  do
  {
    *(uint16_t *)(v9 + 2) = -32640;
    v9 += 2;
  }
  while ( a2 + 30 != v9 );
  *(uint32_t *)(a2 + 32) = 0;
  *(uint32_t *)(a2 + 36) = 0;
  v10 = a2 + 36;
  do
  {
    *(uint32_t *)(v10 + 4) = 0;
    v10 += 4;
  }
  while ( a2 + 100 != v10 );
  while ( !*(uint32_t *)off_10C5B4 )
    ;
  if ( v7 )
  {
    v11 = (*(uint32_t *)off_10C5B8 >> 5) & 0x1F;
    if ( (*(uint32_t *)off_10C5B8 & 0x400) != 0 )
      v11 *= 2;
    if ( (*(uint32_t *)off_10C5BC & 0x80000) != 0 && (*(uint32_t *)off_10C5BC & 0x40000) != 0 )
      v11 >>= 1;
    v12 = *(uint8_t *)off_10C5C4 * v11;
    *(uint32_t *)off_10C5C0 &= ~1u;
    if ( (uint8_t)v4 >> 7 )
    {
      v13 = *(uint64_t *)&dword_10C5A0;
      v14 = dbl_10C598;
    }
    else
    {
      v13 = *(uint64_t *)&dword_10C590;
      v14 = dbl_10C588;
    }
    v15 = int_to_double(v12);
    v16 = double_add(v15, HIDWORD(v15), 0, dword_10C5C8);
    v17 = double_subtract(v13, HIDWORD(v13), v16, HIDWORD(v16));
    v18 = double_add(v17, HIDWORD(v17), 0, dword_10C5CC);
    v19 = double_add(v18);
    v20 = double_subtract(LODWORD(v14), HIDWORD(v14), 0, dword_10C5C8);
    v21 = double_add(v20);
    v22 = v19;
    v23 = v21;
    *(uint32_t *)off_10C5E8 = double_to_int(v22) & 0x7FFFFFFF;
    *(uint32_t *)off_10C5D0 = dword_10C5D4 & (double_to_int(v23) << 13) | *(uint32_t *)off_10C5D0 & dword_10C5D8;
  }
  enable_pa();
  periph_init_2((uint8_t)v4, a2, v8, (uint16_t)v4 >> 12, BYTE1(v4) & 0xF, 0);
  result = (int *)configure_gpio_bits();
  *(uint32_t *)off_10C5B4 = 1;
  if ( a4 )
  {
LABEL_3:
    if ( ((*(uint32_t *)off_10C5A8 & 0x8000000) == 0 || (*(uint32_t *)off_10C5AC & 0x400) != 0) && !v7 )
    {
      v24 = (uint16_t *)off_10C5E0;
      v25 = *(uint32_t *)(dword_10C5DC + 4);
      v26 = *(uint32_t *)(dword_10C5DC + 8);
      v27 = dword_10C5DC + 72;
      v37[0] = *(uint32_t *)dword_10C5DC;
      v37[1] = v25;
      v37[2] = v26;
      enable_pa();
      v28 = *(uint64_t *)v27;
      v29 = *(uint32_t *)(v27 + 8);
      v30 = *(uint32_t *)(v27 + 12);
      v27 += 16;
      v38 = v28;
      v39 = v29;
      v40 = v30;
      v31 = *(uint64_t *)v27;
      v32 = *(uint32_t *)(v27 + 8);
      v33 = *(uint32_t *)(v27 + 12);
      v27 += 16;
      v41 = v31;
      v42 = v32;
      v43 = v33;
      HIDWORD(v31) = *(uint32_t *)(v27 + 4);
      v34 = *(uint32_t *)(v27 + 8);
      v35 = *(uint32_t *)(v27 + 12);
      v44 = *(uint32_t *)v27;
      v45 = HIDWORD(v31);
      v46 = v34;
      v47 = v35;
      *((uint8_t *)v24 + 4) = 0;
      LODWORD(v31) = dword_10C5E4;
      *((uint8_t *)v24 + 12) = 0;
      *((uint8_t *)v24 + 20) = 0;
      *((uint8_t *)v24 + 28) = 0;
      *((uint8_t *)v24 + 36) = 0;
      *((uint8_t *)v24 + 44) = 0;
      *((uint8_t *)v24 + 52) = 0;
      periph_base_setup((unsigned int *)v31, (uint8_t *)(a2 + 125), (int)v24);
      boot_init(v37, dword_10C5E4, a2 + 104, a2 + 125, v24, 6, 1, v36, 0, 0, &v38);
      *((uint8_t *)v24 + 4) = 0;
      *((uint8_t *)v24 + 12) = 0;
      *((uint8_t *)v24 + 20) = 0;
      *((uint8_t *)v24 + 28) = 0;
      *((uint8_t *)v24 + 36) = 0;
      *((uint8_t *)v24 + 44) = 0;
      *((uint8_t *)v24 + 52) = 0;
      return (int *)configure_gpio_bits();
    }
  }
  return result;
}

