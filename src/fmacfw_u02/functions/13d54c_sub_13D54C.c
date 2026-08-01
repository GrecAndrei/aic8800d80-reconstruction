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

extern uint32_t dword_13D690;

// bt_cmd_handler @ 0x13d54c, size 322 bytes
int  bt_cmd_handler(int a1, unsigned int a2)
{
  int v4; // r5
  int16_t v5; // r0
  int v6; // r2
  char v7; // r7
  unsigned int v8; // r5
  unsigned int v9; // r2
  int v10; // cc
  int result; // r0
  int v12; // r3
  uint8_t v13; // r5
  unsigned int v14; // r3
  int v15; // r1

  v4 = (a2 >> 11) & 7;
  if ( (a2 & 0x2000) != 0 )
  {
    v5 = scale_timer_value(a1);
    v6 = a2 & 0xF;
    switch ( v4 )
    {
      case 4:
        if ( (a2 & 0xF) == 0 )
          goto LABEL_13;
        result = (uint16_t)((v6 - 1) | a2 & 0xFFF0);
        if ( *(uint8_t *)(a1 + 181) )
          return result | 0x200;
        return result;
      case 5:
        if ( (a2 & 0xF) == 0 )
          goto LABEL_13;
        v15 = v6 - 1;
        result = a2 & 0xFFF0 | (uint16_t)(v6 - 1);
        if ( (a2 & 0x4000) == 0 )
          return result;
        if ( v6 == 3 )
          return result & 0xBFFF;
        goto LABEL_21;
      case 7:
        if ( (a2 & 0xF) != 0 )
        {
          v15 = v6 - 1;
          result = a2 & 0xFFF0 | (uint16_t)(v6 - 1);
          if ( (a2 & 0x4000) != 0 )
          {
LABEL_21:
            if ( v15 > *(uint8_t *)(a1 + 195) )
              return result & 0xBFFF;
          }
          return result;
        }
        if ( *(uint8_t *)(a1 + 183) && (a2 & 0x180) == 0 )
          return dword_13D690 & a2 | 1;
        break;
      default:
        return a2;
    }
    return a2;
  }
  if ( ((a2 >> 11) & 6) == 0 )
  {
    v7 = a2;
    v8 = a2 & 0x7F;
    scale_timer_value(a1);
    if ( (v7 & 0x7C) != 0 )
    {
      v9 = *(uint8_t *)(a1 + 177);
      if ( v9 < 4 )
        v9 = 4;
    }
    else
    {
      v9 = *(uint8_t *)(a1 + 177);
    }
    while ( 1 )
    {
      v10 = v8 > v9;
      v8 = (uint8_t)(v8 - 1);
      if ( !v10 )
        break;
      if ( ((*(uint16_t *)(a1 + 174) >> v8) & 1) != 0 )
      {
        result = a2 & 0xFFFFFF80 | v8;
        if ( !v8 )
          return (uint16_t)result | 0x400;
        return result;
      }
    }
    return a2;
  }
  v5 = scale_timer_value(a1);
  v12 = a2 & 7;
  while ( 1 )
  {
    v13 = v12 - 1;
    if ( !v12 )
      break;
    v12 = v13;
    if ( ((*(uint8_t *)(((a2 >> 3) & 3) + a1 + 170) >> v13) & 1) != 0 )
    {
      result = a2 & 0xFFFFFFF8 | v13;
      if ( *(uint8_t *)(a1 + 181) )
        return (uint16_t)result | 0x200;
      return result;
    }
  }
LABEL_13:
  v14 = *(uint8_t *)(a1 + 178);
  if ( v14 > 3 )
    return a2;
  if ( *(uint8_t *)(a1 + 178) )
    return (uint16_t)(v14 | (*(uint8_t *)(a1 + 182) << 10)) | v5 & 0x400;
  else
    return 1024;
}

