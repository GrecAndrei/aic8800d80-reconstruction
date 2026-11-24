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
  memset_byte((int *)dword_132414, 0, 0x17Cu);
  hci_cmd_send(5u, 0);
  dma_rx_reset();
  txpwr_reset_state();
  llm_get_ctrl_flags();
  rf_init_queues();
  return dma_tx_reset_1();
}
