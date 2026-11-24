// sub_107944 @ 0x107944, size 276 bytes
int __fastcall sub_107944(int a1, _DWORD *a2)
{
  unsigned int *v2; // r6
  unsigned int *v3; // r8
  unsigned int v4; // r3
  int v5; // r7
  int v7; // r9
  int *v8; // r4
  int v9; // r11
  int v10; // r10
  int v11; // r0
  int v12; // t1
  int v13; // r3
  int v14; // r2
  int v15; // r1
  int v16; // r5
  unsigned int *v17; // r3
  int v18; // r2
  int v20; // [sp+8h] [bp-1Ch]
  int v21; // [sp+Ch] [bp-18h]
  int v22; // [sp+10h] [bp-14h]
  int v23; // [sp+14h] [bp-10h]
  int v24; // [sp+18h] [bp-Ch]

  v2 = (unsigned int *)off_107A58;
  v3 = (unsigned int *)off_107A6C;
  *(_DWORD *)off_107A58 |= 0x1000000u;
  v4 = *v2 & 0xFDFFFFFF;
  v5 = 1;
  *v2 = v4;
  v7 = 1000;
  sub_11F74C(1, dword_107A5C, a2, v4);
  v8 = (int *)(a1 + 12);
  v23 = 1;
  v24 = 1;
  v21 = 1;
  v20 = 1;
  v22 = 1;
  v9 = 1;
  v10 = 1000;
  do
  {
    while ( 1 )
    {
      v11 = *(_DWORD *)(v8 + 0x28);
      v12 = *(_DWORD *)(v8 + 0x4);
      ++v8;
      *v3 = dword_107A60 & (v11 << 16) | *v3 & 0xF000FFFF;
      *v3 = v12 & 0xFFF | *v3 & 0xFFFFF000;
      sub_100560(40);
      v13 = *(_DWORD *)(v8 + 0x24);
      v14 = *v8;
      v15 = dword_107A64;
      *v2 |= 0x4000000u;
      v16 = *(_DWORD *)off_107A68 & 0x7FFF;
      *v2 &= ~0x4000000u;
      sub_11F74C(1, v15, v14, v13);
      if ( v16 >= v7 )
        break;
      v23 = v21;
      v24 = v20;
      v21 = *(_DWORD *)(v8 + 0x24);
      v22 = v9;
      v10 = v7;
      v20 = *v8;
      v7 = v16;
      v9 = v5;
LABEL_3:
      if ( ++v5 == 10 )
        goto LABEL_7;
    }
    if ( v16 >= v10 )
      goto LABEL_3;
    v22 = v5++;
    v24 = *v8;
    v23 = *(_DWORD *)(v8 + 0x24);
    v10 = v16;
  }
  while ( v5 != 10 );
LABEL_7:
  v17 = (unsigned int *)off_107A58;
  v18 = *(_DWORD *)off_107A58;
  *(_DWORD *)(a2 + 0x14) = v20;
  *(_DWORD *)(a2 + 0x18) = v21;
  *(_DWORD *)(a2 + 0x1c) = v24;
  *(_DWORD *)(a2 + 0xc) = v7;
  *(_DWORD *)(a2 + 0x20) = v23;
  *(_DWORD *)(a2 + 0x24) = v9;
  *(_DWORD *)(a2 + 0x10) = v10;
  *(_DWORD *)(a2 + 0x28) = v22;
  *v17 = v18 & 0xFEFFFFFF;
  *v17 &= ~0x2000000u;
  return v22;
}

