// fwstruct annotate: 125cd0_sub_125CD0.c
// sub_125CD0 @ 0x125cd0, size 94 bytes
int __fastcall sub_125CD0(int result)
{
  int v1; // r6
  int v2; // r4
  int v3; // r3
  int v4; // r5
  int v5; // r4
  int *v6; // r3
  int v7; // r1

  v1 = dword_125D30;
  v2 = *(unsigned __int8 *)(result + 1225);
  v3 = dword_125D30 + 140 * v2;
  v4 = result;
  if ( !*(_BYTE *)(v3 + 32) && *(_BYTE *)(v3 + 16) )
    result = ((int (*)(void))sub_12A5C0)();
  v5 = v1 + 140 * v2;
  if ( !*(_BYTE *)(v5 + 80) && *(_BYTE *)(v5 + 64) )
    result = sub_12A5C0(v4, 1);
  v6 = *((int **)off_125D34 + 2);
  if ( v6 )
  {
    v7 = *(unsigned __int8 *)(v4 + 107);
    result = 255;
    do
    {
      if ( *((unsigned __int8 *)v6 + 86) == v7 )
        *((_BYTE *)v6 + 86) = -1;
      v6 = (int *)*v6;
    }
    while ( v6 );
  }
  return result;
}

