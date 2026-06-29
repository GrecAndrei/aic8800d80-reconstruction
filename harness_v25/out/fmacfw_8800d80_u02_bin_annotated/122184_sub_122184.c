// fwstruct annotate: 122184_sub_122184.c
// sub_122184 @ 0x122184, size 116 bytes
int __fastcall sub_122184(int a1)
{
  int *v1; // r3
  int v2; // r6
  int v3; // r5
  int *v4; // r0
  int *v5; // r1
  int v6; // r2
  int v7; // t1
  int v8; // r4
  _BYTE *v9; // r4
  _BYTE *v10; // r1
  _BYTE *v11; // r2
  int v12; // r1
  int v13; // r2
  _DWORD v15[7]; // [sp+0h] [bp-1Ch] BYREF

  v1 = (int *)dword_1221FC;
  v2 = dword_122200;
  v3 = dword_122204;
  v4 = (int *)(a1 + 12);
  v5 = (int *)(*(_DWORD *)off_1221F8 + 4);
  do
  {
    v7 = *v5++;
    v6 = v7;
    v8 = v7 & 0xFFF;
    if ( v7 )
    {
      if ( !v8 )
      {
        *v1 = *v4 & 0xFFF | v6 & v2;
        goto LABEL_5;
      }
    }
    else
    {
      v6 = *v4;
    }
    *v1 = v6;
LABEL_5:
    ++v1;
    ++v4;
  }
  while ( v1 != (int *)v3 );
  v9 = off_122208;
  sub_102B80(*((_BYTE *)off_122208 + 409));
  v10 = off_122210;
  v11 = off_122214;
  *((_BYTE *)off_12220C + 7) = v9[409];
  memset(&v15[1], 0, 16);
  *v10 = 0;
  v15[0] = 0;
  *v11 = 0;
  v15[5] = 0;
  sub_117CC4((int)v15);
  return sub_12EA88(dword_122218, v12, v13);
}

