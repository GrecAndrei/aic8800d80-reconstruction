// sub_11446C @ 0x11446c, size 110 bytes
int  sub_11446C(int result)
{
  if ( !result )
  {
    if ( *(uint32_t *)off_1144DC
      && (result = *((uint32_t *)off_1144E0 + 4),
          *(uint32_t *)(*(uint32_t *)off_1144DC + 12) - result - *((unsigned __int16 *)off_1144E4 + 92) - 2000 < 0) )
    {
      result = sub_12EB90(2, dword_1144F4);
    }
    else
    {
      if ( !*(uint8_t *)off_1144E8
        || (result = *((uint32_t *)off_1144E0 + 4),
            *((uint32_t *)off_1144E8 + 1)
          + *((uint32_t *)off_1144E8 + 2)
          - result
          - *((unsigned __int16 *)off_1144E4 + 92)
          - *(unsigned __int16 *)(*(uint32_t *)off_1144EC + 52) >= 0) )
      {
        *(uint32_t *)off_1144F0 = 0x40000000;
        return result;
      }
      result = sub_12EB90(2, dword_1144F8);
    }
  }
  *(uint32_t *)off_1144F0 = 0x80000000;
  return result;
}

