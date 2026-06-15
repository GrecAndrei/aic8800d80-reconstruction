// sub_124178 @ 0x124178, size 26 bytes
int __fastcall sub_124178(int a1)
{
  unsigned int v1; // r1
  int v2; // r0

  v1 = *(_DWORD *)off_124194 & 0xFFFBFFFF | (a1 << 18);
  v2 = dword_124198;
  *(_DWORD *)off_124194 = v1;
  sub_11F504(v2);
  return 0;
}

