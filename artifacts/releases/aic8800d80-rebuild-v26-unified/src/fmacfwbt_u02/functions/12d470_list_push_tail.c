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

extern uint32_t off_12D4AC;
extern uint32_t dword_12D4B4;
extern uint32_t dword_12D4B0;

// list_push_tail @ 0x12d470, size 60 bytes
// Doc: list_push_tail [util]: Append node to tail of linked list
// list_push_tail [util]: Append node to tail of linked list
int  list_push_tail(int result, uint32_t *a2)
{
  int v2; // r5

  v2 = result;
  if ( **(int16_t **)off_12D4AC < 0 && !a2 )
    result = sub_12F694(dword_12D4B4, dword_12D4B0, 72);
  if ( *(uint32_t *)v2 )
    **(uint32_t **)(v2 + 4) = a2;
  else
    *(uint32_t *)v2 = a2;
  *(uint32_t *)(v2 + 4) = a2;
  *a2 = 0;
  return result;
}

