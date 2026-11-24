// sub_122F5C @ 0x122f5c, size 472 bytes
void __fastcall sub_122F5C(int a1, int *a2, int a3, int a4)
{
  int v5; // r4
  int v6; // r3
  unsigned int v7; // r3
  unsigned int v8; // r0
  int v9; // r7
  __int64 v10; // r0
  int v11; // r3
  int v12; // r6
  int v13; // r0
  __int16 v14; // [sp+Ah] [bp-92h] BYREF
  int v15; // [sp+Ch] [bp-90h]
  int v16; // [sp+10h] [bp-8Ch]
  _DWORD *(_DWORD *)(v17 + 0x88); // [sp+14h] [bp-88h] BYREF

  v14 = 0;
  v5 = rf_bus_setup_n3a8(106, a4, a3, 0x10u);
  if ( (*(_DWORD *)off_123134 & 0x2000000) != 0 )
  {
    sub_114EA4(&v14);
    sub_114ED0((_BYTE *)&v14 + 1);
    sub_12ECB0(dword_12314C, (unsigned __int8)v14, HIBYTE(v14));
    v6 = (unsigned __int8)v14;
  }
  else
  {
    *(_DWORD *)(v17 + 0x0) = 0;
    if ( sub_115370((int)v17) )
    {
      v6 = (unsigned __int8)v14;
    }
    else
    {
      v6 = LOBYTE(*(_DWORD *)(v17 + 0x0));
      v14 = *(_DWORD *)(v17 + 0x0);
    }
  }
  if ( !v6 && *((_BYTE *)a2 + 20) )
  {
    sub_12ECB0(dword_123160);
    LOBYTE(v14) = *((_BYTE *)a2 + 20);
  }
  v7 = HIBYTE(v14);
  if ( HIBYTE(v14) )
  {
    v8 = (unsigned __int8)v14;
    if ( !(_BYTE)v14 )
      goto LABEL_20;
  }
  else if ( *((_BYTE *)a2 + 21) )
  {
    sub_12ECB0(dword_12315C);
    v8 = (unsigned __int8)v14;
    v7 = *((unsigned __int8 *)a2 + 21);
    HIBYTE(v14) = *((_BYTE *)a2 + 21);
    if ( !(_BYTE)v14 )
      goto LABEL_19;
  }
  else
  {
    v8 = (unsigned __int8)v14;
    if ( !(_BYTE)v14 )
      goto LABEL_10;
  }
  if ( v8 > 0x1F )
  {
    v8 = 31;
    LOBYTE(v14) = 31;
  }
  sub_10ED90(v8);
  sub_12ECB0(dword_123150, (unsigned __int8)v14);
  v7 = HIBYTE(v14);
LABEL_19:
  if ( !v7 )
  {
LABEL_10:
    if ( !*(_DWORD *)(a2 + 0xc) )
      goto LABEL_11;
    goto LABEL_23;
  }
LABEL_20:
  if ( v7 > 0x3F )
  {
    HIBYTE(v14) = 63;
    v12 = 16515072;
  }
  else
  {
    v12 = (HIBYTE(v14) << 18) & 0xFC0000;
  }
  v13 = dword_123158;
  *(_DWORD *)off_123154 = *(_DWORD *)off_123154 & 0xFF03FFFF | v12;
  sub_12ECB0(v13);
  if ( !*(_DWORD *)(a2 + 0xc) )
    goto LABEL_11;
LABEL_23:
  sub_10C688();
LABEL_11:
  v9 = *a2;
  v16 = *(_DWORD *)(a2 + 0x8);
  v15 = v9;
  tx_phy_dispatch(0, 2437);
  if ( *((_BYTE *)off_123138 + 188) )
  {
    v15 = *(_DWORD *)(a2 + 0x4);
    tx_phy_dispatch(1, 5700);
    tx_phy_dispatch(1, 5250);
    tx_phy_dispatch(1, 5500);
    tx_phy_dispatch(1, 5500);
    sub_101DE8(0, 2437, 2437, 0, 0, 0);
  }
  LODWORD(v10) = *((_DWORD *)off_12313C + 2);
  HIDWORD(v10) = *(_DWORD *)off_123140;
  v11 = dword_123148;
  *(_DWORD *)(v5 + 12) = *(_DWORD *)off_123144;
  *(_QWORD *)(v5 + 4) = v10;
  *(_DWORD *)v5 = v11;
  sub_12CBB4(v5);
}
