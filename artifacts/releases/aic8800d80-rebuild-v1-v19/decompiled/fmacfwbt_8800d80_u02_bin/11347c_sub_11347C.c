// sub_11347C @ 0x11347c, size 106 bytes
// Doc: rf_stream_start2_n26e [rf]: RF stream start variant; tail-calls helper at 0x114e84
// rf_stream_start2_n26e [rf]: RF stream start variant; tail-calls helper at 0x114e84
_DWORD *__fastcall sub_11347C(int a1)
{
  _DWORD *result; // r0
  _DWORD *v2; // r4
  int v3; // r0
  unsigned int v4; // r0

  switch ( a1 )
  {
    case 1:
      v2 = rf_bus_write2_n1be;
      v3 = sub_14380C(rf_bus_write2_n1be, rf_stream_start2_n2a8, 18);
      if ( *((_BYTE *)rf_fault_dump_n_3ec + 370) && bt_ps_control(v3) )
      {
        v4 = sub_114E98();
        v2[2] = ((HIWORD(v4) << 16) + 0x10000) | (unsigned __int16)v4;
        return v2;
      }
      else if ( *(unsigned __int16 *)rf_stream_start2_n2b1 == 0xFFFF
             || *((unsigned __int16 *)rf_stream_start2_n2b1 + 1) == 0xFFFF )
      {
        return rf_bus_write2_n1be;
      }
      else
      {
        result = rf_bus_write2_n1be;
        v2[2] = *(_DWORD *)rf_stream_start2_n2b1;
      }
      break;
    case 6:
      return (_DWORD *)rf_stream_start2_4ec;
    case 15:
      return (_DWORD *)rf_stream_start2_n29c;
    default:
      return nullptr;
  }
  return result;
}

