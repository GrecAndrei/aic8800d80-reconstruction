// bt_msg_handler_sub @ 0x12d688, size 126 bytes
// Doc: bt_msg_handler_sub [bt]: Bluetooth message handler stub
// bt_msg_handler_sub [bt]: Bluetooth message handler stub
int  bt_msg_handler_sub(int result, uint32_t *a2, uint32_t *a3)
{
  __int16 **v3; // r7
  uint32_t *v4; // r6

  v3 = (__int16 **)off_12D708;
  v4 = (uint32_t *)result;
  if ( **(__int16 **)off_12D708 < 0 )
  {
    if ( result || (result = sub_12F694(dword_12D718, dword_12D70C, 384), **v3 < 0) )
    {
      if ( a2 )
      {
        if ( (uint32_t *)*a2 != a3 )
        {
          result = sub_12F694(dword_12D710, dword_12D70C, 385);
          if ( **v3 >= 0 )
            goto LABEL_3;
        }
        if ( a3 )
          goto LABEL_3;
      }
      else if ( a3 )
      {
        goto LABEL_14;
      }
      result = sub_12F694(dword_12D714, dword_12D70C, 386);
    }
  }
  if ( a2 )
  {
LABEL_3:
    *a2 = *a3;
    goto LABEL_4;
  }
LABEL_14:
  *v4 = *a3;
LABEL_4:
  if ( (uint32_t *)v4[1] == a3 )
    v4[1] = a2;
  *a3 = 0;
  return result;
}

