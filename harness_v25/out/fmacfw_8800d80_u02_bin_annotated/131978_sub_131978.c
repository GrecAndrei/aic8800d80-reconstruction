// fwstruct annotate: 131978_sub_131978.c
// sub_131978 @ 0x131978, size 70 bytes
// Doc: me_chan_ctxt_update [mac]: Update MAC engine channel context fields
// me_chan_ctxt_update [mac]: Update MAC engine channel context fields
int __fastcall sub_131978(int a1, int a2, unsigned int a3)
{
  int v4; // r1

  if ( **(__int16 **)off_1319C0 < 0 && msg_get_value(a3) != 1 )
    sub_12F46C(dword_1319CC, dword_1319C8, 670);
  v4 = *((unsigned __int16 *)off_1319C4 + 4);
  if ( v4 != 255 )
    sub_12CA10(5144, v4, a3);
  sub_12CD34(a3, 0);
  return 0;
}

