// sub_127568 @ 0x127568, size 48 bytes
int sub_127568()
{
  void *v0; // r2
  int v1; // r0
  int result; // r0

  v0 = off_127598;
  if ( (*((_BYTE *)off_127598 + 88) & 0x10) == 0 )
  {
    v1 = *((unsigned __int8 *)off_127598 + 90);
    *((_BYTE *)off_127598 + 88) |= 0x10u;
    if ( v1 )
      return timestamp_update_4f60((int)v0 + 48, *((_DWORD *)off_12759C + 4) + 30000);
    else
      return bt_link_state_get_is_up();
  }
  return result;
}

