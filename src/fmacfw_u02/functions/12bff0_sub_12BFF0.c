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

extern uint32_t off_12C184;
extern uint32_t off_12C188;
extern uint32_t dword_12C18C;
extern uint32_t dword_12C190;
extern uint32_t off_12C1A0;
extern uint32_t off_12C1A4;
extern uint32_t off_12C1A8;
extern uint32_t off_12C194;
extern uint32_t dword_12C1AC;
extern uint32_t dword_12C198;
extern uint32_t dword_12C1B0;
extern uint32_t dword_12C1B4;
extern uint32_t dword_12C1B8;
extern uint32_t dword_12C1BC;
extern uint32_t dword_12C1C0;
extern uint32_t dword_12C1C4;
extern uint32_t dword_12C1C8;
extern uint32_t dword_12C1CC;
extern uint32_t dword_12C1D0;
extern uint32_t dword_12C1D4;
extern uint32_t dword_12C1D8;
extern uint32_t dword_12C1DC;
extern uint32_t dword_12C19C;

// sub_12BFF0 @ 0x12bff0, size 402 bytes
int  sub_12BFF0(int result, int a2, int a3, int a4)
{
  int v4; // r1
  int v5; // r4
  int v6; // r3
  int v7; // r5

  v4 = *(uint32_t *)off_12C184;
  v5 = *(uint32_t *)off_12C188 & *(uint32_t *)off_12C184;
  v6 = dword_12C18C & v5;
  *((uint32_t *)off_12C184 + 1) = v5;
  if ( v6 )
    result = sub_12D104(0x1000000);
  if ( (dword_12C190 & v5) != 0 )
    result = sub_12D104(0x800000);
  if ( (v5 & 4) != 0 )
    result = sub_12B540();
  if ( (v5 & 8) != 0 )
    result = sub_12BE8C(result, v4);
  if ( (v5 & 0x10000000) != 0 )
  {
    v7 = *(uint32_t *)off_12C1A0;
    *((uint8_t *)off_12C1A4 + 30) |= *(uint8_t *)off_12C1A0 & 0x3F;
    result = sub_12D104(0x40000);
    *(uint32_t *)off_12C1A8 = v7;
  }
  if ( **(int16_t **)off_12C194 < 0 )
  {
    if ( (v5 & 0x400000) != 0 )
    {
      return sub_12F408(dword_12C1AC, dword_12C198, 847, a4);
    }
    else if ( (v5 & 0x200000) != 0 )
    {
      return sub_12F408(dword_12C1B0, dword_12C198, 848, a4);
    }
    else if ( (v5 & 0x40) != 0 )
    {
      return sub_12F408(dword_12C1B4, dword_12C198, 849, a4);
    }
    else if ( (v5 & 0x100) != 0 )
    {
      return sub_12F408(dword_12C1B8, dword_12C198, 850, a4);
    }
    else if ( (v5 & 0x1000) != 0 )
    {
      return sub_12F408(dword_12C1BC, dword_12C198, 851, a4);
    }
    else if ( (v5 & 0x2000) != 0 )
    {
      return sub_12F408(dword_12C1C0, dword_12C198, 852, a4);
    }
    else if ( (v5 & 0x4000) != 0 )
    {
      return sub_12F408(dword_12C1C4, dword_12C198, 853, a4);
    }
    else if ( (v5 & 0x8000) != 0 )
    {
      return sub_12F408(dword_12C1C8, dword_12C198, 854, a4);
    }
    else if ( (v5 & 0x10000) != 0 )
    {
      return sub_12F408(dword_12C1CC, dword_12C198, 855, a4);
    }
    else if ( (v5 & 0x20000) != 0 )
    {
      return sub_12F408(dword_12C1D0, dword_12C198, 856, a4);
    }
    else
    {
      result = v5 << 7;
      if ( (v5 & 0x1000000) != 0 )
      {
        return sub_12F408(dword_12C1D4, dword_12C198, 857, a4);
      }
      else if ( (v5 & 0x2000000) != 0 )
      {
        return sub_12F408(dword_12C1D8, dword_12C198, 858, a4);
      }
      else if ( (v5 & 0x100000) != 0 )
      {
        return sub_12F408(dword_12C1DC, dword_12C198, 859, a4);
      }
      else if ( (v5 & 0x8000000) != 0 )
      {
        return sub_12F408(dword_12C19C, dword_12C198, 860, a4);
      }
    }
  }
  return result;
}

