// sub_12B49C @ 0x12b49c, size 46 bytes
int __fastcall sub_12B49C(int a1)
{
  _DWORD *v1; // r6
  char *v2; // r4
  int result; // r0

  v1 = off_12B4CC;
  v2 = (char *)off_12B4D0;
  v1[1] = sub_12DD88(off_12B4D0, *(unsigned __int16 *)(*(_DWORD *)off_12B4CC + 364));
  result = sub_12B3C8();
  *(_DWORD *)&v2[-8] = *(_DWORD *)&v2[-12] - 1 + *(unsigned __int16 *)(a1 + 364);
  *((_DWORD *)v2 - 1) = 0;
  return result;
}

