// fwstruct annotate: 128ec4_sub_128EC4.c
// sub_128EC4 @ 0x128ec4, size 64 bytes
int __fastcall sub_128EC4(int a1, int a2, int a3, int a4)
{
  int result; // r0
  unsigned __int16 *v7; // r2
  char v8; // r3

  feature_guard_sdio(2, dword_128F08);
  result = sub_128D50(a1, a2, dword_128F0C);
  if ( result )
  {
    v7 = (unsigned __int16 *)off_128F10;
    if ( !*((_BYTE *)off_128F10 + 8) || (v8 = *((_BYTE *)off_128F10 + 8) - 1, (*((_BYTE *)off_128F10 + 8) = v8) == 0) )
    {
      *(_BYTE *)v7 = 1;
      return message_dispatch_n84(50, v7[1], 0, a4);
    }
  }
  return result;
}

