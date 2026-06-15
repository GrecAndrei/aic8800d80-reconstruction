// v23 annotated: sub_1238E0 @ 0x1238e0
// Original: 1238e0_sub_1238E0.c
// Primary struct: <unclustered>
//
// sub_1238E0 @ 0x1238e0, size 276 bytes
unsigned int sub_1238E0()
{
  int *v0; // r10
  int *v1; // r8
  _DWORD *v2; // r7
  int v3; // r11
  unsigned int v4; // r9
  unsigned int v5; // r4
  int v6; // r5
  int v7; // r6
  int v8; // r2
  int v9; // r0
  int v10; // r2
  unsigned int v11; // r6
  unsigned int v12; // r6
  int v13; // r1
  _BYTE *v14; // r4
  unsigned int result; // r0
  unsigned int *v16; // r3
  int v17; // [sp+14h] [bp-10h]
  int v18; // [sp+18h] [bp-Ch]

  event_queue_push(144, 0);
  v0 = (int *)off_123A18;
  v1 = (int *)off_123A1C;
  v2 = off_1239F8;
  timer_set_relative(144, 0, dword_1239F4);
  v3 = *(_DWORD *)off_1239FC;
  v17 = *(_DWORD *)off_123A00;
  v4 = *(_DWORD *)off_1239FC - *v0;
  v5 = *(_DWORD *)off_123A00 - *v1;
  v6 = *v2;
  v7 = sub_128280(v4);
  if ( sub_128280(v5) > 50000 )
    v8 = 2;
  else
    v8 = v7 > 50000;
  v18 = v8;
  v9 = sub_128280(-v6);
  v10 = v18;
  v11 = v4 + v5;
  if ( v9 > 50000 )
    v10 = 3;
  if ( v6 == v11 || (v12 = v11 - v6, v12 < v4) || v12 < v5 || v12 < -v6 )
  {
    v13 = 4;
LABEL_8:
    v14 = off_123A08;
    result = msg_parse(dword_123A04, v13, *v0, v3, *v1, v17, *v2, 0);
    goto LABEL_9;
  }
  v13 = v10;
  result = 10000 * (v5 - v6) / v12;
  if ( v10 )
    goto LABEL_8;
  v14 = off_123A08;
  if ( !*(_BYTE *)off_123A08 )
    goto LABEL_12;
  result = msg_parse(dword_123A0C, v4, v12);
  v16 = (unsigned int *)off_123A14;
  *(_DWORD *)off_123A10 = v4;
  *v16 = v12;
LABEL_9:
  if ( !*v14 )
LABEL_12:
    *v14 = 1;
  *v0 = v3;
  *v1 = v17;
  *v2 = 0;
  return result;
}

