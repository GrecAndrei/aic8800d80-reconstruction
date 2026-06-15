// sub_11C528 @ 0x11c528, size 26 bytes
int __fastcall sub_11C528(int a1)
{
  _DWORD *v1; // r3
  int v2; // r1

  v1 = off_11C548;
  v2 = *((_DWORD *)off_11C544 + 4);
  *((_DWORD *)off_11C548 + 1) = dword_11C54C;
  v1[2] = a1;
  return timestamp_update(v1, v2 + 5000);
}

