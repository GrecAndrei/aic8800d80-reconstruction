// v23 annotated: sub_11316C @ 0x11316c
// Original: 11316c_sub_11316C.c
// Primary struct: <unclustered>
//
// sub_11316C @ 0x11316c, size 126 bytes
int __fastcall sub_11316C(int a1)
{
  unsigned __int16 *v2; // r4
  int v3; // r1
  int v4; // r2
  _BYTE *v5; // r1
  _BYTE *v6; // r2
  _DWORD *v7; // r7
  int v8; // r6
  int v9; // r1
  int v10; // r4
  int v11; // r2

  if ( (*(_DWORD *)off_1131EC & 0x2000000) != 0 )
  {
    sub_100200((int *)off_1131F0, 0xFFu, 4u);
  }
  else
  {
    v2 = (unsigned __int16 *)off_1131F0;
    sub_100200((int *)off_1131F0, 0xFFu, 4u);
    if ( sub_114D38(v2) || (v4 = v2[1], v4 == 0xFFFF) || (v3 = *v2, v3 == 0xFFFF) )
      sub_12E948(dword_1131F4, v3, v4);
    else
      sub_12E948(dword_11320C, v3, v4);
  }
  v5 = off_1131FC;
  v6 = off_113200;
  *(_DWORD *)off_1131F8 = *(_DWORD *)a1;
  v7 = (_DWORD *)dword_113204;
  v8 = dword_113208;
  *v5 = 0;
  *v6 = 0;
  do
  {
    v9 = *(unsigned __int8 *)(a1 + 8);
    if ( *(_BYTE *)(a1 + 8) )
      v9 = 1;
    v10 = sub_111C78(v7, v9);
    sub_12E948(v8, v10, v11);
  }
  while ( v10 );
  return 0;
}

