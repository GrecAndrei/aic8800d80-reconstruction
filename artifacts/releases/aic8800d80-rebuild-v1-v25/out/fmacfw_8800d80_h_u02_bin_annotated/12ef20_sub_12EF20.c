// fwstruct annotate: 12ef20_sub_12EF20.c
// sub_12EF20 @ 0x12ef20, size 90 bytes
int sub_12EF20()
{
  _BYTE *v0; // r5
  int v1; // r0
  int v2; // r4

  v0 = off_12EF7C;
  v1 = sub_12C5FC(1070, 1);
  v2 = (char)v0[1];
  if ( v2 == 1 )
  {
    sub_130230();
    sub_12C4A4(1070, 1, dword_12EF80);
    v0[1] = 2;
    return 0;
  }
  else
  {
    if ( v2 == 2 )
    {
      sub_130370(v1);
      sub_12C4A4(1070, 1, 1000 * *((_DWORD *)off_12EF84 + 91));
      v0[1] = 1;
    }
    return 0;
  }
}

