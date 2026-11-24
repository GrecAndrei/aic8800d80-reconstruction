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


extern uint32_t off_12EEE0;
extern uint32_t off_12EEF4;

// rx_packet_handler_2 @ 0x12ed40, size 404 bytes
int  rx_packet_handler_2(int result, int a2, int a3, int a4)
{
  int v4; // r4
  unsigned int v5; // r5
  unsigned int v6; // r7
  uint16_t *v7; // r6
  unsigned int v8; // r11
  int v9; // r1
  const char *v10; // r0
  int v11; // r10
  uint8_t *v12; // r11
  int v13; // r4
  unsigned int v14; // r8
  unsigned int v16; // r8
  int v17; // r0
  unsigned int v18; // r8
  unsigned int v19; // r6
  unsigned int v20; // [sp+Ch] [bp-10h]
  int v22; // [sp+14h] [bp-8h]

  if ( !a2 )
    return result;
  v4 = a3;
  if ( a3 != 4 && (unsigned int)(a3 - 1) > 1 )
    return result;
  v20 = a2 * a3;
  v5 = -a3 & result;
  while ( 1 )
  {
    ke_event_schedule_1("%08x:", v5);
    v6 = v20;
    if ( v20 >= 0x10 )
      v6 = 16;
    if ( ((v5 >> 20) & 0xFFFFFDFF) == 0x500 )
    {
      if ( !v20 )
        return (int)uart_puts(off_12EEE0);
      v18 = 0;
      while ( 1 )
      {
        v19 = jump_table_1b0();
        if ( v4 == 4 )
          break;
        if ( v4 == 2 )
        {
          v18 += 4;
          ke_event_schedule_1(" %04X %04X", (uint16_t)v19, HIWORD(v19));
          v5 += 4;
          if ( v6 <= v18 )
          {
LABEL_40:
            a4 = 0;
            goto LABEL_31;
          }
        }
        else
        {
          ke_event_schedule_1(" %02X %02X %02X %02X", (uint8_t)v19, BYTE1(v19), BYTE2(v19), HIBYTE(v19));
LABEL_36:
          v18 += 4;
          v5 += 4;
          if ( v6 <= v18 )
            goto LABEL_40;
        }
      }
      ke_event_schedule_1(" %08X", v19);
      goto LABEL_36;
    }
    if ( v20 )
      break;
    if ( a4 )
    {
      v7 = (uint16_t *)v5;
      goto LABEL_20;
    }
LABEL_31:
    result = (int)uart_puts(off_12EEE0);
    v20 -= v6;
    if ( !v20 )
      return result;
  }
  v7 = (uint16_t *)v5;
  v8 = 0;
  do
  {
    while ( 1 )
    {
      v10 = a02x;
      if ( v4 != 4 )
        break;
      v8 += 4;
      ke_event_schedule_1(" %08X", *(uint32_t *)v7);
      v7 += 2;
      if ( v6 <= v8 )
        goto LABEL_18;
    }
    if ( v4 == 2 )
      v9 = *v7;
    else
      v9 = *(uint8_t *)v7;
    if ( v4 == 2 )
      v10 = a04x;
    v8 += v4;
    ke_event_schedule_1(v10, v9);
    v7 = (uint16_t *)((char *)v7 + v4);
  }
  while ( v6 > v8 );
LABEL_18:
  if ( !a4 )
    goto LABEL_30;
  if ( v20 > 0xF )
  {
    uart_puts(asc_14ADA8);
    goto LABEL_26;
  }
LABEL_20:
  v11 = v4 - 1;
  v22 = v4;
  v12 = off_12EEF4;
  v13 = 0;
  v14 = 16 - v6;
  do
  {
    while ( (v11 & v13++) != 0 )
    {
      uart_puts(v12);
      if ( v14 == v13 )
        goto LABEL_25;
    }
    uart_putc(32);
    uart_puts(v12);
  }
  while ( v14 != v13 );
LABEL_25:
  v4 = v22;
  uart_puts(asc_14ADA8);
  if ( v20 )
  {
LABEL_26:
    v16 = 0;
    do
    {
      v17 = *(uint8_t *)(v5 + v16);
      if ( (unsigned int)(v17 - 31) > 0x5F )
        v17 = 46;
      ++v16;
      uart_putc(v17);
    }
    while ( v6 > v16 );
LABEL_30:
    v5 = (unsigned int)v7;
    goto LABEL_31;
  }
  return (int)uart_puts(off_12EEE0);
}
