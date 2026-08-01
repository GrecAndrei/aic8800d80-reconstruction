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

extern uint32_t dword_1235CC;

// rf_tx_start_cmd @ 0x12357c, size 80 bytes
// Doc: sub_122357C [ipc]: Invoke IPC/utility with cmd 0x54 sub 0xd, flag 1, arg 0
// sub_122357C [ipc]: Invoke IPC/utility with cmd 0x54 sub 0xd, flag 1, arg 0
int  rf_tx_start_cmd(int a1, uint8_t *a2)
{
  uint8_t *v3; // r0
  uint8_t *v4; // r4
  unsigned int v5; // r0

  v3 = (uint8_t *)ke_msg_alloc(84, 13, 0, 1);
  *v3 = 1;
  v4 = v3;
  v5 = *a2;
  if ( v5 > 4 || !*(uint8_t *)(dword_1235CC + 1320 * v5 + 1224) )
    goto LABEL_5;
  *v4 = 0;
  if ( a2[1] )
  {
    llc_get_conn_state();
LABEL_5:
    ke_msg_send(v4);
    return 0;
  }
  llc_get_conn_role();
  ke_msg_send(v4);
  return 0;
}

