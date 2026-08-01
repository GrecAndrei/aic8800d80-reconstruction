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

extern uint32_t dword_123808;

// mem_setup_log @ 0x1237e0, size 40 bytes
int  mem_setup_log(int a1, int a2, int a3, int a4)
{
  rx_buf_align_desc(a2);
  check_feature_flag(256, dword_123808);
  mac_write_header_word(108, a4, a3);
  return 0;
}

