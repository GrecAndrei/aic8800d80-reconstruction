// sub_119C0C @ 0x119c0c, size 264 bytes
int *sub_119C0C()
{
  _DWORD *v0; // r3
  __int64 v1; // kr00_8
  __int64 v2; // kr08_8
  int **v3; // r5
  int *v4; // r7
  int v5; // r8
  int v6; // r6
  int **v7; // r9
  int *v8; // t1
  int *result; // r0
  int v10; // t1
  int v11; // r11
  int v12; // r10
  int *v13; // r4
  int v14; // r0
  int v15; // r3

  v0 = off_119D18;
  if ( *(_DWORD *)off_119D18 != *(_DWORD *)off_119D14 )
  {
    v1 = *(_QWORD *)((char *)off_119D14 + 4);
    v2 = *(_QWORD *)((char *)off_119D14 + 12);
    *(_DWORD *)off_119D18 = *(_DWORD *)off_119D14;
    *(_DWORD *)(v0 + 0x4) = v1;
    *(_DWORD *)(v0 + 0x8) = HIDWORD(v1);
    *(_DWORD *)(v0 + 0xc) = v2;
    *(_DWORD *)(v0 + 0x10) = HIDWORD(v2);
  }
  v3 = (int **)off_119D18;
  v4 = (int *)dword_119D20;
  v5 = dword_119D30;
  v6 = dword_119D1C;
  sub_100200((int *)dword_119D1C, 0, 0x30u);
  v7 = v3 + 6;
  do
  {
    v8 = *v3++;
    result = sub_100200(v8, 0, 360 * *v4);
    v10 = *v4++;
    if ( v10 > 0 )
    {
      v11 = 0;
      v12 = 0;
      do
      {
        v13 = &(*(v3 - 1))[v11];
        *(_DWORD *)(v13 + 0x48) = dword_119D24;
        *(_DWORD *)(v13 + 0xac) = dword_119D28;
        *((_BYTE *)v13 + 155) = 5;
        *(_DWORD *)(v13 + 0x78) = (int)(v13 + 43);
        *(_DWORD *)(v13 + 0x64) = (int)(v13 + 38);
        *(_DWORD *)(v13 + 0x68) = (int)v13 + 175;
        *(_DWORD *)(v13 + 0x6c) = 24;
        *(_DWORD *)(v13 + 0x88) = 1536;
        *(_DWORD *)(v13 + 0x8c) = 323;
        *(_DWORD *)(v13 + 0x38) = 0;
        *(_DWORD *)(v13 + 0x3c) = 0;
        *(_DWORD *)(v13 + 0x5c) = 0;
        *(_DWORD *)(v13 + 0x60) = 0;
        *(_DWORD *)(v13 + 0x7c) = 0;
        *(_DWORD *)(v13 + 0x80) = 0;
        *((_BYTE *)v13 + 152) = -124;
        *((_BYTE *)v13 + 153) = 0;
        *((_BYTE *)v13 + 154) = 0;
        *(_DWORD *)(v13 + 0x2c) = 0;
        *(_DWORD *)(v13 + 0x40) = 0;
        *(_DWORD *)(v13 + 0x70) = 0;
        *(_DWORD *)(v13 + 0x84) = 0;
        *(_DWORD *)(v13 + 0x74) = 0;
        *(_DWORD *)(v13 + 0x154) = v6;
        *(_DWORD *)(v13 + 0x10) = v5;
        *(_DWORD *)(v13 + 0x54) = v5;
        *(_DWORD *)(v13 + 0xb0) = sub_101A2C() << 14;
        v14 = sub_102AB0();
        v15 = dword_119D2C;
        *(_DWORD *)(v13 + 0xb4) = v14;
        *(_DWORD *)(v13 + 0xb8) = 0;
        *(_DWORD *)(v13 + 0xbc) = v15;
        result = (int *)sub_12D108(v6);
        ++v12;
        v11 += 90;
      }
      while ( v12 < *(v4 - 1) );
    }
    v6 += 8;
  }
  while ( v3 != v7 );
  return result;
}

