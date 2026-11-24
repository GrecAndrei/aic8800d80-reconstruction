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


extern uint32_t off_1231DC;

// send_hci_reset_cmd @ 0x123164, size 120 bytes
int  send_hci_reset_cmd(int a1, int a2, uint16_t a3, uint16_t a4)
{
  uint8_t *v4; // r4
  uint16_t v5; // r3
  unsigned int v6; // r2
  unsigned int v8; // [sp+0h] [bp-14h] BYREF
  unsigned int a2a; // [sp+4h] [bp-10h] BYREF
  unsigned int v10[3]; // [sp+8h] [bp-Ch] BYREF

  v8 = 0;
  a2a = 0;
  v4 = (uint8_t *)bt_buf_alloc(116, a4, a3, 6);
  if ( (*(uint32_t *)off_1231DC & 0x2000000) != 0 )
  {
    syscall8_op(&v8, &a2a);
    v6 = v8;
    v5 = a2a;
  }
  else
  {
    memset(v10, 0, 6);
    ioctl2_cmd_2((int)v10);
    v5 = __rev16(LOWORD(v10[0]));
    v6 = bswap32(*(unsigned int *)((char *)v10 + 2));
    v8 = v6;
    a2a = v5;
  }
  v4[1] = v5;
  v4[5] = v6;
  *v4 = HIBYTE(v5);
  v4[3] = BYTE2(v6);
  v4[2] = HIBYTE(v6);
  v4[4] = BYTE1(v6);
  ke_event_schedule_1(aGetMacaddrXX, HIBYTE(v5), (uint8_t)v6, HIBYTE(v6), v8, a2a);
  hci_evt_send((int)v4);
  return 0;
}
