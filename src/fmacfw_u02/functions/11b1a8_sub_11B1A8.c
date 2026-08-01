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

extern uint32_t dword_11B1F0;

// get_connection_by_index @ 0x11b1a8, size 72 bytes
int  get_connection_by_index(int a1, int a2)
{
  int v4; // r5
  int v5; // r8
  int v6; // r2

  v4 = dword_11B1F0 + 84 * a2;
  v5 = *(uint32_t *)(a1 + 76);
  mem_word_load(84 * (int16_t)a2 + 12 + dword_11B1F0);
  v6 = *(uint16_t *)(a1 + 4);
  --*(uint8_t *)(v4 + 80);
  if ( v6 )
    return ipc_handler_register(a1, *(uint32_t *)(v5 + 72), a2);
  else
    return free_buf_1882c0();
}

