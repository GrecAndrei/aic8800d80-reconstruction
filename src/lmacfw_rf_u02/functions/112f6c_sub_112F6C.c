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

extern uint32_t off_113098;
extern uint32_t off_1130A4;
extern uint32_t dword_1130C0;
extern uint32_t off_1130A0;
extern uint32_t off_1130A8;
extern uint32_t dword_1130AC;
extern uint32_t off_11309C;
extern uint32_t off_1130B0;
extern uint32_t off_1130C8;
extern uint32_t off_1130B4;
extern uint32_t dword_1130B8;
extern uint32_t dword_1130BC;
extern uint32_t dword_1130C4;

// sub_112F6C @ 0x112f6c, size 298 bytes
// Doc: sub_1212F6C [unknown]: Unknown behavioral stub
// sub_1212F6C [unknown]: Unknown behavioral stub
void  sub_112F6C(int a1, int a2, int a3, int a4)
{
  uint8_t *v4; // r5
  uint16_t *v5; // r2
  int v6; // r1
  int v7; // r0
  uint32_t *v8; // r4
  uint32_t *v9; // r8
  unsigned int *v10; // r6
  unsigned int v11; // r1
  int v12; // r0
  int started; // r0
  uint8_t *v14; // r7
  int v15; // r9
  unsigned int v16; // r1
  int v17; // r0
  int v18; // r0
  uint16_t *v19; // r3
  int v20; // r1

  v4 = off_113098;
  if ( *(uint8_t *)off_113098 )
  {
    if ( !*(uint16_t *)off_1130A4 )
    {
      v6 = dword_1130C0;
      goto LABEL_6;
    }
    if ( *(uint8_t *)off_1130A0 >= (unsigned int)*(uint16_t *)off_1130A4 )
    {
      v19 = (uint16_t *)off_1130A8;
      v20 = dword_1130AC;
      *(uint8_t *)off_11309C = 1;
      sub_11F74C(512, v20, *v19, v19);
    }
  }
  else
  {
    if ( *(uint8_t *)off_11309C )
      return;
    if ( *(uint8_t *)off_1130A0 >= (unsigned int)*(uint16_t *)off_1130A4 && !*(uint8_t *)off_11309C )
    {
      v5 = (uint16_t *)off_1130A8;
      *(uint8_t *)off_11309C = 1;
      v6 = dword_1130AC;
      a3 = *v5;
LABEL_6:
      sub_11F74C(512, v6, a3, a4);
      return;
    }
  }
  v7 = (*(int ( **)(uint32_t))(*((uint32_t *)off_1130B0 + 2) + 16))(*((uint32_t *)off_1130B0 + 1));
  v8 = (uint32_t *)v7;
  if ( v7 )
  {
    if ( *v4 )
    {
      v9 = off_1130C8;
      v10 = (unsigned int *)off_1130B4;
      v11 = *(uint32_t *)off_1130B4;
      v12 = *(uint32_t *)off_1130C8 + v7;
      if ( *(uint8_t *)off_11309C )
        started = rf_stream_start2_cc0(v12, v11);
      else
        started = rf_stream_start_2c20(v12, v11);
    }
    else
    {
      v9 = off_1130C8;
      v10 = (unsigned int *)off_1130B4;
      started = rf_stream_start_2c20(*(uint32_t *)off_1130C8 + v7, *(uint32_t *)off_1130B4);
    }
    if ( started )
    {
      v14 = off_11309C;
      sub_10DA6C(dword_1130B8, started);
      v15 = 5;
      while ( 1 )
      {
        if ( *v4 )
        {
          v16 = *v10;
          v17 = (int)v8 + *v9;
          v18 = *v14 ? rf_stream_start2_cc0(v17, v16) : rf_stream_start_2c20(v17, v16);
        }
        else
        {
          v18 = rf_stream_start_2c20((int)v8 + *v9, *v10);
        }
        if ( !v18 )
          break;
        if ( !--v15 )
        {
          sub_10DA6C(dword_1130BC, 5);
          sub_10FEF8(v8);
          irq_nesting_or(256);
          return;
        }
      }
    }
  }
  else
  {
    irq_nesting_or(256);
    sub_10DA6C(dword_1130C4);
  }
}

