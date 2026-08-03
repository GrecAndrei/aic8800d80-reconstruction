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

extern uint32_t dword_10FFAC;
extern uint32_t off_10FFA4;
extern uint32_t dword_10FFBC;
extern uint32_t dword_10FFB0;
extern uint32_t off_10FFA8;
extern uint32_t dword_10FFB8;
extern uint32_t dword_10FFB4;

// sub_10FEC8 @ 0x10fec8, size 218 bytes
int  sub_10FEC8(uint32_t *a1)
{
  int result; // r0
  int v3; // r2
  int v4; // r3
  int v5; // r3

  result = sub_10FDF4((unsigned int)a1);
  if ( !result )
  {
    result = sub_10DAE4(dword_10FFAC, a1);
    v5 = **(uint8_t **)off_10FFA4;
    if ( v5 != 1 )
    {
      if ( v5 == 2 )
        return sub_113908(a1);
      if ( v5 != 3 )
      {
LABEL_11:
        if ( !sub_10FDF4((unsigned int)a1) )
          sub_10DAE4(dword_10FFBC, a1);
        return sub_10FBA0(dword_10FFB0, a1);
      }
      if ( **(int16_t **)off_10FFA8 < 0 )
        return sub_12F32C(dword_10FFB8, dword_10FFB4, 204);
      return result;
    }
    return sub_110380(a1);
  }
  v3 = *((uint8_t *)a1 - 4);
  v4 = **(uint8_t **)off_10FFA4;
  if ( v4 == 1 )
  {
    if ( v3 == 3 )
      return sub_110250(a1);
    if ( v3 == 2 )
      return sub_1102F0(a1);
    if ( *((uint8_t *)a1 - 4) )
      return result;
    return sub_110380(a1);
  }
  if ( v4 != 2 )
  {
    if ( v4 == 3 )
    {
      if ( **(int16_t **)off_10FFA8 >= 0 )
      {
        if ( v3 != 3 )
          return result;
        return sub_11414C(a1);
      }
      if ( v3 == 3 )
        return sub_11414C(a1);
      return sub_12F32C(dword_10FFB8, dword_10FFB4, 204);
    }
    goto LABEL_11;
  }
  if ( v3 == 3 )
    return sub_1137C4(a1);
  if ( !*((uint8_t *)a1 - 4) )
    return sub_113908(a1);
  return result;
}

