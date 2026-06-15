// v23 annotated: sub_1232B4 @ 0x1232b4
// Original: 1232b4_sub_1232B4.c
// Primary struct: <unclustered>
//
// sub_1232B4 @ 0x1232b4, size 196 bytes
int __fastcall sub_1232B4(int a1, int a2, int a3, int a4)
{
  unsigned int v4; // r4
  int v5; // r6
  int v6; // r7
  unsigned int v7; // r5
  unsigned int v9; // r0
  int v10; // r3
  int v12; // r3
  int v13; // [sp+0h] [bp-Ch]
  int v14; // [sp+0h] [bp-Ch]
  int v15; // [sp+0h] [bp-Ch]
  int v16; // [sp+4h] [bp-8h]
  int v17; // [sp+4h] [bp-8h]
  int v18; // [sp+4h] [bp-8h]

  v4 = *(unsigned __int8 *)(a2 + 5);
  v5 = *(unsigned __int8 *)(a2 + 6);
  v6 = dword_123378;
  v7 = *(_DWORD *)a2;
  *(_DWORD *)(dword_123378 + 4 * (v4 + 330 * v5 + 2)) = *(_DWORD *)a2;
  if ( v4 == 1 )
  {
    v12 = *(_DWORD *)(*(_DWORD *)off_12337C + 4);
    if ( v12 )
    {
      if ( (v12 & 0xFFF) != 0 )
        v7 = *(_DWORD *)(*(_DWORD *)off_12337C + 4);
      else
        v7 = v7 & 0xFFF | v12 & 0xFFFFF000;
    }
    v10 = *(unsigned __int8 *)(v6 + 1320 * v5 + 108);
    if ( *(_BYTE *)(v6 + 1320 * v5 + 108) )
    {
      *(_DWORD *)off_123384 = v7;
      v14 = a3;
      v17 = a4;
      chip_version_read_12207E0();
      a3 = v14;
      a4 = v17;
    }
  }
  else
  {
    v9 = *(_DWORD *)(*(_DWORD *)off_12337C + 4 * v4);
    v10 = *(unsigned __int8 *)(v6 + 1320 * v5 + 108);
    if ( !v9 )
      v9 = v7;
    if ( *(_BYTE *)(v6 + 1320 * v5 + 108) )
    {
      if ( v4 == 2 )
      {
        *(_DWORD *)off_12338C = v9;
        v15 = a3;
        v18 = a4;
        chip_version_read_12207E0();
        a3 = v15;
        a4 = v18;
      }
      else
      {
        if ( v4 > 2 )
          *(_DWORD *)off_123388 = v9;
        else
          *(_DWORD *)off_123380 = v9;
        v13 = a3;
        v16 = a4;
        chip_version_read_12207E0();
        a3 = v13;
        a4 = v16;
      }
    }
  }
  message_dispatch_n84(27, a4, a3, v10);
  return 0;
}

