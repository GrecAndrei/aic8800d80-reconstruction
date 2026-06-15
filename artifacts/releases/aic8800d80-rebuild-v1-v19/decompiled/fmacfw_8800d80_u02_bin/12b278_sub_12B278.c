// sub_12B278 @ 0x12b278, size 46 bytes
// Doc: sub_122B278 [mmio]: Read interface state offset 0x16c and invoke sub-handler
// sub_122B278 [mmio]: Read interface state offset 0x16c and invoke sub-handler
int __fastcall sub_12B278(int a1)
{
  _DWORD *v1; // r6
  char *v2; // r4
  int result; // r0

  v1 = off_12B2A8;
  v2 = (char *)off_12B2AC;
  v1[1] = sub_12DB60(off_12B2AC, *(unsigned __int16 *)(*(_DWORD *)off_12B2A8 + 364));
  result = sub_12B1A4();
  *(_DWORD *)&v2[-8] = *(_DWORD *)&v2[-12] - 1 + *(unsigned __int16 *)(a1 + 364);
  *((_DWORD *)v2 - 1) = 0;
  return result;
}

