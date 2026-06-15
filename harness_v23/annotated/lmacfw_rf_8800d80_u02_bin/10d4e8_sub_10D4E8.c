// v23 annotated: sub_10D4E8 @ 0x10d4e8
// Original: 10d4e8_sub_10D4E8.c
// Primary struct: <unclustered>
//
// sub_10D4E8 @ 0x10d4e8, size 236 bytes
void sub_10D4E8()
{
  int v0; // r3
  _DWORD *v1; // r5
  _DWORD *v2; // r0
  _DWORD *v3; // r1
  _DWORD *v4; // r4
  _DWORD *v5; // r0
  unsigned int v6; // r3
  unsigned int v7; // r2
  unsigned int v8; // r3
  int v9; // r7
  int v10; // r0
  int v11; // r3
  _DWORD *v12; // r2
  _DWORD *v13; // r4
  int *v14; // r5
  int *v15; // r6
  _DWORD *v16; // r0
  unsigned int *v17; // r1
  _DWORD *v18; // r5
  _DWORD *v19; // r2
  int v20; // r0
  _DWORD *v21; // r2
  _DWORD *v22; // r3
  int v23; // r0

  v0 = *((_DWORD *)off_10D5D4 + 43);
  if ( v0 >= 0 )
  {
    if ( *(_DWORD *)off_10D5D8 )
    {
      v21 = off_10D600;
      v22 = off_10D604;
      v23 = dword_10D608;
      *(_DWORD *)off_10D5E0 = 1;
      *(_DWORD *)(v21[2] + 124) = v23;
      *v22 = 0x8000;
    }
  }
  else if ( *(_DWORD *)off_10D5D8 )
  {
    v1 = off_10D5E0;
    v2 = off_10D5E4;
    v3 = off_10D5E8;
    *(_DWORD *)off_10D5DC = 0;
    *v1 = 0;
    *v2 = 1;
    v4 = off_10D5EC;
    v5 = off_10D5F0;
    *v3 |= 0x100u;
    *v4 = 3;
    v6 = v0 & 0x7FFFFFFF;
    if ( (v5[20] & 0x20) != 0 )
    {
      v7 = *(_DWORD *)off_10D610;
      if ( v6 < *(_DWORD *)off_10D610 >> 4 )
        goto LABEL_5;
    }
    else
    {
      v7 = 2 * *(_DWORD *)off_10D5F4;
      if ( v6 < v7 >> 4 )
      {
LABEL_5:
        v8 = v7 / v6;
        v9 = (unsigned __int8)(v8 >> 4);
        v10 = ((v8 >> 1) & 7) + 16 * ((v8 & 0xF) - ((v8 >> 1) & 7));
        v11 = (unsigned __int8)(v8 >> 12);
LABEL_6:
        v12 = off_10D5EC;
        v13 = off_10D5E0;
        v14 = (int *)off_10D5F8;
        v15 = (int *)off_10D5FC;
        *(_DWORD *)off_10D5EC |= 0x80u;
        *v15 = v9;
        *v13 = v11;
        *v14 = v10;
        v16 = off_10D5DC;
        v17 = (unsigned int *)off_10D5E4;
        v18 = off_10D600;
        *v12 &= ~0x80u;
        *v16 = 7;
        v19 = off_10D604;
        v20 = dword_10D608;
        *v17 = *v17 & 0xFFFFFE00 | 1;
        *v13 = 1;
        *(_DWORD *)(v18[2] + 124) = v20;
        *v19 = 0x8000;
        goto LABEL_7;
      }
    }
    v10 = 0;
    v11 = 0;
    v9 = 1;
    goto LABEL_6;
  }
LABEL_7:
  *(_DWORD *)off_10D60C = 1;
}

