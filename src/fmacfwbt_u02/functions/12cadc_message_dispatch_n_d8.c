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

// find_hci_conn_by_handle @ 0x12cadc, size 32 bytes
// Doc: find_hci_conn_by_handle [ipc]: Dispatches incoming message based on header field to handlers
// find_hci_conn_by_handle [ipc]: Dispatches incoming message based on header field to handlers
int  find_hci_conn_by_handle(int a1, int a2)
{
  int **v2; // r3

  v2 = *((int ***)rf_level_apply_n21a + 5);
  if ( !v2 )
    return (int)v2;
  while ( *((uint16_t *)v2 + 2) != a1 || *((uint16_t *)v2 + 3) != a2 )
  {
    v2 = (int **)*v2;
    if ( !v2 )
      return (int)v2;
  }
  return 1;
}

