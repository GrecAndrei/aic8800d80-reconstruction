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

extern uint32_t off_10CB98;
extern uint32_t off_10CBA0;
extern uint32_t off_10CBB8;
extern uint32_t off_10CB9C;
extern uint32_t off_10CBA4;
extern uint32_t off_10CBA8;
extern uint32_t off_10CBAC;
extern uint32_t off_10CBB0;
extern uint32_t dword_10CBB4;

// busy_flag_check @ 0x10cae0, size 182 bytes
int busy_flag_check()
{
  int v0; // r4
  int result; // r0
  uint32_t *v2; // r2
  uint8_t *v3; // r3
  uint32_t *v4; // r2
  uint32_t *v5; // r2
  uint32_t *v6; // r2

  v0 = *(uint32_t *)off_10CB98;
  if ( (*(uint32_t *)off_10CB98 & 0x20) != 0 )
  {
    v6 = off_10CBA0;
    *(uint32_t *)off_10CBB8 = 32;
    *v6 = 32;
    unknown_func_12d104(0x80000);
  }
  result = v0 << 27;
  if ( (v0 & 0x10) != 0 )
  {
    v5 = off_10CBA0;
    *(uint32_t *)off_10CBB8 = 16;
    *v5 = 16;
    result = unknown_func_12d104(0x100000);
  }
  if ( (v0 & 2) != 0 )
  {
    result = unknown_func_12d104(0x8000000);
    *(uint32_t *)off_10CBB8 = 2;
  }
  if ( (v0 & 0x40000000) != 0 )
  {
    result = sub_1145ac(1);
    *(uint32_t *)off_10CBA0 = 0x40000000;
  }
  if ( v0 < 0 )
  {
    v2 = off_10CBA0;
    *(uint32_t *)off_10CB9C = 0x80000000;
    *v2 = 0x80000000;
  }
  if ( (v0 & 0x20000000) == 0 )
  {
    v3 = off_10CBA4;
    if ( !*(uint8_t *)off_10CBA4 || !*(uint32_t *)off_10CBA8 )
      return result;
LABEL_16:
    v4 = off_10CBAC;
    v3[1] = 1;
    *v4 |= 1u;
    return result;
  }
  v3 = off_10CBA4;
  *(uint32_t *)off_10CBA0 = 0x20000000;
  if ( *v3 )
    goto LABEL_16;
  if ( (*(uint32_t *)off_10CBB0 & dword_10CBB4) == 0x10000 )
    return process_global_167204();
  return result;
}

