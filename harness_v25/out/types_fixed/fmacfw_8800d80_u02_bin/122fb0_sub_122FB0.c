// sub_122FB0 @ 0x122fb0, size 186 bytes
int __fastcall sub_122FB0(int a1, _BYTE *a2, int a3, int a4)
{
  int v5; // r1
  int v6; // r2
  _BYTE *v7; // r5
  int v8; // r2
  _BYTE *v9; // r6
  unsigned int v10; // r7
  int v11; // r1
  int v13; // r2
  _BYTE *(_DWORD *)(v14 + 0x14); // [sp+7h] [bp-5h] BYREF

  *(_DWORD *)(v14 + 0x0) = 0;
  v7 = (_BYTE *)sub_12C92C(124, a4, a3, 2);
  if ( *a2 )
  {
    msg_parse(dword_12306C, v5, v6);
    **(_BYTE **)off_123070 = 0;
  }
  else
  {
    msg_parse(dword_12307C, v5, v6);
    **(_BYTE **)off_123070 = 3;
  }
  sub_114B44(v14);
  v8 = *(_DWORD *)(v14 + 0x0);
  *(_DWORD *)(v7 + 0x4) = *(_DWORD *)(v14 + 0x0);
  if ( *(_DWORD *)(a2 + 0x4) )
  {
    v9 = off_123074;
    *((_BYTE *)off_123074 + 188) = (v8 & 0x20) != 0;
    v10 = ((v8 ^ 0x40u) >> 6) & 1;
  }
  else
  {
    v13 = (unsigned __int8)*(_DWORD *)(a2 + 0x8);
    v9 = off_123074;
    v10 = ((v13 ^ 0x40u) >> 6) & 1;
    *((_BYTE *)off_123074 + 188) = (v13 & 0x20) != 0;
  }
  if ( patch_apply_n_313() )
  {
    *(_DWORD *)(v9 + 0x2f0) = 0;
    v11 = 0;
  }
  else
  {
    v11 = (unsigned __int8)*(_DWORD *)(v9 + 0x2f0);
  }
  if ( *a2 )
  {
    if ( *(_DWORD *)(a2 + 0xc) )
      *((_WORD *)v9 + 89) |= 0x4000u;
    msg_parse(dword_123078, v11, v10);
    LOBYTE(v11) = *(_DWORD *)(v9 + 0x2f0);
  }
  *v7 = v11;
  sdio_buffer_prepare_n_4e8(v7);
  return 0;
}

