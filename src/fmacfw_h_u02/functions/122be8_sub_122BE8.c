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


extern uint32_t off_122DC0;
extern uint32_t off_122DC4;
extern uint32_t off_122DD0;
extern uint32_t off_122DD4;
extern uint32_t off_122DE0;
extern uint32_t off_151B28;

// ke_send_msg_6a @ 0x122be8, size 472 bytes
int  ke_send_msg_6a(int a1, int *a2, uint16_t a3, uint16_t a4)
{
  int v5; // r4
  int v6; // r3
  unsigned int v7; // r3
  unsigned int v8; // r0
  int v9; // r7
  uint64_t v10; // r0
  int *v11; // r3
  int v13; // r1
  int v14; // r6
  uint8_t a1a[2]; // [sp+Ah] [bp-92h] BYREF
  uint32_t v16[2]; // [sp+Ch] [bp-90h] BYREF
  uint8_t v17[136]; // [sp+14h] [bp-88h] BYREF

  a1a[0] = 0;
  a1a[1] = 0;
  v5 = tx_send_pdu(106, a4, a3, 16);
  if ( (*(uint32_t *)off_122DC0 & 0x2000000) != 0 )
  {
    rf_cmd_6_read(a1a);
    rf_cmd_6_version(&a1a[1]);
    alloc_tx_event("read xtal_cap efuse=%x,%x\n", a1a[0], a1a[1]);
    v6 = a1a[0];
  }
  else
  {
    *(uint32_t *)v17 = 0;
    if ( send_smc_cmd_2((int)v17) )
    {
      v6 = a1a[0];
    }
    else
    {
      v6 = v17[0];
      a1a[0] = v17[0];
      a1a[1] = v17[1];
    }
  }
  if ( !v6 && *((uint8_t *)a2 + 20) )
  {
    alloc_tx_event("user cap:0x%x\n", *((uint8_t *)a2 + 20));
    a1a[0] = *((uint8_t *)a2 + 20);
  }
  v7 = a1a[1];
  if ( a1a[1] )
  {
    v8 = a1a[0];
    if ( !a1a[0] )
      goto LABEL_20;
  }
  else if ( *((uint8_t *)a2 + 21) )
  {
    alloc_tx_event("user cap_fine:0x%x\n", *((uint8_t *)a2 + 21));
    v8 = a1a[0];
    v7 = *((uint8_t *)a2 + 21);
    a1a[1] = *((uint8_t *)a2 + 21);
    if ( !a1a[0] )
      goto LABEL_19;
  }
  else
  {
    v8 = a1a[0];
    if ( !a1a[0] )
      goto LABEL_10;
  }
  if ( v8 > 0x1F )
  {
    v8 = 31;
    a1a[0] = 31;
  }
  padding_data(v8);
  alloc_tx_event("set xtal_cap 0x%x\n", a1a[0]);
  v7 = a1a[1];
LABEL_19:
  if ( !v7 )
  {
LABEL_10:
    if ( !a2[3] )
      goto LABEL_11;
    goto LABEL_23;
  }
LABEL_20:
  if ( v7 > 0x3F )
  {
    v13 = 63;
    a1a[1] = 63;
    v14 = 16515072;
  }
  else
  {
    v13 = a1a[1];
    v14 = (a1a[1] << 18) & 0xFC0000;
  }
  *(uint32_t *)off_122DE0 = *(uint32_t *)off_122DE0 & 0xFF03FFFF | v14;
  alloc_tx_event("set xtal_cap_fine 0x%x\n", v13);
  if ( !a2[3] )
    goto LABEL_11;
LABEL_23:
  interrupt_dispatcher();
LABEL_11:
  v9 = *a2;
  v16[1] = a2[2];
  v16[0] = v9;
  rf_register_write(0, 2437, (int)v16, (int)v17, 1u, 0);
  if ( LOBYTE(((uint32_t *)(uintptr_t)off_122DC4)[47]) )
  {
    v16[0] = a2[1];
    rf_register_write(1, 5700, (int)v16, (int)v17, 1u, 0);
    rf_register_write(1, 5250, (int)v16, (int)v17, 1u, 0);
    rf_register_write(1, 5500, (int)v16, (int)v17, 1u, 0);
    rf_register_write(1, 5500, (int)v16, (int)v17, 0, 1u);
    rf_calibrate_tx(0, 0x985u, 0x985u, 0, 0, 0);
  }
  v10 = __PAIR64__(*(unsigned int *)aX, (unsigned int)off_151B28);
  v11 = (int *)off_122DD4;
  *(uint32_t *)(v5 + 12) = ((uint32_t *)(uintptr_t)off_122DD0)[0];
  *(uint64_t *)(v5 + 4) = v10;
  *(uint32_t *)v5 = v11;
  rx_process_packet_1(v5);
  return 0;
}
