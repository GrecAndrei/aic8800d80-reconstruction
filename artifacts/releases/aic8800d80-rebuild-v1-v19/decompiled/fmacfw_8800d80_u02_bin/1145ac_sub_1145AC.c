// sub_1145AC @ 0x1145ac, size 110 bytes
int __fastcall sub_1145AC(int result)
{
  if ( !result )
  {
    if ( *(_DWORD *)off_11461C
      && (result = *((_DWORD *)off_114620 + 4),
          *(_DWORD *)(*(_DWORD *)off_11461C + 12) - result - *((unsigned __int16 *)off_114624 + 92) - 2000 < 0) )
    {
      result = sub_12ECD0(2, dword_114634);
    }
    else
    {
      if ( !*(_BYTE *)off_114628
        || (result = *((_DWORD *)off_114620 + 4),
            *((_DWORD *)off_114628 + 1)
          + *((_DWORD *)off_114628 + 2)
          - result
          - *((unsigned __int16 *)off_114624 + 92)
          - *(unsigned __int16 *)(*(_DWORD *)off_11462C + 52) >= 0) )
      {
        *(_DWORD *)off_114630 = 0x40000000;
        return result;
      }
      result = sub_12ECD0(2, dword_114638);
    }
  }
  *(_DWORD *)off_114630 = 0x80000000;
  return result;
}

