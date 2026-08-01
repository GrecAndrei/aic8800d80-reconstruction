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

extern uint32_t dword_12F584;

// load_and_process_r0 @ 0x12f554, size 48 bytes
// Doc: sub_122F554 [unknown]: Save callee-saved regs and dereference first argument pointer
// sub_122F554 [unknown]: Save callee-saved regs and dereference first argument pointer
uint32_t ** load_and_process_r0(uint32_t **result)
{
  uint32_t *v1; // r4
  int v2; // r6
  uint32_t *v3; // r5
  int v4; // r2

  v1 = *result;
  if ( *result )
  {
    v2 = dword_12F584;
    v3 = result;
    do
    {
      while ( 1 )
      {
        mem_word_load((int)v3);
        result = (uint32_t **)v2;
        if ( !v1[3] )
          break;
        result = (uint32_t **)cmd_handler_a(v2, v1);
        v1 = (uint32_t *)*v3;
        if ( !*v3 )
          return result;
      }
      v4 = v1[2];
      v1 = (uint32_t *)*v3;
      *(uint16_t *)(v4 + 8) = 0;
    }
    while ( v1 );
  }
  return result;
}

