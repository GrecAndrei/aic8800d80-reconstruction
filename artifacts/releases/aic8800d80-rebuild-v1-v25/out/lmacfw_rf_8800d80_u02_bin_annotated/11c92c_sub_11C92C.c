// fwstruct annotate: 11c92c_sub_11C92C.c
// sub_11C92C @ 0x11c92c, size 98 bytes
int sub_11C92C()
{
  int v0; // r5
  int v1; // r4
  int v2; // r0

  v0 = *(_DWORD *)off_11C990;
  v1 = *((unsigned __int8 *)off_11C990 + 10);
  if ( sub_11E34C(2) != 2 )
  {
    v2 = sub_11E34C(2);
    msg_parse(dword_11C994, v2);
  }
  if ( **(__int16 **)off_11C998 < 0 && sub_11E34C(2) != 2 )
    rf_cmd_send_n264(dword_11C9A0, dword_11C99C, 163);
  if ( (*(_BYTE *)(v0 + 6 * v1 + 3) & 1) == 0 )
    sub_11CBC8();
  sub_11E1E4(2);
  return 0;
}

