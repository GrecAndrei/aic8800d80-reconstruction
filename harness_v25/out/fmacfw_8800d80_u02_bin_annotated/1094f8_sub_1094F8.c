// fwstruct annotate: 1094f8_sub_1094F8.c
// sub_1094F8 @ 0x1094f8, size 32 bytes
int __fastcall sub_1094F8(int result, int a2, _BYTE *a3, char *a4, int *a5)
{
  unsigned int v5; // r3
  __int64 v6; // kr00_8
  char v7; // r3
  char v8; // r3
  int v9; // r3
  char v10; // r3
  char v11; // r3
  char v12; // r3
  int v13; // r4
  char v14; // r3
  int v15; // r3
  char v16; // r3
  int savedregs; // [sp+0h] [bp+0h]
  int savedregs_4; // [sp+4h] [bp+4h]

  if ( a2 == 15 )
  {
    if ( result == 1 )
    {
      v15 = *a5;
      if ( *a5 >= 0x2000 )
      {
        *a4 = 48;
      }
      else if ( v15 <= 0 )
      {
        if ( v15 > -8192 )
          v16 = -80;
        else
          v16 = -48;
        *a4 = v16;
      }
      else
      {
        *a4 = 80;
      }
    }
    else if ( result == 2 )
    {
      savedregs_4 = savedregs;
      v13 = *a5;
      if ( *a5 >= 0x2000 )
      {
        a4[1] = *a4 + 16;
        *a3 = 1;
        return 1;
      }
      else if ( v13 <= 0 )
      {
        if ( v13 > -8192 )
        {
          if ( a5[1] <= 0 )
            result = 6;
          else
            result = 5;
          a4[1] = *a4 - 16;
          *a3 = result;
        }
        else
        {
          a4[1] = *a4 - 16;
          *a3 = 4;
          return 4;
        }
      }
      else
      {
        v14 = *a4;
        if ( a5[1] < 0 )
          v14 += 16;
        else
          result = 3;
        if ( a5[1] >= 0 )
          v14 -= 16;
        a4[1] = v14;
        *a3 = result;
      }
    }
    else
    {
      switch ( *a3 )
      {
        case 1:
          if ( a5[2] <= 0 )
            goto LABEL_62;
          a4[2] = 32;
          break;
        case 2:
          if ( a5[2] <= 0 )
            goto LABEL_64;
          a4[2] = 64;
          break;
        case 3:
          a4[2] = 56;
          break;
        case 4:
          if ( a5[2] <= 0 )
            a4[2] = -32;
          else
LABEL_64:
            a4[2] = -112;
          break;
        case 5:
          if ( a5[2] <= 0 )
            a4[2] = -64;
          else
LABEL_62:
            a4[2] = 112;
          break;
        case 6:
          a4[2] = -56;
          break;
        default:
          a4[2] = -120;
          break;
      }
    }
  }
  else if ( result == 1 )
  {
    v9 = *a5;
    if ( *a5 >= 0x2000 )
    {
      *a4 = 32;
    }
    else if ( v9 <= 0 )
    {
      if ( v9 > -8192 )
        v10 = -64;
      else
        v10 = -32;
      *a4 = v10;
    }
    else
    {
      *a4 = 64;
    }
  }
  else if ( result == 2 )
  {
    v6 = *(_QWORD *)a5;
    if ( *a5 <= 0 )
    {
      if ( SHIDWORD(v6) <= 0 )
      {
        v11 = *a4;
        if ( (int)v6 >= 2 * HIDWORD(v6) )
          v12 = v11 + 24;
        else
          v12 = v11 + 16;
        a4[1] = v12;
      }
      else
      {
        a4[1] = *a4 - 32;
      }
    }
    else if ( v6 < 0 )
    {
      a4[1] = *a4 + 32;
    }
    else
    {
      v7 = *a4;
      if ( (int)v6 <= 2 * HIDWORD(v6) )
        v8 = v7 - 24;
      else
        v8 = v7 - 16;
      a4[1] = v8;
    }
  }
  else
  {
    v5 = (unsigned __int8)a4[1];
    if ( v5 <= 0x10 )
    {
LABEL_7:
      a4[2] = 48;
      return result;
    }
    if ( v5 <= 0x30 )
    {
      a4[2] = 24;
      return result;
    }
    if ( v5 > 0x60 )
    {
      if ( v5 > 0xC0 )
      {
        if ( v5 <= 0xD8 )
        {
          a4[2] = -24;
          return result;
        }
      }
      else
      {
        if ( a5[2] > 0 )
        {
          a4[2] = 96;
          return result;
        }
        if ( v5 == 160 )
        {
          a4[2] = -32;
          return result;
        }
      }
      a4[2] = -48;
      return result;
    }
    if ( a5[2] < 0 )
    {
      a4[2] = -96;
    }
    else
    {
      if ( v5 != 96 )
        goto LABEL_7;
      a4[2] = 32;
    }
  }
  return result;
}

