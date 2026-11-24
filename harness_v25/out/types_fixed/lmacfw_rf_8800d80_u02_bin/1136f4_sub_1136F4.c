// sub_1136F4 @ 0x1136f4, size 82 bytes
int __fastcall sub_1136F4(int a1, int a2, int a3, int a4)
{
  int result; // r0

  if ( a1 == *(_DWORD *)off_113748 || a1 == *((_DWORD *)off_113748 + 1) )
    result = sub_11F504(dword_11375C, dword_113758);
  else
    result = sub_11F504(dword_11374C, a1);
  if ( *((_BYTE *)off_113750 + 353) )
    return sub_11DAFC(1068, 1, 1000 * *((unsigned __int8 *)off_113750 + 354), a4);
  return result;
}

