#pragma once
// MESSAGE UNDERPAN_STATUS PACKING

#define MAVLINK_MSG_ID_UNDERPAN_STATUS 45001


typedef struct __mavlink_underpan_status_t {
 int32_t speed1; /*<  The speed read from the motor*/
 int32_t speed2; /*<  The speed read from the motor*/
 int32_t speed3; /*<  The speed read from the motor*/
 int32_t speed4; /*<  The speed read from the motor*/
 uint8_t under_status; /*<  under_status*/
} mavlink_underpan_status_t;

#define MAVLINK_MSG_ID_UNDERPAN_STATUS_LEN 17
#define MAVLINK_MSG_ID_UNDERPAN_STATUS_MIN_LEN 17
#define MAVLINK_MSG_ID_45001_LEN 17
#define MAVLINK_MSG_ID_45001_MIN_LEN 17

#define MAVLINK_MSG_ID_UNDERPAN_STATUS_CRC 60
#define MAVLINK_MSG_ID_45001_CRC 60



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_UNDERPAN_STATUS { \
    45001, \
    "UNDERPAN_STATUS", \
    5, \
    {  { "under_status", NULL, MAVLINK_TYPE_UINT8_T, 0, 16, offsetof(mavlink_underpan_status_t, under_status) }, \
         { "speed1", NULL, MAVLINK_TYPE_INT32_T, 0, 0, offsetof(mavlink_underpan_status_t, speed1) }, \
         { "speed2", NULL, MAVLINK_TYPE_INT32_T, 0, 4, offsetof(mavlink_underpan_status_t, speed2) }, \
         { "speed3", NULL, MAVLINK_TYPE_INT32_T, 0, 8, offsetof(mavlink_underpan_status_t, speed3) }, \
         { "speed4", NULL, MAVLINK_TYPE_INT32_T, 0, 12, offsetof(mavlink_underpan_status_t, speed4) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_UNDERPAN_STATUS { \
    "UNDERPAN_STATUS", \
    5, \
    {  { "under_status", NULL, MAVLINK_TYPE_UINT8_T, 0, 16, offsetof(mavlink_underpan_status_t, under_status) }, \
         { "speed1", NULL, MAVLINK_TYPE_INT32_T, 0, 0, offsetof(mavlink_underpan_status_t, speed1) }, \
         { "speed2", NULL, MAVLINK_TYPE_INT32_T, 0, 4, offsetof(mavlink_underpan_status_t, speed2) }, \
         { "speed3", NULL, MAVLINK_TYPE_INT32_T, 0, 8, offsetof(mavlink_underpan_status_t, speed3) }, \
         { "speed4", NULL, MAVLINK_TYPE_INT32_T, 0, 12, offsetof(mavlink_underpan_status_t, speed4) }, \
         } \
}
#endif

/**
 * @brief Pack a underpan_status message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param under_status  under_status
 * @param speed1  The speed read from the motor
 * @param speed2  The speed read from the motor
 * @param speed3  The speed read from the motor
 * @param speed4  The speed read from the motor
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_underpan_status_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t under_status, int32_t speed1, int32_t speed2, int32_t speed3, int32_t speed4)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_UNDERPAN_STATUS_LEN];
    _mav_put_int32_t(buf, 0, speed1);
    _mav_put_int32_t(buf, 4, speed2);
    _mav_put_int32_t(buf, 8, speed3);
    _mav_put_int32_t(buf, 12, speed4);
    _mav_put_uint8_t(buf, 16, under_status);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_UNDERPAN_STATUS_LEN);
#else
    mavlink_underpan_status_t packet;
    packet.speed1 = speed1;
    packet.speed2 = speed2;
    packet.speed3 = speed3;
    packet.speed4 = speed4;
    packet.under_status = under_status;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_UNDERPAN_STATUS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_UNDERPAN_STATUS;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_UNDERPAN_STATUS_MIN_LEN, MAVLINK_MSG_ID_UNDERPAN_STATUS_LEN, MAVLINK_MSG_ID_UNDERPAN_STATUS_CRC);
}

/**
 * @brief Pack a underpan_status message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param under_status  under_status
 * @param speed1  The speed read from the motor
 * @param speed2  The speed read from the motor
 * @param speed3  The speed read from the motor
 * @param speed4  The speed read from the motor
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_underpan_status_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t under_status,int32_t speed1,int32_t speed2,int32_t speed3,int32_t speed4)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_UNDERPAN_STATUS_LEN];
    _mav_put_int32_t(buf, 0, speed1);
    _mav_put_int32_t(buf, 4, speed2);
    _mav_put_int32_t(buf, 8, speed3);
    _mav_put_int32_t(buf, 12, speed4);
    _mav_put_uint8_t(buf, 16, under_status);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_UNDERPAN_STATUS_LEN);
#else
    mavlink_underpan_status_t packet;
    packet.speed1 = speed1;
    packet.speed2 = speed2;
    packet.speed3 = speed3;
    packet.speed4 = speed4;
    packet.under_status = under_status;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_UNDERPAN_STATUS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_UNDERPAN_STATUS;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_UNDERPAN_STATUS_MIN_LEN, MAVLINK_MSG_ID_UNDERPAN_STATUS_LEN, MAVLINK_MSG_ID_UNDERPAN_STATUS_CRC);
}

/**
 * @brief Encode a underpan_status struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param underpan_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_underpan_status_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_underpan_status_t* underpan_status)
{
    return mavlink_msg_underpan_status_pack(system_id, component_id, msg, underpan_status->under_status, underpan_status->speed1, underpan_status->speed2, underpan_status->speed3, underpan_status->speed4);
}

/**
 * @brief Encode a underpan_status struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param underpan_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_underpan_status_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_underpan_status_t* underpan_status)
{
    return mavlink_msg_underpan_status_pack_chan(system_id, component_id, chan, msg, underpan_status->under_status, underpan_status->speed1, underpan_status->speed2, underpan_status->speed3, underpan_status->speed4);
}

/**
 * @brief Send a underpan_status message
 * @param chan MAVLink channel to send the message
 *
 * @param under_status  under_status
 * @param speed1  The speed read from the motor
 * @param speed2  The speed read from the motor
 * @param speed3  The speed read from the motor
 * @param speed4  The speed read from the motor
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_underpan_status_send(mavlink_channel_t chan, uint8_t under_status, int32_t speed1, int32_t speed2, int32_t speed3, int32_t speed4)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_UNDERPAN_STATUS_LEN];
    _mav_put_int32_t(buf, 0, speed1);
    _mav_put_int32_t(buf, 4, speed2);
    _mav_put_int32_t(buf, 8, speed3);
    _mav_put_int32_t(buf, 12, speed4);
    _mav_put_uint8_t(buf, 16, under_status);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_UNDERPAN_STATUS, buf, MAVLINK_MSG_ID_UNDERPAN_STATUS_MIN_LEN, MAVLINK_MSG_ID_UNDERPAN_STATUS_LEN, MAVLINK_MSG_ID_UNDERPAN_STATUS_CRC);
#else
    mavlink_underpan_status_t packet;
    packet.speed1 = speed1;
    packet.speed2 = speed2;
    packet.speed3 = speed3;
    packet.speed4 = speed4;
    packet.under_status = under_status;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_UNDERPAN_STATUS, (const char *)&packet, MAVLINK_MSG_ID_UNDERPAN_STATUS_MIN_LEN, MAVLINK_MSG_ID_UNDERPAN_STATUS_LEN, MAVLINK_MSG_ID_UNDERPAN_STATUS_CRC);
#endif
}

/**
 * @brief Send a underpan_status message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_underpan_status_send_struct(mavlink_channel_t chan, const mavlink_underpan_status_t* underpan_status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_underpan_status_send(chan, underpan_status->under_status, underpan_status->speed1, underpan_status->speed2, underpan_status->speed3, underpan_status->speed4);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_UNDERPAN_STATUS, (const char *)underpan_status, MAVLINK_MSG_ID_UNDERPAN_STATUS_MIN_LEN, MAVLINK_MSG_ID_UNDERPAN_STATUS_LEN, MAVLINK_MSG_ID_UNDERPAN_STATUS_CRC);
#endif
}

#if MAVLINK_MSG_ID_UNDERPAN_STATUS_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_underpan_status_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t under_status, int32_t speed1, int32_t speed2, int32_t speed3, int32_t speed4)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_int32_t(buf, 0, speed1);
    _mav_put_int32_t(buf, 4, speed2);
    _mav_put_int32_t(buf, 8, speed3);
    _mav_put_int32_t(buf, 12, speed4);
    _mav_put_uint8_t(buf, 16, under_status);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_UNDERPAN_STATUS, buf, MAVLINK_MSG_ID_UNDERPAN_STATUS_MIN_LEN, MAVLINK_MSG_ID_UNDERPAN_STATUS_LEN, MAVLINK_MSG_ID_UNDERPAN_STATUS_CRC);
#else
    mavlink_underpan_status_t *packet = (mavlink_underpan_status_t *)msgbuf;
    packet->speed1 = speed1;
    packet->speed2 = speed2;
    packet->speed3 = speed3;
    packet->speed4 = speed4;
    packet->under_status = under_status;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_UNDERPAN_STATUS, (const char *)packet, MAVLINK_MSG_ID_UNDERPAN_STATUS_MIN_LEN, MAVLINK_MSG_ID_UNDERPAN_STATUS_LEN, MAVLINK_MSG_ID_UNDERPAN_STATUS_CRC);
#endif
}
#endif

#endif

// MESSAGE UNDERPAN_STATUS UNPACKING


/**
 * @brief Get field under_status from underpan_status message
 *
 * @return  under_status
 */
static inline uint8_t mavlink_msg_underpan_status_get_under_status(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  16);
}

/**
 * @brief Get field speed1 from underpan_status message
 *
 * @return  The speed read from the motor
 */
static inline int32_t mavlink_msg_underpan_status_get_speed1(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  0);
}

/**
 * @brief Get field speed2 from underpan_status message
 *
 * @return  The speed read from the motor
 */
static inline int32_t mavlink_msg_underpan_status_get_speed2(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  4);
}

/**
 * @brief Get field speed3 from underpan_status message
 *
 * @return  The speed read from the motor
 */
static inline int32_t mavlink_msg_underpan_status_get_speed3(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  8);
}

/**
 * @brief Get field speed4 from underpan_status message
 *
 * @return  The speed read from the motor
 */
static inline int32_t mavlink_msg_underpan_status_get_speed4(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  12);
}

/**
 * @brief Decode a underpan_status message into a struct
 *
 * @param msg The message to decode
 * @param underpan_status C-struct to decode the message contents into
 */
static inline void mavlink_msg_underpan_status_decode(const mavlink_message_t* msg, mavlink_underpan_status_t* underpan_status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    underpan_status->speed1 = mavlink_msg_underpan_status_get_speed1(msg);
    underpan_status->speed2 = mavlink_msg_underpan_status_get_speed2(msg);
    underpan_status->speed3 = mavlink_msg_underpan_status_get_speed3(msg);
    underpan_status->speed4 = mavlink_msg_underpan_status_get_speed4(msg);
    underpan_status->under_status = mavlink_msg_underpan_status_get_under_status(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_UNDERPAN_STATUS_LEN? msg->len : MAVLINK_MSG_ID_UNDERPAN_STATUS_LEN;
        memset(underpan_status, 0, MAVLINK_MSG_ID_UNDERPAN_STATUS_LEN);
    memcpy(underpan_status, _MAV_PAYLOAD(msg), len);
#endif
}
