// fwstruct annotate: 133e98_sub_133E98.c
// sub_133E98 @ 0x133e98, size 416 bytes
int __fastcall sub_133E98(int a1, int a2, __int16 a3, __int16 a4)
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
  if ( msg_get_value(6u) != 10 )
  {
    v8 = (_BYTE *)sub_12C92C(6145, a4, a3, 1u);
    if ( msg_get_value(6u) )
    {
      *v8 = 8;
      v19 = 0;
    }
    else if ( *(unsigned __int8 *)(a2 + 61) > 3u
           || (v9 = dword_134058, v10 = (_BYTE *)(dword_134058 + 1320 * v4), v10[106]) )
    {
      *v8 = 4;
      v19 = 0;
    }
    else
    {
      if ( !v10[108] )
      {
        v11 = (__int16 **)off_13405C;
        if ( **(__int16 **)off_13405C < 0 )
        {
          if ( (unsigned __int8)v10[116] == 255 || (sub_12F46C(dword_134050, dword_13404C, 102), **v11 < 0) )
          {
            if ( *(_DWORD *)(v9 + 1320 * v4 + 72) )
              sub_12F46C(dword_134054, dword_13404C, 103);
          }
        }
        v12 = off_134060;
        *((_BYTE *)off_134060 + 33) = 0;
        goto LABEL_8;
      }
      v21 = *(_DWORD *)(a2 + 48) & 0x20;
      if ( v21 )
      {
        v12 = off_134060;
        v22 = dword_134048;
        *((_BYTE *)off_134060 + 33) = 1;
        msg_parse(v22, v21);
LABEL_8:
        v13 = (int *)off_13403C;
        v14 = off_134040;
        *(_BYTE *)off_134038 = 0;
        v15 = *v13;
        v14[32] = 0;
        *v13 = v15 | 0x10;
        v16 = *(unsigned __int8 *)(a2 + 59);
        v14[14] = 1;
        if ( v16 == 3 && rx_descriptor_init(a2 + 64, *(unsigned __int16 *)(a2 + 54)) > 0 )
          *(_BYTE *)(a2 + 59) = 0;
        v12[4] = a2;
        v17 = sub_12C92C(6146, a4, a3, 0x354u);
        v18 = *((unsigned __int8 *)v12 + 33);
        v12[5] = v17;
        if ( v18 )
        {
          sub_143770(dword_134044, v9 + 1320 * *(unsigned __int8 *)(a2 + 61) + 64, 6);
          fmac_msg_alloc_and_send(v9 + 1320 * *(unsigned __int8 *)(a2 + 61), 0, 0);
        }
        else
        {
          v23 = 0;
          v24 = 0;
          sub_134474(&v23, &v24);
          if ( v23 && v24 )
            sub_1345C0(v23, v24, 0);
          else
            sub_1344C0();
        }
        *v8 = 0;
        v19 = 1;
        goto LABEL_13;
      }
      v19 = 0;
      *v8 = 9;
    }
LABEL_13:
    sdio_buffer_prepare_n_4e8((int)v8);
    return v19;
  }
  return 2;
}

