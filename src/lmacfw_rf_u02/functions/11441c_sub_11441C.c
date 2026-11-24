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


extern uint32_t dword_114550;
extern uint32_t off_114548;
extern uint32_t off_11454C;

// ke_task_process @ 0x11441c, size 300 bytes
int  ke_task_process(int a1, char *a2, unsigned int a3)
{
  uint32_t *v6; // r7
  int v7; // r5
  unsigned int v8; // r5
  int v9; // r1
  int v10; // r2
  int v11; // r3
  int v13; // [sp+0h] [bp-48h] BYREF
  int v14; // [sp+4h] [bp-44h]
  char a1a[4]; // [sp+10h] [bp-38h] BYREF
  char v16[12]; // [sp+14h] [bp-34h] BYREF
  char v17[20]; // [sp+20h] [bp-28h] BYREF
  char v18[8]; // [sp+34h] [bp-14h] BYREF
  char v19[4]; // [sp+3Ch] [bp-Ch] BYREF
  char v20[4]; // [sp+40h] [bp-8h] BYREF
  char v21[4]; // [sp+44h] [bp-4h] BYREF

  if ( !*(uint32_t *)off_114548 )
    ke_event_busy_check(a1);
  v6 = off_11454C;
  v7 = dword_114550;
  MEMORY[0x1D8](*(uint32_t *)off_11454C + 0x2000, 72, &v13);
  if ( v13 == v7 )
  {
    v8 = a1 & 1;
    v14 |= a1;
    if ( (a1 & 1) == 0 )
      goto LABEL_5;
  }
  else
  {
    memset_thunk(&v13, 0xFFu, 0x48u);
    v13 = v7;
    v8 = a1 & 1;
    v14 = a1;
    if ( (a1 & 1) == 0 )
    {
LABEL_5:
      if ( (a1 & 2) == 0 )
        goto LABEL_6;
      goto LABEL_15;
    }
  }
  memcpy_large(a1a, a2, 4u);
  v8 = 4;
  if ( (a1 & 2) == 0 )
  {
LABEL_6:
    if ( (a1 & 4) == 0 )
      goto LABEL_7;
    goto LABEL_16;
  }
LABEL_15:
  memcpy_large(v16, &a2[v8], 0xCu);
  v8 += 12;
  if ( (a1 & 4) == 0 )
  {
LABEL_7:
    if ( (a1 & 8) == 0 )
      goto LABEL_8;
    goto LABEL_17;
  }
LABEL_16:
  memcpy_large(v17, &a2[v8], 0x14u);
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
  memcpy_large(v18, &a2[v8], 4u);
  v9 = a1 << 26;
  v8 += 4;
  if ( (a1 & 0x20) == 0 )
  {
LABEL_9:
    v10 = a1 << 25;
    if ( (a1 & 0x40) == 0 )
      goto LABEL_10;
    goto LABEL_19;
  }
LABEL_18:
  memcpy_large(v19, &a2[v8], 4u);
  v10 = a1 << 25;
  v8 += 4;
  if ( (a1 & 0x40) == 0 )
  {
LABEL_10:
    v11 = a1 << 24;
    if ( (a1 & 0x80) == 0 )
      goto LABEL_11;
LABEL_20:
    memcpy_large(v21, &a2[v8], 4u);
    if ( a3 >= v8 + 4 )
      goto LABEL_12;
LABEL_21:
    dispatch_event_handler_1(aFlashCalibInfo, v9, v10, v11, v13, v14);
    goto LABEL_12;
  }
LABEL_19:
  memcpy_large(v20, &a2[v8], 4u);
  v11 = a1 << 24;
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
