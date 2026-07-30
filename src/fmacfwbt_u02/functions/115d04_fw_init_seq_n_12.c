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

extern uint32_t off_115D24;

// fw_init_seq_n_12 @ 0x115d04, size 32 bytes
// Doc: fw_init_seq_n_12 [util]: FW init sequence: clear state and call subroutines
// fw_init_seq_n_12 [util]: FW init sequence: clear state and call subroutines
int fw_init_seq_n_12()
{
  int inited; // r0
  int v1; // r0
  int v2; // r0
  int v3; // r0

  *((uint8_t *)off_115D24 + 1) = 0;
  inited = fw_buffer_init_n478();
  v1 = sub_1323E4(inited);
  v2 = sub_120A58(v1);
  v3 = sub_12D438(v2);
  return mem_clear_init(v3);
}

