// sub_120244 @ 0x120244, size 40 bytes
// Doc: obj_release_n252 [util]: Release/destroy wrapper object and free memory
// obj_release_n252 [util]: Release/destroy wrapper object and free memory
int __fastcall sub_120244(int result)
{
  int v1; // r4

  if ( *(_BYTE *)off_12026C && (*((_DWORD *)off_12026C + 1) & 8) == 0 )
  {
    v1 = result;
    if ( !*(_DWORD *)(result + 4) )
    {
      timestamp_remove(result + 48);
      return rf_cmd_dispatch_n_125(v1);
    }
  }
  return result;
}

