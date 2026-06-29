// fwstruct annotate: 1198ac_sub_1198AC.c
// sub_1198AC @ 0x1198ac, size 198 bytes
int __fastcall sub_1198AC(int a1, int a2, int a3, int a4)
{
  int v4; // r0
  unsigned int v5; // r4
  int v6; // r7
  unsigned int v7; // r12
  int v8; // r1
  unsigned int v9; // r3
  int v11; // r4
  int v12; // [sp+0h] [bp-Ch]
  int v13; // [sp+0h] [bp-Ch]
  int v14; // [sp+0h] [bp-Ch]
  int v15; // [sp+4h] [bp-8h]
  int v17; // [sp+4h] [bp-8h]

  v4 = *(unsigned __int8 *)(a2 + 6);
  v5 = *(unsigned __int8 *)(a2 + 5);
  v6 = dword_119974;
  v7 = *(_DWORD *)a2;
  *(_DWORD *)(dword_119974 + 4 * (v5 + 56 * v4 + 2)) = *(_DWORD *)a2;
  v8 = a4;
  if ( v5 == 1 )
  {
    v11 = *(_DWORD *)(*(_DWORD *)off_119978 + 4);
    if ( v11 )
    {
      if ( (v11 & 0xFFF) != 0 )
        v7 = *(_DWORD *)(*(_DWORD *)off_119978 + 4);
      else
        v7 = v11 & 0xFFFFF000 | v7 & 0xFFF;
    }
    if ( *(_BYTE *)(v6 + 224 * v4 + 96) )
    {
      *(_DWORD *)off_119980 = v7;
      v13 = a3;
      sub_1183A0();
      a3 = v13;
      v8 = a4;
    }
  }
  else
  {
    v9 = *(_DWORD *)(*(_DWORD *)off_119978 + 4 * v5);
    if ( !v9 )
      v9 = v7;
    if ( *(_BYTE *)(v6 + 224 * v4 + 96) )
    {
      if ( v5 == 2 )
      {
        *(_DWORD *)off_119988 = v9;
        v14 = a3;
        v17 = v8;
        sub_1183A0();
        a3 = v14;
        v8 = v17;
      }
      else
      {
        if ( v5 > 2 )
          *(_DWORD *)off_119984 = v9;
        else
          *(_DWORD *)off_11997C = v9;
        v12 = a3;
        v15 = v8;
        sub_1183A0();
        a3 = v12;
        v8 = v15;
      }
    }
  }
  sub_11DED8(27, v8, a3);
  return 0;
}

