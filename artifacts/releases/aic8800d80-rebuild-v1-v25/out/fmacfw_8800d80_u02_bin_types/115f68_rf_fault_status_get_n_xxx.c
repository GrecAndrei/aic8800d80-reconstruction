// rf_fault_status_get_n_xxx @ 0x115f68, size 132 bytes
// Doc: rf_fault_status_get_n_xxx [rf]: Reads RF fault status flag and dispatches accordingly
// rf_fault_status_get_n_xxx [rf]: Reads RF fault status flag and dispatches accordingly
int rf_fault_status_get_n_xxx()
{
  int **v0; // r5
  uint32_t *v1; // r6
  int *v2; // r0
  void *v3; // r8
  int v4; // r7
  unsigned __int16 v5; // r9
  int result; // r0

  v0 = (int **)off_115FF0;
  sub_12D240(dword_115FEC);
  if ( **(__int16 **)off_115FF4 < 0 )
  {
    v2 = *v0;
    v1 = off_115FF8;
    if ( !*v0 || !*(uint32_t *)off_115FF8 )
    {
      sub_12F46C(dword_115FFC, dword_116000, 90);
      v2 = *v0;
    }
  }
  else
  {
    v1 = off_115FF8;
    v2 = *v0;
  }
  v3 = off_116004;
  v4 = dword_115FEC;
  memset_thunk(v2, 0, 88 * *(unsigned __int16 *)(*(uint32_t *)off_116004 + 8) + 88);
  v5 = 0;
  do
  {
    (*v0)[22 * v5 + 19] = *v1 + 80 * v5;
    result = list_push_tail(v4);
    ++v5;
  }
  while ( *(unsigned __int16 *)(*(uint32_t *)v3 + 8) >= (unsigned int)v5 );
  return result;
}

