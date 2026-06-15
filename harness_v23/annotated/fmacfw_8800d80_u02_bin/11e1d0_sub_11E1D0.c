// v23 annotated: sub_11E1D0 @ 0x11e1d0
// Original: 11e1d0_sub_11E1D0.c
// Primary struct: <unclustered>
//
// sub_11E1D0 @ 0x11e1d0, size 148 bytes
int __fastcall sub_11E1D0(int result, int a2, int a3, int a4)
{
  int v4; // r7
  __int16 **v5; // r10
  int v6; // r11
  int v7; // r1
  unsigned int v9; // r8
  __int16 v10; // r3
  __int64 v11; // r4
  int v12; // r6
  int v13; // r4
  int v14; // r3
  _DWORD *v15; // r2
  _DWORD *v16; // r5
  int v17; // r3

  if ( a2 )
  {
    v4 = result;
    v5 = (__int16 **)off_11E268;
    v6 = dword_11E26C;
    result = a2;
    v7 = dword_11E264;
    v9 = 0;
    while ( 1 )
    {
      v11 = *(_QWORD *)(v4 + 8);
      v10 = WORD2(v11) + 1;
      HIDWORD(v11) = (unsigned __int16)(WORD2(v11) + 1 - v11) - a3;
      if ( result < SHIDWORD(v11) )
      {
        v12 = 0;
      }
      else
      {
        v12 = (unsigned __int16)(v11 - v10 + a3 + result);
        result = WORD2(v11);
      }
      v13 = v11 + a3;
      v14 = a4 + 4 * (v9 >> 2);
      if ( (unsigned int)(result + 3) >> 2 )
      {
        v15 = (_DWORD *)(a4 + 4 * (v9 >> 2));
        v16 = (_DWORD *)(v14 + 4 * ((unsigned int)(result + 3) >> 2));
        v17 = v13 - v14;
        do
        {
          *v15 = *(_DWORD *)((char *)v15 + v17);
          ++v15;
        }
        while ( v15 != v16 );
      }
      if ( !v12 )
        break;
      v4 = *(_DWORD *)(v4 + 4);
      v9 = (unsigned __int16)(v9 + result);
      if ( **v5 < 0 && !v4 )
      {
        sub_12F46C(v6, v7, 1189);
        v7 = dword_11E264;
      }
      result = v12;
      a3 = 0;
    }
  }
  return result;
}

