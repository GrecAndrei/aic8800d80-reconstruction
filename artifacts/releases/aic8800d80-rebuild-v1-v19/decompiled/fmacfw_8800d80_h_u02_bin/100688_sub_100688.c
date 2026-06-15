// sub_100688 @ 0x100688, size 50 bytes
int sub_100688()
{
  int *v0; // r4
  int v1; // r5
  int result; // r0
  __int16 v3; // r2

  v0 = (int *)off_1006C0;
  v1 = sub_1005B0(HIBYTE(*(_DWORD *)off_1006BC) & 3);
  sub_100200(v0, 0, 8u);
  result = dword_1006C4 + 16 * v1;
  v3 = *(_WORD *)(result + 6);
  *(_DWORD *)off_1006C8 = *(unsigned __int16 *)(result + 4);
  *((_BYTE *)v0 + 1) = v3;
  *(_BYTE *)v0 = -1;
  return result;
}

