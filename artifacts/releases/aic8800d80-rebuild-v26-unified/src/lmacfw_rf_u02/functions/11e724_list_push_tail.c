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

extern uint32_t off_11E760;
extern uint32_t dword_11E768;

// list_push_tail @ 0x11e724, size 60 bytes
// Doc: sdio_buffer_prepare_n_46e [mmio]: Prepares an SDIO buffer descriptor for host data transfer
// sdio_buffer_prepare_n_46e [mmio]: Prepares an SDIO buffer descriptor for host data transfer
int  list_push_tail(int result, uint32_t *a2)
{
  int v2; // r5

  v2 = result;
  if ( **(int16_t **)off_11E760 < 0 && !a2 )
    result = rf_cmd_send_n264(dword_11E768, sdio_buffer_prepare_n_450, 72);
  if ( *(uint32_t *)v2 )
    **(uint32_t **)(v2 + 4) = a2;
  else
    *(uint32_t *)v2 = a2;
  *(uint32_t *)(v2 + 4) = a2;
  *a2 = 0;
  return result;
}

