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

extern uint32_t dword_105480;
extern uint32_t dword_105484;
extern uint32_t dword_10548C;
extern uint32_t dword_105490;
extern uint32_t dword_105488;

// mac_get_params @ 0x1053c0, size 190 bytes
// Doc: mac_get_params [ke]: Initialize crypto key schedule / expand key material
// mac_get_params [ke]: Initialize crypto key schedule / expand key material
int  mac_get_params(unsigned int a1, uint32_t *a2)
{
  int v4; // r1
  int result; // r0
  int v6; // r2
  int v7; // r3
  int v8; // r7
  int v9; // r9
  int v10; // r8
  int v11; // r5
  int v12; // r3
  int v13; // r3
  int v14; // r2
  unsigned int v15; // r0
  int v16; // r3
  int v17; // r2

  a2[14] = 0;
  a2[15] = 15;
  v4 = dword_105480;
  a2[16] = 8;
  result = check_interrupt_flag(1, v4, a1, 8);
  if ( a1 )
  {
    v8 = dword_105484;
    v9 = dword_10548C;
    v10 = dword_105490;
    v11 = 20;
    while ( 1 )
    {
      while ( ((1 << v11) & a1) >> v11 != 1 )
      {
LABEL_3:
        if ( ++v11 == 28 )
          return result;
      }
      v12 = a2[14] + 10;
      a2[v12] = v11 - 12;
      check_interrupt_flag(1, v8, v11 - 12, v12);
      v13 = a2[14] + 10;
      v14 = a2[v13];
      if ( v14 <= 7 )
      {
        result = check_interrupt_flag(((1 << v11) & a1) >> v11, v9, v14, v13);
        if ( !a2[14] )
          a2[16] = a2[10];
        goto LABEL_3;
      }
      v15 = ((1 << v11) & a1) >> v11;
      if ( v14 > 15 )
      {
        result = check_interrupt_flag(v15, v9, v14, v13);
        if ( !a2[14] )
          a2[15] = a2[10];
        goto LABEL_3;
      }
      result = check_interrupt_flag(v15, v10, v14, v13);
      v16 = a2[14];
      ++v11;
      v17 = a2[v16 + 10];
      a2[14] = v16 + 1;
      a2[15] = v17;
      if ( v11 == 28 )
        return result;
    }
  }
  return check_interrupt_flag(1, dword_105488, v6, v7);
}

