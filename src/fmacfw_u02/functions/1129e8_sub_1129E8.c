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


extern uint32_t dword_112C40;
extern uint32_t dword_112C4C;
extern uint32_t dword_112C50;
extern uint32_t dword_112C5C;
extern uint32_t dword_112C60;
extern uint32_t off_112C30;
extern uint32_t off_112C34;
extern uint32_t off_112C38;
extern uint32_t off_112C3C;
extern uint32_t off_112C44;
extern uint32_t off_112C48;
extern uint32_t off_112C54;
extern uint32_t off_112C58;

// mmio_read_flag @ 0x1129e8, size 582 bytes
int mmio_read_flag()
{
  uint8_t *v0; // r3
  uint32_t *v1; // r4
  uint32_t *v2; // r3
  int *v3; // r1
  int v4; // r5
  uint32_t *v5; // r4
  int i; // r0
  int v7; // r3
  uint32_t *v8; // r3
  int *v9; // r1
  int v10; // lr
  int v11; // r12
  int *v12; // r6
  int v13; // r5
  int v14; // r0
  int *v15; // r2
  uint32_t *v16; // r4
  uint32_t *v17; // r3
  uint32_t *v18; // r3
  int *v19; // r0
  int result; // r0
  int ( *v21)(uint32_t); // r3
  uint16_t *v22; // r2
  int v23; // r4
  uint32_t *v24; // r1
  uint32_t *v25; // r3
  uint32_t *v26; // r2
  uint32_t *v27; // r3

  v0 = off_112C34;
  v1 = off_112C38;
  *(uint8_t *)off_112C30 = 2;
  *v0 = 0;
  v1[896] &= ~1u;
  v1[513] &= ~1u;
  table_lookup_wrapper();
  if ( (v1[6] & 0x80) != 0 )
    v1[6] &= ~0x80u;
  v2 = off_112C38;
  *((uint32_t *)off_112C38 + 513) |= 0x200u;
  while ( (v2[5] & 0x80) == 0 )
    ;
  v3 = (int *)off_112C3C;
  v4 = dword_112C40;
  v5 = off_112C3C;
  for ( i = 1; ; ++i )
  {
    if ( i == 1 )
    {
      if ( (*v5 & 0x80008000) != 0 )
        *v5 |= v4;
      goto LABEL_11;
    }
    v7 = *v3;
    if ( (*v3 & 0x80008000) != 0 )
    {
      *v3 |= v4;
      if ( v7 < 0 )
      {
        v3[2] = 2;
        *v3 |= 0x40000000u;
        while ( (v3[2] & 2) == 0 )
          ;
      }
      if ( (v7 & 0x8000) == 0 )
        *v3 &= ~0x8000u;
    }
    if ( i == 6 )
      break;
LABEL_11:
    v3 += 8;
  }
  v8 = off_112C38;
  *((uint32_t *)off_112C38 + 513) |= 0x400u;
  v8[513] |= 0x80u;
  while ( (v8[5] & 0x40) == 0 )
    ;
  v9 = (int *)off_112C44;
  v10 = dword_112C60;
  v11 = dword_112C40;
  v12 = (int *)off_112C44;
  v13 = 1;
  while ( 2 )
  {
    if ( v13 == 1 )
    {
      v14 = *v12;
      if ( (*v12 & 0x80008000) != 0 )
      {
        v16 = (uint32_t *)v10;
        v15 = v12;
LABEL_20:
        *v16 = 64;
        *v15 |= v11;
        if ( v14 < 0 )
        {
          if ( (v14 & 0x20000) == 0 )
          {
            while ( (*v16 & 0x40) == 0 )
              ;
            *v16 = 64;
          }
          *v16 = 2;
          *v15 |= 0x40000000u;
          while ( (*v16 & 2) == 0 )
            ;
        }
        if ( (v14 & 0x8000) == 0 )
          *v15 &= ~0x8000u;
        goto LABEL_23;
      }
      goto LABEL_24;
    }
    v14 = *v9;
    v15 = v9;
    if ( (*v9 & 0x80008000) != 0 )
    {
      v16 = v9 + 2;
      goto LABEL_20;
    }
LABEL_23:
    if ( v13 != 6 )
    {
LABEL_24:
      ++v13;
      v9 += 8;
      continue;
    }
    break;
  }
  v17 = off_112C38;
  *((uint32_t *)off_112C38 + 4) = 1072;
  while ( (v17[4] & 0x30) != 0 )
    ;
  v17[513] |= 0x100u;
  v17[519] = 65537;
  v17[517] = 41;
  v17[516] = 9;
  v17[6] |= 0xC0000u;
  if ( (v17[18] & 0x80000) != 0 )
  {
    v22 = off_112C58;
    v23 = dword_112C5C;
    v24 = off_112C38;
    v17[9] = 285;
    v17[10] = v23;
    *v22 = 318;
    v17[513] |= 0x80u;
    while ( (v24[5] & 0x40) == 0 )
      ;
    while ( *((int *)off_112C38 + 4) >= 0 )
      ;
    v25 = off_112C38;
    *((uint32_t *)off_112C38 + 4) = 1056;
    while ( (v25[4] & 0x20) != 0 )
      ;
    v26 = off_112C38;
    v25[513] |= 0x100u;
    v25[513] |= 0x200u;
    while ( (v26[5] & 0x80) == 0 )
      ;
    v27 = off_112C38;
    v26[4] |= 0x10u;
    while ( (v27[4] & 0x10) != 0 )
      ;
    v27[513] |= 0x400u;
  }
  v18 = off_112C48;
  v19 = (int *)dword_112C4C;
  *((uint32_t *)off_112C38 + 512) &= 0xFFFFF80F;
  v18[1] = 0;
  v18[2] = 0;
  *(uint8_t *)v18 = 0;
  memset(v19, 0, 0x50u);
  memset((int *)dword_112C50, 0, 0x50u);
  result = mmio_sync();
  v21 = *((int ( **)(uint32_t))off_112C54 + 8);
  if ( v21 )
    return v21(0);
  return result;
}
