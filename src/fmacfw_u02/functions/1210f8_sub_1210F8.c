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

extern uint32_t off_121300;
extern uint32_t off_121304;
extern uint32_t off_121308;
extern uint32_t off_12130C;
extern uint32_t off_121330;
extern uint32_t off_121338;
extern uint32_t off_121310;
extern uint32_t dword_121324;
extern uint32_t off_121314;
extern uint32_t off_121318;
extern uint32_t off_121328;
extern uint32_t dword_12132C;
extern uint32_t off_12131C;
extern uint32_t off_121320;
extern uint32_t dword_121334;

// event_queue_drain @ 0x1210f8, size 520 bytes
// Doc: sub_12210F8 [util]: general utility function with register save
// sub_12210F8 [util]: general utility function with register save
int event_queue_drain()
{
  uint32_t *v0; // r6
  int v1; // r4
  int *v2; // r5
  int v3; // r0
  int v4; // r1
  int v5; // r3
  int v6; // r2
  uint32_t *v7; // r7
  uint32_t *v8; // r8
  uint32_t *v9; // r9
  int v10; // r5
  int v11; // r3
  uint32_t *v12; // r3
  uint32_t *v13; // r2
  unsigned int v14; // r10
  int v15; // r10
  int result; // r0
  uint32_t *v17; // r4
  int v18; // r2
  unsigned int v19; // r3
  int v20; // zf
  int v21; // cc
  int v22; // r3
  int v23; // r1
  int v24; // r3
  int v25; // r2
  int v26; // r3
  int v27; // r1
  int v28; // r0
  int **i; // r3
  int v30; // r2
  int v31; // r1
  int v32; // r12
  int v33; // r2

  v0 = off_121300;
  v1 = *((uint32_t *)off_121300 + 2);
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_121304 = 1;
  }
  v2 = (int *)off_121308;
  ++*(uint32_t *)off_121308;
  mmio_set_bit(4);
  v3 = phy_band_validate(4);
  if ( *v2 && (v5 = *v2 - 1, v6 = *(uint32_t *)off_121304, (*v2 = v5) == 0) && v6 )
  {
    __enable_irq();
    if ( !v1 )
      return ke_event_dispatch(v3);
  }
  else if ( !v1 )
  {
    return ke_event_dispatch(v3);
  }
  v7 = off_12130C;
  v8 = off_121330;
  v9 = off_121338;
  v10 = 0;
  do
  {
    while ( 1 )
    {
      if ( *(uint8_t *)(v1 + 106) != 2 )
        goto LABEL_7;
      v11 = (uint8_t)(*(uint8_t *)(v1 + 225) - 1);
      *(uint8_t *)(v1 + 225) = v11;
      if ( v11 )
        goto LABEL_7;
      v12 = *(uint32_t **)off_121310;
      *(uint8_t *)(v1 + 225) = *(uint8_t *)(v1 + 224);
      if ( !v12 )
        break;
      v13 = (uint32_t *)(v1 + 48);
      while ( v12 != v13 )
      {
        v12 = (uint32_t *)*v12;
        if ( !v12 )
          goto LABEL_15;
      }
      v3 = event_dispatch(dword_121324, v4, v13);
LABEL_7:
      v1 = *(uint32_t *)v1;
      if ( !v1 )
        goto LABEL_26;
    }
LABEL_15:
    configure_mmio(v1);
    v3 = llc_get_conn_idx(v1, *(uint32_t *)(v1 + 36) + 3048);
    v4 = *(uint16_t *)(v1 + 222);
    v14 = 32 * *v7;
    if ( v14 <= 0xBE7 )
      v14 += v4 << 10;
    v15 = v14 + v8[4] - 3048;
    if ( *(uint32_t *)(v1 + 72) )
      v3 = rx_dispatch_frame(v1, *(uint32_t *)(v1 + 36), v15);
    if ( *(uint8_t *)(v1 + 1224) )
    {
      v3 = unknown_worker(v1 + 24, v15);
    }
    else
    {
      if ( *((uint8_t *)off_121314 + 90) > 1u )
      {
        for ( i = *((int ***)off_121314 + 4); i; i = (int **)*i )
        {
          v4 = *((uint8_t *)i + 8);
          if ( v4 == *(uint8_t *)(v1 + 107) )
          {
            v30 = *(uint16_t *)(v1 + 222);
            v31 = *(uint32_t *)(v1 + 36);
            v3 = (int)i[1];
            v32 = v31 + (v30 << 10);
            v33 = v30 << 10;
            if ( v3 == v32 )
            {
              i[1] = (int *)v15;
              v3 = v15;
              v33 = *(uint16_t *)(v1 + 222) << 10;
            }
            v4 = v31 + 2 * v33;
            if ( v4 == v3 )
              i[1] = (int *)(v33 + v15);
          }
        }
      }
      if ( *(uint8_t *)off_121318 && (v0[4] & 0xFFFF00) == 0x10000 && (uint16_t)*v9 > 0x14u )
      {
        v18 = v8[4];
        v19 = *(uint8_t *)off_121328;
        v20 = v19 == 2;
        v21 = v19 > 2;
        v22 = (uint16_t)*v9;
        if ( v21 )
        {
          v3 = unknown_worker(dword_12132C, v18 + 500 * v22);
        }
        else
        {
          if ( v20 )
            v23 = 250;
          else
            v23 = 200;
          v3 = unknown_worker(dword_12132C, v18 + v23 * v22);
        }
      }
      *(uint32_t *)(v1 + 36) = v15;
    }
    if ( *(uint8_t *)(v1 + 412) == 1 )
      v10 = v1;
    v1 = *(uint32_t *)v1;
  }
  while ( v1 );
LABEL_26:
  result = ke_event_dispatch(v3);
  if ( *((uint8_t *)off_12131C + 413) )
  {
    if ( v10 )
    {
      v17 = off_121320;
      if ( *((uint8_t *)off_121320 + 15) )
      {
        result = rx_rate_field_parse(4);
        if ( result != 1 )
        {
          if ( !*((uint8_t *)v17 + 14)
            || (v24 = (uint8_t)(*((uint8_t *)v17 + 14) - 1), *((uint8_t *)v17 + 14) = v24, !v24) )
          {
            v25 = *(uint16_t *)(v10 + 222);
            v26 = v17[4];
            v27 = *((uint32_t *)off_121330 + 4);
            v28 = dword_121334;
            v17[7] = v10;
            *((uint8_t *)v17 + 14) = *((uint8_t *)v17 + 15);
            return unknown_worker(v28, v27 + ((unsigned int)((v25 << 10) - v26) >> 1));
          }
        }
      }
    }
  }
  return result;
}

