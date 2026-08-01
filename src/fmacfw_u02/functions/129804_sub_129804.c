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

extern uint32_t dword_129B5C;
extern uint32_t dword_129B50;
extern uint32_t off_129B54;
extern uint32_t off_129B58;
extern uint32_t off_129C50;
extern uint32_t off_129C54;
extern uint32_t off_129C58;
extern uint32_t dword_129C5C;
extern uint32_t off_129B4C;

// wlc_rx_process @ 0x129804, size 1100 bytes
// Doc: sub_1229804 [mac]: FMAC handler dispatching on field 0x10 type value
// sub_1229804 [mac]: FMAC handler dispatching on field 0x10 type value
uint8_t * wlc_rx_process(uint8_t *result)
{
  uint8_t *v1; // r4
  int v2; // r9
  int v3; // r3
  int v4; // r10
  int v5; // r8
  uint8_t *v6; // r0
  unsigned int v7; // r3
  int v8; // r1
  int v9; // r5
  int v10; // r6
  uint8_t *v11; // r0
  int v12; // r3
  int v13; // r3
  uint16_t *v14; // r0
  int v15; // r7
  int v16; // r1
  int v17; // r5
  int v18; // r6
  int v19; // r4
  uint32_t *v20; // r2
  int v21; // r11
  int v22; // r5
  int v23; // r3
  int v24; // r0
  uint32_t *v25; // r3
  int v26; // r3
  int v27; // r0
  int v28; // r2
  int v29; // r8
  int v30; // r1
  int *v31; // r5
  int v32; // r3
  int v33; // r2
  uint8_t *v34; // [sp+4h] [bp-8h]

  v1 = result;
  if ( result[16] != 2 )
  {
    if ( result[64] != 2 )
      goto LABEL_3;
    if ( !result[135] )
    {
      v7 = 255;
      goto LABEL_36;
    }
    goto LABEL_17;
  }
  if ( !result[135] )
  {
    v7 = result[20];
    if ( result[64] != 2 )
      goto LABEL_26;
    goto LABEL_36;
  }
  if ( result[33] && result[32] == 1 )
  {
    if ( result[64] != 2 )
      goto LABEL_3;
LABEL_17:
    v7 = 255;
    v8 = 0;
    goto LABEL_18;
  }
  v7 = result[20];
  if ( result[64] != 2 )
    goto LABEL_26;
  v8 = 1;
LABEL_18:
  if ( !result[81] || result[80] != 1 )
  {
LABEL_36:
    if ( v7 >= result[68] )
      v7 = result[68];
LABEL_26:
    if ( v7 != 1 )
    {
      v2 = result[134];
      if ( result[134] )
      {
        if ( result[133] == 1 )
          return result;
        v5 = result[113];
        v4 = dword_129B5C;
        v2 = 1;
        goto LABEL_42;
      }
      v9 = result[114];
      v10 = v9 == 1;
      if ( result[133] == v10 )
      {
        if ( !result[112] && v9 == 1 )
          goto LABEL_7;
        return result;
      }
      v5 = result[113];
      v4 = dword_129B5C;
      v11 = (uint8_t *)ke_msg_alloc(77, 13, result[134], 2);
      *v11 = v1[113];
      v11[1] = v9 != 1;
      ke_msg_send(v11);
      v1[133] = v10;
      result = (uint8_t *)nullsub_5(*(uint32_t *)(v4 + 1320 * v5 + 72), v9 != 1);
      if ( v9 == 1 )
      {
LABEL_43:
        if ( v1[112] )
        {
          result = (uint8_t *)unknown_func_12d104(512);
          v28 = v1[112];
        }
        else
        {
          v15 = v4 + 1320 * v5;
          v16 = *(uint8_t *)(v15 + 116);
          if ( v16 == 255 )
          {
            if ( *(uint8_t *)(v15 + 106) == 2 )
            {
              *(uint32_t *)(v15 + 4) |= 0x20u;
              if ( !v2 )
                return (uint8_t *)read_descriptor(v4 + 1320 * v1[113]);
              return result;
            }
            goto LABEL_59;
          }
          v17 = dword_129B50;
          v34 = v1;
          v18 = dword_129B50 + 696 * v16;
          v19 = v4 + 8 * (165 * v5 + 159);
          v20 = off_129B54;
          v21 = 696 * v16 + dword_129B50 + 664;
          *(uint8_t *)(v18 + 36) = 0;
          v22 = v17 + 8 * (87 * (int16_t)v16 + 78);
          do
          {
            if ( *(uint32_t *)(v18 + 584) )
            {
              if ( (__get_CPSR() & 1) == 0 )
              {
                __disable_irq();
                *(uint32_t *)off_129B58 = 1;
              }
              ++*v20;
              list_next(v22 - 40, v19 - 40);
              v23 = *(uint32_t *)(v18 + 588);
              *(uint32_t *)(v15 + 1232) = *(uint32_t *)(v18 + 584);
              *(uint32_t *)(v15 + 1236) = v23;
              zero_8_bytes(v22 - 40);
              v20 = off_129B54;
              v24 = *(uint32_t *)off_129B54 - 1;
              if ( *(uint32_t *)off_129B54 )
              {
                v25 = off_129B58;
                *(uint32_t *)off_129B54 = v24;
                if ( !v24 )
                {
                  if ( *v25 )
                    __enable_irq();
                }
              }
            }
            v26 = *(uint32_t *)(v18 + 624);
            v27 = v19;
            v18 += 8;
            v19 += 8;
            v15 += 8;
            if ( v26 )
            {
              list_next(v27, v22);
              zero_8_bytes(v22);
              v20 = off_129B54;
            }
            v22 += 8;
          }
          while ( v22 != v21 );
          v1 = v34;
          result = (uint8_t *)unknown_func_12d104(512);
          v28 = v34[112];
        }
        v29 = v4 + 1320 * v5;
        if ( *(uint8_t *)(v29 + 106) == 2 )
        {
          *(uint32_t *)(v29 + 4) |= 0x20u;
          if ( v28 )
            return result;
        }
        else if ( v28 )
        {
          return result;
        }
LABEL_59:
        if ( !v2 )
          return (uint8_t *)read_descriptor(v4 + 1320 * v1[113]);
        return result;
      }
LABEL_30:
      v12 = v4 + 1320 * v5;
      if ( *(uint8_t *)(v12 + 106) == 2 )
      {
        v30 = *((uint32_t *)off_129C50 + 1);
        *(uint32_t *)(v12 + 4) &= ~0x20u;
        if ( v30 > 0 )
        {
          if ( (__get_CPSR() & 1) == 0 )
          {
            __disable_irq();
            *(uint32_t *)off_129C54 = 1;
          }
          v31 = (int *)off_129C58;
          ++*(uint32_t *)off_129C58;
          mmio_set_bit(4);
          result = (uint8_t *)phy_band_validate(4);
          if ( *v31 )
          {
            v32 = *v31 - 1;
            v33 = *(uint32_t *)off_129C54;
            *v31 = v32;
            if ( !v32 )
            {
              if ( v33 )
                __enable_irq();
            }
          }
        }
      }
      if ( !v1[112] )
      {
        v13 = *(uint8_t *)(v4 + 1320 * v5 + 116);
        if ( v13 != 255 )
          *(uint8_t *)(dword_129B50 + 696 * v13 + 36) = 1;
      }
      return result;
    }
    goto LABEL_13;
  }
  if ( v8 )
    goto LABEL_26;
LABEL_3:
  v2 = result[115];
  if ( !result[115] )
  {
    if ( result[133] == 1 )
    {
LABEL_5:
      v3 = result[112];
      goto LABEL_6;
    }
    goto LABEL_41;
  }
  if ( result[114] == 1 )
  {
    if ( result[133] == 1 )
      goto LABEL_5;
    goto LABEL_62;
  }
  v3 = result[112];
  if ( v3 == 1 )
  {
    v5 = result[113];
    v4 = dword_129C5C;
    if ( *(uint8_t *)(dword_129C5C + 1320 * v5 + 234) != *(uint8_t *)(dword_129C5C + 1320 * v5 + 1226) )
    {
      if ( result[133] == 1 )
        return result;
      v2 = 0;
      goto LABEL_42;
    }
    if ( !result[133] )
      return result;
    goto LABEL_15;
  }
  v2 = *(uint8_t *)off_129B4C;
  if ( *(uint8_t *)off_129B4C )
  {
    if ( (*((uint32_t *)off_129B4C + 1) & 8) == 0 )
    {
LABEL_13:
      if ( !result[133] )
        return result;
      v5 = result[113];
      v4 = dword_129B5C;
LABEL_15:
      v6 = (uint8_t *)ke_msg_alloc(77, 13, 0, 2);
      *v6 = v1[113];
      v6[1] = 1;
      ke_msg_send(v6);
      v1[133] = 0;
      result = (uint8_t *)nullsub_5(*(uint32_t *)(v4 + 1320 * v5 + 72), 1);
      goto LABEL_30;
    }
    if ( result[133] == 1 )
    {
      if ( !result[112] )
        goto LABEL_7;
      return result;
    }
LABEL_62:
    v5 = result[113];
    v4 = dword_129B5C;
    v2 = 0;
    goto LABEL_42;
  }
  if ( result[133] != 1 )
  {
LABEL_41:
    v5 = result[113];
    v4 = dword_129B5C;
LABEL_42:
    v14 = (uint16_t *)ke_msg_alloc(77, 13, 0, 2);
    *v14 = v1[113];
    ke_msg_send(v14);
    v1[133] = 1;
    result = (uint8_t *)nullsub_5(*(uint32_t *)(v4 + 1320 * v5 + 72), 0);
    goto LABEL_43;
  }
LABEL_6:
  if ( !v3 )
  {
LABEL_7:
    v4 = dword_129B5C;
    return (uint8_t *)read_descriptor(v4 + 1320 * v1[113]);
  }
  return result;
}

