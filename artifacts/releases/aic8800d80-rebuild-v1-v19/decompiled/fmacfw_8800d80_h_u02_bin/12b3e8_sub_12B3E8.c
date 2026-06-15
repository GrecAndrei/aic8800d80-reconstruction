// sub_12B3E8 @ 0x12b3e8, size 20 bytes
int __fastcall sub_12B3E8(int a1)
{
  if ( (*(_BYTE *)(a1 + 3) & 5) != 0 )
    return *(_DWORD *)(*(_DWORD *)off_12B3FC + 20);
  else
    return sub_12AFD4((unsigned __int16 *)a1);
}

