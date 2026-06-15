// v23 annotated: sub_128F8C @ 0x128f8c
// Original: 128f8c_sub_128F8C.c
// Primary struct: <unclustered>
//
// sub_128F8C @ 0x128f8c, size 454 bytes
// Doc: sub_1228F8C [mac]: Processes command structure, reads byte at offset 0x74 with size 0x2b8
// sub_1228F8C [mac]: Processes command structure, reads byte at offset 0x74 with size 0x2b8
unsigned int __fastcall sub_128F8C(unsigned int result, int a2, int a3)
{
  int v3; // r3
  _DWORD *v4; // r7
  int v6; // r2
  int v7; // r12
  unsigned int v8; // r6
  unsigned int v9; // r5
  _BYTE *v10; // r8
  unsigned int v11; // r3
  unsigned int v12; // r3
  unsigned int v13; // r3
  unsigned int v14; // r1
  _BYTE *v15; // r5
  _DWORD *v16; // r3
  int v17; // r3
  int v18; // r1
  int v19; // r0
  _BYTE *v20; // r5
  _DWORD *v21; // r2
  int v22; // r1
  int v23; // r0
  int v24; // r3

  v3 = *(unsigned __int8 *)(a3 + 116);
  v4 = off_129158;
  v6 = *(_DWORD *)(a3 + 4);
  v7 = *(unsigned __int8 *)off_129158;
  v8 = *(unsigned __int16 *)(dword_129154 + 696 * v3 + 32);
  *(_DWORD *)(a3 + 4) = v6 & 0xFFFFFFFE;
  v9 = result;
  if ( v7 )
  {
    if ( result )
    {
      if ( *(_BYTE *)(a3 + 114) )
      {
        v10 = (_BYTE *)(result + 4);
      }
      else
      {
        v10 = (_BYTE *)(result + 4);
        if ( ((*(unsigned __int8 *)((*(unsigned __int8 *)(a3 + 117) >> 3) + result + 4) >> (*(_BYTE *)(a3 + 117) & 7))
            & 1) != 0 )
        {
          v16 = off_12915C;
          *(_DWORD *)(a3 + 4) = v6 & 0xFFFFFFFC | 2;
          if ( (*v16 & 0x200) != 0 )
            *v16 &= ~0x200u;
          if ( !*((_BYTE *)v4 + 29) )
          {
            v17 = *((_DWORD *)off_129170 + 4);
            v18 = *(unsigned __int16 *)(*(_DWORD *)off_12916C + 56);
            v19 = dword_129174;
            v4[5] = a3;
            *((_BYTE *)v4 + 29) = 5;
            timestamp_update(v19, v18 + v17);
          }
        }
        else
        {
          *(_DWORD *)(a3 + 4) = v6 & 0xFFFFFFFC;
        }
      }
      v11 = *v10 & 0xFE;
      result = v8 >> 3;
      if ( v11 <= v8 >> 3
        && result <= *(unsigned __int8 *)(v9 + 1) - 4 + v11
        && (result += v9, (*(unsigned __int8 *)(result - v11 + 5) & (1 << (v8 & 7))) != 0) )
      {
        if ( (*(_DWORD *)off_12915C & 0x200) != 0 )
          *(_DWORD *)off_12915C &= ~0x200u;
        if ( !*(_BYTE *)off_129160 )
        {
          sub_128EA0();
          if ( !*((_BYTE *)v4 + 28) || (*(_DWORD *)off_129168 & 4) != 0 )
          {
            *(_BYTE *)off_129164 = 0;
          }
          else
          {
            v20 = off_129164;
            if ( *(_BYTE *)off_129164 && (sub_1228E8() != 1 || !*((_DWORD *)off_129178 + 126)) )
              sub_118DC4(*(unsigned __int8 *)(a3 + 116), 0, 0);
            *v20 = 1;
          }
          v21 = off_129170;
          v22 = *(unsigned __int16 *)(*(_DWORD *)off_12916C + 58);
          v23 = dword_129174;
          *(_DWORD *)(a3 + 4) |= 4u;
          v24 = v21[4];
          v4[5] = a3;
          *((_BYTE *)v4 + 29) = 6;
          return timestamp_update(v23, v22 + v24);
        }
      }
      else
      {
        v12 = *(_DWORD *)(a3 + 4) & 0xFFFFFFFB;
        *(_BYTE *)off_129164 = 0;
        *(_DWORD *)(a3 + 4) = v12;
      }
    }
  }
  else if ( result
         && (*(_DWORD *)off_129168 & 4) == 0
         && (v13 = *(_BYTE *)(result + 4) & 0xFE, v14 = v8 >> 3, v13 <= v8 >> 3)
         && v14 <= *(unsigned __int8 *)(result + 1) - 4 + v13
         && (*(unsigned __int8 *)(result + v14 - v13 + 5) & (1 << (v8 & 7))) != 0 )
  {
    v15 = off_129164;
    if ( *(_BYTE *)off_129164 )
    {
      result = sub_1228E8();
      if ( result != 1 || !*((_DWORD *)off_129178 + 126) )
        result = sub_118DC4(*(unsigned __int8 *)(a3 + 116), 0, 0);
    }
    *v15 = 1;
  }
  else
  {
    *(_BYTE *)off_129164 = 0;
  }
  return result;
}

