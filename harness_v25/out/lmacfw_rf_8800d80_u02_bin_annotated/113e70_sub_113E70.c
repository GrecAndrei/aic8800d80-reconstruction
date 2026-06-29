// fwstruct annotate: 113e70_sub_113E70.c
// sub_113E70 @ 0x113e70, size 92 bytes
int __fastcall sub_113E70(int a1, char a2, _BYTE *a3)
{
  int v5; // r1
  int v6; // r2
  unsigned int v7; // r0
  unsigned int v8; // r3
  int result; // r0
  char v10; // r2
  _DWORD v11[3]; // [sp+4h] [bp-Ch]

  v5 = *(_DWORD *)(dword_113ECC + 4);
  v6 = *(_DWORD *)(dword_113ECC + 8);
  v11[0] = *(_DWORD *)dword_113ECC;
  v11[1] = v5;
  v11[2] = v6;
  v7 = (unsigned int)sub_113A44(v11[a1]) >> (8 * a2);
  v8 = (unsigned __int8)v7 >> 4;
  if ( (v7 & 0xF0) != 0 )
  {
    result = 0;
  }
  else
  {
    if ( !(_BYTE)v7 )
    {
      *a3 = 0;
      return 2;
    }
    v8 = (unsigned __int8)v7;
    result = 1;
  }
  if ( (v8 & 1) != 0 )
    v10 = -1;
  else
    v10 = 1;
  *a3 = (v8 >> 1) * v10;
  return result;
}

