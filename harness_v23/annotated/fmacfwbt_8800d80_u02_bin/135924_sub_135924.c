// v23 annotated: sub_135924 @ 0x135924
// Original: 135924_sub_135924.c
// Primary struct: <unclustered>
//
// sub_135924 @ 0x135924, size 84 bytes
// Doc: sub_1235924 [unknown]: Unidentified helper routine in fmacfwbt image
// sub_1235924 [unknown]: Unidentified helper routine in fmacfwbt image
// positive sp value has been detected, the output may be wrong!
int __fastcall sub_135924(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
  _BYTE *v11; // r4
  int v12; // r2
  int v13; // r3
  int v15; // r2
  int v16; // r6
  int v17; // r0
  int v18; // r7
  __int16 v19; // r3
  int v20; // r3
  int v22; // [sp-10h] [bp-24h] BYREF
  int v23; // [sp-Ch] [bp-20h]
  __int16 v24; // [sp-8h] [bp-1Ch]

  v11 = (_BYTE *)(dword_135A60 + 1320 * *(unsigned __int8 *)(a1 + 8));
  v12 = (unsigned __int8)v11[108];
  v22 = 0;
  v23 = 0;
  v24 = 0;
  if ( !v12
    || v11[106]
    || (v13 = *(unsigned __int8 *)(a1 + 7), v13 == 255)
    || (v15 = (unsigned __int8)v11[116], v15 != v13)
    || (v16 = dword_135A64 + 696 * v15, *(_BYTE *)(v16 + 52) != 2)
    || *(_BYTE *)(a1 + 13)
    || (v17 = sub_119084(*(unsigned __int8 *)(a1 + 6) != 0, 512), (v18 = v17) == 0) )
  {
    __asm { POP.W           {R4-R9,PC} }
  }
  v19 = *(_WORD *)(a1 + 4);
  LOBYTE(v22) = *(_BYTE *)(a1 + 6);
  LOWORD(v23) = v19;
  HIWORD(v22) = v19;
  ipc_msg_dispatch_454((int)v11, v17, (unsigned __int8 *)&v22);
  v20 = *(_DWORD *)(v18 + 72);
  *(_DWORD *)(v20 + 112) = *(_DWORD *)(v16 + 38);
  *(_BYTE *)(v20 + 108) = -48;
  return sub_1359CC();
}

