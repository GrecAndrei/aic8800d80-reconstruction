// v23 annotated: sub_142480 @ 0x142480
// Original: 142480_sub_142480.c
// Primary struct: <unclustered>
//
// sub_142480 @ 0x142480, size 198 bytes
int __fastcall sub_142480(int a1, unsigned __int8 *a2, __int16 a3, __int16 a4)
{
  int v6; // r7
  int v8; // r11
  int v9; // r4
  int v10; // r0
  char v11; // r2
  _BYTE *v12; // r0
  int v14; // r4
  int v15; // r10
  int v16; // r1
  unsigned __int8 v17; // [sp+4h] [bp-8h]
  int v18; // [sp+4h] [bp-8h]

  if ( !*(_BYTE *)off_142548 )
    goto LABEL_7;
  v6 = *a2;
  if ( *a2 )
    goto LABEL_7;
  v8 = a2[3];
  if ( !a2[1] )
  {
    v9 = dword_14254C;
    v17 = a2[2];
    v10 = sub_1420F8(*(unsigned __int8 *)(dword_14254C + 1320 * v8 + 116), v8, v17);
    if ( v10 )
    {
      sub_1420D4(v10);
      v11 = v17;
LABEL_6:
      LOBYTE(v6) = sub_14207C(a2[3], *(unsigned __int8 *)(v9 + 1320 * v8 + 116), v11) == 0;
      goto LABEL_8;
    }
LABEL_7:
    LOBYTE(v6) = 1;
    goto LABEL_8;
  }
  v14 = dword_142550;
  v15 = dword_142550 + 576;
  v16 = dword_14254C + 1320 * v8;
  do
  {
    if ( (*(_WORD *)v14 & 1) != 0
      && *(unsigned __int8 *)(v14 + 46) == *(unsigned __int8 *)(v16 + 116)
      && *(unsigned __int8 *)(v14 + 47) == a2[3] )
    {
      v18 = v16;
      v6 = 1;
      sub_1420D4(v14);
      v16 = v18;
    }
    v14 += 72;
  }
  while ( v14 != v15 );
  if ( v6 )
  {
    v9 = dword_14254C;
    v11 = 0x80;
    goto LABEL_6;
  }
LABEL_8:
  v12 = (_BYTE *)rf_bus_setup_n3a8(12292, a4, a3, 1u);
  *v12 = v6;
  sub_12CBB4((int)v12);
  return 0;
}

