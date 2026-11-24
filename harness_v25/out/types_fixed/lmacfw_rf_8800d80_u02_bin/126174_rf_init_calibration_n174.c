// rf_init_calibration_n174 @ 0x126174, size 200 bytes
// Doc: rf_init_calibration_n174 [rf]: Performs RF initialization and calibration sequence
// rf_init_calibration_n174 [rf]: Performs RF initialization and calibration sequence
int rf_init_calibration_n174()
{
  _QWORD *v0; // r5
  _DWORD *v1; // r7
  int v2; // r1
  __int64 v3; // r0
  _DWORD *v4; // r12
  _DWORD *v5; // r2
  _DWORD *v6; // r1
  _DWORD *v7; // r5
  char v9; // [sp+6h] [bp-46h] BYREF
  char v10; // [sp+7h] [bp-45h] BYREF
  int v11; // [sp+8h] [bp-44h] BYREF
  unsigned __int16 v12; // [sp+Ch] [bp-40h]
  int v13; // [sp+10h] [bp-3Ch] BYREF
  __int16 v14; // [sp+14h] [bp-38h]
  _BYTE *(_DWORD *)(v15 + 0x20); // [sp+18h] [bp-34h] BYREF
  int v16; // [sp+20h] [bp-2Ch] BYREF
  __int16 v17; // [sp+24h] [bp-28h]
  _BYTE *(_DWORD *)(v18 + 0x48); // [sp+28h] [bp-24h] BYREF
  _BYTE *(_DWORD *)(v19 + 0x48); // [sp+3Ah] [bp-12h] BYREF

  v0 = off_12623C;
  v1 = off_126240;
  v2 = *((_DWORD *)off_12623C + 1);
  v13 = *(_DWORD *)off_12623C;
  v14 = v2;
  v9 = 0;
  v10 = 1;
  sub_1282E8(&v11, &v13, 6);
  sub_1282E8(v19, &v11, 6);
  *(_DWORD *)(v19 + 0x1c) = 0;
  sub_123F04(0, 0, 0, 0);
  sub_117E5C((int)&v11, 0, 0, &v10);
  sub_11930C(0, (int)v18, 0, 0);
  v3 = *(_DWORD *)(v0 + 0x4);
  v17 = *((_DWORD *)v0 + 3);
  v16 = v3;
  sub_1282E8(v15, &v16, 6);
  sub_117E5C((int)v15, 0, 0, &v9);
  v4 = off_126254;
  *(_DWORD *)off_126244 = v11;
  v5 = off_126248;
  v6 = off_12624C;
  v7 = off_126250;
  *v4 = v12;
  *v5 = 0xFFFF;
  *v6 = -1;
  *v1 = 0xFFFF;
  *v7 = -1;
  sub_123FF0(2u, 0, 0);
  sub_12407C(0);
  sub_123F64(1);
  return mmio_field_set_l2h2(0);
}

