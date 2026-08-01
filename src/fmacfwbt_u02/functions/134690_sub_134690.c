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

extern uint32_t off_1346D8;

// ull_scan_event_start @ 0x134690, size 72 bytes
// Doc: sub_1234690 [mac]: initializes state and clears outptr/inptr slots
// sub_1234690 [mac]: initializes state and clears outptr/inptr slots
int  ull_scan_event_start(uint32_t *a1, uint32_t *a2)
{
  int v2; // r6
  int result; // r0

  v2 = *((uint32_t *)off_1346D8 + 4);
  *a1 = 0;
  *a2 = 0;
  if ( (*(uint8_t *)(v2 + 34) & 1) != 0 )
  {
    result = parse_pdu_data(v2);
    if ( result )
    {
      *a1 = result + 2;
LABEL_4:
      *a2 = *(uint32_t *)(result + 44);
      return result;
    }
  }
  else
  {
    *a1 = v2 + 34;
    result = lookup_handle_entry();
    if ( result )
      goto LABEL_4;
  }
  if ( *(uint16_t *)(v2 + 40) != 0xFFFF )
    *a2 = v2 + 40;
  return result;
}

