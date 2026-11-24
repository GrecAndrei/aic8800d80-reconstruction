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


extern uint32_t off_1225C0;

// copy_packet_data @ 0x122508, size 174 bytes
int  copy_packet_data(int a1, int a2)
{
  int result; // r0
  int v5; // r6
  int v6; // r7
  int v7; // r4
  const char *v8; // r8
  float *v9; // r5
  int v10; // r4
  float v11; // s15
  float v12; // [sp+0h] [bp-200h] BYREF
  char v13; // [sp+4h] [bp-1FCh] BYREF

  result = parse_number(*(uint8_t **)(a2 + 4), nullptr, 0);
  v5 = result;
  if ( a1 == 2 )
  {
    if ( result )
      return result;
    sdio_core_reset((unsigned int)&v12, 64);
    dispatch_event_handler_1("Temp[0 ~ %d]:\n", 63);
    v6 = 64;
    goto LABEL_10;
  }
  result = parse_number(*(uint8_t **)(a2 + 8), nullptr, 0);
  v6 = result;
  v7 = result;
  if ( result >= 128 )
    v6 = 128;
  if ( !v5 )
  {
    sdio_core_reset((unsigned int)&v12, v6);
    result = dispatch_event_handler_1("Temp[0 ~ %d]:\n", v6 - 1);
    if ( v7 > 0 )
    {
LABEL_10:
      v8 = (const char *)off_1225C0;
      dispatch_event_handler_1(" %3d", (int)v12);
      v9 = (float *)&v13;
      v10 = 0;
      while ( 1 )
      {
        ++v10;
        result = (int)a3d;
        if ( v10 == v6 )
          break;
        v11 = *v9++;
        dispatch_event_handler_1(" %3d", (int)v11);
        if ( (v10 & 7) == 7 )
          dispatch_event_handler_1(v8);
      }
    }
  }
  return result;
}
