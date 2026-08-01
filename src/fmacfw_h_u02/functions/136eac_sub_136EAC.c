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

extern uint32_t dword_136F78;
extern uint32_t off_136F7C;
extern uint32_t off_136F80;
extern uint32_t dword_136F88;
extern uint32_t dword_136F84;

// rf_set_channel_cfg @ 0x136eac, size 202 bytes
int  rf_set_channel_cfg(int a1, int a2, int a3, int16_t a4)
{
  int v4; // r2
  uint16_t *v5; // r4
  int v7; // r1
  int *v8; // r7
  int v9; // r1
  int v10; // r0
  int16_t v11; // r1
  int v12; // r3
  int v13; // r0
  int v14; // r1
  int16_t **v15; // r3
  int16_t *v16; // r3
  char v18; // r7
  int v19; // r2
  int16_t v20; // r6
  int16_t v21; // r1
  int16_t *v22; // r3
  int v23; // r0

  v4 = dword_136F78;
  v5 = off_136F7C;
  v7 = *(uint8_t *)(a2 + 366);
  *((uint16_t *)off_136F7C + 1924) = a4;
  v8 = (int *)(a2 + 352);
  *(uint32_t *)(v4 + 1320 * v7 + 472) = 0;
  v5[1925] = 1;
  v9 = *(uint32_t *)(a2 + 356);
  *((uint32_t *)v5 + 963) = *(uint32_t *)(a2 + 352);
  v5[1928] = v9;
  *(uint32_t *)v5 = a2;
  *((uint8_t *)v5 + 3899) = 0;
  v10 = rf_hw_init(a2 + 352, 0);
  if ( v10 && (v11 = *(uint8_t *)(v10 + 57), v12 = v10, *(uint8_t *)(v10 + 57)) )
  {
    v18 = *(uint8_t *)(v10 + 58);
    v19 = v10 + 2;
    v13 = *(uint32_t *)(v10 + 2);
    *((uint32_t *)v5 + 973) = v13;
    v5[1948] = *(uint16_t *)(v19 + 4);
    v20 = ((1 << v18) - 1) << 8;
    LOWORD(v19) = v5[1948] & ~v20;
    v5[1948] = v19;
    v21 = *(uint16_t *)(v12 + 6) - (v11 << 8);
    v22 = *(int16_t **)off_136F80;
    v5[1948] = v20 & v21 | v19;
    if ( *v22 >= 0 )
      goto LABEL_4;
  }
  else
  {
    v13 = *v8;
    v14 = *(uint32_t *)(a2 + 356);
    v15 = (int16_t **)off_136F80;
    *((uint32_t *)v5 + 973) = *v8;
    v16 = *v15;
    v5[1948] = v14;
    if ( *v16 >= 0 )
    {
LABEL_4:
      is_initialized(v13);
      return 1;
    }
  }
  if ( (*(uint8_t *)(a2 + 352) & 1) == 0 )
    goto LABEL_4;
  v23 = irq_disable_mmio_write(dword_136F88, dword_136F84, 178);
  is_initialized(v23);
  return 1;
}

