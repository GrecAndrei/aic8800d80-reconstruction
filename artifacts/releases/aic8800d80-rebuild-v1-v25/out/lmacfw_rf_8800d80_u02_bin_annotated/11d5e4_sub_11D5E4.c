// fwstruct annotate: 11d5e4_sub_11D5E4.c
// sub_11D5E4 @ 0x11d5e4, size 330 bytes
int sub_11D5E4()
{
  int v0; // r4
  int result; // r0
  int v2; // r3
  int v3; // r1
  int v4; // r0
  int v5; // r2

  v0 = *(_DWORD *)off_11D730 & *(_DWORD *)off_11D734;
  result = v0 << 29;
  *(_DWORD *)((char *)off_11D730 + 0xFFFFFFFC) = v0;
  if ( (v0 & 4) != 0 )
    result = rf_check_status_b4();
  if ( (v0 & 8) != 0 )
    result = sub_11D470();
  v2 = **(__int16 **)off_11D738;
  if ( v2 < 0 )
  {
    if ( (v0 & 0x400000) != 0 )
    {
      v3 = dword_11D73C;
      v4 = dword_11D744;
      v5 = 847;
    }
    else
    {
      v2 = v0 << 10;
      if ( (v0 & 0x200000) != 0 )
      {
        v3 = dword_11D73C;
        v4 = dword_11D748;
        v5 = 848;
      }
      else if ( (v0 & 0x40) != 0 )
      {
        v3 = dword_11D73C;
        v4 = dword_11D74C;
        v5 = 849;
      }
      else if ( (v0 & 0x100) != 0 )
      {
        v3 = dword_11D73C;
        v4 = dword_11D750;
        v5 = 850;
      }
      else if ( (v0 & 0x1000) != 0 )
      {
        v3 = dword_11D73C;
        v4 = dword_11D754;
        v5 = 851;
      }
      else
      {
        v2 = v0 << 18;
        if ( (v0 & 0x2000) != 0 )
        {
          v3 = dword_11D73C;
          v4 = dword_11D758;
          v5 = 852;
        }
        else if ( (v0 & 0x4000) != 0 )
        {
          v3 = dword_11D73C;
          v4 = dword_11D75C;
          v5 = 853;
        }
        else if ( (v0 & 0x8000) != 0 )
        {
          v3 = dword_11D73C;
          v4 = dword_11D760;
          v5 = 854;
        }
        else if ( (v0 & 0x10000) != 0 )
        {
          v3 = dword_11D73C;
          v4 = dword_11D764;
          v5 = 855;
        }
        else
        {
          v2 = v0 << 14;
          if ( (v0 & 0x20000) != 0 )
          {
            v3 = dword_11D73C;
            v4 = dword_11D768;
            v5 = 856;
          }
          else
          {
            result = v0 << 7;
            if ( (v0 & 0x1000000) != 0 )
            {
              v3 = dword_11D73C;
              v4 = dword_11D76C;
              v5 = 857;
            }
            else if ( (v0 & 0x2000000) != 0 )
            {
              v3 = dword_11D73C;
              v4 = dword_11D770;
              v5 = 858;
            }
            else if ( (v0 & 0x100000) != 0 )
            {
              v3 = dword_11D73C;
              v4 = dword_11D774;
              v5 = 859;
            }
            else
            {
              v2 = 16 * v0;
              if ( (v0 & 0x8000000) == 0 )
                return result;
              v3 = dword_11D73C;
              v4 = dword_11D740;
              v5 = 860;
            }
          }
        }
      }
    }
    return sub_121960(v4, v3, v5, v2);
  }
  return result;
}

