// fwstruct annotate: 1005b0_sub_1005B0.c
// sub_1005B0 @ 0x1005b0, size 132 bytes
int __fastcall sub_1005B0(int a1)
{
  unsigned int v2; // r6
  unsigned int v3; // r5
  int v4; // r7
  int v5; // r0
  int v6; // r6
  int v7; // r5

  v2 = *(_DWORD *)off_100634;
  v3 = *(_DWORD *)off_100634;
  v4 = sub_101874();
  v5 = sub_101878();
  v6 = (v2 >> 8) & 0xF;
  v7 = (v3 >> 27) & 1;
  if ( a1 == 1 )
  {
    if ( v5 )
    {
      return 11;
    }
    else if ( v6 == 1 )
    {
      return 2;
    }
    else if ( v4 )
    {
      return 9;
    }
    else
    {
      return 3;
    }
  }
  else if ( a1 == 2 )
  {
    if ( v6 == 1 )
    {
      if ( v7 )
        return 7;
      else
        return 4;
    }
    else
    {
      return v7 + 5;
    }
  }
  else if ( a1 )
  {
    if ( **(__int16 **)off_100638 < 0 )
      sub_12F694(dword_100640, dword_10063C, 434);
    return 0;
  }
  else if ( v5 )
  {
    return 10;
  }
  else if ( v7 )
  {
    return 8;
  }
  else
  {
    return v6 != 1;
  }
}

