// fwstruct annotate: 122744_sub_122744.c
// sub_122744 @ 0x122744, size 76 bytes
char *sub_122744()
{
  int v0; // r4

  v0 = *(_DWORD *)off_122794 & 0x1800000;
  if ( **(__int16 **)off_122790 < 0 && v0 == 25165824 )
    sub_12F32C(dword_1227A4, dword_1227A0, 1308);
  sub_12D00C(v0);
  if ( *((_BYTE *)off_122798 + 18) )
    return (char *)sub_120FB8();
  else
    return sub_122654(*((char **)off_12279C + 8));
}

