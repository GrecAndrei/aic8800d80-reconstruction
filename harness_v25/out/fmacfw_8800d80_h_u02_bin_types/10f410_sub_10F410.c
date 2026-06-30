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

extern uint32_t off_10F6F4;
extern uint32_t off_10F720;
extern uint32_t off_10F6F8;
extern uint32_t off_10F6FC;
extern uint32_t off_10F700;
extern uint32_t dword_10F704;
extern uint32_t dword_10F714;
extern uint32_t dword_10F710;
extern uint32_t dword_10F71C;
extern uint32_t dword_10F708;
extern uint32_t dword_10F718;
extern uint32_t dword_10F70C;

// sub_10F410 @ 0x10f410, size 740 bytes
int sub_10F410()
{
  int result; // r0
  int *v1; // r9
  int v2; // r0
  int v3; // r2
  int *v4; // r3
  int v5; // r3
  int *v6; // r11
  int16_t **v7; // r6
  int v8; // r5
  int v9; // r8
  int v10; // r7
  int v11; // r0
  unsigned int v12; // r8
  int v13; // r4
  unsigned int v14; // r2
  int v15; // r2
  int v16; // r1
  int v17; // r10
  uint8_t *v18; // r3
  int v19; // r2
  int v20; // r1
  int v21; // r0
  int v22; // r2
  int v23; // r3
  int v24; // r0
  int v25; // [sp+0h] [bp-Ch]
  int *v26; // [sp+4h] [bp-8h]

  result = sub_12D00C(512);
  v26 = *((int **)off_10F6F4 + 2);
  if ( !v26 )
    return result;
  v1 = (int *)off_10F720;
  while ( 2 )
  {
    result = sub_116DBC(v26);
    if ( !result && *((uint8_t *)v26 + 108) )
      goto LABEL_4;
    for ( ; v26[328]; result = sub_13AA68(v2, 3, v3) )
    {
      if ( (__get_CPSR() & 1) == 0 )
      {
        __disable_irq();
        *(uint32_t *)off_10F6F8 = 1;
      }
      ++*v1;
      v2 = sub_12D190(v26 + 328);
      v3 = *v1 - 1;
      if ( *v1 )
      {
        v4 = (int *)off_10F6F8;
        *v1 = v3;
        v5 = *v4;
        if ( !v3 )
        {
          if ( v5 )
            __enable_irq();
        }
      }
    }
    if ( *((uint8_t *)off_10F6FC + 511) )
      goto LABEL_4;
    v6 = v26;
    v7 = (int16_t **)off_10F700;
    v8 = dword_10F704;
    v9 = 4;
    if ( !v26[326] )
    {
LABEL_39:
      v10 = (uint8_t)v9;
      goto LABEL_26;
    }
    while ( 2 )
    {
      v10 = (uint8_t)v9;
      v25 = v9;
      do
      {
        while ( 1 )
        {
          v11 = sub_12D190(v6 + 326);
          v12 = *(uint8_t *)(v11 + 29);
          v13 = v11;
          if ( **v7 < 0 && v12 > 0x1F )
          {
            sub_12F32C(dword_10F714, dword_10F710, 374);
            v12 = *(uint8_t *)(v13 + 29);
          }
          v14 = v8 + 696 * v12;
          if ( !*(uint8_t *)(v14 + 37) && (*(uint16_t *)(v13 + 30) & 8) == 0 )
            break;
          v15 = *(uint8_t *)(v8 + 696 * v12 + 36);
          if ( v15 != 1 )
          {
            sub_13AA68(v13, v10, v15);
            goto LABEL_24;
          }
          if ( **v7 < 0 )
          {
            if ( (*(uint16_t *)(v13 + 30) & 1) != 0 )
            {
LABEL_54:
              sub_12D108(v8 + 8 * (87 * (int16_t)v12 + v25 + 78));
              goto LABEL_23;
            }
            sub_12F32C(dword_10F71C, dword_10F710, 383);
          }
          if ( (*(uint16_t *)(v13 + 30) & 1) != 0 )
            goto LABEL_54;
LABEL_23:
          sub_12E948(dword_10F708, *(uint8_t *)(v8 + 696 * v12 + 35), 696);
LABEL_24:
          if ( !v6[326] )
            goto LABEL_25;
        }
        sub_12E948(dword_10F718, *(uint8_t *)(v14 + 35), v14);
        sub_13A9B4(v13, v10, 0x80000000);
      }
      while ( v6[326] );
LABEL_25:
      v9 = v25;
LABEL_26:
      v16 = v6[316];
      if ( !v16 )
        goto LABEL_37;
      while ( 2 )
      {
        while ( 1 )
        {
          v17 = *(uint8_t *)(v16 + 29);
          v18 = (uint8_t *)(v8 + 696 * v17);
          if ( v18[37] )
            break;
          sub_12E948(dword_10F718, v18[35], v18[37]);
          v24 = sub_12D190(v6 + 316);
          sub_13A9B4(v24, v10, 0x80000000);
          v16 = v6[316];
          if ( !v16 )
            goto LABEL_37;
        }
        if ( v18[36] == 1 )
        {
          if ( (__get_CPSR() & 1) == 0 )
          {
            __disable_irq();
            *(uint32_t *)off_10F6F8 = 1;
          }
          ++*v1;
          sub_12D190(v6 + 316);
          sub_12E948(dword_10F70C, *(uint8_t *)(v8 + 696 * v17 + 35), v8 + 696 * v17);
          if ( *v1 )
          {
            v19 = *v1 - 1;
            v20 = *(uint32_t *)off_10F6F8;
            *v1 = v19;
            if ( !v19 )
            {
              if ( v20 )
                __enable_irq();
            }
          }
          sub_12D108(v8 + 8 * (87 * (int16_t)v17 + v9 + 73));
          goto LABEL_36;
        }
        if ( sub_13BF64(v17, *(uint8_t *)(v16 + 27)) )
        {
          if ( (__get_CPSR() & 1) == 0 )
          {
            __disable_irq();
            *(uint32_t *)off_10F6F8 = 1;
          }
          ++*v1;
          v21 = sub_12D190(v6 + 316);
          if ( *v1 )
          {
            v23 = *v1 - 1;
            v22 = *(uint32_t *)off_10F6F8;
            *v1 = v23;
            if ( !v23 )
            {
              if ( v22 )
                __enable_irq();
            }
          }
          sub_13AA68(v21, v10, v22);
LABEL_36:
          v16 = v6[316];
          if ( !v16 )
            goto LABEL_37;
          continue;
        }
        break;
      }
      *((uint8_t *)off_10F6FC + 512) = 1;
LABEL_37:
      --v9;
      result = sub_11A6A8(v10);
      v6 -= 2;
      if ( v9 != -1 )
      {
        if ( v6[326] )
          continue;
        goto LABEL_39;
      }
      break;
    }
LABEL_4:
    v26 = (int *)*v26;
    if ( v26 )
      continue;
    return result;
  }
}

