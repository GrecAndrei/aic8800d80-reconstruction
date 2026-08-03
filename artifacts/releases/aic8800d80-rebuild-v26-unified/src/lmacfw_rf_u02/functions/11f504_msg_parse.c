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

extern uint32_t off_11F588;
extern uint32_t dword_11F58C;
extern uint32_t dword_11F590;

// msg_parse @ 0x11f504, size 128 bytes
// Doc: rf_mem_read_n_48 [rf]: Read RF calibration/state memory at offset 0x66
// rf_mem_read_n_48 [rf]: Read RF calibration/state memory at offset 0x66
int msg_parse(int result, ...)
{
  uint32_t *v1; // r6
  uint8_t *v2; // r4
  int16_t **v3; // r8
  int v4; // r10
  int v5; // r9
  unsigned int v6; // r5
  unsigned int v7; // t1
  char v8; // r2
  int varg_r0; // [sp+28h] [bp+20h]
  va_list varg_r1; // [sp+2Ch] [bp+24h] BYREF

  va_start(varg_r1, result);
  varg_r0 = result;
  v1 = rf_mem_read_n_10;
  if ( *((uint32_t *)rf_mem_read_n_10 + 1) )
  {
    v2 = (uint8_t *)result;
    v3 = (int16_t **)off_11F588;
    v4 = dword_11F58C;
    v5 = dword_11F590;
    do
    {
      result = (int)v2;
      v7 = *v2++;
      v6 = v7;
      v8 = v7 + 0x80;
      if ( (v7 & 0x80) == 0 )
        break;
      if ( v6 > 0x89 )
      {
        if ( **v3 < 0 && (uint8_t)(v6 + 102) > 5u )
          result = rf_cmd_send_n264(v5, v4, 812);
        if ( v1[1] <= v6 - 154 )
          return result;
      }
      else if ( (((unsigned int)~*v1 >> v8) & 1) != 0 )
      {
        return result;
      }
      result = (int)v2;
    }
    while ( (uint8_t *)(varg_r0 + 2) != v2 );
    return message_dispatch_n286(result, (int)varg_r1);
  }
  return result;
}

