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

extern uint32_t dword_1239AC;
extern uint32_t dword_1239B0;

// load_three_bytes @ 0x12391c, size 142 bytes
int  load_three_bytes(int a1, uint8_t *a2, int a3, int a4)
{
  int v5; // r6
  int v6; // r0
  int v7; // r1
  BOOL v9; // r0
  int v10; // r2
  char v11; // r6
  uint8_t *v12; // r0
  BOOL v14; // r0
  int v15; // r3
  int v16; // r1

  v5 = *a2;
  v6 = a2[1];
  v7 = a2[2];
  if ( v5 )
  {
    v14 = phy_read_channel(v6, v7);
    v10 = a3;
    if ( v14 )
    {
      get_instance_handle_cond(dword_1239AC + 696 * a2[1], a2[2], a3);
      v11 = 2;
      v10 = a3;
      goto LABEL_4;
    }
  }
  else
  {
    v9 = phy_read_band(v6, v7);
    v10 = a3;
    if ( v9 )
    {
      v15 = 696 * a2[1];
      v16 = dword_1239B0 + 32 * *(uint8_t *)(v15 + 12 * a2[2] + dword_1239AC + 453);
      *(uint16_t *)(v15 + 6 * a2[2] + dword_1239AC + 354) = 0;
      *(uint16_t *)(v16 + 12) = 0;
      v11 = 2;
      goto LABEL_4;
    }
  }
  v11 = 3;
LABEL_4:
  v12 = (uint8_t *)bt_buf_alloc(43, a4, v10, 3);
  *v12 = a2[1];
  v12[1] = a2[2];
  v12[2] = v11;
  hci_evt_send(v12);
  return 0;
}

