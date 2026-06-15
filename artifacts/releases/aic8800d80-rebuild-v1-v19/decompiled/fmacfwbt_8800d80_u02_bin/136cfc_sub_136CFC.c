// sub_136CFC @ 0x136cfc, size 306 bytes
int **__fastcall sub_136CFC(int a1, int a2, _DWORD *a3)
{
  int v3; // r7
  int v5; // r2
  int v7; // r8
  int **v8; // r4
  char v9; // r1
  int v10; // r5
  BOOL v11; // r2
  int ***v12; // r10
  int v13; // r1
  char v14; // r3
  int **v15; // r3
  BOOL v16; // r1
  int v18; // r7
  int v19; // r0

  v3 = *(unsigned __int8 *)(a1 + 106);
  if ( v3 != 2 || (v5 = *(unsigned __int8 *)(a2 + 54), !*(_BYTE *)(a2 + 54)) )
  {
    *a3 = 0;
    return nullptr;
  }
  v7 = v5 & 1;
  if ( (v5 & 1) == 0 )
  {
    v3 = 8;
    v7 = 4;
  }
  if ( ((unsigned __int8)v3 & *(_BYTE *)(a2 + 53)) == 0 )
    goto LABEL_26;
  v8 = *(int ***)(a2 + 572);
  if ( !v8 )
  {
LABEL_24:
    if ( **(__int16 **)off_136E34 < 0 )
      sub_12F6C4(dword_136E3C, dword_136E38, 441);
LABEL_26:
    *a3 = 1;
    return nullptr;
  }
  v9 = *(_BYTE *)(a2 + 310);
  v10 = dword_136E30;
  v11 = v5 == 2;
  v12 = nullptr;
  while ( ((unsigned __int8)(v9 & *(_BYTE *)(dword_136E30 + *((unsigned __int8 *)v8 + 27))) == 0) == v11 )
  {
    v12 = (int ***)v8;
    if ( !*v8 )
      goto LABEL_24;
    v8 = (int **)*v8;
  }
  bt_msg_handler_sub(a2 + 572, v12, v8);
  v13 = *(unsigned __int8 *)(a2 + 54);
  if ( (v13 & 8) != 0 )
    v14 = 4;
  else
    v14 = 3;
  *((_BYTE *)v8 + 27) = v14;
  if ( v12 )
    v15 = *v12;
  else
    v15 = *(int ***)(a2 + 572);
  if ( v15 )
  {
    v16 = v13 == 2;
    while ( ((unsigned __int8)(*(_BYTE *)(a2 + 310) & *(_BYTE *)(v10 + *((unsigned __int8 *)v15 + 27))) == 0) == v16 )
    {
      v15 = (int **)*v15;
      if ( !v15 )
        goto LABEL_22;
    }
    goto LABEL_20;
  }
LABEL_22:
  v18 = *(unsigned __int8 *)(a2 + 53) & ~v3;
  *(_BYTE *)(a2 + 53) = v18;
  if ( (v18 & v7) != 0 )
  {
LABEL_20:
    *((_WORD *)v8[18] + 54) |= 0x2000u;
    return v8;
  }
  v19 = rf_bus_setup_n3a8(65, 0, 5, 4u);
  *(_WORD *)v19 = *(_WORD *)(a2 + 32);
  *(_BYTE *)(v19 + 3) = *(_BYTE *)(a2 + 34);
  *(_BYTE *)(v19 + 2) = 0;
  sub_12CBB4(v19);
  return v8;
}

