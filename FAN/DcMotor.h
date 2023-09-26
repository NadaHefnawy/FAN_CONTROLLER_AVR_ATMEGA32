 /******************************************************************************
 *
 * Module: DC MOTOR
 *
 * File Name: DcMotor.h
 *
 * Description: header file for the ATmega32 DC MOTOR driver
 *
 * Author: Nada Hefnawy
 *
 *******************************************************************************/

#ifndef DCMOTOR_H_
#define DCMOTOR_H_
#include "std_types.h"

#define MOTOR_OUTPUT_0_PORTID               PORTB_ID
#define MOTOR_OUTPUT_0_PINID                PIN0_ID

#define MOTOR_OUTPUT_1_PORTID               PORTB_ID
#define MOTOR_OUTPUT_1_PINID                PIN1_ID

typedef enum {
	STOP,CLOCKWISE, ANTI_CLOCKWISE
}DcMotor_State;

/*
 * Description :
 * The Function responsible for setup the direction for the two
 * motor pins through the GPIO driver.
 * Stop at the DC-Motor at the beginning through the GPIO driver.
 */
void DcMotor_Init(void);

/*
 * Description :
 * The function responsible for rotate the DC Motor CW/ or A_CW or
 * stop the motor based on the state input state value.
 * Send the required duty cycle to the PWM driver based on the
 * required speed value.
 */
void DcMotor_Rotate(DcMotor_State state,uint8 speed);


#endif /* DCMOTOR_H_ */
