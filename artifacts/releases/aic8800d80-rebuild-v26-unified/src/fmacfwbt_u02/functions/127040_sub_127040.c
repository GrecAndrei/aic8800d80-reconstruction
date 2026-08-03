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

extern uint32_t off_127224;
extern uint32_t off_127228;
extern uint32_t off_12722C;
extern uint32_t off_127230;
extern uint32_t off_127244;
extern uint32_t off_127248;
extern uint32_t off_127260;
extern uint32_t dword_127268;
extern uint32_t dword_127264;
extern uint32_t off_12724C;
extern uint32_t off_127250;
extern uint32_t off_127254;
extern uint32_t off_127258;
extern uint32_t dword_12725C;
extern uint32_t off_12723C;
extern uint32_t off_127240;
extern uint32_t off_127234;
extern uint32_t dword_127238;

// sub_127040 @ 0x127040, size 484 bytes
int sub_127040()
{
  uint32_t *v0; // r5
  uint32_t *v1; // r6
  int v2; // r4
  uint8_t *v3; // r0
  int v4; // r3
  int16_t v5; // r3
  BOOL v6; // r7
  int v7; // r3
  unsigned int v8; // r3
  int v9; // r5
  int v10; // r7
  unsigned int *v11; // r2
  uint32_t *v12; // r4
  int v13; // r1
  int v14; // r3
  unsigned int v16; // r3
  int v17; // r2
  int v18; // r3
  int v19; // r3
  uint32_t *v20; // r3
  int v21; // r0
  int v22; // r2
  uint16_t *v23; // r1

  v0 = off_127224;
  v1 = off_127228;
  v2 = *((uint32_t *)off_127224 + 11);
  sub_102898((uint16_t *)(v2 + 4), 0);
  sub_12C6AC(*(char *)(v2 + 12));
  *(uint32_t *)off_12722C = v1[*(uint8_t *)(v2 + 4) + 5];
  if ( *(uint8_t *)(v2 + 24) == 3 )
  {
    v7 = v0[10];
    if ( !v7 )
    {
      v0[10] = v2;
      v0[11] = 0;
      *(uint8_t *)(v2 + 16) = 4;
      if ( *((uint8_t *)v0 + 90) || !*((uint8_t *)off_127230 + 511) )
        goto LABEL_29;
      goto LABEL_27;
    }
    v6 = 0;
    goto LABEL_7;
  }
  v3 = (uint8_t *)sub_12CB54(68, 13, 0, 4);
  v4 = *(uint8_t *)(v2 + 24);
  *v3 = v4;
  if ( v4 == 4 )
  {
    v5 = *(uint16_t *)(v2 + 14);
    if ( v5 )
      LOBYTE(v5) = 1;
  }
  else
  {
    LOBYTE(v5) = 0;
  }
  v6 = 0;
  v3[1] = v5;
  v3[3] = 0;
  v3[2] = *(uint8_t *)(v2 + 26);
  sub_12CBB4(v3);
  v7 = v0[10];
  if ( v7 )
  {
    if ( *(uint8_t *)(v2 + 24) == 4
      && *(uint16_t *)(v7 + 4) == *(uint16_t *)(v2 + 4)
      && *(uint8_t *)(v7 + 13) == *(uint8_t *)(v2 + 13)
      && *(uint16_t *)(v7 + 6) == *(uint16_t *)(v2 + 6)
      && *(uint16_t *)(v7 + 8) == *(uint16_t *)(v2 + 8) )
    {
      v6 = *(uint16_t *)(v7 + 10) == *(uint16_t *)(v2 + 10);
    }
LABEL_7:
    *(uint8_t *)(v7 + 16) = 1;
    v8 = *(uint8_t *)(v2 + 24);
    goto LABEL_8;
  }
  v6 = 0;
  v8 = *(uint8_t *)(v2 + 24);
LABEL_8:
  v0[10] = v2;
  v0[11] = 0;
  *(uint8_t *)(v2 + 16) = 4;
  if ( v8 > 2 )
  {
    if ( *((uint8_t *)v0 + 90) && !v6 || !*((uint8_t *)off_127230 + 511) )
    {
      if ( v8 == 3 )
        goto LABEL_29;
      goto LABEL_22;
    }
  }
  else if ( !*((uint8_t *)off_127230 + 511) )
  {
    goto LABEL_10;
  }
LABEL_27:
  sub_117EF8();
  v16 = *(uint8_t *)(v2 + 24);
  if ( v16 > 2 )
  {
    if ( v16 == 3 )
    {
LABEL_29:
      v17 = **(int16_t **)off_127244;
      v18 = v1[1] | 0x2200;
      *(uint32_t *)off_127248 = 0;
      v1[1] = v18;
      if ( v17 < 0 && *(uint32_t *)off_127260 << 28 )
      {
        sub_12F6C4(dword_127268, dword_127264, 472);
        v18 = v1[1];
      }
      v19 = v18 | *v1;
      *(uint32_t *)off_12724C = v19;
      sub_12CC38(141, 2, 255, v19);
      if ( *((uint8_t *)off_127250 + 3851) == 1 && !*((uint8_t *)off_127254 + 10) )
      {
        v20 = *(uint32_t **)off_127258;
        if ( *(uint32_t *)off_127258 )
        {
          v21 = dword_12725C;
          do
          {
            v22 = v20[15];
            if ( v22 >= 0 )
            {
              v23 = (uint16_t *)v20[4];
              if ( v23 )
              {
                if ( (*v23 & 0xFC) == 0x40 )
                  v20[15] = v22 | v21;
              }
            }
            v20 = (uint32_t *)v20[1];
          }
          while ( v20 );
        }
      }
    }
LABEL_22:
    v11 = (unsigned int *)off_12723C;
    v12 = off_127240;
    v13 = *(uint32_t *)off_12723C;
    v14 = *((uint32_t *)off_127240 + 1) | 2;
    *((uint8_t *)v0 + 92) = (*(uint32_t *)off_12723C & 4) != 0;
    *v11 = v13 & 0xFFFFFFFB;
    v12[1] = v14;
    return sub_12141C();
  }
LABEL_10:
  sub_126E94();
  v9 = *((uint32_t *)off_127234 + 2);
  if ( v9 )
  {
    v10 = dword_127238;
    do
    {
      while ( *(uint32_t *)(v9 + 72) != v2 )
      {
        v9 = *(uint32_t *)v9;
        if ( !v9 )
          return sub_12141C();
      }
      *(uint8_t *)(v10 + 32 * *(uint8_t *)(v9 + 107) + 31) = 1;
      sub_12054C(v9);
      v9 = *(uint32_t *)v9;
    }
    while ( v9 );
  }
  return sub_12141C();
}

