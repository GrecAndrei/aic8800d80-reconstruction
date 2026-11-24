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


extern uint32_t dword_10041C;
extern uint32_t dword_100430;
extern uint32_t dword_100450;
extern uint32_t dword_10045C;
extern uint32_t dword_100474;
extern uint32_t off_100418;
extern uint32_t off_100420;
extern uint32_t off_100424;
extern uint32_t off_100428;
extern uint32_t off_100434;
extern uint32_t off_100438;
extern uint32_t off_10043C;
extern uint32_t off_100440;
extern uint32_t off_100444;
extern uint32_t off_100448;
extern uint32_t off_10044C;
extern uint32_t off_100458;
extern uint32_t off_100470;

// mac_event_handler @ 0x1002a0, size 376 bytes
int  mac_event_handler(int a1, int a2, int a3, int a4)
{
  uint8_t **v4; // r5
  int v5; // r7
  int v6; // r3
  int *v7; // r4
  int v8; // r2
  unsigned int v9; // lr
  uint32_t *v10; // r12
  unsigned int v11; // r8
  uint64_t v12; // kr00_8
  uint64_t v13; // kr08_8
  unsigned int v14; // r7
  unsigned int v15; // r3
  int *v16; // r4
  int v17; // r3
  unsigned int v18; // r6
  unsigned int v19; // r0
  unsigned int v20; // r3
  uint16_t **v21; // r6
  int v22; // r3
  int **v23; // r0
  int v24; // r2
  int *v25; // r12
  uint64_t v26; // kr10_8
  int v27; // r1
  int v28; // r7
  int v29; // r4
  uint64_t v30; // kr18_8
  int v31; // r0
  uint32_t *v32; // r7
  int v33; // r2
  int *v34; // r1
  unsigned int v35; // r4
  int v36; // r2
  unsigned int v37; // r3
  unsigned int v38; // r3
  unsigned int v39; // r7
  int result; // r0
  uint8_t *v41; // r3
  int v42; // r2
  unsigned int v43; // r2

  v4 = (uint8_t **)off_100418;
  v5 = dword_10041C;
  v6 = *(uint32_t *)off_100418;
  v7 = (int *)off_100420;
  v8 = *(uint16_t *)(*(uint32_t *)off_100418 + 8);
  v9 = *(uint32_t *)(*(uint32_t *)off_100418 + 52);
  v10 = off_100470;
  v11 = dword_100474;
  *((uint32_t *)off_100470 + 4) = v9;
  v12 = *(uint64_t *)(v6 + 36);
  v13 = *(uint64_t *)(v6 + 44);
  *v7 = v5;
  v14 = v5 + 88 * v8 + 88;
  v15 = (unsigned int)v12 >> 3;
  v16 = off_100424;
  *v10 = v12;
  if ( (unsigned int)v12 >> 3 < 3 )
    v15 = 3;
  *v16 = v15;
  v17 = HIDWORD(v12) >> 3;
  v18 = (unsigned int)v13 >> 3;
  if ( HIDWORD(v12) >> 3 < 3 )
    v17 = 3;
  v10[1] = HIDWORD(v12);
  v19 = HIDWORD(v13) >> 3;
  if ( (unsigned int)v12 < 3 )
    v18 = 3;
  v16[1] = v17;
  v20 = v9 >> 3;
  if ( v19 < 3 )
    v19 = 3;
  v16[2] = v18;
  v21 = (uint16_t **)off_100428;
  v10[3] = HIDWORD(v13);
  if ( v20 < 3 )
    v20 = 3;
  v16[3] = v19;
  v16[4] = v20;
  v10[2] = v13;
  debug_printf("stk_start=%x, ptr_bss=%x\n", v11, v14);
  if ( **v21 < 0 && v14 >= v11 )
    irq_disable_mmio_write((int)aPtrBssStartSta, (int)aPostponedArray, 120);
  v22 = dword_100430;
  v23 = (int **)off_100438;
  v24 = dword_100430 + 80 * (*((uint16_t *)*v4 + 4) + 1);
  *(uint32_t *)off_100434 = v24;
  v25 = *v23;
  v26 = *(uint64_t *)(v16 + 1);
  v27 = v24 + 360 * *v16;
  v28 = v27 + 360 * v26;
  *(uint32_t *)off_10043C = v27;
  v30 = *(uint64_t *)(v16 + 3);
  v29 = v16[4];
  v31 = v28 + 360 * HIDWORD(v26);
  *(uint32_t *)off_100440 = v28;
  v32 = off_100448;
  *(uint32_t *)off_100444 = v31;
  v33 = v31 + 360 * v30;
  v34 = (int *)off_10044C;
  *v32 = v33;
  v35 = v33 + 360 * v29;
  v36 = *v25;
  *v34 = v22;
  if ( !v36 )
  {
    v37 = (v25[1] + 4) & 0xFFFFFFFC;
    *v25 = v35 + 4;
    v35 += v37;
  }
  if ( !v25[2] )
  {
    v38 = (v25[3] + 4) & 0xFFFFFFFC;
    v25[2] = v35 + 4;
    v35 += v38;
  }
  v39 = dword_100450;
  result = debug_printf("emacsh=%x, lmacsh=%x, ptr_macsh=%x\n", dword_100430, dword_100450, v35);
  if ( **v21 < 0 && v35 >= v39 )
    result = irq_disable_mmio_write((int)aPtrMacshLmacsh, (int)aPostponedArray, 156);
  v41 = *v4;
  ((uint32_t *)(uintptr_t)off_100458)[0] = *((uint32_t *)*v4 + 3);
  v42 = *v41;
  if ( v42 == 2 )
  {
    v43 = *((uint32_t *)v41 + 4);
  }
  else
  {
    if ( v42 != 1 )
      return result;
    v43 = *((uint32_t *)v41 + 5);
  }
  if ( v43 )
  {
    if ( dword_10045C > v43 )
      return debug_printf("mem overlaps: stk_end=%x, host_base=%x\r\n", dword_10045C, v43);
  }
  return result;
}
