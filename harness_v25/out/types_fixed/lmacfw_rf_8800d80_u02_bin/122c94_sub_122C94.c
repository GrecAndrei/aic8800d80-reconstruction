// sub_122C94 @ 0x122c94, size 256 bytes
// Doc: sub_1222C94 [unknown]: Check bit 1 of 32-bit value loaded from 0x40500000 and branch on it
// sub_1222C94 [unknown]: Check bit 1 of 32-bit value loaded from 0x40500000 and branch on it
int __fastcall sub_122C94(int a1, int a2, int a3)
{
  int v3; // r3
  int v4; // r0
  int v7; // r5
  int v8; // r6
  int v9; // [sp+Ch] [bp-4h] BYREF

  v3 = HIBYTE(*(_DWORD *)off_122D94) & 2;
  if ( a1 )
  {
    if ( a1 == 1 )
    {
      if ( (unsigned int)(a2 + 7) > 0xF )
      {
        msg_parse(dword_122DB0);
        return -12;
      }
      else
      {
        v7 = 10 * a2;
        if ( v3 )
        {
          v8 = sub_1140F0(a2);
          if ( v8 < 0 )
          {
            msg_parse(dword_122DB4);
            return -11;
          }
          else
          {
            msg_parse(dword_122DA4, a2, v8, v7 + 30, v7 + 39);
            return a2 | (v8 << 8);
          }
        }
        else
        {
          *(_WORD *)((char *)&v9 + 1) = 0;
          HIBYTE(v9) = 0;
          LOBYTE(v9) = a2;
          sub_1145D0((int)&v9);
          msg_parse(dword_122DA0, a2, v7 + 30, v7 + 39);
          return (char)v9 | 0xF00;
        }
      }
    }
    else
    {
      msg_parse(dword_122DAC, a2, a3, v3);
      return -21;
    }
  }
  else if ( v3 )
  {
    v4 = sub_1140B8(&v9);
    msg_parse(dword_122D98, v9, v4, 10 * v9 + 30, 10 * v9 + 39);
    return (char)v9;
  }
  else
  {
    v9 = 0;
    if ( sub_1145C4((int)&v9) )
    {
      msg_parse(dword_122DA8);
      return 3584;
    }
    else
    {
      msg_parse(dword_122D9C, (char)v9, 10 * (char)v9 + 30, 10 * (char)v9 + 39);
      return (char)v9 | 0xF00;
    }
  }
}

