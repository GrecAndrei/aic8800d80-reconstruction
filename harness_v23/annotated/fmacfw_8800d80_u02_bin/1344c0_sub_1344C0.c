// v23 annotated: sub_1344C0 @ 0x1344c0
// Original: 1344c0_sub_1344C0.c
// Primary struct: <unclustered>
//
// sub_1344C0 @ 0x1344c0, size 242 bytes
_DWORD *__fastcall sub_1344C0(int a1, int a2)
{
  int *v4; // r5
  int v5; // r0
  int v6; // r4
  int v7; // r0
  int v8; // r1
  int v9; // r2
  int v10; // r3
  int v11; // r1
  int v12; // r2
  int v13; // r3
  __int16 v15; // r3
  int v16; // r5
  int v17; // r0
  int v18; // r3
  int v19; // r0
  int v20; // r2
  _DWORD v21[2]; // [sp+8h] [bp-8h]

  v4 = *((int **)off_1345B4 + 4);
  v5 = sub_12C92C(4096, 4, 6, 0x178u);
  *(_BYTE *)(v5 + 366) = *((_BYTE *)v4 + 61);
  v6 = v5;
  v7 = *v4;
  v8 = v4[1];
  v9 = v4[2];
  v10 = v4[3];
  v4 += 4;
  *(_DWORD *)(v6 + 360) = 0;
  *(_WORD *)(v6 + 364) = 0;
  *(_DWORD *)(v6 + 252) = v7;
  *(_DWORD *)(v6 + 256) = v8;
  *(_DWORD *)(v6 + 260) = v9;
  *(_DWORD *)(v6 + 264) = v10;
  v11 = v4[1];
  v12 = v4[2];
  v13 = v4[3];
  *(_DWORD *)(v6 + 268) = *v4;
  *(_DWORD *)(v6 + 272) = v11;
  *(_DWORD *)(v6 + 276) = v12;
  *(_DWORD *)(v6 + 280) = v13;
  *(_BYTE *)(v6 + 284) = v4[4];
  *(_BYTE *)(v6 + 368) = 1;
  if ( a1 )
  {
    *(_DWORD *)(v6 + 352) = *(_DWORD *)a1;
    *(_WORD *)(v6 + 356) = *(_WORD *)(a1 + 4);
    if ( a2 )
    {
LABEL_3:
      *(_DWORD *)v6 = *(_DWORD *)a2;
      *(_WORD *)(v6 + 4) = *(_WORD *)(a2 + 4);
      *(_BYTE *)(v6 + 367) = 1;
      goto LABEL_4;
    }
  }
  else
  {
    v15 = *((_WORD *)off_1345B8 + 2);
    *(_DWORD *)(v6 + 352) = *(_DWORD *)off_1345B8;
    *(_WORD *)(v6 + 356) = v15;
    if ( a2 )
      goto LABEL_3;
  }
  v21[0] = off_1345BC;
  v16 = *((unsigned __int8 *)off_1345BC + 253);
  v17 = *((unsigned __int8 *)off_1345BC + 252);
  v21[1] = (char *)off_1345BC + 84;
  *(_BYTE *)(v6 + 367) = a2;
  while ( 1 )
  {
    if ( v17 )
    {
      v18 = v21[a2];
      v19 = 6 * (__int16)v17 + v18;
      do
      {
        if ( (*(_BYTE *)(v18 + 3) & 2) == 0 )
        {
          v20 = *(unsigned __int8 *)(v6 + 367);
          *(_BYTE *)(v6 + 367) = v20 + 1;
          v20 *= 3;
          *(_DWORD *)(v6 + 2 * v20) = *(_DWORD *)v18;
          *(_WORD *)(v6 + 2 * v20 + 4) = *(_WORD *)(v18 + 4);
        }
        v18 += 6;
      }
      while ( v18 != v19 );
    }
    if ( a2 )
      break;
    v17 = v16;
    a2 = 1;
  }
LABEL_4:
  sdio_buffer_prepare_n_4e8(v6);
  return sub_12CD34(6u, 1);
}

