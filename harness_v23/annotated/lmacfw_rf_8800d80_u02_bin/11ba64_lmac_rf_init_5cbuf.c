// v23 annotated: lmac_rf_init_5cbuf @ 0x11ba64
// Original: 11ba64_lmac_rf_init_5cbuf.c
// Primary struct: <unclustered>
//
// lmac_rf_init_5cbuf @ 0x11ba64, size 138 bytes
// Doc: lmac_rf_init_5cbuf [rf]: Initialize RF 0x5c-byte context block to zero
// lmac_rf_init_5cbuf [rf]: Initialize RF 0x5c-byte context block to zero
int lmac_rf_init_5cbuf()
{
  int *v0; // r7
  void *v1; // r6
  unsigned int v2; // r5
  int *i; // r4
  int result; // r0
  _DWORD *v5; // r3
  int v6; // r1

  v0 = (int *)off_11BAF4;
  v1 = off_11BAF0;
  sub_100200((int *)off_11BAF0, 0, 0x5Cu);
  v2 = 0;
  for ( i = v0; ; i += 7 )
  {
    sub_100200(i, 0, 0x1Cu);
    *((_WORD *)i + 7) = 255;
    *((_BYTE *)i + 24) = -1;
    if ( v2 <= 2 )
    {
      list_push_tail(v1);
      goto LABEL_4;
    }
    if ( v2 != 3 )
      break;
    *((_WORD *)v0 + 47) = 0;
    *((_BYTE *)v0 + 89) = 0;
LABEL_4:
    ++v2;
  }
  if ( v2 != 4 )
    goto LABEL_4;
  sub_11E71C(dword_11BAF8);
  sub_11E71C(dword_11BAFC);
  list_push_tail(dword_11BAF8);
  list_push_tail(dword_11BAF8);
  list_push_tail(dword_11BAF8);
  result = list_push_tail(dword_11BAF8);
  v5 = off_11BAF0;
  v6 = dword_11BB14;
  *((_DWORD *)off_11BAF0 + 13) = dword_11BB10;
  v5[17] = v6;
  v5[18] = 0;
  return result;
}

