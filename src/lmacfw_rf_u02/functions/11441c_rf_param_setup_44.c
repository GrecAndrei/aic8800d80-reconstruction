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

extern uint32_t off_114548;
extern uint32_t off_11454C;
extern uint32_t dword_114550;
extern uint32_t dword_114554;

// ke_task_process @ 0x11441c, size 300 bytes
// Doc: ke_task_process [rf]: RF parameter setup routine using global state table at 0x180558
// ke_task_process [rf]: RF parameter setup routine using global state table at 0x180558
int  ke_task_process(int a1, int a2, unsigned int a3)
{
  uint32_t *v6; // r7
  int v7; // r5
  unsigned int v8; // r5
  int v9; // r1
  int v11; // [sp+0h] [bp-48h] BYREF
  int v12; // [sp+4h] [bp-44h]
  uint8_t v13[4]; // [sp+10h] [bp-38h] BYREF
  uint8_t v14[12]; // [sp+14h] [bp-34h] BYREF
  uint8_t v15[20]; // [sp+20h] [bp-28h] BYREF
  uint8_t v16[8]; // [sp+34h] [bp-14h] BYREF
  uint8_t v17[4]; // [sp+3Ch] [bp-Ch] BYREF
  uint8_t v18[4]; // [sp+40h] [bp-8h] BYREF
  uint8_t v19[4]; // [sp+44h] [bp-4h] BYREF

  if ( !*(uint32_t *)off_114548 )
    ke_event_busy_check();
  v6 = off_11454C;
  v7 = dword_114550;
  MEMORY[0x1D8](*(uint32_t *)off_11454C + 0x2000, 72, &v11);
  if ( v11 == v7 )
  {
    v8 = a1 & 1;
    v12 |= a1;
    if ( (a1 & 1) == 0 )
      goto LABEL_5;
  }
  else
  {
    sub_100200(&v11, 0xFFu, 0x48u);
    v11 = v7;
    v8 = a1 & 1;
    v12 = a1;
    if ( (a1 & 1) == 0 )
    {
LABEL_5:
      if ( (a1 & 2) == 0 )
        goto LABEL_6;
      goto LABEL_15;
    }
  }
  memcpy_large(v13, a2, 4);
  v8 = 4;
  if ( (a1 & 2) == 0 )
  {
LABEL_6:
    if ( (a1 & 4) == 0 )
      goto LABEL_7;
    goto LABEL_16;
  }
LABEL_15:
  memcpy_large(v14, a2 + v8, 12);
  v8 += 12;
  if ( (a1 & 4) == 0 )
  {
LABEL_7:
    if ( (a1 & 8) == 0 )
      goto LABEL_8;
    goto LABEL_17;
  }
LABEL_16:
  memcpy_large(v15, a2 + v8, 20);
  v8 += 20;
  if ( (a1 & 8) == 0 )
  {
LABEL_8:
    v9 = a1 << 26;
    if ( (a1 & 0x20) == 0 )
      goto LABEL_9;
    goto LABEL_18;
  }
LABEL_17:
  memcpy_large(v16, a2 + v8, 4);
  v9 = a1 << 26;
  v8 += 4;
  if ( (a1 & 0x20) == 0 )
  {
LABEL_9:
    if ( (a1 & 0x40) == 0 )
      goto LABEL_10;
    goto LABEL_19;
  }
LABEL_18:
  memcpy_large(v17, a2 + v8, 4);
  v8 += 4;
  if ( (a1 & 0x40) == 0 )
  {
LABEL_10:
    if ( (a1 & 0x80) == 0 )
      goto LABEL_11;
LABEL_20:
    memcpy_large(v19, a2 + v8, 4);
    if ( a3 >= v8 + 4 )
      goto LABEL_12;
LABEL_21:
    dispatch_event_handler(dword_114554, v9);
    goto LABEL_12;
  }
LABEL_19:
  memcpy_large(v18, a2 + v8, 4);
  v8 += 4;
  if ( (a1 & 0x80) != 0 )
    goto LABEL_20;
LABEL_11:
  if ( a3 < v8 )
    goto LABEL_21;
LABEL_12:
  ke_event_schedule_alt();
  ke_event_schedule_prio();
  return MEMORY[0x1E0](*v6 + 0x2000, 72);
}

