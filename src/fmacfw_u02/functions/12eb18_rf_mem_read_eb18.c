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

extern uint32_t dword_12ECC0;
extern uint32_t dword_12ECAC;
extern uint32_t dword_12ECB8;
extern uint32_t dword_12ECB0;
extern uint32_t dword_12ECBC;
extern uint32_t dword_12ECC4;
extern uint32_t dword_12ECC8;
extern uint32_t dword_12ECB4;
extern uint32_t dword_12ECCC;

// send_msg @ 0x12eb18, size 404 bytes
// Doc: send_msg [rf]: Read RF memory block; copies N words with offset/length params
// send_msg [rf]: Read RF memory block; copies N words with offset/length params
unsigned int  send_msg(unsigned int result, int a2, int a3, int a4)
{
  int v4; // r4
  int v5; // r9
  unsigned int v6; // r5
  unsigned int v7; // r7
  int v8; // r8
  int v9; // r10
  uint16_t *v10; // r6
  unsigned int v11; // r11
  int v12; // r1
  int v13; // r0
  int v14; // r10
  uint8_t *v15; // r11
  int v16; // r4
  unsigned int v17; // r8
  unsigned int v19; // r8
  int v20; // r0
  int v21; // r10
  unsigned int v22; // r8
  unsigned int cb; // r6
  unsigned int v24; // [sp+Ch] [bp-10h]
  int v26; // [sp+14h] [bp-8h]

  if ( !a2 )
    return result;
  v4 = a3;
  if ( a3 != 4 && (unsigned int)(a3 - 1) > 1 )
    return result;
  v5 = dword_12ECC0;
  v24 = a2 * a3;
  v6 = -a3 & result;
  while ( 1 )
  {
    event_dispatch(dword_12ECAC, v6);
    v7 = v24;
    if ( v24 >= 0x10 )
      v7 = 16;
    if ( ((v6 >> 20) & 0xFFFFFDFF) == 0x500 )
    {
      if ( !v24 )
        return (unsigned int)read_memory_byte((uint8_t *)dword_12ECB8);
      v21 = dword_12ECB0;
      v22 = 0;
      while ( 1 )
      {
        cb = call_ptr_1b0();
        if ( v4 == 4 )
          break;
        if ( v4 == 2 )
        {
          v22 += 4;
          event_dispatch(dword_12ECBC, (uint16_t)cb, HIWORD(cb), BYTE2(cb));
          v6 += 4;
          if ( v7 <= v22 )
          {
LABEL_40:
            a4 = 0;
            goto LABEL_31;
          }
        }
        else
        {
          event_dispatch(v5);
LABEL_36:
          v22 += 4;
          v6 += 4;
          if ( v7 <= v22 )
            goto LABEL_40;
        }
      }
      event_dispatch(v21, cb, BYTE1(cb), BYTE2(cb));
      goto LABEL_36;
    }
    if ( v24 )
      break;
    if ( a4 )
    {
      v10 = (uint16_t *)v6;
      goto LABEL_20;
    }
LABEL_31:
    result = (unsigned int)read_memory_byte((uint8_t *)dword_12ECB8);
    v24 -= v7;
    if ( !v24 )
      return result;
  }
  v8 = dword_12ECC4;
  v9 = dword_12ECC8;
  v10 = (uint16_t *)v6;
  v11 = 0;
  do
  {
    while ( 1 )
    {
      v13 = v8;
      if ( v4 != 4 )
        break;
      v11 += 4;
      event_dispatch(dword_12ECB0, *(uint32_t *)v10);
      v10 += 2;
      if ( v7 <= v11 )
        goto LABEL_18;
    }
    if ( v4 == 2 )
      v12 = *v10;
    else
      v12 = *(uint8_t *)v10;
    if ( v4 == 2 )
      v13 = v9;
    v11 += v4;
    event_dispatch(v13, v12);
    v10 = (uint16_t *)((char *)v10 + v4);
  }
  while ( v7 > v11 );
LABEL_18:
  if ( !a4 )
    goto LABEL_30;
  if ( v24 > 0xF )
  {
    read_memory_byte((uint8_t *)dword_12ECB4);
    goto LABEL_26;
  }
LABEL_20:
  v14 = v4 - 1;
  v26 = v4;
  v15 = (uint8_t *)dword_12ECCC;
  v16 = 0;
  v17 = 16 - v7;
  do
  {
    while ( (v14 & v16++) != 0 )
    {
      read_memory_byte(v15);
      if ( v17 == v16 )
        goto LABEL_25;
    }
    gpio_write(32);
    read_memory_byte(v15);
  }
  while ( v17 != v16 );
LABEL_25:
  v4 = v26;
  read_memory_byte((uint8_t *)dword_12ECB4);
  if ( v24 )
  {
LABEL_26:
    v19 = 0;
    do
    {
      v20 = *(uint8_t *)(v6 + v19);
      if ( (unsigned int)(v20 - 31) > 0x5F )
        v20 = 46;
      ++v19;
      gpio_write(v20);
    }
    while ( v7 > v19 );
LABEL_30:
    v6 = (unsigned int)v10;
    goto LABEL_31;
  }
  return (unsigned int)read_memory_byte((uint8_t *)dword_12ECB8);
}

