// sub_1249FC @ 0x1249fc, size 192 bytes
int __fastcall sub_1249FC(unsigned __int8 *a1)
{
  int v1; // r1
  int v3; // r3
  unsigned int *v4; // r0
  int v5; // r1
  unsigned int *v6; // r0
  unsigned int v7; // r1
  unsigned int *v8; // r0
  int v9; // r2

  v1 = *a1;
  v3 = (unsigned __int8)*(_DWORD *)off_124ABC;
  if ( *a1 )
  {
    v4 = (unsigned int *)off_124AC0;
    *(_DWORD *)off_124AC0 = *(_DWORD *)off_124AC0 & 0xFFFFFF00 | v1;
    *v4 = *v4 & 0xFF0000FF | ((v3 * v1) << 8);
  }
  v5 = a1[1];
  if ( a1[1] )
  {
    v6 = (unsigned int *)off_124AC4;
    *(_DWORD *)off_124AC4 = *(_DWORD *)off_124AC4 & 0xFFFFFF00 | v5;
    *v6 = *v6 & 0xFF0000FF | ((v3 * v5) << 8);
  }
  v7 = a1[2];
  if ( a1[2] )
  {
    v8 = (unsigned int *)off_124AC8;
    *(_DWORD *)off_124AC8 = *(_DWORD *)off_124AC8 & 0xFFFFFF00 | v7;
    *v8 = *v8 & 0xFF0000FF | ((v3 * v7) << 8);
  }
  if ( a1[3] )
  {
    v7 = (unsigned int)off_124ACC;
    *(_DWORD *)off_124ACC = *(_DWORD *)off_124ACC & 0xFFFFFF00 | a1[3];
  }
  if ( a1[4] )
  {
    v7 = (unsigned int)off_124ACC;
    *(_DWORD *)off_124ACC = *(_DWORD *)off_124ACC & 0xFFFF00FF | (a1[4] << 8);
  }
  v9 = a1[5];
  if ( a1[5] )
  {
    v7 = (unsigned int)off_124ACC;
    *(_DWORD *)off_124ACC = *(_DWORD *)off_124ACC & 0xFF00FFFF | (v9 << 16);
  }
  sub_12E948(dword_124AD0, v7, v9);
  return sub_12E9D8(a1, 6, 1, 0);
}

