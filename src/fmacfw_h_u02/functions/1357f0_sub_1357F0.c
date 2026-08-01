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

extern uint32_t dword_135820;

// ke_msg_send @ 0x1357f0, size 46 bytes
void  ke_msg_send(
        int a1,
        int a2,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13)
{
  int v14; // r1
  int v15; // r2
  int v16; // r3

  invalid_handler_12c5fc(6154, 6);
  if ( a1 )
  {
    check_feature_flag(256, dword_135820, a1);
    assert_trace(a1, v14, v15, v16, a5, a6, a7, a8, a9, a10, a11, a12, a13);
  }
  else
  {
    mac_dma_setup();
  }
}

