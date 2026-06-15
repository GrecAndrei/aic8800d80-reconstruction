// sub_12FC7C @ 0x12fc7c, size 212 bytes
int __fastcall sub_12FC7C(int a1, int a2)
{
  unsigned int v4; // r5
  int v5; // r0
  int v7; // r3
  int v8; // r0
  int v9; // [sp+4h] [bp-4h]

  v4 = sub_12FB74(*(unsigned __int8 **)(a2 + 4), nullptr, 0x10u);
  if ( a1 <= 2 )
  {
    v5 = sub_12FC48(*(_DWORD *)a2);
    if ( v5 >= 0 )
      goto LABEL_3;
LABEL_18:
    sub_10DA7C(dword_12FD60, v5);
    return -1;
  }
  v9 = sub_12FB74(*(unsigned __int8 **)(a2 + 8), nullptr, 0);
  v5 = sub_12FC48(*(_DWORD *)a2);
  if ( v5 < 0 )
    goto LABEL_18;
  if ( v9 == 1 )
  {
LABEL_3:
    if ( ((v4 >> 20) & 0xFFFFFDFF) == 0x500 )
    {
      v8 = sub_10EBC4();
      sub_10DA7C(dword_12FD50, v4 & 0xFFFFFFFC, v8);
      return 0;
    }
    else if ( v5 == 4 )
    {
      sub_10DA7C(dword_12FD54, v4, *(_DWORD *)v4);
      return 0;
    }
    else if ( v5 == 2 )
    {
      sub_10DA7C(dword_12FD58, v4, *(unsigned __int16 *)v4);
      return 0;
    }
    else
    {
      if ( v5 == 1 )
        sub_10DA7C(dword_12FD5C, v4, *(unsigned __int8 *)v4);
      return 0;
    }
  }
  v7 = **(_BYTE **)a2 == 82 && v4 < 0x40000000;
  sub_12ED40(v4, v9, (unsigned __int8)v5, v7);
  return 0;
}

