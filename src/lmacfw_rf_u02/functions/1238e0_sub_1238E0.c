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


extern uint32_t dword_1239F4;
extern uint32_t off_1239F8;
extern uint32_t off_1239FC;
extern uint32_t off_123A00;
extern uint32_t off_123A08;
extern uint32_t off_123A10;
extern uint32_t off_123A14;
extern uint32_t off_123A18;
extern uint32_t off_123A1C;

// wait_for_tx_ready @ 0x1238e0, size 276 bytes
unsigned int wait_for_tx_ready()
{
  int *v0; // r10
  int *v1; // r8
  uint32_t *v2; // r7
  int v3; // r11
  unsigned int v4; // r9
  unsigned int v5; // r4
  int v6; // r5
  int v7; // r6
  int v8; // r2
  int v9; // r0
  int v10; // r2
  unsigned int v11; // r6
  unsigned int v12; // r6
  int v13; // r1
  uint8_t *v14; // r4
  unsigned int result; // r0
  int v16; // r4
  unsigned int v17; // r3
  unsigned int *v18; // r3
  int v19; // [sp+14h] [bp-10h]
  int v20; // [sp+18h] [bp-Ch]

  ke_int_lock((char *)0x90, 0);
  v0 = (int *)off_123A18;
  v1 = (int *)off_123A1C;
  v2 = off_1239F8;
  ke_event_loop(144, 0, dword_1239F4);
  v3 = *(uint32_t *)off_1239FC;
  v19 = *(uint32_t *)off_123A00;
  v4 = *(uint32_t *)off_1239FC - *v0;
  v5 = *(uint32_t *)off_123A00 - *v1;
  v6 = *v2;
  v7 = i32_abs(v4);
  if ( i32_abs(v5) > 50000 )
    v8 = 2;
  else
    v8 = v7 > 50000;
  v20 = v8;
  v9 = i32_abs(-v6);
  v10 = v20;
  v11 = v4 + v5;
  if ( v9 > 50000 )
    v10 = 3;
  if ( v6 == v11 || (v12 = v11 - v6, v12 < v4) || v12 < v5 || v12 < -v6 )
  {
    v13 = 4;
LABEL_8:
    v14 = off_123A08;
    result = dispatch_event_handler_1(
               "\x9A\x88err=%x,fcs_ok=(%x,%x),fcs_err=(%x,%x),other_err=(%x,%x)\r\n",
               v13,
               *v0,
               v3,
               *v1,
               v19,
               *v2,
               0);
    goto LABEL_9;
  }
  v16 = v5 - v6;
  v13 = v10;
  v17 = 100 * v16 / v12;
  result = 10000 * v16 / v12;
  if ( v10 )
    goto LABEL_8;
  v14 = off_123A08;
  if ( !*(uint8_t *)off_123A08 )
    goto LABEL_12;
  result = dispatch_event_handler_1("\x9A\x88%4d / %4d, per:%02d.%02d%%\r\n", v4, v12, v17, result - 100 * v17);
  v18 = (unsigned int *)off_123A14;
  *(uint32_t *)off_123A10 = v4;
  *v18 = v12;
LABEL_9:
  if ( !*v14 )
LABEL_12:
    *v14 = 1;
  *v0 = v3;
  *v1 = v19;
  *v2 = 0;
  return result;
}
