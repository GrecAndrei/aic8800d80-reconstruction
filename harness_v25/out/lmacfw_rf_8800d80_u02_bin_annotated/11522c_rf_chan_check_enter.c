// fwstruct annotate: 11522c_rf_chan_check_enter.c
// rf_chan_check_enter @ 0x11522c, size 132 bytes
// Doc: rf_chan_check_enter [rf]: Checks RF channel/state flag and enters RF path
// rf_chan_check_enter [rf]: Checks RF channel/state flag and enters RF path
int rf_chan_check_enter()
{
  int **v0; // r5
  _DWORD *v1; // r6
  int *v2; // r0
  void *v3; // r9
  int v4; // r8
  unsigned __int16 v5; // r10
  int result; // r0

  v0 = (int **)off_1152B4;
  sub_11E71C(dword_1152B0);
  if ( **(__int16 **)off_1152B8 < 0 )
  {
    v2 = *v0;
    v1 = off_1152BC;
    if ( !*v0 || !*(_DWORD *)off_1152BC )
    {
      rf_cmd_send_n264(dword_1152C0, dword_1152C4, 90);
      v2 = *v0;
    }
  }
  else
  {
    v1 = off_1152BC;
    v2 = *v0;
  }
  v3 = off_1152C8;
  v4 = dword_1152B0;
  sub_100200(v2, 0, 44 * *(unsigned __int16 *)(*(_DWORD *)off_1152C8 + 8) + 44);
  v5 = 0;
  do
  {
    (*v0)[11 * v5 + 8] = *v1 + 76 * v5;
    result = list_push_tail(v4);
    ++v5;
  }
  while ( *(unsigned __int16 *)(*(_DWORD *)v3 + 8) >= (unsigned int)v5 );
  return result;
}

