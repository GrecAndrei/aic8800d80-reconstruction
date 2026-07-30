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

extern uint32_t off_11F9C8;
extern uint32_t off_11F9CC;
extern uint32_t dword_11F9D0;
extern uint32_t off_11F9D4;
extern uint32_t off_11F9D8;
extern uint32_t off_11F9DC;
extern uint32_t off_11F9E0;
extern uint32_t off_11F9E4;
extern uint32_t dword_11F9E8;
extern uint32_t off_11F9EC;
extern uint32_t off_11F9F0;
extern uint32_t off_11F9F4;
extern uint32_t off_11F9F8;
extern uint32_t dword_11FA1C;
extern uint32_t off_11F9FC;
extern uint32_t off_11FA00;
extern uint32_t dword_11FA04;
extern uint32_t off_11FA08;
extern uint32_t off_11FA10;
extern uint32_t off_11FA0C;
extern uint32_t dword_11FA24;
extern uint32_t dword_11FA20;
extern uint32_t dword_11FA18;
extern uint32_t off_11FA14;

// sub_11F82C @ 0x11f82c, size 412 bytes
// Doc: sub_121F82C [tx]: TX descriptor/buffer setup routine
// sub_121F82C [tx]: TX descriptor/buffer setup routine
int  sub_11F82C(int result)
{
  int v1; // r4
  int *v2; // r2
  unsigned int v3; // r1
  uint32_t *v4; // r3
  void *v5; // r2
  uint32_t *v6; // r0
  int v7; // r1
  int *v8; // r6
  uint32_t *v9; // r5
  uint32_t *v10; // r7
  int v11; // r8
  uint32_t *v12; // r7
  int v13; // r10
  uint32_t *v14; // r9
  uint32_t *v15; // r8
  int v16; // r5
  int v17; // r3
  int v18; // r2
  uint32_t *v19; // r5
  int v20; // r2
  int v21; // r3
  uint32_t *v22; // r2
  int v23; // r1

  v1 = result;
  if ( *(uint8_t *)(result + 1224) )
    result = bt_rx_handler();
  if ( *(uint32_t *)(v1 + 72) )
    result = sub_1284C0(v1);
  if ( (*(uint32_t *)(v1 + 4) & 1) != 0 )
  {
    if ( (*(uint32_t *)off_11F9C8 & 0x2000000) != 0 || (result = *(uint32_t *)off_11F9C8 << 6, *((uint8_t *)off_11F9CC + 36)) )
    {
      result = feature_guard_sdio(2, dword_11F9D0);
      v2 = (int *)off_11F9D4;
      v3 = *((uint8_t *)off_11F9D4 + 1);
      *(uint32_t *)(v1 + 4) &= ~1u;
      *v2 = v3 > 1;
      if ( *((uint8_t *)off_11F9D8 + 190) )
      {
        if ( **(uint8_t **)off_11F9DC == 2 )
        {
          result = sub_117EF8();
          v4 = off_11F9E0;
          *(uint32_t *)off_11F9E0 &= ~1u;
          *v4 &= ~0x80u;
          if ( *(uint8_t *)(v1 + 128) > 9u )
          {
            v5 = off_11F9C8;
            v6 = off_11F9E4;
            v7 = dword_11F9E8;
            *(uint32_t *)off_11F9C8 &= ~4u;
            if ( (*v6 & v7) == 0 )
              sub_1143D0((int)v6, v7, (int)v5);
            if ( *(uint32_t *)off_11F9EC << 28 )
            {
              if ( (__get_CPSR() & 1) == 0 )
              {
                __disable_irq();
                *(uint32_t *)off_11F9F0 = 1;
              }
              v8 = (int *)off_11F9F4;
              v9 = off_11F9EC;
              v10 = off_11F9F8;
              ++*(uint32_t *)off_11F9F4;
              *v9 = 0;
              v11 = v10[4];
              while ( *v9 << 28 )
              {
                if ( (unsigned int)(v10[4] - v11) > 0x7530 )
                  feature_guard_sdio(2, dword_11FA1C);
              }
              v12 = off_11F9F8;
              v13 = *((uint32_t *)off_11F9F8 + 4);
              if ( (*(uint32_t *)off_11F9FC & *(uint32_t *)off_11FA00 & 4) == 0 )
              {
                v14 = off_11F9FC;
                v15 = off_11FA00;
                do
                {
                  v16 = *v14 & *v15;
                  if ( (unsigned int)(v12[4] - v13) > 0x7530 )
                    feature_guard_sdio(2, dword_11FA04);
                }
                while ( (v16 & 4) == 0 );
              }
              *(uint32_t *)off_11FA08 = 4;
              if ( *v8 )
              {
                v17 = *v8 - 1;
                v18 = *(uint32_t *)off_11F9F0;
                *v8 = v17;
                if ( !v17 )
                {
                  if ( v18 )
                    __enable_irq();
                }
              }
            }
            v19 = off_11FA10;
            v20 = **(int16_t **)off_11FA0C;
            v21 = *((uint32_t *)off_11FA10 + 1) | 0x200;
            *((uint32_t *)off_11FA10 + 1) = v21;
            if ( v20 < 0 )
            {
              if ( *(uint32_t *)off_11F9EC << 28 )
              {
                sub_12F6C4(dword_11FA24, dword_11FA20, 472);
                v21 = v19[1];
              }
            }
            v22 = off_11F9EC;
            v23 = dword_11FA18;
            *(uint32_t *)off_11FA14 = v21 | *v19;
            *v22 = 48;
            return rf_table_lookup_n528(*(uint8_t *)(v1 + 107), v23, v1);
          }
        }
      }
    }
  }
  return result;
}

