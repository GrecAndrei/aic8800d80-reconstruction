// v23 annotated: sub_142E6A @ 0x142e6a
// Original: 142e6a_sub_142E6A.c
// Primary struct: <unclustered>
//
// sub_142E6A @ 0x142e6a, size 98 bytes
int __fastcall sub_142E6A(int result, int a2, int a3, unsigned int a4)
{
  bool v4; // cf
  int v5; // r4
  int v6; // r12
  int v7; // r5
  bool v8; // zf
  bool v9; // zf

  v7 = v6 & (a4 >> 20);
  v8 = v5 == v6;
  if ( v5 == v6 )
    v8 = v7 == v6;
  if ( v8 )
LABEL_25:
    JUMPOUT(0x142CF2);
  if ( v5 == v6 )
  {
    if ( result | (a2 << 12) || v7 == v6 )
      goto LABEL_25;
LABEL_26:
    JUMPOUT(0x142CDC);
  }
  if ( v7 == v6 )
  {
    if ( a3 | (a4 << 12) )
      goto LABEL_25;
    goto LABEL_27;
  }
  v9 = (result | (2 * a2)) == 0;
  if ( result | (2 * a2) )
    v9 = (a3 | (2 * a4)) == 0;
  if ( v9 )
  {
    if ( result | (2 * a2) )
      goto LABEL_26;
    if ( !(a3 | (2 * a4)) )
      goto LABEL_25;
LABEL_27:
    JUMPOUT(0x142CA0);
  }
  if ( v5 )
    goto LABEL_30;
  while ( 1 )
  {
    v4 = __CFSHL__(result, 1);
    result *= 2;
    a2 += v4 + a2;
    if ( (a2 & 0x100000) != 0 )
      break;
    --v5;
  }
  if ( !v7 )
  {
LABEL_30:
    while ( 1 )
    {
      v4 = __CFSHL__(a3, 1);
      a3 *= 2;
      a4 += v4 + a4;
      if ( (a4 & 0x100000) != 0 )
        break;
      --v7;
    }
  }
  return result;
}

