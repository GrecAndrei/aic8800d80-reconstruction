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

extern uint32_t dword_11C03C;
extern uint32_t off_11C038;

// mac_get_link_context @ 0x11bff4, size 68 bytes
// Doc: mac_get_link_context [bt]: Looks up table entry indexed by [base+0xbe] scaled by 0x54
// mac_get_link_context [bt]: Looks up table entry indexed by [base+0xbe] scaled by 0x54
int  mac_get_link_context(int a1, int a2)
{
  int v2; // r6
  int v3; // r5
  int result; // r0
  int v6; // r5

  v2 = dword_11C03C;
  v3 = *((uint8_t *)off_11C038 + 190);
  list_pop_front(dword_11C03C + 84 * v3 + 12);
  result = list_append(a1, a2, v3);
  if ( (*(uint32_t *)(a1 + 36) & 0x380000) == 0x380000 )
  {
    v6 = v2 + 84 * v3;
    *(uint32_t *)(v6 + 36) = *(uint32_t *)(a1 + 68);
    *(uint8_t *)(v6 + 26) = 2;
  }
  return result;
}

