/* Automatically generated nanopb header */
/* Generated by nanopb-0.4.8-dev */

#ifndef PB_MESSAGE_PB_H_INCLUDED
#define PB_MESSAGE_PB_H_INCLUDED
#include <pb.h>

#if PB_PROTO_HEADER_VERSION != 40
#error Regenerate this file with the current version of nanopb generator.
#endif

/* Enum definitions */
/* * defined by Bosch */
typedef enum _SignalIdentifier {
    SignalIdentifier_UNDEFINED = 0,
    SignalIdentifier_IAQ = 1,
    SignalIdentifier_STATIC_IAQ = 2,
    SignalIdentifier_CO2_EQ = 3,
    SignalIdentifier_BREATH_VOC_EQ = 4,
    SignalIdentifier_RAW_TEMPERATURE = 6,
    SignalIdentifier_RAW_PRESSURE = 7,
    SignalIdentifier_RAW_HUMIDITY = 8,
    SignalIdentifier_RAW_GAS = 9,
    SignalIdentifier_STABILIZATION_STATUS = 12,
    SignalIdentifier_RUN_IN_STATUS = 13,
    SignalIdentifier_SENSOR_HEAT_COMPEN_TEMP = 14,
    SignalIdentifier_HEAT_COMPEN_HUMID = 15,
    SignalIdentifier_GAS_PERCENTAGE = 21
} SignalIdentifier;

/* * defined by Bosch */
typedef enum _SensorAccuracy {
    SensorAccuracy_UNRELIABLE = 0,
    SensorAccuracy_LOW_ACCURACY = 1,
    SensorAccuracy_MEDIUM_ACCURACY = 2,
    SensorAccuracy_HIGH_ACCURACY = 3
} SensorAccuracy;

typedef enum _MicSampleFreq {
    MicSampleFreq_SAMPLE_RATE_16000 = 0,
    MicSampleFreq_SAMPLE_RATE_20500 = 1,
    MicSampleFreq_SAMPLE_RATE_44100 = 2,
    MicSampleFreq_SAMPLE_RATE_48000 = 3,
    MicSampleFreq_SAMPLE_RATE_96000 = 4
} MicSampleFreq;

typedef enum _MicBitResolution {
    MicBitResolution_BIT_RES_8 = 0,
    MicBitResolution_BIT_RES_16 = 1
} MicBitResolution;

/* Struct definitions */
typedef struct _PacketHeader {
    uint32_t system_uid;
    uint32_t ms_from_start;
    uint64_t epoch;
} PacketHeader;

typedef struct _SimpleSensorReading {
    uint32_t index;
    uint32_t timestamp_unix;
    float temperature;
    float humidity;
    float co2;
} SimpleSensorReading;

typedef struct _SensorReading {
    uint32_t packet_index;
    uint32_t sample_period;
    pb_callback_t payload;
} SensorReading;

typedef struct _SensorReading_Payload {
    uint64_t timestamp_sensor;
    uint64_t timestamp_unix;
    uint32_t timestamp_ms_from_start;
    float signal;
    uint32_t signal_dimensions;
    SignalIdentifier sensor_id;
    SensorAccuracy accuracy;
} SensorReading_Payload;

typedef struct _SensorConfig {
    uint32_t sample_period_ms;
    bool enable_temperature;
    bool enable_humidity;
    bool enable_gas;
} SensorConfig;

typedef struct _SDCardState {
    bool detected;
    uint64_t space_remaining;
    uint64_t estimated_remaining_recording_time;
} SDCardState;

typedef struct _MarkState {
    bool beep_enabled;
    uint32_t mark_number;
    uint64_t timestamp_unix;
} MarkState;

typedef struct _MarkPacket {
    bool beep_enabled;
    bool has_annotation;
    char annotation[100]; /* throttle max character count (e.g., 50) */
} MarkPacket;

typedef struct _DiscoveredDevices {
    uint32_t number_of_devices;
    pb_callback_t device;
} DiscoveredDevices;

typedef struct _DiscoveredDevices_Device {
    uint32_t UID;
    float range;
} DiscoveredDevices_Device;

typedef struct _SystemInfoPacket {
    uint32_t number_discovered_devices;
    bool has_simple_sensor_reading;
    SimpleSensorReading simple_sensor_reading;
    bool device_recording;
    bool has_sdcard_state;
    SDCardState sdcard_state;
    bool has_mark_state;
    MarkState mark_state;
    bool has_discovered_devices;
    DiscoveredDevices discovered_devices;
} SystemInfoPacket;

typedef struct _AudioCompression {
    bool enabled;
    uint32_t compression_factor;
} AudioCompression;

typedef struct _AudioConfig {
    bool channel_1;
    bool channel_2;
    MicSampleFreq sample_freq;
    MicBitResolution bit_resolution;
    bool has_audio_compression;
    AudioCompression audio_compression;
} AudioConfig;

typedef struct _ScheduleConfig {
    bool Sunday;
    bool Monday;
    bool Tuesday;
    bool Wednesday;
    bool Thursday;
    bool Friday;
    bool Saturday;
    uint32_t start_hour;
    uint32_t start_minute;
    uint32_t stop_hour;
    uint32_t stop_minute;
} ScheduleConfig;

typedef struct _ConfigPacket {
    bool has_audio_config;
    AudioConfig audio_config;
    pb_callback_t schedule_config;
    bool has_sensor_config;
    SensorConfig sensor_config;
} ConfigPacket;

typedef struct _SpecialFunction {
    pb_size_t which_payload;
    union {
        bool format_sdcard;
        bool function_2;
        bool function_3;
        bool function_4;
        bool function_5;
        bool function_6;
        bool function_7;
        bool function_8;
    } payload;
} SpecialFunction;

typedef struct _Packet {
    bool has_header;
    PacketHeader header;
    pb_size_t which_payload;
    union {
        SystemInfoPacket system_info_packet;
        MarkPacket mark_packet;
        ConfigPacket config_packet;
        SpecialFunction special_function;
    } payload;
} Packet;


#ifdef __cplusplus
extern "C" {
#endif

/* Helper constants for enums */
#define _SignalIdentifier_MIN SignalIdentifier_UNDEFINED
#define _SignalIdentifier_MAX SignalIdentifier_GAS_PERCENTAGE
#define _SignalIdentifier_ARRAYSIZE ((SignalIdentifier)(SignalIdentifier_GAS_PERCENTAGE+1))

#define _SensorAccuracy_MIN SensorAccuracy_UNRELIABLE
#define _SensorAccuracy_MAX SensorAccuracy_HIGH_ACCURACY
#define _SensorAccuracy_ARRAYSIZE ((SensorAccuracy)(SensorAccuracy_HIGH_ACCURACY+1))

#define _MicSampleFreq_MIN MicSampleFreq_SAMPLE_RATE_16000
#define _MicSampleFreq_MAX MicSampleFreq_SAMPLE_RATE_96000
#define _MicSampleFreq_ARRAYSIZE ((MicSampleFreq)(MicSampleFreq_SAMPLE_RATE_96000+1))

#define _MicBitResolution_MIN MicBitResolution_BIT_RES_8
#define _MicBitResolution_MAX MicBitResolution_BIT_RES_16
#define _MicBitResolution_ARRAYSIZE ((MicBitResolution)(MicBitResolution_BIT_RES_16+1))




#define SensorReading_Payload_sensor_id_ENUMTYPE SignalIdentifier
#define SensorReading_Payload_accuracy_ENUMTYPE SensorAccuracy









#define AudioConfig_sample_freq_ENUMTYPE MicSampleFreq
#define AudioConfig_bit_resolution_ENUMTYPE MicBitResolution






/* Initializer values for message structs */
#define PacketHeader_init_default                {0, 0, 0}
#define SimpleSensorReading_init_default         {0, 0, 0, 0, 0}
#define SensorReading_init_default               {0, 0, {{NULL}, NULL}}
#define SensorReading_Payload_init_default       {0, 0, 0, 0, 0, _SignalIdentifier_MIN, _SensorAccuracy_MIN}
#define SensorConfig_init_default                {0, 0, 0, 0}
#define SDCardState_init_default                 {0, 0, 0}
#define MarkState_init_default                   {0, 0, 0}
#define MarkPacket_init_default                  {0, false, ""}
#define DiscoveredDevices_init_default           {0, {{NULL}, NULL}}
#define DiscoveredDevices_Device_init_default    {0, 0}
#define SystemInfoPacket_init_default            {0, false, SimpleSensorReading_init_default, 0, false, SDCardState_init_default, false, MarkState_init_default, false, DiscoveredDevices_init_default}
#define AudioCompression_init_default            {0, 0}
#define AudioConfig_init_default                 {0, 0, _MicSampleFreq_MIN, _MicBitResolution_MIN, false, AudioCompression_init_default}
#define ScheduleConfig_init_default              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
#define ConfigPacket_init_default                {false, AudioConfig_init_default, {{NULL}, NULL}, false, SensorConfig_init_default}
#define SpecialFunction_init_default             {0, {0}}
#define Packet_init_default                      {false, PacketHeader_init_default, 0, {SystemInfoPacket_init_default}}
#define PacketHeader_init_zero                   {0, 0, 0}
#define SimpleSensorReading_init_zero            {0, 0, 0, 0, 0}
#define SensorReading_init_zero                  {0, 0, {{NULL}, NULL}}
#define SensorReading_Payload_init_zero          {0, 0, 0, 0, 0, _SignalIdentifier_MIN, _SensorAccuracy_MIN}
#define SensorConfig_init_zero                   {0, 0, 0, 0}
#define SDCardState_init_zero                    {0, 0, 0}
#define MarkState_init_zero                      {0, 0, 0}
#define MarkPacket_init_zero                     {0, false, ""}
#define DiscoveredDevices_init_zero              {0, {{NULL}, NULL}}
#define DiscoveredDevices_Device_init_zero       {0, 0}
#define SystemInfoPacket_init_zero               {0, false, SimpleSensorReading_init_zero, 0, false, SDCardState_init_zero, false, MarkState_init_zero, false, DiscoveredDevices_init_zero}
#define AudioCompression_init_zero               {0, 0}
#define AudioConfig_init_zero                    {0, 0, _MicSampleFreq_MIN, _MicBitResolution_MIN, false, AudioCompression_init_zero}
#define ScheduleConfig_init_zero                 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
#define ConfigPacket_init_zero                   {false, AudioConfig_init_zero, {{NULL}, NULL}, false, SensorConfig_init_zero}
#define SpecialFunction_init_zero                {0, {0}}
#define Packet_init_zero                         {false, PacketHeader_init_zero, 0, {SystemInfoPacket_init_zero}}

/* Field tags (for use in manual encoding/decoding) */
#define PacketHeader_system_uid_tag              1
#define PacketHeader_ms_from_start_tag           2
#define PacketHeader_epoch_tag                   3
#define SimpleSensorReading_index_tag            1
#define SimpleSensorReading_timestamp_unix_tag   2
#define SimpleSensorReading_temperature_tag      3
#define SimpleSensorReading_humidity_tag         4
#define SimpleSensorReading_co2_tag              5
#define SensorReading_packet_index_tag           1
#define SensorReading_sample_period_tag          2
#define SensorReading_payload_tag                3
#define SensorReading_Payload_timestamp_sensor_tag 1
#define SensorReading_Payload_timestamp_unix_tag 2
#define SensorReading_Payload_timestamp_ms_from_start_tag 3
#define SensorReading_Payload_signal_tag         4
#define SensorReading_Payload_signal_dimensions_tag 5
#define SensorReading_Payload_sensor_id_tag      6
#define SensorReading_Payload_accuracy_tag       7
#define SensorConfig_sample_period_ms_tag        1
#define SensorConfig_enable_temperature_tag      2
#define SensorConfig_enable_humidity_tag         3
#define SensorConfig_enable_gas_tag              4
#define SDCardState_detected_tag                 1
#define SDCardState_space_remaining_tag          2
#define SDCardState_estimated_remaining_recording_time_tag 3
#define MarkState_beep_enabled_tag               1
#define MarkState_mark_number_tag                2
#define MarkState_timestamp_unix_tag             3
#define MarkPacket_beep_enabled_tag              1
#define MarkPacket_annotation_tag                2
#define DiscoveredDevices_number_of_devices_tag  1
#define DiscoveredDevices_device_tag             2
#define DiscoveredDevices_Device_UID_tag         1
#define DiscoveredDevices_Device_range_tag       2
#define SystemInfoPacket_number_discovered_devices_tag 1
#define SystemInfoPacket_simple_sensor_reading_tag 2
#define SystemInfoPacket_device_recording_tag    3
#define SystemInfoPacket_sdcard_state_tag        4
#define SystemInfoPacket_mark_state_tag          5
#define SystemInfoPacket_discovered_devices_tag  6
#define AudioCompression_enabled_tag             1
#define AudioCompression_compression_factor_tag  2
#define AudioConfig_channel_1_tag                1
#define AudioConfig_channel_2_tag                2
#define AudioConfig_sample_freq_tag              3
#define AudioConfig_bit_resolution_tag           4
#define AudioConfig_audio_compression_tag        5
#define ScheduleConfig_Sunday_tag                1
#define ScheduleConfig_Monday_tag                2
#define ScheduleConfig_Tuesday_tag               3
#define ScheduleConfig_Wednesday_tag             4
#define ScheduleConfig_Thursday_tag              5
#define ScheduleConfig_Friday_tag                6
#define ScheduleConfig_Saturday_tag              7
#define ScheduleConfig_start_hour_tag            8
#define ScheduleConfig_start_minute_tag          9
#define ScheduleConfig_stop_hour_tag             10
#define ScheduleConfig_stop_minute_tag           11
#define ConfigPacket_audio_config_tag            1
#define ConfigPacket_schedule_config_tag         2
#define ConfigPacket_sensor_config_tag           3
#define SpecialFunction_format_sdcard_tag        1
#define SpecialFunction_function_2_tag           2
#define SpecialFunction_function_3_tag           3
#define SpecialFunction_function_4_tag           4
#define SpecialFunction_function_5_tag           5
#define SpecialFunction_function_6_tag           6
#define SpecialFunction_function_7_tag           7
#define SpecialFunction_function_8_tag           8
#define Packet_header_tag                        1
#define Packet_system_info_packet_tag            2
#define Packet_mark_packet_tag                   3
#define Packet_config_packet_tag                 4
#define Packet_special_function_tag              5

/* Struct field encoding specification for nanopb */
#define PacketHeader_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, UINT32,   system_uid,        1) \
X(a, STATIC,   SINGULAR, UINT32,   ms_from_start,     2) \
X(a, STATIC,   SINGULAR, UINT64,   epoch,             3)
#define PacketHeader_CALLBACK NULL
#define PacketHeader_DEFAULT NULL

#define SimpleSensorReading_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, UINT32,   index,             1) \
X(a, STATIC,   SINGULAR, UINT32,   timestamp_unix,    2) \
X(a, STATIC,   SINGULAR, FLOAT,    temperature,       3) \
X(a, STATIC,   SINGULAR, FLOAT,    humidity,          4) \
X(a, STATIC,   SINGULAR, FLOAT,    co2,               5)
#define SimpleSensorReading_CALLBACK NULL
#define SimpleSensorReading_DEFAULT NULL

#define SensorReading_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, UINT32,   packet_index,      1) \
X(a, STATIC,   SINGULAR, UINT32,   sample_period,     2) \
X(a, CALLBACK, REPEATED, MESSAGE,  payload,           3)
#define SensorReading_CALLBACK pb_default_field_callback
#define SensorReading_DEFAULT NULL
#define SensorReading_payload_MSGTYPE SensorReading_Payload

#define SensorReading_Payload_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, FIXED64,  timestamp_sensor,   1) \
X(a, STATIC,   SINGULAR, UINT64,   timestamp_unix,    2) \
X(a, STATIC,   SINGULAR, UINT32,   timestamp_ms_from_start,   3) \
X(a, STATIC,   SINGULAR, FLOAT,    signal,            4) \
X(a, STATIC,   SINGULAR, UINT32,   signal_dimensions,   5) \
X(a, STATIC,   SINGULAR, UENUM,    sensor_id,         6) \
X(a, STATIC,   SINGULAR, UENUM,    accuracy,          7)
#define SensorReading_Payload_CALLBACK NULL
#define SensorReading_Payload_DEFAULT NULL

#define SensorConfig_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, UINT32,   sample_period_ms,   1) \
X(a, STATIC,   SINGULAR, BOOL,     enable_temperature,   2) \
X(a, STATIC,   SINGULAR, BOOL,     enable_humidity,   3) \
X(a, STATIC,   SINGULAR, BOOL,     enable_gas,        4)
#define SensorConfig_CALLBACK NULL
#define SensorConfig_DEFAULT NULL

#define SDCardState_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, BOOL,     detected,          1) \
X(a, STATIC,   SINGULAR, UINT64,   space_remaining,   2) \
X(a, STATIC,   SINGULAR, UINT64,   estimated_remaining_recording_time,   3)
#define SDCardState_CALLBACK NULL
#define SDCardState_DEFAULT NULL

#define MarkState_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, BOOL,     beep_enabled,      1) \
X(a, STATIC,   SINGULAR, UINT32,   mark_number,       2) \
X(a, STATIC,   SINGULAR, UINT64,   timestamp_unix,    3)
#define MarkState_CALLBACK NULL
#define MarkState_DEFAULT NULL

#define MarkPacket_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, BOOL,     beep_enabled,      1) \
X(a, STATIC,   OPTIONAL, STRING,   annotation,        2)
#define MarkPacket_CALLBACK NULL
#define MarkPacket_DEFAULT NULL

#define DiscoveredDevices_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, UINT32,   number_of_devices,   1) \
X(a, CALLBACK, REPEATED, MESSAGE,  device,            2)
#define DiscoveredDevices_CALLBACK pb_default_field_callback
#define DiscoveredDevices_DEFAULT NULL
#define DiscoveredDevices_device_MSGTYPE DiscoveredDevices_Device

#define DiscoveredDevices_Device_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, UINT32,   UID,               1) \
X(a, STATIC,   SINGULAR, FLOAT,    range,             2)
#define DiscoveredDevices_Device_CALLBACK NULL
#define DiscoveredDevices_Device_DEFAULT NULL

#define SystemInfoPacket_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, UINT32,   number_discovered_devices,   1) \
X(a, STATIC,   OPTIONAL, MESSAGE,  simple_sensor_reading,   2) \
X(a, STATIC,   SINGULAR, BOOL,     device_recording,   3) \
X(a, STATIC,   OPTIONAL, MESSAGE,  sdcard_state,      4) \
X(a, STATIC,   OPTIONAL, MESSAGE,  mark_state,        5) \
X(a, STATIC,   OPTIONAL, MESSAGE,  discovered_devices,   6)
#define SystemInfoPacket_CALLBACK NULL
#define SystemInfoPacket_DEFAULT NULL
#define SystemInfoPacket_simple_sensor_reading_MSGTYPE SimpleSensorReading
#define SystemInfoPacket_sdcard_state_MSGTYPE SDCardState
#define SystemInfoPacket_mark_state_MSGTYPE MarkState
#define SystemInfoPacket_discovered_devices_MSGTYPE DiscoveredDevices

#define AudioCompression_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, BOOL,     enabled,           1) \
X(a, STATIC,   SINGULAR, UINT32,   compression_factor,   2)
#define AudioCompression_CALLBACK NULL
#define AudioCompression_DEFAULT NULL

#define AudioConfig_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, BOOL,     channel_1,         1) \
X(a, STATIC,   SINGULAR, BOOL,     channel_2,         2) \
X(a, STATIC,   SINGULAR, UENUM,    sample_freq,       3) \
X(a, STATIC,   SINGULAR, UENUM,    bit_resolution,    4) \
X(a, STATIC,   OPTIONAL, MESSAGE,  audio_compression,   5)
#define AudioConfig_CALLBACK NULL
#define AudioConfig_DEFAULT NULL
#define AudioConfig_audio_compression_MSGTYPE AudioCompression

#define ScheduleConfig_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, BOOL,     Sunday,            1) \
X(a, STATIC,   SINGULAR, BOOL,     Monday,            2) \
X(a, STATIC,   SINGULAR, BOOL,     Tuesday,           3) \
X(a, STATIC,   SINGULAR, BOOL,     Wednesday,         4) \
X(a, STATIC,   SINGULAR, BOOL,     Thursday,          5) \
X(a, STATIC,   SINGULAR, BOOL,     Friday,            6) \
X(a, STATIC,   SINGULAR, BOOL,     Saturday,          7) \
X(a, STATIC,   SINGULAR, UINT32,   start_hour,        8) \
X(a, STATIC,   SINGULAR, UINT32,   start_minute,      9) \
X(a, STATIC,   SINGULAR, UINT32,   stop_hour,        10) \
X(a, STATIC,   SINGULAR, UINT32,   stop_minute,      11)
#define ScheduleConfig_CALLBACK NULL
#define ScheduleConfig_DEFAULT NULL

#define ConfigPacket_FIELDLIST(X, a) \
X(a, STATIC,   OPTIONAL, MESSAGE,  audio_config,      1) \
X(a, CALLBACK, REPEATED, MESSAGE,  schedule_config,   2) \
X(a, STATIC,   OPTIONAL, MESSAGE,  sensor_config,     3)
#define ConfigPacket_CALLBACK pb_default_field_callback
#define ConfigPacket_DEFAULT NULL
#define ConfigPacket_audio_config_MSGTYPE AudioConfig
#define ConfigPacket_schedule_config_MSGTYPE ScheduleConfig
#define ConfigPacket_sensor_config_MSGTYPE SensorConfig

#define SpecialFunction_FIELDLIST(X, a) \
X(a, STATIC,   ONEOF,    BOOL,     (payload,format_sdcard,payload.format_sdcard),   1) \
X(a, STATIC,   ONEOF,    BOOL,     (payload,function_2,payload.function_2),   2) \
X(a, STATIC,   ONEOF,    BOOL,     (payload,function_3,payload.function_3),   3) \
X(a, STATIC,   ONEOF,    BOOL,     (payload,function_4,payload.function_4),   4) \
X(a, STATIC,   ONEOF,    BOOL,     (payload,function_5,payload.function_5),   5) \
X(a, STATIC,   ONEOF,    BOOL,     (payload,function_6,payload.function_6),   6) \
X(a, STATIC,   ONEOF,    BOOL,     (payload,function_7,payload.function_7),   7) \
X(a, STATIC,   ONEOF,    BOOL,     (payload,function_8,payload.function_8),   8)
#define SpecialFunction_CALLBACK NULL
#define SpecialFunction_DEFAULT NULL

#define Packet_FIELDLIST(X, a) \
X(a, STATIC,   OPTIONAL, MESSAGE,  header,            1) \
X(a, STATIC,   ONEOF,    MESSAGE,  (payload,system_info_packet,payload.system_info_packet),   2) \
X(a, STATIC,   ONEOF,    MESSAGE,  (payload,mark_packet,payload.mark_packet),   3) \
X(a, STATIC,   ONEOF,    MESSAGE,  (payload,config_packet,payload.config_packet),   4) \
X(a, STATIC,   ONEOF,    MESSAGE,  (payload,special_function,payload.special_function),   5)
#define Packet_CALLBACK NULL
#define Packet_DEFAULT NULL
#define Packet_header_MSGTYPE PacketHeader
#define Packet_payload_system_info_packet_MSGTYPE SystemInfoPacket
#define Packet_payload_mark_packet_MSGTYPE MarkPacket
#define Packet_payload_config_packet_MSGTYPE ConfigPacket
#define Packet_payload_special_function_MSGTYPE SpecialFunction

extern const pb_msgdesc_t PacketHeader_msg;
extern const pb_msgdesc_t SimpleSensorReading_msg;
extern const pb_msgdesc_t SensorReading_msg;
extern const pb_msgdesc_t SensorReading_Payload_msg;
extern const pb_msgdesc_t SensorConfig_msg;
extern const pb_msgdesc_t SDCardState_msg;
extern const pb_msgdesc_t MarkState_msg;
extern const pb_msgdesc_t MarkPacket_msg;
extern const pb_msgdesc_t DiscoveredDevices_msg;
extern const pb_msgdesc_t DiscoveredDevices_Device_msg;
extern const pb_msgdesc_t SystemInfoPacket_msg;
extern const pb_msgdesc_t AudioCompression_msg;
extern const pb_msgdesc_t AudioConfig_msg;
extern const pb_msgdesc_t ScheduleConfig_msg;
extern const pb_msgdesc_t ConfigPacket_msg;
extern const pb_msgdesc_t SpecialFunction_msg;
extern const pb_msgdesc_t Packet_msg;

/* Defines for backwards compatibility with code written before nanopb-0.4.0 */
#define PacketHeader_fields &PacketHeader_msg
#define SimpleSensorReading_fields &SimpleSensorReading_msg
#define SensorReading_fields &SensorReading_msg
#define SensorReading_Payload_fields &SensorReading_Payload_msg
#define SensorConfig_fields &SensorConfig_msg
#define SDCardState_fields &SDCardState_msg
#define MarkState_fields &MarkState_msg
#define MarkPacket_fields &MarkPacket_msg
#define DiscoveredDevices_fields &DiscoveredDevices_msg
#define DiscoveredDevices_Device_fields &DiscoveredDevices_Device_msg
#define SystemInfoPacket_fields &SystemInfoPacket_msg
#define AudioCompression_fields &AudioCompression_msg
#define AudioConfig_fields &AudioConfig_msg
#define ScheduleConfig_fields &ScheduleConfig_msg
#define ConfigPacket_fields &ConfigPacket_msg
#define SpecialFunction_fields &SpecialFunction_msg
#define Packet_fields &Packet_msg

/* Maximum encoded size of messages (where known) */
/* SensorReading_size depends on runtime parameters */
/* DiscoveredDevices_size depends on runtime parameters */
/* SystemInfoPacket_size depends on runtime parameters */
/* ConfigPacket_size depends on runtime parameters */
/* Packet_size depends on runtime parameters */
#define AudioCompression_size                    8
#define AudioConfig_size                         18
#define DiscoveredDevices_Device_size            11
#define MarkPacket_size                          103
#define MarkState_size                           19
#define PacketHeader_size                        23
#define SDCardState_size                         24
#define ScheduleConfig_size                      38
#define SensorConfig_size                        12
#define SensorReading_Payload_size               41
#define SimpleSensorReading_size                 27
#define SpecialFunction_size                     2

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
