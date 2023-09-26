 /******************************************************************************
 *
 * Module: DC MOTOR
 *
 * File Name: DcMotor.c
 *
 * Description: source file for the ATmega32 DC MOTOR driver
 *
 * Author: Nada Hefnawy
 *
 *******************************************************************************/
#include "gpio.h"
#include "pwm.h"
#include "common_macros.h"
#include "DcMotor.h"


/*
 * Description :
 * The Function responsible for setup the direction for the two
 * motor pins through the GPIO driver.
 * Stop at the DC-Motor at the beginning through the GPIO driver.
 */
void DcMotor_Init(void)
{
	GPIO_setupPinDirection(MOTOR_OUTPUT_0_PORTID, MOTOR_OUTPUT_0_PINID, PIN_OUTPUT);
	GPIO_setupPinDirection(MOTOR_OUTPUT_1_PORTID, MOTOR_OUTPUT_1_PINID, PIN_OUTPUT);
	DcMotor_Rotate(STOP, 0);
}
/*
 * Description :
 * The function responsible for rotate the DC Motor CW/ or A_CW or
 * stop the motor based on the state input state value.
 * Send the required duty cycle to the PWM driver based on the
 * required speed value.
 */
void DcMotor_Rotate(DcMotor_State state,uint8 speed)
{
	PWM_Timer0_Start(speed);
	GPIO_writePin(MOTOR_OUTPUT_0_PORTID, MOTOR_OUTPUT_0_PINID, GET_BIT(state,0));
	GPIO_writePin(MOTOR_OUTPUT_1_PORTID, MOTOR_OUTPUT_1_PINID, GET_BIT(state,1));
}
