// mmio_ahb_gate_release_n_60 @ 0x101260, size 1142 bytes
// Doc: mmio_ahb_gate_release_n_60 [mmio]: Release AHB clock gate and clear bit in MMIO control register
// mmio_ahb_gate_release_n_60 [mmio]: Release AHB clock gate and clear bit in MMIO control register
_DWORD *__fastcall mmio_ahb_gate_release_n_60(unsigned int a1)
{
  _DWORD *v1; // r2
  _DWORD *v2; // r3
  _DWORD *v3; // r5
  _DWORD *v4; // r4
  unsigned int *v5; // r6
  _DWORD *v6; // r1
  unsigned int *v7; // r5
  unsigned int *v8; // r3
  _DWORD *v9; // r4
  unsigned int v10; // r12
  int *v12; // r0
  int v13; // r3
  int *v14; // r8
  int *v15; // r7
  int v16; // r1
  int v17; // r2
  unsigned int v18; // lr
  int v19; // r10
  int v20; // r1
  unsigned int *v21; // r2
  unsigned int v22; // r0
  __int64 v23; // r4
  _DWORD *v24; // r3
  unsigned int *v25; // r2
  int v26; // r2
  int v27; // r1
  int v28; // r5
  int v29; // r3
  int v30; // r2
  unsigned int *v31; // r0
  _BYTE *v32; // r4
  _DWORD *v33; // r2
  _DWORD *v34; // r0
  unsigned int v35; // r3
  unsigned int *v36; // r2
  unsigned int *v37; // r1
  __int64 *v38; // r3
  __int64 v39; // r0
  int v40; // r5
  _BYTE *v41; // r4
  _DWORD *v42; // r2
  _DWORD *result; // r0
  __int64 *v44; // r3
  __int64 v45; // r0
  __int64 v46; // r0
  int v47; // r2
  int v48; // r2

  v1 = off_1014EC;
  v2 = off_1014F0;
  *(_DWORD *)off_1014EC &= ~0x400u;
  v3 = off_1014F4;
  v4 = off_1014F8;
  v5 = (unsigned int *)off_1014FC;
  *v1 &= ~0x800u;
  *v3 |= 4u;
  v6 = off_101500;
  *v4 |= 0x80000u;
  *v4 &= ~0x100000u;
  *v2 |= 0x400u;
  *v2 &= ~0x100u;
  *v2 |= 0x80u;
  v7 = (unsigned int *)off_101504;
  v1[16] |= 0x8000u;
  *v6 |= 1u;
  *v6 &= ~2u;
  v4[4] |= 0x40u;
  *v7 = *v7 & 0xFFC01FFF | 0x32000;
  v4[24] &= ~0x8000u;
  v4[24] |= 0x4000u;
  *v5 = *v5 & 0xFFF9FFFF | 0x20000;
  *(unsigned int *)((char *)v7 + 0xFFFFFFC0) = *(unsigned int *)((char *)v7 + 0xFFFFFFC0) & 0xFFFFE3FF | 0x800;
  v4[7] = v4[7] & 0xFC7FFFFF | 0x1000000;
  v8 = (unsigned int *)off_101508;
  *(unsigned int *)((char *)v7 + 0xFFFFFFBC) &= 0xFFFFC7FF;
  *v8 = *v8 & 0xFFFFF83F | 0x400;
  v1[16] = v1[16] & 0xFFFFE3FF | 0x1000;
  *v6 |= 0xC00u;
  v9 = off_10150C;
  v1[16] = v1[16] & 0xFFFFFF87 | 0x48;
  v7 -= 1921;
  *v8 &= ~1u;
  *v7 |= 8u;
  *v7 |= 4u;
  *v8 &= ~2u;
  *v9 &= ~0x20000u;
  v10 = (unsigned __int16)(a1 - 5000);
  *v8 |= 0x20u;
  if ( v10 > 0xFA )
  {
    if ( a1 > 0x14C8 )
    {
      if ( a1 <= 0x15C2 )
      {
        v14 = (int *)off_101750;
        v15 = (int *)off_101738;
        v13 = dword_10173C;
        v16 = dword_101740;
        v47 = dword_101744;
        *(_DWORD *)off_101734 = dword_10173C;
        *v14 = v47;
        *v15 = v16;
        v18 = 0x80000000;
        v19 = 1610612736;
        goto LABEL_4;
      }
      if ( a1 <= 0x1612 )
      {
        v14 = (int *)off_101544;
        v15 = (int *)off_101518;
        v13 = dword_101538;
        v16 = dword_10153C;
        v30 = dword_101540;
        *(_DWORD *)off_101510 = dword_101538;
        *v14 = v30;
        *v15 = v16;
        v18 = 0;
        v19 = 1610612736;
        goto LABEL_4;
      }
      v12 = (int *)off_101734;
      v13 = dword_10173C;
      v14 = (int *)off_101750;
      v15 = (int *)off_101738;
      v16 = dword_101740;
      if ( a1 <= 0x1662 )
      {
        v48 = dword_101748;
        *(_DWORD *)off_101734 = dword_10173C;
        *v14 = v48;
        *v15 = v16;
        v18 = 0;
        v19 = 0x40000000;
        goto LABEL_4;
      }
      v17 = dword_10174C;
    }
    else
    {
      v12 = (int *)off_101510;
      v13 = dword_101514;
      v14 = (int *)off_101544;
      v15 = (int *)off_101518;
      v16 = dword_10151C;
      v17 = dword_101534;
    }
  }
  else
  {
    v12 = (int *)off_101510;
    v13 = dword_101514;
    v14 = (int *)off_101544;
    v15 = (int *)off_101518;
    v16 = dword_10151C;
    v17 = dword_101520;
  }
  *v12 = v13;
  v18 = 0;
  *v14 = v17;
  *v15 = v16;
  v19 = 0;
LABEL_4:
  v20 = v16 + 4;
  v21 = (unsigned int *)v13;
  do
  {
    if ( v10 > 0x140 )
    {
      v22 = v21[1] & 0xFFFFFFFE;
      *v21 = *v21 & 0x1FFFFFFF | v19 | v18;
      v21[1] = v22;
      v23 = *(_QWORD *)(v20 - 4);
      LODWORD(v23) = v23 & 0x1FFFFFFF | v19 | v18;
      HIDWORD(v23) &= ~1u;
      *(_QWORD *)(v20 - 4) = v23;
    }
    v21 += 3;
    v20 += 12;
  }
  while ( (unsigned int *)(v13 + 192) != v21 );
  sub_102EB8(1, 0, 16, v13);
  sub_102EB8(1, 16, 16, *v14);
  sub_102EB8(1, 32, 16, *v15);
  sub_1009A0(1, a1);
  v24 = off_101524;
  v25 = (unsigned int *)off_101528;
  *(_DWORD *)off_101524 |= 8u;
  *v24 |= 4u;
  *v25 = *v25 & 0xFFFC7FFF | 0x10000;
  *v25 = *v25 & 0xFFFF8FFF | 0x3000;
  if ( a1 > 0x1666 )
  {
    v28 = 10;
    v27 = 5;
  }
  else if ( a1 > 0x1616 )
  {
    v28 = 8;
    v27 = 4;
  }
  else if ( a1 > 0x15C6 )
  {
    v28 = 6;
    v27 = 3;
  }
  else
  {
    if ( a1 <= 0x1571 )
    {
      v26 = *(unsigned __int8 *)off_10152C;
      v27 = a1 > 0x1486;
      if ( a1 <= 0x1486 )
        v28 = 0;
      else
        v28 = 2;
      if ( v26 == 3 )
        goto LABEL_16;
      goto LABEL_24;
    }
    v28 = 4;
    v27 = 2;
  }
  v26 = *(unsigned __int8 *)off_1016D8;
  if ( v26 == 3 )
  {
LABEL_16:
    v29 = dword_101530;
    goto LABEL_26;
  }
LABEL_24:
  v29 = dword_1016DC;
  if ( v26 != 7 )
    v29 = 0;
LABEL_26:
  v31 = (unsigned int *)off_1016E4;
  *(_DWORD *)off_1016E0 = *(_DWORD *)off_1016E0 & 0xFFFFFF00 | *(unsigned __int8 *)(v29 + v28);
  v32 = off_1016E8;
  *v31 = *v31 & 0xFFFFFF00 | *(unsigned __int8 *)(v29 + v28 + 1);
  if ( !v32[1] )
  {
    v33 = off_1016EC;
    v31[1918] &= 0xFFFFFC7F;
    *v33 &= ~0x8000u;
  }
  v34 = off_1016F4;
  v35 = *(_DWORD *)off_1016F0 & 0xFF00FFFF;
  if ( v27 <= 1 )
    v35 |= 0x1F0000u;
  *(_DWORD *)off_1016F0 = v35;
  v36 = (unsigned int *)off_1016F8;
  v37 = (unsigned int *)off_1016FC;
  *v34 &= ~0x4000u;
  *v36 = *v36 & 0xFFF8FFFF | 0x20000;
  *v36 = *v36 & 0xFFFFFFF0 | 8;
  *v37 = *v37 & 0xFFF1FFFF | 0x60000;
  if ( a1 <= 0x15E4 )
  {
    v44 = (__int64 *)off_101700;
    if ( a1 <= 0x14D6 )
    {
      v46 = qword_101728;
      *((_DWORD *)off_101700 + 2) = dword_101730;
      *v44 = v46;
      v40 = 0;
    }
    else
    {
      v45 = qword_10171C;
      *((_DWORD *)off_101700 + 2) = dword_101724;
      *v44 = v45;
      v40 = 1;
    }
  }
  else
  {
    v38 = (__int64 *)off_101700;
    v39 = qword_101704;
    *((_DWORD *)off_101700 + 2) = dword_10170C;
    *v38 = v39;
    v40 = 2;
  }
  v41 = off_101710;
  if ( *(unsigned __int8 *)off_101710 != v40 )
    ipc_msg_dispatch(0);
  v42 = off_101714;
  *v41 = v40;
  while ( !*v42 )
    ;
  result = (_DWORD *)(*(_DWORD *)off_101718 & 1);
  if ( result )
    goto LABEL_40;
  if ( a1 - 5270 <= 0x32 || a1 - 5550 <= 0x64 )
  {
    result = mmio_regs_poll_1200ee8();
LABEL_40:
    *(_DWORD *)off_101714 = 1;
    return result;
  }
  result = (_DWORD *)message_dispatch_n244(0);
  *(_DWORD *)off_101714 = 1;
  return result;
}

