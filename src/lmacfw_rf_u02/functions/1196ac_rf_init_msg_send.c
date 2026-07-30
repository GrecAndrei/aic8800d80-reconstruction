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

extern uint32_t off_119724;
extern uint32_t dword_119728;

// rf_init_msg_send @ 0x1196ac, size 120 bytes
// Doc: rf_init_msg_send [ipc]: Build and send RF init message (op 0x74) via ipc_send
// rf_init_msg_send [ipc]: Build and send RF init message (op 0x74) via ipc_send
int  rf_init_msg_send(int a1, int a2, int a3, int a4)
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
  v4 = (uint8_t *)rf_setup_dispatch(116, a4, a3, 6);
  if ( (*(uint32_t *)off_119724 & 0x2000000) != 0 )
  {
    sub_113C48((int *)&v9, &v10);
    v6 = v9;
    v5 = v10;
  }
  else
  {
    memset(v11, 0, 6);
    rf_reg_write_setup_n4820((int)v11);
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
  v7 = dword_119728;
  v4[4] = BYTE1(v6);
  msg_parse(v7, HIBYTE(v5));
  sub_11DE50(v4);
  return 0;
}

