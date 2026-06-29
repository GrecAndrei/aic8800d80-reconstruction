// fwstruct annotate: 11cb84_sub_11CB84.c
// sub_11CB84 @ 0x11cb84, size 60 bytes
int __fastcall sub_11CB84(int a1)
{
  char *v1; // r4
  _DWORD *v2; // r6
  int result; // r0

  v1 = (char *)off_11CBC0;
  v2 = off_11CBC4;
  sub_1282E8(off_11CBC0, *(_DWORD *)(a1 + 360), *(unsigned __int16 *)(a1 + 364));
  v2[1] = sub_11EB74(v1, *(unsigned __int16 *)(*v2 + 364));
  result = sub_11CAC8();
  *(_DWORD *)&v1[-8] = *(_DWORD *)&v1[-12] - 1 + *(unsigned __int16 *)(a1 + 364);
  *((_DWORD *)v1 - 1) = 0;
  return result;
}

