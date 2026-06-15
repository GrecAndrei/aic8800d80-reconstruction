// sub_125BFC @ 0x125bfc, size 258 bytes
int __fastcall sub_125BFC(int a1, unsigned __int8 **a2)
{
  int v4; // r8
  int v5; // r4
  int v6; // r5
  int v7; // r6
  BOOL v9; // r0
  BOOL v10; // r0

  v4 = (*a2)[4];
  v5 = sub_121E3C(a2[1], nullptr, 0);
  v6 = sub_121E3C(a2[2], nullptr, 0);
  if ( v6 )
  {
    if ( a1 <= 3 )
      return -1;
    v7 = sub_121E3C(a2[3], nullptr, 0);
    if ( v4 == 97 )
      goto LABEL_4;
  }
  else
  {
    v7 = 0;
    if ( v4 == 97 )
    {
LABEL_4:
      if ( v5 <= 15 )
      {
        sub_10DA88(v5);
        if ( v6 )
        {
          sub_10DAF0(v5);
          if ( v7 )
            sub_10DB04(v5);
          else
            sub_10DB18(v5);
          sub_11F504(dword_125D00, v5, v7);
          return 0;
        }
        else
        {
          sub_10DAD8(v5);
          v10 = sub_10DB30(v5);
          sub_11F504(dword_125D0C, v5, v10);
          return 0;
        }
      }
      sub_11F504(dword_125D14, v5);
      return -2;
    }
  }
  if ( v5 > 15 )
  {
    sub_11F504(dword_125D10, v5);
    return -2;
  }
  sub_10DB48(v5);
  if ( !v6 )
  {
    sub_10DB78(v5);
    v9 = sub_10DBD0(v5);
    sub_11F504(dword_125D04, v5, v9);
    return v6;
  }
  sub_10DB90(v5);
  if ( v7 )
    sub_10DBA4(v5);
  else
    sub_10DBB8(v5);
  sub_11F504(dword_125D08, v5, v7);
  return 0;
}

