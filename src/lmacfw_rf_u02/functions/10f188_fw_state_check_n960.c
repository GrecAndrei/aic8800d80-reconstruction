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

extern uint32_t dword_10F1DC;

// get_bandgap_trim @ 0x10f188, size 82 bytes
// Doc: get_bandgap_trim [util]: Load firmware state word from 0x182b60 and test sign
// get_bandgap_trim [util]: Load firmware state word from 0x182b60 and test sign
int  get_bandgap_trim(int a1)
{
  unsigned int v2; // r0
  unsigned int v3; // r1

  v2 = critical_enter(dword_10F1DC, 1);
  v3 = (v2 >> 20) & 0xF;
  if ( a1 )
  {
    if ( ((v2 >> 20) & 0xE) != 0 )
    {
      v3 = ((v3 - 2) << 20) & 0xF00000;
    }
    else if ( v3 )
    {
      v3 = ((v3 - 1) << 20) & 0xF00000;
    }
  }
  else if ( v3 > 0xD )
  {
    v3 = 15728640;
  }
  else
  {
    v3 = ((v3 + 2) << 20) & 0xF00000;
  }
  return critical_enter3(dword_10F1DC, v3, 15728640, 1);
}

