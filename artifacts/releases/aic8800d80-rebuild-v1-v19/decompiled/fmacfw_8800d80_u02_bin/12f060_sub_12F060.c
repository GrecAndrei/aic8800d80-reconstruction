// sub_12F060 @ 0x12f060, size 90 bytes
int sub_12F060()
{
  _BYTE *v0; // r5
  int v1; // r0
  int v2; // r4

  v0 = off_12F0BC;
  v1 = sub_12C73C(1070, 1);
  v2 = (char)v0[1];
  if ( v2 == 1 )
  {
    sub_130370();
    sub_12C5E4(1070, 1, dword_12F0C0);
    v0[1] = 2;
    return 0;
  }
  else
  {
    if ( v2 == 2 )
    {
      sub_1304B0(v1);
      sub_12C5E4(1070, 1, 1000 * *((_DWORD *)off_12F0C4 + 91));
      v0[1] = 1;
    }
    return 0;
  }
}

