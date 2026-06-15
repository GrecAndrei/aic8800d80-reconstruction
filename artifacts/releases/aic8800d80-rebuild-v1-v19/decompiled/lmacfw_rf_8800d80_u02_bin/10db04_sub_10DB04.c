// sub_10DB04 @ 0x10db04, size 16 bytes
// Doc: sub_120DB04 [rf]: Unknown LMAC RF helper function
// sub_120DB04 [rf]: Unknown LMAC RF helper function
int __fastcall sub_10DB04(char a1)
{
  int result; // r0

  result = (1 << a1) | *(_DWORD *)off_10DB14;
  *(_DWORD *)off_10DB14 = result;
  return result;
}

