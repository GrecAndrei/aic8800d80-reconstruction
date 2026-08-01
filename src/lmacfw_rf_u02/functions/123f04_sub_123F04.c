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

extern uint32_t dword_123F48;

// format_message @ 0x123f04, size 68 bytes
int  format_message(int a1, int a2, int16_t a3, int16_t a4)
{
  int v5; // r0
  int v6; // r4
  int v9; // [sp+8h] [bp-8h] BYREF
  int v10; // [sp+Ch] [bp-4h] BYREF

  chip_id_get(&v9, &v10);
  v5 = ke_msg_send(2, a4, a3, 0x48u);
  v6 = v5;
  if ( (BYTE2(v9) & 3) == 2 )
    memcpy_large(v5, dword_123F48, 33);
  *(uint32_t *)(v6 + 64) = 255;
  rx_irq_handler(v6);
  return 0;
}

