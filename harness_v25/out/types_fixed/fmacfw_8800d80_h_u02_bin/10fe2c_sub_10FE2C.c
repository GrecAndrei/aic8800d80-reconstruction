// sub_10FE2C @ 0x10fe2c, size 66 bytes
int __fastcall sub_10FE2C(int a1, int a2, int a3)
{
  _DWORD *v3; // r3
  _DWORD *v4; // r3

  v3 = off_10FE70;
  *((_DWORD *)off_10FE70 + 3) = dword_10FE74;
  *v3 = a2;
  *(_DWORD *)(v3 + 0x4) = a3;
  *((_BYTE *)v3 + 8) = 4;
  sub_10F7E4(v3, a1, 0x20u);
  v4 = off_10FE78;
  *((_DWORD *)off_10FE78 + 5) = 4;
  *(_DWORD *)(v4 + 0x4) = 0x10000;
  *(_DWORD *)(v4 + 0xc) = 131074;
  *(_DWORD *)(v4 + 0x18) = 0x40000;
  *v4 = 1;
  *(_DWORD *)(v4 + 0x8) = 1;
  *(_DWORD *)(v4 + 0x10) = 0;
  *((_WORD *)v4 + 14) = 0;
  return 0x40000;
}

