using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor leftMotor;
extern motor rightMotor;
extern motor ScissorLeft;
extern motor ScissorRight;
extern motor Clamp;
extern controller Controller1;
extern motor leftMotorFwd;
extern motor rightMotorFwd;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );