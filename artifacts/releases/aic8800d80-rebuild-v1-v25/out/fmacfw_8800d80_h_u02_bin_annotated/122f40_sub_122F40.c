// fwstruct annotate: 122f40_sub_122F40.c
// sub_122F40 @ 0x122f40, size 196 bytes
int __fastcall sub_122F40(int a1, int a2, int a3, int a4)
{
  unsigned int v4; // r4
  int v5; // r6
  int v6; // r7
  unsigned int v7; // r5
  int v8; // r1
  unsigned int v9; // r0
  int v11; // r3
  int v12; // [sp+0h] [bp-Ch]
  int v13; // [sp+0h] [bp-Ch]
  int v14; // [sp+0h] [bp-Ch]
  int v16; // [sp+4h] [bp-8h]

  v4 = *(unsigned __int8 *)(a2 + 5);
  v5 = *(unsigned __int8 *)(a2 + 6);
  v6 = dword_123004;
  v7 = *(_DWORD *)a2;
  *(_DWORD *)(dword_123004 + 4 * (v4 + 330 * v5 + 2)) = *(_DWORD *)a2;
  v8 = a4;
  if ( v4 == 1 )
  {
    v11 = *(_DWORD *)(*(_DWORD *)off_123008 + 4);
    if ( v11 )
    {
      if ( (v11 & 0xFFF) != 0 )
        v7 = *(_DWORD *)(*(_DWORD *)off_123008 + 4);
      else
        v7 = v7 & 0xFFF | v11 & 0xFFFFF000;
    }
    if ( *(_BYTE *)(v6 + 1320 * v5 + 108) )
    {
      *(_DWORD *)off_123010 = v7;
      v13 = a3;
      v16 = v8;
      sub_120368();
      a3 = v13;
      v8 = v16;
    }
  }
  else
  {
    v9 = *(_DWORD *)(*(_DWORD *)off_123008 + 4 * v4);
    if ( !v9 )
      v9 = v7;
    if ( *(_BYTE *)(v6 + 1320 * v5 + 108) )
    {
      if ( v4 == 2 )
      {
        *(_DWORD *)off_123018 = v9;
        v14 = a3;
        sub_120368();
        a3 = v14;
        v8 = a4;
      }
      else
      {
        if ( v4 > 2 )
          *(_DWORD *)off_123014 = v9;
        else
          *(_DWORD *)off_12300C = v9;
        v12 = a3;
        sub_120368();
        a3 = v12;
        v8 = a4;
      }
    }
  }
  sub_12C8D0(27, v8, a3);
  return 0;
}

