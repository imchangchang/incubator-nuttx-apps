#pragma once
// MESSAGE UNDERPAN_CONTROL PACKING

#define MAVLINK_MSG_ID_UNDERPAN_CONTROL 45000


typedef struct __mavlink_underpan_control_t {
 int32_t cmd1; /*<  [-10000,10000], 0.01%*/
 int32_t cmd2; /*<  [-10000,10000], 0.01%*/
 int32_t cmd3; /*<  [-10000,10000], 0.01%*/
 int32_t cmd4; /*<  [-10000,10000], 0.01%*/
 uint8_t control_command; /*<  control command*/
} mavlink_underpan_control_t;

#define MAVLINK_MSG_ID_UNDERPAN_CONTROL_LEN 17
#define MAVLINK_MSG_ID_UNDERPAN_CONTROL_MIN_LEN 17
#define MAVLINK_MSG_ID_45000_LEN 17
#define MAVLINK_MSG_ID_45000_MIN_LEN 17

#define MAVLINK_MSG_ID_UNDERPAN_CONTROL_CRC 110
#define MAVLINK_MSG_ID_45000_CRC 110



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_UNDERPAN_CONTROL { \
    45000, \
    "UNDERPAN_CONTROL", \
    5, \
    {  { "control_command", NULL, MAVLINK_TYPE_UINT8_T, 0, 16, offsetof(mavlink_underpan_control_t, control_command) }, \
         { "cmd1", NULL, MAVLINK_TYPE_INT32_T, 0, 0, offsetof(mavlink_underpan_control_t, cmd1) }, \
         { "cmd2", NULL, MAVLINK_TYPE_INT32_T, 0, 4, offsetof(mavlink_underpan_control_t, cmd2) }, \
         { "cmd3", NULL, MAVLINK_TYPE_INT32_T, 0, 8, offsetof(mavlink_underpan_control_t, cmd3) }, \
         { "cmd4", NULL, MAVLINK_TYPE_INT32_T, 0, 12, offsetof(mavlink_underpan_control_t, cmd4) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_UNDERPAN_CONTROL { \
    "UNDERPAN_CONTROL", \
    5, \
    {  { "control_command", NULL, MAVLINK_TYPE_UINT8_T, 0, 16, offsetof(mavlink_underpan_control_t, control_command) }, \
         { "cmd1", NULL, MAVLINK_TYPE_INT32_T, 0, 0, offsetof(mavlink_underpan_control_t, cmd1) }, \
         { "cmd2", NULL, MAVLINK_TYPE_INT32_T, 0, 4, offsetof(mavlink_underpan_control_t, cmd2) }, \
         { "cmd3", NULL, MAVLINK_TYPE_INT32_T, 0, 8, offsetof(mavlink_underpan_control_t, cmd3) }, \
         { "cmd4", NULL, MAVLINK_TYPE_INT32_T, 0, 12, offsetof(mavlink_underpan_control_t, cmd4) }, \
         } \
}
#endif

/**
 * @brief Pack a underpan_control message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param control_command  control command
 * @param cmd1  [-10000,10000], 0.01%
 * @param cmd2  [-10000,10000], 0.01%
 * @param cmd3  [-10000,10000], 0.01%
 * @param cmd4  [-10000,10000], 0.01%
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_underpan_control_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t control_command, int32_t cmd1, int32_t cmd2, int32_t cmd3, int32_t cmd4)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_UNDERPAN_CONTROL_LEN];
    _mav_put_int32_t(buf, 0, cmd1);
    _mav_put_int32_t(buf, 4, cmd2);
    _mav_put_int32_t(buf, 8, cmd3);
    _mav_put_int32_t(buf, 12, cmd4);
    _mav_put_uint8_t(buf, 16, control_command);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_UNDERPAN_CONTROL_LEN);
#else
    mavlink_underpan_control_t packet;
    packet.cmd1 = cmd1;
    packet.cmd2 = cmd2;
    packet.cmd3 = cmd3;
    packet.cmd4 = cmd4;
    packet.control_command = control_command;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_UNDERPAN_CONTROL_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_UNDERPAN_CONTROL;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_UNDERPAN_CONTROL_MIN_LEN, MAVLINK_MSG_ID_UNDERPAN_CONTROL_LEN, MAVLINK_MSG_ID_UNDERPAN_CONTROL_CRC);
}

/**
 * @brief Pack a underpan_control message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param control_command  control command
 * @param cmd1  [-10000,10000], 0.01%
 * @param cmd2  [-10000,10000], 0.01%
 * @param cmd3  [-10000,10000], 0.01%
 * @param cmd4  [-10000,10000], 0.01%
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_underpan_control_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t control_command,int32_t cmd1,int32_t cmd2,int32_t cmd3,int32_t cmd4)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_UNDERPAN_CONTROL_LEN];
    _mav_put_int32_t(buf, 0, cmd1);
    _mav_put_int32_t(buf, 4, cmd2);
    _mav_put_int32_t(buf, 8, cmd3);
    _mav_put_int32_t(buf, 12, cmd4);
    _mav_put_uint8_t(buf, 16, control_command);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_UNDERPAN_CONTROL_LEN);
#else
    mavlink_underpan_control_t packet;
    packet.cmd1 = cmd1;
    packet.cmd2 = cmd2;
    packet.cmd3 = cmd3;
    packet.cmd4 = cmd4;
    packet.control_command = control_command;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_UNDERPAN_CONTROL_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_UNDERPAN_CONTROL;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_UNDERPAN_CONTROL_MIN_LEN, MAVLINK_MSG_ID_UNDERPAN_CONTROL_LEN, MAVLINK_MSG_ID_UNDERPAN_CONTROL_CRC);
}

/**
 * @brief Encode a underpan_control struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param underpan_control C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_underpan_control_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_underpan_control_t* underpan_control)
{
    return mavlink_msg_underpan_control_pack(system_id, component_id, msg, underpan_control->control_command, underpan_control->cmd1, underpan_control->cmd2, underpan_control->cmd3, underpan_control->cmd4);
}

/**
 * @brief Encode a underpan_control struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param underpan_control C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_underpan_control_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_underpan_control_t* underpan_control)
{
    return mavlink_msg_underpan_control_pack_chan(system_id, component_id, chan, msg, underpan_control->control_command, underpan_control->cmd1, underpan_control->cmd2, underpan_control->cmd3, underpan_control->cmd4);
}

/**
 * @brief Send a underpan_control message
 * @param chan MAVLink channel to send the message
 *
 * @param control_command  control command
 * @param cmd1  [-10000,10000], 0.01%
 * @param cmd2  [-10000,10000], 0.01%
 * @param cmd3  [-10000,10000], 0.01%
 * @param cmd4  [-10000,10000], 0.01%
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_underpan_control_send(mavlink_channel_t chan, uint8_t control_command, int32_t cmd1, int32_t cmd2, int32_t cmd3, int32_t cmd4)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_UNDERPAN_CONTROL_LEN];
    _mav_put_int32_t(buf, 0, cmd1);
    _mav_put_int32_t(buf, 4, cmd2);
    _mav_put_int32_t(buf, 8, cmd3);
    _mav_put_int32_t(buf, 12, cmd4);
    _mav_put_uint8_t(buf, 16, control_command);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_UNDERPAN_CONTROL, buf, MAVLINK_MSG_ID_UNDERPAN_CONTROL_MIN_LEN, MAVLINK_MSG_ID_UNDERPAN_CONTROL_LEN, MAVLINK_MSG_ID_UNDERPAN_CONTROL_CRC);
#else
    mavlink_underpan_control_t packet;
    packet.cmd1 = cmd1;
    packet.cmd2 = cmd2;
    packet.cmd3 = cmd3;
    packet.cmd4 = cmd4;
    packet.control_command = control_command;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_UNDERPAN_CONTROL, (const char *)&packet, MAVLINK_MSG_ID_UNDERPAN_CONTROL_MIN_LEN, MAVLINK_MSG_ID_UNDERPAN_CONTROL_LEN, MAVLINK_MSG_ID_UNDERPAN_CONTROL_CRC);
#endif
}

/**
 * @brief Send a underpan_control message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_underpan_control_send_struct(mavlink_channel_t chan, const mavlink_underpan_control_t* underpan_control)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_underpan_control_send(chan, underpan_control->control_command, underpan_control->cmd1, underpan_control->cmd2, underpan_control->cmd3, underpan_control->cmd4);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_UNDERPAN_CONTROL, (const char *)underpan_control, MAVLINK_MSG_ID_UNDERPAN_CONTROL_MIN_LEN, MAVLINK_MSG_ID_UNDERPAN_CONTROL_LEN, MAVLINK_MSG_ID_UNDERPAN_CONTROL_CRC);
#endif
}

#if MAVLINK_MSG_ID_UNDERPAN_CONTROL_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_underpan_control_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t control_command, int32_t cmd1, int32_t cmd2, int32_t cmd3, int32_t cmd4)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_int32_t(buf, 0, cmd1);
    _mav_put_int32_t(buf, 4, cmd2);
    _mav_put_int32_t(buf, 8, cmd3);
    _mav_put_int32_t(buf, 12, cmd4);
    _mav_put_uint8_t(buf, 16, control_command);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_UNDERPAN_CONTROL, buf, MAVLINK_MSG_ID_UNDERPAN_CONTROL_MIN_LEN, MAVLINK_MSG_ID_UNDERPAN_CONTROL_LEN, MAVLINK_MSG_ID_UNDERPAN_CONTROL_CRC);
#else
    mavlink_underpan_control_t *packet = (mavlink_underpan_control_t *)msgbuf;
    packet->cmd1 = cmd1;
    packet->cmd2 = cmd2;
    packet->cmd3 = cmd3;
    packet->cmd4 = cmd4;
    packet->control_command = control_command;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_UNDERPAN_CONTROL, (const char *)packet, MAVLINK_MSG_ID_UNDERPAN_CONTROL_MIN_LEN, MAVLINK_MSG_ID_UNDERPAN_CONTROL_LEN, MAVLINK_MSG_ID_UNDERPAN_CONTROL_CRC);
#endif
}
#endif

#endif

// MESSAGE UNDERPAN_CONTROL UNPACKING


/**
 * @brief Get field control_command from underpan_control message
 *
 * @return  control command
 */
static inline uint8_t mavlink_msg_underpan_control_get_control_command(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  16);
}

/**
 * @brief Get field cmd1 from underpan_control message
 *
 * @return  [-10000,10000], 0.01%
 */
static inline int32_t mavlink_msg_underpan_control_get_cmd1(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  0);
}

/**
 * @brief Get field cmd2 from underpan_control message
 *
 * @return  [-10000,10000], 0.01%
 */
static inline int32_t mavlink_msg_underpan_control_get_cmd2(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  4);
}

/**
 * @brief Get field cmd3 from underpan_control message
 *
 * @return  [-10000,10000], 0.01%
 */
static inline int32_t mavlink_msg_underpan_control_get_cmd3(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  8);
}

/**
 * @brief Get field cmd4 from underpan_control message
 *
 * @return  [-10000,10000], 0.01%
 */
static inline int32_t mavlink_msg_underpan_control_get_cmd4(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  12);
}

/**
 * @brief Decode a underpan_control message into a struct
 *
 * @param msg The message to decode
 * @param underpan_control C-struct to decode the message contents into
 */
static inline void mavlink_msg_underpan_control_decode(const mavlink_message_t* msg, mavlink_underpan_control_t* underpan_control)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    underpan_control->cmd1 = mavlink_msg_underpan_control_get_cmd1(msg);
    underpan_control->cmd2 = mavlink_msg_underpan_control_get_cmd2(msg);
    underpan_control->cmd3 = mavlink_msg_underpan_control_get_cmd3(msg);
    underpan_control->cmd4 = mavlink_msg_underpan_control_get_cmd4(msg);
    underpan_control->control_command = mavlink_msg_underpan_control_get_control_command(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_UNDERPAN_CONTROL_LEN? msg->len : MAVLINK_MSG_ID_UNDERPAN_CONTROL_LEN;
        memset(underpan_control, 0, MAVLINK_MSG_ID_UNDERPAN_CONTROL_LEN);
    memcpy(underpan_control, _MAV_PAYLOAD(msg), len);
#endif
}
