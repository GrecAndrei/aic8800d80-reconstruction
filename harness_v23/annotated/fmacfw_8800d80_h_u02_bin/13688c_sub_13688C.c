// v23 annotated: sub_13688C @ 0x13688c
// Original: 13688c_sub_13688C.c
// Primary struct: <unclustered>
//
// sub_13688C @ 0x13688c, size 290 bytes
_DWORD *__fastcall sub_13688C(int a1)
{
  _BYTE *v2; // r6
  int v3; // r0
  _BYTE *v4; // r5
  int v5; // r1
  unsigned int v6; // r2
  int *v7; // r3
  _BYTE *v8; // r0
  _BYTE *v9; // r3
  char *v10; // r0
  int v12; // r0
  int v13; // r0

  v2 = (_BYTE *)sub_12C7EC(5145, 5, 7, 2u);
  v3 = sub_12C7EC(5143, 5, 7, 2u);
  *(_BYTE *)(dword_1369B0 + 696 * (*(unsigned __int8 *)(a1 + 107) + 32) + 37) = 0;
  v4 = (_BYTE *)v3;
  sub_136528();
  *v2 = 0;
  v2[1] = *(_BYTE *)(a1 + 107);
  sub_12D108(dword_1369B4, (_DWORD *)v2 - 3);
  v7 = *((int **)off_1369B8 + 2);
  if ( v7 )
  {
    v5 = 4999;
    while ( 1 )
    {
      if ( (int *)a1 != v7 )
      {
        v6 = *((unsigned __int8 *)v7 + 108);
        if ( *((_BYTE *)v7 + 108) )
        {
          v6 = *((unsigned __int16 *)v7 + 208);
          if ( v6 <= 0x1387 )
            break;
        }
      }
      v7 = (int *)*v7;
      if ( !v7 )
        goto LABEL_7;
    }
    sub_10D0BC(v6 | (*((unsigned __int8 *)v7 + 413) << 16) | 0x80000000, 4999, v6);
  }
  else
  {
LABEL_7:
    sub_10D0BC(0, v5, v6);
  }
  sub_12063C((int *)a1, 0, 0);
  if ( *(_BYTE *)(a1 + 108) )
  {
    v12 = sub_12C7EC(30, 0, 7, 4u);
    *(_BYTE *)(v12 + 2) = 0;
    *(_BYTE *)(v12 + 3) = *(_BYTE *)(a1 + 107);
    sub_12D108(dword_1369B4, (_DWORD *)(v12 - 12));
  }
  if ( *(_DWORD *)(a1 + 72) )
  {
    v8 = (_BYTE *)sub_12C7EC(57, 0, 7, 1u);
    *v8 = *(_BYTE *)(a1 + 107);
    sub_12D108(dword_1369B4, (_DWORD *)v8 - 3);
  }
  *v4 = 0;
  v4[1] = *(_BYTE *)(a1 + 107);
  sub_12D108(dword_1369B4, (_DWORD *)v4 - 3);
  sub_1366E0();
  if ( !*(_BYTE *)(a1 + 1224) )
  {
    v13 = dword_1369C4;
    *(_BYTE *)off_1369C0 = 0;
    sub_12E948(v13);
  }
  v9 = off_1369BC;
  v10 = (char *)off_1369BC + 20;
  *((_BYTE *)off_1369BC + 13) = 0;
  v9[14] = 0;
  sub_124CF4((int)v10);
  return sub_12CBF4(7u, 3);
}

