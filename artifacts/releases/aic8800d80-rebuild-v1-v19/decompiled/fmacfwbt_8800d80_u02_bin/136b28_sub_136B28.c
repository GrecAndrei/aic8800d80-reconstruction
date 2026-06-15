// sub_136B28 @ 0x136b28, size 256 bytes
_DWORD *__fastcall sub_136B28(int a1)
{
  _BYTE *v2; // r6
  int v3; // r0
  _BYTE *v4; // r5
  int v5; // r1
  unsigned int v6; // r2
  int *v7; // r3
  _BYTE *v8; // r0
  int v9; // r0
  int v11; // r0

  v2 = (_BYTE *)sub_12CB54(5145, 5, 7, 2u);
  v3 = sub_12CB54(5143, 5, 7, 2u);
  *(_BYTE *)(dword_136C28 + 696 * (*(unsigned __int8 *)(a1 + 107) + 32) + 37) = 0;
  v4 = (_BYTE *)v3;
  sub_136828();
  *v2 = 0;
  v2[1] = *(_BYTE *)(a1 + 107);
  sub_12D470(dword_136C2C, (_DWORD *)v2 - 3);
  v7 = *((int **)off_136C30 + 2);
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
    sub_10D054(v6 | (*((unsigned __int8 *)v7 + 413) << 16) | 0x80000000, 4999, v6);
  }
  else
  {
LABEL_7:
    sub_10D054(0, v5, v6);
  }
  sub_120AB4((int *)a1, 0, 0);
  if ( *(_BYTE *)(a1 + 108) )
  {
    v11 = sub_12CB54(30, 0, 7, 4u);
    *(_BYTE *)(v11 + 2) = 0;
    *(_BYTE *)(v11 + 3) = *(_BYTE *)(a1 + 107);
    sub_12D470(dword_136C2C, (_DWORD *)(v11 - 12));
  }
  if ( *(_DWORD *)(a1 + 72) )
  {
    v8 = (_BYTE *)sub_12CB54(57, 0, 7, 1u);
    *v8 = *(_BYTE *)(a1 + 107);
    sub_12D470(dword_136C2C, (_DWORD *)v8 - 3);
  }
  *v4 = 0;
  v9 = dword_136C2C;
  v4[1] = *(_BYTE *)(a1 + 107);
  sub_12D470(v9, (_DWORD *)v4 - 3);
  sub_13697C();
  return sub_12CF5C(7u, 3);
}

