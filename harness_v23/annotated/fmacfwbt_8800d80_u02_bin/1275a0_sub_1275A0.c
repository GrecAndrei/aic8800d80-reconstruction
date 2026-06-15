// v23 annotated: sub_1275A0 @ 0x1275a0
// Original: 1275a0_sub_1275A0.c
// Primary struct: <unclustered>
//
// sub_1275A0 @ 0x1275a0, size 670 bytes
int __fastcall sub_1275A0(int a1, int a2)
{
  _BYTE *v2; // r4
  _DWORD *v5; // r2
  _DWORD *v6; // r7
  int v7; // r1
  int result; // r0
  unsigned int v9; // r3
  int *v10; // r3
  int v11; // r3
  int v12; // r3
  bool v13; // zf
  int v14; // r3
  char v15; // r8
  int v16; // r3
  int v17; // r2
  int v18; // r1
  _WORD *v19; // r8
  _WORD *v20; // r0
  _WORD *v21; // r7
  int v22; // r0
  int v23; // r2
  unsigned int *v24; // r12
  _DWORD *v25; // r1
  char v26; // r3
  _DWORD *v27; // r7
  int v28; // r2
  unsigned int v29; // r3
  int v30; // r3
  _BYTE *v31; // r9
  int v32; // r7
  unsigned int v33; // r3
  int v34; // lr
  char *v35; // r2
  unsigned int v36; // r10
  _DWORD *v37; // r7
  int v38; // r2
  void *v39; // r2
  int v40; // r1
  int v41; // r0
  _DWORD *v42; // r7
  int v43; // r2

  v2 = off_127840;
  *((_DWORD *)off_127840 + 10) = 0;
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)off_127844 = 1;
  }
  v5 = off_127848;
  v6 = off_12784C;
  v7 = *(_DWORD *)off_127848;
  result = *(_DWORD *)off_127848 + 1;
  v9 = *((_DWORD *)off_12784C + 1) & 0xFFFFFFFD;
  *(_DWORD *)off_127848 = result;
  v6[1] = v9;
  if ( result )
  {
    v10 = (int *)off_127844;
    *v5 = v7;
    v11 = *v10;
    if ( !v7 )
    {
      if ( v11 )
        __enable_irq();
    }
  }
  *(_DWORD *)off_127850 = (4 * (unsigned __int8)v2[92]) & 4 | *(_DWORD *)off_127850 & 0xFFFFFFFB;
  if ( a2 )
    goto LABEL_6;
  result = fw_init_or_check_1221d44();
  if ( !*((_BYTE *)off_127854 + 408) )
    goto LABEL_6;
  v12 = *(unsigned __int8 *)(a1 + 24);
  if ( v12 != 3 )
  {
LABEL_7:
    v13 = v12 == 4;
    v14 = (unsigned __int8)v2[88];
    if ( v13 )
    {
      v2[88] = v14 & 0xFB;
      if ( *(_WORD *)(a1 + 14) )
      {
        result = phy_init_or_register_n_e(a1);
        v14 = (unsigned __int8)v2[88];
      }
      else
      {
        v14 &= 0xDBu;
      }
    }
    goto LABEL_8;
  }
  v15 = *((_BYTE *)off_127858 + 3850);
  if ( v15 || *((unsigned __int8 *)off_12785C + 10) + 1 != *(unsigned __int8 *)(*(_DWORD *)off_12785C + 367) )
    goto LABEL_23;
  v16 = *(_DWORD *)off_127858;
  if ( *(_BYTE *)(*(_DWORD *)off_127858 + 367) )
  {
    v17 = 0;
    do
    {
      v18 = *(unsigned __int8 *)(v16 + 2);
      ++v17;
      v16 += 6;
      if ( v18 == *((unsigned __int8 *)off_127858 + 3851) + 1 )
        goto LABEL_23;
    }
    while ( v17 != *(unsigned __int8 *)(*(_DWORD *)off_127858 + 367) );
  }
  v31 = off_127888;
  if ( *((unsigned __int16 *)off_127888 + 2) <= 1u && *((unsigned __int16 *)off_127888 + 3) <= 1u )
  {
LABEL_50:
    v42 = off_12786C;
    v43 = **(__int16 **)off_127868;
    *((_DWORD *)off_12786C + 1) |= 0x100040u;
    if ( v43 < 0 && *(_DWORD *)off_127874 << 28 )
      sub_12F6C4(dword_12787C, dword_127878, 472);
    v39 = off_127870;
    v40 = 1;
    *(_DWORD *)off_127870 = *v42 | v42[1];
    v15 = 1;
    goto LABEL_48;
  }
  v32 = 0;
  while ( !*((_WORD *)off_127858 + 2) )
  {
LABEL_44:
    if ( v32 )
      goto LABEL_50;
    v32 = 1;
  }
  v33 = 0;
  v34 = 0;
  while ( 1 )
  {
    v35 = (char *)off_127858 + 60 * v33;
    v36 = (unsigned __int8)(v33 + 1);
    v33 = v36;
    if ( *(unsigned __int8 *)(*((_DWORD *)v35 + 13) + 2) != v32 || !v35[16] || v35[64] < -79 )
      goto LABEL_38;
    if ( v34 )
      break;
    v34 = 1;
LABEL_38:
    if ( v36 >= *((unsigned __int16 *)off_127858 + 2) )
      goto LABEL_44;
  }
  v37 = off_12786C;
  v38 = **(__int16 **)off_127868;
  *((_DWORD *)off_12786C + 1) &= 0xFFEFFFBF;
  if ( v38 < 0 && *(_DWORD *)off_127874 << 28 )
    sub_12F6C4(dword_12787C, dword_127878, 472);
  v39 = off_127870;
  *(_DWORD *)off_127870 = *v37 | v37[1];
  v40 = 0;
LABEL_48:
  v41 = dword_127880;
  v31[8] = v15;
  result = sub_12ECB0(v41, v40, v39);
LABEL_6:
  v12 = *(unsigned __int8 *)(a1 + 24);
  if ( v12 != 3 )
    goto LABEL_7;
LABEL_23:
  v2[88] &= ~8u;
  v19 = (_WORD *)phy_chan_idx_calc();
  v20 = (_WORD *)rf_bus_setup_n3a8(79, 13, 0, 12);
  *v20 = *v19;
  v21 = v20;
  v22 = sub_12B74C(v19);
  v23 = dword_127860;
  v24 = (unsigned int *)off_127884;
  v25 = off_127864;
  *((_DWORD *)v21 + 1) = (unsigned int)(((unsigned int)dword_127860 * (unsigned __int64)(unsigned int)v22) >> 32) >> 6;
  *((_DWORD *)v21 + 2) = (unsigned int)(((unsigned int)v23 * (unsigned __int64)*v24) >> 32) >> 6;
  *((_BYTE *)v21 + 2) = 0;
  v26 = 10;
  while ( 1 )
  {
    --v26;
    if ( (unsigned __int8)*v25 )
      break;
    if ( !v26 )
      goto LABEL_26;
  }
  *((_BYTE *)v21 + 2) = *v25;
LABEL_26:
  sub_12CBB4(v21);
  v27 = off_12786C;
  v28 = **(__int16 **)off_127868;
  v29 = *((_DWORD *)off_12786C + 1) & 0xFFFFDDFF;
  *((_DWORD *)off_12786C + 1) = v29;
  if ( v28 < 0 && *(_DWORD *)off_127874 << 28 )
  {
    sub_12F6C4(dword_12787C, dword_127878, 472);
    v29 = v27[1];
  }
  v30 = v29 | *v27;
  *(_DWORD *)off_127870 = v30;
  result = message_dispatch_n84(142, 2, 255, v30);
  v14 = (unsigned __int8)v2[88];
LABEL_8:
  *(_BYTE *)(a1 + 24) = -1;
  v2[88] = v14 & 0xEF;
  if ( !(v14 << 30) )
  {
    if ( a2 )
      return result;
    return sub_121CD4();
  }
  result = sub_127568();
  if ( !a2 )
    return sub_121CD4();
  return result;
}

