// fwstruct annotate: 122be8_sub_122BE8.c
// sub_122BE8 @ 0x122be8, size 472 bytes
void __fastcall __noreturn sub_122BE8(int a1, int *a2, int a3, int a4)
{
  int v5; // r2
  int v6; // r3
  unsigned int v7; // r3
  unsigned int v8; // r0
  int v9; // r7
  int v10; // r2
  int v11; // r1
  int v12; // r6
  void *v13; // r2
  int v14; // r0
  __int16 v15; // [sp+Ah] [bp-92h] BYREF
  int v16; // [sp+Ch] [bp-90h]
  int v17; // [sp+10h] [bp-8Ch]
  int v18; // [sp+14h] [bp-88h] BYREF

  sub_12C7EC(106, a4, a3, 16);
  v15 = 0;
  if ( (*(_DWORD *)off_122DC0 & 0x2000000) != 0 )
  {
    sub_114728(&v15);
    sub_114754((_BYTE *)&v15 + 1);
    sub_12E948(dword_122DD8, (unsigned __int8)v15, HIBYTE(v15));
    v6 = (unsigned __int8)v15;
  }
  else
  {
    v18 = 0;
    if ( sub_114BF4((int)&v18) )
    {
      v6 = (unsigned __int8)v15;
    }
    else
    {
      v6 = (unsigned __int8)v18;
      v5 = BYTE1(v18);
      v15 = v18;
    }
  }
  if ( !v6 && *((_BYTE *)a2 + 20) )
  {
    sub_12E948(dword_122DEC, *((unsigned __int8 *)a2 + 20), v5);
    LOBYTE(v15) = *((_BYTE *)a2 + 20);
  }
  v7 = HIBYTE(v15);
  if ( HIBYTE(v15) )
  {
    v8 = (unsigned __int8)v15;
    if ( !(_BYTE)v15 )
      goto LABEL_18;
  }
  else if ( *((_BYTE *)a2 + 21) )
  {
    sub_12E948(dword_122DE8, *((unsigned __int8 *)a2 + 21), v5);
    v8 = (unsigned __int8)v15;
    v7 = *((unsigned __int8 *)a2 + 21);
    HIBYTE(v15) = *((_BYTE *)a2 + 21);
    if ( !(_BYTE)v15 )
      goto LABEL_17;
  }
  else
  {
    v8 = (unsigned __int8)v15;
    if ( !(_BYTE)v15 )
      goto LABEL_10;
  }
  if ( v8 > 0x1F )
  {
    v8 = 31;
    LOBYTE(v15) = 31;
  }
  sub_10EDF8(v8);
  sub_12E948(dword_122DDC, (unsigned __int8)v15, v10);
  v7 = HIBYTE(v15);
LABEL_17:
  if ( !v7 )
  {
LABEL_10:
    if ( !a2[3] )
      goto LABEL_11;
    goto LABEL_21;
  }
LABEL_18:
  if ( v7 > 0x3F )
  {
    v11 = 63;
    HIBYTE(v15) = 63;
    v12 = 16515072;
  }
  else
  {
    v11 = HIBYTE(v15);
    v12 = (HIBYTE(v15) << 18) & 0xFC0000;
  }
  v13 = off_122DE0;
  v14 = dword_122DE4;
  *(_DWORD *)off_122DE0 = *(_DWORD *)off_122DE0 & 0xFF03FFFF | v12;
  sub_12E948(v14, v11, v13);
  if ( !a2[3] )
  {
LABEL_11:
    v9 = *a2;
    v17 = a2[2];
    v16 = v9;
    sub_10C4AC(0, 2437);
  }
LABEL_21:
  sub_10C6F0();
  goto LABEL_11;
}

