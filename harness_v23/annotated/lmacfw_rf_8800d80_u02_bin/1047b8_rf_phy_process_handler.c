// v23 annotated: rf_phy_process_handler @ 0x1047b8
// Original: 1047b8_rf_phy_process_handler.c
// Primary struct: <unclustered>
//
// rf_phy_process_handler @ 0x1047b8, size 710 bytes
// Doc: rf_phy_process_handler [rf]: RF PHY processing routine with VFP context save and dispatch
// rf_phy_process_handler [rf]: RF PHY processing routine with VFP context save and dispatch
int __fastcall rf_phy_process_handler(int *a1, int a2, int a3, int a4, __int64 *a5)
{
  int v6; // r0
  int v8; // r0
  float v9; // r0
  int *v10; // r11
  __int64 v11; // d9
  __int64 v12; // r0
  __int64 v13; // d13
  __int64 v14; // r0
  __int64 v15; // r4
  __int64 v16; // r0
  int v17; // r0
  __int64 v18; // d8
  __int64 v19; // r0
  __int64 v20; // r0
  __int64 v21; // r0
  int v22; // r0
  int *v23; // r10
  __int64 v24; // d11
  __int64 v25; // r6
  __int64 v26; // r0
  __int64 v27; // r8
  __int64 v28; // r6
  __int64 v29; // r0
  __int64 v30; // d10
  __int64 v31; // r6
  __int64 v32; // r0
  __int64 v33; // r6
  __int64 v34; // r0
  __int64 v35; // r6
  __int64 v36; // r0
  __int64 v37; // d12
  __int64 v38; // r6
  __int64 v39; // r0
  __int64 v40; // r6
  __int64 v41; // r0
  __int64 v42; // r0
  __int64 v43; // r8
  __int64 v44; // r0
  __int64 v45; // r6
  __int64 v46; // r0
  __int64 v47; // r6
  __int64 v48; // r0
  __int64 v49; // r0
  __int64 v50; // r2
  __int64 v51; // r0
  int v52; // r0
  int result; // r0
  int v54; // t1
  __int64 v55; // r8
  __int64 v56; // [sp+0h] [bp-1Ch]
  __int64 v57; // [sp+8h] [bp-14h]
  __int64 v58; // [sp+10h] [bp-Ch]

  v6 = sub_127B54(a3, a4);
  v8 = msg_parse(dword_104A80, v6);
  v9 = sub_10DD20(v8);
  v10 = a1;
  msg_parse(dword_104A88, (int)(float)(v9 * flt_104A84));
  v11 = a5[2];
  v12 = sub_127620(*((_DWORD *)a5 + 4), *((_DWORD *)a5 + 5), 0, dword_104A8C);
  sub_127B54(v12, HIDWORD(v12));
  v13 = a5[1];
  v14 = sub_127620(*((_DWORD *)a5 + 2), *((_DWORD *)a5 + 3), 0, dword_104A8C);
  sub_127B54(v14, HIDWORD(v14));
  v15 = *a5;
  v16 = sub_127620(*(_DWORD *)a5, *((_DWORD *)a5 + 1), 0, dword_104A8C);
  v17 = sub_127B54(v16, HIDWORD(v16));
  v18 = a5[5];
  v58 = a5[4];
  v57 = a5[3];
  msg_parse(dword_104A90, v17);
  v19 = sub_127620(v18, HIDWORD(v18), 0, dword_104A8C);
  sub_127B54(v19, HIDWORD(v19));
  v20 = sub_127620(v58, HIDWORD(v58), 0, dword_104A8C);
  sub_127B54(v20, HIDWORD(v20));
  v21 = sub_127620(v57, HIDWORD(v57), 0, dword_104A8C);
  v22 = sub_127B54(v21, HIDWORD(v21));
  msg_parse(dword_104A94, v22);
  v23 = v10 + 32;
  do
  {
    v54 = *v10++;
    v55 = sub_127570(v54);
    if ( sub_127B2C(v15, HIDWORD(v15), v55, HIDWORD(v55)) )
    {
      v50 = v57;
    }
    else if ( sub_127AF0(v13, HIDWORD(v13), v55, HIDWORD(v55)) )
    {
      v50 = v58;
    }
    else if ( sub_127B18(v11, HIDWORD(v11), v55, HIDWORD(v55)) )
    {
      v50 = v18;
    }
    else
    {
      v24 = sub_1272B0(v55, HIDWORD(v55), v13, HIDWORD(v13));
      v25 = sub_1272B0(v55, HIDWORD(v55), v11, HIDWORD(v11));
      v26 = sub_1272B0(v55, HIDWORD(v55), v15, HIDWORD(v15));
      v27 = v25;
      v28 = v26;
      v29 = sub_127620(v57, HIDWORD(v57), v24, HIDWORD(v24));
      v30 = v28;
      v31 = sub_127620(v29, HIDWORD(v29), v27, HIDWORD(v27));
      v32 = sub_1272B0(v15, HIDWORD(v15), v13, HIDWORD(v13));
      v33 = sub_127874(v31, HIDWORD(v31), v32, HIDWORD(v32));
      v34 = sub_1272B0(v15, HIDWORD(v15), v11, HIDWORD(v11));
      v35 = sub_127874(v33, HIDWORD(v33), v34, HIDWORD(v34));
      v36 = sub_127620(v58, HIDWORD(v58), v30, HIDWORD(v30));
      v37 = v35;
      v38 = sub_127620(v36, HIDWORD(v36), v27, HIDWORD(v27));
      v39 = sub_1272B0(v13, HIDWORD(v13), v15, HIDWORD(v15));
      v40 = sub_127874(v38, HIDWORD(v38), v39, HIDWORD(v39));
      v41 = sub_1272B0(v13, HIDWORD(v13), v11, HIDWORD(v11));
      v42 = sub_127874(v40, HIDWORD(v40), v41, HIDWORD(v41));
      v43 = sub_1272B4(v37, HIDWORD(v37), v42, HIDWORD(v42));
      v44 = sub_127620(v18, HIDWORD(v18), v30, HIDWORD(v30));
      v45 = sub_127620(v44, HIDWORD(v44), v24, HIDWORD(v24));
      v46 = sub_1272B0(v11, HIDWORD(v11), v15, HIDWORD(v15));
      v47 = sub_127874(v45, HIDWORD(v45), v46, HIDWORD(v46));
      v48 = sub_1272B0(v11, HIDWORD(v11), v13, HIDWORD(v13));
      v49 = sub_127874(v47, HIDWORD(v47), v48, HIDWORD(v48));
      v50 = sub_1272B4(v43, HIDWORD(v43), v49, HIDWORD(v49));
    }
    v56 = v50;
    v51 = sub_127570(v10[63]);
    v52 = sub_127620(v51, HIDWORD(v51), v56, HIDWORD(v56));
    result = sub_127BE4(v52);
    v10[31] = result;
  }
  while ( v10 != v23 );
  return result;
}

