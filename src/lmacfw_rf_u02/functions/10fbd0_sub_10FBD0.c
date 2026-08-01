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

extern uint32_t off_10FDFC;
extern uint32_t off_10FE08;
extern uint32_t dword_10FE10;
extern uint32_t off_10FE00;
extern uint32_t off_10FE04;
extern uint32_t dword_10FE0C;
extern uint32_t dword_10FE1C;
extern uint32_t dword_10FE18;
extern uint32_t dword_10FE14;
extern uint32_t dword_10FE20;

// sorted_list_search @ 0x10fbd0, size 554 bytes
int  sorted_list_search(int a1, uint32_t *a2)
{
  unsigned int *v4; // r7
  unsigned int v5; // r6
  int v6; // r8
  int *v7; // r5
  unsigned int v8; // r0
  int v9; // cf
  int v10; // r9
  int result; // r0
  int v12; // r3
  int v13; // r2
  int *v14; // r3
  int v15; // r2
  int v16; // r3
  int v17; // r2
  int v18; // r6
  uint16_t *v19; // r9
  int v20; // r6
  int16_t v21; // r3
  int v22; // r0
  int v23; // r3
  int v24; // r3
  int v25; // r2

  if ( !a2 )
    return -1;
  if ( *(uint32_t *)a1 > (unsigned int)a2 || (unsigned int)a2 > *(uint32_t *)a1 + *(uint32_t *)(a1 + 4) )
    return -1;
  if ( (v4 = (unsigned int *)off_10FDFC, (unsigned int)a2 >= *(uint32_t *)off_10FDFC)
    && (unsigned int)a2 <= *(uint32_t *)off_10FDFC + *((uint32_t *)off_10FDFC + 1)
    || (unsigned int)a2 >= *(uint32_t *)off_10FE08
    && (unsigned int)a2 <= *(uint32_t *)off_10FE08 + *((uint32_t *)off_10FE08 + 1) )
  {
    v5 = *((uint8_t *)a2 - 4);
  }
  else
  {
    log_printf(dword_10FE10, a2);
    v5 = 0;
  }
  if ( *(uint8_t *)(a1 + 8) <= v5 )
    return -1;
  v6 = *(uint32_t *)(a1 + 12);
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_10FE00 = 1;
  }
  v7 = (int *)off_10FE04;
  v8 = *v4;
  v9 = (unsigned int)a2 >= *v4;
  ++*(uint32_t *)off_10FE04;
  if ( !v9 || (unsigned int)a2 > v4[1] + v8 )
  {
    v14 = (int *)off_10FE08;
    v15 = *(uint32_t *)off_10FE08;
    if ( (unsigned int)a2 < *(uint32_t *)off_10FE08 || (unsigned int)a2 > *((uint32_t *)off_10FE08 + 1) + v15 )
    {
      log_printf(dword_10FE0C, a2);
    }
    else
    {
      v10 = *((uint8_t *)a2 - 3);
      if ( v10 == 170 )
      {
        if ( (unsigned int)a2 < v8 )
          goto LABEL_37;
        goto LABEL_15;
      }
      if ( v10 == 255 )
      {
        if ( (unsigned int)a2 < v8 )
          goto LABEL_36;
        goto LABEL_15;
      }
    }
LABEL_24:
    if ( *v7 )
    {
      v16 = *v7 - 1;
      v17 = *(uint32_t *)off_10FE00;
      *v7 = v16;
      if ( !v16 )
      {
        if ( v17 )
          __enable_irq();
      }
    }
    return -1;
  }
  v10 = *((uint8_t *)a2 - 3);
  if ( v10 == 170 )
  {
    result = (uint8_t)(*((uint8_t *)a2 - 2) - 1);
    *((uint8_t *)a2 - 2) = result;
    if ( result )
    {
LABEL_17:
      if ( *v7 )
      {
        v12 = *v7 - 1;
        v13 = *(uint32_t *)off_10FE00;
        *v7 = v12;
        if ( !v12 )
        {
          if ( v13 )
            __enable_irq();
        }
      }
      return (char)result;
    }
LABEL_40:
    v18 = 3 * v5;
    v19 = (uint16_t *)(v6 + 4 * v18);
    v20 = 4 * v18;
    if ( *v19 < (unsigned int)v19[1] )
    {
      if ( (unsigned int)a2 >= *v4 && (unsigned int)a2 <= *v4 + v4[1]
        || (unsigned int)a2 >= *(uint32_t *)off_10FE08
        && (unsigned int)a2 <= *(uint32_t *)off_10FE08 + *((uint32_t *)off_10FE08 + 1) )
      {
        *((uint8_t *)a2 - 3) = 85;
      }
      else
      {
        log_printf(dword_10FE1C, a2);
      }
      if ( (unsigned int)a2 >= *v4 && (unsigned int)a2 <= *v4 + v4[1]
        || (unsigned int)a2 >= *(uint32_t *)off_10FE08
        && (unsigned int)a2 <= *(uint32_t *)off_10FE08 + *((uint32_t *)off_10FE08 + 1) )
      {
        *a2 = *((uint32_t *)v19 + 2);
      }
      else
      {
        log_printf(dword_10FE18, a2);
      }
      v21 = *(uint16_t *)(v6 + v20);
      v22 = *v7;
      *((uint32_t *)v19 + 2) = a2;
      *(uint16_t *)(v6 + v20) = v21 + 1;
      if ( !v22 )
        return 0;
      result = v22 - 1;
      v23 = *(uint32_t *)off_10FE00;
      *v7 = result;
      if ( result || !v23 )
        return 0;
      __enable_irq();
      return result;
    }
    goto LABEL_24;
  }
  if ( v10 != 255 )
    goto LABEL_24;
LABEL_15:
  if ( (unsigned int)a2 <= v8 + v4[1] )
    goto LABEL_16;
  v14 = (int *)off_10FE08;
LABEL_36:
  v15 = *v14;
  if ( (unsigned int)a2 < *v14 )
  {
LABEL_38:
    log_printf(dword_10FE14, a2);
    goto LABEL_39;
  }
LABEL_37:
  if ( (unsigned int)a2 > v15 + v14[1] )
    goto LABEL_38;
LABEL_16:
  result = (uint8_t)(*((uint8_t *)a2 - 2) - 1);
  *((uint8_t *)a2 - 2) = result;
  if ( result )
    goto LABEL_17;
LABEL_39:
  if ( v10 != 255 )
    goto LABEL_40;
  if ( (unsigned int)a2 >= *v4 && (unsigned int)a2 <= *v4 + v4[1]
    || (unsigned int)a2 >= *(uint32_t *)off_10FE08
    && (unsigned int)a2 <= *(uint32_t *)off_10FE08 + *((uint32_t *)off_10FE08 + 1) )
  {
    *((uint8_t *)a2 - 2) = 1;
  }
  else
  {
    log_printf(dword_10FE20, a2);
  }
  if ( *v7 )
  {
    v24 = *v7 - 1;
    v25 = *(uint32_t *)off_10FE00;
    *v7 = v24;
    if ( !v24 )
    {
      if ( v25 )
        __enable_irq();
    }
  }
  return 1;
}

