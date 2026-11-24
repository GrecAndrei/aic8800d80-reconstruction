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

// process_packet_params @ 0x12e9d8, size 404 bytes
int  process_packet_params(int result, int a2, int a3, int a4)
{
  int v4; // r4
  unsigned int v5; // r5
  unsigned int v6; // r7
  uint16_t *v7; // r6
  unsigned int v8; // r11
  int v9; // r1
  const char *v10; // r0
  int v11; // r10
  int v12; // r4
  unsigned int v13; // r8
  unsigned int v15; // r8
  int v16; // r0
  unsigned int v17; // r8
  unsigned int v18; // r6
  unsigned int v19; // [sp+Ch] [bp-10h]
  int v21; // [sp+14h] [bp-8h]

  if ( !a2 )
    return result;
  v4 = a3;
  if ( a3 != 4 && (unsigned int)(a3 - 1) > 1 )
    return result;
  v19 = a2 * a3;
  v5 = -a3 & result;
  while ( 1 )
  {
    alloc_tx_event("%08x:", v5);
    v6 = v19;
    if ( v19 >= 0x10 )
      v6 = 16;
    if ( ((v5 >> 20) & 0xFFFFFDFF) == 0x500 )
    {
      if ( !v19 )
        return (int)radio_tx_write_string(&aNoTxDscrHdr[16]);
      v17 = 0;
      while ( 1 )
      {
        v18 = call_patch_hook_0();
        if ( v4 == 4 )
          break;
        if ( v4 == 2 )
        {
          v17 += 4;
          alloc_tx_event(" %04X %04X", (uint16_t)v18, HIWORD(v18));
          v5 += 4;
          if ( v6 <= v17 )
          {
LABEL_40:
            a4 = 0;
            goto LABEL_31;
          }
        }
        else
        {
          alloc_tx_event(" %02X %02X %02X %02X", (uint8_t)v18, BYTE1(v18), BYTE2(v18), HIBYTE(v18));
LABEL_36:
          v17 += 4;
          v5 += 4;
          if ( v6 <= v17 )
            goto LABEL_40;
        }
      }
      alloc_tx_event(" %08X", v18);
      goto LABEL_36;
    }
    if ( v19 )
      break;
    if ( a4 )
    {
      v7 = (uint16_t *)v5;
      goto LABEL_20;
    }
LABEL_31:
    result = (int)radio_tx_write_string(&aNoTxDscrHdr[16]);
    v19 -= v6;
    if ( !v19 )
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
      alloc_tx_event(" %08X", *(uint32_t *)v7);
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
    alloc_tx_event(v10, v9);
    v7 = (uint16_t *)((char *)v7 + v4);
  }
  while ( v6 > v8 );
LABEL_18:
  if ( !a4 )
    goto LABEL_30;
  if ( v19 > 0xF )
  {
    radio_tx_write_string(asc_14AAE0);
    goto LABEL_26;
  }
LABEL_20:
  v11 = v4 - 1;
  v21 = v4;
  v12 = 0;
  v13 = 16 - v6;
  do
  {
    while ( (v11 & v12++) != 0 )
    {
      radio_tx_write_string(&aUseWfPa5gInput[28]);
      if ( v13 == v12 )
        goto LABEL_25;
    }
    radio_tx_write_byte(32);
    radio_tx_write_string(&aUseWfPa5gInput[28]);
  }
  while ( v13 != v12 );
LABEL_25:
  v4 = v21;
  radio_tx_write_string(asc_14AAE0);
  if ( v19 )
  {
LABEL_26:
    v15 = 0;
    do
    {
      v16 = *(uint8_t *)(v5 + v15);
      if ( (unsigned int)(v16 - 31) > 0x5F )
        v16 = 46;
      ++v15;
      radio_tx_write_byte(v16);
    }
    while ( v6 > v15 );
LABEL_30:
    v5 = (unsigned int)v7;
    goto LABEL_31;
  }
  return (int)radio_tx_write_string(&aNoTxDscrHdr[16]);
}
