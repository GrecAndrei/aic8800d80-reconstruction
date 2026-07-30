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

extern uint32_t dword_1213F8;
extern uint32_t off_1213FC;
extern uint32_t off_121410;
extern uint32_t off_121414;
extern uint32_t off_121400;
extern uint32_t off_121404;
extern uint32_t off_121408;
extern uint32_t off_12140C;

// rf_chan_table_init_n_74 @ 0x121340, size 184 bytes
// Doc: rf_chan_table_init_n_74 [rf]: Initialize per-channel RF register table at 0x403200ac..bc sized 0x2b8
// rf_chan_table_init_n_74 [rf]: Initialize per-channel RF register table at 0x403200ac..bc sized 0x2b8
int  rf_chan_table_init_n_74(int a1, int a2)
{
  int v2; // r6
  uint32_t *v3; // r3
  uint32_t *v4; // lr
  uint32_t *v5; // r12
  uint32_t *v6; // r7
  uint16_t *v7; // r2
  uint32_t *v8; // r5
  int *v9; // r2
  int v10; // r4
  unsigned int v11; // r5
  uint32_t *v12; // r12
  uint32_t *v13; // r7
  uint16_t *v14; // r3
  uint32_t *v15; // r2

  v2 = dword_1213F8;
  v3 = off_1213FC;
  v4 = off_121410;
  v5 = off_121414;
  v6 = off_121400;
  v7 = (uint16_t *)(dword_1213F8 + 696 * a1);
  *(uint32_t *)off_1213FC = v7[19] | (v7[20] << 16);
  v8 = off_121404;
  v3[1] = v7[21];
  v9 = (int *)off_121408;
  *v4 = 0;
  *v5 = 0;
  *v8 = 0;
  *v6 = 0;
  v10 = (uint8_t)(a1 + 16);
  *v9 = 0x20000000;
  while ( (*v9 & 0x20000000) != 0 )
    ;
  if ( (*v9 & 0x10000000) == 0 )
  {
    v11 = HIWORD(*v9);
    if ( (uint8_t)BYTE2(*v9) != v10 )
    {
      v12 = off_12140C;
      v13 = off_121408;
      *(uint32_t *)off_1213FC = -1;
      *v12 = -1;
      *v9 = ((uint8_t)v11 << 16) | 0x40000000;
      while ( (*v13 & 0x40000000) != 0 )
        ;
      v14 = (uint16_t *)(v2 + 696 * a1);
      *(uint32_t *)off_1213FC = v14[19] | (v14[20] << 16);
      *(uint32_t *)off_12140C = v14[21];
    }
  }
  v15 = off_121408;
  *(uint32_t *)off_121408 = (16 * a2) | (v10 << 16) | 0x40000002;
  while ( (*v15 & 0x40000000) != 0 )
    ;
  return (uint8_t)(a1 + 16);
}

