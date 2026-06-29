// fwstruct annotate: 133d58_sub_133D58.c
// sub_133D58 @ 0x133d58, size 416 bytes
int __fastcall sub_133D58(int a1, int a2, __int16 a3, __int16 a4)
{
  int v4; // r9
  _BYTE *v8; // r5
  int v9; // r8
  _BYTE *v10; // r3
  __int16 **v11; // r10
  _DWORD *v12; // r9
  int *v13; // r1
  _BYTE *v14; // r2
  int v15; // r3
  int v16; // r3
  int v17; // r0
  int v18; // r6
  int v19; // r4
  int v21; // r1
  int v22; // r0
  int v23; // [sp+0h] [bp-8h] BYREF
  int v24; // [sp+4h] [bp-4h] BYREF

  v4 = *(unsigned __int8 *)(a2 + 61);
  if ( sub_12CD48(6u) != 10 )
  {
    v8 = (_BYTE *)sub_12C7EC(6145, a4, a3, 1u);
    if ( sub_12CD48(6u) )
    {
      *v8 = 8;
      v19 = 0;
    }
    else if ( *(unsigned __int8 *)(a2 + 61) > 3u
           || (v9 = dword_133F18, v10 = (_BYTE *)(dword_133F18 + 1320 * v4), v10[106]) )
    {
      *v8 = 4;
      v19 = 0;
    }
    else
    {
      if ( !v10[108] )
      {
        v11 = (__int16 **)off_133F1C;
        if ( **(__int16 **)off_133F1C < 0 )
        {
          if ( (unsigned __int8)v10[116] == 255 || (sub_12F32C(dword_133F10, dword_133F0C, 102), **v11 < 0) )
          {
            if ( *(_DWORD *)(v9 + 1320 * v4 + 72) )
              sub_12F32C(dword_133F14, dword_133F0C, 103);
          }
        }
        v12 = off_133F20;
        *((_BYTE *)off_133F20 + 33) = 0;
        goto LABEL_8;
      }
      v21 = *(_DWORD *)(a2 + 48) & 0x20;
      if ( v21 )
      {
        v12 = off_133F20;
        v22 = dword_133F08;
        *((_BYTE *)off_133F20 + 33) = 1;
        sub_12E948(v22, v21);
LABEL_8:
        v13 = (int *)off_133EFC;
        v14 = off_133F00;
        *(_BYTE *)off_133EF8 = 0;
        v15 = *v13;
        v14[32] = 0;
        *v13 = v15 | 0x10;
        v16 = *(unsigned __int8 *)(a2 + 59);
        v14[14] = 1;
        if ( v16 == 3 && sub_135970(a2 + 64, *(unsigned __int16 *)(a2 + 54)) > 0 )
          *(_BYTE *)(a2 + 59) = 0;
        v12[4] = a2;
        v17 = sub_12C7EC(6146, a4, a3, 0x354u);
        v18 = *((unsigned __int8 *)v12 + 33);
        v12[5] = v17;
        if ( v18 )
        {
          sub_143630(dword_133F04, v9 + 1320 * *(unsigned __int8 *)(a2 + 61) + 64, 6);
          sub_134C4C(v9 + 1320 * *(unsigned __int8 *)(a2 + 61), 0, 0);
        }
        else
        {
          v23 = 0;
          v24 = 0;
          sub_134334(&v23, &v24);
          if ( v23 && v24 )
            sub_134480(v23, v24, 0);
          else
            sub_134380();
        }
        *v8 = 0;
        v19 = 1;
        goto LABEL_13;
      }
      v19 = 0;
      *v8 = 9;
    }
LABEL_13:
    sub_12C84C((int)v8);
    return v19;
  }
  return 2;
}

