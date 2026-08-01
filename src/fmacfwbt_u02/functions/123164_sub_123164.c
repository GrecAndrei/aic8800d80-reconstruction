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
extern uint32_t dword_1231E0;

// send_hci_reset_cmd @ 0x123164, size 120 bytes
int  send_hci_reset_cmd(int a1, int a2, int a3, int a4)
{
  uint8_t *v4; // r4
  uint16_t v5; // r3
  unsigned int v6; // r2
  int v7; // r0
  unsigned int v9; // [sp+0h] [bp-14h] BYREF
  unsigned int v10; // [sp+4h] [bp-10h] BYREF
  unsigned int v11[3]; // [sp+8h] [bp-Ch] BYREF

  v9 = 0;
  v10 = 0;
  v4 = (uint8_t *)bt_buf_alloc(116, a4, a3, 6);
  if ( (*(uint32_t *)off_1231DC & 0x2000000) != 0 )
  {
    syscall8_op(&v9, &v10);
    v6 = v9;
    v5 = v10;
  }
  else
  {
    memset(v11, 0, 6);
    ioctl2_cmd_2((int)v11);
    v5 = __rev16(LOWORD(v11[0]));
    v6 = bswap32(*(unsigned int *)((char *)v11 + 2));
    v9 = v6;
    v10 = v5;
  }
  v4[1] = v5;
  v4[5] = v6;
  *v4 = HIBYTE(v5);
  v4[3] = BYTE2(v6);
  v4[2] = HIBYTE(v6);
  v7 = dword_1231E0;
  v4[4] = BYTE1(v6);
  ke_event_schedule(v7, (uint32_t *)(uintptr_t)(HIBYTE(v5)), (uint8_t)v6);
  hci_evt_send(v4);
  return 0;
}

