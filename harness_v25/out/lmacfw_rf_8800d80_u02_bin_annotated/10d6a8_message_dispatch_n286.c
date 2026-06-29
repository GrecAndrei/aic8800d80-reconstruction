// fwstruct annotate: 10d6a8_message_dispatch_n286.c
// message_dispatch_n286 @ 0x10d6a8, size 940 bytes
// Doc: message_dispatch_n286 [ipc]: Dispatch message by ID/index comparison
// message_dispatch_n286 [ipc]: Dispatch message by ID/index comparison
int __fastcall message_dispatch_n286(int a1, int a2)
{
  int v2; // r4
  int v3; // r0
  int v4; // r1
  int v5; // r6
  int v6; // r5
  int v7; // r3
  unsigned __int8 *v8; // r4
  _DWORD *v9; // r1
  _DWORD *v10; // r0
  unsigned __int8 *v11; // r5
  int v12; // r2
  int v13; // t1
  _BYTE **v15; // r7
  int v16; // r3
  _BYTE **v17; // r8
  int v18; // r0
  _DWORD *v19; // r2
  int *v20; // r4
  int v21; // r1
  int v22; // t1
  int v23; // r1
  _BYTE *v24; // r7
  int v25; // r8
  _BYTE *v26; // r0
  _BYTE *v27; // r7
  _BYTE *v28; // r8
  int v29; // r0
  _DWORD *v30; // r2
  int *v31; // r12
  int v32; // r1
  int v33; // t1
  unsigned __int16 *v34; // r9
  int v35; // r10
  int v36; // r0
  _DWORD *v37; // r2
  int *v38; // r5
  int v39; // r1
  int v40; // t1
  int *v41; // r11
  int v42; // r0
  int v43; // r7
  int v44; // r3
  _BYTE *v45; // r1
  unsigned int v46; // r2
  __int16 v47; // r0
  _DWORD *v48; // r5
  int v49; // r2
  int *v50; // r5
  int v51; // r0
  int v52; // r0
  int v53; // r3
  int v54; // r2
  int v55; // r0
  _DWORD *v56; // r2
  int *v57; // r4
  int v58; // r1
  int v59; // t1
  int v60; // r0
  _DWORD *v61; // r2
  int *v62; // r4
  int v63; // r1
  int v64; // t1
  int v65; // r0
  _DWORD *v66; // r2
  int *v67; // r7
  int v68; // r1
  int v69; // t1
  int *v70; // r11
  __int64 v71; // kr00_8
  int (__fastcall *v72)(_DWORD); // r3
  int v73; // r0
  _WORD *v74; // r3
  int v75; // r3
  unsigned __int16 v76; // r5
  int v77; // r1
  _DWORD *v78; // r2
  int *v79; // r0
  int v80; // t1
  _BYTE v81[260]; // [sp+8h] [bp-104h] BYREF

  v3 = sub_11EBB4(v81, 256, 0, a1, a2);
  v5 = v3;
  if ( v3 <= 0 )
    return v5;
  v6 = v3;
  if ( *(_DWORD *)off_10D970 )
  {
    v7 = *((_WORD *)off_10D974 + 89) & 0x4000;
    if ( (*((_WORD *)off_10D974 + 89) & 0x4000) == 0 )
      goto LABEL_4;
  }
  else
  {
    log_hw_init_d4e8();
    v7 = *((_WORD *)off_10D974 + 89) & 0x4000;
    if ( (*((_WORD *)off_10D974 + 89) & 0x4000) == 0 )
    {
LABEL_4:
      v8 = v81;
      v9 = off_10D978;
      v10 = off_10D97C;
      v11 = &v81[v6];
      do
      {
        v13 = *v8++;
        v12 = v13;
        if ( v13 == 10 && v7 != 13 )
        {
          while ( (*v9 & 0x80000) != 0 )
            ;
          *v10 = 13;
          v12 = *(v8 - 1);
        }
        while ( (*v9 & 0x80000) != 0 )
          ;
        *v10 = v12;
        v7 = *(v8 - 1);
      }
      while ( v8 != v11 );
      return v5;
    }
  }
  v15 = (_BYTE **)off_10D980;
  v16 = **(unsigned __int8 **)off_10D980;
  if ( v16 == 1 )
  {
    if ( **(_BYTE **)off_10D988 != 3 )
    {
      if ( v6 >= 124 )
        LOWORD(v6) = 124;
      rf_chan_setup_init(19, v81, (unsigned __int16)v6);
    }
  }
  else
  {
    if ( v16 != 2 )
      return v5;
    v17 = (_BYTE **)off_10D988;
    if ( **(_BYTE **)off_10D988 == 3 )
      goto LABEL_12;
    if ( (unsigned int)sub_11E82C(dword_10D98C, v4) <= 4 )
    {
      if ( **v15 != 2 )
        return v5;
      if ( **v17 != 3 )
      {
        if ( (unsigned int)sub_11E82C(dword_10D98C, v23) > 4 )
        {
          v60 = dword_10D9B8;
          v61 = off_10D978;
          v62 = (int *)off_10D97C;
          v63 = 111;
          do
          {
            while ( (*v61 & 0x80000) != 0 )
              ;
            *v62 = v63;
            v64 = *(unsigned __int8 *)++v60;
            v63 = v64;
          }
          while ( v64 );
        }
        else
        {
          v55 = dword_10D9B4;
          v56 = off_10D978;
          v57 = (int *)off_10D97C;
          v58 = 102;
          do
          {
            while ( (*v56 & 0x80000) != 0 )
              ;
            *v57 = v58;
            v59 = *(unsigned __int8 *)++v55;
            v58 = v59;
          }
          while ( v59 );
        }
        return v5;
      }
LABEL_12:
      v18 = dword_10D984;
      v19 = off_10D978;
      v20 = (int *)off_10D97C;
      v21 = 110;
      do
      {
        while ( (*v19 & 0x80000) != 0 )
          ;
        *v20 = v21;
        v22 = *(unsigned __int8 *)++v18;
        v21 = v22;
      }
      while ( v22 );
      return v5;
    }
    v24 = v81;
    v25 = dword_10D9C8;
    while ( 1 )
    {
      v26 = v24++;
      if ( !sub_128288(v26, v25, 20) )
        break;
      if ( &v81[v6] == v24 )
      {
        v27 = off_10D990;
        goto LABEL_30;
      }
    }
    v65 = dword_10D9BC;
    v66 = off_10D978;
    v67 = (int *)off_10D97C;
    v68 = 70;
    do
    {
      while ( (*v66 & 0x80000) != 0 )
        ;
      *v67 = v68;
      v69 = *(unsigned __int8 *)++v65;
      v68 = v69;
    }
    while ( v69 );
    v27 = off_10D990;
    v70 = (int *)off_10D9D0;
    v71 = *(_QWORD *)(*(_DWORD *)off_10D9C0 + 4);
    v72 = *(int (__fastcall **)(_DWORD))(HIDWORD(v71) + 16);
    *(_BYTE *)off_10D990 = 1;
    v73 = v72(v71);
    v74 = off_10D9C4;
    *v70 = v73;
    *v74 = 4;
LABEL_30:
    if ( *v27 )
    {
      v28 = off_10D9CC;
      if ( !sub_128288(v81, dword_10D994, 5) )
      {
        v29 = dword_10D998;
        v30 = off_10D978;
        v31 = (int *)off_10D97C;
        *v28 = 1;
        v32 = 80;
        do
        {
          while ( (*v30 & 0x80000) != 0 )
            ;
          *v31 = v32;
          v33 = *(unsigned __int8 *)++v29;
          v32 = v33;
        }
        while ( v33 );
      }
      v34 = (unsigned __int16 *)off_10D9C4;
      v35 = *(unsigned __int16 *)off_10D9C4;
      if ( v35 + v6 <= 1720 )
      {
        v41 = (int *)off_10DA68;
        sub_1282E8(*(_DWORD *)off_10DA68 + v35, v81, v6);
        v75 = (unsigned __int8)*v28;
        v76 = v6 + *v34;
        v35 = v76;
        *v34 = v76;
        if ( !v75 )
          return v5;
      }
      else
      {
        v36 = dword_10D99C;
        v37 = off_10D978;
        v38 = (int *)off_10D97C;
        v39 = 66;
        do
        {
          while ( (*v37 & 0x80000) != 0 )
            ;
          *v38 = v39;
          v40 = *(unsigned __int8 *)++v36;
          v39 = v40;
        }
        while ( v40 );
        v41 = (int *)off_10D9D0;
      }
      v42 = dword_10D98C;
      *v27 = 0;
      *v28 = 0;
      v43 = *v41;
      *v34 = 4;
      *v41 = 0;
      v5 = v35;
      sub_11E7AC(v42);
    }
    else
    {
      v2 = sub_11E7AC(dword_10DA54);
      if ( v6 <= 122 )
        v43 = sub_1132C0();
      else
        v43 = (*(int (__fastcall **)(_DWORD))(*(_DWORD *)(*(_DWORD *)off_10DA58 + 8) + 16))(*(_DWORD *)(*(_DWORD *)off_10DA58 + 4));
      if ( !v43 )
      {
        v77 = dword_10DA5C;
        v78 = off_10DA60;
        v79 = (int *)off_10DA64;
        v5 = 110;
        do
        {
          while ( (*v78 & 0x80000) != 0 )
            ;
          *v79 = v5;
          v80 = *(unsigned __int8 *)++v77;
          v5 = v80;
        }
        while ( v80 );
        return v5;
      }
      sub_1282E8(v43 + 4, v81, v6);
      LOWORD(v35) = v6;
    }
    *(_WORD *)v43 = v5 + 1;
    *(_BYTE *)(v43 + 2) = 19;
    v44 = 0;
    v45 = off_10D9A0;
    *(_BYTE *)(v43 + 3) = 0;
    *(_BYTE *)(v43 + v5 + 4) = 0;
    v46 = *((unsigned __int16 *)v45 + 4122);
    if ( v46 > 0x186 )
    {
      LOWORD(v46) = 0;
      v47 = 1;
    }
    else
    {
      v47 = v46 + 1;
      v44 = 8 * v46;
    }
    v48 = off_10D9A4;
    *(_WORD *)(v2 + 12) = v46;
    v49 = *v48 + v44;
    *(_DWORD *)(v49 + 4) = v43;
    *(_WORD *)v49 = v35 + 5;
    *(_BYTE *)(v49 + 3) = *(_BYTE *)(v49 + 3) & 0x31 | 4;
    LOBYTE(v48) = v45[3074] + 1;
    *((_WORD *)v45 + 4122) = v47;
    v45[3074] = (_BYTE)v48;
    *(_DWORD *)(v2 + 4) = v49;
    *(_BYTE *)(v2 + 14) = 1;
    *(_DWORD *)v2 = 0;
    *(_DWORD *)(v2 + 8) = v5 + 5;
    if ( (__get_CPSR() & 1) == 0 )
    {
      __disable_irq();
      *(_DWORD *)off_10D9A8 = 1;
    }
    v50 = (int *)off_10D9AC;
    v51 = dword_10D9B0;
    ++*(_DWORD *)off_10D9AC;
    v52 = list_push_tail(v51);
    rf_bus_mark_ne0(v52);
    if ( *v50 )
    {
      v53 = *v50 - 1;
      v54 = *(_DWORD *)off_10D9A8;
      *v50 = v53;
      if ( !v53 )
      {
        if ( v54 )
          __enable_irq();
      }
    }
  }
  return v5;
}

