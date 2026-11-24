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


extern uint32_t dword_126818;
extern uint32_t dword_126820;
extern uint32_t off_12681C;

// ke_task_poll @ 0x1267e0, size 56 bytes
uint32_t *ke_task_poll()
{
  uint32_t *result; // r0
  uint32_t *v1; // r4
  uint32_t *v2; // r1
  int v3; // r5
  int v4; // r4
  uint32_t *a2; // [sp+4h] [bp-8h]

  result = mem_word_load(dword_126818);
  a2 = result;
  if ( result )
  {
    v1 = off_12681C;
    fault_handler((uint32_t *)dword_126820);
    v2 = a2;
    v1[18] = 0;
    v3 = (int)(v1 + 6);
    v4 = (int)(v1 + 8);
    do
    {
      cmd_handler_a(v3, v2);
      result = mem_word_load(v4);
      v2 = result;
    }
    while ( result );
  }
  return result;
}
