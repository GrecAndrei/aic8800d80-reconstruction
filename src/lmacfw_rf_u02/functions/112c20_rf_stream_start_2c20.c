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

extern uint32_t off_112CA4;
extern uint32_t off_112CA8;
extern uint32_t dword_112CB8;
extern uint32_t dword_112CB4;
extern uint32_t off_112CAC;
extern uint32_t dword_112CBC;
extern uint32_t off_112CB0;

// send_data_packet @ 0x112c20, size 130 bytes
// Doc: sdio_buffer_prepare_n1dc [mmio]: Prepare SDIO transfer buffer alignment and descriptor
// sdio_buffer_prepare_n1dc [mmio]: Prepare SDIO transfer buffer alignment and descriptor
int  send_data_packet(int a1, unsigned int a2)
{
  uint8_t *v2; // r4
  uint8_t *v3; // r6
  uint32_t *v4; // r7
  int v5; // r0
  int v6; // r2

  v2 = off_112CA4;
  if ( *(uint8_t *)off_112CA4 )
    return -14;
  if ( !a1 || !a2 )
    return -11;
  v3 = off_112CA8;
  if ( *(uint8_t *)off_112CA8 )
  {
    log_printf(dword_112CB8, dword_112CB4, *(uint8_t *)off_112CA8);
    return -3;
  }
  else
  {
    v4 = off_112CAC;
    *(uint8_t *)off_112CA8 = 1;
    v4[716] &= 0xE007FFFF;
    v5 = rf_channel_update(1, a1, a2);
    v6 = v5;
    if ( v5 )
    {
      log_printf(dword_112CBC, dword_112CB4, v5);
      return -1;
    }
    else
    {
      *(uint8_t *)off_112CB0 = 1;
      if ( *v2 )
      {
        rf_enable_tx_patch_dup(0, 1u);
        *v3 = 0;
        return -14;
      }
    }
  }
  return v6;
}

