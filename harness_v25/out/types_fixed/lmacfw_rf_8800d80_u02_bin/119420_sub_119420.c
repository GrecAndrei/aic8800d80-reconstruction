// sub_119420 @ 0x119420, size 76 bytes
int __fastcall sub_119420(int a1, int *a2, int a3, int a4)
{
  char *v7; // r7
  _DWORD *v8; // r3
  int v9; // r6
  int v10; // r4
  int v11; // r12
  int v12; // r5
  int v13; // r6

  if ( *(_BYTE *)a2 )
  {
    v7 = (char *)off_119470;
    if ( (*((_BYTE *)off_11946C + 1) & 1) == 0 || (*((_DWORD *)off_119470 + 98) & 1) != 0 )
    {
      v8 = off_119474;
      v9 = *a2;
      v10 = *(_DWORD *)(a2 + 0x8);
      v11 = *(_DWORD *)(a2 + 0xc);
      *((_DWORD *)off_119474 + 1) = *(_DWORD *)(a2 + 0x4);
      *(_DWORD *)(v7 + 266) = v9;
      v12 = *(_DWORD *)(a2 + 0x14);
      v13 = *(_DWORD *)(a2 + 0x10);
      *(_DWORD *)(v8 + 0x8) = v10;
      *(_DWORD *)(v8 + 0x18) = *(_DWORD *)(a2 + 0x18);
      *(_DWORD *)(v8 + 0xc) = v11;
      *(_DWORD *)(v8 + 0x10) = v13;
      *(_DWORD *)(v8 + 0x14) = v12;
    }
  }
  sub_11DED8(122, a4, a3);
  return 0;
}

