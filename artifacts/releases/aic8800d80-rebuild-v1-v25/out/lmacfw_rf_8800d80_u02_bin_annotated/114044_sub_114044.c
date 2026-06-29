// fwstruct annotate: 114044_sub_114044.c
// sub_114044 @ 0x114044, size 110 bytes
int __fastcall sub_114044(int a1, int a2, int a3)
{
  int v5; // r1
  int v6; // r2
  unsigned int v7; // r6
  char v8; // r5
  unsigned int v9; // r0
  unsigned int v10; // r7
  int v11; // r0
  int v12; // r7
  unsigned __int8 v14; // r1
  _DWORD v15[3]; // [sp+4h] [bp-10h]

  v5 = *(_DWORD *)(dword_1140B4 + 4);
  v6 = *(_DWORD *)(dword_1140B4 + 8);
  v15[0] = *(_DWORD *)dword_1140B4;
  v15[1] = v5;
  v15[2] = v6;
  v7 = v15[a1];
  if ( a2 > 3 )
  {
    ++v7;
    LOBYTE(a2) = a2 - 4;
  }
  v8 = 8 * a2;
  v9 = (unsigned int)sub_113A44(v7) >> v8;
  v10 = (unsigned __int8)v9;
  v11 = v9 & 0xF;
  if ( v11 )
  {
    v12 = v10 >> 4;
    if ( v12 )
      return -1;
    LOBYTE(v11) = 4;
  }
  else
  {
    v12 = 1;
  }
  if ( a3 > 0 )
    v14 = 2 * a3;
  else
    v14 = (-2 * a3) | 1;
  host_reg_wait_set(v7, v14 << v11 << v8);
  return v12;
}

