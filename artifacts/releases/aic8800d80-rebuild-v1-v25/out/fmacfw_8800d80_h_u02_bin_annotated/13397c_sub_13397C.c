// fwstruct annotate: 13397c_sub_13397C.c
// sub_13397C @ 0x13397c, size 266 bytes
int sub_13397C()
{
  int v0; // r2
  unsigned int v1; // r3
  _BYTE *v2; // r3
  _BYTE *v4; // r4
  int v5; // r3
  int v6; // r1
  int v7; // [sp+0h] [bp-Ch] BYREF
  int v8; // [sp+4h] [bp-8h] BYREF

  if ( **(__int16 **)off_133A88 < 0 && sub_12CD48(6u) != 4 && sub_12CD48(6u) != 10 )
    sub_12F32C(dword_133AA0, dword_133A9C, 697);
  if ( sub_12CD48(6u) == 10 )
  {
    v4 = off_133A8C;
    v5 = *((unsigned __int8 *)off_133A8C + 4);
    *(_DWORD *)(*((_DWORD *)off_133A8C + 2) + 472) = 0;
    if ( v5 )
    {
      sub_12C8D0(6148, 13, 6);
      v4[4] = 0;
    }
    sub_12C84C(*(_DWORD *)v4 + 12);
    v6 = (unsigned __int8)v4[33];
    *(_DWORD *)v4 = 0;
    if ( v6 )
    {
      v7 = 0;
      v8 = 0;
      sub_134334(&v7, &v8);
      sub_134480(v7, v8, 0);
    }
    else
    {
      sub_12CBF4(6u, 0);
    }
    return 0;
  }
  else
  {
    v0 = *((_DWORD *)off_133A8C + 4);
    v1 = *(unsigned __int8 *)(v0 + 59);
    if ( v1 == 2 )
    {
      if ( (*(_DWORD *)(v0 + 48) & 0x40) != 0 )
      {
        sub_135224();
        v2 = off_133A90;
        if ( *((_BYTE *)off_133A90 + 13) )
        {
LABEL_6:
          if ( (v2[15] & 1) != 0 )
          {
            sub_12C4A4(6155, 6, dword_133A94);
            sub_10D0F4();
          }
        }
        return 0;
      }
LABEL_5:
      sub_135028(1, 0);
      v2 = off_133A90;
      if ( *((_BYTE *)off_133A90 + 13) )
        goto LABEL_6;
      return 0;
    }
    if ( v1 <= 2 )
      goto LABEL_5;
    if ( v1 == 3 )
    {
      sub_135710(dword_133A98);
      if ( *((_BYTE *)off_133A90 + 13) )
        *((_BYTE *)off_133A90 + 15) |= 2u;
      return 0;
    }
    sub_134CC4(1);
    return 0;
  }
}

