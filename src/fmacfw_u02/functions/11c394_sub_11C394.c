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

extern uint32_t off_11C464;
extern uint32_t dword_11C47C;
extern uint32_t dword_11C480;
extern uint32_t dword_11C48C;
extern uint32_t dword_11C474;
extern uint32_t dword_11C484;
extern uint32_t dword_11C468;
extern uint32_t dword_11C46C;
extern uint32_t dword_11C488;
extern uint32_t dword_11C478;
extern uint32_t dword_11C470;

// get_channel_number @ 0x11c394, size 208 bytes
unsigned int  get_channel_number(int a1, int a2, uint32_t *a3, uint32_t *a4, uint32_t *a5, int *a6)
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
    v16 = (int16_t **)off_11C464;
    v17 = *(int16_t **)off_11C464;
    *a3 = dword_11C47C;
    v18 = *v17;
    *a4 = dword_11C480;
    if ( v18 < 0 )
    {
      if ( v11 )
      {
        mmio_clear_register(dword_11C48C, dword_11C474, 2707);
        if ( **v16 >= 0 )
          goto LABEL_3;
        v8 = *a6;
      }
      if ( v8 != 1 )
        mmio_clear_register(dword_11C484, dword_11C474, 2709);
    }
  }
  else
  {
    v12 = (int16_t **)off_11C464;
    v13 = *(int16_t **)off_11C464;
    *a3 = dword_11C468;
    v14 = *v13;
    *a4 = dword_11C46C;
    if ( v14 < 0 )
    {
      if ( (v10 & 4) == 0 || (mmio_clear_register(dword_11C488, dword_11C474, 2717), **v12 < 0) )
      {
        if ( v11 > 0xB )
          mmio_clear_register(dword_11C478, dword_11C474, 2718);
      }
    }
  }
LABEL_3:
  *a5 = *(uint32_t *)(dword_11C470 + 696 * v7 + 12);
  return v9 + 6 * v11;
}

