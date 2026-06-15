// v23 annotated: sub_103540 @ 0x103540
// Original: 103540_sub_103540.c
// Primary struct: <unclustered>
//
// sub_103540 @ 0x103540, size 138 bytes
int __fastcall sub_103540(int a1, int a2, int a3, int a4, int a5)
{
  _DWORD *v5; // r2
  int v6; // r3
  _DWORD *v7; // r3
  _DWORD *v8; // r2
  int v9; // r3
  int *v10; // r3
  int *v11; // r0
  int v12; // r1
  int v13; // r2
  int v14; // r3

  v5 = off_1035D0;
  *(_DWORD *)off_1035CC |= 1u;
  while ( (*v5 & 0x10) == 0 )
  {
    LOWORD(v6) = 50;
    do
      v6 = (unsigned __int16)(v6 - 1);
    while ( v6 );
  }
  v7 = off_1035D4;
  v8 = off_1035D0;
  *(_DWORD *)off_1035D4 |= 0x80000u;
  *v7 |= 0x100000u;
  while ( (*v8 & 8) == 0 )
  {
    LOWORD(v9) = 50;
    do
      v9 = (unsigned __int16)(v9 - 1);
    while ( v9 );
  }
  v10 = (int *)off_1035DC;
  v11 = (int *)off_1035E0;
  v12 = dword_1035E4;
  *(_DWORD *)off_1035D8 |= 0x20000u;
  *v10 |= 0x1000000u;
  v13 = *v10 | 0x8000000;
  *v10 = v13;
  v14 = *v11 | 0x524;
  *v11 = v14;
  return sub_11F74C(0x2000, v12, v13, v14, a5);
}

