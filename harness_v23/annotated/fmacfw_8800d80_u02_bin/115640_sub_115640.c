// v23 annotated: sub_115640 @ 0x115640
// Original: 115640_sub_115640.c
// Primary struct: <unclustered>
//
// sub_115640 @ 0x115640, size 296 bytes
int sub_115640()
{
  _DWORD *v0; // r2
  _BYTE *v1; // r4
  _DWORD *v2; // r2
  _BYTE *v3; // r6
  _DWORD *v4; // r3
  _BYTE **v5; // r5
  int v6; // r3
  int result; // r0
  _BYTE *v8; // r7
  int v9; // r3
  int v10; // r3
  int v11; // r1
  _DWORD *v12; // r4

  v0 = off_11576C;
  *((_DWORD *)off_115768 + 14) |= 0x10u;
  *v0 &= ~0x2000000u;
  v1 = off_115774;
  sub_12ECD0(2, dword_115770);
  v2 = off_115778;
  *(_DWORD *)off_115778 |= 0x80000000;
  v1[1] = 0;
  while ( (*v2 & 0x40000000) == 0 )
    ;
  v3 = off_11577C;
  if ( *((_BYTE *)off_11577C + 189) && **(__int16 **)off_115780 < 0 && *v1 != (*(_DWORD *)off_115794 & 0xF) )
    sub_12F46C(dword_1157B0, dword_1157AC, 968);
  v4 = off_115778;
  v5 = (_BYTE **)off_115784;
  *(_DWORD *)off_115778 &= ~0x40000000u;
  *v4 &= ~0x80000000;
  v6 = (unsigned __int8)**v5;
  if ( v6 == 3 )
  {
    *(_DWORD *)off_1157A8 &= ~1u;
  }
  else if ( v6 == 1 )
  {
    *(_DWORD *)off_1157A4 &= ~0x20u;
  }
  if ( *(_BYTE *)off_115788 )
    *(_DWORD *)off_11576C |= 0x2000000u;
  else
    *((_DWORD *)off_115768 + 14) &= ~0x10u;
  result = sub_12ECD0(2, dword_11578C);
  v8 = *(_BYTE **)off_115790;
  v9 = **(unsigned __int8 **)off_115790;
  if ( v9 == 2 )
  {
    if ( **v5 == 3 )
LABEL_22:
      *(_DWORD *)off_1157A8 &= ~1u;
  }
  else
  {
    if ( !v3[189] )
    {
      *(_DWORD *)off_115794 = (unsigned __int8)(16 * *v1);
      v9 = (unsigned __int8)*v8;
    }
    if ( v9 == 1 )
    {
      v10 = dword_115798;
      v11 = dword_11579C;
      v12 = off_1157A0;
      do
      {
        if ( *(_BYTE *)(v10 + 37) )
        {
          result = v12[4];
          **(_DWORD **)(v10 + 340) = result;
        }
        v10 += 696;
      }
      while ( v10 != v11 );
    }
    if ( **v5 == 3 && *v8 == 2 )
      goto LABEL_22;
  }
  return result;
}

