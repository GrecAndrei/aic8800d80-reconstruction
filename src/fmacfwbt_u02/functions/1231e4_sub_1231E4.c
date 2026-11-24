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


extern uint32_t off_1232A4;
extern uint32_t off_1232A8;

// send_cmd_0x7c @ 0x1231e4, size 186 bytes
int  send_cmd_0x7c(int a1, uint8_t *a2, uint16_t a3, uint16_t a4)
{
  uint8_t *v5; // r5
  int v6; // r2
  int *v7; // r6
  unsigned int v8; // r7
  int v9; // r1
  int v11; // r2
  uint8_t a1a[5]; // [sp+7h] [bp-5h] BYREF

  a1a[0] = 0;
  v5 = (uint8_t *)bt_buf_alloc(124, a4, a3, 2);
  if ( *a2 )
  {
    ke_event_schedule_1(aDriverStart);
    **(uint8_t **)off_1232A4 = 0;
  }
  else
  {
    ke_event_schedule_1(aDriverStop);
    **(uint8_t **)off_1232A4 = 3;
  }
  rom_call_extract_byte(a1a);
  v6 = a1a[0];
  v5[1] = a1a[0];
  if ( a2[1] )
  {
    v7 = (int *)off_1232A8;
    LOBYTE(((uint32_t *)(uintptr_t)off_1232A8)[47]) = (v6 & 0x20) != 0;
    v8 = ((v6 ^ 0x40u) >> 6) & 1;
  }
  else
  {
    v11 = (uint8_t)a2[2];
    v7 = (int *)off_1232A8;
    v8 = ((v11 ^ 0x40u) >> 6) & 1;
    LOBYTE(((uint32_t *)(uintptr_t)off_1232A8)[47]) = (v11 & 0x20) != 0;
  }
  if ( get_hw_info_bit20() )
  {
    *((uint8_t *)v7 + 188) = 0;
    v9 = 0;
  }
  else
  {
    v9 = *((uint8_t *)v7 + 188);
  }
  if ( *a2 )
  {
    if ( a2[3] )
      *((uint16_t *)v7 + 89) |= 0x4000u;
    ke_event_schedule_1("is 5g=%d, sw_en=%d, vendor_info=0x%x\r\n", v9, v8, a1a[0]);
    LOBYTE(v9) = *((uint8_t *)v7 + 188);
  }
  *v5 = v9;
  hci_evt_send((int)v5);
  return 0;
}
