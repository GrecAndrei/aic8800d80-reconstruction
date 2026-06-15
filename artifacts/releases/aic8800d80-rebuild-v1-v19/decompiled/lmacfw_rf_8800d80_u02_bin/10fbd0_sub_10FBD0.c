// sub_10FBD0 @ 0x10fbd0, size 554 bytes
int __fastcall sub_10FBD0(int a1, _DWORD *a2)
{
  unsigned int *v4; // r7
  unsigned int v5; // r6
  int v6; // r8
  int *v7; // r5
  unsigned int v8; // r0
  bool v9; // cf
  int v10; // r9
  int result; // r0
  int v12; // r3
  int v13; // r2
  int *v14; // r3
  int v15; // r2
  int v16; // r3
  int v17; // r2
  int v18; // r6
  unsigned __int16 *v19; // r9
  int v20; // r6
  __int16 v21; // r3
  int v22; // r0
  int v23; // r3
  int v24; // r3
  int v25; // r2

  if ( !a2 )
    return -1;
  if ( *(_DWORD *)a1 > (unsigned int)a2 || (unsigned int)a2 > *(_DWORD *)a1 + *(_DWORD *)(a1 + 4) )
    return -1;
  if ( (v4 = (unsigned int *)off_10FDFC, (unsigned int)a2 >= *(_DWORD *)off_10FDFC)
    && (unsigned int)a2 <= *(_DWORD *)off_10FDFC + *((_DWORD *)off_10FDFC + 1)
    || (unsigned int)a2 >= *(_DWORD *)off_10FE08
    && (unsigned int)a2 <= *(_DWORD *)off_10FE08 + *((_DWORD *)off_10FE08 + 1) )
  {
    v5 = *((unsigned __int8 *)a2 - 4);
  }
  else
  {
    sub_10DA6C(dword_10FE10, a2);
    v5 = 0;
  }
  if ( *(unsigned __int8 *)(a1 + 8) <= v5 )
    return -1;
  v6 = *(_DWORD *)(a1 + 12);
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)off_10FE00 = 1;
  }
  v7 = (int *)off_10FE04;
  v8 = *v4;
  v9 = (unsigned int)a2 >= *v4;
  ++*(_DWORD *)off_10FE04;
  if ( !v9 || (unsigned int)a2 > v4[1] + v8 )
  {
    v14 = (int *)off_10FE08;
    v15 = *(_DWORD *)off_10FE08;
    if ( (unsigned int)a2 < *(_DWORD *)off_10FE08 || (unsigned int)a2 > *((_DWORD *)off_10FE08 + 1) + v15 )
    {
      sub_10DA6C(dword_10FE0C, a2);
    }
    else
    {
      v10 = *((unsigned __int8 *)a2 - 3);
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
      v17 = *(_DWORD *)off_10FE00;
      *v7 = v16;
      if ( !v16 )
      {
        if ( v17 )
          __enable_irq();
      }
    }
    return -1;
  }
  v10 = *((unsigned __int8 *)a2 - 3);
  if ( v10 == 170 )
  {
    result = (unsigned __int8)(*((_BYTE *)a2 - 2) - 1);
    *((_BYTE *)a2 - 2) = result;
    if ( result )
    {
LABEL_17:
      if ( *v7 )
      {
        v12 = *v7 - 1;
        v13 = *(_DWORD *)off_10FE00;
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
    v19 = (unsigned __int16 *)(v6 + 4 * v18);
    v20 = 4 * v18;
    if ( *v19 < (unsigned int)v19[1] )
    {
      if ( (unsigned int)a2 >= *v4 && (unsigned int)a2 <= *v4 + v4[1]
        || (unsigned int)a2 >= *(_DWORD *)off_10FE08
        && (unsigned int)a2 <= *(_DWORD *)off_10FE08 + *((_DWORD *)off_10FE08 + 1) )
      {
        *((_BYTE *)a2 - 3) = 85;
      }
      else
      {
        sub_10DA6C(dword_10FE1C, a2);
      }
      if ( (unsigned int)a2 >= *v4 && (unsigned int)a2 <= *v4 + v4[1]
        || (unsigned int)a2 >= *(_DWORD *)off_10FE08
        && (unsigned int)a2 <= *(_DWORD *)off_10FE08 + *((_DWORD *)off_10FE08 + 1) )
      {
        *a2 = *((_DWORD *)v19 + 2);
      }
      else
      {
        sub_10DA6C(dword_10FE18, a2);
      }
      v21 = *(_WORD *)(v6 + v20);
      v22 = *v7;
      *((_DWORD *)v19 + 2) = a2;
      *(_WORD *)(v6 + v20) = v21 + 1;
      if ( !v22 )
        return 0;
      result = v22 - 1;
      v23 = *(_DWORD *)off_10FE00;
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
    sub_10DA6C(dword_10FE14, a2);
    goto LABEL_39;
  }
LABEL_37:
  if ( (unsigned int)a2 > v15 + v14[1] )
    goto LABEL_38;
LABEL_16:
  result = (unsigned __int8)(*((_BYTE *)a2 - 2) - 1);
  *((_BYTE *)a2 - 2) = result;
  if ( result )
    goto LABEL_17;
LABEL_39:
  if ( v10 != 255 )
    goto LABEL_40;
  if ( (unsigned int)a2 >= *v4 && (unsigned int)a2 <= *v4 + v4[1]
    || (unsigned int)a2 >= *(_DWORD *)off_10FE08
    && (unsigned int)a2 <= *(_DWORD *)off_10FE08 + *((_DWORD *)off_10FE08 + 1) )
  {
    *((_BYTE *)a2 - 2) = 1;
  }
  else
  {
    sub_10DA6C(dword_10FE20, a2);
  }
  if ( *v7 )
  {
    v24 = *v7 - 1;
    v25 = *(_DWORD *)off_10FE00;
    *v7 = v24;
    if ( !v24 )
    {
      if ( v25 )
        __enable_irq();
    }
  }
  return 1;
}

