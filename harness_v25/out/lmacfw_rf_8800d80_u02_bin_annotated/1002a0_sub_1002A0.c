// fwstruct annotate: 1002a0_sub_1002A0.c
// sub_1002A0 @ 0x1002a0, size 234 bytes
int sub_1002A0()
{
  unsigned __int8 **v0; // r5
  int v1; // r0
  unsigned int v2; // r7
  __int64 v3; // kr00_8
  __int64 v4; // kr08_8
  int v5; // r2
  _DWORD *v6; // r3
  unsigned int v7; // r4
  __int16 **v8; // r6
  int v9; // r0
  _DWORD *v10; // r2
  int v11; // r1
  int v12; // r4
  int v13; // r3
  unsigned int v14; // r4
  unsigned int v15; // r3
  unsigned int v16; // r3
  unsigned int v17; // r7
  int result; // r0
  unsigned __int8 *v19; // r3
  int v20; // r2
  unsigned int v21; // r2

  v0 = (unsigned __int8 **)off_10038C;
  v1 = dword_100390;
  v2 = dword_100398;
  v3 = *(_QWORD *)(*(_DWORD *)off_10038C + 36);
  v4 = *(_QWORD *)(*(_DWORD *)off_10038C + 44);
  v5 = 44 * *(unsigned __int16 *)(*(_DWORD *)off_10038C + 8) + 44;
  v6 = off_10039C;
  *(_DWORD *)off_100394 = dword_100390;
  v7 = v5 + v1;
  v8 = (__int16 **)off_1003A0;
  v6[1] = HIDWORD(v3);
  v9 = dword_1003A4;
  *v6 = v3;
  v6[2] = v4;
  v6[3] = HIDWORD(v4);
  sub_10DA6C(v9, v2, v7);
  if ( **v8 < 0 && v7 >= v2 )
    sub_1219C4(dword_1003D0, dword_1003C8, 120);
  v10 = *(_DWORD **)off_1003A8;
  v11 = dword_1003AC;
  v12 = 76 * *((unsigned __int16 *)*v0 + 4) + 76;
  v13 = **(_DWORD **)off_1003A8;
  *(_DWORD *)off_1003B0 = dword_1003AC;
  v14 = v12 + v11;
  if ( !v13 )
  {
    v15 = (v10[1] + 4) & 0xFFFFFFFC;
    *v10 = v14 + 4;
    v14 += v15;
  }
  if ( !v10[2] )
  {
    v16 = (v10[3] + 4) & 0xFFFFFFFC;
    v10[2] = v14 + 4;
    v14 += v16;
  }
  v17 = dword_1003B4;
  result = sub_10DA6C(dword_1003B8, dword_1003AC, dword_1003B4);
  if ( **v8 < 0 && v14 >= v17 )
    result = sub_1219C4(dword_1003CC, dword_1003C8, 156);
  v19 = *v0;
  *(_DWORD *)off_1003BC = *((_DWORD *)*v0 + 3);
  v20 = *v19;
  if ( v20 == 2 )
  {
    v21 = *((_DWORD *)v19 + 4);
  }
  else
  {
    if ( v20 != 1 )
      return result;
    v21 = *((_DWORD *)v19 + 5);
  }
  if ( v21 )
  {
    if ( dword_1003C0 > v21 )
      return sub_10DA6C(dword_1003C4, dword_1003C0, v21);
  }
  return result;
}

