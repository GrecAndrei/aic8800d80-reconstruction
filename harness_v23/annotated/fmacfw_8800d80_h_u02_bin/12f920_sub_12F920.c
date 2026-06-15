// v23 annotated: sub_12F920 @ 0x12f920
// Original: 12f920_sub_12F920.c
// Primary struct: <unclustered>
//
// sub_12F920 @ 0x12f920, size 212 bytes
int __fastcall sub_12F920(int a1, int a2)
{
  unsigned int v4; // r5
  int v5; // r0
  int v7; // r3
  int v8; // r0
  int v9; // [sp+4h] [bp-4h]

  v4 = sub_12F818(*(unsigned __int8 **)(a2 + 4), nullptr, 0x10u);
  if ( a1 <= 2 )
  {
    v5 = sub_12F8EC(*(_DWORD *)a2);
    if ( v5 >= 0 )
      goto LABEL_3;
LABEL_18:
    sub_10DAE4(dword_12FA04, v5);
    return -1;
  }
  v9 = sub_12F818(*(unsigned __int8 **)(a2 + 8), nullptr, 0);
  v5 = sub_12F8EC(*(_DWORD *)a2);
  if ( v5 < 0 )
    goto LABEL_18;
  if ( v9 == 1 )
  {
LABEL_3:
    if ( ((v4 >> 20) & 0xFFFFFDFF) == 0x500 )
    {
      v8 = sub_10EC2C();
      sub_10DAE4(dword_12F9F4, v4 & 0xFFFFFFFC, v8);
      return 0;
    }
    else if ( v5 == 4 )
    {
      sub_10DAE4(dword_12F9F8, v4, *(_DWORD *)v4);
      return 0;
    }
    else if ( v5 == 2 )
    {
      sub_10DAE4(dword_12F9FC, v4, *(unsigned __int16 *)v4);
      return 0;
    }
    else
    {
      if ( v5 == 1 )
        sub_10DAE4(dword_12FA00, v4, *(unsigned __int8 *)v4);
      return 0;
    }
  }
  v7 = **(_BYTE **)a2 == 82 && v4 < 0x40000000;
  sub_12E9D8(v4, v9, (unsigned __int8)v5, v7);
  return 0;
}

