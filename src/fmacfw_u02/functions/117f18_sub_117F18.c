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

extern uint32_t dword_117F44;
extern uint32_t dword_117F48;

// ipc_handler_register @ 0x117f18, size 44 bytes
// Doc: sub_1217F18 [unknown]: Lookup 8-byte table entry by index and invoke callback
// sub_1217F18 [unknown]: Lookup 8-byte table entry by index and invoke callback
int  ipc_handler_register(int a1, int a2, int a3)
{
  int v3; // r3
  int v5; // r0
  int result; // r0

  v3 = *(uint32_t *)(a1 + 76);
  v5 = dword_117F44;
  *(uint32_t *)(v3 + 4) = a2;
  result = cmd_handler_a(v5 + 8 * a3);
  if ( (*(uint32_t *)(a1 + 36) & 0x200000) == 0 )
    return unknown_func_12d104(*(uint32_t *)(dword_117F48 + 4 * a3));
  return result;
}

