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


extern uint32_t dword_12FFF8;
extern uint32_t dword_130004;
extern uint32_t dword_130008;
extern uint32_t off_130014;
extern uint32_t off_130018;

// sub_12FED8 @ 0x12fed8, size 288 bytes
int  sub_12FED8(int a1)
{
  int v1; // r0
  int v2; // r4
  uint32_t *v4; // r0
  uint32_t *v5; // r5
  unsigned int CPSR; // r1
  unsigned int v7; // r2
  unsigned int v8; // r4
  unsigned int v9; // r5
  uint8_t *v10; // r2
  int v11; // r0
  unsigned int v12; // r5
  unsigned int v13; // r6
  int v14; // t1
  unsigned int v15; // r4
  unsigned int v16; // r5
  int v17; // t1

  v1 = sub_12F6D0(a1, (uint8_t *)dword_12FFF8, 0);
  v2 = v1;
  if ( v1 >= 0 )
  {
    if ( v1 )
    {
      if ( sub_143D00((unsigned int)asc_14B2A4) != v1
        || sub_143968((unsigned int)asc_14B2A4, (unsigned int *)dword_12FFF8) )
      {
        v4 = sub_12D190(dword_130004);
        v5 = v4;
        if ( v4 )
        {
          sub_143C3C((unsigned int)(v4 + 1), dword_12FFF8);
          sub_12D108(dword_130008, v5);
        }
        else
        {
          sub_10D674(aErrCmdFreeList);
        }
      }
      else
      {
        CPSR = __get_CPSR();
        v7 = __get_CPSR();
        v8 = __get_CPSR();
        v9 = __get_CPSR();
        sub_10DAE4(aControl08xXpsr, CPSR, v7, v8, v9, __get_CPSR(), __get_CPSR());
        if ( v9 )
        {
          v12 = v9 & 0xFFFFFFF0;
          sub_10D674(aDumpmsp);
          v13 = v12 + 256;
          do
          {
            if ( !(v12 << 28) )
              sub_10DAE4("\r\n[%08x]:", v12);
            v14 = *(uint32_t *)v12;
            v12 += 4;
            sub_10DAE4(" %08X", v14);
          }
          while ( v13 != v12 );
        }
        if ( v8 )
        {
          v15 = v8 & 0xFFFFFFF0;
          sub_10D674(aDumppsp);
          v16 = v15 + 256;
          do
          {
            if ( !(v15 << 28) )
              sub_10DAE4("\r\n[%08x]:", v15);
            v17 = *(uint32_t *)v15;
            v15 += 4;
            sub_10DAE4(" %08X", v17);
          }
          while ( v16 != v15 );
        }
        sub_10D674(aAic_0);
        v10 = off_130014;
        v11 = *(uint8_t *)off_130014;
        if ( *(uint8_t *)off_130014 )
        {
          *((uint8_t *)off_130018 + 783) = -4;
          v2 = 0;
          *v10 = 0;
        }
        else
        {
          *((uint8_t *)off_130018 + 783) = -12;
          v2 = v11;
          *v10 = 1;
        }
      }
    }
    else
    {
      sub_10D674(aAic);
    }
    sub_12F6D0(0x30u, (uint8_t *)dword_12FFF8, (unsigned int)aAic);
  }
  return v2;
}
