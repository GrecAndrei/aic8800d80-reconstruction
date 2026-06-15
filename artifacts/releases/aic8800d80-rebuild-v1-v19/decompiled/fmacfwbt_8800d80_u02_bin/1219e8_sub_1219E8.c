// sub_1219E8 @ 0x1219e8, size 118 bytes
unsigned int __fastcall sub_1219E8(int *a1)
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

  v1 = off_121A60;
  v2 = off_121A64;
  v3 = off_121A68;
  v4 = off_121A6C;
  v5 = off_121A70;
  v6 = off_121A74;
  *(_DWORD *)off_121A60 &= ~2u;
  *v1 |= 1u;
  *v2 = 768;
  v7 = *a1;
  v8 = *((unsigned __int16 *)a1 + 2);
  *v5 = 0;
  *v6 = 0;
  *v3 = v7;
  *v4 = v8;
  v9 = (__int16 **)off_121A78;
  v10 = (int *)off_121A7C;
  v11 = dword_121A80;
  *v1 &= 0xFFFFF8FF;
  v12 = *v9;
  *v10 = v11;
  if ( *v12 < 0 && *(_DWORD *)off_121A88 << 28 )
  {
    sub_12F6C4(dword_121A90, dword_121A8C, 472);
    v11 = *v10;
  }
  *(_DWORD *)off_121A84 = v11 | v10[1];
  return sub_11E4C0(0);
}

