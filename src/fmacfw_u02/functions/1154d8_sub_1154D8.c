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

extern uint32_t off_11558C;
extern uint32_t off_1155A4;
extern uint32_t dword_1155AC;
extern uint32_t dword_115594;

// check_init_status @ 0x1154d8, size 180 bytes
// Doc: sdio_buffer_prepare_n_11c [util]: Initializes SDIO buffer descriptor chain
// sdio_buffer_prepare_n_11c [util]: Initializes SDIO buffer descriptor chain
int check_init_status()
{
  uint8_t *v0; // r4
  int result; // r0
  uint32_t *v2; // r3
  int v3; // r3

  v0 = off_11558C;
  if ( !*(uint8_t *)off_11558C && *(uint8_t *)ipc_doorbell_handler_n_3ec )
  {
    result = check_status_bits(2, patch_apply_n2e0);
    v2 = ipc_doorbell_handler_n_3dc;
    *v0 = 1;
    if ( (uint16_t)*v2 )
    {
      switch ( *(uint8_t *)off_1155A4 )
      {
        case 1:
          v3 = 700 * (uint16_t)*(uint32_t *)ipc_doorbell_handler_n_3dc;
          break;
        case 2:
          v3 = 500 * (uint16_t)*(uint32_t *)ipc_doorbell_handler_n_3dc;
          break;
        case 3:
          v3 = 300 * (uint16_t)*(uint32_t *)ipc_doorbell_handler_n_3dc;
          break;
        case 4:
          v3 = 200 * (uint16_t)*(uint32_t *)ipc_doorbell_handler_n_3dc;
          break;
        case 5:
          v3 = 100 * (uint16_t)*(uint32_t *)ipc_doorbell_handler_n_3dc;
          break;
        default:
          v3 = 100 * (uint16_t)*(uint32_t *)ipc_doorbell_handler_n_3dc;
          break;
      }
      return unknown_worker(dword_1155AC, *((uint32_t *)ipc_doorbell_handler_n_3d4 + 4) + v3);
    }
  }
  else
  {
    result = check_status_bits(2, dword_115594);
    if ( *((uint8_t *)ipc_doorbell_handler_n_3e4 + 18) )
      *v0 = 0;
  }
  return result;
}

