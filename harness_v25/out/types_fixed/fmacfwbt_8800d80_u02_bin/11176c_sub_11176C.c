// sub_11176C @ 0x11176c, size 74 bytes
int sub_11176C()
{
  _DWORD *v0; // r1
  int v1; // r0
  _DWORD *v2; // r3
  int result; // r0

  v0 = *(_DWORD **)off_1117B8;
  v1 = *(_DWORD *)off_1117BC;
  v2 = off_1117C0;
  *((_WORD *)off_1117C4 + 5) = 0;
  *v0 = 167772160;
  *(_DWORD *)(v0 + 0x4) = v1;
  *(_DWORD *)(v2 + 0x10) = *(_DWORD *)(v2 + 0x10) & 0xFFFFF81F | 0x20;
  do
    result = *(_DWORD *)(v2 + 0x10) & 0x20;
  while ( result );
  *(_DWORD *)(v2 + 0x908) = *(_DWORD *)(v2 + 0x908);
  *(_DWORD *)(v2 + 0x914) = v0;
  *(_DWORD *)(v2 + 0x900) |= 0x84000000;
  return result;
}

