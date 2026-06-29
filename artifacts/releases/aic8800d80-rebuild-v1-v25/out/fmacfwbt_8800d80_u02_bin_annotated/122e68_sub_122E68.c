// fwstruct annotate: 122e68_sub_122E68.c
// sub_122E68 @ 0x122e68, size 92 bytes
int __fastcall sub_122E68(int a1, unsigned __int8 *a2, int a3, int a4)
{
  int v4; // r7
  int v6; // r5
  int v9; // r0
  int v10; // r3

  v4 = dword_122EC8;
  v6 = *a2;
  if ( **(__int16 **)off_122EC4 < 0 && *(_BYTE *)(dword_122EC8 + 1320 * v6 + 106) )
    sub_12F694(dword_122ED0, dword_122ECC, 2639);
  v9 = v4 + 1320 * v6;
  *(_WORD *)(v9 + 112) = *((_WORD *)a2 + 1);
  v10 = a2[4];
  *(_BYTE *)(v9 + 114) = v10;
  message_dispatch_n84(76, a4, a3, v10);
  return 0;
}

