// sub_133914 @ 0x133914, size 90 bytes
int sub_133914()
{
  int v0; // r2
  int v2; // [sp+0h] [bp-Ch] BYREF
  int v3; // [sp+4h] [bp-8h] BYREF

  v0 = **(__int16 **)off_133970;
  v2 = 0;
  v3 = 0;
  if ( v0 < 0 && sub_12CD48(6u) != 1 )
    sub_12F32C(dword_133978, dword_133974, 303);
  sub_134334(&v2, &v3);
  if ( v2 && v3 )
  {
    sub_134480();
    return 0;
  }
  else
  {
    sub_134CC4(1);
    return 0;
  }
}

