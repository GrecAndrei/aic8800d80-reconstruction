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

extern uint32_t dword_13593C;

// ke_msg_handler @ 0x1358c0, size 124 bytes
void  ke_msg_handler(
        uint16_t *a1,
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
  uint16_t *v13; // r6
  int v15; // r5
  int v16; // r1
  int v17; // r2
  int v18; // r3
  int v19; // r3
  int v20; // r3
  unsigned int v21; // r3

  v13 = a1 + 6;
  invalid_handler_12c5fc(6154, 6);
  v15 = v13[2];
  check_feature_flag(256, dword_13593C, v15);
  if ( v15 )
  {
    assert_trace(v15, v16, v17, v18, a5, a6, a7, a8, a9, a10, a11, a12, a13);
    return;
  }
  v19 = a1[6];
  if ( !a1[6] )
  {
LABEL_7:
    mac_dma_setup();
    return;
  }
  if ( v19 != 1 )
  {
    if ( v19 == 2 )
      ke_msg_alloc(*((uint8_t *)a1 + 8), (int)(a1 + 9), (uint16_t)(*a1 - 6));
    return;
  }
  v20 = v13[1];
  if ( v20 == 4 )
  {
    crypto_read_status(3000);
    goto LABEL_7;
  }
  if ( v20 == 2 )
  {
    v21 = *a1;
    if ( v21 > 0x22 )
      ll_evt_schedule(3, (char *)a1 + 20, v17, v21, a5, a6, a7, a8, a9, a10, a11, a12, a13);
  }
}

