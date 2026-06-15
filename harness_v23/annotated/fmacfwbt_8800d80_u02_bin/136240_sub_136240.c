// v23 annotated: sub_136240 @ 0x136240
// Original: 136240_sub_136240.c
// Primary struct: <unclustered>
//
// sub_136240 @ 0x136240, size 112 bytes
// Doc: sub_1236240 [util]: Allocates 0x100-byte buffer and triggers initialization sequence
// sub_1236240 [util]: Allocates 0x100-byte buffer and triggers initialization sequence
int __fastcall sub_136240(int a1, unsigned __int16 *a2, __int16 a3, __int16 a4)
{
  int v7; // r2
  int v9; // r7
  int v10; // r1
  int v11; // r2
  char v12; // r12

  feature_guard_sdio(256, dword_1362B0, *a2);
  v7 = *a2;
  if ( *(_BYTE *)(dword_1362B4 + 1320 * v7 + 106) == 2 )
  {
    v9 = dword_1362B8 + 696 * (v7 + 32);
    v10 = *(_DWORD *)(a2 + 3);
    v11 = *(_DWORD *)(a2 + 5);
    v12 = *((_BYTE *)a2 + 14);
    *(_DWORD *)(v9 + 192) = *(_DWORD *)(a2 + 1);
    *(_DWORD *)(v9 + 196) = v10;
    *(_DWORD *)(v9 + 200) = v11;
    *(_BYTE *)(v9 + 204) = v12;
    feature_guard_sdio(256, dword_1362BC, *((unsigned __int8 *)a2 + 2));
    bt_link_state_check(v9);
  }
  message_dispatch_n84(7179, a4, a3);
  return 0;
}

