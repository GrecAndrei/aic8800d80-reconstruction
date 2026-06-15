// sub_1347D4 @ 0x1347d4, size 314 bytes
int sub_1347D4()
{
  _WORD *v0; // r6
  int v1; // r4
  int v2; // r5
  __int16 v3; // r7
  _DWORD *v4; // r1
  int *v5; // r2
  int *v6; // r3
  unsigned int v7; // r2
  int result; // r0
  _DWORD *v9; // r12
  int *v10; // r0
  int v11; // r1

  v0 = off_134910;
  v1 = *((_DWORD *)off_134910 + 2);
  sub_12EB90(256, dword_134914);
  v2 = sub_12C7EC(6149, 13, 6, 6u);
  if ( *((_BYTE *)v0 + 4) )
    v3 = 0;
  else
    v3 = v0[6];
  *(_BYTE *)(v1 + 149) = 0;
  sub_124CF4(v1 + 152);
  v6 = *((int **)off_134918 + 2);
  if ( !v6 )
  {
LABEL_14:
    sub_10D0BC(0, (int)v4, (int)v5);
    goto LABEL_15;
  }
  v4 = nullptr;
  while ( 1 )
  {
    while ( 1 )
    {
      if ( !*((_BYTE *)v6 + 106) )
      {
        if ( !*((_BYTE *)v6 + 108) )
          goto LABEL_8;
        v4 = (_DWORD *)((char *)v4 + 1);
        if ( (int *)v1 == v6 )
          goto LABEL_8;
        break;
      }
      if ( (int *)v1 == v6 )
        goto LABEL_8;
      if ( *((_BYTE *)v6 + 108) )
        break;
      v6 = (int *)*v6;
      if ( !v6 )
      {
LABEL_13:
        v5 = *(int **)off_13491C;
        if ( *(int *)off_13491C < 0 && v4 == (_DWORD *)1 )
        {
          v4 = off_134924;
          *((_BYTE *)off_134920 + 2) = (_BYTE)v6;
          v5 = (int *)off_134928;
          *v4 |= 0x80000000;
          *v5 = (HIWORD(*v5) << 16) | 0x5DC;
        }
        goto LABEL_14;
      }
    }
    v7 = *((unsigned __int16 *)v6 + 208);
    if ( v7 <= 0x1387 )
      break;
LABEL_8:
    v6 = (int *)*v6;
    if ( !v6 )
      goto LABEL_13;
  }
  if ( *(int *)off_13491C < 0 && v4 == (_DWORD *)1 )
  {
    v9 = off_134924;
    *((_BYTE *)off_134920 + 2) = 0;
    v10 = (int *)off_134928;
    *v9 |= 0x80000000;
    v11 = (HIWORD(*v10) << 16) | 0x5DC;
    *v10 = v11;
    sub_10D0BC(v7 | (*((unsigned __int8 *)v6 + 413) << 16) | 0x80000000, v11, v7);
  }
  else
  {
    sub_10D0BC(v7 | (*((unsigned __int8 *)v6 + 413) << 16) | 0x80000000, (int)v4, v7);
  }
LABEL_15:
  sub_12063C((int *)v1, 0, 0);
  result = sub_1346C0(v1);
  *(_WORD *)v2 = v3;
  *(_BYTE *)(v2 + 2) = *(_BYTE *)(v1 + 107);
  *(_BYTE *)(v2 + 4) = *((_BYTE *)v0 + 33);
  *(_DWORD *)v0 = v2 - 12;
  return result;
}

