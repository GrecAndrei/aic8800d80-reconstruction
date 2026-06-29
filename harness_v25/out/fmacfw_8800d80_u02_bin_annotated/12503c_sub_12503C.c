// fwstruct annotate: 12503c_sub_12503C.c
// sub_12503C @ 0x12503c, size 152 bytes
// Doc: sub_122503E [unknown]: Helper routine saving r4-r6 and remapping args
// sub_122503E [unknown]: Helper routine saving r4-r6 and remapping args
int __fastcall sub_12503C(int a1, int a2)
{
  int v4; // r5

  switch ( a2 )
  {
    case 2:
      v4 = dword_1250D8;
      *(_DWORD *)(dword_1250DC + 20 * a1 + 4) = 0;
      break;
    case 3:
      v4 = dword_1250D8;
      rf_chan_info_copy_n_2d0(*(unsigned __int8 *)(dword_1250D8 + 1320 * a1 + 1225), dword_1250E8 + 38 * a1);
      break;
    case 1:
      v4 = dword_1250D8;
      *(_DWORD *)(dword_1250DC + 20 * a1 + 4) = dword_1250E0 + 20 * a1;
      break;
    default:
      v4 = dword_1250D8;
      if ( **(__int16 **)off_1250D4 < 0 )
        sub_12F46C(dword_1250F0, dword_1250EC, 1214);
      break;
  }
  *(_BYTE *)(a1 + dword_1250E4 + 20) = 0;
  return sub_12AC98(*(unsigned __int8 *)(v4 + 1320 * a1 + 1225), a2);
}

