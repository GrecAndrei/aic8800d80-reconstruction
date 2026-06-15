// v23 annotated: sub_11CD50 @ 0x11cd50
// Original: 11cd50_sub_11CD50.c
// Primary struct: <unclustered>
//
// sub_11CD50 @ 0x11cd50, size 20 bytes
int __fastcall sub_11CD50(int a1)
{
  if ( (*(_BYTE *)(a1 + 3) & 5) != 0 )
    return *(_DWORD *)(*(_DWORD *)off_11CD64 + 20);
  else
    return fw_signature_check((unsigned __int16 *)a1);
}

