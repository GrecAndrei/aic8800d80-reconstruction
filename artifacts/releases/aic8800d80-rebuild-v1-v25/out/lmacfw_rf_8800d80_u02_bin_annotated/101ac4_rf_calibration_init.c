// fwstruct annotate: 101ac4_rf_calibration_init.c
// rf_calibration_init @ 0x101ac4, size 384 bytes
// Doc: rf_calibration_init [rf]: Initialize RF calibration parameters
// rf_calibration_init [rf]: Initialize RF calibration parameters
int __fastcall rf_calibration_init(int a1, _BYTE *a2, _BYTE *a3)
{
  int result; // r0
  unsigned int v4; // r3
  int v5; // r7
  char v6; // r4
  int v7; // r3
  char v8; // r5
  unsigned int v9; // r0
  int v10; // r0
  unsigned __int8 v11; // r5
  int v12; // r3
  char v13; // r3
  char v14; // r5

  result = *((unsigned __int8 *)off_101C44 + 36);
  v4 = *((unsigned __int16 *)off_101C44 + 20);
  if ( *((_BYTE *)off_101C44 + 36) )
  {
    result = *((unsigned __int8 *)off_101C48 + 197);
    if ( *((_BYTE *)off_101C48 + 197) )
    {
      if ( v4 <= 0x1666 )
      {
        if ( v4 > 0x1616 )
        {
          v10 = 4;
        }
        else if ( v4 > 0x15C6 )
        {
          v10 = 3;
        }
        else if ( v4 > 0x1571 )
        {
          v10 = 2;
        }
        else
        {
          v10 = v4 > 0x1486;
        }
      }
      else
      {
        v10 = 5;
      }
      v11 = *((_BYTE *)off_101C48 + 236);
      v12 = (char)(*((_BYTE *)off_101C54 + 1) + *((_BYTE *)off_101C50 + 11) + *(_BYTE *)(*(_DWORD *)off_101C58 + v10));
      if ( *((_BYTE *)off_101C48 + 396) )
        result = (unsigned __int8)(*(_BYTE *)(*(_DWORD *)off_101C6C + v10) + v11);
      else
        result = v11;
      if ( (v12 & 1) != 0 )
        v12 = (char)v12 - 1;
      v13 = v12 / 2 + result;
      *a3 = v13;
      *a2 = v13;
    }
    else if ( **(__int16 **)off_101C5C < 0 )
    {
      return rf_cmd_send_n264(dword_101C64, dword_101C60, 6921);
    }
  }
  else if ( *((_BYTE *)off_101C48 + 197) )
  {
    if ( v4 > 0x97B )
    {
      if ( v4 > 0x994 )
        result = 2;
      else
        result = 1;
    }
    LOBYTE(v5) = *((_BYTE *)off_101C48 + 198);
    v6 = *(_BYTE *)off_101C54 + *((_BYTE *)off_101C50 + 8) + *(_BYTE *)(*(_DWORD *)off_101C4C + result);
    v7 = (char)(*((_BYTE *)off_101C50 + 10) + *(_BYTE *)off_101C54 + *(_BYTE *)(*(_DWORD *)off_101C4C + result + 6));
    if ( *((_BYTE *)off_101C48 + 396) )
    {
      v14 = *(_BYTE *)(*(_DWORD *)off_101C68 + result);
      v5 = (unsigned __int8)(v5 + v14);
      v8 = v14 + *((_BYTE *)off_101C48 + 210);
    }
    else
    {
      v5 = (unsigned __int8)v5;
      v8 = *((_BYTE *)off_101C48 + 210);
    }
    if ( ((*(_BYTE *)off_101C54 + *((_BYTE *)off_101C50 + 8) + *(_BYTE *)(*(_DWORD *)off_101C4C + result)) & 1) != 0 )
      v9 = v6 - 1 + ((unsigned int)(v6 - 1) >> 31);
    else
      v9 = v6 + ((unsigned int)v6 >> 31);
    if ( (v7 & 1) != 0 )
      v7 = (char)v7 - 1;
    result = (unsigned __int8)(v9 >> 1) + v5;
    *a2 = result;
    *a3 = v7 / 2 + v8;
  }
  else if ( **(__int16 **)off_101C5C < 0 )
  {
    return rf_cmd_send_n264(dword_101C64, dword_101C60, 6875);
  }
  return result;
}

