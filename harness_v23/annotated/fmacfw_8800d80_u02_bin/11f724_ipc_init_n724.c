// v23 annotated: ipc_init_n724 @ 0x11f724
// Original: 11f724_ipc_init_n724.c
// Primary struct: <unclustered>
//
// ipc_init_n724 @ 0x11f724, size 98 bytes
// Doc: ipc_init_n724 [ipc]: Initializes IPC at 0x18e610 with zero and calls setup helper
// ipc_init_n724 [ipc]: Initializes IPC at 0x18e610 with zero and calls setup helper
int ipc_init_n724()
{
  _BYTE *v0; // r8
  int v1; // r4
  int v2; // r7
  int v3; // r6
  int result; // r0

  v0 = off_11F788;
  memset_thunk((int *)off_11F788, 0, 0x18u);
  sub_12D240(v0);
  v1 = dword_11F78C;
  v2 = dword_11F790;
  sub_12D240(v0 + 8);
  v3 = v1 + 5280;
  do
  {
    memset_thunk((int *)v1, 0, 0x528u);
    *(_DWORD *)(v1 + 52) = v2;
    *(_DWORD *)(v1 + 56) = v1;
    *(_BYTE *)(v1 + 106) = 5;
    *(_BYTE *)(v1 + 109) = 127;
    *(_BYTE *)(v1 + 110) = 127;
    v1 += 1320;
    result = list_push_tail(v0);
  }
  while ( v1 != v3 );
  v0[16] = -1;
  return result;
}

