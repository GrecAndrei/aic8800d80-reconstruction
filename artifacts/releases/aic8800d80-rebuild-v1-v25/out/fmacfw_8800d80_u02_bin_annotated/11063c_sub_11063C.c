// fwstruct annotate: 11063c_sub_11063C.c
// sub_11063C @ 0x11063c, size 286 bytes
int __fastcall sub_11063C(int a1, int a2)
{
  _DWORD *v2; // r4
  int *v3; // r7
  unsigned int v6; // r2
  _DWORD *v7; // r9
  int *v8; // r11
  int v9; // r10
  _DWORD *v10; // r0
  _DWORD *v11; // r5
  int v12; // r0
  int *v13; // r3
  int v14; // r0
  int v15; // r1
  __int16 v16; // r2
  _DWORD *v17; // r1
  int v18; // r0
  int v19; // r2
  unsigned int v21; // [sp+4h] [bp-8h]

  v2 = off_110760;
  v3 = (int *)off_110764;
  v21 = *(unsigned __int16 *)(*(_DWORD *)off_11075C + 48);
  log_queue_refill(a2);
  v6 = *(unsigned __int16 *)(a2 + 0xC);
LABEL_2:
  v7 = off_11078C;
  v8 = (int *)off_110790;
  while ( v21 > v6 )
  {
    if ( *v7 <= 4u )
      goto LABEL_24;
    v9 = (*(int (__fastcall **)(_DWORD))(*(_DWORD *)(a1 + 4 + 4) + 16))(*(_DWORD *)(a1 + 4));
    if ( !v9 )
    {
      sub_10DC24(dword_110788, *v7);
LABEL_23:
      if ( *(unsigned __int16 *)(a2 + 0xC) >= (unsigned int)*(unsigned __int16 *)(*(_DWORD *)off_11075C + 50) )
        return 1;
LABEL_24:
      irq_nesting_or_d104(32);
      return 1;
    }
    v10 = (_DWORD *)sub_1102BC();
    v11 = v10;
    if ( !v10 )
    {
      sub_10DC24(dword_110784);
      (*(void (__fastcall **)(_DWORD, int))(*(_DWORD *)(a1 + 4 + 4) + 20))(*(_DWORD *)(a1 + 4), v9);
      goto LABEL_23;
    }
    *v10 = 0;
    v12 = *v8;
    v11[1] = 0;
    v11[2] = 0;
    *v11 = v12 + v9;
    if ( (__get_CPSR() & 1) == 0 )
    {
      __disable_irq();
      *(_DWORD *)off_110768 = 1;
    }
    v13 = (int *)off_11076C;
    v14 = *(_DWORD *)off_11076C + 1;
    *(_DWORD *)off_11076C = v14;
    *v2 = 1;
    while ( (*v2 & 2) != 0 )
      ;
    if ( *v3 )
    {
      v19 = *(_DWORD *)(a2 + 4);
      if ( v19 )
        *(_DWORD *)(v19 + 4) = v11;
    }
    else
    {
      if ( **(__int16 **)off_110770 < 0 && *(_DWORD *)off_110774 )
      {
        sub_12F46C(dword_11077C, dword_110780, 400);
        v13 = (int *)off_11076C;
        v14 = *(_DWORD *)off_11076C;
      }
      *(_DWORD *)off_110774 = v11;
    }
    v15 = *v3;
    v16 = *(_WORD *)(a2 + 0xC);
    *(_DWORD *)(a2 + 4) = v11;
    v6 = (unsigned __int16)(v16 + 1);
    *(_WORD *)(a2 + 0xC) = v6;
    *v3 = (unsigned __int16)(v15 + 1);
    *(_DWORD *)off_110778 = 1;
    if ( v14 )
    {
      v17 = off_110768;
      v18 = v14 - 1;
      *v13 = v18;
      if ( !v18 )
      {
        if ( *v17 )
        {
          __enable_irq();
          v6 = *(unsigned __int16 *)(a2 + 0xC);
        }
      }
      goto LABEL_2;
    }
  }
  return 1;
}

