// sub_116034 @ 0x116034, size 92 bytes
int *__fastcall sub_116034(int a1, int a2, int a3, int a4)
{
  int *result; // r0
  char *v7; // r4
  int v8; // r5
  char v9; // t1
  _BYTE v10[8]; // [sp+8h] [bp-14h] BYREF
  char v11; // [sp+10h] [bp-Ch] BYREF

  if ( (**(_BYTE **)off_116090 & 1) != 0 )
    return sub_100200((int *)(a3 + a4), 0, 8u);
  v7 = v10;
  sub_1334A4(v10, a2, a1 + 12, a1 + 18, *(unsigned __int8 *)(a1 + 27));
  sub_1334F0(v10, a3, a4);
  sub_13362C(v10);
  v8 = a4 + a3;
  do
  {
    result = (int *)(v7 - v10);
    v9 = *v7++;
    *((_BYTE *)result + v8) = v9;
  }
  while ( v7 != &v11 );
  return result;
}

