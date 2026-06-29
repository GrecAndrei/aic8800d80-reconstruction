// sub_1145AC @ 0x1145ac, size 110 bytes
int  sub_1145AC(int result)
{
  if ( !result )
  {
    if ( *(uint32_t *)off_11461C
      && (result = *((uint32_t *)off_114620 + 4),
          *(uint32_t *)(*(uint32_t *)off_11461C + 12) - result - *((unsigned __int16 *)off_114624 + 92) - 2000 < 0) )
    {
      result = sub_12ECD0(2, dword_114634);
    }
    else
    {
      if ( !*(uint8_t *)off_114628
        || (result = *((uint32_t *)off_114620 + 4),
            *((uint32_t *)off_114628 + 1)
          + *((uint32_t *)off_114628 + 2)
          - result
          - *((unsigned __int16 *)off_114624 + 92)
          - *(unsigned __int16 *)(*(uint32_t *)off_11462C + 52) >= 0) )
      {
        *(uint32_t *)off_114630 = 0x40000000;
        return result;
      }
      result = sub_12ECD0(2, dword_114638);
    }
  }
  *(uint32_t *)off_114630 = 0x80000000;
  return result;
}

