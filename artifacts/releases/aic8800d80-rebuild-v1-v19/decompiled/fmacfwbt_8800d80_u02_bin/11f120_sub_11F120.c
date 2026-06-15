// sub_11F120 @ 0x11f120, size 76 bytes
int *__fastcall sub_11F120(int a1)
{
  int v2; // r5
  int v3; // r0
  int *result; // r0
  int v5; // r3

  v2 = a1 + 572;
  while ( *(_DWORD *)(a1 + 572) )
  {
    v3 = sub_12D4F8(v2);
    sub_11913C(v3, 1);
  }
  result = sub_100200((int *)a1, 0, 0x2B8u);
  v5 = a1;
  do
  {
    *(_BYTE *)(v5 + 452) = 33;
    *(_BYTE *)(v5 + 453) = 33;
    v5 += 12;
  }
  while ( v5 != a1 + 108 );
  *(_BYTE *)(a1 + 34) = -1;
  return result;
}

