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


extern uint32_t dword_113550;
extern uint32_t off_113548;
extern uint32_t off_11354C;
extern uint32_t off_113554;

// sub_1134B4 @ 0x1134b4, size 148 bytes
int sub_1134B4()
{
  uint8_t *v0; // r6
  int **v1; // r4
  char v2; // r0
  uint8_t *v3; // r12
  int *v4; // r7
  int *v5; // r5
  unsigned int v6; // r4
  int *v7; // r1
  char v8; // r3
  char v9; // r2
  uint16_t *v10; // r1
  int v11; // r2
  char v12; // r3

  v0 = off_113548;
  if ( *(uint8_t *)off_113548 )
    return -99;
  v1 = (int **)off_11354C;
  v2 = sub_12D36C((uint32_t **)off_11354C);
  v3 = off_113554;
  *(uint8_t *)off_113554 = v2;
  if ( v2 )
  {
    v4 = *v1;
    v5 = *(int **)(dword_113550 + 8240);
    if ( v2 != 1 )
    {
      v6 = *((uint16_t *)v4 + 6);
      if ( *((uint16_t *)v5 + 6) < v6 )
      {
        v7 = v4;
        v8 = v2;
        while ( 1 )
        {
          v9 = v2 - v8--;
          if ( !v6 )
            break;
          if ( !*v7 || !v8 )
          {
            *v3 = v8;
            v5 = v7;
            goto LABEL_11;
          }
          v6 = *(uint16_t *)(*v7 + 12);
          v5 = v7;
          v7 = (int *)*v7;
        }
        *v3 = v9;
      }
      goto LABEL_11;
    }
    if ( v5 )
    {
LABEL_11:
      v10 = (uint16_t *)v4[1];
      v11 = v5[1] + 8 * (*((uint8_t *)v5 + 14) - 1);
      v12 = *(uint8_t *)(v11 + 3);
      *v0 = 1;
      *(uint8_t *)(v11 + 3) = v12 & 0xF5 | 0xA;
      return sub_113010(1, v10);
    }
  }
  return -98;
}
