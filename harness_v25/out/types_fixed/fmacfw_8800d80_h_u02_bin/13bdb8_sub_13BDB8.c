// sub_13BDB8 @ 0x13bdb8, size 104 bytes
int __fastcall sub_13BDB8(unsigned int a1)
{
  int v1; // r5
  int v2; // r6
  int v3; // r7
  int v5; // r8
  int v6; // r0
  int v7; // r4

  v1 = dword_13BE20;
  v2 = dword_13BE20 + 32 * a1;
  v3 = *(unsigned __int8 *)(v2 + 16);
  v5 = 32 * a1;
  if ( a1 <= 0xF )
  {
    sub_12D1A8(dword_13BE30, (_DWORD *)v2);
    sub_12D108(dword_13BE34, (_DWORD *)v2);
  }
  else
  {
    sub_12D1A8(dword_13BE24, (_DWORD *)v2);
    sub_12D108(dword_13BE28, (_DWORD *)v2);
  }
  v6 = (a1 << 8) & 0xFF00;
  v7 = dword_13BE2C;
  sub_12CBF4(v6 | 8, 4);
  *(_BYTE *)(v1 + v5 + 25) = 0;
  return sub_13B558(v3, v2, 2, 0, 0, 39, v7);
}

