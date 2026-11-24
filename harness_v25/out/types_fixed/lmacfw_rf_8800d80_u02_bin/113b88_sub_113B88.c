// sub_113B88 @ 0x113b88, size 40 bytes
int __fastcall sub_113B88(_BYTE *a1)
{
  __int16 v2; // r0

  v2 = sub_113A44(6u);
  if ( (v2 & 0xFF00) != 0 )
  {
    *a1 = HIBYTE(v2);
    return 0;
  }
  else
  {
    *a1 = v2;
    if ( (_BYTE)v2 )
      return 1;
    else
      return 2;
  }
}

