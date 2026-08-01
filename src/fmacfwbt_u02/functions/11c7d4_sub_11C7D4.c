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

extern uint32_t off_11C8A4;
extern uint32_t dword_11C8BC;
extern uint32_t off_11C8C0;
extern uint32_t dword_11C8CC;
extern uint32_t dword_11C8B4;
extern uint32_t dword_11C8C4;
extern uint32_t dword_11C8A8;
extern uint32_t dword_11C8AC;
extern uint32_t dword_11C8C8;
extern uint32_t dword_11C8B8;
extern uint32_t dword_11C8B0;

// get_rate_index @ 0x11c7d4, size 208 bytes
// Doc: sub_121C7D4 [bt]: Process BT control message with field extraction
// sub_121C7D4 [bt]: Process BT control message with field extraction
unsigned int  get_rate_index(int a1, int a2, uint32_t *a3, uint32_t *a4, uint32_t *a5, int *a6)
{
  unsigned int v6; // r4
  int v7; // r8
  int v8; // r0
  int v9; // r9
  unsigned int v10; // r12
  unsigned int v11; // r7
  int16_t **v12; // r4
  int16_t *v13; // r1
  int v14; // r2
  int16_t **v16; // r4
  int16_t *v17; // r1
  int v18; // r2

  v6 = *(uint32_t *)(a1 + 4);
  v7 = *(uint8_t *)(a1 + 12);
  v8 = ((v6 >> 4) & 7) + 1;
  *a6 = v8;
  v9 = (v6 >> 9) & 3;
  v10 = v6 >> 4;
  v11 = v6 & 0xF;
  if ( a2 == 7 && ((v6 >> 7) & 3) == 1 )
  {
    v16 = (int16_t **)off_11C8A4;
    v17 = *(int16_t **)off_11C8A4;
    *a3 = dword_11C8BC;
    v18 = *v17;
    *a4 = off_11C8C0;
    if ( v18 < 0 )
    {
      if ( v11 )
      {
        mmio_irq_clear(dword_11C8CC, dword_11C8B4, 2707);
        if ( **v16 >= 0 )
          goto LABEL_3;
        v8 = *a6;
      }
      if ( v8 != 1 )
        mmio_irq_clear(dword_11C8C4, dword_11C8B4, 2709);
    }
  }
  else
  {
    v12 = (int16_t **)off_11C8A4;
    v13 = *(int16_t **)off_11C8A4;
    *a3 = dword_11C8A8;
    v14 = *v13;
    *a4 = dword_11C8AC;
    if ( v14 < 0 )
    {
      if ( (v10 & 4) == 0 || (mmio_irq_clear(dword_11C8C8, dword_11C8B4, 2717), **v12 < 0) )
      {
        if ( v11 > 0xB )
          mmio_irq_clear(dword_11C8B8, dword_11C8B4, 2718);
      }
    }
  }
LABEL_3:
  *a5 = *(uint32_t *)(dword_11C8B0 + 696 * v7 + 12);
  return v9 + 6 * v11;
}

