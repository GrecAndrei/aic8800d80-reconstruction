// v23 annotated: sub_10D494 @ 0x10d494
// Original: 10d494_sub_10D494.c
// Primary struct: <unclustered>
//
// sub_10D494 @ 0x10d494, size 68 bytes
int sub_10D494()
{
  unsigned int *v0; // r2
  unsigned int v1; // r3
  int result; // r0
  _DWORD *v3; // r3

  v0 = (unsigned int *)off_10D4D8;
  v1 = *(_DWORD *)off_10D4D8;
  if ( (*(_DWORD *)off_10D4D8 & 1) == 0 )
  {
    v1 = v1 & 0xFFFFFCFE | 0x101;
    result = 17;
    *((_DWORD *)off_10D4D8 + 4) = 0;
    v0[5] = 0;
    v0[1] = 17;
    *v0 = v1;
  }
  if ( (v1 & 0x4000) == 0 )
    *(_DWORD *)off_10D4D8 = v1 | 0x4040;
  v3 = off_10D4E0;
  *(_DWORD *)(*((_DWORD *)off_10D4DC + 2) + 148) = dword_10D4E4;
  *v3 = 0x200000;
  return result;
}

