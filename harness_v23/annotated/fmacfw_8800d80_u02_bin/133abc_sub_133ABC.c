// v23 annotated: sub_133ABC @ 0x133abc
// Original: 133abc_sub_133ABC.c
// Primary struct: <unclustered>
//
// sub_133ABC @ 0x133abc, size 266 bytes
int sub_133ABC()
{
  int v0; // r2
  unsigned int v1; // r3
  _BYTE *v2; // r3
  _BYTE *v4; // r4
  int v5; // r3
  int v6; // r1
  int v7; // [sp+0h] [bp-Ch] BYREF
  int v8; // [sp+4h] [bp-8h] BYREF

  if ( **(__int16 **)off_133BC8 < 0 && sub_12CE88(6u) != 4 && sub_12CE88(6u) != 10 )
    sub_12F46C(dword_133BE0, dword_133BDC, 697);
  if ( sub_12CE88(6u) == 10 )
  {
    v4 = off_133BCC;
    v5 = *((unsigned __int8 *)off_133BCC + 4);
    *(_DWORD *)(*((_DWORD *)off_133BCC + 2) + 472) = 0;
    if ( v5 )
    {
      sub_12CA10(6148, 13, 6);
      v4[4] = 0;
    }
    sub_12C98C(*(_DWORD *)v4 + 12);
    v6 = (unsigned __int8)v4[33];
    *(_DWORD *)v4 = 0;
    if ( v6 )
    {
      v7 = 0;
      v8 = 0;
      sub_134474(&v7, &v8);
      sub_1345C0(v7, v8, 0);
    }
    else
    {
      sub_12CD34(6u, 0);
    }
    return 0;
  }
  else
  {
    v0 = *((_DWORD *)off_133BCC + 4);
    v1 = *(unsigned __int8 *)(v0 + 59);
    if ( v1 == 2 )
    {
      if ( (*(_DWORD *)(v0 + 48) & 0x40) != 0 )
      {
        sub_135364();
        v2 = off_133BD0;
        if ( *((_BYTE *)off_133BD0 + 13) )
        {
LABEL_6:
          if ( (v2[15] & 1) != 0 )
          {
            sub_12C5E4(6155, 6, dword_133BD4);
            sub_10D234();
          }
        }
        return 0;
      }
LABEL_5:
      sub_135168(1, 0);
      v2 = off_133BD0;
      if ( *((_BYTE *)off_133BD0 + 13) )
        goto LABEL_6;
      return 0;
    }
    if ( v1 <= 2 )
      goto LABEL_5;
    if ( v1 == 3 )
    {
      sub_135850(dword_133BD8);
      if ( *((_BYTE *)off_133BD0 + 13) )
        *((_BYTE *)off_133BD0 + 15) |= 2u;
      return 0;
    }
    sub_134E04(1);
    return 0;
  }
}

