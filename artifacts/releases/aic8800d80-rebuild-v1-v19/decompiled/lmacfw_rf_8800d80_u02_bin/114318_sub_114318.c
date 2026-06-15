// sub_114318 @ 0x114318, size 248 bytes
int __fastcall sub_114318(int a1, int a2, unsigned int a3)
{
  int v6; // r4
  unsigned int v7; // r5
  _DWORD v9[4]; // [sp+0h] [bp-4Ch] BYREF
  _BYTE v10[4]; // [sp+10h] [bp-3Ch] BYREF
  _BYTE v11[12]; // [sp+14h] [bp-38h] BYREF
  _BYTE v12[20]; // [sp+20h] [bp-2Ch] BYREF
  _BYTE v13[8]; // [sp+34h] [bp-18h] BYREF
  _BYTE v14[4]; // [sp+3Ch] [bp-10h] BYREF
  _BYTE v15[4]; // [sp+40h] [bp-Ch] BYREF
  _BYTE v16[8]; // [sp+44h] [bp-8h] BYREF

  if ( !*(_DWORD *)off_114410 )
    sub_1142E0();
  MEMORY[0x1D8](*(_DWORD *)off_114414 + 0x2000, 72, v9);
  if ( v9[0] != dword_114418 )
    return -1;
  v6 = a1 & v9[1];
  if ( !v6 )
    return 1;
  v7 = v6 & 1;
  if ( (v6 & 1) != 0 )
  {
    sub_1282E8(a2, v10, 4);
    v7 = 4;
    if ( (v6 & 2) == 0 )
    {
LABEL_7:
      if ( (v6 & 4) == 0 )
        goto LABEL_8;
      goto LABEL_22;
    }
  }
  else if ( (v6 & 2) == 0 )
  {
    goto LABEL_7;
  }
  sub_1282E8(a2 + v7, v11, 12);
  v7 += 12;
  if ( (v6 & 4) == 0 )
  {
LABEL_8:
    if ( (v6 & 8) == 0 )
      goto LABEL_9;
    goto LABEL_20;
  }
LABEL_22:
  sub_1282E8(a2 + v7, v12, 20);
  v7 += 20;
  if ( (v6 & 8) == 0 )
  {
LABEL_9:
    if ( (v6 & 0x20) == 0 )
      goto LABEL_10;
    goto LABEL_18;
  }
LABEL_20:
  sub_1282E8(a2 + v7, v13, 4);
  v7 += 4;
  if ( (v6 & 0x20) == 0 )
  {
LABEL_10:
    if ( (v6 & 0x40) == 0 )
      goto LABEL_11;
    goto LABEL_16;
  }
LABEL_18:
  sub_1282E8(a2 + v7, v14, 4);
  v7 += 4;
  if ( (v6 & 0x40) == 0 )
  {
LABEL_11:
    if ( (v6 & 0x80) == 0 )
      goto LABEL_12;
    goto LABEL_15;
  }
LABEL_16:
  sub_1282E8(a2 + v7, v15, 4);
  v7 += 4;
  if ( (v6 & 0x80) != 0 )
  {
LABEL_15:
    sub_1282E8(a2 + v7, v16, 4);
    v7 += 4;
  }
LABEL_12:
  if ( a3 < v7 )
    return -2;
  else
    return 0;
}

