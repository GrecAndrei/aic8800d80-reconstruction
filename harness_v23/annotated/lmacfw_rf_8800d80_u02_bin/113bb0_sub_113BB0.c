// v23 annotated: sub_113BB0 @ 0x113bb0
// Original: 113bb0_sub_113BB0.c
// Primary struct: <unclustered>
//
// sub_113BB0 @ 0x113bb0, size 54 bytes
int __fastcall sub_113BB0(int a1)
{
  __int16 v2; // r0
  char v3; // r1
  int v4; // r5

  v2 = sub_113A44(6u);
  v3 = v2;
  if ( !(_BYTE)v2 )
  {
    v4 = 1;
LABEL_3:
    sub_113AD0(6u, a1 << v3);
    return v4;
  }
  v4 = HIBYTE(v2);
  if ( (v2 & 0xFF00) == 0 )
  {
    v3 = 8;
    goto LABEL_3;
  }
  return -1;
}

