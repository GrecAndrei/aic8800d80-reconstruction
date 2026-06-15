// sub_124B3C @ 0x124b3c, size 192 bytes
// Doc: sub_1224B3C [util]: Helper reading a byte from a global and indexing input pointer
// sub_1224B3C [util]: Helper reading a byte from a global and indexing input pointer
int __fastcall sub_124B3C(unsigned __int8 *a1)
{
  int v1; // r1
  int v3; // r3
  unsigned int *v4; // r0
  int v5; // r1
  unsigned int *v6; // r0
  unsigned int v7; // r1
  unsigned int *v8; // r0
  int v9; // r2

  v1 = *a1;
  v3 = (unsigned __int8)*(_DWORD *)off_124BFC;
  if ( *a1 )
  {
    v4 = (unsigned int *)off_124C00;
    *(_DWORD *)off_124C00 = *(_DWORD *)off_124C00 & 0xFFFFFF00 | v1;
    *v4 = *v4 & 0xFF0000FF | ((v3 * v1) << 8);
  }
  v5 = a1[1];
  if ( a1[1] )
  {
    v6 = (unsigned int *)off_124C04;
    *(_DWORD *)off_124C04 = *(_DWORD *)off_124C04 & 0xFFFFFF00 | v5;
    *v6 = *v6 & 0xFF0000FF | ((v3 * v5) << 8);
  }
  v7 = a1[2];
  if ( a1[2] )
  {
    v8 = (unsigned int *)off_124C08;
    *(_DWORD *)off_124C08 = *(_DWORD *)off_124C08 & 0xFFFFFF00 | v7;
    *v8 = *v8 & 0xFF0000FF | ((v3 * v7) << 8);
  }
  if ( a1[3] )
  {
    v7 = (unsigned int)off_124C0C;
    *(_DWORD *)off_124C0C = *(_DWORD *)off_124C0C & 0xFFFFFF00 | a1[3];
  }
  if ( a1[4] )
  {
    v7 = (unsigned int)off_124C0C;
    *(_DWORD *)off_124C0C = *(_DWORD *)off_124C0C & 0xFFFF00FF | (a1[4] << 8);
  }
  v9 = a1[5];
  if ( a1[5] )
  {
    v7 = (unsigned int)off_124C0C;
    *(_DWORD *)off_124C0C = *(_DWORD *)off_124C0C & 0xFF00FFFF | (v9 << 16);
  }
  msg_parse(dword_124C10, v7, v9);
  return rf_mem_read_eb18(a1, 6, 1, 0);
}

