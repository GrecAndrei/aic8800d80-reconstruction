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

extern uint32_t off_101C7C;
extern uint32_t off_101C80;
extern uint32_t off_101C88;
extern uint32_t off_101C8C;
extern uint32_t off_101C84;
extern uint32_t off_101C90;
extern uint32_t off_101C9C;
extern uint32_t dword_101CA4;
extern uint32_t dword_101CA0;
extern uint32_t dword_101CA8;
extern uint32_t off_101C94;
extern uint32_t off_101C98;

// bt_event_handler @ 0x101a54, size 550 bytes
int  bt_event_handler(int a1, uint8_t *a2, uint8_t *a3)
{
  int result; // r0
  unsigned int v5; // r10
  int v7; // r9
  int v8; // r6
  char v9; // r8
  char v10; // r11
  unsigned int v11; // r3
  unsigned int v12; // r2
  unsigned int v13; // r3
  int v14; // r2
  int v15; // r6
  char v16; // r8
  unsigned int v17; // r3
  char v18; // r3
  int v19; // r2
  int v20; // r2
  int v21; // r3
  unsigned int v22; // [sp+4h] [bp-8h]

  result = *((uint8_t *)off_101C7C + 36);
  v5 = *((uint16_t *)off_101C7C + 20);
  if ( !*((uint8_t *)off_101C7C + 36) )
  {
    if ( *((uint8_t *)off_101C80 + 197) )
    {
      if ( v5 > 0x97B )
      {
        if ( v5 > 0x994 )
          result = 2;
        else
          result = 1;
      }
      v7 = *((char *)off_101C80 + 198);
      v8 = *((char *)off_101C80 + 210);
      v9 = *((uint8_t *)off_101C88 + 10) + *(uint8_t *)off_101C8C + *(uint8_t *)(*(uint32_t *)off_101C84 + result + 6);
      v10 = *(uint8_t *)off_101C8C + *((uint8_t *)off_101C88 + 8) + *(uint8_t *)(*(uint32_t *)off_101C84 + result);
      v11 = v10;
      if ( *((uint8_t *)off_101C80 + 396) )
      {
        result = *(uint8_t *)(*(uint32_t *)off_101C90 + result);
        v7 = (char)(result + v7);
        v8 = (char)(v8 + result);
      }
      if ( (*((uint32_t *)off_101C80 + 98) & 2) != 0 )
      {
        result = is_adv_enabled(0, *((uint16_t *)off_101C7C + 20));
        v11 = v10;
        if ( result )
        {
          v20 = *(char *)(result + 4);
        }
        else
        {
          if ( **(int16_t **)off_101C9C < 0 )
          {
            mmio_write_field(dword_101CA4, dword_101CA0, 6857);
            v11 = v10;
          }
          v22 = v11;
          result = alloc_tx_event(dword_101CA8, 0, v5);
          v11 = v22;
          v20 = 15;
        }
        if ( v7 >= v20 )
          LOBYTE(v7) = v20;
        if ( v8 >= v20 )
          LOBYTE(v8) = v20;
      }
      if ( (v10 & 1) != 0 )
        v12 = v11 - 1;
      else
        v12 = v11 + (v11 >> 31);
      if ( (v10 & 1) != 0 )
        v12 += v12 >> 31;
      if ( (v9 & 1) != 0 )
        v13 = v9 - 1 + ((unsigned int)(v9 - 1) >> 31);
      else
        v13 = v9 + ((unsigned int)v9 >> 31);
      *a2 = (v12 >> 1) + v7;
      *a3 = (v13 >> 1) + v8;
      return result;
    }
    if ( **(int16_t **)off_101C9C >= 0 )
      return result;
    v19 = 6875;
    return irq_disable_mmio_write(dword_101CA4, dword_101CA0, v19);
  }
  if ( !*((uint8_t *)off_101C80 + 197) )
  {
    if ( **(int16_t **)off_101C9C >= 0 )
      return result;
    v19 = 6921;
    return irq_disable_mmio_write(dword_101CA4, dword_101CA0, v19);
  }
  if ( v5 <= 0x1666 )
  {
    if ( v5 > 0x1616 )
    {
      v14 = 4;
    }
    else if ( v5 > 0x15C6 )
    {
      v14 = 3;
    }
    else if ( v5 > 0x1571 )
    {
      v14 = 2;
    }
    else
    {
      v14 = v5 > 0x1486;
    }
  }
  else
  {
    v14 = 5;
  }
  result = *((uint8_t *)off_101C80 + 396);
  v15 = *((char *)off_101C80 + 236);
  v16 = *((uint8_t *)off_101C8C + 1) + *((uint8_t *)off_101C88 + 11) + *(uint8_t *)(*(uint32_t *)off_101C94 + v14);
  if ( *((uint8_t *)off_101C80 + 396) )
    v15 = (char)(*(uint8_t *)(*(uint32_t *)off_101C98 + v14) + v15);
  if ( (*((uint32_t *)off_101C80 + 98) & 2) != 0 )
  {
    result = is_adv_enabled(1, *((uint16_t *)off_101C7C + 20));
    if ( result )
    {
      v21 = *(char *)(result + 4);
    }
    else
    {
      if ( **(int16_t **)off_101C9C < 0 )
        mmio_write_field(dword_101CA4, dword_101CA0, 6907);
      result = alloc_tx_event(dword_101CA8, 1, v5);
      v21 = 15;
    }
    if ( v15 >= v21 )
      LOBYTE(v15) = v21;
  }
  if ( (v16 & 1) != 0 )
    v17 = v16 - 1 + ((unsigned int)(v16 - 1) >> 31);
  else
    v17 = v16 + ((unsigned int)v16 >> 31);
  v18 = (v17 >> 1) + v15;
  *a3 = v18;
  *a2 = v18;
  return result;
}

