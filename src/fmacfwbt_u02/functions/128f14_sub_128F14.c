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

extern uint32_t dword_128F78;
extern uint32_t dword_128F7C;
extern uint32_t off_128F80;
extern uint32_t off_128F84;

// log_alt_state_message @ 0x128f14, size 96 bytes
uint16_t * log_alt_state_message(int a1, int a2, int a3, int a4)
{
  uint16_t *result; // r0
  int *i; // r3
  int v8; // r3

  state_check_feature(2, dword_128F78);
  result = (uint16_t *)is_log_enabled(a1, a2, dword_128F7C);
  if ( result )
  {
    result = (uint16_t *)off_128F80;
    if ( !*((uint8_t *)off_128F80 + 8)
      || (v8 = (uint8_t)(*((uint8_t *)off_128F80 + 8) - 1), *((uint8_t *)off_128F80 + 8) = v8, !v8) )
    {
      for ( i = *((int **)off_128F84 + 2); i; i = (int *)*i )
      {
        if ( !*((uint8_t *)i + 106) )
        {
          if ( *((uint8_t *)i + 108) )
            i[1] &= 0xFFFFFFF1;
        }
      }
      *(uint8_t *)result = 0;
      return (uint16_t *)hci_evt_alloc_send(50, result[1], 0, a4);
    }
  }
  return result;
}

