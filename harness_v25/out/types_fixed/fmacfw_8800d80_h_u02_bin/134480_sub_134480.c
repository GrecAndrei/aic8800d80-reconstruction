// sub_134480 @ 0x134480, size 260 bytes
void __fastcall sub_134480(int a1, int a2, int a3)
{
  _DWORD *v4; // r3
  _BYTE *v7; // r9
  int *v8; // r10
  int v9; // r4
  __int16 v10; // lr
  int v11; // r0
  int v12; // r1
  int v13; // r2
  int v14; // r3
  int v15; // r1
  int v16; // r2
  int v17; // r3
  _DWORD *v18; // r6
  _DWORD *v19; // r4
  unsigned int v20; // r2

  v4 = off_134584;
  if ( !*(_BYTE *)(a2 + 2)
    && *((_BYTE *)off_134584 + 1)
    && *(int *)off_134588 < 0
    && (*((_DWORD *)off_13458C + 75) & 0x80) != 0 )
  {
    if ( *((_BYTE *)off_134584 + 14) == 1 )
    {
      v18 = off_134594;
      *(_DWORD *)off_134590 = dword_134598;
      v19 = off_13459C;
      *v18 &= 0xFFFFFFF0;
      *v19 &= ~0x80000000;
      *(_DWORD *)(v4 + 0x4) = a1;
      *(_DWORD *)(v4 + 0x8) = a2;
      *((_BYTE *)v4 + 12) = a3;
      *((_BYTE *)v4 + 13) = 1;
      *((_WORD *)v4 + 1) = 257;
      v20 = dword_1345A0;
      *(_DWORD *)(v18 + 0x22c28) = 0;
      sub_12C4A4(6155, 6, v20);
      sub_10D0F4();
      return;
    }
    *((_BYTE *)off_134584 + 3) = 0;
  }
  else
  {
    *((_BYTE *)off_134584 + 14) = 0;
    *((_BYTE *)v4 + 13) = 0;
    *((_BYTE *)v4 + 3) = 0;
  }
  v7 = off_1345A4;
  v8 = *((int **)off_1345A4 + 4);
  v9 = sub_12C7EC(4098, 4, 6, 0x178u);
  *(_DWORD *)v9 = *(_DWORD *)a2;
  v10 = *(_WORD *)(a2 + 4);
  *(_BYTE *)(v9 + 367) = 1;
  v11 = *v8;
  v12 = *(_DWORD *)(v8 + 0x4);
  v13 = *(_DWORD *)(v8 + 0x8);
  v14 = *(_DWORD *)(v8 + 0xc);
  *(_WORD *)(v9 + 4) = v10;
  *(_DWORD *)(v9 + 252) = v11;
  *(_DWORD *)(v9 + 256) = v12;
  *(_DWORD *)(v9 + 260) = v13;
  *(_DWORD *)(v9 + 264) = v14;
  v15 = *(_DWORD *)(v8 + 0x14);
  v16 = *(_DWORD *)(v8 + 0x18);
  v17 = *(_DWORD *)(v8 + 0x1c);
  *(_DWORD *)(v9 + 268) = *(_DWORD *)(v8 + 0x10);
  *(_DWORD *)(v9 + 272) = v15;
  *(_DWORD *)(v9 + 276) = v16;
  *(_DWORD *)(v9 + 280) = v17;
  *(_BYTE *)(v9 + 284) = *(_DWORD *)(v8 + 0x20);
  *(_BYTE *)(v9 + 368) = 1;
  *(_WORD *)(v9 + 364) = 0;
  *(_DWORD *)(v9 + 360) = 0;
  *(_BYTE *)(v9 + 366) = *((_BYTE *)v8 + 61);
  *(_DWORD *)(v9 + 352) = *(_DWORD *)a1;
  *(_WORD *)(v9 + 356) = *(_WORD *)(a1 + 4);
  if ( a3 )
    *(_BYTE *)(v9 + 3) |= 1u;
  *(_DWORD *)(v7 + 0x80) = a3;
  sub_12C84C(v9);
  sub_12CBF4(6u, 2);
}

