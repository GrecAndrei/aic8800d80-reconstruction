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

extern uint32_t dword_136094;
extern uint32_t dword_136098;
extern uint32_t dword_13609C;
extern uint32_t dword_1360A0;

// ipc_send_msg @ 0x136024, size 112 bytes
int  ipc_send_msg(int a1, uint16_t *a2, int16_t a3, int16_t a4)
{
  int v7; // r2
  int v9; // r7
  int v10; // r1
  int v11; // r2
  char v12; // r12

  check_status_bits(256, dword_136094, *a2);
  v7 = *a2;
  if ( *(uint8_t *)(dword_136098 + 1320 * v7 + 106) == 2 )
  {
    v9 = dword_13609C + 696 * (v7 + 32);
    v10 = *(uint32_t *)(a2 + 3);
    v11 = *(uint32_t *)(a2 + 5);
    v12 = *((uint8_t *)a2 + 14);
    *(uint32_t *)(v9 + 192) = *(uint32_t *)(a2 + 1);
    *(uint32_t *)(v9 + 196) = v10;
    *(uint32_t *)(v9 + 200) = v11;
    *(uint8_t *)(v9 + 204) = v12;
    check_status_bits(256, dword_1360A0, *((uint8_t *)a2 + 2));
    patch_check_version(v9);
  }
  ke_msg_send_no_param(7179, a4, a3);
  return 0;
}

