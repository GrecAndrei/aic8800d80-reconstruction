// v23 annotated: sub_136014 @ 0x136014
// Original: 136014_sub_136014.c
// Primary struct: <unclustered>
//
// sub_136014 @ 0x136014, size 148 bytes
int __fastcall sub_136014(int a1, unsigned __int8 *a2, __int16 a3, __int16 a4)
{
  int v7; // r2
  int v8; // r3
  int v9; // r1
  char v10; // r7
  char *v11; // r0
  int v13; // r0
  int v14; // r0
  int v15; // r1
  unsigned __int8 v16[5]; // [sp+7h] [bp-5h] BYREF

  v7 = a2[9];
  v8 = *a2;
  v16[0] = 0;
  sub_12E948(dword_1360A8, dword_1360AC, v7, v8);
  v9 = dword_1360B0 + 1320 * a2[10];
  if ( *(_BYTE *)(v9 + 106) == 2 )
  {
    if ( *(_BYTE *)(v9 + 108) || sub_12CD48(7u) )
    {
      v10 = 8;
    }
    else
    {
      v13 = sub_127BF4(a2, v16);
      v10 = v13;
      if ( v13 )
      {
        v10 = 1;
      }
      else
      {
        v14 = a2[10];
        v15 = v16[0];
        *(_BYTE *)off_1360B4 = 1;
        sub_128748(v14, v15);
        *((_DWORD *)off_1360B8 + 1) |= 0x10u;
      }
    }
  }
  else
  {
    v10 = 4;
  }
  v11 = (char *)sub_12C7EC(7173, a4, a3, 2u);
  *v11 = v10;
  v11[1] = v16[0];
  sub_12C84C((int)v11);
  return 0;
}

