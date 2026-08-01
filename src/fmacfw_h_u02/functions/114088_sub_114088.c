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

extern uint32_t off_1140DC;
extern uint32_t dword_1140E0;
extern uint32_t dword_1140F0;
extern uint32_t dword_1140EC;
extern uint32_t dword_1140E8;
extern uint32_t off_1140E4;

// check_global_value @ 0x114088, size 82 bytes
int  check_global_value(int a1, int a2, int a3, int a4)
{
  int result; // r0
  int v5; // r2

  if ( a1 == *(uint32_t *)off_1140DC )
  {
    v5 = 0;
  }
  else
  {
    if ( a1 != *((uint32_t *)off_1140DC + 1) )
    {
      result = alloc_tx_event(dword_1140E0, a1, *(uint32_t *)off_1140DC);
      goto LABEL_4;
    }
    v5 = 1;
  }
  result = alloc_tx_event(dword_1140F0, dword_1140EC, *(uint32_t *)(dword_1140E8 + 4 * v5));
LABEL_4:
  if ( *((uint8_t *)off_1140E4 + 353) )
    return ke_event_handler(1068, 1, 1000 * *((uint8_t *)off_1140E4 + 354), a4);
  return result;
}

