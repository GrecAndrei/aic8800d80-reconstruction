// v23 annotated: sub_140AAC @ 0x140aac
// Original: 140aac_sub_140AAC.c
// Primary struct: <unclustered>
//
// sub_140AAC @ 0x140aac, size 408 bytes
int __fastcall sub_140AAC(int a1, int a2)
{
  int v3; // r5
  int v4; // r7
  int *v5; // r0
  __int64 v6; // r0
  int v7; // r8
  int v8; // r7
  int v9; // r5
  int v10; // r9
  _DWORD *v11; // r1
  int v12; // r2
  int v13; // r3
  int v14; // r3
  int v15; // r2
  char *v16; // r0
  char *v17; // r5
  int v18; // r6
  int v19; // r2

  if ( a2 )
  {
    v3 = dword_140C48;
    sub_12D100((_DWORD *)dword_140C44);
    v4 = v3 + 6336;
    do
    {
      *(_WORD *)(v3 - 2) = 0;
      v5 = (int *)v3;
      v3 += 528;
      sub_100200(v5, 0, 6u);
    }
    while ( v4 != v3 );
    LODWORD(v6) = sub_12BD00();
    *(_QWORD *)(a1 + 40) = v6;
    *(_DWORD *)(a1 + 96) = 0;
  }
  v7 = dword_140C4C;
  v8 = dword_140C44;
LABEL_6:
  while ( sub_12CD48(0xBu) == 1 )
  {
    v9 = dword_140C4C;
    v10 = dword_140C4C + 6336;
    do
    {
      while ( *(_WORD *)(v9 + 4) != 1 || !sub_140A38((unsigned __int16 *)(v9 + 6), v9 + 28, a1) )
      {
        v9 += 528;
        if ( v9 == v10 )
          goto LABEL_12;
      }
      v11 = (_DWORD *)v9;
      *(_WORD *)(v9 + 24) = 0;
      *(_BYTE *)(v9 + 22) = 0;
      *(_WORD *)(v9 + 4) = 2;
      v9 += 528;
      sub_12D108(v8, v11);
    }
    while ( v9 != v10 );
LABEL_12:
    v12 = *(unsigned __int8 *)(a1 + 101);
    v13 = *(_DWORD *)(a1 + 96) + 1;
    *(_DWORD *)(a1 + 96) = v13;
    if ( v13 >= v12 )
    {
      if ( **(__int16 **)off_140C50 < 0 && sub_1403D0() )
      {
        if ( *(_DWORD *)(a1 + 92) )
          sub_12F32C(dword_140C58, dword_140C54, 1585);
      }
      sub_12CBF4(0xBu, 2);
      return sub_1409A4(a1, 0);
    }
    sub_12CBF4(0xBu, 3);
    if ( !sub_1403D0() )
      return sub_1409A4(a1, 0);
  }
  sub_12CBF4(0xBu, 1);
  v14 = *(_DWORD *)(a1 + 96);
  while ( 1 )
  {
    v16 = sub_132104((char *)*(unsigned __int8 *)(a1 + 100), *(unsigned __int8 *)(v14 + a1 + 102));
    v17 = v16;
    if ( v16 )
    {
      if ( (v16[3] & 2) == 0 )
        break;
    }
    v15 = *(unsigned __int8 *)(a1 + 101);
    v14 = *(_DWORD *)(a1 + 96) + 1;
    *(_DWORD *)(a1 + 96) = v14;
    if ( v14 >= v15 )
      goto LABEL_6;
  }
  v18 = sub_12C7EC(4096, 4, 11, 0x178u);
  *(_DWORD *)v18 = *(_DWORD *)v17;
  *(_WORD *)(v18 + 4) = *((_WORD *)v17 + 2);
  if ( !*(_BYTE *)(a1 + 3) )
    *(_BYTE *)(v18 + 3) |= 1u;
  *(_BYTE *)(v18 + 367) = 1;
  v19 = *(unsigned __int8 *)(a1 + 58);
  *(_BYTE *)(v18 + 252) = v19;
  sub_143630(v18 + 253, a1 + 59, v19);
  *(_BYTE *)(v18 + 368) = 1;
  *(_WORD *)(v18 + 352) = *(_WORD *)(a1 + 52);
  *(_WORD *)(v18 + 354) = *(_WORD *)(a1 + 54);
  *(_WORD *)(v18 + 356) = *(_WORD *)(a1 + 56);
  *(_BYTE *)(v18 + 366) = *(_BYTE *)(v7 + 6489);
  *(_DWORD *)(v18 + 372) = *(unsigned __int16 *)(a1 + 48) << 10;
  return sub_12C84C(v18);
}

