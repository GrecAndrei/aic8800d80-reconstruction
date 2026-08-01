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

extern uint32_t dword_132414;

// llm_env_reset @ 0x1323e4, size 46 bytes
int llm_env_reset()
{
  uint32_t *v0; // r0
  int v1; // r0
  int v2; // r0
  int v3; // r0
  int inited; // r0

  memset_byte((int *)dword_132414, 0, 0x17Cu);
  v0 = hci_cmd_send(5u, 0);
  v1 = dma_rx_reset(v0);
  v2 = txpwr_reset_state(v1);
  v3 = llm_get_ctrl_flags(v2);
  inited = rf_init_queues(v3);
  return dma_tx_reset(inited);
}

