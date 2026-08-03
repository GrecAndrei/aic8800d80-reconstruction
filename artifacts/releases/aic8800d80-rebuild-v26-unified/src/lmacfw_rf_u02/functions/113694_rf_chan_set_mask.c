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

extern uint32_t dword_1136A4;

// rf_chan_set_mask @ 0x113694, size 16 bytes
// Doc: rf_chan_set_mask [rf]: Sets a 0x100 channel/mask register for RF configuration
// rf_chan_set_mask [rf]: Sets a 0x100 channel/mask register for RF configuration
int  rf_chan_set_mask(int a1, int a2)
{
  msg_parse(dword_1136A4, a2);
  return rf_stream_start_once();
}

