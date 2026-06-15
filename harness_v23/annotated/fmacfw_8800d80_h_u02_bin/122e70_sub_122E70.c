// v23 annotated: sub_122E70 @ 0x122e70
// Original: 122e70_sub_122E70.c
// Primary struct: <unclustered>
//
// sub_122E70 @ 0x122e70, size 186 bytes
int __fastcall sub_122E70(int a1, _BYTE *a2, int a3, int a4)
{
  int v5; // r1
  int v6; // r2
  _BYTE *v7; // r5
  int v8; // r2
  _BYTE *v9; // r6
  unsigned int v10; // r7
  int v11; // r1
  int v13; // r2
  _BYTE v14[5]; // [sp+7h] [bp-5h] BYREF

  v14[0] = 0;
  v7 = (_BYTE *)sub_12C7EC(124, a4, a3, 2);
  if ( *a2 )
  {
    sub_12E948(dword_122F2C, v5, v6);
    **(_BYTE **)off_122F30 = 0;
  }
  else
  {
    sub_12E948(dword_122F3C, v5, v6);
    **(_BYTE **)off_122F30 = 3;
  }
  sub_114A04(v14);
  v8 = v14[0];
  v7[1] = v14[0];
  if ( a2[1] )
  {
    v9 = off_122F34;
    *((_BYTE *)off_122F34 + 188) = (v8 & 0x20) != 0;
    v10 = ((v8 ^ 0x40u) >> 6) & 1;
  }
  else
  {
    v13 = (unsigned __int8)a2[2];
    v9 = off_122F34;
    v10 = ((v13 ^ 0x40u) >> 6) & 1;
    *((_BYTE *)off_122F34 + 188) = (v13 & 0x20) != 0;
  }
  if ( sub_114A58() )
  {
    v9[188] = 0;
    v11 = 0;
  }
  else
  {
    v11 = (unsigned __int8)v9[188];
  }
  if ( *a2 )
  {
    if ( a2[3] )
      *((_WORD *)v9 + 89) |= 0x4000u;
    sub_12E948(dword_122F38, v11, v10);
    LOBYTE(v11) = v9[188];
  }
  *v7 = v11;
  sub_12C84C(v7);
  return 0;
}

