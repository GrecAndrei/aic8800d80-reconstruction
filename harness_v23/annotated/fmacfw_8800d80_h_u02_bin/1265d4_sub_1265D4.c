// v23 annotated: sub_1265D4 @ 0x1265d4
// Original: 1265d4_sub_1265D4.c
// Primary struct: <unclustered>
//
// sub_1265D4 @ 0x1265d4, size 166 bytes
int __fastcall sub_1265D4(int a1, int a2, int a3)
{
  int v6; // r0
  _DWORD *v7; // r4
  _DWORD *v8; // r5
  char *v9; // r0
  int v10; // r6
  int result; // r0
  int *v12; // r6
  int v13; // r1
  int v14; // r0
  int v15; // r3
  int v16; // r2
  int *v17; // r3
  int v18; // r3
  int v19; // r3
  int v20; // r2

  v6 = sub_12D190(dword_12667C);
  v7 = (_DWORD *)v6;
  if ( **(__int16 **)off_126680 < 0 && !v6 )
    sub_12F32C(dword_12668C, dword_126688, 227);
  v8 = off_126684;
  v9 = (char *)off_126684 + 32;
  v10 = *((_DWORD *)off_126684 + 8);
  v7[3] = a3;
  v7[1] = a1;
  v7[2] = a2;
  result = sub_12D108(v9);
  if ( !v10 )
  {
    v8[18] = v7;
    if ( (__get_CPSR() & 1) == 0 )
    {
      __disable_irq();
      *(_DWORD *)off_126690 = 1;
    }
    v12 = (int *)off_126698;
    v13 = v7[1];
    v14 = *(_DWORD *)off_126698;
    v15 = v13 - *((_DWORD *)off_126694 + 4);
    v16 = *(_DWORD *)off_126698 + 1;
    *(_DWORD *)off_126698 = v16;
    if ( v15 - 64 >= 0 )
    {
      result = sub_124BFC(dword_12669C, v13);
      if ( *v12 )
      {
        v19 = *v12 - 1;
        v20 = *(_DWORD *)off_126690;
        *v12 = v19;
        if ( !v19 )
        {
          if ( v20 )
            __enable_irq();
        }
      }
    }
    else
    {
      if ( v16 )
      {
        v17 = (int *)off_126690;
        *v12 = v14;
        v18 = *v17;
        if ( !v14 )
        {
          if ( v18 )
            __enable_irq();
        }
      }
      return ((int (__fastcall *)(_DWORD *))v8[17])(v7);
    }
  }
  return result;
}

