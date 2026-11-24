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


extern uint32_t dword_138578;
extern uint32_t dword_13857C;
extern uint32_t off_138564;
extern uint32_t off_138568;
extern uint32_t off_13856C;
extern uint32_t off_138570;
extern uint32_t off_138574;

// sub_1383DC @ 0x1383dc, size 392 bytes
int  sub_1383DC(char a1)
{
  int v2; // r3
  int v3; // r3
  int result; // r0
  int v5; // r1
  uint32_t *v6; // r3
  int v7; // r3
  int v8; // r3
  int *v9; // r2
  int v10; // r3
  int v11; // r3
  uint32_t *v12; // r4
  uint32_t *v13; // r2
  uint32_t *v14; // r0
  int v15; // r3
  int v16; // r3
  uint32_t *v17; // r4
  uint32_t *v18; // r2
  uint32_t *v19; // r0
  int v20; // r3
  int v21; // r3

  *(uint32_t *)off_138564 = 53;
  __dsb(0xFu);
  __isb(0xFu);
  do
  {
    v2 = 16;
    do
      --v2;
    while ( v2 );
  }
  while ( (*(uint32_t *)off_138568 & 1) != 0 );
  v3 = *(uint32_t *)off_13856C;
  result = (*(uint32_t *)off_13856C >> 6) & 1;
  if ( (a1 & 2) == 0 )
  {
    v5 = (a1 & 1) != 0 ? (uint8_t)v3 | 0x40 : *(uint32_t *)off_13856C & 0xBF;
    if ( v5 != (uint8_t)v3 )
    {
      if ( *(int *)off_138570 >= 0 )
      {
        v6 = off_138564;
        *(uint32_t *)off_138574 = dword_138578;
        *v6 = 159;
        __dsb(0xFu);
        __isb(0xFu);
        do
        {
          v7 = 16;
          do
            --v7;
          while ( v7 );
        }
        while ( (*(uint32_t *)off_138568 & 1) != 0 );
        *(uint32_t *)off_138570 = (*(uint32_t *)off_13856C << 16) & 0xFF0000
                              | (uint16_t)((uint16_t)*(uint32_t *)off_13856C << 8)
                              | (uint8_t)*(uint32_t *)off_13856C
                              | 0x80000000;
      }
      *(uint32_t *)off_138564 = 5;
      __dsb(0xFu);
      __isb(0xFu);
      do
      {
        v8 = 16;
        do
          --v8;
        while ( v8 );
      }
      while ( (*(uint32_t *)off_138568 & 1) != 0 );
      v9 = (int *)off_138574;
      v10 = *(uint32_t *)off_13856C;
      *(uint32_t *)off_138574 = dword_13857C;
      __dsb(0xFu);
      *++v9 = (uint8_t)v10;
      __dsb(0xFu);
      __isb(0xFu);
      *v9 = v5;
      __dsb(0xFu);
      *(uint32_t *)off_138564 = 6;
      __dsb(0xFu);
      __isb(0xFu);
      do
      {
        v11 = 16;
        do
          --v11;
        while ( v11 );
      }
      while ( (*(uint32_t *)off_138568 & 1) != 0 );
      v12 = off_138564;
      v13 = off_138568;
      v14 = off_13856C;
      do
      {
        *v12 = 5;
        __dsb(0xFu);
        __isb(0xFu);
        do
        {
          v15 = 16;
          do
            --v15;
          while ( v15 );
        }
        while ( (*v13 & 1) != 0 );
      }
      while ( (*v14 & 2) == 0 );
      *(uint32_t *)off_138564 = 1;
      __dsb(0xFu);
      __isb(0xFu);
      do
      {
        v16 = 16;
        do
          --v16;
        while ( v16 );
      }
      while ( (*(uint32_t *)off_138568 & 1) != 0 );
      v17 = off_138564;
      v18 = off_138568;
      v19 = off_13856C;
      do
      {
        *v17 = 5;
        __dsb(0xFu);
        __isb(0xFu);
        do
        {
          v20 = 16;
          do
            --v20;
          while ( v20 );
        }
        while ( (*v18 & 1) != 0 );
      }
      while ( (*v19 & 1) != 0 );
      *(uint32_t *)off_138564 = 53;
      __dsb(0xFu);
      __isb(0xFu);
      do
      {
        v21 = 16;
        do
          --v21;
        while ( v21 );
      }
      while ( (*(uint32_t *)off_138568 & 1) != 0 );
      return (*(uint32_t *)off_13856C >> 6) & 1;
    }
  }
  return result;
}
