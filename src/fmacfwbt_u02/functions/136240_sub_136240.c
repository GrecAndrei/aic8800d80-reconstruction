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


extern uint32_t dword_1362B4;
extern uint32_t dword_1362B8;

// patch_copy_data @ 0x136240, size 112 bytes
int  patch_copy_data(int a1, uint16_t *a2, int a3, int a4)
{
  int v7; // r2
  int v9; // r7
  int v10; // r1
  int v11; // r2
  char v12; // r12

  state_check_feature(256, "apm_update_basicrate:%d\r\n", *a2);
  v7 = *a2;
  if ( *(uint8_t *)(dword_1362B4 + 1320 * v7 + 106) == 2 )
  {
    v9 = dword_1362B8 + 696 * (v7 + 32);
    v10 = *(uint32_t *)(a2 + 3);
    v11 = *(uint32_t *)(a2 + 5);
    v12 = *((uint8_t *)a2 + 14);
    *(uint32_t *)(v9 + 192) = *(uint32_t *)(a2 + 1);
    *(uint32_t *)(v9 + 196) = v10;
    *(uint32_t *)(v9 + 200) = v11;
    *(uint8_t *)(v9 + 204) = v12;
    state_check_feature(256, "param->basic_rates:%d\r\n", *((uint8_t *)a2 + 2));
    bt_get_local_addr_type(v9);
  }
  hci_evt_alloc_send(7179, a4, a3);
  return 0;
}
