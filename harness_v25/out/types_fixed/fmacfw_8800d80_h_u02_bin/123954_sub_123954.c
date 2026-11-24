// sub_123954 @ 0x123954, size 182 bytes
void __fastcall sub_123954(int a1, int a2, int a3, int a4)
{
  __int16 **v4; // r8
  int v5; // r0
  int v9; // r0
  int v10; // [sp+0h] [bp-28h]
  int v11; // [sp+4h] [bp-24h] BYREF
  char v12; // [sp+Dh] [bp-1Bh]
  _DWORD *(_DWORD *)(v13 + 0x18); // [sp+10h] [bp-18h] BYREF

  v4 = (__int16 **)off_123A24;
  v5 = **(__int16 **)off_123A24;
  memset(v13, 0, sizeof(v13));
  if ( v5 < 0 && sub_12CD48(a3) )
    sub_12F32C(off_123A20, off_123A1C[0], 337);
  sub_102934((int *)a2);
  v12 = 0;
  log_free_dispatch((unsigned __int16 *)&v11, 0, dword_123A0C, 2484, v10, dword_123A0C, 2484);
  sub_12C344(15);
  *((_WORD *)off_123A10 + 14) = *(_WORD *)(a2 + 68);
  sub_117B84(v13);
  if ( **v4 < 0 && (unsigned __int8)a4 > 0xEu )
  {
    sub_12F32C(off_123A18[0], off_123A14[0], 183);
    goto LABEL_7;
  }
  if ( (unsigned __int8)a4 > 0xCu )
LABEL_7:
    sub_12C8D0(3, a4, a3);
  v9 = sub_120FA4();
  sub_12B6C4(v9);
  sub_12CBF4(a3, 2);
}

