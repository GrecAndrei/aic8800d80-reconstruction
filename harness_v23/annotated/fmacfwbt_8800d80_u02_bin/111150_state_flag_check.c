// v23 annotated: state_flag_check @ 0x111150
// Original: 111150_state_flag_check.c
// Primary struct: <unclustered>
//
// state_flag_check @ 0x111150, size 16 bytes
// Doc: state_flag_check [rf]: Check internal state flags
// state_flag_check [rf]: Check internal state flags
int state_flag_check()
{
  if ( *(_BYTE *)off_111160 )
    return 1;
  else
    return *(unsigned __int8 *)off_111164;
}

