// sub_120104 @ 0x120104, size 40 bytes
int __fastcall sub_120104(int result)
{
  int v1; // r4

  if ( *(_BYTE *)off_12012C && (*((_DWORD *)off_12012C + 1) & 8) == 0 )
  {
    v1 = result;
    if ( !*(_DWORD *)(result + 4) )
    {
      sub_124CF4(result + 48);
      return sub_11F3B4(v1);
    }
  }
  return result;
}

