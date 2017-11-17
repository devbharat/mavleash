#pragma once
// MESSAGE WP_ARMING_CHECK PACKING

#define MAVLINK_MSG_ID_WP_ARMING_CHECK 204

MAVPACKED(
typedef struct __mavlink_wp_arming_check_t {
 uint8_t arming_ready; /*<  Value for arming ready: true or false*/
}) mavlink_wp_arming_check_t;

#define MAVLINK_MSG_ID_WP_ARMING_CHECK_LEN 1
#define MAVLINK_MSG_ID_WP_ARMING_CHECK_MIN_LEN 1
#define MAVLINK_MSG_ID_204_LEN 1
#define MAVLINK_MSG_ID_204_MIN_LEN 1

#define MAVLINK_MSG_ID_WP_ARMING_CHECK_CRC 211
#define MAVLINK_MSG_ID_204_CRC 211



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_WP_ARMING_CHECK { \
    204, \
    "WP_ARMING_CHECK", \
    1, \
    {  { "arming_ready", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_wp_arming_check_t, arming_ready) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_WP_ARMING_CHECK { \
    "WP_ARMING_CHECK", \
    1, \
    {  { "arming_ready", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_wp_arming_check_t, arming_ready) }, \
         } \
}
#endif

/**
 * @brief Pack a wp_arming_check message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param arming_ready  Value for arming ready: true or false
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wp_arming_check_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t arming_ready)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WP_ARMING_CHECK_LEN];
    _mav_put_uint8_t(buf, 0, arming_ready);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WP_ARMING_CHECK_LEN);
#else
    mavlink_wp_arming_check_t packet;
    packet.arming_ready = arming_ready;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WP_ARMING_CHECK_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WP_ARMING_CHECK;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_WP_ARMING_CHECK_MIN_LEN, MAVLINK_MSG_ID_WP_ARMING_CHECK_LEN, MAVLINK_MSG_ID_WP_ARMING_CHECK_CRC);
}

/**
 * @brief Pack a wp_arming_check message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param arming_ready  Value for arming ready: true or false
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wp_arming_check_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t arming_ready)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WP_ARMING_CHECK_LEN];
    _mav_put_uint8_t(buf, 0, arming_ready);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WP_ARMING_CHECK_LEN);
#else
    mavlink_wp_arming_check_t packet;
    packet.arming_ready = arming_ready;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WP_ARMING_CHECK_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WP_ARMING_CHECK;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_WP_ARMING_CHECK_MIN_LEN, MAVLINK_MSG_ID_WP_ARMING_CHECK_LEN, MAVLINK_MSG_ID_WP_ARMING_CHECK_CRC);
}

/**
 * @brief Encode a wp_arming_check struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param wp_arming_check C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wp_arming_check_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_wp_arming_check_t* wp_arming_check)
{
    return mavlink_msg_wp_arming_check_pack(system_id, component_id, msg, wp_arming_check->arming_ready);
}

/**
 * @brief Encode a wp_arming_check struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param wp_arming_check C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wp_arming_check_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_wp_arming_check_t* wp_arming_check)
{
    return mavlink_msg_wp_arming_check_pack_chan(system_id, component_id, chan, msg, wp_arming_check->arming_ready);
}

/**
 * @brief Send a wp_arming_check message
 * @param chan MAVLink channel to send the message
 *
 * @param arming_ready  Value for arming ready: true or false
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_wp_arming_check_send(mavlink_channel_t chan, uint8_t arming_ready)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WP_ARMING_CHECK_LEN];
    _mav_put_uint8_t(buf, 0, arming_ready);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WP_ARMING_CHECK, buf, MAVLINK_MSG_ID_WP_ARMING_CHECK_MIN_LEN, MAVLINK_MSG_ID_WP_ARMING_CHECK_LEN, MAVLINK_MSG_ID_WP_ARMING_CHECK_CRC);
#else
    mavlink_wp_arming_check_t packet;
    packet.arming_ready = arming_ready;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WP_ARMING_CHECK, (const char *)&packet, MAVLINK_MSG_ID_WP_ARMING_CHECK_MIN_LEN, MAVLINK_MSG_ID_WP_ARMING_CHECK_LEN, MAVLINK_MSG_ID_WP_ARMING_CHECK_CRC);
#endif
}

/**
 * @brief Send a wp_arming_check message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_wp_arming_check_send_struct(mavlink_channel_t chan, const mavlink_wp_arming_check_t* wp_arming_check)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_wp_arming_check_send(chan, wp_arming_check->arming_ready);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WP_ARMING_CHECK, (const char *)wp_arming_check, MAVLINK_MSG_ID_WP_ARMING_CHECK_MIN_LEN, MAVLINK_MSG_ID_WP_ARMING_CHECK_LEN, MAVLINK_MSG_ID_WP_ARMING_CHECK_CRC);
#endif
}

#if MAVLINK_MSG_ID_WP_ARMING_CHECK_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_wp_arming_check_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t arming_ready)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint8_t(buf, 0, arming_ready);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WP_ARMING_CHECK, buf, MAVLINK_MSG_ID_WP_ARMING_CHECK_MIN_LEN, MAVLINK_MSG_ID_WP_ARMING_CHECK_LEN, MAVLINK_MSG_ID_WP_ARMING_CHECK_CRC);
#else
    mavlink_wp_arming_check_t *packet = (mavlink_wp_arming_check_t *)msgbuf;
    packet->arming_ready = arming_ready;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WP_ARMING_CHECK, (const char *)packet, MAVLINK_MSG_ID_WP_ARMING_CHECK_MIN_LEN, MAVLINK_MSG_ID_WP_ARMING_CHECK_LEN, MAVLINK_MSG_ID_WP_ARMING_CHECK_CRC);
#endif
}
#endif

#endif

// MESSAGE WP_ARMING_CHECK UNPACKING


/**
 * @brief Get field arming_ready from wp_arming_check message
 *
 * @return  Value for arming ready: true or false
 */
static inline uint8_t mavlink_msg_wp_arming_check_get_arming_ready(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Decode a wp_arming_check message into a struct
 *
 * @param msg The message to decode
 * @param wp_arming_check C-struct to decode the message contents into
 */
static inline void mavlink_msg_wp_arming_check_decode(const mavlink_message_t* msg, mavlink_wp_arming_check_t* wp_arming_check)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    wp_arming_check->arming_ready = mavlink_msg_wp_arming_check_get_arming_ready(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_WP_ARMING_CHECK_LEN? msg->len : MAVLINK_MSG_ID_WP_ARMING_CHECK_LEN;
        memset(wp_arming_check, 0, MAVLINK_MSG_ID_WP_ARMING_CHECK_LEN);
    memcpy(wp_arming_check, _MAV_PAYLOAD(msg), len);
#endif
}
