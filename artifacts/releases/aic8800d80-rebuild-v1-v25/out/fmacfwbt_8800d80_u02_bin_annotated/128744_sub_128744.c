// fwstruct annotate: 128744_sub_128744.c
// sub_128744 @ 0x128744, size 34 bytes
BOOL __fastcall sub_128744(int a1)
{
  BOOL result; // r0

  result = bt_state_get_n28(a1);
  if ( result )
    return !*((_DWORD *)off_128768 + 11) || *(unsigned __int8 *)(*((_DWORD *)off_128768 + 10) + 16) == 6;
  return result;
}

