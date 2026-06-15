// v23 annotated: sub_14216C @ 0x14216c
// Original: 14216c_sub_14216C.c
// Primary struct: <unclustered>
//
// sub_14216C @ 0x14216c, size 582 bytes
unsigned int __fastcall sub_14216C(unsigned int result)
{
  int v1; // r1
  int v2; // r2
  int v3; // r5
  unsigned int v4; // r4
  int v5; // r6
  int v6; // r3
  int v7; // r3
  int v8; // r6
  int v9; // r5
  int v10; // r3
  int v11; // r5
  int v12; // r4
  _BYTE *v13; // r1
  char v14; // r3
  unsigned int v15; // r9
  __int16 v16; // r8
  unsigned __int16 *v17; // r7
  unsigned int v18; // r10
  int v19; // r11
  unsigned int v20; // r8
  char *v21; // r8
  int v22; // r5
  int v23; // r7
  __int16 v24; // r2
  char v25; // r3
  int v26; // r0
  _WORD *v27; // r3
  char v28; // r12
  char v29; // r0
  int v30; // r4
  char *v31; // r11
  char v32; // r3
  char v33; // r3
  __int64 v34; // r0
  __int64 v35; // r0
  unsigned __int8 v36; // r0
  __int16 v37[38]; // [sp+0h] [bp-4Ch] BYREF

  v1 = *(unsigned __int8 *)(result + 7);
  v2 = *(unsigned __int8 *)(result + 8);
  v3 = dword_1423B4;
  v4 = result;
  v5 = v2;
  if ( (v1 != 255 || !*(_BYTE *)(dword_1423B4 + 1320 * v2 + 108))
    && (*(_DWORD *)(dword_1423B4 + 1320 * v2 + 472) & 8) != 0 )
  {
    if ( *(_BYTE *)(result + 12) == 22 )
    {
      v6 = *(unsigned __int8 *)(result + 13);
      result += 12;
      if ( v6 == 6 )
      {
        v15 = *(unsigned __int8 *)(v4 + 17);
        v16 = *(_WORD *)v4;
        v17 = (unsigned __int16 *)(v4 + 18);
        v18 = *(unsigned __int16 *)(v4 + 18);
        if ( **(__int16 **)off_1423B8 < 0 && v2 == 255 )
        {
          result = sub_12F694(dword_1423D0, dword_1423CC, 637);
          v5 = *(unsigned __int8 *)(v4 + 8);
        }
        if ( (v15 & 0xC) == 0 )
        {
          v19 = (v18 >> 1) & 7;
          v20 = (unsigned __int16)(v16 - 6);
          if ( v19 == 4 )
          {
            if ( (v18 & 1) == 0 )
            {
              v26 = v3 + 1320 * v5;
              if ( *(_QWORD *)(v26 + 40) )
              {
                v27 = (_WORD *)dword_1423BC;
                v28 = *(_BYTE *)(v26 + 107);
                v29 = *(_BYTE *)(v4 + 7);
                v30 = v18 & 1;
                do
                {
                  if ( (*v27 & 1) == 0 )
                    v30 = (int)v27;
                  v27 += 36;
                }
                while ( (_WORD *)(dword_1423BC + 576) != v27 );
                v31 = (char *)off_1423C0;
                *(_BYTE *)(v30 + 47) = v28;
                v32 = *v31;
                *(_BYTE *)(v30 + 46) = v29;
                *(_BYTE *)(v30 + 2) = v32;
                *(_BYTE *)(v30 + 41) = 0;
                sub_100200((int *)(v30 + 32), 0, 9u);
                v33 = *v31;
                *(_WORD *)v30 = 1;
                *v31 = v33 + 1;
                sub_141D1C(v17, v20, v15, (__int16 *)v30);
                sub_141E38(4, v30);
                LODWORD(v34) = sub_12C068();
                v35 = *(_QWORD *)(v30 + 24) - v34 - *(_QWORD *)(v3 + 1320 * v5 + 40);
                v36 = sub_1434B0(v35, HIDWORD(v35), *(_DWORD *)(v30 + 16), 0);
                return sub_141DE8(v30, v36);
              }
              else
              {
                return sub_14207C(*(unsigned __int8 *)(v26 + 107), *(unsigned __int8 *)(v4 + 7), (v18 >> 7) & 7);
              }
            }
          }
          else if ( v19 == 7 )
          {
            sub_141D1C((unsigned __int16 *)(v4 + 18), v20, v15, v37);
            return sub_141E38((v18 >> 1) & 7, (int)v37);
          }
        }
      }
      else if ( v6 == 7 )
      {
        result = *(unsigned __int8 *)(v4 + 14);
        v7 = (result >> 5) & 3;
        if ( (result & 0x60) == 0 )
        {
          v8 = dword_1423BC;
          if ( (result & 0x80) != 0 )
          {
            v21 = (char *)off_1423C0;
            v22 = (result >> 5) & 3;
            v23 = dword_1423BC + 576;
            do
            {
              if ( (*(_WORD *)v8 & 1) != 0
                && *(unsigned __int8 *)(v8 + 46) == *(unsigned __int8 *)(v4 + 7)
                && *(unsigned __int8 *)(v8 + 47) == *(unsigned __int8 *)(v4 + 8) )
              {
                result = sub_141F70(v8);
                v24 = *(_WORD *)v8;
                v25 = *v21;
                *(_BYTE *)(v8 + 2) = v22;
                *(_WORD *)v8 = v24 & 0xFFFE;
                *v21 = v25 - 1;
              }
              v8 += 72;
            }
            while ( v8 != v23 );
          }
          else
          {
            v9 = result & 7;
            result = dword_1423BC;
            while ( (*(_WORD *)result & 1) == 0
                 || *(unsigned __int8 *)(result + 47) != v2
                 || *(unsigned __int8 *)(result + 46) != v1
                 || *(unsigned __int8 *)(result + 2) != v9 )
            {
              ++v7;
              result += 72;
              if ( v7 == 8 )
                return result;
            }
            v10 = 9 * v7;
            v11 = dword_1423BC + 8 * v10;
            v12 = 8 * v10;
            sub_141F70(v11);
            v13 = off_1423C0;
            v14 = *(_BYTE *)off_1423C0 - 1;
            *(_WORD *)(v8 + v12) &= ~1u;
            *(_BYTE *)(v11 + 2) = 0;
            *v13 = v14;
            return 0;
          }
        }
      }
    }
    else if ( **(__int16 **)off_1423B8 < 0 )
    {
      return sub_12F694(dword_1423C8, dword_1423C4, 828);
    }
  }
  return result;
}

