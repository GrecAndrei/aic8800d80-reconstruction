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

// process_llcp_pdu @ 0x119af4, size 54 bytes
int  process_llcp_pdu(int a1, uint8_t *a2, int a3, int a4)
{
  char v7; // r0
  char v9; // r6
  uint8_t *v10; // r0

  v7 = tx_header_prepare(a2, a4);
  if ( a4 )
  {
    v9 = v7;
    v10 = (uint8_t *)ke_msg_send(71, a4, a3, 3);
    *v10 = *a2;
    v10[1] = v9;
    v10[2] = 4;
    rx_irq_handler(v10);
  }
  return 0;
}

