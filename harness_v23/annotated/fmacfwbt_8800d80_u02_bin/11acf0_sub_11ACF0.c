// v23 annotated: sub_11ACF0 @ 0x11acf0
// Original: 11acf0_sub_11ACF0.c
// Primary struct: <unclustered>
//
// sub_11ACF0 @ 0x11acf0, size 68 bytes
// Doc: sub_121ACF0 [bt]: FMAC+BT firmware routine at 0x121acf0
// sub_121ACF0 [bt]: FMAC+BT firmware routine at 0x121acf0
int __fastcall sub_11ACF0(int result, int a2)
{
  int v2; // r3
  int v3; // r2
  int v4; // r3
  unsigned int v5; // r3

  v2 = *(_DWORD *)(result + 60);
  if ( v2 < 0 )
  {
    v3 = *(_DWORD *)(result + 36);
    if ( **(__int16 **)off_11AD34 < 0 && (v4 = v2 << 15, v4 >= 0) )
    {
      return sub_12F630(dword_11AD3C, dword_11AD38, 3371, v4);
    }
    else
    {
      v5 = *(_DWORD *)(v3 + 20) & 0xFFFE3FFF | 0x4000;
      *(_DWORD *)(result + 60) = 0;
      *(_DWORD *)(v3 + 20) = v5;
      return bt_chan_dispatch_n_6f0(result, a2, v3, v5);
    }
  }
  return result;
}

