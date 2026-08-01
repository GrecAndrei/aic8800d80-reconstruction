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

// util_chk_field @ 0x12c6f0, size 26 bytes
// Doc: util_chk_field [ipc]: Dispatch IPC message handling 0x7f opcode sentinel
// util_chk_field [ipc]: Dispatch IPC message handling 0x7f opcode sentinel
int  util_chk_field(int a1, uint8_t *a2, uint8_t *a3)
{
  int v3; // r3
  int result; // r0

  v3 = *(char *)(a1 + 109);
  if ( v3 == 127 )
    result = *(uint32_t *)message_dispatch_n_4a7;
  else
    result = (uint8_t)v3;
  if ( v3 == 127 )
    result = (uint8_t)result;
  if ( a2 )
    *a2 = v3;
  if ( a3 )
    *a3 = result;
  return result;
}

