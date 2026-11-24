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
extern uint32_t off_119674;
extern uint32_t off_119678;
extern uint32_t off_11967C;
extern uint32_t off_119680;
extern uint32_t off_119688;

// ke_alloc_msg_0x6a @ 0x11954c, size 288 bytes
int  ke_alloc_msg_0x6a(int a1, int a2, uint16_t a3, uint16_t a4)
{
  int v5; // r4
  int v6; // r3
  unsigned int v7; // r3
  unsigned int v8; // r0
  uint64_t v9; // r0
  int *v10; // r3
  int v12; // r1
  int v13; // r5
  uint16_t a1a; // [sp+2h] [bp-Ah] BYREF
  int a3a; // [sp+4h] [bp-8h] BYREF

  a1a = 0;
  v5 = ke_msg_send_1(106, a4, a3, 16);
  if ( (*(uint32_t *)off_11966C & 0x2000000) != 0 )
  {
    mmio_read_status(&a1a);
    mmio_read_byte((uint8_t *)&a1a + 1);
    dispatch_event_handler_1("read xtal_cap efuse=%x,%x\n", (uint8_t)a1a, HIBYTE(a1a));
    goto LABEL_16;
  }
  a3a = 0;
  if ( bus_read32((int)&a3a) )
  {
LABEL_16:
    v6 = (uint8_t)a1a;
    goto LABEL_4;
  }
  v6 = (uint8_t)a3a;
  a1a = a3a;
LABEL_4:
  if ( !v6 && *(uint8_t *)(a2 + 20) )
  {
    dispatch_event_handler_1("user cap:0x%x\n", *(uint8_t *)(a2 + 20));
    LOBYTE(a1a) = *(uint8_t *)(a2 + 20);
  }
  v7 = HIBYTE(a1a);
  if ( !HIBYTE(a1a) )
  {
    if ( *(uint8_t *)(a2 + 21) )
    {
      dispatch_event_handler_1("user cap_fine:0x%x\n", *(uint8_t *)(a2 + 21));
      v8 = (uint8_t)a1a;
      v7 = *(uint8_t *)(a2 + 21);
      HIBYTE(a1a) = *(uint8_t *)(a2 + 21);
      if ( !(uint8_t)a1a )
        goto LABEL_13;
    }
    else
    {
      v8 = (uint8_t)a1a;
      if ( !(uint8_t)a1a )
        goto LABEL_14;
    }
LABEL_10:
    if ( v8 > 0x1F )
    {
      v8 = 31;
      LOBYTE(a1a) = 31;
    }
    set_xtal_ftune(v8);
    dispatch_event_handler_1("set xtal_cap 0x%x\n", (uint8_t)a1a);
    v7 = HIBYTE(a1a);
LABEL_13:
    if ( !v7 )
      goto LABEL_14;
    goto LABEL_18;
  }
  v8 = (uint8_t)a1a;
  if ( (uint8_t)a1a )
    goto LABEL_10;
LABEL_18:
  if ( v7 > 0x3F )
  {
    v12 = 63;
    HIBYTE(a1a) = 63;
    v13 = 16515072;
  }
  else
  {
    v12 = HIBYTE(a1a);
    v13 = (HIBYTE(a1a) << 18) & 0xFC0000;
  }
  *(uint32_t *)off_119688 = *(uint32_t *)off_119688 & 0xFF03FFFF | v13;
  dispatch_event_handler_1("set xtal_cap_fine 0x%x\n", v12);
LABEL_14:
  LODWORD(v9) = off_119674[2];
  HIDWORD(v9) = *(uint32_t *)off_119678;
  v10 = (int *)off_119680;
  *(uint32_t *)(v5 + 12) = *(uint32_t *)off_11967C;
  *(uint64_t *)(v5 + 4) = v9;
  *(uint32_t *)v5 = v10;
  rx_irq_handler_1(v5);
  return 0;
}
