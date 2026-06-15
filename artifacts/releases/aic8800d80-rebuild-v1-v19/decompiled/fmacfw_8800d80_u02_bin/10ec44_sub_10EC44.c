// sub_10EC44 @ 0x10ec44, size 256 bytes
int sub_10EC44()
{
  unsigned int *v0; // r4
  _DWORD *v1; // r2
  int v2; // r0
  int v3; // r3
  _DWORD *v4; // r9
  _DWORD *v5; // r6
  _DWORD *v6; // r10
  int v7; // r5
  int *v8; // r2
  int v9; // r1
  unsigned int v10; // r8
  unsigned int v11; // r7
  unsigned int v12; // r6
  unsigned int v13; // r5
  int result; // r0
  _DWORD v15[2]; // [sp+4h] [bp-Ch] BYREF
  __int16 v16; // [sp+Ch] [bp-4h]

  v0 = (unsigned int *)off_10ED44;
  v1 = off_10ED48;
  v2 = dword_10ED4C;
  v3 = dword_10ED50;
  v4 = off_10ED64;
  v5 = off_10ED54;
  v6 = off_10ED68;
  v7 = dword_10ED58;
  v16 = 0;
  *((_DWORD *)off_10ED44 + 14) = 296;
  v1[3] = v2 | v1[3] & 0xE0000000;
  v1[2] = v3 & v1[2] | 0x1200000D;
  *v4 |= 0x20000000u;
  *v5 &= ~1u;
  v15[0] = v7;
  v15[1] = 2442;
  sub_102A20((unsigned __int16 *)v15, 0);
  v8 = (int *)off_10ED5C;
  v9 = dword_10ED60;
  v0 += 593954;
  *v6 |= 0x80000000;
  *v8 = v9;
  v10 = *v0;
  v11 = *v0;
  v12 = *v0;
  v13 = *v0;
  *v0 &= ~0x80000u;
  *v0 |= 0x100000u;
  *v0 |= 0x200000u;
  *v0 |= 0x400000u;
  result = rf_reg_field_modify_n12a(4);
  *v6 &= ~0x80000000;
  *v4 &= ~0x20000000u;
  *v0 = v10 & 0x80000 | *v0 & 0xFFF7FFFF;
  *v0 = v11 & 0x100000 | *v0 & 0xFFEFFFFF;
  *v0 = v12 & 0x200000 | *v0 & 0xFFDFFFFF;
  *v0 = v13 & 0x400000 | *v0 & 0xFFBFFFFF;
  return result;
}

