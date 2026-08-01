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

extern uint32_t dword_1081E4;
extern uint32_t dword_1081DC;
extern uint32_t dword_1081E0;

// list_get_at @ 0x108080, size 348 bytes
// Doc: list_get_at [mac]: Calculate crypto channel parameters from context
// list_get_at [mac]: Calculate crypto channel parameters from context
int  list_get_at(int a1, int *a2, uint32_t *a3)
{
  int v4; // r3
  uint64_t v5; // kr08_8
  int v6; // r2
  int v9; // r8
  int v10; // r7
  uint64_t v11; // r2
  int v12; // kr00_4
  int v13; // kr04_4
  unsigned uint64_t v14; // kr18_8
  uint64_t v15; // r2
  int v17; // r12
  unsigned int v18; // r1
  int v19; // r4
  uint64_t v20; // kr20_8
  int v21; // r2
  int v22; // r6
  int v23; // r12
  unsigned int v24; // r4
  int v25; // r6
  int v26; // r7
  int v27; // r3

  v4 = a3[1] - 1;
  v5 = *(uint64_t *)(a1 + 36);
  v6 = *(uint32_t *)(a1 + 12);
  if ( *(uint32_t *)a1 < v4 && v6 <= 49 )
  {
    check_status_bits(1, dword_1081E4);
    rf_tx_power_set((int)a2, a3, a1);
    v6 = *(uint32_t *)(a1 + 12);
  }
  if ( *(uint32_t *)(a1 + 16) - v6 >= a3[6] )
  {
LABEL_8:
    HIDWORD(v15) = ((unsigned uint64_t)(dword_1081DC * (uint64_t)a2[1]) >> 32) - (a2[1] >> 31);
    LODWORD(v15) = ((unsigned uint64_t)(dword_1081DC * (uint64_t)*a2) >> 32) - (*a2 >> 31);
    v14 = *(uint64_t *)(a1 + 20);
    *(uint64_t *)a2 = v15;
    goto LABEL_9;
  }
  v9 = ((unsigned uint64_t)(dword_1081DC * (uint64_t)(int)v5) >> 32) - ((int)v5 >> 31);
  v10 = ((unsigned uint64_t)(dword_1081DC * (uint64_t)SHIDWORD(v5)) >> 32) - (SHIDWORD(v5) >> 31);
  if ( (int)v5 - 1 - 3 * (((unsigned uint64_t)(dword_1081DC * (uint64_t)((int)v5 - 1)) >> 32) - (((int)v5 - 1) >> 31)) == HIDWORD(v5) - 1 - 3 * (((unsigned uint64_t)(dword_1081DC * (uint64_t)(HIDWORD(v5) - 1)) >> 32) - ((HIDWORD(v5) - 1) >> 31)) )
  {
    if ( v9 != v10 )
    {
      v17 = *(uint32_t *)(a1 + 32);
      v18 = *(uint32_t *)(a1 + 20);
      v19 = ((unsigned uint64_t)(dword_1081DC * (uint64_t)(2 * *(uint32_t *)(a1 + 24))) >> 32)
          - ((2 * *(uint32_t *)(a1 + 24)) >> 31);
      v20 = dword_1081DC * (uint64_t)v17;
      v21 = ((unsigned uint64_t)(dword_1081DC * (uint64_t)*a2) >> 32) - (*a2 >> 31);
      a2[1] = 2 * (((unsigned uint64_t)(dword_1081DC * (uint64_t)a2[1]) >> 32) - (a2[1] >> 31));
      *a2 = v21;
      v14 = __PAIR64__(v19 + HIDWORD(v20) - (v17 >> 31), v18);
      goto LABEL_9;
    }
    goto LABEL_8;
  }
  if ( v9 == v10 )
  {
    v22 = *(uint32_t *)(a1 + 20);
    v23 = *(uint32_t *)(a1 + 28);
    v24 = *(uint32_t *)(a1 + 24);
    v25 = ((unsigned uint64_t)(dword_1081DC * (uint64_t)(2 * v22)) >> 32) - ((2 * v22) >> 31);
    v26 = ((unsigned uint64_t)(dword_1081DC * (uint64_t)v23) >> 32) - (v23 >> 31);
    v27 = ((unsigned uint64_t)(dword_1081DC * (uint64_t)a2[1]) >> 32) - (a2[1] >> 31);
    *a2 = 2 * (((unsigned uint64_t)(dword_1081DC * (uint64_t)*a2) >> 32) - (*a2 >> 31));
    a2[1] = v27;
    v14 = __PAIR64__(v24, v25 + v26);
  }
  else
  {
    LODWORD(v11) = 2 * (((unsigned uint64_t)(dword_1081DC * (uint64_t)*a2) >> 32) - (*a2 >> 31));
    HIDWORD(v11) = 2 * (((unsigned uint64_t)(dword_1081DC * (uint64_t)a2[1]) >> 32) - (a2[1] >> 31));
    v12 = *(uint32_t *)(a1 + 20) + *(uint32_t *)(a1 + 28);
    v13 = *(uint32_t *)(a1 + 32) + *(uint32_t *)(a1 + 24);
    *(uint64_t *)a2 = v11;
    v14 = __PAIR64__(v13 / 2, v12 / 2);
  }
LABEL_9:
  *((uint64_t *)a2 + 1) = v14;
  return check_status_bits(1, dword_1081E0);
}

