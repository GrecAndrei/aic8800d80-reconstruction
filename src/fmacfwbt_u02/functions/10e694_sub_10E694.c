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

extern uint32_t off_10E834;
extern uint32_t off_10E838;
extern uint32_t off_10E83C;
extern uint32_t dword_10E840;
extern uint32_t dword_10E844;
extern uint32_t dword_10E848;

// gpio_set_pin_mode @ 0x10e694, size 416 bytes
int  gpio_set_pin_mode(unsigned int a1, unsigned int a2, unsigned int *a3)
{
  unsigned int v3; // r4
  unsigned int *v4; // r6
  unsigned int *v5; // r5
  int16_t *v8; // r5
  int v9; // r10
  int v10; // r2
  unsigned int *v11; // r7
  unsigned int *v12; // r6
  unsigned int v13; // r11
  int v14; // r8
  int v15; // r9
  int v16; // r2
  int v17; // r0
  int v18; // r2
  int v20; // r5
  unsigned int v21; // [sp+Ch] [bp-20h]
  unsigned int v22; // [sp+10h] [bp-1Ch]
  int v23; // [sp+14h] [bp-18h]
  unsigned int v24; // [sp+18h] [bp-14h]
  unsigned int v25; // [sp+1Ch] [bp-10h]

  v4 = (unsigned int *)off_10E834;
  v5 = (unsigned int *)off_10E838;
  *(uint32_t *)off_10E834 = *(uint32_t *)off_10E834 & 0xFFFFFFF8 | a1 & 7;
  *v5 = ((uint16_t)a1 << 12) & 0x7000 | *v5 & 0xFFFF8FFF;
  *v4 = (8 * a2) & 0x78 | *v4 & 0xFFFFFF87;
  *v5 = (a2 << 15) & 0x78000 | *v5 & 0xFFF87FFF;
  v8 = (int16_t *)off_10E83C;
  v9 = radio_setup();
  ke_event_schedule(dword_10E840, a1, a2);
  v10 = *v8;
  if ( v10 > v9 )
  {
    v23 = 1;
  }
  else
  {
    if ( v10 >= v9 )
    {
      v20 = 0;
      goto LABEL_9;
    }
    v23 = -1;
  }
  v3 = a2;
  v11 = (unsigned int *)off_10E834;
  v12 = (unsigned int *)off_10E838;
  v21 = a1;
  v22 = a1 + a2;
  v13 = a1;
  v14 = 7;
  v20 = 0;
  while ( 1 )
  {
    v24 = v13;
    v20 += v23;
    v13 = __usat(3u, v21 + v20);
    *v11 = *v11 & 0xFFFFFFF8 | v13;
    *v12 = *v12 & 0xFFFF8FFF | (v13 << 12);
    v25 = v3;
    v3 = __usat(4u, v22 + v20 - v13);
    *v11 = *v11 & 0xFFFFFF87 | (8 * v3);
    *v12 = *v12 & 0xFFF87FFF | (v3 << 15);
    v15 = v9;
    v9 = radio_setup();
    ke_event_schedule(dword_10E844, v13, v3);
    v16 = *(int16_t *)off_10E83C;
    v17 = v9 - v16;
    v18 = v15 - v16;
    if ( v18 * v17 <= 0 )
      break;
    if ( !--v14 )
      goto LABEL_9;
  }
  if ( v18 < 0 )
    v18 = -v18;
  if ( v17 < 0 )
    v17 = -v17;
  if ( v18 <= v17 )
  {
    v3 = v25;
    *v11 = *v11 & 0xFFFFFFF8 | v24 & 7;
    *v12 = (v24 << 12) & 0x7000 | *v12 & 0xFFFF8FFF;
    *v11 = (8 * v25) & 0x78 | *v11 & 0xFFFFFF87;
    v13 = v24;
    *v12 = (v25 << 15) & 0x78000 | *v12 & 0xFFF87FFF;
  }
  ke_event_schedule(dword_10E848, v20, v13 - v21);
LABEL_9:
  *a3 = v3;
  return v20;
}

