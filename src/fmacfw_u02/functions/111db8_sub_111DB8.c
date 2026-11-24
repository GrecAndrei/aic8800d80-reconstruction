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


extern uint32_t dword_111EF4;
extern uint32_t off_111EC4;
extern uint32_t off_111EC8;
extern uint32_t off_111ECC;
extern uint32_t off_111ED0;
extern uint32_t off_111ED8;
extern uint32_t off_111EDC;
extern uint32_t off_111EE0;
extern uint32_t off_111EE8;
extern uint32_t off_111EEC;
extern uint32_t off_111EF0;

// cmd_dispatch @ 0x111db8, size 262 bytes
int  cmd_dispatch(int a1, int a2)
{
  uint8_t *v4; // r6
  int *v5; // r7
  char *v6; // r0
  int v7; // r1
  uint32_t *v8; // r4
  uint32_t *v9; // r3
  uint8_t *v11; // r7
  int v12; // r0
  int v13; // r1
  uint32_t *v14; // r3
  void ( *v15)(int); // r2

  event_dispatch("open:%d/%d\n", 0, a2);
  if ( !a1 )
    return 1;
  if ( !*(uint32_t *)a1 || !*(uint32_t *)(a1 + 4) || !*(uint32_t *)(a1 + 8) || !*(uint32_t *)(a1 + 20) )
    return 2;
  v4 = off_111EC4;
  if ( *(uint8_t *)off_111EC4 )
    return 3;
  v5 = (int *)off_111EC8;
  v6 = (char *)off_111ECC;
  *(uint8_t *)off_111EC4 = 1;
  memcpy(v6, (char *)a1, 0x50u);
  v7 = v5[97];
  if ( v7 )
  {
    event_dispatch("usb sftdiscon delay %d\n", v7);
    timer_delay(v5[97]);
  }
  v8 = off_111ED0;
  if ( (*((uint32_t *)off_111ED0 + 512) & 0x7F0) != 0 )
  {
    v11 = off_111EE8;
    *((uint32_t *)off_111EE8 + 1) = 0;
    *((uint32_t *)v11 + 2) = 0;
    *v11 = 0;
    *v4 = 4;
    v12 = mmio_sync();
    v13 = *(uint32_t *)off_111EEC;
    v14 = *(uint32_t **)off_111EF0;
    *v14 = dword_111EF4;
    v14[1] = v13;
    v8[709] = v14;
    v8[706] = v8[706];
    v15 = *((void ( **)(int))off_111ECC + 19);
    v8[704] |= 0x84000000;
    *v11 = 1;
    if ( v15 )
      v15(v12);
  }
  else
  {
    if ( (*((uint32_t *)off_111ED0 + 2) & 1) != 0 )
    {
      *((uint32_t *)off_111ED0 + 2) &= ~1u;
      v8[513] |= 2u;
    }
    mmio_set_bit();
  }
  event_dispatch(aEnableIrq);
  v9 = off_111EE0;
  *(uint32_t *)(*((uint32_t *)off_111ED8 + 2) + 320) = off_111EDC;
  v9[2] = 1;
  if ( a2 == 1 )
  {
    while ( *v4 != 4 )
      ;
  }
  event_dispatch(aOpenDone);
  return 0;
}
