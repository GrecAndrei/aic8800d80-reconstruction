// v23 annotated: rf_stream_kick @ 0x114104
// Original: 114104_rf_stream_kick.c
// Primary struct: <unclustered>
//
// rf_stream_kick @ 0x114104, size 12 bytes
// Doc: rf_msg_process_body_n4c0 [rf]: Process RF message body using table pointer
// rf_msg_process_body_n4c0 [rf]: Process RF message body using table pointer
void rf_stream_kick()
{
  if ( !*(_BYTE *)rf_msg_process_body_n4c8 )
    log_flush();
}

