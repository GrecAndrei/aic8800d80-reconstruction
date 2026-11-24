// rf_stream_start_once @ 0x113640, size 64 bytes
// Doc: rf_stream_start_once [rf]: Initialize and start an RF data stream via callback
// rf_stream_start_once [rf]: Initialize and start an RF data stream via callback
int rf_stream_start_once()
{
  int v0; // r0
  _DWORD *v1; // r4
  int result; // r0

  v0 = (*(int (__fastcall **)(_DWORD))(*((_DWORD *)off_113680 + 2) + 16))(*((_DWORD *)off_113680 + 1));
  if ( !v0 )
    return sub_10DA6C(dword_11368C);
  v1 = (_DWORD *)v0;
  result = rf_stream_start_2c20(*(_DWORD *)off_113684 + v0, *(_DWORD *)off_113688);
  if ( result < 0 )
  {
    sub_10FEF8(v1);
    return sub_10DA6C(dword_113690);
  }
  return result;
}

