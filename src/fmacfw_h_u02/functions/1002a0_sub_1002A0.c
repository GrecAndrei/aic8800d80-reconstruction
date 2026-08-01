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

extern uint32_t off_100418;
extern uint32_t dword_10041C;
extern uint32_t off_100420;
extern uint32_t off_100470;
extern uint32_t dword_100474;
extern uint32_t off_100424;
extern uint32_t off_100428;
extern uint32_t dword_10042C;
extern uint32_t dword_10046C;
extern uint32_t dword_100464;
extern uint32_t dword_100430;
extern uint32_t off_100438;
extern uint32_t off_100434;
extern uint32_t off_10043C;
extern uint32_t off_100440;
extern uint32_t off_100448;
extern uint32_t off_100444;
extern uint32_t off_10044C;
extern uint32_t dword_100450;
extern uint32_t dword_100454;
extern uint32_t dword_100468;
extern uint32_t off_100458;
extern uint32_t dword_10045C;
extern uint32_t dword_100460;

// mac_event_handler @ 0x1002a0, size 376 bytes
int mac_event_handler()
{
  uint8_t **v0; // r5
  int v1; // r7
  int v2; // r3
  int *v3; // r4
  int v4; // r2
  unsigned int v5; // lr
  uint32_t *v6; // r12
  unsigned int v7; // r8
  uint64_t v8; // kr00_8
  uint64_t v9; // kr08_8
  unsigned int v10; // r7
  unsigned int v11; // r3
  unsigned int *v12; // r4
  int v13; // r3
  unsigned int v14; // r6
  unsigned int v15; // r0
  unsigned int v16; // r3
  int16_t **v17; // r6
  int v18; // r0
  int v19; // r3
  int **v20; // r0
  int v21; // r2
  int *v22; // r12
  uint64_t v23; // kr10_8
  int v24; // r1
  int v25; // r7
  unsigned int v26; // r4
  uint64_t v27; // kr18_8
  int v28; // r0
  uint32_t *v29; // r7
  int v30; // r2
  int *v31; // r1
  unsigned int v32; // r4
  int v33; // r2
  unsigned int v34; // r3
  unsigned int v35; // r3
  unsigned int v36; // r7
  int result; // r0
  uint8_t *v38; // r3
  int v39; // r2
  unsigned int v40; // r2

  v0 = (uint8_t **)off_100418;
  v1 = dword_10041C;
  v2 = *(uint32_t *)off_100418;
  v3 = (int *)off_100420;
  v4 = *(uint16_t *)(*(uint32_t *)off_100418 + 8);
  v5 = *(uint32_t *)(*(uint32_t *)off_100418 + 52);
  v6 = off_100470;
  v7 = dword_100474;
  *((uint32_t *)off_100470 + 4) = v5;
  v8 = *(uint64_t *)(v2 + 36);
  v9 = *(uint64_t *)(v2 + 44);
  *v3 = v1;
  v10 = v1 + 88 * v4 + 88;
  v11 = (unsigned int)v8 >> 3;
  v12 = (unsigned int *)off_100424;
  *v6 = v8;
  if ( (unsigned int)v8 >> 3 < 3 )
    v11 = 3;
  *v12 = v11;
  v13 = HIDWORD(v8) >> 3;
  v14 = (unsigned int)v9 >> 3;
  if ( HIDWORD(v8) >> 3 < 3 )
    v13 = 3;
  v6[1] = HIDWORD(v8);
  v15 = HIDWORD(v9) >> 3;
  if ( (unsigned int)v8 < 3 )
    v14 = 3;
  v12[1] = v13;
  v16 = v5 >> 3;
  if ( v15 < 3 )
    v15 = 3;
  v12[2] = v14;
  v17 = (int16_t **)off_100428;
  v6[3] = HIDWORD(v9);
  if ( v16 < 3 )
    v16 = 3;
  v12[3] = v15;
  v18 = dword_10042C;
  v12[4] = v16;
  v6[2] = v9;
  debug_printf(v18, v7, v10);
  if ( **v17 < 0 && v10 >= v7 )
    irq_disable_mmio_write(dword_10046C, dword_100464, 120);
  v19 = dword_100430;
  v20 = (int **)off_100438;
  v21 = dword_100430 + 80 * (*((uint16_t *)*v0 + 4) + 1);
  *(uint32_t *)off_100434 = v21;
  v22 = *v20;
  v23 = *(uint64_t *)(v12 + 1);
  v24 = v21 + 360 * *v12;
  v25 = v24 + 360 * v23;
  *(uint32_t *)off_10043C = v24;
  v27 = *(uint64_t *)(v12 + 3);
  v26 = v12[4];
  v28 = v25 + 360 * HIDWORD(v23);
  *(uint32_t *)off_100440 = v25;
  v29 = off_100448;
  *(uint32_t *)off_100444 = v28;
  v30 = v28 + 360 * v27;
  v31 = (int *)off_10044C;
  *v29 = v30;
  v32 = v30 + 360 * v26;
  v33 = *v22;
  *v31 = v19;
  if ( !v33 )
  {
    v34 = (v22[1] + 4) & 0xFFFFFFFC;
    *v22 = v32 + 4;
    v32 += v34;
  }
  if ( !v22[2] )
  {
    v35 = (v22[3] + 4) & 0xFFFFFFFC;
    v22[2] = v32 + 4;
    v32 += v35;
  }
  v36 = dword_100450;
  result = debug_printf(dword_100454, dword_100430, dword_100450);
  if ( **v17 < 0 && v32 >= v36 )
    result = irq_disable_mmio_write(dword_100468, dword_100464, 156);
  v38 = *v0;
  *(uint32_t *)off_100458 = *((uint32_t *)*v0 + 3);
  v39 = *v38;
  if ( v39 == 2 )
  {
    v40 = *((uint32_t *)v38 + 4);
  }
  else
  {
    if ( v39 != 1 )
      return result;
    v40 = *((uint32_t *)v38 + 5);
  }
  if ( v40 )
  {
    if ( dword_10045C > v40 )
      return debug_printf(dword_100460, dword_10045C, v40);
  }
  return result;
}

