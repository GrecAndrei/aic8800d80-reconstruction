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

// sub_13D34C @ 0x13d34c, size 302 bytes
unsigned int  sub_13D34C(unsigned int result)
{
  unsigned int v1; // r4
  int v2; // r1
  int16_t v3; // r3
  unsigned int v4; // r1
  int i; // r3
  int v6; // r2
  int v7; // r2
  int16_t v8; // r1
  int16_t v9; // r1
  unsigned int v10; // r2
  int v11; // r0
  int16_t v12; // r3

  switch ( *(uint8_t *)(result + 169) )
  {
    case 0:
    case 1:
      v4 = *(uint16_t *)(result + 174);
      LOWORD(result) = (((v4 >> 3) & 1) << (1 - *(uint8_t *)(result + 182)))
                     + ((((v4 >> 1) & 1) + ((v4 >> 2) & 1)) << (1 - *(uint8_t *)(result + 182)))
                     + (v4 & 1);
      for ( i = 4; i != 12; ++i )
      {
        v6 = ((int)v4 >> i) & 1;
        result = (uint16_t)(result + v6);
      }
      goto LABEL_5;
    case 2:
    case 3:
      v1 = *(uint8_t *)(result + 170);
      v2 = 8;
      v3 = 0;
      do
      {
        --v2;
        v3 += (v1 & 1)
            * (((*(uint8_t *)(result + 179) + 1) << *(uint8_t *)(result + 181))
             + *(uint8_t *)(result + 180)
             * (uint16_t)((*(uint8_t *)(result + 179) + 1) << *(uint8_t *)(result + 181)));
        v1 >>= 1;
      }
      while ( v2 );
      result = (uint16_t)(((((*(uint16_t *)(result + 174) >> 2) & 1)
                                  + ((*(uint16_t *)(result + 174) >> 1) & 1)) << (1 - *(uint8_t *)(result + 182)))
                                + (*(uint16_t *)(result + 174) & 1)
                                + (((*(uint16_t *)(result + 174) >> 3) & 1) << (1 - *(uint8_t *)(result + 182)))
                                + v3);
      goto LABEL_5;
    case 4:
      v9 = *(uint8_t *)(result + 180);
      v10 = (*(uint16_t *)(result + 170) & 3) - 1;
      v11 = (*(uint8_t *)(result + 179) + 1) << *(uint8_t *)(result + 181);
      if ( v10 <= 1 )
        v12 = 9;
      else
        v12 = 8;
      result = (uint16_t)((v11 + v9 * v11) * v12);
      goto LABEL_5;
    case 5:
      v7 = *(uint16_t *)(result + 170) & 3;
      if ( v7 == 1 )
      {
        v8 = 10;
      }
      else if ( v7 == 2 )
      {
        v8 = 12;
      }
      else
      {
        v8 = 8;
      }
      result = (uint16_t)(3
                                * (*(uint8_t *)(result + 180)
                                 + 1
                                 + *(uint8_t *)(result + 179) * (*(uint8_t *)(result + 180) + 1))
                                * v8
                                + (*(uint16_t *)(result + 174) & 1));
LABEL_5:
      if ( result >= 0xA )
        result = 10;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}

