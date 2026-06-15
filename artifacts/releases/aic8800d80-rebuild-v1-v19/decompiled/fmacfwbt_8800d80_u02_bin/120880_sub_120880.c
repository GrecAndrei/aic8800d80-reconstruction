// sub_120880 @ 0x120880, size 82 bytes
int sub_120880()
{
  _BYTE *v0; // r4
  int v1; // r3
  __int16 *v2; // r1
  int v3; // r1
  int result; // r0

  v0 = off_1208D4;
  memset_thunk((int *)off_1208D4, 0, 0x34u);
  v1 = dword_1208DC;
  v2 = *(__int16 **)off_1208D8;
  *(_DWORD *)v0 = dword_1208DC;
  v0[31] = 1;
  *((_WORD *)v0 + 9) = 0;
  v3 = *v2;
  *((_DWORD *)v0 + 1) = 0;
  if ( v3 < 0 && *(_DWORD *)off_1208E8 << 28 )
  {
    sub_12F6C4(dword_1208F0, dword_1208EC, 472);
    v1 = *(_DWORD *)v0 | *((_DWORD *)v0 + 1);
  }
  *(_DWORD *)off_1208E0 = v1;
  result = chip_version_read_12207E0();
  *((_DWORD *)v0 + 9) = dword_1208E4;
  return result;
}

