// v23 annotated: sub_12047C @ 0x12047c
// Original: 12047c_sub_12047C.c
// Primary struct: <unclustered>
//
// sub_12047C @ 0x12047c, size 284 bytes
_DWORD *sub_12047C()
{
  int *v0; // r4
  int *v1; // r5
  int *v2; // r6
  int v3; // r0
  int v4; // r0
  _DWORD *v5; // r0
  unsigned int *v6; // r1
  unsigned int *v7; // r3
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

  v0 = (int *)off_120598;
  v1 = (int *)off_12059C;
  v2 = (int *)off_1205A0;
  v3 = nullsub_1();
  v4 = nullsub_2(v3);
  nullsub_3(v4);
  v5 = off_1205A4;
  v6 = (unsigned int *)off_1205A8;
  v7 = (unsigned int *)off_1205AC;
  *v0 = *v0 & 0x3FFFFF | 0x2800000;
  v8 = dword_1205B0;
  *v5 |= 0x8000000u;
  *v6 = *v6 & 0xFF0FFFFF | 0x200000;
  *v7 = *v7 & 0xFFFFF8FF | 0x600;
  *v7 = *v7 & 0xFFFFC7FF | 0x2000;
  *v7 = *v7 & 0xFFFE3FFF | 0xC000;
  *v7 |= 0xE0000u;
  *v1 = *v1 & v8 | 0x5DC;
  v5[1] = v5[1] & v8 | 0xBB8;
  *(v6 - 205) = *(v6 - 205) & 0xFFFF00FF | 0xDA00;
  v9 = *v2;
  v10 = *(_BYTE *)(*v2 + 2);
  if ( (v10 & 0x10) != 0 )
    v5[16] &= ~0x80000000;
  else
    *(_DWORD *)off_1205DC |= 0x80000000;
  v11 = (v10 & 1) == 0;
  v12 = *(_DWORD *)off_1205B4;
  if ( v11 )
    v13 = v12 & 0xFFFBFFFF;
  else
    v13 = v12 | 0x40000;
  *(_DWORD *)off_1205B4 = v13;
  v14 = off_1205B8;
  *(_DWORD *)off_1205B8 = dword_1205BC;
  if ( *(_BYTE *)(v9 + 1) )
    *(v14 - 215) |= 0x40u;
  v15 = off_1205C4;
  v16 = off_1205C8;
  v17 = off_1205CC;
  result = off_1205D0;
  v19 = (unsigned __int8 **)off_1205D4;
  *(_DWORD *)off_1205C0 &= ~1u;
  *v15 = 0xFFFF;
  *v16 = -1;
  *v17 = 0xFFFF;
  *result = -1;
  v20 = **v19;
  if ( (unsigned int)(v20 - 1) <= 1 || v20 == 4 )
    *(_DWORD *)off_1205D8 |= 0x80000000;
  return result;
}

