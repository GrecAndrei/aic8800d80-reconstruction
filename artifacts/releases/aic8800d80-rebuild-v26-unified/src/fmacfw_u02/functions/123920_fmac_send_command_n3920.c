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

extern uint32_t dword_123948;

// fmac_send_command_n3920 @ 0x123920, size 40 bytes
// Doc: fmac_send_command_n3920 [mac]: Prepare and send FMAC command, returns status
// fmac_send_command_n3920 [mac]: Prepare and send FMAC command, returns status
int  fmac_send_command_n3920(int a1, int a2, int a3, int a4)
{
  mem_block_free_n_490(a2);
  feature_guard_check(256, dword_123948);
  sub_12CA10(108, a4, a3);
  return 0;
}

