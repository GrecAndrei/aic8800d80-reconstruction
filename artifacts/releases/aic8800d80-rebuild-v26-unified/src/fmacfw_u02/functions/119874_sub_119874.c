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

extern uint32_t dword_1199BC;
extern uint32_t off_1199C4;
extern uint32_t off_1199C0;

// sub_119874 @ 0x119874, size 326 bytes
// Doc: sub_1219874 [unknown]: Unknown behavioral function in fmacfw
// sub_1219874 [unknown]: Unknown behavioral function in fmacfw
int  sub_119874(int a1, int *a2, unsigned int a3, unsigned int a4, uint8_t a5)
{
  int *v5; // r4
  int v6; // r5
  int v8; // r6
  int v9; // r8
  uint16_t *v10; // lr
  int v11; // r9
  char v12; // r0
  int v13; // r0
  unsigned int v14; // r0
  unsigned int v15; // r7
  unsigned int v16; // r0
  unsigned int v17; // r3
  int16_t v18; // r10
  int *v19; // r8
  unsigned int v20; // r7
  int16_t v21; // r12
  int v22; // r10
  int v23; // r8

  v5 = (int *)*a2;
  if ( (*(uint16_t *)(*a2 + 82) & 1) == 0 )
    return 0;
  v6 = *(uint32_t *)(a1 + 68);
  if ( *(uint8_t *)(v6 + 12) != *((uint8_t *)v5 + 29)
    || *(uint8_t *)(v6 + 13) != *((uint8_t *)v5 + 27) )
  {
    return 0;
  }
  v8 = v5[19];
  v9 = *(uint32_t *)(v6 + 324);
  v10 = *(uint16_t **)(v8 + 28);
  v11 = *(uint32_t *)(v9 + 76);
  if ( !v10 || (*v10 & 0x8000) != 0 )
  {
    v13 = *(uint32_t *)(v8 + 36);
  }
  else
  {
    *v10 = ~((unsigned int)~((uint16_t)*v10 << 17) >> 17);
    v12 = *((uint8_t *)v5 + 50) + 4;
    *((uint8_t *)v5 + 51) += 4;
    *((uint8_t *)v5 + 50) = v12;
    v13 = *(uint32_t *)(v8 + 36) + 4;
    *(uint32_t *)(v8 + 32) += 4;
    *(uint32_t *)(v8 + 36) = v13;
  }
  v14 = (uint16_t)(((v13 + 3) & 0xFFFC) + 4);
  if ( a4 <= v14 )
  {
    v15 = 0;
  }
  else
  {
    v15 = ((unsigned int)(uint16_t)(a4 - v14) + 3) >> 2;
    v14 = (uint16_t)(v14 + 4 * v15);
  }
  v16 = v14 + *(uint32_t *)(v6 + 40);
  if ( v16 > a3 )
    return 0;
  v17 = *(uint32_t *)(v9 + 36) & 0xFFE7FFFF;
  v18 = *(uint16_t *)(v6 + 10);
  --*(uint8_t *)(dword_1199BC + 84 * a5 + 80);
  *(uint32_t *)(v9 + 36) = v17 | 0x300000;
  v19 = (int *)off_1199C4;
  v20 = v5[9] & 0xFFE7FFFF | (v15 << 9);
  v21 = *((uint16_t *)v5 + 40) + v18;
  v22 = *v5;
  *(uint32_t *)(v11 + 68) = v17 | 0x300100;
  *(uint32_t *)(v11 + 20) = v8 + 12;
  v23 = *v19;
  v5[9] = v20 | 0x780000;
  *(uint32_t *)(v8 + 68) = v20 | 0x780100;
  *(uint32_t *)(v8 + 16) = 0;
  *(uint32_t *)(v8 + 48) = 0;
  *(uint32_t *)(v6 + 40) = v16;
  v5[17] = v6;
  *(uint32_t *)(v6 + 324) = v5;
  *(uint16_t *)(v6 + 10) = v21;
  *a2 = v22;
  if ( !*(uint8_t *)(v23 + 1) )
    *(uint32_t *)(v6 + 20) = *(uint8_t *)(v23 + 1);
  if ( v10 )
    *(uint32_t *)(*(uint32_t *)(v8 + 32) - 3) = *((uint32_t *)off_1199C0 + 43);
  *(uint8_t *)(v8 + 1) = *(uint8_t *)(v11 + 1) + 1;
  return 1;
}

