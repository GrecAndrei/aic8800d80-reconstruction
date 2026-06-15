// v23 annotated: sub_112F6C @ 0x112f6c
// Original: 112f6c_sub_112F6C.c
// Primary struct: <unclustered>
//
// sub_112F6C @ 0x112f6c, size 298 bytes
// Doc: sub_1212F6C [unknown]: Unknown behavioral stub
// sub_1212F6C [unknown]: Unknown behavioral stub
void __fastcall sub_112F6C(int a1, int a2, int a3, int a4)
{
  _BYTE *v4; // r5
  unsigned __int16 *v5; // r2
  int v6; // r1
  int v7; // r0
  _DWORD *v8; // r4
  _DWORD *v9; // r8
  unsigned int *v10; // r6
  unsigned int v11; // r1
  int v12; // r0
  int started; // r0
  _BYTE *v14; // r7
  int v15; // r9
  unsigned int v16; // r1
  int v17; // r0
  int v18; // r0
  unsigned __int16 *v19; // r3
  int v20; // r1

  v4 = off_113098;
  if ( *(_BYTE *)off_113098 )
  {
    if ( !*(_WORD *)off_1130A4 )
    {
      v6 = dword_1130C0;
      goto LABEL_6;
    }
    if ( *(unsigned __int8 *)off_1130A0 >= (unsigned int)*(unsigned __int16 *)off_1130A4 )
    {
      v19 = (unsigned __int16 *)off_1130A8;
      v20 = dword_1130AC;
      *(_BYTE *)off_11309C = 1;
      sub_11F74C(512, v20, *v19, v19);
    }
  }
  else
  {
    if ( *(_BYTE *)off_11309C )
      return;
    if ( *(unsigned __int8 *)off_1130A0 >= (unsigned int)*(unsigned __int16 *)off_1130A4 && !*(_BYTE *)off_11309C )
    {
      v5 = (unsigned __int16 *)off_1130A8;
      *(_BYTE *)off_11309C = 1;
      v6 = dword_1130AC;
      a3 = *v5;
LABEL_6:
      sub_11F74C(512, v6, a3, a4);
      return;
    }
  }
  v7 = (*(int (__fastcall **)(_DWORD))(*((_DWORD *)off_1130B0 + 2) + 16))(*((_DWORD *)off_1130B0 + 1));
  v8 = (_DWORD *)v7;
  if ( v7 )
  {
    if ( *v4 )
    {
      v9 = off_1130C8;
      v10 = (unsigned int *)off_1130B4;
      v11 = *(_DWORD *)off_1130B4;
      v12 = *(_DWORD *)off_1130C8 + v7;
      if ( *(_BYTE *)off_11309C )
        started = rf_stream_start2_cc0(v12, v11);
      else
        started = rf_stream_start_2c20(v12, v11);
    }
    else
    {
      v9 = off_1130C8;
      v10 = (unsigned int *)off_1130B4;
      started = rf_stream_start_2c20(*(_DWORD *)off_1130C8 + v7, *(_DWORD *)off_1130B4);
    }
    if ( started )
    {
      v14 = off_11309C;
      sub_10DA6C(dword_1130B8, started);
      v15 = 5;
      while ( 1 )
      {
        if ( *v4 )
        {
          v16 = *v10;
          v17 = (int)v8 + *v9;
          v18 = *v14 ? rf_stream_start2_cc0(v17, v16) : rf_stream_start_2c20(v17, v16);
        }
        else
        {
          v18 = rf_stream_start_2c20((int)v8 + *v9, *v10);
        }
        if ( !v18 )
          break;
        if ( !--v15 )
        {
          sub_10DA6C(dword_1130BC, 5);
          sub_10FEF8(v8);
          irq_nesting_or(256);
          return;
        }
      }
    }
  }
  else
  {
    irq_nesting_or(256);
    sub_10DA6C(dword_1130C4);
  }
}

