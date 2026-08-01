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

extern uint32_t dword_107BD4;
extern uint32_t dword_107BCC;
extern uint32_t dword_107BD0;

// rx_queue_pop_packet @ 0x107a70, size 348 bytes
int  rx_queue_pop_packet(int a1, int *a2, uint32_t *a3)
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
  int v16; // r12
  unsigned int v17; // r1
  int v18; // r4
  uint64_t v19; // kr20_8
  int v20; // r6
  int v21; // r12
  unsigned int v22; // r4
  int v23; // r6
  int v24; // r7

  v4 = a3[1] - 1;
  v5 = *(uint64_t *)(a1 + 36);
  v6 = *(uint32_t *)(a1 + 12);
  if ( *(uint32_t *)a1 < v4 && v6 <= 49 )
  {
    check_interrupt_flag(1, dword_107BD4, v6, v4);
    rf_core_irq_clear((int)a2, a3, a1);
    v6 = *(uint32_t *)(a1 + 12);
  }
  if ( *(uint32_t *)(a1 + 16) - v6 >= a3[6] )
  {
LABEL_8:
    HIDWORD(v11) = ((unsigned uint64_t)(dword_107BCC * (uint64_t)a2[1]) >> 32) - (a2[1] >> 31);
    LODWORD(v11) = ((unsigned uint64_t)(dword_107BCC * (uint64_t)*a2) >> 32) - (*a2 >> 31);
    v14 = *(uint64_t *)(a1 + 20);
    *(uint64_t *)a2 = v11;
    goto LABEL_9;
  }
  v9 = ((unsigned uint64_t)(dword_107BCC * (uint64_t)(int)v5) >> 32) - ((int)v5 >> 31);
  v10 = ((unsigned uint64_t)(dword_107BCC * (uint64_t)SHIDWORD(v5)) >> 32) - (SHIDWORD(v5) >> 31);
  if ( (int)v5 - 1 - 3 * (((unsigned uint64_t)(dword_107BCC * (uint64_t)((int)v5 - 1)) >> 32) - (((int)v5 - 1) >> 31)) == HIDWORD(v5) - 1 - 3 * (((unsigned uint64_t)(dword_107BCC * (uint64_t)(HIDWORD(v5) - 1)) >> 32) - ((HIDWORD(v5) - 1) >> 31)) )
  {
    if ( v9 != v10 )
    {
      v16 = *(uint32_t *)(a1 + 32);
      v17 = *(uint32_t *)(a1 + 20);
      v18 = ((unsigned uint64_t)(dword_107BCC * (uint64_t)(2 * *(uint32_t *)(a1 + 24))) >> 32)
          - ((2 * *(uint32_t *)(a1 + 24)) >> 31);
      v19 = dword_107BCC * (uint64_t)v16;
      HIDWORD(v11) = 2 * (((unsigned uint64_t)(dword_107BCC * (uint64_t)a2[1]) >> 32) - (a2[1] >> 31));
      LODWORD(v11) = ((unsigned uint64_t)(dword_107BCC * (uint64_t)*a2) >> 32) - (*a2 >> 31);
      *(uint64_t *)a2 = v11;
      v14 = __PAIR64__(v18 + HIDWORD(v19) - (v16 >> 31), v17);
      goto LABEL_9;
    }
    goto LABEL_8;
  }
  if ( v9 == v10 )
  {
    v20 = *(uint32_t *)(a1 + 20);
    v21 = *(uint32_t *)(a1 + 28);
    v22 = *(uint32_t *)(a1 + 24);
    v23 = ((unsigned uint64_t)(dword_107BCC * (uint64_t)(2 * v20)) >> 32) - ((2 * v20) >> 31);
    LODWORD(v11) = 2 * (((unsigned uint64_t)(dword_107BCC * (uint64_t)*a2) >> 32) - (*a2 >> 31));
    v24 = ((unsigned uint64_t)(dword_107BCC * (uint64_t)v21) >> 32) - (v21 >> 31);
    HIDWORD(v11) = ((unsigned uint64_t)(dword_107BCC * (uint64_t)a2[1]) >> 32) - (a2[1] >> 31);
    *(uint64_t *)a2 = v11;
    v14 = __PAIR64__(v22, v23 + v24);
  }
  else
  {
    LODWORD(v11) = 2 * (((unsigned uint64_t)(dword_107BCC * (uint64_t)*a2) >> 32) - (*a2 >> 31));
    HIDWORD(v11) = 2 * (((unsigned uint64_t)(dword_107BCC * (uint64_t)a2[1]) >> 32) - (a2[1] >> 31));
    v12 = *(uint32_t *)(a1 + 20) + *(uint32_t *)(a1 + 28);
    v13 = *(uint32_t *)(a1 + 32) + *(uint32_t *)(a1 + 24);
    *(uint64_t *)a2 = v11;
    v14 = __PAIR64__(v13 / 2, v12 / 2);
  }
LABEL_9:
  *((uint64_t *)a2 + 1) = v14;
  return check_interrupt_flag(1, dword_107BD0, v11, HIDWORD(v11));
}

