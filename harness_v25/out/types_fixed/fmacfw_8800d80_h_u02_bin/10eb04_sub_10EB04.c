// sub_10EB04 @ 0x10eb04, size 256 bytes
int sub_10EB04()
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
  _DWORD *(_DWORD *)(v15 + 0x8); // [sp+4h] [bp-Ch] BYREF
  __int16 v16; // [sp+Ch] [bp-4h]

  v0 = (unsigned int *)off_10EC04;
  v1 = off_10EC08;
  v2 = dword_10EC0C;
  v3 = dword_10EC10;
  v4 = off_10EC24;
  v5 = off_10EC14;
  v6 = off_10EC28;
  v7 = dword_10EC18;
  v16 = 0;
  *((_DWORD *)off_10EC04 + 14) = 296;
  *(_DWORD *)(v1 + 0xc) = v2 | *(_DWORD *)(v1 + 0xc) & 0xE0000000;
  *(_DWORD *)(v1 + 0x8) = v3 & *(_DWORD *)(v1 + 0x8) | 0x1200000D;
  *v4 |= 0x20000000u;
  *v5 &= ~1u;
  *(_DWORD *)(v15 + 0x0) = v7;
  *(_DWORD *)(v15 + 0x4) = 2442;
  sub_102970((unsigned __int16 *)v15, 0);
  v8 = (int *)off_10EC1C;
  v9 = dword_10EC20;
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
  result = sub_10E8B4(4);
  *v6 &= ~0x80000000;
  *v4 &= ~0x20000000u;
  *v0 = v10 & 0x80000 | *v0 & 0xFFF7FFFF;
  *v0 = v11 & 0x100000 | *v0 & 0xFFEFFFFF;
  *v0 = v12 & 0x200000 | *v0 & 0xFFDFFFFF;
  *v0 = v13 & 0x400000 | *v0 & 0xFFBFFFFF;
  return result;
}
