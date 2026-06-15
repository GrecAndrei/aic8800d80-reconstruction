// v23 annotated: sub_113FD8 @ 0x113fd8
// Original: 113fd8_sub_113FD8.c
// Primary struct: <unclustered>
//
// sub_113FD8 @ 0x113fd8, size 102 bytes
int __fastcall sub_113FD8(int a1, int a2, _BYTE *a3)
{
  int v5; // r1
  int v6; // r2
  unsigned int v7; // r0
  unsigned int v8; // r4
  unsigned int v9; // r3
  int result; // r0
  char v11; // r2
  _DWORD v12[3]; // [sp+4h] [bp-Ch]

  v5 = *(_DWORD *)(dword_114040 + 4);
  v6 = *(_DWORD *)(dword_114040 + 8);
  v12[0] = *(_DWORD *)dword_114040;
  v12[1] = v5;
  v12[2] = v6;
  v7 = v12[a1];
  if ( a2 > 3 )
  {
    ++v7;
    LOBYTE(a2) = a2 - 4;
  }
  v8 = (unsigned int)sub_113A44(v7) >> (8 * a2);
  v9 = (unsigned __int8)v8 >> 4;
  if ( (v8 & 0xF0) != 0 )
  {
    result = 0;
  }
  else
  {
    if ( !(_BYTE)v8 )
    {
      *a3 = 0;
      return 2;
    }
    v9 = (unsigned __int8)v8;
    result = 1;
  }
  if ( (v9 & 1) != 0 )
    v11 = -1;
  else
    v11 = 1;
  *a3 = (v9 >> 1) * v11;
  return result;
}

