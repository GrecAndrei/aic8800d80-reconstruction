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


extern uint32_t dword_1149A0;
extern uint32_t off_114994;
extern uint32_t off_114998;

// hci_rx_data @ 0x114904, size 142 bytes
int  hci_rx_data(int a1, char *a2, unsigned int a3)
{
  uint32_t *v6; // r4
  int v7; // r8
  int v9; // [sp+0h] [bp-50h] BYREF
  int v10; // [sp+4h] [bp-4Ch]
  char a1a[64]; // [sp+10h] [bp-40h] BYREF

  if ( !*(uint32_t *)off_114994 )
    ke_event_busy_check(a1);
  v6 = off_114998;
  v7 = dword_1149A0;
  MEMORY[0x1D8](*(uint32_t *)off_114998, 80, &v9);
  if ( v9 == v7 )
  {
    v10 |= a1;
    if ( (a1 & 1) == 0 )
      goto LABEL_5;
  }
  else
  {
    memset_thunk(&v9, 0xFFu, 0x50u);
    v10 = a1;
    v9 = v7;
    if ( (a1 & 1) == 0 )
      goto LABEL_5;
  }
  memcpy_large(a1a, a2, 0x40u);
  if ( a3 <= 0x3F )
    dispatch_event_handler_1(aFlashBtdmInfoW);
LABEL_5:
  ke_event_schedule_alt();
  ke_event_schedule_prio();
  return MEMORY[0x1E0](*v6, 80);
}
