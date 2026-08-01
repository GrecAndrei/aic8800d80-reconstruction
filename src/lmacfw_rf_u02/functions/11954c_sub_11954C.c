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

extern uint32_t off_11966C;
extern uint32_t dword_119684;
extern uint32_t dword_119694;
extern uint32_t dword_119690;
extern uint32_t dword_119670;
extern uint32_t dword_11968C;
extern uint32_t off_119688;
extern uint32_t off_119674;
extern uint32_t off_119678;
extern uint32_t dword_119680;
extern uint32_t off_11967C;

// ke_alloc_msg_0x6a @ 0x11954c, size 288 bytes
// Doc: sub_121954C [rf]: Issue sub-call with opcode 0x6a via dispatch
// sub_121954C [rf]: Issue sub-call with opcode 0x6a via dispatch
int  ke_alloc_msg_0x6a(int a1, int a2, int a3, int a4)
{
  int v5; // r4
  int v6; // r3
  unsigned int v7; // r3
  unsigned int v8; // r0
  uint64_t v9; // r0
  int v10; // r3
  int v12; // r1
  int v13; // r5
  int v14; // r0
  int16_t v15; // [sp+2h] [bp-Ah] BYREF
  int v16; // [sp+4h] [bp-8h] BYREF

  v15 = 0;
  v5 = ke_msg_send(106, a4, a3, 16);
  if ( (*(uint32_t *)off_11966C & 0x2000000) != 0 )
  {
    mmio_read_status(&v15);
    mmio_read_byte((uint8_t *)&v15 + 1);
    dispatch_event_handler(dword_119684, (uint8_t)v15);
    goto LABEL_16;
  }
  v16 = 0;
  if ( bus_read32((int)&v16) )
  {
LABEL_16:
    v6 = (uint8_t)v15;
    goto LABEL_4;
  }
  v6 = (uint8_t)v16;
  v15 = v16;
LABEL_4:
  if ( !v6 && *(uint8_t *)(a2 + 20) )
  {
    dispatch_event_handler(dword_119694, *(uint8_t *)(a2 + 20));
    LOBYTE(v15) = *(uint8_t *)(a2 + 20);
  }
  v7 = HIBYTE(v15);
  if ( !HIBYTE(v15) )
  {
    if ( *(uint8_t *)(a2 + 21) )
    {
      dispatch_event_handler(dword_119690, *(uint8_t *)(a2 + 21));
      v8 = (uint8_t)v15;
      v7 = *(uint8_t *)(a2 + 21);
      HIBYTE(v15) = *(uint8_t *)(a2 + 21);
      if ( !(uint8_t)v15 )
        goto LABEL_13;
    }
    else
    {
      v8 = (uint8_t)v15;
      if ( !(uint8_t)v15 )
        goto LABEL_14;
    }
LABEL_10:
    if ( v8 > 0x1F )
    {
      v8 = 31;
      LOBYTE(v15) = 31;
    }
    set_xtal_ftune(v8);
    dispatch_event_handler(dword_119670, (uint8_t)v15);
    v7 = HIBYTE(v15);
LABEL_13:
    if ( !v7 )
      goto LABEL_14;
    goto LABEL_18;
  }
  v8 = (uint8_t)v15;
  if ( (uint8_t)v15 )
    goto LABEL_10;
LABEL_18:
  if ( v7 > 0x3F )
  {
    v12 = 63;
    HIBYTE(v15) = 63;
    v13 = 16515072;
  }
  else
  {
    v12 = HIBYTE(v15);
    v13 = (HIBYTE(v15) << 18) & 0xFC0000;
  }
  v14 = dword_11968C;
  *(uint32_t *)off_119688 = *(uint32_t *)off_119688 & 0xFF03FFFF | v13;
  dispatch_event_handler(v14, v12);
LABEL_14:
  LODWORD(v9) = *((uint32_t *)off_119674 + 2);
  HIDWORD(v9) = *(uint32_t *)off_119678;
  v10 = dword_119680;
  *(uint32_t *)(v5 + 12) = *(uint32_t *)off_11967C;
  *(uint64_t *)(v5 + 4) = v9;
  *(uint32_t *)v5 = v10;
  rx_irq_handler(v5);
  return 0;
}

