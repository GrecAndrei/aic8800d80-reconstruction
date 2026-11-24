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


extern uint32_t dword_100E14;
extern uint32_t off_100DE8;
extern uint32_t off_100DEC;
extern uint32_t off_100DF0;
extern uint32_t off_100DF4;
extern uint32_t off_100DF8;
extern uint32_t off_100DFC;
extern uint32_t off_100E00;
extern uint32_t off_100E04;
extern uint32_t off_100E08;
extern uint32_t off_100E0C;
extern uint32_t off_100E10;
extern uint32_t off_100E18;
extern uint32_t off_100E1C;
extern uint32_t off_100E20;

// save_and_call_handler @ 0x100be0, size 520 bytes
void  save_and_call_handler(int a1, int a2, int a3, int a4, char a5)
{
  int *v5; // r8
  uint32_t *v10; // r2
  uint32_t *v11; // r1
  char *v12; // r2
  uint32_t *v13; // r2
  uint32_t *v14; // r1
  int v15; // r3
  char *v16; // r0
  unsigned int *v17; // r5
  unsigned int *v18; // r1
  int v19; // r2
  unsigned int *v20; // r1
  char *v21; // r0
  unsigned int *v22; // r2
  int v23; // r3
  int v24; // r2
  unsigned int *v25; // r1
  unsigned int *v26; // r2
  unsigned int *v27; // r2
  uint32_t *v28; // r1
  uint32_t *v29; // r2
  uint32_t *v30; // r1
  int v31; // r2

  v5 = (int *)off_100E20;
  mmio_write_cmd();
  if ( *((uint8_t *)v5 + 413) && *(uint8_t *)off_100DE8 )
  {
    radio_clock_disable();
  }
  else
  {
    v10 = off_100DEC;
    v11 = off_100DF0;
    *(uint32_t *)off_100DEC &= ~0x800u;
    *v11 &= ~0x20u;
    v10[33] &= ~0x1000u;
  }
  v12 = (char *)off_100DF4;
  *(uint32_t *)off_100DF4 &= ~0x40u;
  if ( a1 == 1 )
  {
    v27 = (unsigned int *)(v12 - 728);
    v28 = off_100DFC;
    *v27 = *v27 & 0xFFFE3FFF | 0x18000;
    *v28 &= ~1u;
    v27[27857] |= 0x100u;
    if ( (a5 & 4) != 0 )
    {
      if ( *((uint8_t *)v5 + 413) && *(uint8_t *)off_100DE8 )
      {
        pmu_init(a3);
      }
      else
      {
        v29 = off_100DEC;
        v30 = off_100DF0;
        *(uint32_t *)off_100DEC |= 0x800u;
        *v30 |= 0x20u;
        v29[33] |= 0x1000u;
      }
      *(uint32_t *)off_100DF4 |= 0x40u;
      if ( a4 != 1 )
        goto LABEL_7;
      goto LABEL_22;
    }
  }
  else
  {
    v13 = off_100DF8;
    v14 = off_100DFC;
    *(uint32_t *)off_100DF8 = *(uint32_t *)off_100DF8 & 0xFFFE3FFF | 0xC000;
    *v14 |= 1u;
    v13[27857] &= ~0x100u;
  }
  if ( a4 != 1 )
  {
LABEL_7:
    if ( a4 == 2 )
    {
      v23 = a3 - a2;
      if ( a3 - a2 <= 0 )
      {
        if ( v23 >= -10 )
          v24 = 2;
        else
          v24 = 3;
      }
      else
      {
        v24 = v23 <= 10;
      }
      v15 = ((uint8_t)((int)((uint64_t)(dword_100E14 * (uint64_t)(a2 - (a3 - 30))) >> 32) >> 3)
           - (uint8_t)((a2 - (a3 - 30)) >> 31))
          & 7;
      *(uint32_t *)off_100E00 = v24;
    }
    else
    {
      v15 = 0;
      *(uint32_t *)off_100E00 = 0;
    }
    goto LABEL_9;
  }
LABEL_22:
  if ( a3 <= (unsigned int)a2 )
    v31 = 2;
  else
    v31 = 1;
  *(uint32_t *)off_100E00 = v31;
  v15 = a3 <= (unsigned int)a2;
LABEL_9:
  v16 = (char *)off_100E04;
  v17 = (unsigned int *)off_100E08;
  v18 = (unsigned int *)off_100E0C;
  *(uint32_t *)off_100E04 = v15 | *(uint32_t *)off_100E04 & 0xFFFFFFF8;
  v19 = (a4 << 24) & 0x3000000;
  *v17 = *v17 & 0xFCFFFFFF | v19;
  *v18 = (a4 << 16) & 0x30000 | *v18 & 0xFFFCFFFF;
  v20 = v18 + 16708;
  *(uint32_t *)&v16[-80] = *(uint32_t *)&v16[-80] & 0xFFFFFFF0 | a4 & 0xF;
  v21 = v16 - 80;
  *v20 = v19 | *v20 & 0xFCFFFFFF;
  if ( a4 )
  {
    if ( a4 == 1 )
    {
      v25 = (unsigned int *)off_100E1C;
      v26 = (unsigned int *)off_100E10;
      *(uint32_t *)off_100E18 = *(uint32_t *)off_100E18 & 0xFFFFFF | 0x18000000;
      *v25 = *v25 & 0xFFFFFFCF | 0x10;
      *v26 = *v26 & 0xFFFF00FF | 0x6C00;
    }
  }
  else
  {
    v22 = (unsigned int *)off_100E10;
    *((uint32_t *)v21 + 1) = *((uint32_t *)v21 + 1) & 0xFFFFFF | 0x19000000;
    v20[15866] &= 0xFFFFFFCF;
    *v22 = *v22 & 0xFFFF00FF | 0x9C00;
  }
}
