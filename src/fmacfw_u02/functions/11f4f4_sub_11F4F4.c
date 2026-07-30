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

extern uint32_t off_11F690;
extern uint32_t off_11F694;
extern uint32_t dword_11F698;
extern uint32_t off_11F69C;
extern uint32_t off_11F6A0;
extern uint32_t off_11F6A4;
extern uint32_t off_11F6A8;
extern uint32_t off_11F6AC;
extern uint32_t dword_11F6B0;
extern uint32_t off_11F6B4;
extern uint32_t off_11F6B8;
extern uint32_t off_11F6BC;
extern uint32_t off_11F6C0;
extern uint32_t dword_11F6E4;
extern uint32_t off_11F6C4;
extern uint32_t off_11F6C8;
extern uint32_t dword_11F6CC;
extern uint32_t off_11F6D0;
extern uint32_t off_11F6D8;
extern uint32_t off_11F6D4;
extern uint32_t dword_11F6EC;
extern uint32_t dword_11F6E8;
extern uint32_t off_11F6E0;
extern uint32_t off_11F6DC;

// sub_11F4F4 @ 0x11f4f4, size 412 bytes
int  sub_11F4F4(int result)
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
  void *v23; // r1

  v1 = result;
  if ( *(uint8_t *)(result + 1224) )
    result = sub_12A31C();
  if ( *(uint32_t *)(v1 + 72) )
    result = sub_12829C(v1);
  if ( (*(uint32_t *)(v1 + 4) & 1) != 0 )
  {
    if ( (*(uint32_t *)off_11F690 & 0x2000000) != 0 || (result = *(uint32_t *)off_11F690 << 6, *((uint8_t *)off_11F694 + 36)) )
    {
      result = sub_12ECD0(2, dword_11F698);
      v2 = (int *)off_11F69C;
      v3 = *((uint8_t *)off_11F69C + 1);
      *(uint32_t *)(v1 + 4) &= ~1u;
      *v2 = v3 > 1;
      if ( *((uint8_t *)off_11F6A0 + 190) )
      {
        if ( **(uint8_t **)off_11F6A4 == 2 )
        {
          result = sub_117AB8();
          v4 = off_11F6A8;
          *(uint32_t *)off_11F6A8 &= ~1u;
          *v4 &= ~0x80u;
          if ( *(uint8_t *)(v1 + 128) > 9u )
          {
            v5 = off_11F690;
            v6 = off_11F6AC;
            v7 = dword_11F6B0;
            *(uint32_t *)off_11F690 &= ~4u;
            if ( (*v6 & v7) == 0 )
              sub_114574((int)v6, v7, (int)v5);
            if ( *(uint32_t *)off_11F6B4 << 28 )
            {
              if ( (__get_CPSR() & 1) == 0 )
              {
                __disable_irq();
                *(uint32_t *)off_11F6B8 = 1;
              }
              v8 = (int *)off_11F6BC;
              v9 = off_11F6B4;
              v10 = off_11F6C0;
              ++*(uint32_t *)off_11F6BC;
              *v9 = 0;
              v11 = v10[4];
              while ( *v9 << 28 )
              {
                if ( (unsigned int)(v10[4] - v11) > 0x7530 )
                  sub_12ECD0(2, dword_11F6E4);
              }
              v12 = off_11F6C0;
              v13 = *((uint32_t *)off_11F6C0 + 4);
              if ( (*(uint32_t *)off_11F6C4 & *(uint32_t *)off_11F6C8 & 4) == 0 )
              {
                v14 = off_11F6C4;
                v15 = off_11F6C8;
                do
                {
                  v16 = *v14 & *v15;
                  if ( (unsigned int)(v12[4] - v13) > 0x7530 )
                    sub_12ECD0(2, dword_11F6CC);
                }
                while ( (v16 & 4) == 0 );
              }
              *(uint32_t *)off_11F6D0 = 4;
              if ( *v8 )
              {
                v17 = *v8 - 1;
                v18 = *(uint32_t *)off_11F6B8;
                *v8 = v17;
                if ( !v17 )
                {
                  if ( v18 )
                    __enable_irq();
                }
              }
            }
            v19 = off_11F6D8;
            v20 = **(int16_t **)off_11F6D4;
            v21 = *((uint32_t *)off_11F6D8 + 1) | 0x200;
            *((uint32_t *)off_11F6D8 + 1) = v21;
            if ( v20 < 0 )
            {
              if ( *(uint32_t *)off_11F6B4 << 28 )
              {
                sub_12F49C(dword_11F6EC, dword_11F6E8, 472);
                v21 = v19[1];
              }
            }
            v22 = off_11F6B4;
            v23 = off_11F6E0;
            *(uint32_t *)off_11F6DC = v21 | *v19;
            *v22 = 48;
            return sub_12B2B0(*(uint8_t *)(v1 + 107), v23, v1);
          }
        }
      }
    }
  }
  return result;
}

