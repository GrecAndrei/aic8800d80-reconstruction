// mac_state_branch_handler @ 0x10c8f8, size 114 bytes
// Doc: mac_state_branch_handler [mac]: Handles MAC sub-state branch based on register field == 2
// mac_state_branch_handler [mac]: Handles MAC sub-state branch based on register field == 2
int *mac_state_branch_handler()
{
  int v0; // r4
  bool v1; // zf
  unsigned __int8 v2; // r1
  int **v3; // r4

  v0 = *((_DWORD *)off_10C96C + 23);
  memset_thunk((int *)dword_10C970, 0, 0x28u);
  memset_thunk((int *)dword_10C974, 0, 0x1E6Cu);
  if ( (*(_DWORD *)off_10C978 & 8) != 0 )
  {
    while ( (*(_DWORD *)off_10C978 & 0x10) == 0 )
      ;
    v3 = (int **)off_10C97C;
  }
  else
  {
    v2 = v0 & 3;
    v1 = (v0 & 3) == 0;
    v3 = (int **)off_10C97C;
    *(_DWORD *)off_10C978 |= 8u;
    if ( v1 )
      memset_thunk(*v3, v2, 0x288u);
    *(_DWORD *)off_10C978 |= 0x10u;
  }
  (*v3)[161] = *(_DWORD *)off_10C980;
  return sub_10C840();
}

