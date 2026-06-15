// sub_113108 @ 0x113108, size 126 bytes
int __fastcall sub_113108(int a1)
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

  if ( (*(_DWORD *)off_113188 & 0x2000000) != 0 )
  {
    sub_100200((int *)off_11318C, 0xFFu, 4u);
  }
  else
  {
    v2 = (unsigned __int16 *)off_11318C;
    sub_100200((int *)off_11318C, 0xFFu, 4u);
    if ( sub_1154B4(v2) || (v4 = v2[1], v4 == 0xFFFF) || (v3 = *v2, v3 == 0xFFFF) )
      sub_12ECB0(dword_113190, v3, v4);
    else
      sub_12ECB0(dword_1131A8, v3, v4);
  }
  v5 = off_113198;
  v6 = off_11319C;
  *(_DWORD *)off_113194 = *(_DWORD *)a1;
  v7 = (_DWORD *)dword_1131A0;
  v8 = dword_1131A4;
  *v5 = 0;
  *v6 = 0;
  do
  {
    v9 = *(unsigned __int8 *)(a1 + 8);
    if ( *(_BYTE *)(a1 + 8) )
      v9 = 1;
    v10 = sub_111C14(v7, v9);
    sub_12ECB0(v8, v10, v11);
  }
  while ( v10 );
  return 0;
}

