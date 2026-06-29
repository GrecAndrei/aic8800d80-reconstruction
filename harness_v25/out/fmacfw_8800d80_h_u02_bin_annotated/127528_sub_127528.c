// fwstruct annotate: 127528_sub_127528.c
// sub_127528 @ 0x127528, size 526 bytes
int __fastcall sub_127528(int a1)
{
  __int16 **v1; // r7
  _BYTE *v2; // r6
  int v4; // r0
  int v5; // r5
  int v6; // r3
  _DWORD *v7; // r4
  int v8; // r3
  int v9; // r2
  int v10; // r3
  int v11; // r2
  char *v12; // r0
  int v13; // r0
  int result; // r0
  int *v15; // r5
  int v16; // r1
  int v17; // r6
  int v18; // r3
  int v19; // r2
  int *v20; // r3
  int v21; // r3
  int v22; // r1
  int v23; // r2
  int v24; // r3
  int v25; // r7
  int v26; // r3
  int v27; // r3
  unsigned int v28; // r8
  _DWORD *v29; // r2
  _DWORD *v30; // r7
  int v31; // r1
  int v32; // r0
  int v33; // r3
  int *v34; // r3
  int v35; // r3
  _DWORD *v36; // r2
  int v37; // r3
  int v38; // r2

  v1 = (__int16 **)off_127738;
  v2 = off_12773C;
  v4 = sub_12D190(dword_127740);
  v5 = v4;
  if ( **v1 >= 0 )
  {
    v6 = (unsigned __int8)*v2;
    if ( *v2 )
    {
LABEL_3:
      v7 = off_127744;
      goto LABEL_4;
    }
    goto LABEL_25;
  }
  if ( a1 == v4 )
  {
    v6 = (unsigned __int8)*v2;
    if ( *v2 )
      goto LABEL_3;
  }
  else
  {
    sub_12F32C(dword_127774, dword_127770, 1958);
    v6 = (unsigned __int8)*v2;
    if ( *v2 )
      goto LABEL_3;
    if ( **v1 >= 0 )
    {
LABEL_25:
      v7 = off_127744;
      goto LABEL_5;
    }
  }
  v7 = off_127744;
  v8 = *((_DWORD *)off_127744 + 10);
  if ( v8 )
    goto LABEL_6;
  sub_12F32C(dword_127778, dword_127770, 1960);
  v6 = (unsigned __int8)*v2;
LABEL_4:
  if ( v6 != 1 )
  {
LABEL_5:
    v8 = v7[10];
    goto LABEL_6;
  }
  sub_12E948(dword_12775C, *((unsigned __int8 *)v7 + 88), v7[11]);
  v24 = *((unsigned __int8 *)v7 + 88);
  if ( (v24 & 8) != 0 )
  {
    v25 = dword_12777C;
  }
  else
  {
    v22 = v24 << 29;
    if ( (v24 & 4) == 0 )
    {
      v25 = v7[11];
      if ( !v25 )
        goto LABEL_5;
      goto LABEL_32;
    }
    v25 = dword_127760;
  }
  v26 = v7[11];
  if ( v26 != v25 && v26 )
  {
    v23 = 1;
    *(_BYTE *)(v26 + 16) = 1;
  }
LABEL_32:
  v27 = v7[10];
  if ( v27 )
  {
    v23 = 1;
    *(_BYTE *)(v27 + 16) = 1;
  }
  v7[10] = v25;
  v7[11] = 0;
  v28 = *(unsigned __int8 *)(v25 + 24);
  *(_BYTE *)(v25 + 16) = 4;
  if ( v28 == 3 )
  {
    sub_12E948(dword_127784, v22, v23);
    sub_12CBF4(2);
    v28 = *(unsigned __int8 *)(v25 + 24);
  }
  if ( v28 <= 2 )
    goto LABEL_5;
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)off_127750 = 1;
  }
  v29 = off_127758;
  v30 = off_127764;
  v31 = *(_DWORD *)off_127758;
  v32 = *(_DWORD *)off_127758 + 1;
  v33 = *((_DWORD *)off_127764 + 1) | 2;
  *(_DWORD *)off_127758 = v32;
  v30[1] = v33;
  if ( v32 )
  {
    v34 = (int *)off_127750;
    *v29 = v31;
    v35 = *v34;
    if ( !v31 )
    {
      if ( v35 )
        __enable_irq();
    }
  }
  v36 = off_127768;
  v8 = v7[10];
  *((_BYTE *)v7 + 92) = (*(_DWORD *)off_127768 & 4) != 0;
  *v36 &= ~4u;
LABEL_6:
  *(_BYTE *)(v8 + 16) = 1;
  v9 = v7[20];
  v10 = 0;
  *v2 = 0;
  if ( v9 )
  {
    v11 = *((unsigned __int8 *)v7 + 90);
    v7[20] = 0;
    if ( !v11 )
    {
      *(_DWORD *)(v5 + 8) = 0;
      goto LABEL_14;
    }
    if ( v11 == 1 || (v10 = v7[4]) == 0 )
    {
      v12 = (char *)off_127780;
      if ( *((unsigned __int8 *)off_127780 + 24) == 255 )
      {
        if ( *((unsigned __int8 *)off_127780 + 52) == 255 )
        {
          if ( *((unsigned __int8 *)off_127780 + 80) == 255 )
          {
            *(_DWORD *)(v5 + 8) = v10;
            goto LABEL_14;
          }
          v12 = (char *)off_127780 + 56;
        }
        else
        {
          v12 = (char *)off_127780 + 28;
        }
      }
    }
    else
    {
      v12 = *(char **)(dword_127748 + 1320 * *(unsigned __int8 *)(v10 + 8) + 72);
    }
    *(_DWORD *)(v5 + 8) = v12;
  }
  else
  {
    v12 = *(char **)(v5 + 8);
  }
  if ( v12 )
    sub_126F8C((int)v12);
LABEL_14:
  sub_12D108(dword_12774C);
  v13 = v7[10];
  if ( *(unsigned __int8 *)(v13 + 24) > 2u )
    sub_12723C(v13, 0);
  result = v7[8];
  v7[18] = result;
  if ( result )
  {
    if ( (__get_CPSR() & 1) == 0 )
    {
      __disable_irq();
      *(_DWORD *)off_127750 = 1;
    }
    v15 = (int *)off_127758;
    v16 = *(_DWORD *)(result + 4);
    v17 = *(_DWORD *)off_127758;
    v18 = v16 - *((_DWORD *)off_127754 + 4);
    v19 = *(_DWORD *)off_127758 + 1;
    *(_DWORD *)off_127758 = v19;
    if ( v18 - 64 >= 0 )
    {
      result = sub_124BFC(dword_12776C, v16);
      if ( *v15 )
      {
        v37 = *v15 - 1;
        v38 = *(_DWORD *)off_127750;
        *v15 = v37;
        if ( !v37 )
        {
          if ( v38 )
            __enable_irq();
        }
      }
    }
    else
    {
      if ( v19 )
      {
        v20 = (int *)off_127750;
        *v15 = v17;
        v21 = *v20;
        if ( !v17 )
        {
          if ( v21 )
            __enable_irq();
        }
      }
      return ((int (*)(void))v7[17])();
    }
  }
  return result;
}

