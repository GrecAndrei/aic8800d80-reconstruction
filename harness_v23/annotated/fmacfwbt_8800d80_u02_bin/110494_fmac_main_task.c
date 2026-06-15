// v23 annotated: fmac_main_task @ 0x110494
// Original: 110494_fmac_main_task.c
// Primary struct: <unclustered>
//
// fmac_main_task @ 0x110494, size 286 bytes
// Doc: fmac_main_task [unknown]: FMAC main behavioral task entry
// fmac_main_task [unknown]: FMAC main behavioral task entry
int __fastcall fmac_main_task(int a1, int a2)
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

  v2 = off_1105B8;
  v3 = (int *)off_1105BC;
  v21 = *(unsigned __int16 *)(*(_DWORD *)off_1105B4 + 48);
  sub_11035C(a2);
  v6 = *(unsigned __int16 *)(a2 + 0xC);
LABEL_2:
  v7 = off_1105E4;
  v8 = (int *)off_1105E8;
  while ( v21 > v6 )
  {
    if ( *v7 <= 4u )
      goto LABEL_24;
    v9 = (*(int (__fastcall **)(_DWORD))(*(_DWORD *)(a1 + 4 + 4) + 16))(*(_DWORD *)(a1 + 4));
    if ( !v9 )
    {
      log_printf(dword_1105E0, *v7);
LABEL_23:
      if ( *(unsigned __int16 *)(a2 + 0xC) >= (unsigned int)*(unsigned __int16 *)(*(_DWORD *)off_1105B4 + 50) )
        return 1;
LABEL_24:
      irq_nesting_or(32);
      return 1;
    }
    v10 = (_DWORD *)log_free_dispatch_n2b4();
    v11 = v10;
    if ( !v10 )
    {
      log_printf(dword_1105DC);
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
      *(_DWORD *)off_1105C0 = 1;
    }
    v13 = (int *)off_1105C4;
    v14 = *(_DWORD *)off_1105C4 + 1;
    *(_DWORD *)off_1105C4 = v14;
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
      if ( **(__int16 **)off_1105C8 < 0 && *(_DWORD *)off_1105CC )
      {
        sub_12F694(dword_1105D4, dword_1105D8, 400);
        v13 = (int *)off_1105C4;
        v14 = *(_DWORD *)off_1105C4;
      }
      *(_DWORD *)off_1105CC = v11;
    }
    v15 = *v3;
    v16 = *(_WORD *)(a2 + 0xC);
    *(_DWORD *)(a2 + 4) = v11;
    v6 = (unsigned __int16)(v16 + 1);
    *(_WORD *)(a2 + 0xC) = v6;
    *v3 = (unsigned __int16)(v15 + 1);
    *(_DWORD *)off_1105D0 = 1;
    if ( v14 )
    {
      v17 = off_1105C0;
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

