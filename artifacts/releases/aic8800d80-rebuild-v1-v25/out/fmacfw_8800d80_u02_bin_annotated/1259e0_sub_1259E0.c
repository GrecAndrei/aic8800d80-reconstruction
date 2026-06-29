// fwstruct annotate: 1259e0_sub_1259E0.c
// sub_1259E0 @ 0x1259e0, size 94 bytes
// Doc: sub_12259E0 [ipc]: Helper: fetch FW header word and issue mailbox/IPC call (0x40)
// sub_12259E0 [ipc]: Helper: fetch FW header word and issue mailbox/IPC call (0x40)
int __fastcall sub_1259E0(int a1)
{
  int *v1; // r5
  int v2; // r6
  int v4; // r2
  int v5; // r3
  int v6; // r6
  int v7; // r2

  v1 = (int *)off_125A40;
  v2 = *(_DWORD *)off_125A40;
  sub_12CA10(64, *(unsigned __int16 *)(*(_DWORD *)off_125A40 - 4), 0);
  sub_125510(a1, *v1);
  v4 = *v1;
  *(_BYTE *)(a1 + 231) = 0;
  v5 = *(unsigned __int8 *)(v4 + 10);
  *(_BYTE *)(a1 + 232) = v5;
  *(_BYTE *)(a1 + 233) = *(_BYTE *)(v4 + 11);
  v6 = v2 - 12;
  if ( v5 )
    *(_BYTE *)(a1 + 231) = *(_BYTE *)(*(_DWORD *)(*(_DWORD *)(a1 + 192) + 28) + v5) + 1;
  v7 = *((unsigned __int8 *)v1 + 8);
  *((_BYTE *)v1 + 9) = 0;
  if ( v7 )
    sub_1258C0();
  *v1 = 0;
  return sub_12CA38(v6);
}

