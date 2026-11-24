// sub_122C98 @ 0x122c98, size 152 bytes
int __fastcall sub_122C98(int a1, unsigned __int8 *a2, int a3, int a4)
{
  int v4; // r4
  _BYTE *v7; // r4
  _DWORD *v8; // r6
  _DWORD *v9; // r5
  unsigned int v10; // r3
  void *v11; // r3
  _DWORD *v13; // r6
  _DWORD *v14; // r5

  v4 = *a2;
  if ( v4 && *((_BYTE *)off_122D30 + 177) )
  {
    v7 = off_122D34;
    v13 = off_122D38;
    v14 = off_122D3C;
    *(_BYTE *)off_122D34 = 1;
    *v13 |= 0x2000000u;
    *(_DWORD *)(v14 + 0x38) |= 0x10u;
  }
  else
  {
    v7 = off_122D34;
    v8 = off_122D38;
    v9 = off_122D3C;
    *(_BYTE *)off_122D34 = 0;
    *v8 &= ~0x2000000u;
    *(_DWORD *)(v9 + 0x38) &= ~0x10u;
  }
  *(_DWORD *)off_122D38 &= ~0x800u;
  *(_DWORD *)(v7 + 0x8) = 0;
  if ( *(_DWORD *)(a2 + 0x8) )
    v10 = *(_DWORD *)off_122D40 | 0x80000000;
  else
    v10 = *(_DWORD *)off_122D40 & 0x7FFFFFFF;
  *(_DWORD *)off_122D40 = v10;
  v11 = (void *)*(_DWORD *)(a2 + 0x10);
  if ( *(_DWORD *)(a2 + 0x10) )
  {
    v11 = off_122D48;
    *(_DWORD *)off_122D44 = *((_DWORD *)a2 + 2);
    *(_DWORD *)v11 &= 0xFFFFFu;
    *(_DWORD *)v11 |= *((_DWORD *)a2 + 3) << 20;
  }
  message_dispatch_n84(102, a4, a3, v11);
  return 0;
}

