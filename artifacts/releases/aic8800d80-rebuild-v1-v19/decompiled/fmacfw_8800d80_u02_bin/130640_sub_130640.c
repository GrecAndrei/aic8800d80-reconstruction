// sub_130640 @ 0x130640, size 120 bytes
int __fastcall sub_130640(int *a1)
{
  char *v1; // r4
  __int16 v2; // r3
  int v3; // r2
  int v4; // r6
  char *v5; // r3
  char v6; // t1
  char *v7; // r2
  int v8; // r5
  _BYTE *v9; // r3
  _BYTE *v10; // r5
  char v11; // t1

  v1 = (char *)off_1306B8;
  v2 = *((_WORD *)off_1306B8 + 6);
  *(_BYTE *)*a1 = 45;
  *(_BYTE *)(*a1 + 1) = 26;
  v3 = *a1;
  *(_WORD *)(v3 + 2) = v2 & 0xFFE3 | 0xC;
  *(_BYTE *)(v3 + 4) = v1[14];
  v4 = *a1;
  v5 = v1 + 15;
  do
  {
    v6 = *v5++;
    *(_BYTE *)(v5 - v1 + v4 - 11) = v6;
  }
  while ( v5 != v1 + 31 );
  v7 = (char *)dword_1306BC;
  *(_BYTE *)(*a1 + 15) = 0;
  *(_BYTE *)(*a1 + 16) = 0;
  v8 = *a1;
  *(_WORD *)(v8 + 21) = *((_WORD *)v1 + 16);
  v9 = (_BYTE *)(v8 + 23);
  v10 = (_BYTE *)(v8 + 27);
  do
  {
    v11 = *v7++;
    *v9++ = v11;
  }
  while ( v9 != v10 );
  *(_BYTE *)(*a1 + 27) = v1[40];
  *a1 += 28;
  return 28;
}

