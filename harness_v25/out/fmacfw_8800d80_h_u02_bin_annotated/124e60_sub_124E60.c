// fwstruct annotate: 124e60_sub_124E60.c
// sub_124E60 @ 0x124e60, size 134 bytes
int __fastcall sub_124E60(_BYTE *a1, int a2, int a3)
{
  char v4; // r2
  int v5; // r1
  int v6; // r0
  int v7; // r2
  int result; // r0
  unsigned int v9; // r3
  _BYTE *v10; // r0
  _BYTE *v11; // r6

  if ( (a2 & 0x800000) != 0 )
  {
    result = sub_12E948(dword_124EF0, dword_124EE8, a3);
    v9 = (unsigned __int8)a1[35];
    a1[668] = 0;
    if ( v9 <= 0x23 )
    {
      *(_DWORD *)(dword_124EF4 + 696 * v9 + 664) = *((_DWORD *)off_124EF8 + 4);
      return 696;
    }
  }
  else
  {
    v4 = a1[668];
    v5 = dword_124EE8;
    v6 = dword_124EEC;
    v7 = (unsigned __int8)(v4 + 1);
    a1[668] = v7;
    result = sub_12E948(v6, v5, v7);
    if ( (unsigned __int8)a1[668] > 9u )
    {
      v10 = (_BYTE *)sub_12C7EC(125, 13, 0, 8);
      *v10 = a1[35];
      v10[1] = a1[34];
      v11 = v10;
      a1[668] = 0;
      sub_143630(v10 + 2, a1 + 38, 6);
      return sub_12C84C(v11);
    }
  }
  return result;
}

