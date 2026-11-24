// sub_130798 @ 0x130798, size 56 bytes
int __fastcall sub_130798(int a1)
{
  _DWORD *v2; // r1
  _WORD *v3; // r2
  __int16 v4; // r6
  __int16 v5; // r5
  __int16 v6; // r4

  v2 = off_1307D0;
  **(_BYTE **)a1 = -65;
  *(_BYTE *)(*(_DWORD *)a1 + 1) = 12;
  *(_DWORD *)(*(_DWORD *)a1 + 2) = *(_DWORD *)(v2 + 0x30);
  v3 = *(_WORD **)a1;
  v4 = *((_WORD *)v2 + 26);
  v5 = *((_WORD *)v2 + 27);
  v6 = *((_WORD *)v2 + 28);
  *(_DWORD *)(v3 + 0x18) = *((_WORD *)v2 + 29);
  *(_DWORD *)(v3 + 0xc) = v4;
  *(_DWORD *)(v3 + 0x10) = v5;
  *(_DWORD *)(v3 + 0x14) = v6;
  *(_DWORD *)a1 = v3 + 7;
  return 14;
}

