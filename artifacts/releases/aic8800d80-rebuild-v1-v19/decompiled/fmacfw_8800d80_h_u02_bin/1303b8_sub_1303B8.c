// sub_1303B8 @ 0x1303b8, size 174 bytes
void sub_1303B8()
{
  _BYTE *v0; // r4
  int v1; // r2
  int v2; // r3
  unsigned int v3; // r3
  char v4; // r0
  int v5; // r1
  char v6; // r3
  int v7; // r0
  unsigned __int8 v8; // [sp+3h] [bp-Dh] BYREF
  int v9; // [sp+4h] [bp-Ch] BYREF
  int v10; // [sp+8h] [bp-8h] BYREF
  int v11; // [sp+Ch] [bp-4h] BYREF

  v0 = off_130468;
  v1 = *(char *)off_130468;
  if ( *(_BYTE *)off_130468 )
    return;
  v8 = *(_BYTE *)off_130468;
  v2 = *(_DWORD *)off_13046C;
  v9 = v1;
  if ( (v2 & 0x2000000) != 0 )
  {
    sub_114728(&v8);
    sub_11498C(&v9);
    goto LABEL_4;
  }
  v10 = 0;
  v11 = 0;
  if ( !sub_114BF4((int)&v10) )
    v8 = v10;
  if ( sub_114C24((int)&v11) )
  {
LABEL_4:
    v3 = v8;
    if ( v8 )
      goto LABEL_5;
    goto LABEL_19;
  }
  v9 = (char)v11;
  v3 = v8;
  if ( v8 )
  {
LABEL_5:
    if ( v3 > 0x1F )
    {
      LOBYTE(v3) = 31;
      v8 = 31;
    }
    goto LABEL_7;
  }
LABEL_19:
  LOBYTE(v3) = 15;
LABEL_7:
  v0[4] = v3;
  v4 = sub_10EDE4();
  v5 = v9;
  v0[6] = v4;
  if ( v5 )
  {
    if ( v5 < -7 )
    {
      v6 = -7;
      v9 = -7;
      v5 = -7;
    }
    else if ( v5 > 8 )
    {
      v6 = 8;
      v9 = 8;
      v5 = 8;
    }
    else
    {
      v6 = v5;
    }
    v7 = dword_130470;
    v0[2] = v6;
    sub_12E948(v7, v5);
  }
  v0[3] = 0x80;
  *v0 = 1;
}

