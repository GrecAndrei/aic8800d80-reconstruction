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

extern uint32_t off_11B9B0;
extern uint32_t off_11B9B4;
extern uint32_t off_11B9B8;
extern uint32_t off_11B9BC;
extern uint32_t off_11B9C8;
extern uint32_t off_11B9CC;
extern uint32_t off_11B9D4;
extern uint32_t dword_11B9DC;
extern uint32_t dword_11B9D8;
extern uint32_t off_11B9D0;
extern uint32_t off_11B9C0;
extern uint32_t dword_11B9C4;

// sub_11B80C @ 0x11b80c, size 420 bytes
int sub_11B80C()
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
  int v11; // r1
  unsigned int v13; // r3
  int v14; // r2
  int v15; // r3

  v0 = off_11B9B0;
  v1 = off_11B9B4;
  v2 = *((uint32_t *)off_11B9B0 + 11);
  sub_102908((uint8_t *)(v2 + 4), 0);
  sub_11D9F8(*(char *)(v2 + 12));
  *(uint32_t *)off_11B9B8 = v1[*(uint8_t *)(v2 + 4) + 5];
  if ( *(uint8_t *)(v2 + 24) == 3 )
  {
    v7 = v0[10];
    if ( !v7 )
    {
      v0[10] = v2;
      v0[11] = 0;
      *(uint8_t *)(v2 + 16) = 4;
      if ( *((uint8_t *)v0 + 90) || !*((uint8_t *)off_11B9BC + 143) )
        goto LABEL_31;
      goto LABEL_29;
    }
    v6 = 0;
    goto LABEL_7;
  }
  v3 = (uint8_t *)sub_11DDF0(68, 4, 0, 4);
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
  sub_11DE50(v3);
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
    if ( *((uint8_t *)v0 + 90) && !v6 || !*((uint8_t *)off_11B9BC + 143) )
    {
      if ( v8 != 3 )
        return sub_1188F4();
      goto LABEL_31;
    }
    goto LABEL_29;
  }
  if ( *((uint8_t *)off_11B9BC + 143) )
  {
LABEL_29:
    sub_115DBC();
    v13 = *(uint8_t *)(v2 + 24);
    if ( v13 <= 2 )
      goto LABEL_10;
    if ( v13 != 3 )
      return sub_1188F4();
LABEL_31:
    v14 = **(int16_t **)off_11B9C8;
    v15 = v1[1] | 0x2200;
    *(uint32_t *)off_11B9CC = 0;
    v1[1] = v15;
    if ( v14 < 0 && *(uint32_t *)off_11B9D4 << 28 )
    {
      sub_1219F4(dword_11B9DC, dword_11B9D8, 472);
      v15 = v1[1];
    }
    *(uint32_t *)off_11B9D0 = v15 | *v1;
    sub_11DED8(141, 2, 255);
    return sub_1188F4();
  }
LABEL_10:
  sub_11B6F0();
  v9 = *((uint32_t *)off_11B9C0 + 2);
  if ( v9 )
  {
    v10 = dword_11B9C4;
    do
    {
      while ( *(uint32_t *)(v9 + 72) != v2 )
      {
        v9 = *(uint32_t *)v9;
        if ( !v9 )
          goto LABEL_15;
      }
      *(uint8_t *)(v10 + 32 * *(uint8_t *)(v9 + 95) + 31) = 1;
      sub_1182C8(v9);
      v9 = *(uint32_t *)v9;
    }
    while ( v9 );
  }
LABEL_15:
  v11 = *(uint16_t *)(v2 + 14);
  if ( v11 != 255 )
  {
    sub_11DED8(62, v11, 0);
    *(uint16_t *)(v2 + 14) = 255;
  }
  return sub_1188F4();
}

