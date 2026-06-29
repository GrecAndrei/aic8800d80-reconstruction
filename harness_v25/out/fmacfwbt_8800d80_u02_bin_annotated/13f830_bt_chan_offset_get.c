// fwstruct annotate: 13f830_bt_chan_offset_get.c
// bt_chan_offset_get @ 0x13f830, size 142 bytes
// Doc: bt_chan_offset_get [bt]: Compute Bluetooth channel offset via 0x2b8 stride lookup
// bt_chan_offset_get [bt]: Compute Bluetooth channel offset via 0x2b8 stride lookup
int __fastcall bt_chan_offset_get(int a1)
{
  int v1; // r4
  int v2; // r3
  int result; // r0
  char v4; // r3

  v1 = *(_DWORD *)(dword_13F8C4 + 696 * a1 + 340);
  if ( **(__int16 **)off_13F8C0 < 0 && !v1 )
    sub_12F694(dword_13F8CC, dword_13F8C8, 2194);
  sub_13E3C4(v1);
  v2 = *(unsigned __int16 *)(v1 + 184);
  *(_WORD *)(v1 + 136) = (v2 - 1) & ~(unsigned __int16)((v2 - 1) >> 31);
  *(_WORD *)(v1 + 138) = (v2 - 2) & ~(unsigned __int16)((v2 - 2) >> 31);
  *(_WORD *)(v1 + 140) = (v2 - 3) & ~(unsigned __int16)((v2 - 3) >> 31);
  *(_DWORD *)(v1 + 148) = 0x10000;
  *(_WORD *)(v1 + 190) = -1;
  *(_WORD *)(v1 + 142) = 0;
  *(_BYTE *)(v1 + 166) = 0;
  result = sub_13F66C(v1, 1);
  v4 = *(_BYTE *)(v1 + 184);
  *(_BYTE *)(v1 + 154) = 0;
  *(_BYTE *)(v1 + 164) = v4 - 4;
  *(_WORD *)(v1 + 152) = 5;
  return result;
}

