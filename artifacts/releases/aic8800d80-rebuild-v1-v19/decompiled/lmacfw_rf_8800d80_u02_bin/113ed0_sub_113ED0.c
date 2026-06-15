// sub_113ED0 @ 0x113ed0, size 104 bytes
int __fastcall sub_113ED0(int a1, char a2, int a3)
{
  int v5; // r1
  int v6; // r2
  unsigned int v7; // r5
  unsigned int v8; // r0
  char v9; // r1
  unsigned int v10; // r0
  unsigned int v11; // r6
  int v12; // r0
  int v13; // r6
  unsigned __int8 v15; // r4
  _DWORD v16[3]; // [sp+4h] [bp-Ch]

  v5 = *(_DWORD *)(dword_113F38 + 4);
  v6 = *(_DWORD *)(dword_113F38 + 8);
  v16[0] = *(_DWORD *)dword_113F38;
  v16[1] = v5;
  v16[2] = v6;
  v7 = v16[a1];
  v8 = sub_113A44(v7);
  v9 = 8 * a2;
  v10 = v8 >> (8 * a2);
  v11 = (unsigned __int8)v10;
  v12 = v10 & 0xF;
  if ( v12 )
  {
    v13 = v11 >> 4;
    if ( v13 )
      return -1;
    LOBYTE(v12) = 4;
  }
  else
  {
    v13 = 1;
  }
  if ( a3 > 0 )
    v15 = 2 * a3;
  else
    v15 = (-2 * a3) | 1;
  host_reg_wait_set(v7, v15 << v12 << v9);
  return v13;
}

