// sub_11DA78 @ 0x11da78, size 64 bytes
int __fastcall sub_11DA78(int result, int a2)
{
  int v2; // r4
  int v3; // r0

  if ( *((_BYTE *)off_11DAB8 + 197) )
  {
    v2 = *(_DWORD *)(*(_DWORD *)(a2 + 32) + 44);
    v3 = sub_101C70((*(_DWORD *)(v2 + 20) >> 11) & 7, *(_DWORD *)(v2 + 20) & 0x7F, *(_DWORD *)(result + 72) + 4);
    result = v3 | (v3 << 8);
    *(_DWORD *)(v2 + 36) = result;
  }
  else if ( **(__int16 **)off_11DABC < 0 )
  {
    return rf_cmd_send_n264(dword_11DAC4, dword_11DAC0, 92);
  }
  return result;
}

