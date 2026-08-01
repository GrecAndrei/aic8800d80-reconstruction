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

// rx_queue_flush @ 0x117d6c, size 70 bytes
// Doc: sub_1217D6C [unknown]: Push-context helper loading offset 0x30 from argument struct
// sub_1217D6C [unknown]: Push-context helper loading offset 0x30 from argument struct
int  rx_queue_flush(int a1, int a2, int a3)
{
  int v3; // r4
  int v6; // r8
  int v7; // r0
  int v8; // r1

  v3 = *(uint32_t *)(a2 + 48);
  if ( v3 )
  {
    v3 = 0;
    v6 = a2 + 48;
    do
    {
      if ( !rf_is_idle() )
        break;
      v7 = list_pop_front(v6);
      v8 = *(uint8_t *)(v7 + 14);
      *(uint8_t *)(v7 + 53) = 0;
      ++v3;
      llm_scan_pdu_cfg(v7, v8);
      if ( a3 )
      {
        if ( v3 == a3 )
          break;
      }
    }
    while ( *(uint32_t *)(a2 + 48) );
  }
  return v3;
}

