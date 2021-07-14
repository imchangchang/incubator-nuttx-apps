/** @file
 *  @brief MAVLink comm protocol generated from underpan.xml
 *  @see http://mavlink.org
 */
#pragma once
#ifndef MAVLINK_UNDERPAN_H
#define MAVLINK_UNDERPAN_H

#ifndef MAVLINK_H
    #error Wrong include order: MAVLINK_UNDERPAN.H MUST NOT BE DIRECTLY USED. Include mavlink.h from the same directory instead or set ALL AND EVERY defines from MAVLINK.H manually accordingly, including the #define MAVLINK_H call.
#endif

#undef MAVLINK_THIS_XML_IDX
#define MAVLINK_THIS_XML_IDX 0

#ifdef __cplusplus
extern "C" {
#endif

// MESSAGE LENGTHS AND CRCS

#ifndef MAVLINK_MESSAGE_LENGTHS
#define MAVLINK_MESSAGE_LENGTHS {}
#endif

#ifndef MAVLINK_MESSAGE_CRCS
#define MAVLINK_MESSAGE_CRCS {{45000, 110, 17, 17, 0, 0, 0}, {45001, 60, 17, 17, 0, 0, 0}}
#endif

#include "../protocol.h"

#define MAVLINK_ENABLED_UNDERPAN

// ENUM DEFINITIONS


/** @brief This is the motor command, to control the underpand motors. */
#ifndef HAVE_ENUM_MOTOR_CMD
#define HAVE_ENUM_MOTOR_CMD
typedef enum MOTOR_CMD
{
   MOTOR_CMD_STOP=0, /* Stop pwm output. The motor will be released. | */
   MOTOR_CMD_BREAK=1, /* Break the motor. | */
   MOTOR_CMD_PWM=2, /* Control the motor by pwm rate. | */
   MOTOR_CMD_SPEED=3, /* Control the motor speed. In this case, the motor will use a feedback pid control to control the motor speed. | */
   MOTOR_CMD_ENUM_END=4, /*  | */
} MOTOR_CMD;
#endif

/** @brief motor status */
#ifndef HAVE_ENUM_MOTOR_STATUS
#define HAVE_ENUM_MOTOR_STATUS
typedef enum MOTOR_STATUS
{
   MOTOR_STATUS_LOCKED=0, /* Motor is locked by a hardware switch. | */
   MOTOR_STATUS_STOP=1, /* Stop pwm output | */
   MOTOR_STATUS_BREAK=2, /* Break | */
   MOTOR_STATUS_PWM=3, /* PWM | */
   MOTOR_STATUS_SPEED=4, /* SPEED | */
   MOTOR_STATUS_ENUM_END=5, /*  | */
} MOTOR_STATUS;
#endif

// MAVLINK VERSION

#ifndef MAVLINK_VERSION
#define MAVLINK_VERSION 3
#endif

#if (MAVLINK_VERSION == 0)
#undef MAVLINK_VERSION
#define MAVLINK_VERSION 3
#endif

// MESSAGE DEFINITIONS
#include "./mavlink_msg_underpan_control.h"
#include "./mavlink_msg_underpan_status.h"

// base include


#undef MAVLINK_THIS_XML_IDX
#define MAVLINK_THIS_XML_IDX 0

#if MAVLINK_THIS_XML_IDX == MAVLINK_PRIMARY_XML_IDX
# define MAVLINK_MESSAGE_INFO {MAVLINK_MESSAGE_INFO_UNDERPAN_CONTROL, MAVLINK_MESSAGE_INFO_UNDERPAN_STATUS}
# define MAVLINK_MESSAGE_NAMES {{ "UNDERPAN_CONTROL", 45000 }, { "UNDERPAN_STATUS", 45001 }}
# if MAVLINK_COMMAND_24BIT
#  include "../mavlink_get_info.h"
# endif
#endif

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // MAVLINK_UNDERPAN_H
