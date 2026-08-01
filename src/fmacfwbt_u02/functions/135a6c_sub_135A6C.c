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

extern uint32_t off_135B38;
extern uint32_t dword_135B3C;
extern uint32_t off_135B34;
extern uint32_t dword_135B48;
extern uint32_t dword_135B44;
extern uint32_t dword_135B40;

// rf_check_status @ 0x135a6c, size 200 bytes
// Doc: sub_1235A6C [bt]: Bluetooth task entry: dispatch handler using table lookup
// sub_1235A6C [bt]: Bluetooth task entry: dispatch handler using table lookup
int  rf_check_status(unsigned int a1)
{
  int v1; // r8
  int v2; // r7
  int v3; // r5
  uint8_t *v5; // r0
  uint32_t *v6; // r3
  int v7; // r1
  int *v8; // r2
  int v9; // r4
  int *v10; // r1
  int v11; // lr
  int v12; // r12
  int v13; // r0
  int v14; // r5
  int v15; // r0

  v1 = *((uint32_t *)off_135B38 + 4);
  v2 = dword_135B3C;
  v3 = *(uint8_t *)(v1 + 61);
  if ( **(int16_t **)off_135B34 < 0 && *(int *)(dword_135B3C + 1320 * v3 + 472) >= 0 )
    mmio_irq_clear(dword_135B48, dword_135B44, 1398);
  v5 = (uint8_t *)bt_buf_alloc(6150, 13, 6, 0x2Cu);
  *v5 = *(uint8_t *)(v1 + 61);
  v6 = v5 + 1;
  v7 = v2 + 1320 * v3;
  v8 = (int *)(v7 + 374);
  v9 = (int)v5;
  v10 = (int *)(v7 + 406);
  do
  {
    v11 = *v8;
    v12 = v8[1];
    v13 = v8[2];
    v6[3] = v8[3];
    v8 += 4;
    *v6 = v11;
    v6[1] = v12;
    v6[2] = v13;
    v6 += 4;
  }
  while ( v8 != v10 );
  *(uint8_t *)v6 = *(uint8_t *)v8;
  v14 = v2 + 1320 * v3;
  v15 = *(uint32_t *)(v14 + 368);
  *(uint16_t *)(v9 + 38) = *(uint16_t *)(v14 + 372);
  *(uint32_t *)(v9 + 34) = v15;
  *(uint32_t *)(v9 + 40) = bswap32(a1);
  hci_cmd_send(6u, 6);
  patch_aware_dispatch(6154, 6, dword_135B40);
  return hci_evt_send(v9);
}

