#pragma once
// MESSAGE GEOTAG_ITEM PACKING

#define MAVLINK_MSG_ID_GEOTAG_ITEM 205

MAVPACKED(
typedef struct __mavlink_geotag_item_t {
 double time; /*< tag timestamp*/
 double lat; /*< latitude*/
 double lon; /*< longitude*/
 float alt; /*< altitude*/
 float roll; /*< vehicle roll*/
 float pitch; /*< vehicle pitch*/
 float yaw; /*< vehicle yaw*/
 uint16_t seq; /*< tag sequence number*/
 uint8_t target_system; /*< System ID*/
 uint8_t target_component; /*< Component ID*/
}) mavlink_geotag_item_t;

#define MAVLINK_MSG_ID_GEOTAG_ITEM_LEN 44
#define MAVLINK_MSG_ID_GEOTAG_ITEM_MIN_LEN 44
#define MAVLINK_MSG_ID_205_LEN 44
#define MAVLINK_MSG_ID_205_MIN_LEN 44

#define MAVLINK_MSG_ID_GEOTAG_ITEM_CRC 46
#define MAVLINK_MSG_ID_205_CRC 46



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_GEOTAG_ITEM { \
    205, \
    "GEOTAG_ITEM", \
    10, \
    {  { "time", NULL, MAVLINK_TYPE_DOUBLE, 0, 0, offsetof(mavlink_geotag_item_t, time) }, \
         { "lat", NULL, MAVLINK_TYPE_DOUBLE, 0, 8, offsetof(mavlink_geotag_item_t, lat) }, \
         { "lon", NULL, MAVLINK_TYPE_DOUBLE, 0, 16, offsetof(mavlink_geotag_item_t, lon) }, \
         { "alt", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_geotag_item_t, alt) }, \
         { "roll", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_geotag_item_t, roll) }, \
         { "pitch", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_geotag_item_t, pitch) }, \
         { "yaw", NULL, MAVLINK_TYPE_FLOAT, 0, 36, offsetof(mavlink_geotag_item_t, yaw) }, \
         { "seq", NULL, MAVLINK_TYPE_UINT16_T, 0, 40, offsetof(mavlink_geotag_item_t, seq) }, \
         { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 42, offsetof(mavlink_geotag_item_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 43, offsetof(mavlink_geotag_item_t, target_component) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_GEOTAG_ITEM { \
    "GEOTAG_ITEM", \
    10, \
    {  { "time", NULL, MAVLINK_TYPE_DOUBLE, 0, 0, offsetof(mavlink_geotag_item_t, time) }, \
         { "lat", NULL, MAVLINK_TYPE_DOUBLE, 0, 8, offsetof(mavlink_geotag_item_t, lat) }, \
         { "lon", NULL, MAVLINK_TYPE_DOUBLE, 0, 16, offsetof(mavlink_geotag_item_t, lon) }, \
         { "alt", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_geotag_item_t, alt) }, \
         { "roll", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_geotag_item_t, roll) }, \
         { "pitch", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_geotag_item_t, pitch) }, \
         { "yaw", NULL, MAVLINK_TYPE_FLOAT, 0, 36, offsetof(mavlink_geotag_item_t, yaw) }, \
         { "seq", NULL, MAVLINK_TYPE_UINT16_T, 0, 40, offsetof(mavlink_geotag_item_t, seq) }, \
         { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 42, offsetof(mavlink_geotag_item_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 43, offsetof(mavlink_geotag_item_t, target_component) }, \
         } \
}
#endif

/**
 * @brief Pack a geotag_item message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param target_system System ID
 * @param target_component Component ID
 * @param seq tag sequence number
 * @param time tag timestamp
 * @param lat latitude
 * @param lon longitude
 * @param alt altitude
 * @param roll vehicle roll
 * @param pitch vehicle pitch
 * @param yaw vehicle yaw
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_geotag_item_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t target_system, uint8_t target_component, uint16_t seq, double time, double lat, double lon, float alt, float roll, float pitch, float yaw)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_GEOTAG_ITEM_LEN];
    _mav_put_double(buf, 0, time);
    _mav_put_double(buf, 8, lat);
    _mav_put_double(buf, 16, lon);
    _mav_put_float(buf, 24, alt);
    _mav_put_float(buf, 28, roll);
    _mav_put_float(buf, 32, pitch);
    _mav_put_float(buf, 36, yaw);
    _mav_put_uint16_t(buf, 40, seq);
    _mav_put_uint8_t(buf, 42, target_system);
    _mav_put_uint8_t(buf, 43, target_component);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_GEOTAG_ITEM_LEN);
#else
    mavlink_geotag_item_t packet;
    packet.time = time;
    packet.lat = lat;
    packet.lon = lon;
    packet.alt = alt;
    packet.roll = roll;
    packet.pitch = pitch;
    packet.yaw = yaw;
    packet.seq = seq;
    packet.target_system = target_system;
    packet.target_component = target_component;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_GEOTAG_ITEM_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_GEOTAG_ITEM;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_GEOTAG_ITEM_MIN_LEN, MAVLINK_MSG_ID_GEOTAG_ITEM_LEN, MAVLINK_MSG_ID_GEOTAG_ITEM_CRC);
}

/**
 * @brief Pack a geotag_item message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param target_system System ID
 * @param target_component Component ID
 * @param seq tag sequence number
 * @param time tag timestamp
 * @param lat latitude
 * @param lon longitude
 * @param alt altitude
 * @param roll vehicle roll
 * @param pitch vehicle pitch
 * @param yaw vehicle yaw
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_geotag_item_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t target_system,uint8_t target_component,uint16_t seq,double time,double lat,double lon,float alt,float roll,float pitch,float yaw)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_GEOTAG_ITEM_LEN];
    _mav_put_double(buf, 0, time);
    _mav_put_double(buf, 8, lat);
    _mav_put_double(buf, 16, lon);
    _mav_put_float(buf, 24, alt);
    _mav_put_float(buf, 28, roll);
    _mav_put_float(buf, 32, pitch);
    _mav_put_float(buf, 36, yaw);
    _mav_put_uint16_t(buf, 40, seq);
    _mav_put_uint8_t(buf, 42, target_system);
    _mav_put_uint8_t(buf, 43, target_component);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_GEOTAG_ITEM_LEN);
#else
    mavlink_geotag_item_t packet;
    packet.time = time;
    packet.lat = lat;
    packet.lon = lon;
    packet.alt = alt;
    packet.roll = roll;
    packet.pitch = pitch;
    packet.yaw = yaw;
    packet.seq = seq;
    packet.target_system = target_system;
    packet.target_component = target_component;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_GEOTAG_ITEM_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_GEOTAG_ITEM;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_GEOTAG_ITEM_MIN_LEN, MAVLINK_MSG_ID_GEOTAG_ITEM_LEN, MAVLINK_MSG_ID_GEOTAG_ITEM_CRC);
}

/**
 * @brief Encode a geotag_item struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param geotag_item C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_geotag_item_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_geotag_item_t* geotag_item)
{
    return mavlink_msg_geotag_item_pack(system_id, component_id, msg, geotag_item->target_system, geotag_item->target_component, geotag_item->seq, geotag_item->time, geotag_item->lat, geotag_item->lon, geotag_item->alt, geotag_item->roll, geotag_item->pitch, geotag_item->yaw);
}

/**
 * @brief Encode a geotag_item struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param geotag_item C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_geotag_item_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_geotag_item_t* geotag_item)
{
    return mavlink_msg_geotag_item_pack_chan(system_id, component_id, chan, msg, geotag_item->target_system, geotag_item->target_component, geotag_item->seq, geotag_item->time, geotag_item->lat, geotag_item->lon, geotag_item->alt, geotag_item->roll, geotag_item->pitch, geotag_item->yaw);
}

/**
 * @brief Send a geotag_item message
 * @param chan MAVLink channel to send the message
 *
 * @param target_system System ID
 * @param target_component Component ID
 * @param seq tag sequence number
 * @param time tag timestamp
 * @param lat latitude
 * @param lon longitude
 * @param alt altitude
 * @param roll vehicle roll
 * @param pitch vehicle pitch
 * @param yaw vehicle yaw
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_geotag_item_send(mavlink_channel_t chan, uint8_t target_system, uint8_t target_component, uint16_t seq, double time, double lat, double lon, float alt, float roll, float pitch, float yaw)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_GEOTAG_ITEM_LEN];
    _mav_put_double(buf, 0, time);
    _mav_put_double(buf, 8, lat);
    _mav_put_double(buf, 16, lon);
    _mav_put_float(buf, 24, alt);
    _mav_put_float(buf, 28, roll);
    _mav_put_float(buf, 32, pitch);
    _mav_put_float(buf, 36, yaw);
    _mav_put_uint16_t(buf, 40, seq);
    _mav_put_uint8_t(buf, 42, target_system);
    _mav_put_uint8_t(buf, 43, target_component);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GEOTAG_ITEM, buf, MAVLINK_MSG_ID_GEOTAG_ITEM_MIN_LEN, MAVLINK_MSG_ID_GEOTAG_ITEM_LEN, MAVLINK_MSG_ID_GEOTAG_ITEM_CRC);
#else
    mavlink_geotag_item_t packet;
    packet.time = time;
    packet.lat = lat;
    packet.lon = lon;
    packet.alt = alt;
    packet.roll = roll;
    packet.pitch = pitch;
    packet.yaw = yaw;
    packet.seq = seq;
    packet.target_system = target_system;
    packet.target_component = target_component;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GEOTAG_ITEM, (const char *)&packet, MAVLINK_MSG_ID_GEOTAG_ITEM_MIN_LEN, MAVLINK_MSG_ID_GEOTAG_ITEM_LEN, MAVLINK_MSG_ID_GEOTAG_ITEM_CRC);
#endif
}

/**
 * @brief Send a geotag_item message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_geotag_item_send_struct(mavlink_channel_t chan, const mavlink_geotag_item_t* geotag_item)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_geotag_item_send(chan, geotag_item->target_system, geotag_item->target_component, geotag_item->seq, geotag_item->time, geotag_item->lat, geotag_item->lon, geotag_item->alt, geotag_item->roll, geotag_item->pitch, geotag_item->yaw);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GEOTAG_ITEM, (const char *)geotag_item, MAVLINK_MSG_ID_GEOTAG_ITEM_MIN_LEN, MAVLINK_MSG_ID_GEOTAG_ITEM_LEN, MAVLINK_MSG_ID_GEOTAG_ITEM_CRC);
#endif
}

#if MAVLINK_MSG_ID_GEOTAG_ITEM_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_geotag_item_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t target_system, uint8_t target_component, uint16_t seq, double time, double lat, double lon, float alt, float roll, float pitch, float yaw)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_double(buf, 0, time);
    _mav_put_double(buf, 8, lat);
    _mav_put_double(buf, 16, lon);
    _mav_put_float(buf, 24, alt);
    _mav_put_float(buf, 28, roll);
    _mav_put_float(buf, 32, pitch);
    _mav_put_float(buf, 36, yaw);
    _mav_put_uint16_t(buf, 40, seq);
    _mav_put_uint8_t(buf, 42, target_system);
    _mav_put_uint8_t(buf, 43, target_component);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GEOTAG_ITEM, buf, MAVLINK_MSG_ID_GEOTAG_ITEM_MIN_LEN, MAVLINK_MSG_ID_GEOTAG_ITEM_LEN, MAVLINK_MSG_ID_GEOTAG_ITEM_CRC);
#else
    mavlink_geotag_item_t *packet = (mavlink_geotag_item_t *)msgbuf;
    packet->time = time;
    packet->lat = lat;
    packet->lon = lon;
    packet->alt = alt;
    packet->roll = roll;
    packet->pitch = pitch;
    packet->yaw = yaw;
    packet->seq = seq;
    packet->target_system = target_system;
    packet->target_component = target_component;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GEOTAG_ITEM, (const char *)packet, MAVLINK_MSG_ID_GEOTAG_ITEM_MIN_LEN, MAVLINK_MSG_ID_GEOTAG_ITEM_LEN, MAVLINK_MSG_ID_GEOTAG_ITEM_CRC);
#endif
}
#endif

#endif

// MESSAGE GEOTAG_ITEM UNPACKING


/**
 * @brief Get field target_system from geotag_item message
 *
 * @return System ID
 */
static inline uint8_t mavlink_msg_geotag_item_get_target_system(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  42);
}

/**
 * @brief Get field target_component from geotag_item message
 *
 * @return Component ID
 */
static inline uint8_t mavlink_msg_geotag_item_get_target_component(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  43);
}

/**
 * @brief Get field seq from geotag_item message
 *
 * @return tag sequence number
 */
static inline uint16_t mavlink_msg_geotag_item_get_seq(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  40);
}

/**
 * @brief Get field time from geotag_item message
 *
 * @return tag timestamp
 */
static inline double mavlink_msg_geotag_item_get_time(const mavlink_message_t* msg)
{
    return _MAV_RETURN_double(msg,  0);
}

/**
 * @brief Get field lat from geotag_item message
 *
 * @return latitude
 */
static inline double mavlink_msg_geotag_item_get_lat(const mavlink_message_t* msg)
{
    return _MAV_RETURN_double(msg,  8);
}

/**
 * @brief Get field lon from geotag_item message
 *
 * @return longitude
 */
static inline double mavlink_msg_geotag_item_get_lon(const mavlink_message_t* msg)
{
    return _MAV_RETURN_double(msg,  16);
}

/**
 * @brief Get field alt from geotag_item message
 *
 * @return altitude
 */
static inline float mavlink_msg_geotag_item_get_alt(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  24);
}

/**
 * @brief Get field roll from geotag_item message
 *
 * @return vehicle roll
 */
static inline float mavlink_msg_geotag_item_get_roll(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  28);
}

/**
 * @brief Get field pitch from geotag_item message
 *
 * @return vehicle pitch
 */
static inline float mavlink_msg_geotag_item_get_pitch(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  32);
}

/**
 * @brief Get field yaw from geotag_item message
 *
 * @return vehicle yaw
 */
static inline float mavlink_msg_geotag_item_get_yaw(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  36);
}

/**
 * @brief Decode a geotag_item message into a struct
 *
 * @param msg The message to decode
 * @param geotag_item C-struct to decode the message contents into
 */
static inline void mavlink_msg_geotag_item_decode(const mavlink_message_t* msg, mavlink_geotag_item_t* geotag_item)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    geotag_item->time = mavlink_msg_geotag_item_get_time(msg);
    geotag_item->lat = mavlink_msg_geotag_item_get_lat(msg);
    geotag_item->lon = mavlink_msg_geotag_item_get_lon(msg);
    geotag_item->alt = mavlink_msg_geotag_item_get_alt(msg);
    geotag_item->roll = mavlink_msg_geotag_item_get_roll(msg);
    geotag_item->pitch = mavlink_msg_geotag_item_get_pitch(msg);
    geotag_item->yaw = mavlink_msg_geotag_item_get_yaw(msg);
    geotag_item->seq = mavlink_msg_geotag_item_get_seq(msg);
    geotag_item->target_system = mavlink_msg_geotag_item_get_target_system(msg);
    geotag_item->target_component = mavlink_msg_geotag_item_get_target_component(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_GEOTAG_ITEM_LEN? msg->len : MAVLINK_MSG_ID_GEOTAG_ITEM_LEN;
        memset(geotag_item, 0, MAVLINK_MSG_ID_GEOTAG_ITEM_LEN);
    memcpy(geotag_item, _MAV_PAYLOAD(msg), len);
#endif
}
