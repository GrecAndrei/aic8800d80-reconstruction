// v23 annotated: sub_10F50C @ 0x10f50c
// Original: 10f50c_sub_10F50C.c
// Primary struct: log_state (cluster 19, 4 funcs)
// Fields: enable=0x0, state=0x0, level=0x4, flag=0x7, count=0x8, tick=0xa, buf=0x14, status=0x16a
//
// sub_10F50C @ 0x10f50c, size 52 bytes
int sub_10F50C()
{
  _BYTE *v0; // r3
  int result; // r0
  void *v2; // r1
  int v3; // r2

  if ( *((_BYTE *)off_10F540 + 362) )
  {
    *(_BYTE *)off_10F544 = 0;
  }
  else
  {
    v0 = off_10F544;
    *(_DWORD *)off_10F544 = dword_10F548;
    v2 = off_10F54C;
    v3 = dword_10F550;
    v0[7] = -62;
    *((_DWORD *)v0 + 2) = 1000;
    *((_WORD *)v0 + 2) = 1752;
    *((_DWORD *)v0 + 4) = v2;
    *((_DWORD *)v0 + 8) = v3;
    return 1752;
  }
  return result;
}

