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

extern uint32_t dword_136F1C;

// sub_136EFC @ 0x136efc, size 32 bytes
// Doc: sub_1236EFC [ipc]: Calls message dispatch init/registration
// sub_1236EFC [ipc]: Calls message dispatch init/registration
int  sub_136EFC(int a1, int a2, int a3, int16_t a4)
{
  int v4; // r0

  v4 = sub_12C92C(4107, a4, 4, 1u);
  sdio_buffer_prepare_n_4e8(v4);
  feature_guard_check(8, dword_136F1C);
  return 0;
}

