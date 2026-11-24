// sub_11C850 @ 0x11c850, size 48 bytes
// Doc: sub_121C850 [mmio]: Allocate LMAC object via helper and stash return in r4
// sub_121C850 [mmio]: Allocate LMAC object via helper and stash return in r4
int __fastcall sub_11C850(int a1, int a2, int a3, int a4)
{
  int v5; // r4

  v5 = sub_11E34C(2);
  sub_11F74C(4, dword_11C884, dword_11C880, v5);
  if ( v5 )
    *((_BYTE *)off_11C888 + 11) = 1;
  else
    sub_11CD0C(1, a4);
  return 0;
}

