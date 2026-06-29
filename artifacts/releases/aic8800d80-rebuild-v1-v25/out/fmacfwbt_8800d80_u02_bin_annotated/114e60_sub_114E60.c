// fwstruct annotate: 114e60_sub_114E60.c
// sub_114E60 @ 0x114e60, size 12 bytes
int __fastcall sub_114E60(int a1, int a2)
{
  int v2; // r1
  int v3; // r4
  int v4; // r0
  int *v5; // r4
  int v6; // r5
  int *v7; // r2
  int *v8; // r3
  _BYTE *v9; // r2
  int v10; // r0
  _DWORD *v12; // r3

  if ( !*(_BYTE *)off_114E40 )
    return 3;
  v2 = dword_114E48;
  *(_DWORD *)off_114E44 = 0x20000;
  v3 = v2 + 120;
  while ( 1 )
  {
    v4 = *(unsigned __int8 *)(v2 + 16);
    if ( !*(_BYTE *)(v2 + 16) )
      break;
    v2 += 20;
    if ( v2 == v3 )
      return -1;
  }
  v5 = (int *)off_114E4C;
  *(_DWORD *)v2 = v4;
  v6 = *v5;
  *(_BYTE *)(v2 + 4) = v4;
  *(_DWORD *)(v2 + 8) = a2;
  *(_DWORD *)(v2 + 12) = a1;
  *(_BYTE *)(v2 + 16) = 1;
  if ( v6 )
  {
    v7 = (int *)off_114E50;
    v8 = *(int **)off_114E50;
    if ( *(_DWORD *)off_114E50 )
    {
      do
      {
        v7 = v8;
        v8 = (int *)*v8;
      }
      while ( v8 );
    }
    *v7 = v2;
  }
  else
  {
    v12 = off_114E5C;
    *v5 = v2;
    *v12 = 0x10000;
  }
  if ( *(_BYTE *)off_114E54 != 1 )
  {
    v9 = off_114E58;
    v10 = *(unsigned __int8 *)off_114E58;
    *(_BYTE *)off_114E54 = 1;
    if ( v10 != 1 )
      *v9 = 1;
  }
  return 0;
}

