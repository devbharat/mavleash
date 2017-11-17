#pragma once
// MESSAGE PF_CHECK PACKING

#define MAVLINK_MSG_ID_PF_CHECK 203

MAVPACKED(
typedef struct __mavlink_pf_check_t {
 char checker[16]; /*<  Person signing safety check list*/
 char check[16]; /*<  Exact safety check performed*/
 uint8_t val; /*<  Value for check: true or false*/
}) mavlink_pf_check_t;

#define MAVLINK_MSG_ID_PF_CHECK_LEN 33
#define MAVLINK_MSG_ID_PF_CHECK_MIN_LEN 33
#define MAVLINK_MSG_ID_203_LEN 33
#define MAVLINK_MSG_ID_203_MIN_LEN 33

#define MAVLINK_MSG_ID_PF_CHECK_CRC 180
#define MAVLINK_MSG_ID_203_CRC 180

#define MAVLINK_MSG_PF_CHECK_FIELD_CHECKER_LEN 16
#define MAVLINK_MSG_PF_CHECK_FIELD_CHECK_LEN 16

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_PF_CHECK { \
    203, \
    "PF_CHECK", \
    3, \
    {  { "checker", NULL, MAVLINK_TYPE_CHAR, 16, 0, offsetof(mavlink_pf_check_t, checker) }, \
         { "check", NULL, MAVLINK_TYPE_CHAR, 16, 16, offsetof(mavlink_pf_check_t, check) }, \
         { "val", NULL, MAVLINK_TYPE_UINT8_T, 0, 32, offsetof(mavlink_pf_check_t, val) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_PF_CHECK { \
    "PF_CHECK", \
    3, \
    {  { "checker", NULL, MAVLINK_TYPE_CHAR, 16, 0, offsetof(mavlink_pf_check_t, checker) }, \
         { "check", NULL, MAVLINK_TYPE_CHAR, 16, 16, offsetof(mavlink_pf_check_t, check) }, \
         { "val", NULL, MAVLINK_TYPE_UINT8_T, 0, 32, offsetof(mavlink_pf_check_t, val) }, \
         } \
}
#endif

/**
 * @brief Pack a pf_check message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param checker  Person signing safety check list
 * @param check  Exact safety check performed
 * @param val  Value for check: true or false
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_pf_check_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               const char *checker, const char *check, uint8_t val)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_PF_CHECK_LEN];
    _mav_put_uint8_t(buf, 32, val);
    _mav_put_char_array(buf, 0, checker, 16);
    _mav_put_char_array(buf, 16, check, 16);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_PF_CHECK_LEN);
#else
    mavlink_pf_check_t packet;
    packet.val = val;
    mav_array_memcpy(packet.checker, checker, sizeof(char)*16);
    mav_array_memcpy(packet.check, check, sizeof(char)*16);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_PF_CHECK_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_PF_CHECK;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_PF_CHECK_MIN_LEN, MAVLINK_MSG_ID_PF_CHECK_LEN, MAVLINK_MSG_ID_PF_CHECK_CRC);
}

/**
 * @brief Pack a pf_check message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param checker  Person signing safety check list
 * @param check  Exact safety check performed
 * @param val  Value for check: true or false
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_pf_check_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   const char *checker,const char *check,uint8_t val)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_PF_CHECK_LEN];
    _mav_put_uint8_t(buf, 32, val);
    _mav_put_char_array(buf, 0, checker, 16);
    _mav_put_char_array(buf, 16, check, 16);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_PF_CHECK_LEN);
#else
    mavlink_pf_check_t packet;
    packet.val = val;
    mav_array_memcpy(packet.checker, checker, sizeof(char)*16);
    mav_array_memcpy(packet.check, check, sizeof(char)*16);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_PF_CHECK_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_PF_CHECK;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_PF_CHECK_MIN_LEN, MAVLINK_MSG_ID_PF_CHECK_LEN, MAVLINK_MSG_ID_PF_CHECK_CRC);
}

/**
 * @brief Encode a pf_check struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param pf_check C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_pf_check_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_pf_check_t* pf_check)
{
    return mavlink_msg_pf_check_pack(system_id, component_id, msg, pf_check->checker, pf_check->check, pf_check->val);
}

/**
 * @brief Encode a pf_check struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param pf_check C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_pf_check_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_pf_check_t* pf_check)
{
    return mavlink_msg_pf_check_pack_chan(system_id, component_id, chan, msg, pf_check->checker, pf_check->check, pf_check->val);
}

/**
 * @brief Send a pf_check message
 * @param chan MAVLink channel to send the message
 *
 * @param checker  Person signing safety check list
 * @param check  Exact safety check performed
 * @param val  Value for check: true or false
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_pf_check_send(mavlink_channel_t chan, const char *checker, const char *check, uint8_t val)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_PF_CHECK_LEN];
    _mav_put_uint8_t(buf, 32, val);
    _mav_put_char_array(buf, 0, checker, 16);
    _mav_put_char_array(buf, 16, check, 16);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PF_CHECK, buf, MAVLINK_MSG_ID_PF_CHECK_MIN_LEN, MAVLINK_MSG_ID_PF_CHECK_LEN, MAVLINK_MSG_ID_PF_CHECK_CRC);
#else
    mavlink_pf_check_t packet;
    packet.val = val;
    mav_array_memcpy(packet.checker, checker, sizeof(char)*16);
    mav_array_memcpy(packet.check, check, sizeof(char)*16);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PF_CHECK, (const char *)&packet, MAVLINK_MSG_ID_PF_CHECK_MIN_LEN, MAVLINK_MSG_ID_PF_CHECK_LEN, MAVLINK_MSG_ID_PF_CHECK_CRC);
#endif
}

/**
 * @brief Send a pf_check message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_pf_check_send_struct(mavlink_channel_t chan, const mavlink_pf_check_t* pf_check)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_pf_check_send(chan, pf_check->checker, pf_check->check, pf_check->val);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PF_CHECK, (const char *)pf_check, MAVLINK_MSG_ID_PF_CHECK_MIN_LEN, MAVLINK_MSG_ID_PF_CHECK_LEN, MAVLINK_MSG_ID_PF_CHECK_CRC);
#endif
}

#if MAVLINK_MSG_ID_PF_CHECK_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_pf_check_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  const char *checker, const char *check, uint8_t val)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint8_t(buf, 32, val);
    _mav_put_char_array(buf, 0, checker, 16);
    _mav_put_char_array(buf, 16, check, 16);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PF_CHECK, buf, MAVLINK_MSG_ID_PF_CHECK_MIN_LEN, MAVLINK_MSG_ID_PF_CHECK_LEN, MAVLINK_MSG_ID_PF_CHECK_CRC);
#else
    mavlink_pf_check_t *packet = (mavlink_pf_check_t *)msgbuf;
    packet->val = val;
    mav_array_memcpy(packet->checker, checker, sizeof(char)*16);
    mav_array_memcpy(packet->check, check, sizeof(char)*16);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PF_CHECK, (const char *)packet, MAVLINK_MSG_ID_PF_CHECK_MIN_LEN, MAVLINK_MSG_ID_PF_CHECK_LEN, MAVLINK_MSG_ID_PF_CHECK_CRC);
#endif
}
#endif

#endif

// MESSAGE PF_CHECK UNPACKING


/**
 * @brief Get field checker from pf_check message
 *
 * @return  Person signing safety check list
 */
static inline uint16_t mavlink_msg_pf_check_get_checker(const mavlink_message_t* msg, char *checker)
{
    return _MAV_RETURN_char_array(msg, checker, 16,  0);
}

/**
 * @brief Get field check from pf_check message
 *
 * @return  Exact safety check performed
 */
static inline uint16_t mavlink_msg_pf_check_get_check(const mavlink_message_t* msg, char *check)
{
    return _MAV_RETURN_char_array(msg, check, 16,  16);
}

/**
 * @brief Get field val from pf_check message
 *
 * @return  Value for check: true or false
 */
static inline uint8_t mavlink_msg_pf_check_get_val(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  32);
}

/**
 * @brief Decode a pf_check message into a struct
 *
 * @param msg The message to decode
 * @param pf_check C-struct to decode the message contents into
 */
static inline void mavlink_msg_pf_check_decode(const mavlink_message_t* msg, mavlink_pf_check_t* pf_check)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_pf_check_get_checker(msg, pf_check->checker);
    mavlink_msg_pf_check_get_check(msg, pf_check->check);
    pf_check->val = mavlink_msg_pf_check_get_val(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_PF_CHECK_LEN? msg->len : MAVLINK_MSG_ID_PF_CHECK_LEN;
        memset(pf_check, 0, MAVLINK_MSG_ID_PF_CHECK_LEN);
    memcpy(pf_check, _MAV_PAYLOAD(msg), len);
#endif
}
