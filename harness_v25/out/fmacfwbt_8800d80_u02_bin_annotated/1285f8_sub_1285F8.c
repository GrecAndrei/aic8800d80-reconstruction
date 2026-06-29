// fwstruct annotate: 1285f8_sub_1285F8.c
// sub_1285F8 @ 0x1285f8, size 160 bytes
int __fastcall sub_1285F8(int result)
{
  int v1; // r7
  int v2; // r5
  _BYTE *v3; // r6
  int v4; // r8
  int v5; // r0
  __int16 v6; // r5
  __int16 v7; // r4
  int v8; // r2

  v1 = *(_DWORD *)(result + 72);
  v2 = result;
  if ( **(__int16 **)off_128698 < 0 && !v1 )
    result = sub_12F694(dword_1286AC, dword_1286A8, 3591);
  v3 = off_12869C;
  if ( (*((_BYTE *)off_12869C + 88) & 0x20) == 0 && *((unsigned __int8 *)off_12869C + 90) > 1u )
  {
    v4 = *(unsigned __int8 *)(v2 + 116);
    v5 = sub_12CB54(70, *((_BYTE *)off_12869C + 88) & 0x20, *((_BYTE *)off_12869C + 88) & 0x20, 20);
    *(_BYTE *)v5 = 0;
    *(_BYTE *)(v5 + 1) = *(_BYTE *)(v2 + 107);
    *(_BYTE *)(v5 + 2) = *(_BYTE *)(v1 + 4);
    *(_BYTE *)(v5 + 3) = *(_BYTE *)(v1 + 5);
    v6 = *(_WORD *)(v1 + 8);
    v7 = *(_WORD *)(v1 + 10);
    v8 = dword_1286A0;
    *(_WORD *)(v5 + 4) = *(_WORD *)(v1 + 6);
    *(_WORD *)(v5 + 6) = v6;
    *(_WORD *)(v5 + 8) = v7;
    *(_BYTE *)(v5 + 16) = *(_BYTE *)(v1 + 12);
    *(_DWORD *)(v5 + 12) = (unsigned int)(((unsigned int)dword_1286A4
                                         * (unsigned __int64)(unsigned int)(*(_DWORD *)(v8 + 696 * v4 + 8) - 5000)) >> 32) >> 6;
    result = sub_12CBB4(v5);
    v3[88] |= 0x20u;
  }
  return result;
}

