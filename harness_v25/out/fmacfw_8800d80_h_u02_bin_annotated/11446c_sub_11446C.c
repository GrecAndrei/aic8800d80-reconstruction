// fwstruct annotate: 11446c_sub_11446C.c
// sub_11446C @ 0x11446c, size 110 bytes
int __fastcall sub_11446C(int result)
{
  if ( !result )
  {
    if ( *(_DWORD *)off_1144DC
      && (result = *((_DWORD *)off_1144E0 + 4),
          *(_DWORD *)(*(_DWORD *)off_1144DC + 12) - result - *((unsigned __int16 *)off_1144E4 + 92) - 2000 < 0) )
    {
      result = sub_12EB90(2, dword_1144F4);
    }
    else
    {
      if ( !*(_BYTE *)off_1144E8
        || (result = *((_DWORD *)off_1144E0 + 4),
            *((_DWORD *)off_1144E8 + 1)
          + *((_DWORD *)off_1144E8 + 2)
          - result
          - *((unsigned __int16 *)off_1144E4 + 92)
          - *(unsigned __int16 *)(*(_DWORD *)off_1144EC + 52) >= 0) )
      {
        *(_DWORD *)off_1144F0 = 0x40000000;
        return result;
      }
      result = sub_12EB90(2, dword_1144F8);
    }
  }
  *(_DWORD *)off_1144F0 = 0x80000000;
  return result;
}

