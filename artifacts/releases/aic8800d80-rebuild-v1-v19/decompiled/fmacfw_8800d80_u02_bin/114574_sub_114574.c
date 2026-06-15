// sub_114574 @ 0x114574, size 40 bytes
int __fastcall sub_114574(int a1, int a2, int a3)
{
  int result; // r0
  _BYTE *v4; // r3
  _DWORD *v5; // r1

  result = sub_12EA88(dword_11459C, a2, a3);
  v4 = off_1145A0;
  if ( *((_BYTE *)off_1145A0 + 3) )
  {
    v5 = off_1145A8;
    *(_DWORD *)off_1145A4 &= ~8u;
    *v5 &= 0xFFFFFFF0;
    v4[3] = 0;
    return 0;
  }
  return result;
}

