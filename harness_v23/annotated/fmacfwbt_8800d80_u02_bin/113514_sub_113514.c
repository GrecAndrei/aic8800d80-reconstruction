// v23 annotated: sub_113514 @ 0x113514
// Original: 113514_sub_113514.c
// Primary struct: <unclustered>
//
// sub_113514 @ 0x113514, size 294 bytes
void sub_113514()
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

  v0 = off_11363C;
  if ( *(_BYTE *)off_11363C )
  {
    if ( !*(_WORD *)off_113648 )
    {
      sub_12EEF8(512, dword_113664);
      return;
    }
    if ( *(unsigned __int8 *)off_113644 >= (unsigned int)*(unsigned __int16 *)off_113648 )
    {
      v13 = dword_113650;
      *(_BYTE *)off_113640 = 1;
      sub_12EEF8(512, v13);
    }
  }
  else
  {
    if ( *(_BYTE *)off_113640 )
      return;
    if ( *(unsigned __int8 *)off_113644 >= (unsigned int)*(unsigned __int16 *)off_113648 && !*(_BYTE *)off_113640 )
    {
      *(_BYTE *)off_113640 = 1;
      sub_12EEF8(512, dword_113650);
      return;
    }
  }
  v1 = (*(int (__fastcall **)(_DWORD))(*((_DWORD *)off_113654 + 2) + 16))(*((_DWORD *)off_113654 + 1));
  v2 = (_DWORD *)v1;
  if ( v1 )
  {
    if ( *v0 )
    {
      v3 = off_11366C;
      v4 = (unsigned int *)off_113658;
      v5 = *(_DWORD *)off_113658;
      v6 = *(_DWORD *)off_11366C + v1;
      if ( *(_BYTE *)off_113640 )
        v7 = sub_11324C(v6, v5);
      else
        v7 = sub_1131AC(v6, v5);
    }
    else
    {
      v3 = off_11366C;
      v4 = (unsigned int *)off_113658;
      v7 = sub_1131AC(*(_DWORD *)off_11366C + v1, *(_DWORD *)off_113658);
    }
    if ( v7 )
    {
      v8 = off_113640;
      sub_10DA7C(dword_11365C, v7);
      v9 = 5;
      while ( 1 )
      {
        if ( *v0 )
        {
          v10 = *v4;
          v11 = (int)v2 + *v3;
          v12 = *v8 ? sub_11324C(v11, v10) : sub_1131AC(v11, v10);
        }
        else
        {
          v12 = sub_1131AC((int)v2 + *v3, *v4);
        }
        if ( !v12 )
          break;
        if ( !--v9 )
        {
          sub_10DA7C(dword_113660, 5);
          sub_10FE60(v2);
          sub_12D32C(32);
          return;
        }
      }
    }
  }
  else
  {
    sub_12D32C(32);
    sub_10DA7C(dword_113668);
  }
}

