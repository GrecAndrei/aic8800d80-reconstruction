// fwstruct annotate: 1350d0_fmac_handler_n150d0.c
// fmac_handler_n150d0 @ 0x1350d0, size 142 bytes
// Doc: fmac_handler_n150d0 [mac]: FMAC handler processing PHY channel/status fields
// fmac_handler_n150d0 [mac]: FMAC handler processing PHY channel/status fields
void __fastcall fmac_handler_n150d0(
        int a1,
        int a2,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13)
{
  int v13; // r5
  _BYTE *v14; // r7
  int v17; // r1
  int v18; // r2
  __int16 v19; // r5

  v13 = *(_DWORD *)(a1 + 72);
  v14 = off_135160;
  feature_guard_check(
    256,
    dword_135164,
    *((unsigned __int8 *)off_135160 + 34),
    a2,
    (unsigned __int8)*(_WORD *)(v13 + 108));
  if ( !v14[34] )
  {
    sub_134E04(1, v17, v18, (unsigned __int8)v14[34], a5, a6, a7, a8, a9, a10, a11, a12, a13);
    return;
  }
  v19 = *(_WORD *)(v13 + 108);
  if ( msg_get_value(6u) != 5 && msg_get_value(6u) != 8 )
  {
LABEL_5:
    v14[34] = 0;
    return;
  }
  if ( msg_get_value(6u) == 5 && (v19 & 0xFC) == 0xB0 || msg_get_value(6u) == 8 && (v19 & 0xDC) == 0 )
  {
    if ( (a2 & 0x800000) == 0 )
    {
      rf_param_get_status(a1, 5);
      *(_BYTE *)(a1 + 98) = 1;
      return;
    }
    goto LABEL_5;
  }
}

