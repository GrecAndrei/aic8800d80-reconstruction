// sub_101B00 @ 0x101b00, size 550 bytes
// Doc: sub_1201B00 [mac]: FMAC init/setup routine reading state from globals
// sub_1201B00 [mac]: FMAC init/setup routine reading state from globals
int __fastcall sub_101B00(int a1, _BYTE *a2, _BYTE *a3)
{
  int result; // r0
  unsigned int v5; // r10
  int v7; // r9
  int v8; // r6
  char v9; // r8
  char v10; // r11
  unsigned int v11; // r3
  unsigned int v12; // r2
  unsigned int v13; // r3
  int v14; // r2
  int v15; // r6
  char v16; // r8
  unsigned int v17; // r3
  char v18; // r3
  int v19; // r2
  int v20; // r2
  int v21; // r3
  unsigned int v22; // [sp+4h] [bp-8h]

  result = *((unsigned __int8 *)off_101D28 + 36);
  v5 = *((unsigned __int16 *)off_101D28 + 20);
  if ( !*((_BYTE *)off_101D28 + 36) )
  {
    if ( *((_BYTE *)off_101D2C + 197) )
    {
      if ( v5 > 0x97B )
      {
        if ( v5 > 0x994 )
          result = 2;
        else
          result = 1;
      }
      v7 = *((char *)off_101D2C + 198);
      v8 = *((char *)off_101D2C + 210);
      v9 = *((_BYTE *)off_101D34 + 10) + *(_BYTE *)off_101D38 + *(_BYTE *)(*(_DWORD *)off_101D30 + result + 6);
      v10 = *(_BYTE *)off_101D38 + *((_BYTE *)off_101D34 + 8) + *(_BYTE *)(*(_DWORD *)off_101D30 + result);
      v11 = v10;
      if ( *((_BYTE *)off_101D2C + 396) )
      {
        result = *(unsigned __int8 *)(*(_DWORD *)off_101D3C + result);
        v7 = (char)(result + v7);
        v8 = (char)(v8 + result);
      }
      if ( (*((_DWORD *)off_101D2C + 98) & 2) != 0 )
      {
        result = sub_1321FC(0, *((unsigned __int16 *)off_101D28 + 20));
        v11 = v10;
        if ( result )
        {
          v20 = *(char *)(result + 4);
        }
        else
        {
          if ( **(__int16 **)off_101D48 < 0 )
          {
            sub_12F49C(dword_101D50, dword_101D4C, 6857);
            v11 = v10;
          }
          v22 = v11;
          result = msg_parse(dword_101D54, 0, v5);
          v11 = v22;
          v20 = 15;
        }
        if ( v7 >= v20 )
          LOBYTE(v7) = v20;
        if ( v8 >= v20 )
          LOBYTE(v8) = v20;
      }
      if ( (v10 & 1) != 0 )
        v12 = v11 - 1;
      else
        v12 = v11 + (v11 >> 31);
      if ( (v10 & 1) != 0 )
        v12 += v12 >> 31;
      if ( (v9 & 1) != 0 )
        v13 = v9 - 1 + ((unsigned int)(v9 - 1) >> 31);
      else
        v13 = v9 + ((unsigned int)v9 >> 31);
      *a2 = (v12 >> 1) + v7;
      *a3 = (v13 >> 1) + v8;
      return result;
    }
    if ( **(__int16 **)off_101D48 >= 0 )
      return result;
    v19 = 6875;
    return sub_12F46C(dword_101D50, dword_101D4C, v19);
  }
  if ( !*((_BYTE *)off_101D2C + 197) )
  {
    if ( **(__int16 **)off_101D48 >= 0 )
      return result;
    v19 = 6921;
    return sub_12F46C(dword_101D50, dword_101D4C, v19);
  }
  if ( v5 <= 0x1666 )
  {
    if ( v5 > 0x1616 )
    {
      v14 = 4;
    }
    else if ( v5 > 0x15C6 )
    {
      v14 = 3;
    }
    else if ( v5 > 0x1571 )
    {
      v14 = 2;
    }
    else
    {
      v14 = v5 > 0x1486;
    }
  }
  else
  {
    v14 = 5;
  }
  result = *((unsigned __int8 *)off_101D2C + 396);
  v15 = *((char *)off_101D2C + 236);
  v16 = *((_BYTE *)off_101D38 + 1) + *((_BYTE *)off_101D34 + 11) + *(_BYTE *)(*(_DWORD *)off_101D40 + v14);
  if ( *((_BYTE *)off_101D2C + 396) )
    v15 = (char)(*(_BYTE *)(*(_DWORD *)off_101D44 + v14) + v15);
  if ( (*((_DWORD *)off_101D2C + 98) & 2) != 0 )
  {
    result = sub_1321FC(1, *((unsigned __int16 *)off_101D28 + 20));
    if ( result )
    {
      v21 = *(char *)(result + 4);
    }
    else
    {
      if ( **(__int16 **)off_101D48 < 0 )
        sub_12F49C(dword_101D50, dword_101D4C, 6907);
      result = msg_parse(dword_101D54, 1, v5);
      v21 = 15;
    }
    if ( v15 >= v21 )
      LOBYTE(v15) = v21;
  }
  if ( (v16 & 1) != 0 )
    v17 = v16 - 1 + ((unsigned int)(v16 - 1) >> 31);
  else
    v17 = v16 + ((unsigned int)v16 >> 31);
  v18 = (v17 >> 1) + v15;
  *a3 = v18;
  *a2 = v18;
  return result;
}

