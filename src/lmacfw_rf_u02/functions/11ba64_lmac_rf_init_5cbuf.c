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

extern uint32_t off_11BAF4;
extern uint32_t off_11BAF0;
extern uint32_t dword_11BAF8;
extern uint32_t dword_11BAFC;
extern uint32_t dword_11BB14;
extern uint32_t dword_11BB10;

// env_reset @ 0x11ba64, size 138 bytes
// Doc: env_reset [rf]: Initialize RF 0x5c-byte context block to zero
// env_reset [rf]: Initialize RF 0x5c-byte context block to zero
int env_reset()
{
  int *v0; // r7
  void *v1; // r6
  unsigned int v2; // r5
  int *i; // r4
  int result; // r0
  uint32_t *v5; // r3
  int v6; // r1

  v0 = (int *)off_11BAF4;
  v1 = off_11BAF0;
  sub_100200((int *)off_11BAF0, 0, 0x5Cu);
  v2 = 0;
  for ( i = v0; ; i += 7 )
  {
    sub_100200(i, 0, 0x1Cu);
    *((uint16_t *)i + 7) = 255;
    *((uint8_t *)i + 24) = -1;
    if ( v2 <= 2 )
    {
      check_kernel_state(v1);
      goto LABEL_4;
    }
    if ( v2 != 3 )
      break;
    *((uint16_t *)v0 + 47) = 0;
    *((uint8_t *)v0 + 89) = 0;
LABEL_4:
    ++v2;
  }
  if ( v2 != 4 )
    goto LABEL_4;
  list_init(dword_11BAF8);
  list_init(dword_11BAFC);
  check_kernel_state(dword_11BAF8);
  check_kernel_state(dword_11BAF8);
  check_kernel_state(dword_11BAF8);
  result = check_kernel_state(dword_11BAF8);
  v5 = off_11BAF0;
  v6 = dword_11BB14;
  *((uint32_t *)off_11BAF0 + 13) = dword_11BB10;
  v5[17] = v6;
  v5[18] = 0;
  return result;
}

