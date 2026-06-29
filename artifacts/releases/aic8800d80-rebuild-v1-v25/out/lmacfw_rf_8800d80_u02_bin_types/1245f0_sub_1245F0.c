// sub_1245F0 @ 0x1245f0, size 60 bytes
int sub_1245F0()
{
  uint16_t *v0; // r4
  int result; // r0
  int v2; // r3
  int v3; // r0

  if ( *(uint8_t *)off_12462C )
  {
    v0 = off_124630;
    result = sub_1242F0(0x80u);
    v2 = (unsigned __int16)(*v0 + 1);
    *v0 = v2;
    if ( v2 == 10 )
    {
      sub_12646C(1);
      v3 = *(uint32_t *)off_124634 + 39936;
      *v0 = 0;
      return sub_1264DC(v3 + 64);
    }
  }
  return result;
}

