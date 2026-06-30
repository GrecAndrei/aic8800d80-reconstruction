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

extern uint32_t off_12EF20;
extern uint32_t dword_12EF28;
extern uint32_t dword_12EF24;

// sub_12EE6C @ 0x12ee6c, size 178 bytes
int  sub_12EE6C(int a1, int *a2, int16_t a3, int16_t a4)
{
  uint64_t *v5; // r0
  int v6; // r5
  uint32_t *v7; // r0
  uint64_t v8; // r2
  int v9; // r0

  v5 = (uint64_t *)sub_12C92C(1042, a4, a3, 8u);
  v6 = (int)v5;
  if ( (unsigned int)**(uint8_t **)off_12EF20 - 1 <= 1 )
  {
    LODWORD(v8) = *a2;
    if ( *a2 == dword_12EF28 || (uint32_t)v8 == dword_12EF28 - 36184 )
    {
      *(uint32_t *)v8 ^= (a2[2] ^ *(uint32_t *)v8) & a2[1];
      HIDWORD(v8) = a2[2];
      LODWORD(v8) = *a2;
      v9 = HIDWORD(v8);
      *(uint64_t *)v6 = v8;
    }
    else
    {
      HIDWORD(v8) = a2[2];
      *v5 = v8;
      v9 = HIDWORD(v8);
    }
  }
  else
  {
    v7 = (uint32_t *)*a2;
    if ( (((unsigned int)*a2 >> 20) & 0xFFFFFDFF) == 0x500 )
    {
      sub_10EE2C((int)v7, a2[2], a2[1], 1);
      v9 = sub_10ED84(*a2, 1);
      LODWORD(v8) = *a2;
    }
    else
    {
      *v7 ^= (a2[2] ^ *v7) & a2[1];
      LODWORD(v8) = *a2;
      v9 = *(uint32_t *)*a2;
    }
    *(uint32_t *)(v6 + 4) = v9;
    HIDWORD(v8) = a2[2];
    *(uint32_t *)v6 = v8;
  }
  sub_12EA88(dword_12EF24, a2[1], HIDWORD(v8), HIDWORD(v8), (uint32_t)v8, v9, v9);
  sub_12C98C(v6);
  return 0;
}

