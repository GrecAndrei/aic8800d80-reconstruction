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


extern uint32_t dword_117B44;
extern uint32_t dword_117B48;

// init_table_185d40 @ 0x117af8, size 74 bytes
uint32_t *init_table_185d40()
{
  int v0; // r5
  int v1; // r7
  int i; // r6
  uint32_t *v3; // r4
  uint32_t *v4; // r0
  uint32_t *result; // r0

  v0 = dword_117B48;
  v1 = dword_117B44;
  list_init_1((uint32_t *)dword_117B44);
  for ( i = 0; i != 76; i += 19 )
  {
    mutex_acquire_if_ready(v0 - 88);
    check_kernel_state(v1, (uint32_t *)(v0 - 88));
    v3 = (uint32_t *)(v0 - 32);
    do
    {
      list_init_1(v3);
      v4 = v3 + 8;
      v3 += 2;
      result = list_init_1(v4);
    }
    while ( v3 != (uint32_t *)v0 );
    v0 = (int)(v3 + 38);
  }
  return result;
}
