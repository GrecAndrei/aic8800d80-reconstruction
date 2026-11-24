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


extern uint32_t dword_12F7A0;

// process_pending_queue @ 0x12f770, size 48 bytes
int * process_pending_queue(int *result, int a2)
{
  uint32_t *v2; // r4
  int *v3; // r6
  int *v4; // r5
  int v5; // r2

  v2 = (uint32_t *)*result;
  if ( *result )
  {
    v3 = (int *)dword_12F7A0;
    v4 = result;
    do
    {
      while ( 1 )
      {
        list_pop_front((int)v4);
        result = v3;
        if ( !v2[3] )
          break;
        result = (int *)check_abort_flag((int)v3, v2);
        v2 = (uint32_t *)*v4;
        if ( !*v4 )
          return result;
      }
      v5 = v2[2];
      v2 = (uint32_t *)*v4;
      *(uint16_t *)(v5 + 8) = 0;
    }
    while ( v2 );
  }
  return result;
}
