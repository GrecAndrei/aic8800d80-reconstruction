// sub_122D9C @ 0x122d9c, size 76 bytes
int __fastcall sub_122D9C(int a1, int *a2, int a3, _DWORD *a4)
{
  int v4; // r4
  _DWORD *v6; // r1
  char *v7; // r7
  int v8; // r6
  int v9; // r4
  int v10; // r12
  int v11; // r5
  int v12; // r6

  v4 = *(unsigned __int8 *)a2;
  v6 = a4;
  if ( v4 )
  {
    v7 = (char *)off_122DEC;
    if ( (*((_BYTE *)off_122DE8 + 1) & 1) == 0
      || (a4 = (_DWORD *)(*((_DWORD *)off_122DEC + 98) << 31), (*((_DWORD *)off_122DEC + 98) & 1) != 0) )
    {
      a4 = off_122DF0;
      v8 = *a2;
      v9 = *(_DWORD *)(a2 + 0x8);
      v10 = *(_DWORD *)(a2 + 0xc);
      *((_DWORD *)off_122DF0 + 1) = *(_DWORD *)(a2 + 0x4);
      *(_DWORD *)(v7 + 266) = v8;
      v11 = *(_DWORD *)(a2 + 0x14);
      v12 = *(_DWORD *)(a2 + 0x10);
      *(_DWORD *)(a4 + 0x8) = v9;
      *(_DWORD *)(a4 + 0x18) = *(_DWORD *)(a2 + 0x18);
      *(_DWORD *)(a4 + 0xc) = v10;
      *(_DWORD *)(a4 + 0x10) = v12;
      *(_DWORD *)(a4 + 0x14) = v11;
    }
  }
  message_dispatch_n84(122, v6, a3, a4);
  return 0;
}

