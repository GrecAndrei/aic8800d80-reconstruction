// sub_121648 @ 0x121648, size 118 bytes
unsigned int __fastcall sub_121648(int *a1)
{
  _DWORD *v1; // r3
  _DWORD *v2; // r7
  _DWORD *v3; // r4
  _DWORD *v4; // r1
  _DWORD *v5; // r6
  _DWORD *v6; // r5
  int v7; // r7
  int v8; // r0
  __int16 **v9; // r0
  int *v10; // r4
  int v11; // r2
  __int16 *v12; // r3

  v1 = off_1216C0;
  v2 = off_1216C4;
  v3 = off_1216C8;
  v4 = off_1216CC;
  v5 = off_1216D0;
  v6 = off_1216D4;
  *(_DWORD *)off_1216C0 &= ~2u;
  *v1 |= 1u;
  *v2 = 768;
  v7 = *a1;
  v8 = *((unsigned __int16 *)a1 + 2);
  *v5 = 0;
  *v6 = 0;
  *v3 = v7;
  *v4 = v8;
  v9 = (__int16 **)off_1216D8;
  v10 = (int *)off_1216DC;
  v11 = dword_1216E0;
  *v1 &= 0xFFFFF8FF;
  v12 = *v9;
  *v10 = v11;
  if ( *v12 < 0 && *(_DWORD *)off_1216E8 << 28 )
  {
    sub_12F35C(dword_1216F0, dword_1216EC, 472);
    v11 = *v10;
  }
  *(_DWORD *)off_1216E4 = v11 | v10[1];
  return sub_11DF40(0);
}

