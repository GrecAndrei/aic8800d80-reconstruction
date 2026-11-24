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


extern uint32_t dword_136C28;
extern uint32_t dword_136C2C;
extern uint32_t off_136C30;

// rf_path_config @ 0x136b28, size 256 bytes
int  rf_path_config(int a1)
{
  uint8_t *v2; // r6
  int v3; // r0
  uint8_t *v4; // r5
  int *v5; // r3
  unsigned int v6; // r2
  uint8_t *v7; // r0
  int v8; // r0
  int v9; // r0
  int v10; // r1
  int v12; // r0

  v2 = (uint8_t *)bt_buf_alloc(5145, 5, 7, 2);
  v3 = bt_buf_alloc(5143, 5, 7, 2);
  *(uint8_t *)(dword_136C28 + 696 * (*(uint8_t *)(a1 + 107) + 32) + 37) = 0;
  v4 = (uint8_t *)v3;
  txpwr_get_context();
  *v2 = 0;
  v2[1] = *(uint8_t *)(a1 + 107);
  check_abort_flag(dword_136C2C, (uint32_t *)v2 - 3);
  v5 = *((int **)off_136C30 + 2);
  if ( v5 )
  {
    while ( 1 )
    {
      if ( (int *)a1 != v5 )
      {
        if ( *((uint8_t *)v5 + 108) )
        {
          v6 = *((uint16_t *)v5 + 208);
          if ( v6 <= 0x1387 )
            break;
        }
      }
      v5 = (int *)*v5;
      if ( !v5 )
        goto LABEL_6;
    }
    hw_reg_write(v6 | (*((uint8_t *)v5 + 413) << 16) | 0x80000000);
  }
  else
  {
LABEL_6:
    hw_reg_write(0);
  }
  bt_coex_control((int *)a1, 0, 0);
  if ( *(uint8_t *)(a1 + 108) )
  {
    v12 = bt_buf_alloc(30, 0, 7, 4);
    *(uint8_t *)(v12 + 2) = 0;
    *(uint8_t *)(v12 + 3) = *(uint8_t *)(a1 + 107);
    check_abort_flag(dword_136C2C, (uint32_t *)(v12 - 12));
  }
  if ( *(uint32_t *)(a1 + 72) )
  {
    v7 = (uint8_t *)bt_buf_alloc(57, 0, 7, 1);
    *v7 = *(uint8_t *)(a1 + 107);
    check_abort_flag(dword_136C2C, (uint32_t *)v7 - 3);
  }
  *v4 = 0;
  v8 = dword_136C2C;
  v4[1] = *(uint8_t *)(a1 + 107);
  v9 = check_abort_flag(v8, (uint32_t *)v4 - 3);
  txpwr_get_state(v9, v10);
  return hci_cmd_send(7u, 3);
}
