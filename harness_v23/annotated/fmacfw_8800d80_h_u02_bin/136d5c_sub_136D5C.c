// v23 annotated: sub_136D5C @ 0x136d5c
// Original: 136d5c_sub_136D5C.c
// Primary struct: <unclustered>
//
// sub_136D5C @ 0x136d5c, size 90 bytes
int __fastcall sub_136D5C(int a1, unsigned __int8 *a2, int a3, __int16 a4)
{
  _WORD *v4; // r4
  _BYTE *v6; // r0
  _DWORD *v7; // r6
  unsigned int v8; // r2
  int *v10; // r4
  int v11; // r0
  int v12; // r1
  int v13; // r2
  int v14; // r3
  int v15; // r0
  int v16; // r1
  int v17; // r2
  int v18; // r3
  int v19; // r0
  int v20; // r1
  int v21; // r2
  int v22; // r3
  int v23; // r1
  int v24; // r2

  v4 = off_136DB8;
  v6 = (_BYTE *)sub_12C7EC(4102, a4, 4, 0x3Cu);
  v7 = v6;
  if ( v4[2] && (v8 = *a2, (unsigned __int16)v4[2] > v8) )
  {
    v10 = (int *)&v4[30 * v8 + 4];
    v11 = *v10;
    v12 = v10[1];
    v13 = v10[2];
    v14 = v10[3];
    v10 += 4;
    *v7 = v11;
    v7[1] = v12;
    v7[2] = v13;
    v7[3] = v14;
    v15 = *v10;
    v16 = v10[1];
    v17 = v10[2];
    v18 = v10[3];
    v10 += 4;
    v7[4] = v15;
    v7[5] = v16;
    v7[6] = v17;
    v7[7] = v18;
    v19 = *v10;
    v20 = v10[1];
    v21 = v10[2];
    v22 = v10[3];
    v10 += 4;
    v7[8] = v19;
    v7[9] = v20;
    v7[10] = v21;
    v7[11] = v22;
    v23 = v10[1];
    v24 = v10[2];
    v7[12] = *v10;
    v7[13] = v23;
    v7[14] = v24;
    sub_12C84C((int)v7);
    return 0;
  }
  else
  {
    *v6 = 0;
    sub_12C84C((int)v6);
    return 0;
  }
}

