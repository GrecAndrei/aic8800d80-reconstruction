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

extern uint32_t off_114078;
extern uint32_t dword_11407C;
extern uint32_t dword_11408C;
extern uint32_t dword_114088;
extern uint32_t dword_114084;
extern uint32_t off_114080;

// sub_114024 @ 0x114024, size 82 bytes
int  sub_114024(int a1, int a2, int a3, int a4)
{
  int result; // r0
  int v5; // r2

  if ( a1 == *(uint32_t *)off_114078 )
  {
    v5 = 0;
  }
  else
  {
    if ( a1 != *((uint32_t *)off_114078 + 1) )
    {
      result = sub_12ECB0(dword_11407C, a1, *(uint32_t *)off_114078);
      goto LABEL_4;
    }
    v5 = 1;
  }
  result = sub_12ECB0(dword_11408C, dword_114088, *(uint32_t *)(dword_114084 + 4 * v5));
LABEL_4:
  if ( *((uint8_t *)off_114080 + 353) )
    return rf_level_apply_80c(1068, 1, 1000 * *((uint8_t *)off_114080 + 354), a4);
  return result;
}

