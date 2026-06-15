// v23 annotated: sub_107C28 @ 0x107c28
// Original: 107c28_sub_107C28.c
// Primary struct: <unclustered>
//
// sub_107C28 @ 0x107c28, size 56 bytes
int sub_107C28()
{
  unsigned int *v0; // r5
  int v1; // r6
  unsigned __int16 v2; // r4
  int result; // r0
  _DWORD *v4; // r1

  v0 = (unsigned int *)off_107C64;
  v1 = *(_DWORD *)off_107C64;
  v2 = (unsigned __int16)*(_DWORD *)off_107C60 >> 4;
  result = sub_11F74C(1, dword_107C68, v2, off_107C60);
  v4 = off_107C6C;
  *v0 = (v2 + (_WORD)v1) & 0xFFF | *v0 & 0xFFFFF000;
  *v4 |= 0x400000u;
  return result;
}

