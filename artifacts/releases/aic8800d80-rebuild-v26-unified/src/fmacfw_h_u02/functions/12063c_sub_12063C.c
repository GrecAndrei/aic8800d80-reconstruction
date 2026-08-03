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

extern uint32_t off_1206F8;
extern uint32_t off_1206FC;

// sub_12063C @ 0x12063c, size 188 bytes
int * sub_12063C(int *result, int a2, int a3)
{
  int *v3; // r3
  unsigned int *v4; // r3
  unsigned int *v5; // r3
  unsigned int *v6; // r3

  if ( !a2 )
  {
    v3 = *((int **)off_1206F8 + 2);
    if ( !v3 )
    {
      if ( a3 )
        goto LABEL_13;
      goto LABEL_4;
    }
    while ( 1 )
    {
      while ( result == v3 || !*((uint8_t *)v3 + 108) )
      {
LABEL_7:
        v3 = (int *)*v3;
        if ( !v3 )
          goto LABEL_12;
      }
      if ( *((uint8_t *)v3 + 413) == 2 )
      {
        if ( *((uint8_t *)v3 + 106) == 2 )
          break;
        a2 = 1;
        goto LABEL_7;
      }
      v3 = (int *)*v3;
      if ( !v3 )
      {
LABEL_12:
        if ( a2 | a3 )
        {
LABEL_13:
          v5 = (unsigned int *)off_1206FC;
          *(uint32_t *)off_1206FC = *(uint32_t *)off_1206FC & 0xFFFFFF00 | 0x68;
          *v5 = *v5 & 0xFFFF00FF | 0x7800;
          *v5 = *v5 & 0xFF00FFFF | 0x780000;
          return result;
        }
LABEL_4:
        v4 = (unsigned int *)off_1206FC;
        *(uint32_t *)off_1206FC = *(uint32_t *)off_1206FC & 0xFFFFFF00 | 0x80;
        *v4 = *v4 & 0xFFFF00FF | 0x8000;
        *v4 = *v4 & 0xFF00FFFF | 0x800000;
        return result;
      }
    }
  }
  v6 = (unsigned int *)off_1206FC;
  *(uint32_t *)off_1206FC = *(uint32_t *)off_1206FC & 0xFFFFFF00 | 0x60;
  *v6 = *v6 & 0xFFFF00FF | 0x6000;
  *v6 = *v6 & 0xFF00FFFF | 0x600000;
  return result;
}

