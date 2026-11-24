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


extern uint32_t dword_126A3C;
extern uint32_t dword_126A44;
extern uint32_t off_126A40;

// hci_acl_buf_alloc @ 0x126a04, size 56 bytes
uint32_t *hci_acl_buf_alloc()
{
  uint32_t *result; // r0
  uint32_t *v1; // r4
  uint32_t *v2; // r1
  int v3; // r5
  int v4; // r4
  uint32_t *a2; // [sp+4h] [bp-8h]

  result = list_pop_front(dword_126A3C);
  a2 = result;
  if ( result )
  {
    v1 = off_126A40;
    ke_event_set_lock((uint32_t *)dword_126A44);
    v2 = a2;
    v1[18] = 0;
    v3 = (int)(v1 + 6);
    v4 = (int)(v1 + 8);
    do
    {
      check_abort_flag(v3, v2);
      result = list_pop_front(v4);
      v2 = result;
    }
    while ( result );
  }
  return result;
}
