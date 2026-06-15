// sub_10D5D4 @ 0x10d5d4, size 68 bytes
int sub_10D5D4()
{
  unsigned int *v0; // r2
  unsigned int v1; // r3
  int result; // r0
  _DWORD *v3; // r3

  v0 = (unsigned int *)off_10D618;
  v1 = *(_DWORD *)off_10D618;
  if ( (*(_DWORD *)off_10D618 & 1) == 0 )
  {
    v1 = v1 & 0xFFFFFCFE | 0x101;
    result = 17;
    *((_DWORD *)off_10D618 + 4) = 0;
    v0[5] = 0;
    v0[1] = 17;
    *v0 = v1;
  }
  if ( (v1 & 0x4000) == 0 )
    *(_DWORD *)off_10D618 = v1 | 0x4040;
  v3 = off_10D620;
  *(_DWORD *)(*((_DWORD *)off_10D61C + 2) + 148) = dword_10D624;
  *v3 = 0x200000;
  return result;
}

