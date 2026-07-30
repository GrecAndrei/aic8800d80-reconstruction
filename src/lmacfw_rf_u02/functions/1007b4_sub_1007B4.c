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

extern uint32_t off_1008E4;
extern uint32_t dword_1008E8;
extern uint32_t off_1008F8;
extern uint32_t dword_1008FC;
extern uint32_t off_1008F4;
extern uint32_t dword_100900;
extern uint32_t dword_100908;
extern uint32_t off_100904;
extern uint32_t off_1008EC;
extern uint32_t dword_1008F0;

// sub_1007B4 @ 0x1007b4, size 302 bytes
int  sub_1007B4(int a1, unsigned int a2, uint32_t *a3)
{
  int v4; // r4
  int v5; // r6
  uint8_t *v6; // r7
  int v8; // r12
  int v9; // r0
  int v10; // r12
  char *v11; // r7
  int v12; // r0
  int v13; // r3
  int v14; // t1
  int v15; // nf
  int v16; // r2
  char *v17; // r7
  uint8_t *v18; // r2
  int i; // r0
  int v20; // t1
  int v21; // r3
  int v22; // zf

  if ( !a1 )
  {
    if ( a2 > 0x97B )
    {
      v4 = *(uint32_t *)off_1008E4;
      if ( a2 > 0x994 )
        a1 = 2;
      else
        a1 = 1;
      if ( v4 )
        goto LABEL_4;
    }
    else
    {
      v4 = *(uint32_t *)off_1008E4;
      if ( *(uint32_t *)off_1008E4 )
      {
LABEL_4:
        v4 = 0;
LABEL_5:
        v5 = dword_1008E8;
        goto LABEL_6;
      }
    }
    v10 = *(uint8_t *)off_1008F8;
    v11 = (char *)dword_1008FC;
    v12 = a1 + *(uint32_t *)off_1008F4;
    v13 = v4;
    do
    {
      v14 = *v11++;
      v16 = (*(uint8_t *)(v12 + 3 * v13) + v14 + v10) << 31;
      v15 = ((*(uint8_t *)(v12 + 3 * v13) + v14 + v10) & 1) != 0;
      if ( ((*(uint8_t *)(v12 + 3 * v13) + v14 + v10) & 1) != 0 )
        v16 = 1 << v13;
      ++v13;
      if ( v15 )
        v4 |= v16;
    }
    while ( v13 != 3 );
    goto LABEL_5;
  }
  if ( a2 > 0x1666 )
  {
    v9 = 1920;
    v8 = 5;
  }
  else if ( a2 > 0x1616 )
  {
    v9 = 1536;
    v8 = 4;
  }
  else if ( a2 > 0x15C6 )
  {
    v9 = 1152;
    v8 = 3;
  }
  else if ( a2 > 0x1571 )
  {
    v9 = 768;
    v8 = 2;
  }
  else
  {
    v8 = a2 > 0x1486;
    if ( a2 <= 0x1486 )
      v9 = 0;
    else
      v9 = 384;
  }
  v4 = *(uint32_t *)off_1008E4;
  v5 = dword_100900 + v9;
  if ( *(uint32_t *)off_1008E4 )
  {
    v4 = 0;
  }
  else
  {
    v17 = (char *)dword_100908;
    v18 = (uint8_t *)(*(uint32_t *)off_100904 + v8);
    for ( i = 0; i != 3; ++i )
    {
      v20 = *v17++;
      v21 = *v18 + v20 + *((uint8_t *)off_1008F8 + 1);
      v22 = (v21 & 1) == 0;
      if ( (v21 & 1) != 0 )
        v21 = 1 << i;
      if ( !v22 )
        v4 |= v21;
      v18 += 6;
    }
  }
LABEL_6:
  v6 = off_1008EC;
  if ( *(char *)off_1008EC > 0 )
  {
    msg_parse(dword_1008F0, a2);
    --*v6;
  }
  *a3 = v4;
  return v5;
}

