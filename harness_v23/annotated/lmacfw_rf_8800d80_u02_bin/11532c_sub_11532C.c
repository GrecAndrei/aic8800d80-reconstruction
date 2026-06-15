// v23 annotated: sub_11532C @ 0x11532c
// Original: 11532c_sub_11532C.c
// Primary struct: <unclustered>
//
// sub_11532C @ 0x11532c, size 80 bytes
int __fastcall sub_11532C(int result)
{
  switch ( result )
  {
    case 0:
      *(_DWORD *)off_11537C = 2;
      break;
    case 1:
      *(_DWORD *)off_11537C = 4;
      break;
    case 2:
      *(_DWORD *)off_11537C = 8;
      break;
    case 3:
      *(_DWORD *)off_11537C = 16;
      break;
    case 5:
      *(_DWORD *)off_11537C = 32;
      break;
    default:
      if ( **(__int16 **)off_115380 < 0 )
        result = sub_1219C4(dword_115388, dword_115384, 944);
      break;
  }
  return result;
}

