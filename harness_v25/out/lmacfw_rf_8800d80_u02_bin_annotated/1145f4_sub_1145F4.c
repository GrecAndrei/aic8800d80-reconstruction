// fwstruct annotate: 1145f4_sub_1145F4.c
// sub_1145F4 @ 0x1145f4, size 228 bytes
int __fastcall sub_1145F4(int a1, int a2, unsigned int a3)
{
  unsigned int v6; // r4
  int v8; // [sp+0h] [bp-144h] BYREF
  int v9; // [sp+4h] [bp-140h]
  _BYTE v10[272]; // [sp+14h] [bp-130h] BYREF
  _BYTE v11[4]; // [sp+124h] [bp-20h] BYREF
  _BYTE v12[8]; // [sp+128h] [bp-1Ch] BYREF
  _BYTE v13[4]; // [sp+130h] [bp-14h] BYREF
  _BYTE v14[2]; // [sp+134h] [bp-10h] BYREF
  _BYTE v15[14]; // [sp+136h] [bp-Eh] BYREF

  if ( !*(_DWORD *)off_1146D8 )
    sub_1142E0();
  MEMORY[0x1D8](*(_DWORD *)off_1146DC + 4096, 320, &v8);
  if ( v8 != dword_1146E0 )
    return -1;
  if ( (v9 & a1) == 0 )
    return 1;
  v6 = (unsigned __int8)v9 & (unsigned __int8)a1 & 2;
  if ( ((unsigned __int8)v9 & (unsigned __int8)a1 & 2) != 0 )
  {
    sub_1282E8(a2, v10, 6);
    v6 = 6;
    if ( (a1 & 0x100000) == 0 )
    {
LABEL_7:
      if ( (a1 & 0x200000) == 0 )
        goto LABEL_8;
      goto LABEL_19;
    }
  }
  else if ( (a1 & 0x100000) == 0 )
  {
    goto LABEL_7;
  }
  sub_1282E8(a2 + v6, v11, 2);
  v6 += 2;
  if ( (a1 & 0x200000) == 0 )
  {
LABEL_8:
    if ( (a1 & 0x400000) == 0 )
      goto LABEL_9;
    goto LABEL_17;
  }
LABEL_19:
  sub_1282E8(a2 + v6, v12, 8);
  v6 += 8;
  if ( (a1 & 0x400000) == 0 )
  {
LABEL_9:
    if ( (a1 & 0x800000) == 0 )
      goto LABEL_10;
    goto LABEL_15;
  }
LABEL_17:
  sub_1282E8(a2 + v6, v13, 4);
  v6 += 4;
  if ( (a1 & 0x800000) == 0 )
  {
LABEL_10:
    if ( (a1 & 0x1000000) == 0 )
      goto LABEL_11;
    goto LABEL_14;
  }
LABEL_15:
  sub_1282E8(a2 + v6, v14, 2);
  v6 += 2;
  if ( (a1 & 0x1000000) != 0 )
  {
LABEL_14:
    sub_1282E8(a2 + v6, v15, 10);
    v6 += 10;
  }
LABEL_11:
  if ( a3 < v6 )
    return -2;
  else
    return 0;
}

