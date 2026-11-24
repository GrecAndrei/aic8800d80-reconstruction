// sub_122A28 @ 0x122a28, size 76 bytes
int __fastcall sub_122A28(int a1, int *a2, int a3, int a4)
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
    v7 = (char *)off_122A78;
    if ( (*((_BYTE *)off_122A74 + 1) & 1) == 0 || (*((_DWORD *)off_122A78 + 98) & 1) != 0 )
    {
      v8 = off_122A7C;
      v9 = *a2;
      v10 = *(_DWORD *)(a2 + 0x8);
      v11 = *(_DWORD *)(a2 + 0xc);
      *((_DWORD *)off_122A7C + 1) = *(_DWORD *)(a2 + 0x4);
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
  sub_12C8D0(122, a4, a3);
  return 0;
}

