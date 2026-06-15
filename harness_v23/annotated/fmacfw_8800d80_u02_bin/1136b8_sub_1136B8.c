// v23 annotated: sub_1136B8 @ 0x1136b8
// Original: 1136b8_sub_1136B8.c
// Primary struct: <unclustered>
//
// sub_1136B8 @ 0x1136b8, size 294 bytes
void sub_1136B8()
{
  _BYTE *v0; // r5
  int v1; // r0
  _DWORD *v2; // r4
  _DWORD *v3; // r8
  unsigned int *v4; // r6
  unsigned int v5; // r1
  int v6; // r0
  int v7; // r0
  _BYTE *v8; // r7
  int v9; // r9
  unsigned int v10; // r1
  int v11; // r0
  int v12; // r0
  int v13; // r1

  v0 = off_1137E0;
  if ( *(_BYTE *)off_1137E0 )
  {
    if ( !*(_WORD *)off_1137EC )
    {
      sub_12ECD0(512, dword_113808);
      return;
    }
    if ( *(unsigned __int8 *)off_1137E8 >= (unsigned int)*(unsigned __int16 *)off_1137EC )
    {
      v13 = dword_1137F4;
      *(_BYTE *)off_1137E4 = 1;
      sub_12ECD0(512, v13);
    }
  }
  else
  {
    if ( *(_BYTE *)off_1137E4 )
      return;
    if ( *(unsigned __int8 *)off_1137E8 >= (unsigned int)*(unsigned __int16 *)off_1137EC && !*(_BYTE *)off_1137E4 )
    {
      *(_BYTE *)off_1137E4 = 1;
      sub_12ECD0(512, dword_1137F4);
      return;
    }
  }
  v1 = (*(int (__fastcall **)(_DWORD))(*((_DWORD *)off_1137F8 + 2) + 16))(*((_DWORD *)off_1137F8 + 1));
  v2 = (_DWORD *)v1;
  if ( v1 )
  {
    if ( *v0 )
    {
      v3 = off_113810;
      v4 = (unsigned int *)off_1137FC;
      v5 = *(_DWORD *)off_1137FC;
      v6 = *(_DWORD *)off_113810 + v1;
      if ( *(_BYTE *)off_1137E4 )
        v7 = sub_1133F0(v6, v5);
      else
        v7 = sub_113350(v6, v5);
    }
    else
    {
      v3 = off_113810;
      v4 = (unsigned int *)off_1137FC;
      v7 = sub_113350(*(_DWORD *)off_113810 + v1, *(_DWORD *)off_1137FC);
    }
    if ( v7 )
    {
      v8 = off_1137E4;
      sub_10DC24(dword_113800, v7);
      v9 = 5;
      while ( 1 )
      {
        if ( *v0 )
        {
          v10 = *v4;
          v11 = (int)v2 + *v3;
          v12 = *v8 ? sub_1133F0(v11, v10) : sub_113350(v11, v10);
        }
        else
        {
          v12 = sub_113350((int)v2 + *v3, *v4);
        }
        if ( !v12 )
          break;
        if ( !--v9 )
        {
          sub_10DC24(dword_113804, 5);
          sub_110008(v2);
          sub_12D104(32);
          return;
        }
      }
    }
  }
  else
  {
    sub_12D104(32);
    sub_10DC24(dword_11380C);
  }
}

