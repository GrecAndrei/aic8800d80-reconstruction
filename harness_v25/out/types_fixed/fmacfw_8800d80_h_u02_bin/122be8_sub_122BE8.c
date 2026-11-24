// sub_122BE8 @ 0x122be8, size 472 bytes
int __fastcall sub_122BE8(int a1, int *a2, int a3, int a4)
{
  int v5; // r1
  int v6; // r4
  int v7; // r2
  int v8; // r3
  unsigned int v9; // r3
  unsigned int v10; // r0
  int v11; // r7
  __int64 v12; // r0
  int *v13; // r3
  int v15; // r3
  int v16; // r2
  int v17; // r3
  int v18; // r1
  int v19; // r6
  void *v20; // r2
  char *v21; // r0
  unsigned int v22; // r3
  __int16 v23; // [sp+Ah] [bp-92h] BYREF
  _DWORD *(_DWORD *)(v24 + 0x8); // [sp+Ch] [bp-90h] BYREF
  unsigned __int8 *(_DWORD *)(v25 + 0x220); // [sp+14h] [bp-88h] BYREF

  v23 = 0;
  v6 = sub_12C7EC(106, a4, a3, 16);
  if ( (*(_DWORD *)off_122DC0 & 0x2000000) != 0 )
  {
    sub_114728(&v23, v5, off_122DC0, HIBYTE(*(_DWORD *)off_122DC0) & 2);
    sub_114754((char *)&v23 + 1);
    msg_parse(off_122DD8[0], (unsigned __int8)v23, HIBYTE(v23), v15);
    v8 = (unsigned __int8)v23;
  }
  else
  {
    *(_DWORD *)v25 = 0;
    if ( sub_114BF4(v25) )
    {
      v8 = (unsigned __int8)v23;
    }
    else
    {
      v8 = *(_DWORD *)(v25 + 0x0);
      v7 = *(_DWORD *)(v25 + 0x4);
      v23 = *(_WORD *)v25;
    }
  }
  if ( !v8 && *((_BYTE *)a2 + 20) )
  {
    msg_parse(off_122DEC, *((unsigned __int8 *)a2 + 20), v7, 0);
    LOBYTE(v23) = *((_BYTE *)a2 + 20);
  }
  v9 = HIBYTE(v23);
  if ( HIBYTE(v23) )
  {
    v10 = (unsigned __int8)v23;
    if ( !(_BYTE)v23 )
      goto LABEL_20;
  }
  else if ( *((_BYTE *)a2 + 21) )
  {
    msg_parse(off_122DE8[0], *((unsigned __int8 *)a2 + 21), v7, HIBYTE(v23));
    v10 = (unsigned __int8)v23;
    v9 = *((unsigned __int8 *)a2 + 21);
    HIBYTE(v23) = *((_BYTE *)a2 + 21);
    if ( !(_BYTE)v23 )
      goto LABEL_19;
  }
  else
  {
    v10 = (unsigned __int8)v23;
    if ( !(_BYTE)v23 )
      goto LABEL_10;
  }
  if ( v10 > 0x1F )
    LOBYTE(v23) = 31;
  sub_10EDF8();
  msg_parse(off_122DDC, (unsigned __int8)v23, v16, v17);
  v9 = HIBYTE(v23);
LABEL_19:
  if ( !v9 )
  {
LABEL_10:
    if ( !*(_DWORD *)(a2 + 0xc) )
      goto LABEL_11;
    goto LABEL_23;
  }
LABEL_20:
  if ( v9 > 0x3F )
  {
    v18 = 63;
    HIBYTE(v23) = 63;
    v19 = 16515072;
  }
  else
  {
    v18 = HIBYTE(v23);
    v19 = (HIBYTE(v23) << 18) & 0xFC0000;
  }
  v20 = off_122DE0;
  v21 = off_122DE4[0];
  v22 = *(_DWORD *)off_122DE0 & 0xFF03FFFF | v19;
  *(_DWORD *)off_122DE0 = v22;
  msg_parse(v21, v18, v20, v22);
  if ( !*(_DWORD *)(a2 + 0xc) )
    goto LABEL_11;
LABEL_23:
  sub_10C6F0(*(_DWORD *)(a2 + 0x10));
LABEL_11:
  v11 = *a2;
  *(_DWORD *)(v24 + 0x4) = *(_DWORD *)(a2 + 0x8);
  *(_DWORD *)(v24 + 0x0) = v11;
  sub_10C4AC(0, 2437, (int)v24, (int)v25, 1u, 0);
  if ( LOBYTE((*off_122DC4)[47]) )
  {
    *(_DWORD *)(v24 + 0x0) = *(_DWORD *)(a2 + 0x4);
    sub_10C4AC(1, 5700, (int)v24, (int)v25, 1u, 0);
    sub_10C4AC(1, 5250, (int)v24, (int)v25, 1u, 0);
    sub_10C4AC(1, 5500, (int)v24, (int)v25, 1u, 0);
    sub_10C4AC(1, 5500, (int)v24, (int)v25, 0, 1u);
    sub_101EC0(0, 0x985u, 0x985u, 0, 0, 0);
  }
  LODWORD(v12) = off_122DC8[2];
  HIDWORD(v12) = (*off_122DCC[0])[0];
  v13 = (int *)off_122DD4;
  *(_DWORD *)(v6 + 12) = (*off_122DD0)[0];
  *(_QWORD *)(v6 + 4) = v12;
  *(_DWORD *)v6 = v13;
  sub_12C84C(v6);
  return 0;
}

