// fwstruct annotate: 12b74c_sub_12B74C.c
// sub_12B74C @ 0x12b74c, size 20 bytes
int __fastcall sub_12B74C(int a1)
{
  if ( (*(_BYTE *)(a1 + 3) & 5) != 0 )
    return *(_DWORD *)(*(_DWORD *)off_12B760 + 20);
  else
    return sub_12B338((unsigned __int16 *)a1);
}

