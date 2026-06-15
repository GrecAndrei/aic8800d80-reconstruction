// sub_12287C @ 0x12287c, size 148 bytes
int __fastcall sub_12287C(int a1, int a2, int a3, int a4)
{
  int v4; // r9
  int v6; // r5
  int v9; // r8
  char v10; // r1
  int v11; // r2

  v4 = dword_122920;
  v6 = *(unsigned __int8 *)(a2 + 5);
  if ( **(__int16 **)off_122910 < 0 && *(_BYTE *)(dword_122920 + 1320 * v6 + 106) )
    sub_12F32C(dword_12291C, dword_122918, 2660);
  v9 = v4 + 1320 * v6;
  v10 = *(_BYTE *)(a2 + 4);
  v11 = *(unsigned __int8 *)(v9 + 149);
  *(_DWORD *)(v9 + 1228) = *(_DWORD *)a2;
  *(_BYTE *)(v9 + 1227) = v10;
  if ( v11 == 1 )
  {
    sub_124CF4(1320 * v6 + 152 + v4);
    *(_BYTE *)(v9 + 149) = 0;
  }
  sub_12EB90(256, dword_122914);
  sub_12C8D0(98, a4, a3);
  return 0;
}

