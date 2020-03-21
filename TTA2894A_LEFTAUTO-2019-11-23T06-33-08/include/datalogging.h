// #include"fstream"
// #include"vex.h"
// // storage for some information to save
// uint8_t     motorTempData[ 100 ];
// uint8_t     myReadBuffer[ 1000 ];




// int main() {
//     // set the test data to something detectable
//     for(int i=0;i<100;i++) {
//         motorTempData[i] = i * 2;
//     }
    
//     // write test data to SD Card
//     int nWritten = Brain.SDcard.savefile( "test.h", motorTempData, sizeof(motorTempData) );

//     // did that work ?
//     if( nWritten > 0) {
//         // display on screen how many bytes we wrote
//         Brain.Screen.setCursor( 2, 2 );
//         Brain.Screen.print( "We wrote %d bytes to the SD Card", nWritten );

//         // now read it back into a different buffer
//         int nRead = Brain.SDcard.loadfile( "test.h", myReadBuffer, sizeof(myReadBuffer) );

//         // display on screen how many bytes we read
//         Brain.Screen.setCursor( 3, 2 );
//         Brain.Screen.print( "We read %d bytes from the SD Card", nRead );

//         // and display some of the data
//         Brain.Screen.setCursor( 6, 2 );
//         for(int i=0;i<8;i++)
//             Brain.Screen.print("%02X ", myReadBuffer[i]);
//     }
//     else {
//         Brain.Screen.printAt( 10, 40, "Error writing to the SD Card" );        
//     }
// }





// int main() {
//     // set the test data to something detectable
//     for(
//        (leftMotor.temperature(percentUnits::pct);
    
    
//     // write test data to SD Card
//     int nWritten = Brain.SDcard.savefile( "test.h", motorTempData, 
//     sizeof(motorTempData));
//     // (sizeof(leftMotorFwd.temperature(percentUnits::pct))),
//     // (sizeof(leftMotor.temperature(percentUnits::pct))),
//     // (sizeof(rightMotorFwd.temperature(percentUnits::pct))),
//     // (sizeof(rightMotor.temperature(percentUnits::pct))),
//     // (sizeof(ScissorRight.temperature(percentUnits::pct))),
//     // (sizeof(ScissorLeft.temperature(percentUnits::pct))),
//     // (sizeof(Clamp.temperature(percentUnits::pct)))));

//     // did that work ?
//     if( nWritten > 0) {
//         // display on screen how many bytes we wrote
//         Brain.Screen.setCursor( 2, 120 );
//         Brain.Screen.print( "We wrote %d bytes to the SD Card", nWritten );

//         // now read it back into a different buffer
//         int nRead = Brain.SDcard.loadfile( "test.h", myReadBuffer, sizeof(myReadBuffer) );

//         // display on screen how many bytes we read
//         Brain.Screen.setCursor( 3, 140 );
//         Brain.Screen.print( "We read %d bytes from the SD Card", nRead );

//         // and display some of the data
//         Brain.Screen.setCursor( 6, 2 );
//         for(int i=0;i<8;i++)
//             Brain.Screen.print("%02X ", myReadBuffer[i]);
//     }
//     else {
//         Brain.Screen.printAt( 10, 40, "Error writing to the SD Card" );        
//     }
// }













//   while (true) {
  //     Controller1.Screen.clearScreen();
  //     Controller1.Screen.setCursor(1, 1);
  //     Controller1.Screen.print(ScissorLeft.temperature(percent));
  //     Controller1.Screen.newLine();
  //     Controller1.Screen.print(ScissorRight.temperature(percent));
  //     Controller1.Screen.newLine();
  //     Controller1.Screen.print(Clamp.temperature(percent));
  //     wait(1, seconds);
  //     Controller1.Screen.clearScreen();
  //     Controller1.Screen.setCursor(1, 1);
  //     Controller1.Screen.print("Battery Charge");
  //     wait(0.2, seconds);
  //     Controller1.Screen.clearScreen();
  //     Controller1.Screen.setCursor(1, 1);
  //     Controller1.Screen.print(Brain.Battery.capacity(percent));
  //     wait(1, seconds);
  //     Controller1.Screen.clearScreen();
  //     wait(0.125, seconds);
    //   Brain.Screen.printAt(2, 40, "BLMotor Temp: %f",
    //                        leftMotor.temperature(percentUnits::pct));
    //   Brain.Screen.printAt(2, 60, "FLMotor Temp: %f",
    //                        leftMotorFwd.temperature(percentUnits::pct));
    //   Brain.Screen.printAt(2, 80, "BR Motor Temp: %f",
    //                        rightMotor.temperature(percentUnits::pct));
    //   Brain.Screen.printAt(2, 100, "FR Motor Temp: %f",
    //                        rightMotorFwd.temperature(percentUnits::pct));
    //   Brain.Screen.printAt(2, 120, "Lift Right Motor Temp: %f",
    //                        ScissorRight.temperature(percentUnits::pct));
    //   Brain.Screen.printAt(2, 140, "Lift Left Motor Temp: %f",
    //                        ScissorLeft.temperature(percentUnits::pct));
    //   Brain.Screen.printAt(2, 160, "Clamp Motor Temp: %f",
    //                        Clamp.temperature(percentUnits::pct));
    //   Brain.Screen.printAt(2, 180, "Brain Battery: %f",
    //                        Brain.Battery.capacity(percent));
    // }
