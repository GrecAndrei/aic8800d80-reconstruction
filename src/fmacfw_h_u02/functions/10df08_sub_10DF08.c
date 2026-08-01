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

extern uint32_t off_10DF68;
extern uint32_t dword_10DF50;
extern uint32_t dword_10DF54;
extern uint32_t dword_10DF58;
extern uint32_t dword_10DF5C;
extern uint32_t dword_10DF60;
extern uint32_t dword_10DF64;

// hw_poll_status @ 0x10df08, size 72 bytes
int hw_poll_status()
{
  uint32_t *v0; // r3
  uint64_t v1; // r0
  uint64_t v2; // r0
  uint64_t v3; // r0
  int v4; // r0

  while ( *((uint32_t *)off_10DF68 + 7) != 1 )
    ;
  v0 = off_10DF68;
  *((uint32_t *)off_10DF68 + 7) = 1;
  v1 = unsigned_int_to_double(v0[4]);
  v2 = double_compare_common(v1, HIDWORD(v1), dword_10DF50, dword_10DF54);
  v3 = double_compare_core(v2, HIDWORD(v2), dword_10DF58, dword_10DF5C);
  v4 = double_compare_neg(v3, HIDWORD(v3), dword_10DF60, dword_10DF64);
  return double_to_int(v4);
}

