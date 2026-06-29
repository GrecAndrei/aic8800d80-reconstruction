// fwstruct annotate: 11c968_sub_11C968.c
// sub_11C968 @ 0x11c968, size 26 bytes
int __fastcall sub_11C968(int a1)
{
  _DWORD *v1; // r3
  int v2; // r1

  v1 = off_11C988;
  v2 = *((_DWORD *)off_11C984 + 4);
  *((_DWORD *)off_11C988 + 1) = dword_11C98C;
  v1[2] = a1;
  return timestamp_update_4f60(v1, v2 + 5000);
}

