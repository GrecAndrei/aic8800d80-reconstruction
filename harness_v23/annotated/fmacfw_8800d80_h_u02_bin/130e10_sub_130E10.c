// v23 annotated: sub_130E10 @ 0x130e10
// Original: 130e10_sub_130E10.c
// Primary struct: <unclustered>
//
// sub_130E10 @ 0x130e10, size 266 bytes
int __fastcall sub_130E10(unsigned __int8 *a1, int a2, _BYTE *a3, int a4)
{
  unsigned int v8; // r7
  unsigned int v9; // r0
  _BYTE *v10; // r8
  _BYTE *v11; // r9
  unsigned __int8 *v12; // r0
  int v13; // r5
  unsigned int v14; // r3
  unsigned int v15; // r2
  __int16 v16; // r3
  int v18; // r2
  bool v19; // [sp+7h] [bp-1h] BYREF

  v8 = (unsigned int)sub_12D8F8(a1, a2);
  v9 = (unsigned int)sub_12D938(a1, a2);
  if ( !(v8 | v9) )
    return 0;
  v10 = (_BYTE *)v9;
  v11 = sub_12D978(a1, a2, &v19);
  if ( v11 )
  {
    if ( !v19 )
      return 0;
  }
  v12 = sub_12D9BC(a1, a2, &v19);
  if ( v12 )
  {
    if ( !v19 )
      return 0;
  }
  if ( v8 )
  {
    v13 = *(unsigned __int8 *)(v8 + 4);
    *a3 = *(_BYTE *)(v8 + 2);
    v14 = *(unsigned __int8 *)(v8 + 3);
  }
  else
  {
    v13 = (unsigned __int8)v10[5];
    *a3 = v10[2];
    v14 = (unsigned __int8)v10[4];
  }
  if ( !v13 )
    v13 = 2;
  *(_BYTE *)a4 = v14 > 0xE;
  v15 = v14 - 1;
  if ( v14 > 0xE )
  {
    if ( (unsigned __int8)v15 <= 0xB0u )
    {
      v16 = 5 * v14 + 5000;
      goto LABEL_17;
    }
    goto LABEL_23;
  }
  if ( v15 > 0xD )
  {
LABEL_23:
    v16 = 0;
    goto LABEL_17;
  }
  if ( v14 == 14 )
    v16 = 2484;
  else
    v16 = 5 * v14 + 2407;
LABEL_17:
  *(_WORD *)(a4 + 2) = v16;
  *(_WORD *)(a4 + 4) = v16;
  *(_BYTE *)(a4 + 1) = 0;
  *(_WORD *)(a4 + 6) = 0;
  if ( v11 )
  {
    v18 = (unsigned __int8)v11[2];
    if ( v18 == 1 )
    {
      *(_WORD *)(a4 + 4) = v16 + 10;
      *(_BYTE *)(a4 + 1) = 1;
    }
    else if ( v18 == 3 )
    {
      *(_WORD *)(a4 + 4) = v16 - 10;
      *(_BYTE *)(a4 + 1) = 1;
      if ( !v12 )
        goto LABEL_21;
LABEL_25:
      sub_133458(v12[2], v12[3], v12[4], a4);
      goto LABEL_21;
    }
  }
  if ( v12 )
    goto LABEL_25;
LABEL_21:
  sub_132178(a4);
  return v13;
}

