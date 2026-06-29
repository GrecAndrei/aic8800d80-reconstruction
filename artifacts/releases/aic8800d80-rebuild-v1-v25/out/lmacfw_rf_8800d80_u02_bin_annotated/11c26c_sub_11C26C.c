// fwstruct annotate: 11c26c_sub_11C26C.c
// sub_11C26C @ 0x11c26c, size 158 bytes
int __fastcall sub_11C26C(int result)
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
  if ( **(__int16 **)off_11C30C < 0 && !v1 )
    result = sub_1219C4(dword_11C320, dword_11C31C, 3591);
  v3 = off_11C310;
  if ( (*((_BYTE *)off_11C310 + 88) & 0x20) == 0 && *((unsigned __int8 *)off_11C310 + 90) > 1u )
  {
    v4 = *(unsigned __int8 *)(v2 + 102);
    v5 = sub_11DDF0(70, *((_BYTE *)off_11C310 + 88) & 0x20, *((_BYTE *)off_11C310 + 88) & 0x20, 20);
    *(_BYTE *)v5 = 0;
    *(_BYTE *)(v5 + 1) = *(_BYTE *)(v2 + 95);
    *(_BYTE *)(v5 + 2) = *(_BYTE *)(v1 + 4);
    *(_BYTE *)(v5 + 3) = *(_BYTE *)(v1 + 5);
    v6 = *(_WORD *)(v1 + 8);
    v7 = *(_WORD *)(v1 + 10);
    v8 = dword_11C314;
    *(_WORD *)(v5 + 4) = *(_WORD *)(v1 + 6);
    *(_WORD *)(v5 + 6) = v6;
    *(_WORD *)(v5 + 8) = v7;
    *(_BYTE *)(v5 + 16) = *(_BYTE *)(v1 + 12);
    *(_DWORD *)(v5 + 12) = (unsigned int)(((unsigned int)dword_11C318
                                         * (unsigned __int64)(unsigned int)(*(_DWORD *)(v8 + 152 * v4 + 8) - 5000)) >> 32) >> 6;
    result = sub_11DE50(v5);
    v3[88] |= 0x20u;
  }
  return result;
}

