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

extern uint32_t dword_13AB78;
extern uint32_t dword_13AB7C;
extern uint32_t off_13AB84;
extern uint32_t dword_13AB8C;
extern uint32_t dword_13AB88;
extern uint32_t dword_13AB80;

// sub_13AA1C @ 0x13aa1c, size 346 bytes
uint16_t * sub_13AA1C(int a1, uint16_t *a2, int a3)
{
  int v4; // r5
  int v5; // r3
  uint16_t *v6; // r9
  uint8_t *v7; // r8
  int v9; // r4
  int v10; // r5
  int v11; // r3
  int16_t v12; // r3
  int v13; // r2

  v4 = *(uint8_t *)(a1 + 29);
  v5 = dword_13AB78 + 696 * v4;
  v6 = a2;
  v7 = **(uint8_t ***)(v5 + 188);
  if ( v7 )
  {
    v9 = dword_13AB7C + 1320 * *(uint8_t *)(a1 + 28);
    if ( *(uint32_t *)(v9 + 1200) )
    {
      if ( (*(uint32_t *)(v9 + 1208) & 2) == 0
        || *(uint16_t *)(v5 + 56) != (uint16_t)__rev16(*(uint16_t *)(a1 + 24)) )
      {
        v10 = dword_13AB78 + 696 * v4;
        v11 = *(uint32_t *)(v10 + 184);
        if ( !v11 || (unsigned int)*(uint8_t *)(v11 + 96) - 1 > 1 || *(uint8_t *)(v10 + 669) > 1u )
        {
          switch ( v7[96] )
          {
            case 0:
            case 3:
              *(a2 - 2) = *(uint16_t *)(a1 + 56);
              v6 = a2 - 2;
              *(a2 - 1) = *(uint16_t *)(a1 + 58) | ((uint8_t)v7[97] << 14);
              if ( a3 )
                goto LABEL_11;
              goto LABEL_17;
            case 1:
              *(a2 - 4) = *(uint16_t *)(a1 + 56) & 0x5F00 | 0x2000 | HIBYTE(*(uint16_t *)(a1 + 56));
              v6 = a2 - 4;
              v12 = *(uint8_t *)(a1 + 56) | (uint16_t)((uint8_t)v7[97] << 14);
              goto LABEL_9;
            case 2:
            case 6:
            case 7:
            case 8:
              *(a2 - 4) = *(uint16_t *)(a1 + 56);
              v6 = a2 - 4;
              v12 = (uint8_t)v7[97] << 14;
LABEL_9:
              v6[1] = v12 | 0x2000;
              v6[2] = *(uint16_t *)(a1 + 58);
              v6[3] = *(uint16_t *)(a1 + 60);
              break;
            case 4:
              *(a2 - 9) = (uint8_t)v7[97];
              v6 = a2 - 9;
              v6[1] = *(uint16_t *)(a1 + 56);
              v6[2] = *(uint16_t *)(a1 + 58);
              v6[3] = *(uint16_t *)(a1 + 60);
              v6[4] = *(uint16_t *)(a1 + 62);
              v6[5] = 23606;
              v6[6] = 23606;
              v6[7] = 23606;
              v6[8] = 23606;
              break;
            default:
              if ( **(int16_t **)off_13AB84 < 0 )
                sub_12F694(dword_13AB8C, dword_13AB88, 743);
              break;
          }
          if ( a3 )
LABEL_11:
            v13 = *(uint32_t *)(a1 + 44);
          else
LABEL_17:
            v13 = *(uint32_t *)(a1 + 72) + 44;
          *(uint32_t *)(v13 + 12) = dword_13AB80 & *(uint32_t *)(v13 + 12) | (uint8_t)v7[98];
        }
      }
    }
  }
  return v6;
}

