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


extern uint32_t off_12EB08;
extern uint32_t off_12EB0C;

// event_dispatch @ 0x12ea88, size 128 bytes
int event_dispatch(const char *fmt, ...)
{
  uint32_t *v1; // r6
  const char *v2; // r4
  uint16_t **v3; // r8
  unsigned int v4; // r5
  unsigned int v5; // t1
  char v6; // r2
  const char *varg_r0; // [sp+28h] [bp+20h]
  va_list varg_r1; // [sp+2Ch] [bp+24h] BYREF

  va_start(varg_r1, fmt);
  varg_r0 = fmt;
  v1 = off_12EB08;
  if ( *((uint32_t *)off_12EB08 + 1) )
  {
    v2 = fmt;
    v3 = (uint16_t **)off_12EB0C;
    do
    {
      fmt = v2;
      v5 = *(uint8_t *)v2++;
      v4 = v5;
      v6 = v5 + 0x80;
      if ( (v5 & 0x80) == 0 )
        break;
      if ( v4 > 0x89 )
      {
        if ( **v3 < 0 && (uint8_t)(v4 + 102) > 5u )
          fmt = (const char *)mmio_clear_register((int)aDbgSevMinPrefi, (int)aDbgTestPrint, 812);
        if ( v1[1] <= v4 - 154 )
          return (int)fmt;
      }
      else if ( (((unsigned int)~*v1 >> v6) & 1) != 0 )
      {
        return (int)fmt;
      }
      fmt = v2;
    }
    while ( varg_r0 + 2 != v2 );
    return prepare_debug_buffer(fmt, (unsigned int *)(*(void **)&(varg_r1)));
  }
  return (int)fmt;
}
