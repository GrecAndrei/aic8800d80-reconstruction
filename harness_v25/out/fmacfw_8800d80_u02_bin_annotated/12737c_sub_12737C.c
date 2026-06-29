// fwstruct annotate: 12737c_sub_12737C.c
// sub_12737C @ 0x12737c, size 670 bytes
// Doc: sub_122737C [unknown]: unknown FMAC routine at 0x122737c
// sub_122737C [unknown]: unknown FMAC routine at 0x122737c
int __fastcall sub_12737C(int a1, int a2)
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
  _BYTE *v30; // r9
  int v31; // r7
  unsigned int v32; // r3
  int v33; // lr
  char *v34; // r2
  unsigned int v35; // r10
  _DWORD *v36; // r7
  int v37; // r2
  void *v38; // r2
  int v39; // r1
  int v40; // r0
  _DWORD *v41; // r7
  int v42; // r2

  v2 = off_12761C;
  *((_DWORD *)off_12761C + 10) = 0;
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)off_127620 = 1;
  }
  v5 = off_127624;
  v6 = off_127628;
  v7 = *(_DWORD *)off_127624;
  result = *(_DWORD *)off_127624 + 1;
  v9 = *((_DWORD *)off_127628 + 1) & 0xFFFFFFFD;
  *(_DWORD *)off_127624 = result;
  v6[1] = v9;
  if ( result )
  {
    v10 = (int *)off_127620;
    *v5 = v7;
    v11 = *v10;
    if ( !v7 )
    {
      if ( v11 )
        __enable_irq();
    }
  }
  *(_DWORD *)off_12762C = (4 * (unsigned __int8)v2[92]) & 4 | *(_DWORD *)off_12762C & 0xFFFFFFFB;
  if ( a2 )
    goto LABEL_6;
  result = sub_121AE4();
  if ( !*((_BYTE *)off_127630 + 408) )
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
        result = sub_125D98(a1);
        v14 = (unsigned __int8)v2[88];
      }
      else
      {
        v14 &= 0xDBu;
      }
    }
    goto LABEL_8;
  }
  v15 = *((_BYTE *)off_127634 + 3850);
  if ( v15 || *((unsigned __int8 *)off_127638 + 10) + 1 != *(unsigned __int8 *)(*(_DWORD *)off_127638 + 367) )
    goto LABEL_23;
  v16 = *(_DWORD *)off_127634;
  if ( *(_BYTE *)(*(_DWORD *)off_127634 + 367) )
  {
    v17 = 0;
    do
    {
      v18 = *(unsigned __int8 *)(v16 + 2);
      ++v17;
      v16 += 6;
      if ( v18 == *((unsigned __int8 *)off_127634 + 3851) + 1 )
        goto LABEL_23;
    }
    while ( v17 != *(unsigned __int8 *)(*(_DWORD *)off_127634 + 367) );
  }
  v30 = off_127664;
  if ( *((unsigned __int16 *)off_127664 + 2) <= 1u && *((unsigned __int16 *)off_127664 + 3) <= 1u )
  {
LABEL_50:
    v41 = off_127648;
    v42 = **(__int16 **)off_127644;
    *((_DWORD *)off_127648 + 1) |= 0x100040u;
    if ( v42 < 0 && *(_DWORD *)off_127650 << 28 )
      sub_12F49C(dword_127658, dword_127654, 472);
    v38 = off_12764C;
    v39 = 1;
    *(_DWORD *)off_12764C = *v41 | v41[1];
    v15 = 1;
    goto LABEL_48;
  }
  v31 = 0;
  while ( !*((_WORD *)off_127634 + 2) )
  {
LABEL_44:
    if ( v31 )
      goto LABEL_50;
    v31 = 1;
  }
  v32 = 0;
  v33 = 0;
  while ( 1 )
  {
    v34 = (char *)off_127634 + 60 * v32;
    v35 = (unsigned __int8)(v32 + 1);
    v32 = v35;
    if ( *(unsigned __int8 *)(*((_DWORD *)v34 + 13) + 2) != v31 || !v34[16] || v34[64] < -79 )
      goto LABEL_38;
    if ( v33 )
      break;
    v33 = 1;
LABEL_38:
    if ( v35 >= *((unsigned __int16 *)off_127634 + 2) )
      goto LABEL_44;
  }
  v36 = off_127648;
  v37 = **(__int16 **)off_127644;
  *((_DWORD *)off_127648 + 1) &= 0xFFEFFFBF;
  if ( v37 < 0 && *(_DWORD *)off_127650 << 28 )
    sub_12F49C(dword_127658, dword_127654, 472);
  v38 = off_12764C;
  *(_DWORD *)off_12764C = *v36 | v36[1];
  v39 = 0;
LABEL_48:
  v40 = dword_12765C;
  v30[8] = v15;
  result = msg_parse(v40, v39, v38);
LABEL_6:
  v12 = *(unsigned __int8 *)(a1 + 24);
  if ( v12 != 3 )
    goto LABEL_7;
LABEL_23:
  v2[88] &= ~8u;
  v19 = (_WORD *)sub_12B514();
  v20 = (_WORD *)sub_12C92C(79, 13, 0, 12);
  *v20 = *v19;
  v21 = v20;
  v22 = sub_12B528(v19);
  v23 = dword_12763C;
  v24 = (unsigned int *)off_127660;
  v25 = off_127640;
  *((_DWORD *)v21 + 1) = (unsigned int)(((unsigned int)dword_12763C * (unsigned __int64)(unsigned int)v22) >> 32) >> 6;
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
  sdio_buffer_prepare_n_4e8(v21);
  v27 = off_127648;
  v28 = **(__int16 **)off_127644;
  v29 = *((_DWORD *)off_127648 + 1) & 0xFFFFDDFF;
  *((_DWORD *)off_127648 + 1) = v29;
  if ( v28 < 0 && *(_DWORD *)off_127650 << 28 )
  {
    sub_12F49C(dword_127658, dword_127654, 472);
    v29 = v27[1];
  }
  *(_DWORD *)off_12764C = v29 | *v27;
  result = sub_12CA10(142, 2, 255);
  v14 = (unsigned __int8)v2[88];
LABEL_8:
  *(_BYTE *)(a1 + 24) = -1;
  v2[88] = v14 & 0xEF;
  if ( !(v14 << 30) )
  {
    if ( a2 )
      return result;
    return sub_121A74();
  }
  result = sub_127344();
  if ( !a2 )
    return sub_121A74();
  return result;
}

