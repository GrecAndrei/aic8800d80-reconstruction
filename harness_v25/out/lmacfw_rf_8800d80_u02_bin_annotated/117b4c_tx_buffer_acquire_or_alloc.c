// fwstruct annotate: 117b4c_tx_buffer_acquire_or_alloc.c
// tx_buffer_acquire_or_alloc @ 0x117b4c, size 328 bytes
// Doc: tx_buffer_acquire_or_alloc [tx]: Acquire or allocate LMAC TX buffer via SDIO prep
// tx_buffer_acquire_or_alloc [tx]: Acquire or allocate LMAC TX buffer via SDIO prep
int __fastcall tx_buffer_acquire_or_alloc(int *a1, _BYTE *a2)
{
  int v3; // r6
  int v5; // r0
  int v6; // r4
  int v7; // r1
  int *v8; // r2
  int v9; // r0
  int v10; // r3
  unsigned int v11; // r0
  char v12; // r3
  int v13; // r2
  int v14; // r3
  int v15; // r1
  int v16; // r6
  int v17; // r3
  _DWORD *v18; // r3
  int v19; // r0
  int v20; // r2
  int v21; // r1
  _DWORD *v22; // r1
  int v24; // r0
  char v25; // r1
  __int16 v26; // lr
  int v27; // r3
  __int16 v28; // r12
  int v29; // r12

  v3 = *((unsigned __int8 *)a1 + 25);
  v5 = sub_11E7AC(dword_117C94);
  if ( !v5 )
    return 1;
  v6 = v5;
  if ( *((_BYTE *)a1 + 29) )
  {
    v24 = sub_11E7AC(dword_117C94);
    if ( !v24 )
    {
      list_push_tail(dword_117C94);
      return 1;
    }
    *(_DWORD *)(v6 + 44) = v24;
    *(_DWORD *)(v24 + 44) = v6;
    v25 = *((_BYTE *)a1 + 30);
    v8 = (int *)((char *)a1 + 18);
    v26 = *((unsigned __int8 *)a1 + 29);
    *(_DWORD *)(v24 + 36) = *(int *)((char *)a1 + 18);
    *(_WORD *)(v24 + 40) = *((_WORD *)a1 + 11);
    v27 = (1 << v25) - 1;
    v7 = dword_117C98;
    LOWORD(v27) = (_WORD)v27 << 8;
    v28 = *(_WORD *)(v24 + 40) & ~(_WORD)v27;
    *(_WORD *)(v24 + 40) = v28;
    LOWORD(v27) = v28 | v27 & (*((_WORD *)a1 + 11) - (v26 << 8));
    v29 = dword_117C9C * ((v24 - v7) >> 3);
    *(_WORD *)(v24 + 40) = v27;
    *(_BYTE *)(v24 + 33) = v29;
    *(_WORD *)(v24 + 30) = -1;
  }
  else
  {
    v7 = dword_117C98;
    v8 = (int *)((char *)a1 + 18);
  }
  v9 = *v8;
  v10 = *a1;
  *(_WORD *)(v6 + 40) = *((_WORD *)v8 + 2);
  *(_DWORD *)(v6 + 4) = v10;
  *(_DWORD *)(v6 + 36) = v9;
  v11 = *((unsigned __int8 *)a1 + 24);
  v12 = dword_117C9C;
  v13 = dword_117CA0;
  if ( v11 < 0x10 )
    LOBYTE(v11) = 16;
  *(_BYTE *)(v6 + 28) = v11;
  *(_WORD *)(v6 + 20) = *((_WORD *)a1 + 8);
  *(_DWORD *)(v6 + 16) = a1[2];
  *(_DWORD *)(v6 + 12) = a1[1];
  *(_DWORD *)(v6 + 24) = a1[3];
  v14 = (unsigned __int8)(v12 * ((v6 - v7) >> 3));
  *(_BYTE *)(v6 + 32) = *((_BYTE *)a1 + 25);
  *a2 = v14;
  v15 = dword_117CA4;
  *(_BYTE *)(v6 + 33) = v14;
  sub_11F74C(256, v15, v13, v14);
  v16 = dword_117CA8 + 224 * v3;
  if ( *(_BYTE *)(v16 + 94) )
    v17 = 102400;
  else
    v17 = *(unsigned __int16 *)(v16 + 100) << 10;
  *(_DWORD *)(v6 + 8) = v17;
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)off_117CAC = 1;
  }
  v18 = off_117CB0;
  v19 = *(_DWORD *)(v6 + 44);
  v20 = *(_DWORD *)off_117CB0;
  v21 = *(_DWORD *)off_117CB0 + 1;
  *(_DWORD *)off_117CB0 = v21;
  *(_BYTE *)(v6 + 35) = 1;
  if ( v19 )
    *(_BYTE *)(v19 + 35) = 1;
  if ( v21 )
  {
    v22 = off_117CAC;
    *v18 = v20;
    if ( !v20 )
    {
      if ( *v22 )
        __enable_irq();
    }
  }
  *(_BYTE *)(v6 + 124) = 0;
  return 0;
}

