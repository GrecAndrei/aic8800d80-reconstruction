// sub_126F90 @ 0x126f90, size 62 bytes
unsigned int sub_126F90()
{
  int v0; // s15
  int v1; // r3

  v0 = (int)COERCE_FLOAT(sub_10DEF0());
  sub_11F504(dword_126FD0, v0);
  v1 = (char)v0 - *((char *)off_126FD4 + 3);
  if ( v1 < 0 )
    v1 = *((char *)off_126FD4 + 3) - (char)v0;
  if ( v1 > 4 )
  {
    *((uint8_t *)off_126FD4 + 3) = v0;
    sub_126F10((char)v0);
  }
  return sub_126DA4();
}

