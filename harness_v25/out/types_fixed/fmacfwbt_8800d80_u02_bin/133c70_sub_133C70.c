// sub_133C70 @ 0x133c70, size 90 bytes
int sub_133C70()
{
  int v0; // r2
  int v2; // [sp+0h] [bp-Ch] BYREF
  int v3; // [sp+4h] [bp-8h] BYREF

  v0 = **(__int16 **)off_133CCC;
  v2 = 0;
  v3 = 0;
  if ( v0 < 0 && sub_12D0B0(6u) != 1 )
    sub_12F694(dword_133CD4, dword_133CD0, 303);
  sub_134690(&v2, &v3);
  if ( v2 && v3 )
  {
    sub_1347DC();
    return 0;
  }
  else
  {
    sub_135020(1);
    return 0;
  }
}

