#define ENCODER_IF 
#define BUTTON_IF
#define TIMER1_IF
#define TIMER_ON
#define ACTIVE_FLAG
#define CHANNEL_FLAG
#define SELECT_FLAG
#define SCROLL_FLAG
#define ENC_B_STATE

if (ENCODER_IF == 1)
{
  TMR1H = 0;
  TMR1L = 0;
  TIMER_ON = 1;
  
  if (ACTIVE_FLAG == 0)               // basically wake up.. in menu mode now
  {
    ACTIVE_FLAG = 1;                  // selecting a scale on a particular channel will zero this flag.. or timer1 flag
    SELECT_FLAG = 0;                  // haven't chosen a channel yet
    CHANNEL_FLAG = 0;                 // current potential channel
    highlight(CHANNEL_FLAG);
    return;
  }
  
  if (ACTIVE_FLAG == 1) && (SELECT_FLAG == 0)   // level 1 menu.. choosing which channel to modify
  {
    unhighlight(CHANNEL_FLAG);
    CHANNEL_FLAG = ~CHANNEL_FLAG;
    highlight(CHANNEL_FLAG);
    return;
  }
  
  if (ACTIVE_FLAG == 1) && (SELECT_FLAG == 1)
  {
    // scrolling through scales starting from current scale
  }
}

if (BUTTON_IF == 1)
{
  if (ACTIVE_FLAG == 1) && (SELECT_FLAG == 0)
  {
      TMR1H = 0;
      TMR1L = 0;
      TIMER_ON = 1;
      
      SELECT_FLAG = 1;
      return;
  }
  
  if (ACTIVE_FLAG == 1) && (SELECT_FLAG == 1)
  {
    // potential scale of selected channel saved as current scale
    TIMER_ON = 0;
    return;
  }
}

if (TIMER1_IF)
{
  TIMER_ON = 0;
  ACTIVE_FLAG = 0;
  unhighlight(0);
  unhighlight(1);
  lcd_set_cursor(1,1);
  lcd_write_string(scale1)
  lcd_set_cursor(2,1);
  lcd_write_string(scale2)
  TIMER1_IF = 0;
  return;
}
  
