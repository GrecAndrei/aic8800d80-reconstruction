// fwstruct annotate: 1286f4_bt_state_get_n28.c
// bt_state_get_n28 @ 0x1286f4, size 74 bytes
// Doc: bt_state_get_n28 [bt]: Read BT state field at offset 0x28 from global control block
// bt_state_get_n28 [bt]: Read BT state field at offset 0x28 from global control block
BOOL __fastcall bt_state_get_n28(int a1)
{
  int v1; // r3
  unsigned int v2; // r1

  v1 = *((_DWORD *)off_128740 + 10);
  if ( !v1 )
    return 0;
  v2 = *(unsigned __int8 *)(v1 + 24);
  if ( v2 <= 2 )
    return *(_DWORD *)(a1 + 72) == v1;
  if ( *(_DWORD *)(a1 + 72) && !*(_BYTE *)(a1 + 1224) && v2 == 4 )
    return sub_1286B4(a1);
  return *(unsigned __int8 *)(v1 + 26) == *(unsigned __int8 *)(a1 + 107);
}

