// sub_11B688 @ 0x11b688, size 100 bytes
_DWORD *__fastcall sub_11B688(_DWORD *result)
{
  _DWORD *v1; // r2
  int v2; // r5
  _DWORD *v3; // r4
  _DWORD *v4; // r2
  _DWORD *v5; // r3
  _DWORD *v6; // r6
  int v7; // r4
  int v8; // r1
  _DWORD *v9; // r5

  v1 = off_11B6F4;
  v2 = *(_DWORD *)(result + 0x24);
  v3 = off_11B6F8;
  *(_DWORD *)off_11B6F0 = *(_DWORD *)off_11B6EC + 20000;
  *v1 = 64;
  v4 = off_11B6FC;
  v5 = off_11B700;
  v6 = off_11B704;
  *v3 |= 0x40u;
  *(_DWORD *)(v5 + 0x44c) = *(_DWORD *)(v2 + 12);
  v7 = *(_DWORD *)(v4 + 0xd0);
  v8 = *(_DWORD *)(result + 0x3c);
  *(_DWORD *)(v5 + 0x450) = *(_DWORD *)(v2 + 16);
  *(_DWORD *)(v4 + 0xd0) = v7 | 1;
  v9 = off_11B708;
  *(_DWORD *)(result + 0x24) = v5 + 272;
  *(_DWORD *)(result + 0x3c) = v8 & 0xFF00;
  *(_DWORD *)(result + 0x4) = 0;
  *((_BYTE *)v4 + 200) = 0;
  *v6 = result;
  *v9 = 0x2000;
  return result;
}

