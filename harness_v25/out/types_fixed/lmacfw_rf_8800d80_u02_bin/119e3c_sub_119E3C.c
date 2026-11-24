// sub_119E3C @ 0x119e3c, size 184 bytes
void __fastcall sub_119E3C(int a1, int a2, int a3)
{
  __int16 v3; // r3
  __int16 **v4; // r8
  int v5; // r0
  __int16 v7; // r7
  __int16 v8; // r5
  int v9; // r2
  _DWORD *(_DWORD *)(v10 + 0x8); // [sp+0h] [bp-20h] BYREF
  char v11; // [sp+9h] [bp-17h]
  _DWORD *(_DWORD *)(v12 + 0x14); // [sp+Ch] [bp-14h] BYREF

  v4 = (__int16 **)off_119F0C;
  v5 = **(__int16 **)off_119F0C;
  memset(v12, 0, sizeof(v12));
  v7 = a3;
  v8 = v3;
  if ( v5 < 0 && sub_11E34C((unsigned __int16)a3) )
    rf_cmd_send_n264(dword_119F08, dword_119F04, 337);
  sub_1028B8((int *)a2);
  v9 = dword_119EF8;
  *(_BYTE *)off_119EF4 = 1;
  *(_DWORD *)(v10 + 0x0) = v9;
  *(_DWORD *)(v10 + 0x4) = 2412;
  v11 = 0;
  sub_102908((unsigned __int8 *)v10, 0);
  sub_11D9F8(15);
  sub_115F78((int)v12);
  if ( **v4 < 0 && (unsigned __int8)v8 > 5u )
  {
    rf_cmd_send_n264(dword_119F00, dword_119EFC, 183);
    if ( (v8 & 0xFC) != 0 )
      goto LABEL_7;
LABEL_4:
    mmio_init_clock_gate_n121();
    return;
  }
  if ( (v8 & 0xFC) == 0 )
    goto LABEL_4;
LABEL_7:
  sub_11DED8(3, v8, v7);
  mmio_init_clock_gate_n121();
}

