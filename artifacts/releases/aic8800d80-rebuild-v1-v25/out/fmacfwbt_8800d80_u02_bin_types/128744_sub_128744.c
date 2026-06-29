// sub_128744 @ 0x128744, size 34 bytes
BOOL  sub_128744(int a1)
{
  BOOL result; // r0

  result = bt_state_get_n28(a1);
  if ( result )
    return !*((uint32_t *)off_128768 + 11) || *(unsigned __int8 *)(*((uint32_t *)off_128768 + 10) + 16) == 6;
  return result;
}

