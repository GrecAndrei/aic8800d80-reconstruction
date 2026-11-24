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


extern uint32_t dword_110E30;
extern uint32_t dword_110E4C;
extern uint32_t dword_110E5C;
extern uint32_t dword_110E64;
extern uint32_t off_110E20;
extern uint32_t off_110E24;
extern uint32_t off_110E2C;
extern uint32_t off_110E34;
extern uint32_t off_110E38;
extern uint32_t off_110E3C;
extern uint32_t off_110E40;
extern uint32_t off_110E44;
extern uint32_t off_110E48;
extern uint32_t off_110E50;
extern uint32_t off_110E54;
extern uint32_t off_110E58;
extern uint32_t off_110E6C;
extern uint32_t off_110E70;
extern uint32_t off_110E74;

// rf_tx_start @ 0x110c80, size 414 bytes
int rf_tx_start()
{
  uint32_t *v0; // r3
  uint32_t *v1; // r1
  int *v2; // r4
  unsigned int *v3; // r5
  unsigned int *v4; // r2
  uint32_t *v5; // r0
  uint32_t *v6; // r7
  uint32_t *v7; // r6
  int v8; // r1
  uint32_t *v9; // r3
  uint32_t *v10; // r2
  uint32_t *v11; // r0
  int v12; // r1
  int *v13; // r3
  int v14; // r1
  void *v15; // r2
  uint32_t *v16; // r1
  int result; // r0
  uint32_t *v18; // r3
  unsigned int *v19; // r2
  unsigned int *v20; // r1

  v0 = off_110E24;
  *(uint32_t *)off_110E20 = 16;
  if ( (*v0 & 4) != 0 )
  {
    v19 = (unsigned int *)off_110E54;
    v20 = (unsigned int *)off_110E38;
    *(uint32_t *)off_110E54 = *(uint32_t *)off_110E54 & 0x8000FFFF | 0x4E200000;
    *v19 = *v19 & 0xFFFF8000 | 0x4E20;
    *v20 = *v20 & 0xFFFFF000 | 0x960;
    result = (int)send_cmd_040d();
  }
  else
  {
    ke_event_schedule_1(aWaitCmd5);
    do
    {
      while ( (*(uint32_t *)off_110E2C & 0x20000000) != 0 )
        ;
    }
    while ( *(int *)off_110E2C < 0 );
    v1 = off_110E2C;
    *(uint32_t *)off_110E2C = dword_110E30;
    while ( (*v1 & 0x20000000) != 0 )
      ;
    if ( (*v1 & 2) == 0 )
    {
      while ( (*(uint32_t *)off_110E24 & 1) == 0 )
        ;
    }
    v2 = (int *)off_110E34;
    v3 = (unsigned int *)off_110E38;
    v4 = (unsigned int *)off_110E3C;
    v5 = off_110E40;
    v6 = off_110E44;
    v7 = off_110E48;
    *(uint32_t *)off_110E24 = 2;
    v8 = dword_110E4C;
    *v2 = (HIWORD(*v2) << 16) | 0x7E0;
    *v3 = *v3 & 0xFFFFF000 | 0x50;
    *v4 = *v4 & 0xFFFFFF00 | 8;
    *v4 = *v4 & 0xFFFF00FF | 0xF00;
    v9 = off_110E50;
    *v5 &= v8;
    *(int *)((char *)v2 + 0xFFFFFFF8) = 385;
    v3[136] = 385;
    v10 = off_110E54;
    *v9 &= ~0x80000000;
    *v9 &= ~0x20u;
    v11 = off_110E58;
    *v10 = *v10 & v8 | 0x4E200000;
    *v10 = *v10 & 0xFFFF8000 | 0x4E20;
    v3[3] = -1;
    *(int *)((char *)v2 + 0xFFFFFFD8) = -1;
    *v11 = 0x1FFFFFF;
    v12 = dword_110E5C;
    *v6 = 15;
    *v7 = 15;
    *(v10 - 75) = v12;
    ke_event_schedule_1(aWaitIoEnable);
    v13 = (int *)off_110E2C;
    v14 = dword_110E30;
    while ( 1 )
    {
      while ( (*v13 & 0x20000000) != 0 )
        ;
      if ( *v13 >= 0 )
      {
        *v13 = v14;
        while ( (*v13 & 0x20000000) != 0 )
          ;
        if ( (*v13 & 6) != 0 )
          break;
      }
    }
    v15 = off_110E2C;
    do
    {
      while ( (*(uint32_t *)off_110E2C & 0x20000000) != 0 )
        ;
    }
    while ( *(int *)off_110E2C < 0 );
    v16 = off_110E2C;
    *(uint32_t *)off_110E2C = dword_110E64;
    while ( (*v16 & 0x20000000) != 0 )
      ;
    result = ke_event_schedule_1(aIoEnable, v16, v15, 4 * *v16);
    *(uint32_t *)off_110E38 = *(uint32_t *)off_110E38 & 0xFFFFF000 | 0x960;
  }
  v18 = off_110E70;
  *(uint32_t *)(*((uint32_t *)off_110E6C + 2) + 324) = off_110E74;
  v18[2] = 2;
  return result;
}
