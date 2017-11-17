#pragma once
// MESSAGE GEOTAG_CANCEL PACKING

#define MAVLINK_MSG_ID_GEOTAG_CANCEL 211

MAVPACKED(
typedef struct __mavlink_geotag_cancel_t {
 uint8_t target_system; /*< System ID*/
 uint8_t target_component; /*< Component ID*/
}) mavlink_geotag_cancel_t;

#define MAVLINK_MSG_ID_GEOTAG_CANCEL_LEN 2
#define MAVLINK_MSG_ID_GEOTAG_CANCEL_MIN_LEN 2
#define MAVLINK_MSG_ID_211_LEN 2
#define MAVLINK_MSG_ID_211_MIN_LEN 2

#define MAVLINK_MSG_ID_GEOTAG_CANCEL_CRC 5
#define MAVLINK_MSG_ID_211_CRC 5



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_GEOTAG_CANCEL { \
    211, \
    "GEOTAG_CANCEL", \
    2, \
    {  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_geotag_cancel_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_geotag_cancel_t, target_component) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_GEOTAG_CANCEL { \
    "GEOTAG_CANCEL", \
    2, \
    {  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_geotag_cancel_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_geotag_cancel_t, target_component) }, \
         } \
}
#endif

/**
 * @brief Pack a geotag_cancel message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param target_system System ID
 * @param target_component Component ID
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_geotag_cancel_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t target_system, uint8_t target_component)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_GEOTAG_CANCEL_LEN];
    _mav_put_uint8_t(buf, 0, target_system);
    _mav_put_uint8_t(buf, 1, target_component);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_GEOTAG_CANCEL_LEN);
#else
    mavlink_geotag_cancel_t packet;
    packet.target_system = target_system;
    packet.target_component = target_component;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_GEOTAG_CANCEL_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_GEOTAG_CANCEL;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_GEOTAG_CANCEL_MIN_LEN, MAVLINK_MSG_ID_GEOTAG_CANCEL_LEN, MAVLINK_MSG_ID_GEOTAG_CANCEL_CRC);
}

/**
 * @brief Pack a geotag_cancel message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param target_system System ID
 * @param target_component Component ID
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_geotag_cancel_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t target_system,uint8_t target_component)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_GEOTAG_CANCEL_LEN];
    _mav_put_uint8_t(buf, 0, target_system);
    _mav_put_uint8_t(buf, 1, target_component);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_GEOTAG_CANCEL_LEN);
#else
    mavlink_geotag_cancel_t packet;
    packet.target_system = target_system;
    packet.target_component = target_component;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_GEOTAG_CANCEL_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_GEOTAG_CANCEL;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_GEOTAG_CANCEL_MIN_LEN, MAVLINK_MSG_ID_GEOTAG_CANCEL_LEN, MAVLINK_MSG_ID_GEOTAG_CANCEL_CRC);
}

/**
 * @brief Encode a geotag_cancel struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param geotag_cancel C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_geotag_cancel_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_geotag_cancel_t* geotag_cancel)
{
    return mavlink_msg_geotag_cancel_pack(system_id, component_id, msg, geotag_cancel->target_system, geotag_cancel->target_component);
}

/**
 * @brief Encode a geotag_cancel struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param geotag_cancel C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_geotag_cancel_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_geotag_cancel_t* geotag_cancel)
{
    return mavlink_msg_geotag_cancel_pack_chan(system_id, component_id, chan, msg, geotag_cancel->target_system, geotag_cancel->target_component);
}

/**
 * @brief Send a geotag_cancel message
 * @param chan MAVLink channel to send the message
 *
 * @param target_system System ID
 * @param target_component Component ID
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_geotag_cancel_send(mavlink_channel_t chan, uint8_t target_system, uint8_t target_component)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_GEOTAG_CANCEL_LEN];
    _mav_put_uint8_t(buf, 0, target_system);
    _mav_put_uint8_t(buf, 1, target_component);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GEOTAG_CANCEL, buf, MAVLINK_MSG_ID_GEOTAG_CANCEL_MIN_LEN, MAVLINK_MSG_ID_GEOTAG_CANCEL_LEN, MAVLINK_MSG_ID_GEOTAG_CANCEL_CRC);
#else
    mavlink_geotag_cancel_t packet;
    packet.target_system = target_system;
    packet.target_component = target_component;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GEOTAG_CANCEL, (const char *)&packet, MAVLINK_MSG_ID_GEOTAG_CANCEL_MIN_LEN, MAVLINK_MSG_ID_GEOTAG_CANCEL_LEN, MAVLINK_MSG_ID_GEOTAG_CANCEL_CRC);
#endif
}

/**
 * @brief Send a geotag_cancel message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_geotag_cancel_send_struct(mavlink_channel_t chan, const mavlink_geotag_cancel_t* geotag_cancel)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_geotag_cancel_send(chan, geotag_cancel->target_system, geotag_cancel->target_component);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GEOTAG_CANCEL, (const char *)geotag_cancel, MAVLINK_MSG_ID_GEOTAG_CANCEL_MIN_LEN, MAVLINK_MSG_ID_GEOTAG_CANCEL_LEN, MAVLINK_MSG_ID_GEOTAG_CANCEL_CRC);
#endif
}

#if MAVLINK_MSG_ID_GEOTAG_CANCEL_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_geotag_cancel_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t target_system, uint8_t target_component)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint8_t(buf, 0, target_system);
    _mav_put_uint8_t(buf, 1, target_component);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GEOTAG_CANCEL, buf, MAVLINK_MSG_ID_GEOTAG_CANCEL_MIN_LEN, MAVLINK_MSG_ID_GEOTAG_CANCEL_LEN, MAVLINK_MSG_ID_GEOTAG_CANCEL_CRC);
#else
    mavlink_geotag_cancel_t *packet = (mavlink_geotag_cancel_t *)msgbuf;
    packet->target_system = target_system;
    packet->target_component = target_component;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GEOTAG_CANCEL, (const char *)packet, MAVLINK_MSG_ID_GEOTAG_CANCEL_MIN_LEN, MAVLINK_MSG_ID_GEOTAG_CANCEL_LEN, MAVLINK_MSG_ID_GEOTAG_CANCEL_CRC);
#endif
}
#endif

#endif

// MESSAGE GEOTAG_CANCEL UNPACKING


/**
 * @brief Get field target_system from geotag_cancel message
 *
 * @return System ID
 */
static inline uint8_t mavlink_msg_geotag_cancel_get_target_system(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field target_component from geotag_cancel message
 *
 * @return Component ID
 */
static inline uint8_t mavlink_msg_geotag_cancel_get_target_component(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  1);
}

/**
 * @brief Decode a geotag_cancel message into a struct
 *
 * @param msg The message to decode
 * @param geotag_cancel C-struct to decode the message contents into
 */
static inline void mavlink_msg_geotag_cancel_decode(const mavlink_message_t* msg, mavlink_geotag_cancel_t* geotag_cancel)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    geotag_cancel->target_system = mavlink_msg_geotag_cancel_get_target_system(msg);
    geotag_cancel->target_component = mavlink_msg_geotag_cancel_get_target_component(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_GEOTAG_CANCEL_LEN? msg->len : MAVLINK_MSG_ID_GEOTAG_CANCEL_LEN;
        memset(geotag_cancel, 0, MAVLINK_MSG_ID_GEOTAG_CANCEL_LEN);
    memcpy(geotag_cancel, _MAV_PAYLOAD(msg), len);
#endif
}
