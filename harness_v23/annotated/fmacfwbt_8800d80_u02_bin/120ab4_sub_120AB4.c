// v23 annotated: sub_120AB4 @ 0x120ab4
// Original: 120ab4_sub_120AB4.c
// Primary struct: <unclustered>
//
// sub_120AB4 @ 0x120ab4, size 188 bytes
// Doc: sub_121E604 [util]: Processes r0 object, reads from global table, updates state
// sub_121E604 [util]: Processes r0 object, reads from global table, updates state
int *__fastcall sub_120AB4(int *result, int a2, int a3)
{
  int *v3; // r3
  unsigned int *v4; // r3
  unsigned int *v5; // r3
  unsigned int *v6; // r3

  if ( !a2 )
  {
    v3 = *((int **)off_120B70 + 2);
    if ( !v3 )
    {
      if ( a3 )
        goto LABEL_13;
      goto LABEL_4;
    }
    while ( 1 )
    {
      while ( result == v3 || !*((_BYTE *)v3 + 108) )
      {
LABEL_7:
        v3 = (int *)*v3;
        if ( !v3 )
          goto LABEL_12;
      }
      if ( *((_BYTE *)v3 + 413) == 2 )
      {
        if ( *((_BYTE *)v3 + 106) == 2 )
          break;
        a2 = 1;
        goto LABEL_7;
      }
      v3 = (int *)*v3;
      if ( !v3 )
      {
LABEL_12:
        if ( a2 | a3 )
        {
LABEL_13:
          v5 = (unsigned int *)off_120B74;
          *(_DWORD *)off_120B74 = *(_DWORD *)off_120B74 & 0xFFFFFF00 | 0x68;
          *v5 = *v5 & 0xFFFF00FF | 0x7800;
          *v5 = *v5 & 0xFF00FFFF | 0x780000;
          return result;
        }
LABEL_4:
        v4 = (unsigned int *)off_120B74;
        *(_DWORD *)off_120B74 = *(_DWORD *)off_120B74 & 0xFFFFFF00 | 0x80;
        *v4 = *v4 & 0xFFFF00FF | 0x8000;
        *v4 = *v4 & 0xFF00FFFF | 0x800000;
        return result;
      }
    }
  }
  v6 = (unsigned int *)off_120B74;
  *(_DWORD *)off_120B74 = *(_DWORD *)off_120B74 & 0xFFFFFF00 | 0x60;
  *v6 = *v6 & 0xFFFF00FF | 0x6000;
  *v6 = *v6 & 0xFF00FFFF | 0x600000;
  return result;
}

