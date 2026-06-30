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

// sub_121C6C @ 0x121c6c, size 136 bytes
// Doc: rf_mem_write_n_384 [rf]: Invoke RF memory write helper and compare result
// rf_mem_write_n_384 [rf]: Invoke RF memory write helper and compare result
uint32_t * sub_121C6C(int a1, uint32_t *a2, int a3)
{
  int v5; // r0
  int v6; // r11
  int v7; // r9
  uint32_t *v8; // r4
  int v9; // r5
  int v10; // r6
  uint32_t *v11; // r10

  v5 = sub_12841C(a1, 46);
  if ( v5 )
    v6 = v5 - a1;
  else
    v6 = sub_1288C0(a1);
  if ( a3 )
  {
    v7 = 0;
    v8 = a2;
    v9 = 0;
    do
    {
      while ( 1 )
      {
        v10 = *v8;
        ++v9;
        v11 = v8;
        if ( !sub_12899C(a1, *v8, v6) )
          break;
        v8 += 4;
        if ( a3 == v9 )
          goto rf_cmd_dispatch_1ccc;
      }
      if ( sub_1288C0(v10) == v6 )
        return v11;
      a2 = v8;
      ++v7;
      v8 += 4;
    }
    while ( a3 != v9 );
rf_cmd_dispatch_1ccc:
    if ( v7 == 1 )
      return a2;
  }
  return 0;
}

