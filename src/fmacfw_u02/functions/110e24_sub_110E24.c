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


extern uint32_t dword_110FD4;
extern uint32_t dword_110FF0;
extern uint32_t dword_111000;
extern uint32_t dword_111008;
extern uint32_t off_110FC4;
extern uint32_t off_110FC8;
extern uint32_t off_110FD0;
extern uint32_t off_110FD8;
extern uint32_t off_110FDC;
extern uint32_t off_110FE0;
extern uint32_t off_110FE4;
extern uint32_t off_110FE8;
extern uint32_t off_110FEC;
extern uint32_t off_110FF4;
extern uint32_t off_110FF8;
extern uint32_t off_110FFC;
extern uint32_t off_111010;
extern uint32_t off_111014;
extern uint32_t off_111018;

// mmio_write_config @ 0x110e24, size 414 bytes
int mmio_write_config()
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

  v0 = off_110FC8;
  *(uint32_t *)off_110FC4 = 16;
  if ( (*v0 & 4) != 0 )
  {
    v19 = (unsigned int *)off_110FF8;
    v20 = (unsigned int *)off_110FDC;
    *(uint32_t *)off_110FF8 = *(uint32_t *)off_110FF8 & 0x8000FFFF | 0x4E200000;
    *v19 = *v19 & 0xFFFF8000 | 0x4E20;
    *v20 = *v20 & 0xFFFFF000 | 0x960;
    result = (int)sys_command_40d();
  }
  else
  {
    event_dispatch(aWaitCmd5);
    do
    {
      while ( (*(uint32_t *)off_110FD0 & 0x20000000) != 0 )
        ;
    }
    while ( *(int *)off_110FD0 < 0 );
    v1 = off_110FD0;
    *(uint32_t *)off_110FD0 = dword_110FD4;
    while ( (*v1 & 0x20000000) != 0 )
      ;
    if ( (*v1 & 2) == 0 )
    {
      while ( (*(uint32_t *)off_110FC8 & 1) == 0 )
        ;
    }
    v2 = (int *)off_110FD8;
    v3 = (unsigned int *)off_110FDC;
    v4 = (unsigned int *)off_110FE0;
    v5 = off_110FE4;
    v6 = off_110FE8;
    v7 = off_110FEC;
    *(uint32_t *)off_110FC8 = 2;
    v8 = dword_110FF0;
    *v2 = (HIWORD(*v2) << 16) | 0x7E0;
    *v3 = *v3 & 0xFFFFF000 | 0x50;
    *v4 = *v4 & 0xFFFFFF00 | 8;
    *v4 = *v4 & 0xFFFF00FF | 0xF00;
    v9 = off_110FF4;
    *v5 &= v8;
    *(int *)((char *)v2 + 0xFFFFFFF8) = 385;
    v3[136] = 385;
    v10 = off_110FF8;
    *v9 &= ~0x80000000;
    *v9 &= ~0x20u;
    v11 = off_110FFC;
    *v10 = *v10 & v8 | 0x4E200000;
    *v10 = *v10 & 0xFFFF8000 | 0x4E20;
    v3[3] = -1;
    *(int *)((char *)v2 + 0xFFFFFFD8) = -1;
    *v11 = 0x1FFFFFF;
    v12 = dword_111000;
    *v6 = 15;
    *v7 = 15;
    *(v10 - 75) = v12;
    event_dispatch(aWaitIoEnable);
    v13 = (int *)off_110FD0;
    v14 = dword_110FD4;
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
    v15 = off_110FD0;
    do
    {
      while ( (*(uint32_t *)off_110FD0 & 0x20000000) != 0 )
        ;
    }
    while ( *(int *)off_110FD0 < 0 );
    v16 = off_110FD0;
    *(uint32_t *)off_110FD0 = dword_111008;
    while ( (*v16 & 0x20000000) != 0 )
      ;
    result = event_dispatch(aIoEnable, v16, v15, 4 * *v16);
    *(uint32_t *)off_110FDC = *(uint32_t *)off_110FDC & 0xFFFFF000 | 0x960;
  }
  v18 = off_111014;
  *(uint32_t *)(*((uint32_t *)off_111010 + 2) + 324) = off_111018;
  v18[2] = 2;
  return result;
}
