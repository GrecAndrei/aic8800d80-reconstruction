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

extern uint32_t dword_121C34;
extern uint32_t dword_121C38;
extern uint32_t off_121C40;
extern uint32_t off_121C3C;

// ke_send_msg @ 0x121b98, size 156 bytes
int  ke_send_msg(int a1, uint8_t *a2, uint8_t *a3)
{
  int v6; // r4
  int v8; // r5
  int v9; // r9
  int v10; // r0
  int v11; // r3
  uint8_t *v12; // r3
  int v13; // r1

  v6 = is_controller_active((int *)a1, a2);
  if ( v6 )
    return v6;
  v8 = *(uint8_t *)(a1 + 25);
  v9 = dword_121C34 + 696 * (uint8_t)*a2;
  *(uint8_t *)(v9 + 669) = 0;
  *(uint16_t *)(v9 + 670) = 0;
  v10 = ll_tx_setup((uint8_t)*a2, v8);
  *a3 = v10;
  v11 = *(uint32_t *)(v9 + 44);
  if ( v11 )
    v10 = ll_tx_setup(*(uint8_t *)(v11 + 35), *(uint8_t *)(a1 + 25));
  v12 = (uint8_t *)(dword_121C38 + 1320 * v8);
  if ( v12[106] )
  {
    if ( (uint8_t)*a2 <= 0x1Fu && v12[106] == 2 && !v12[1224] )
    {
      v13 = *(uint8_t *)off_121C40;
      ++*(uint8_t *)off_121C3C;
      if ( v13 == 1 )
        rf_rate_code_check_alt(v10);
    }
    return v6;
  }
  v12[116] = *a2;
  v12[117] = *(uint8_t *)(a1 + 29);
  v12[118] = *(uint8_t *)(a1 + 30);
  return 0;
}

