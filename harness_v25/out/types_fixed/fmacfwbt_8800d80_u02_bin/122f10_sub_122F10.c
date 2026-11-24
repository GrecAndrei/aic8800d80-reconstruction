// sub_122F10 @ 0x122f10, size 64 bytes
int __fastcall sub_122F10(int a1, unsigned __int8 *a2, int a3, int a4)
{
  int v7; // r1
  _BYTE *v8; // r2
  BOOL v9; // r0
  int v10; // r3

  if ( *(_DWORD *)(a2 + 0x4) != 255 )
    sub_13BD84();
  v7 = *a2;
  v8 = off_122F54;
  if ( *a2 )
    v7 = 1;
  v9 = *(_DWORD *)(a2 + 0x8) != 0;
  *(_BYTE *)off_122F50 = v9;
  *v8 = v7;
  sub_12ECB0(dword_122F58, v7, v9);
  message_dispatch_n84(100, a4, a3, v10);
  return 0;
}

