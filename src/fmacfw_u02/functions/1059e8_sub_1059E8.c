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

// mac_event_init @ 0x1059e8, size 190 bytes
int  mac_event_init(unsigned int a1, uint32_t *a2)
{
  int result; // r0
  int v5; // r5
  int v6; // r2
  unsigned int v7; // r0
  int v8; // r3
  int v9; // r2

  a2[14] = 0;
  a2[15] = 15;
  a2[16] = 8;
  result = check_status_bits(1, "bit_mask=%x\n", a1);
  if ( a1 )
  {
    v5 = 20;
    while ( 1 )
    {
      while ( ((1 << v5) & a1) >> v5 != 1 )
      {
LABEL_3:
        if ( ++v5 == 28 )
          return result;
      }
      a2[a2[14] + 10] = v5 - 12;
      check_status_bits(1, "you want to cal %x index\n", v5 - 12);
      v6 = a2[a2[14] + 10];
      if ( v6 <= 7 )
      {
        result = check_status_bits(((1 << v5) & a1) >> v5, " %x ana_pwr_index dont need cal\n", v6);
        if ( !a2[14] )
          a2[16] = a2[10];
        goto LABEL_3;
      }
      v7 = ((1 << v5) & a1) >> v5;
      if ( v6 > 15 )
      {
        result = check_status_bits(v7, " %x ana_pwr_index dont need cal\n", v6);
        if ( !a2[14] )
          a2[15] = a2[10];
        goto LABEL_3;
      }
      result = check_status_bits(v7, "need cal %x ana_pwr_index\n", v6);
      v8 = a2[14];
      ++v5;
      v9 = a2[v8 + 10];
      a2[14] = v8 + 1;
      a2[15] = v9;
      if ( v5 == 28 )
        return result;
    }
  }
  return check_status_bits(1, aLoftDontNeedCa);
}
