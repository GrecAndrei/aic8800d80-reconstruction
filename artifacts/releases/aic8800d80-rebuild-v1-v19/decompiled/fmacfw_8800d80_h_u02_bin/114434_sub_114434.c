// sub_114434 @ 0x114434, size 40 bytes
int __fastcall sub_114434(int a1, int a2, int a3)
{
  int result; // r0
  _BYTE *v4; // r3
  _DWORD *v5; // r1

  result = sub_12E948(dword_11445C, a2, a3);
  v4 = off_114460;
  if ( *((_BYTE *)off_114460 + 3) )
  {
    v5 = off_114468;
    *(_DWORD *)off_114464 &= ~8u;
    *v5 &= 0xFFFFFFF0;
    v4[3] = 0;
    return 0;
  }
  return result;
}

