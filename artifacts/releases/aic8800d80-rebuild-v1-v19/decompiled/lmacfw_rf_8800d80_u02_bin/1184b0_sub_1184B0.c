// sub_1184B0 @ 0x1184b0, size 294 bytes
_DWORD *sub_1184B0()
{
  int *v0; // r4
  int v1; // r0
  int v2; // r0
  _DWORD *v3; // r0
  unsigned int *v4; // r1
  unsigned int *v5; // r3
  int *v6; // r5
  int *v7; // r6
  int v8; // r4
  int v9; // r3
  char v10; // r2
  bool v11; // zf
  int v12; // r2
  unsigned int v13; // r2
  _DWORD *v14; // r2
  _DWORD *v15; // r6
  _DWORD *v16; // r5
  _DWORD *v17; // r4
  _DWORD *result; // r0
  unsigned __int8 **v19; // r1
  int v20; // r3

  v0 = (int *)off_1185DC;
  *(_DWORD *)off_1185D8 |= 0x10u;
  v1 = nullsub_1();
  v2 = nullsub_2(v1);
  nullsub_3(v2);
  v3 = off_1185E0;
  v4 = (unsigned int *)off_1185E4;
  v5 = (unsigned int *)off_1185E8;
  v6 = (int *)off_1185EC;
  v7 = (int *)off_1185F0;
  *v0 = *v0 & 0x3FFFFF | 0x2800000;
  v8 = dword_1185F4;
  *v3 |= 0x8000000u;
  *v4 = *v4 & 0xFF0FFFFF | 0x200000;
  *v5 = *v5 & 0xFFFFF8FF | 0x600;
  *v5 = *v5 & 0xFFFFC7FF | 0x2000;
  *v5 = *v5 & 0xFFFE3FFF | 0xC000;
  *v5 |= 0xE0000u;
  *v6 = *v6 & v8 | 0x5DC;
  v3[1] = v3[1] & v8 | 0xBB8;
  *(v4 - 205) = *(v4 - 205) & 0xFFFF00FF | 0xDA00;
  v9 = *v7;
  v10 = *(_BYTE *)(*v7 + 2);
  if ( (v10 & 0x10) != 0 )
    v3[16] &= ~0x80000000;
  else
    *(_DWORD *)off_118620 |= 0x80000000;
  v11 = (v10 & 1) == 0;
  v12 = *(_DWORD *)off_1185F8;
  if ( v11 )
    v13 = v12 & 0xFFFBFFFF;
  else
    v13 = v12 | 0x40000;
  *(_DWORD *)off_1185F8 = v13;
  v14 = off_1185FC;
  *(_DWORD *)off_1185FC = dword_118600;
  if ( *(_BYTE *)(v9 + 1) )
    *(v14 - 215) |= 0x40u;
  v15 = off_118608;
  v16 = off_11860C;
  v17 = off_118610;
  result = off_118614;
  v19 = (unsigned __int8 **)off_118618;
  *(_DWORD *)off_118604 &= ~1u;
  *v15 = 0xFFFF;
  *v16 = -1;
  *v17 = 0xFFFF;
  *result = -1;
  v20 = **v19;
  if ( (unsigned int)(v20 - 1) <= 1 || v20 == 4 )
    *(_DWORD *)off_11861C |= 0x80000000;
  return result;
}

