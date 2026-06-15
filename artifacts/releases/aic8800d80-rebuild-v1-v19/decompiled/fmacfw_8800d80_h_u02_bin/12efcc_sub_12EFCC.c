// sub_12EFCC @ 0x12efcc, size 116 bytes
int __fastcall sub_12EFCC(int a1, int *a2, __int16 a3, __int16 a4)
{
  int v5; // r0
  int v6; // r3
  _DWORD *v7; // r4
  int v9; // r5

  v5 = sub_12C7EC(1038, a4, a3, 4u);
  v6 = a2[1];
  v7 = (_DWORD *)v5;
  switch ( v6 )
  {
    case 1:
      sub_12E948(loc_12F04C, *(_DWORD *)(*a2 + 4));
      break;
    case 2:
      sub_12E948(loc_12F050, *a2);
      break;
    case 3:
      v9 = *a2;
      sub_12E948(loc_12F048, v9);
      if ( !v9 )
        sub_12EF88();
      sub_12C4A4(1068, 1, v9 << 10);
      break;
    default:
      sub_12E948(sub_12F040);
      break;
  }
  *v7 = (unsigned __int8)sub_114700();
  sub_12E948(loc_12F044);
  sub_12C84C((int)v7);
  return 0;
}

