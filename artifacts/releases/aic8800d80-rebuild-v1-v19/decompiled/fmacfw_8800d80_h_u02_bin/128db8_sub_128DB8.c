// sub_128DB8 @ 0x128db8, size 28 bytes
int sub_128DB8()
{
  _DWORD *v0; // r4
  int *v1; // r0
  int result; // r0

  v0 = off_128DD4;
  v1 = sub_100200((int *)off_128DD4, 0, 0x28u);
  result = sub_141F60(v1);
  v0[4] = off_128DD8;
  *((_BYTE *)v0 + 28) = 1;
  return result;
}

