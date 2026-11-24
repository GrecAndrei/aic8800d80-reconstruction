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


extern uint32_t dword_11C510;
extern uint32_t dword_11C528;
extern uint32_t dword_11C534;
extern uint32_t dword_11C538;
extern uint32_t off_11C514;
extern uint32_t off_11C53C;

// bt_conn_tx_schedule @ 0x11c38c, size 388 bytes
int  bt_conn_tx_schedule(int a1, int a2)
{
  uint16_t **v2; // r9
  int v3; // r7
  int v4; // r10
  uint32_t *v7; // r6
  int v8; // r11
  int v9; // r8
  int v10; // r3
  int v11; // r5
  int v12; // r2
  int v13; // r5
  char v15; // r0
  uint16_t *v16; // r1
  unsigned int v17; // r3
  int v18; // r3
  int v19; // r3
  int v20; // r1

  v2 = (uint16_t **)off_11C53C;
  v3 = dword_11C510;
  v4 = dword_11C538;
  v7 = (uint32_t *)(dword_11C510 + 28 * a2);
  if ( **(uint16_t **)off_11C53C < 0 )
  {
    v8 = 8 * a1;
    if ( *(uint32_t *)(dword_11C538 + 224 * a1 + 72)
      && (flash_ctrl_init((int)aVifChanCtxtNul, (int)aChanCtxtLink, 3061), **v2 >= 0) )
    {
      v9 = 8 * a2;
    }
    else
    {
      v9 = 8 * a2;
      if ( *(uint8_t *)(v3 + 28 * a2 + 24) == 255 )
        flash_ctrl_init((int)aCtxtIdxChanCtx, (int)aChanCtxtLink, 3062);
    }
  }
  else
  {
    v8 = 8 * a1;
    v9 = 8 * a2;
  }
  v10 = v3 + 4 * (v9 - a2);
  v11 = v4 + 32 * (v8 - a1);
  v12 = (uint8_t)(*(uint8_t *)(v10 + 25) + 1);
  *(uint32_t *)(v11 + 72) = v7;
  *(uint8_t *)(v11 + 85) = 0;
  *(uint8_t *)(v10 + 25) = v12;
  v13 = off_11C514;
  if ( v12 == 1 )
  {
    v15 = *(uint8_t *)(off_11C514 + 0x5A);
    *(uint8_t *)(v10 + 16) = 1;
    v16 = *v2;
    v17 = (uint8_t)(v15 + 1);
    *(uint8_t *)(v13 + 0x5A) = v17;
    if ( *v16 < 0 && v17 > 2 )
    {
      flash_ctrl_init((int)aChanEnvNbSched_0, (int)aChanCtxtLink, 3082);
      v17 = *(uint8_t *)(v13 + 0x5A);
    }
    if ( v17 == 2 )
    {
      list_init_1((uint32_t *)dword_11C534);
      v19 = dword_11C538;
      v20 = dword_11C538 + 896;
      do
      {
        *(uint8_t *)(v19 + 85) &= ~1u;
        v19 += 224;
      }
      while ( v20 != v19 );
    }
    check_kernel_state(dword_11C528, v7);
    if ( (*(uint8_t *)(v13 + 0x58) & 0xC) != 0 )
    {
      v18 = *(uint32_t *)(v13 + 0x20);
      if ( **v2 < 0 && !v18 )
      {
        flash_ctrl_init((int)aChSwitch, (int)aChanCtxtLink, 3097);
        v18 = 0;
      }
      *(uint32_t *)(v18 + 8) = v7;
      v12 = *(uint8_t *)(v3 + 4 * (v9 - a2) + 25);
    }
    else
    {
      if ( *(uint32_t *)(v13 + 0x2C) )
        *(uint32_t *)(v13 + 0x2C) = v7;
      else
        list_search(v7);
      v12 = *(uint8_t *)(v3 + 4 * (v9 - a2) + 25);
    }
  }
  check_interrupt_flag(
    256,
    "chan link:%d,%d,%d,%d\r\n",
    v12,
    a2,
    *(uint8_t *)(v13 + 0x5A),
    *(uint8_t *)(v13 + 0x5B));
  return bt_conn_find_by_ptr((int)v7);
}
