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

extern uint32_t dword_11B264;
extern uint32_t dword_11B24C;
extern uint32_t off_11B250;
extern uint32_t dword_11B260;
extern uint32_t dword_11B25C;
extern uint32_t off_11B254;
extern uint32_t dword_11B268;
extern uint32_t dword_11B26C;
extern uint32_t off_11B258;

// get_84_entry @ 0x11b0b4, size 406 bytes
int  get_84_entry(int result)
{
  uint32_t *v1; // r5
  int16_t **v2; // r6
  uint32_t *v3; // r4
  int v4; // r3
  int v5; // r2
  int v6; // r7
  int *v7; // r4
  int v8; // r8
  int v9; // r3
  int *v10; // r6
  int v11; // r1
  unsigned int v12; // r3
  int v13; // r9
  int v14; // r4
  int v15; // r10
  int v16; // r3
  int v17; // r3
  int v18; // [sp+4h] [bp-4h] BYREF

  if ( result == 5 )
  {
    v1 = (uint32_t *)dword_11B264;
  }
  else
  {
    result *= 21;
    v1 = (uint32_t *)(dword_11B24C + 4 * result);
  }
  v2 = (int16_t **)off_11B250;
  v3 = (uint32_t *)v1[3];
  if ( **(int16_t **)off_11B250 < 0 && !v3 )
    result = mmio_irq_clear(dword_11B260, dword_11B25C, 3166);
  while ( 1 )
  {
    v4 = v3[9];
    if ( (v4 & 0x200000) != 0 )
      break;
    if ( *(int *)(v3[19] + 72) < 0 )
    {
      v3 = (uint32_t *)*v3;
      if ( v3 )
        continue;
    }
    return result;
  }
  v5 = **v2;
  if ( v5 >= 0 )
  {
    v6 = v3[17];
    v7 = *(int **)(v6 + 4 * ((uint8_t)*(uint32_t *)off_11B254 + 82));
    v8 = v7[19];
LABEL_10:
    v9 = v7[9];
    goto LABEL_11;
  }
  if ( (v4 & 0x380000) == 0x280000 )
  {
    v6 = v3[17];
    v7 = *(int **)(v6 + 4 * ((uint8_t)*(uint32_t *)off_11B254 + 82));
    v8 = v7[19];
  }
  else
  {
    mmio_irq_clear(dword_11B268, dword_11B25C, 3182);
    v6 = v3[17];
    v5 = **v2;
    v7 = *(int **)(v6 + 4 * ((uint8_t)*(uint32_t *)off_11B254 + 82));
    v8 = v7[19];
    if ( v5 >= 0 )
      goto LABEL_10;
  }
  v9 = v7[9];
  if ( (v9 & 0x380000) == 0x380000 )
  {
    mmio_irq_clear(dword_11B26C, dword_11B25C, 3192);
    v9 = v7[9];
  }
  v5 = **v2;
LABEL_11:
  v10 = (int *)off_11B258;
  v11 = *(uint32_t *)off_11B258;
  v7[9] = v9 | 0x380000;
  v12 = v9 & 0xFFC7FEFF | 0x380100;
  if ( *(uint8_t *)(v11 + 1) )
  {
    v15 = v6 + 84;
    v13 = *(uint32_t *)(v6 + 88);
    v14 = *v7;
    *(uint32_t *)(v8 + 68) = v12;
    *(uint32_t *)(v8 + 20) = v6 + 84;
    if ( v5 >= 0 )
      goto LABEL_13;
  }
  else
  {
    v13 = *(uint32_t *)(v6 + 20);
    v14 = *v7;
    *(uint32_t *)(v8 + 68) = v12;
    *(uint32_t *)(v8 + 20) = 0;
    v15 = v6 + 16;
    if ( v5 >= 0 )
      goto LABEL_13;
  }
  if ( !v14 )
    mmio_irq_clear(dword_11B260, dword_11B25C, 3217);
LABEL_13:
  result = context_proc_at_offset44(v14, (int)&v18);
  if ( !result )
    return result;
  v16 = *v10;
  *(uint32_t *)(v15 + 4) = result;
  if ( *(uint8_t *)(v16 + 1) )
  {
    v17 = v18;
    *(uint32_t *)(v18 + 4) = v13;
    if ( v13 )
      return result;
    *v1 = v17;
  }
  else if ( (*(uint32_t *)(v18 + 56) & 0x200000) != 0 )
  {
    *(uint32_t *)(result + 4) = v13;
    if ( v13 )
      return result;
  }
  else
  {
    *(uint32_t *)(v18 + 4) = v13;
    if ( v13 )
      return result;
  }
  if ( (*(uint32_t *)(result + 56) & 0x200000) != 0 )
  {
    v1[1] = result;
    v1[2] = 1;
  }
  else
  {
    v1[1] = 0;
    v1[2] = 0;
  }
  return result;
}

