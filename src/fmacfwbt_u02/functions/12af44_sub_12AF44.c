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

extern uint32_t dword_12B018;
extern uint32_t off_12B01C;
extern uint32_t dword_12B024;
extern uint32_t off_12B020;

// rf_tx_power_configure @ 0x12af44, size 212 bytes
int  rf_tx_power_configure(int a1)
{
  int v1; // r7
  int v3; // r5
  int v4; // r4
  int v5; // r9
  int v6; // r8
  int **v7; // r0
  int v8; // r12
  int v9; // r1
  int v10; // r4
  unsigned int v11; // r2
  unsigned int v12; // r4
  int v13; // cc
  int v14; // r3
  int v15; // r1

  v1 = dword_12B018;
  v3 = *((uint32_t *)off_12B01C + 4);
  bt_adv_check((uint8_t *)(dword_12B018 + 1320 * *(uint8_t *)(a1 + 28)));
  if ( *(uint8_t *)(a1 + 31) )
  {
    v4 = *(uint32_t *)(a1 + 16) > 2u;
    v5 = *(uint8_t *)(a1 + 28);
    if ( *(uint32_t *)(a1 + 20) > 2u )
      v4 |= 2u;
    if ( (*(uint8_t *)(a1 + 29) ^ v4) << 30 )
      bt_dev_check_ready(*(uint8_t *)(a1 + 28), v4);
    v6 = *(uint8_t *)(a1 + 28);
    *(uint8_t *)(a1 + 29) = v4;
    v7 = *(int ***)(v1 + 1320 * v5 + 240);
    if ( v7 )
    {
      v8 = dword_12B024;
      do
      {
        v9 = *((uint8_t *)v7 + 35);
        v7 = (int **)*v7;
        v10 = 3 * v9 + v8;
        v11 = *(uint8_t *)(v10 + 1);
        v12 = *(uint8_t *)(v10 + 2);
        v13 = v11 > 2;
        v14 = 3 * v9;
        if ( v11 > 2 )
          LOBYTE(v11) = 1;
        v15 = v8 + v14;
        if ( !v13 )
          LOBYTE(v11) = 0;
        if ( v12 > 2 )
          LOBYTE(v11) = v11 | 2;
        *(uint8_t *)(v8 + v14) = v11;
        *(uint8_t *)(v15 + 1) = 0;
        *(uint8_t *)(v15 + 2) = 0;
      }
      while ( v7 );
    }
  }
  else
  {
    v6 = *(uint8_t *)(a1 + 28);
  }
  *(uint8_t *)(a1 + 31) = *((uint32_t *)off_12B020 + 10) == *(uint32_t *)(v1 + 1320 * v6 + 72);
  *(uint32_t *)(a1 + 16) = 0;
  *(uint32_t *)(a1 + 20) = 0;
  return ke_event_lock(a1, v3 + 102400);
}

