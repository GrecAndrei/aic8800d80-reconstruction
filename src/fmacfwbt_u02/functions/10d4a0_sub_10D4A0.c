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

extern uint32_t off_10D58C;
extern uint32_t off_10D590;
extern uint32_t off_10D5B8;
extern uint32_t off_10D5BC;
extern uint32_t dword_10D5C0;
extern uint32_t off_10D598;
extern uint32_t off_10D59C;
extern uint32_t off_10D5A0;
extern uint32_t off_10D594;
extern uint32_t off_10D5A4;
extern uint32_t off_10D5A8;
extern uint32_t off_10D5C8;
extern uint32_t off_10D5AC;
extern uint32_t off_10D5B0;
extern uint32_t off_10D5B4;
extern uint32_t off_10D5C4;

// event_loop @ 0x10d4a0, size 236 bytes
void event_loop()
{
  int v0; // r3
  uint32_t *v1; // r5
  uint32_t *v2; // r0
  uint32_t *v3; // r1
  uint32_t *v4; // r4
  uint32_t *v5; // r0
  unsigned int v6; // r3
  unsigned int v7; // r2
  unsigned int v8; // r3
  int v9; // r7
  int v10; // r0
  int v11; // r3
  uint32_t *v12; // r2
  uint32_t *v13; // r4
  int *v14; // r5
  int *v15; // r6
  uint32_t *v16; // r0
  unsigned int *v17; // r1
  uint32_t *v18; // r5
  uint32_t *v19; // r2
  int v20; // r0
  uint32_t *v21; // r2
  uint32_t *v22; // r3
  int v23; // r0

  v0 = *((uint32_t *)off_10D58C + 43);
  if ( v0 >= 0 )
  {
    if ( *(uint32_t *)off_10D590 )
    {
      v21 = off_10D5B8;
      v22 = off_10D5BC;
      v23 = dword_10D5C0;
      *(uint32_t *)off_10D598 = 1;
      *(uint32_t *)(v21[2] + 124) = v23;
      *v22 = 0x8000;
    }
  }
  else if ( *(uint32_t *)off_10D590 )
  {
    v1 = off_10D598;
    v2 = off_10D59C;
    v3 = off_10D5A0;
    *(uint32_t *)off_10D594 = 0;
    *v1 = 0;
    *v2 = 1;
    v4 = off_10D5A4;
    v5 = off_10D5A8;
    *v3 |= 0x100u;
    *v4 = 3;
    v6 = v0 & 0x7FFFFFFF;
    if ( (v5[20] & 0x20) != 0 )
    {
      v7 = *(uint32_t *)off_10D5C8;
      if ( v6 < *(uint32_t *)off_10D5C8 >> 4 )
        goto LABEL_5;
    }
    else
    {
      v7 = 2 * *(uint32_t *)off_10D5AC;
      if ( v6 < v7 >> 4 )
      {
LABEL_5:
        v8 = v7 / v6;
        v9 = (uint8_t)(v8 >> 4);
        v10 = ((v8 >> 1) & 7) + 16 * ((v8 & 0xF) - ((v8 >> 1) & 7));
        v11 = (uint8_t)(v8 >> 12);
LABEL_6:
        v12 = off_10D5A4;
        v13 = off_10D598;
        v14 = (int *)off_10D5B0;
        v15 = (int *)off_10D5B4;
        *(uint32_t *)off_10D5A4 |= 0x80u;
        *v15 = v9;
        *v13 = v11;
        *v14 = v10;
        v16 = off_10D594;
        v17 = (unsigned int *)off_10D59C;
        v18 = off_10D5B8;
        *v12 &= ~0x80u;
        *v16 = 7;
        v19 = off_10D5BC;
        v20 = dword_10D5C0;
        *v17 = *v17 & 0xFFFFFE00 | 1;
        *v13 = 1;
        *(uint32_t *)(v18[2] + 124) = v20;
        *v19 = 0x8000;
        goto LABEL_7;
      }
    }
    v10 = 0;
    v11 = 0;
    v9 = 1;
    goto LABEL_6;
  }
LABEL_7:
  *(uint32_t *)off_10D5C4 = 1;
}

