// v23 annotated: sub_114880 @ 0x114880
// Original: 114880_sub_114880.c
// Primary struct: <unclustered>
//
// sub_114880 @ 0x114880, size 132 bytes
int __fastcall sub_114880(int a1, unsigned __int8 *a2, int a3, int a4)
{
  __int16 v5; // r6
  __int16 v6; // r7
  _BYTE *v7; // r5
  int v8; // r9
  int v9; // r8
  int v10; // r0
  _WORD *v11; // r3
  int v12; // r0

  v5 = a4;
  v6 = a3;
  v7 = (_BYTE *)rf_bus_setup_n3a8(3089, a4, a3, 1);
  v8 = *(_DWORD *)a2;
  v9 = a2[4];
  v10 = sub_114790(a2 + 4);
  if ( v10 < 0 )
  {
    sub_12ECB0(dword_114910, v9, v8);
    sub_12CBB4(v7);
    return 0;
  }
  else if ( v8 == v10 )
  {
    v11 = off_114904;
    *((_WORD *)off_114904 + 12) = v6;
    v11[13] = v5;
    sub_11469C(a2);
    v12 = dword_114908;
    *v7 = 1;
    sub_12ECB0(v12, v9, v8);
    sub_12CBB4(v7);
    return 1;
  }
  else
  {
    sub_12ECB0(dword_11490C, v10, v8);
    sub_12CBB4(v7);
    return 0;
  }
}

