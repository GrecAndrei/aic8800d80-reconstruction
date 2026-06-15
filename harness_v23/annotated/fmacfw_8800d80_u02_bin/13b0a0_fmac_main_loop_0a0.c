// v23 annotated: fmac_main_loop_0a0 @ 0x13b0a0
// Original: 13b0a0_fmac_main_loop_0a0.c
// Primary struct: <unclustered>
//
// fmac_main_loop_0a0 @ 0x13b0a0, size 62 bytes
// Doc: fmac_main_loop_0a0 [mac]: FMAC firmware main behavioral loop
// fmac_main_loop_0a0 [mac]: FMAC firmware main behavioral loop
_WORD *__fastcall fmac_main_loop_0a0(int a1, _WORD *a2, int a3)
{
  _WORD *v6; // r1
  int v8; // r0
  char v9; // r3
  int v10; // [sp+4h] [bp-4h] BYREF

  if ( *(_BYTE *)(a1 + 51) )
  {
    v6 = (_WORD *)((char *)a2 + a3 + *(unsigned __int8 *)(a1 + 51));
  }
  else
  {
    v8 = sub_13A528(a1, &v10);
    v9 = v10;
    *(_BYTE *)(a1 + 51) = v8;
    v6 = (_WORD *)((char *)a2 + a3 + v8);
    *(_BYTE *)(a1 + 53) = v9;
  }
  *a2 |= 0x4000u;
  return sub_13A980(a1, v6, 0);
}

