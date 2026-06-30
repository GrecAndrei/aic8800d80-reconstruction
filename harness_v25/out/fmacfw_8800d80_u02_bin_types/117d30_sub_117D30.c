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

extern uint32_t off_117EAC;
extern uint32_t off_117ED8;
extern uint32_t dword_117EB0;
extern uint32_t off_117EB4;
extern uint32_t dword_117EB8;
extern uint32_t off_117EBC;
extern uint32_t off_117EC0;
extern uint32_t dword_117EC4;
extern uint32_t dword_117EC8;
extern uint32_t dword_117ED0;
extern uint32_t dword_117ED4;
extern uint32_t off_117ECC;

// sub_117D30 @ 0x117d30, size 380 bytes
void  sub_117D30(int a1, uint32_t *a2)
{
  int v2; // r3
  int v3; // r2
  uint8_t *v6; // r6
  uint8_t *v7; // r9
  int v8; // r0
  int v9; // r12
  int v10; // r7
  unsigned int v11; // r3
  int16_t v12; // lr
  int v13; // r2
  uint32_t *v14; // r1
  int v15; // r3
  int *v16; // r12
  int *v17; // r6
  int v18; // r2
  int v19; // r0
  int v20; // r0
  int v21; // r1
  int v22; // r3
  int v23; // r2
  int v24; // r6
  int v25; // [sp+0h] [bp-28h] BYREF
  int v26; // [sp+4h] [bp-24h]

  v2 = *(uint32_t *)(a1 + 84);
  if ( v2 < 0 )
  {
    v3 = **(uint8_t **)off_117EAC;
    switch ( v3 )
    {
      case 2:
        v6 = (uint8_t *)sub_113A08();
        if ( v6 )
        {
          v7 = off_117ED8;
          if ( *((uint32_t *)off_117ED8 + 2057) )
          {
            v8 = sub_12D2D0(dword_117EB0);
            *v6 = 8;
            v6[1] = 0;
            v6[3] = 0;
            v6[2] = 18;
            v9 = *a2 & 0xF;
            v10 = v8;
            v26 = *(uint32_t *)(a1 + 84) & 0x3FFFFFFF;
            v25 = v9;
            sub_143770(v6 + 4, &v25, 8);
            v11 = *((uint16_t *)v7 + 4122);
            if ( v11 > 0x186 )
            {
              v13 = 0;
              LOWORD(v11) = 0;
              v12 = 1;
            }
            else
            {
              v12 = v11 + 1;
              v13 = 8 * v11;
            }
            v14 = off_117EB4;
            *(uint16_t *)(v10 + 12) = v11;
            v15 = dword_117EB8;
            v16 = (int *)(*v14 + v13);
            v16[1] = (int)v6;
            *v16 = v15 & *v16 | 0x400000C;
            LOBYTE(v15) = v7[3074];
            *((uint16_t *)v7 + 4122) = v12;
            v7[3074] = v15 + 1;
            *(uint32_t *)(v10 + 4) = v16;
            *(uint8_t *)(v10 + 14) = 1;
            *(uint32_t *)v10 = 0;
            *(uint32_t *)(v10 + 8) = 12;
            if ( (__get_CPSR() & 1) == 0 )
            {
              __disable_irq();
              *(uint32_t *)off_117EBC = 1;
            }
            v17 = (int *)off_117EC0;
            v18 = *(uint16_t *)(a1 + 32);
            v19 = dword_117EC4;
            ++*(uint32_t *)off_117EC0;
            sub_12EA88(v19, a1, v18);
            v20 = sub_12D248(dword_117EC8);
            sub_1134B4(v20, v21);
            if ( *v17 )
            {
              v22 = *v17 - 1;
              v23 = *(uint32_t *)off_117EBC;
              *v17 = v22;
              if ( !v22 )
              {
                if ( v23 )
                  __enable_irq();
              }
            }
          }
          else
          {
            sub_10DC24(dword_117ED0);
          }
        }
        else
        {
          sub_10DC24(dword_117ED4);
        }
        break;
      case 1:
        v24 = *a2 & 0xF;
        v26 = v2 & 0x3FFFFFFF;
        v25 = v24;
        sub_111270(18, (int)&v25, 8);
        sub_12EA88(dword_117EC4, a1, *(uint16_t *)(a1 + 32));
        break;
      case 3:
        **(uint32_t **)off_117ECC = *a2 & 0xF;
        sub_10CC94();
        break;
    }
  }
}

