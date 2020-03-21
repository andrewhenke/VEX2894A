while(true)
{
  // Joystic Control:
  motor[port2] = vexRT[Ch2]; //Motor port 2 speed is determined by Ch2 on the VEXnet Transmitter
  motor[port3] = vexRT[Ch3]; //Motor port 3 speed is determined by Ch3 on the VEXnet Transmitter


  // Button Control:
  if(vexRT[Btn5U] == 1)      //If button 5U is pressed:
  {
    motor[port5] = 32;         //run motor port 5 at quarter speed (i.e. lift an arm)
  }
  else if(vexRT[Btn5D] == 1) //If button 5D is pressed:
  {
    motor[port5] = -32;        //run motor port 5 at quarter speed reversed (i.e. lower an arm)
  }
  else                       //If neither buttons 5U or 5D are pressed:
  {
    motor[port5] = 0;         //stop motor port 5 (i.e. don't move arm up or down)
  }
}
