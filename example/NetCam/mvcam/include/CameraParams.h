
#ifndef _MV_CAMERA_PARAMS_H_
#define _MV_CAMERA_PARAMS_H_

#include "PixelType.h"

#ifndef __cplusplus
typedef char    bool;
#define true    1
#define false   0
#endif

/// \~chinese ?????                  \~english The Method of Sorting
typedef enum _MV_SORT_METHOD_
{
    SortMethod_SerialNumber   = 0,                  ///< \~chinese ????????????                     \~english Sorting by SerialNumber
    SortMethod_UserID         = 1,                  ///< \~chinese ??????????????????             \~english Sorting by UserID
    SortMethod_CurrentIP_ASC  = 2,                  ///< \~chinese ?????IP???????????         \~english Sorting by current IP??Ascending??
    SortMethod_CurrentIP_DESC = 3,                  ///< \~chinese ?????IP??????????         \~english Sorting by current IP??Descending??

}MV_SORT_METHOD;

/// \~chinese GigE??????              \~english GigE device info
typedef struct _MV_GIGE_DEVICE_INFO_
{
    unsigned int        nIpCfgOption;                               ///< [OUT] \~chinese IP???????             \~english IP Configuration Options
    unsigned int        nIpCfgCurrent;                              ///< [OUT] \~chinese ???IP????             \~english IP Configuration
    unsigned int        nCurrentIp;                                 ///< [OUT] \~chinese ???IP???             \~english Current Ip
    unsigned int        nCurrentSubNetMask;                         ///< [OUT] \~chinese ???????????           \~english Curtent Subnet Mask
    unsigned int        nDefultGateWay;                             ///< [OUT] \~chinese ???????               \~english Current Gateway
    unsigned char       chManufacturerName[32];                     ///< [OUT] \~chinese ??????????             \~english Manufacturer Name
    unsigned char       chModelName[32];                            ///< [OUT] \~chinese ???????               \~english Model Name
    unsigned char       chDeviceVersion[32];                        ///< [OUT] \~chinese ??????               \~english Device Version 
    unsigned char       chManufacturerSpecificInfo[48];             ///< [OUT] \~chinese ?????????????       \~english Manufacturer Specific Information
    unsigned char       chSerialNumber[16];                         ///< [OUT] \~chinese ??????                 \~english Serial Number
    unsigned char       chUserDefinedName[16];                      ///< [OUT] \~chinese ????????????         \~english User Defined Name 
    unsigned int        nNetExport;                                 ///< [OUT] \~chinese ????IP???             \~english NetWork IP Address

    unsigned int        nReserved[4];                               ///<       \~chinese ???                   \~english Reserved

}MV_GIGE_DEVICE_INFO;

///< \~chinese ???????????????       \~english Maximum data information size
#define INFO_MAX_BUFFER_SIZE            64

/// \~chinese USB??????               \~english USB device info
typedef struct _MV_USB3_DEVICE_INFO_
{
    unsigned char       CrtlInEndPoint;                             ///< [OUT] \~chinese ??????????           \~english Control input endpoint
    unsigned char       CrtlOutEndPoint;                            ///< [OUT] \~chinese ??????????           \~english Control output endpoint
    unsigned char       StreamEndPoint;                             ///< [OUT] \~chinese ?????                 \~english Flow endpoint
    unsigned char       EventEndPoint;                              ///< [OUT] \~chinese ??????               \~english Event endpoint
    unsigned short      idVendor;                                   ///< [OUT] \~chinese ?????ID??             \~english Vendor ID Number
    unsigned short      idProduct;                                  ///< [OUT] \~chinese ???ID??               \~english Device ID Number
    unsigned int        nDeviceNumber;                              ///< [OUT] \~chinese ?????????             \~english Device Number
    unsigned char       chDeviceGUID[INFO_MAX_BUFFER_SIZE];         ///< [OUT] \~chinese ???GUID??             \~english Device GUID Number
    unsigned char       chVendorName[INFO_MAX_BUFFER_SIZE];         ///< [OUT] \~chinese ?????????             \~english Vendor Name
    unsigned char       chModelName[INFO_MAX_BUFFER_SIZE];          ///< [OUT] \~chinese ???????               \~english Model Name
    unsigned char       chFamilyName[INFO_MAX_BUFFER_SIZE];         ///< [OUT] \~chinese ????????               \~english Family Name
    unsigned char       chDeviceVersion[INFO_MAX_BUFFER_SIZE];      ///< [OUT] \~chinese ??????               \~english Device Version
    unsigned char       chManufacturerName[INFO_MAX_BUFFER_SIZE];   ///< [OUT] \~chinese ??????????             \~english Manufacturer Name
    unsigned char       chSerialNumber[INFO_MAX_BUFFER_SIZE];       ///< [OUT] \~chinese ??????                 \~english Serial Number
    unsigned char       chUserDefinedName[INFO_MAX_BUFFER_SIZE];    ///< [OUT] \~chinese ????????????         \~english User Defined Name
    unsigned int        nbcdUSB;                                    ///< [OUT] \~chinese ????USB????          \~english Support USB Protocol
    unsigned int        nDeviceAddress;                             ///< [OUT] \~chinese ??????               \~english Device Address

    unsigned int        nReserved[2];                               ///<       \~chinese ???                   \~english Reserved

}MV_USB3_DEVICE_INFO;

/// \~chinese CameraLink??????        \~english CameraLink device info
typedef struct _MV_CamL_DEV_INFO_
{
    unsigned char       chPortID[INFO_MAX_BUFFER_SIZE];             ///< [OUT] \~chinese ????                 \~english Port ID
    unsigned char       chModelName[INFO_MAX_BUFFER_SIZE];          ///< [OUT] \~chinese ???????               \~english Model Name
    unsigned char       chFamilyName[INFO_MAX_BUFFER_SIZE];         ///< [OUT] \~chinese ????                   \~english Family Name
    unsigned char       chDeviceVersion[INFO_MAX_BUFFER_SIZE];      ///< [OUT] \~chinese ??????               \~english Device Version
    unsigned char       chManufacturerName[INFO_MAX_BUFFER_SIZE];   ///< [OUT] \~chinese ??????????             \~english Manufacturer Name
    unsigned char       chSerialNumber[INFO_MAX_BUFFER_SIZE];       ///< [OUT] \~chinese ??????                 \~english Serial Number

    unsigned int        nReserved[38];                              ///<       \~chinese ???                   \~english Reserved

}MV_CamL_DEV_INFO;

///< \~chinese ????????????????       \~english Device Transport Layer Protocol Type
#define MV_UNKNOW_DEVICE                0x00000000                  ///< \~chinese ???????????????????       \~english Unknown Device Type, Reserved 
#define MV_GIGE_DEVICE                  0x00000001                  ///< \~chinese GigE???                     \~english GigE Device
#define MV_1394_DEVICE                  0x00000002                  ///< \~chinese 1394-a/b ???                \~english 1394-a/b Device
#define MV_USB_DEVICE                   0x00000004                  ///< \~chinese USB ???                     \~english USB Device
#define MV_CAMERALINK_DEVICE            0x00000008                  ///< \~chinese CameraLink???               \~english CameraLink Device
#define MV_VIR_GIGE_DEVICE              0x00000010                  ///< \~chinese ????GigE???                 \~english Virtual GigE Device
#define MV_VIR_USB_DEVICE               0x00000020                  ///< \~chinese ????USB???                 \~english Virtual USB Device
#define MV_GENTL_GIGE_DEVICE            0x00000040                  ///< \~chinese ??????????GigE???          \~english GenTL GigE Device

/// \~chinese ??????                  \~english Device info
typedef struct _MV_CC_DEVICE_INFO_
{
    unsigned short          nMajorVer;                              ///< [OUT] \~chinese ??????               \~english Major Version
    unsigned short          nMinorVer;                              ///< [OUT] \~chinese ??????               \~english Minor Version
    unsigned int            nMacAddrHigh;                           ///< [OUT] \~chinese ??MAC???              \~english High MAC Address
    unsigned int            nMacAddrLow;                            ///< [OUT] \~chinese ??MAC???              \~english Low MAC Address
    unsigned int            nTLayerType;                            ///< [OUT] \~chinese ????????????????     \~english Device Transport Layer Protocol Type

    unsigned int            nReserved[4];                           ///<       \~chinese ???                   \~english Reserved

    union
    {
        MV_GIGE_DEVICE_INFO stGigEInfo;                             ///< [OUT] \~chinese GigE??????           \~english GigE Device Info
        MV_USB3_DEVICE_INFO stUsb3VInfo;                            ///< [OUT] \~chinese USB??????            \~english USB Device Info
        MV_CamL_DEV_INFO    stCamLInfo;                             ///< [OUT] \~chinese CameraLink??????     \~english CameraLink Device Info
        // more ...
    }SpecialInfo;

}MV_CC_DEVICE_INFO;

///< \~chinese ?????????????????? \~english The maximum number of supported transport layer instances
#define MV_MAX_TLS_NUM                  8
///< \~chinese ??????????????       \~english The maximum number of supported devices
#define MV_MAX_DEVICE_NUM               256

/// \~chinese ??????????              \~english Device Information List
typedef struct _MV_CC_DEVICE_INFO_LIST_
{
    unsigned int        nDeviceNum;                                 ///< [OUT] \~chinese ???????????           \~english Online Device Number
    MV_CC_DEVICE_INFO*  pDeviceInfo[MV_MAX_DEVICE_NUM];             ///< [OUT] \~chinese ??????256?????      \~english Support up to 256 devices

}MV_CC_DEVICE_INFO_LIST;

/// \~chinese ???GenTL??????????? \~english Interface Information with GenTL
typedef struct _MV_GENTL_IF_INFO_
{
    unsigned char       chInterfaceID[INFO_MAX_BUFFER_SIZE];        ///< [OUT] \~chinese GenTL???ID            \~english Interface ID
    unsigned char       chTLType[INFO_MAX_BUFFER_SIZE];             ///< [OUT] \~chinese ?????????             \~english GenTL Type
    unsigned char       chDisplayName[INFO_MAX_BUFFER_SIZE];        ///< [OUT] \~chinese Interface???????      \~english Display Name
    unsigned int        nCtiIndex;                                  ///< [OUT] \~chinese GenTL??cti???????     \~english The Index of Cti Files

    unsigned int        nReserved[8];                               ///<       \~chinese ???                   \~english Reserved

}MV_GENTL_IF_INFO;

///< \~chinese ???????GenTL???????  \~english The maximum number of GenTL interface supported
#define MV_MAX_GENTL_IF_NUM             256

/// \~chinese ???GenTL??????????????? \~english Inferface Information List with GenTL
typedef struct _MV_GENTL_IF_INFO_LIST_
{
    unsigned int        nInterfaceNum;                              ///< [OUT] \~chinese ??????????           \~english Online Inferface Number
    MV_GENTL_IF_INFO*   pIFInfo[MV_MAX_GENTL_IF_NUM];               ///< [OUT] \~chinese ??????256?????      \~english Support up to 256 inferfaces

}MV_GENTL_IF_INFO_LIST;

/// \~chinese ???GenTL???????????? \~english Device Information with GenTL
typedef struct _MV_GENTL_DEV_INFO_
{
    unsigned char       chInterfaceID[INFO_MAX_BUFFER_SIZE];        ///< [OUT] \~chinese GenTL???ID            \~english Interface ID
    unsigned char       chDeviceID[INFO_MAX_BUFFER_SIZE];           ///< [OUT] \~chinese ???ID                 \~english Device ID
    unsigned char       chVendorName[INFO_MAX_BUFFER_SIZE];         ///< [OUT] \~chinese ?????????             \~english Vendor Name
    unsigned char       chModelName[INFO_MAX_BUFFER_SIZE];          ///< [OUT] \~chinese ???????               \~english Model Name
    unsigned char       chTLType[INFO_MAX_BUFFER_SIZE];             ///< [OUT] \~chinese ?????????             \~english GenTL Type
    unsigned char       chDisplayName[INFO_MAX_BUFFER_SIZE];        ///< [OUT] \~chinese ??????????           \~english Display Name
    unsigned char       chUserDefinedName[INFO_MAX_BUFFER_SIZE];    ///< [OUT] \~chinese ????????????         \~english User Defined Name
    unsigned char       chSerialNumber[INFO_MAX_BUFFER_SIZE];       ///< [OUT] \~chinese ??????                 \~english Serial Number
    unsigned char       chDeviceVersion[INFO_MAX_BUFFER_SIZE];      ///< [OUT] \~chinese ????????             \~english Device Version
    unsigned int        nCtiIndex;                                  ///< [OUT] \~chinese GenTL??cti???????     \~english The Index of Cti Files

    unsigned int        nReserved[8];                               ///<       \~chinese ???                   \~english Reserved

}MV_GENTL_DEV_INFO;

///< \~chinese ???????GenTL???????  \~english The maximum number of GenTL devices supported
#define MV_MAX_GENTL_DEV_NUM            256

/// \~chinese ???GenTL???????????????? \~english Device Information List with GenTL
typedef struct _MV_GENTL_DEV_INFO_LIST_
{
    unsigned int        nDeviceNum;                                 ///< [OUT] \~chinese ???????????           \~english Online Device Number
    MV_GENTL_DEV_INFO*  pDeviceInfo[MV_MAX_GENTL_DEV_NUM];          ///< [OUT] \~chinese ??????256?????      \~english Support up to 256 devices

}MV_GENTL_DEV_INFO_LIST;

/// \~chinese ??????????            \~english Device Access Mode
#define MV_ACCESS_Exclusive                     1                   /// \~chinese ???????????APP???????CCP?????                    \~english Exclusive authority, other APP is only allowed to read the CCP register
#define MV_ACCESS_ExclusiveWithSwitch           2                   /// \~chinese ?????5??????????????????????             \~english You can seize the authority from the 5 mode, and then open with exclusive authority
#define MV_ACCESS_Control                       3                   /// \~chinese ????????????APP???????????????                     \~english Control authority, allows other APP reading all registers
#define MV_ACCESS_ControlWithSwitch             4                   /// \~chinese ?????5?????????????????????????           \~english You can seize the authority from the 5 mode, and then open with control authority
#define MV_ACCESS_ControlSwitchEnable           5                   /// \~chinese ????????????????                              \~english Open with seized control authority
#define MV_ACCESS_ControlSwitchEnableWithKey    6                   /// \~chinese ?????5???????????????????????????????? \~english You can seize the authority from the 5 mode, and then open with seized control authority
#define MV_ACCESS_Monitor                       7                   /// \~chinese ?????????????????????????                      \~english Open with read mode and is available under control authority

/// \~chinese Chunk????                 \~english The content of ChunkData
typedef struct _MV_CHUNK_DATA_CONTENT_
{
    unsigned char*      pChunkData;                                 ///< [OUT] \~chinese Chunk????              \~english Chunk Data
    unsigned int        nChunkID;                                   ///< [OUT] \~chinese Chunk ID               \~english Chunk ID
    unsigned int        nChunkLen;                                  ///< [OUT] \~chinese Chunk?????            \~english Chunk Length

    unsigned int        nReserved[8];                               ///<       \~chinese ???                   \~english Reserved

}MV_CHUNK_DATA_CONTENT;


/// \~chinese ?????????              \~english Output Frame Information
typedef struct _MV_FRAME_OUT_INFO_EX_
{
    unsigned short          nWidth;                                 ///< [OUT] \~chinese ????(???65535??????????nExtendWidth)    \~english Image Width (over 65535, use nExtendWidth)
    unsigned short          nHeight;                                ///< [OUT] \~chinese ????(???65535??????????nExtendHeight)   \~english Image Height(over 65535, use nExtendHeight)
    enum MvGvspPixelType    enPixelType;                            ///< [OUT] \~chinese ??????               \~english Pixel Type

    unsigned int            nFrameNum;                              ///< [OUT] \~chinese ???                   \~english Frame Number
    unsigned int            nDevTimeStampHigh;                      ///< [OUT] \~chinese ??????32??           \~english Timestamp high 32 bits
    unsigned int            nDevTimeStampLow;                       ///< [OUT] \~chinese ??????32??           \~english Timestamp low 32 bits
    unsigned int            nReserved0;                             ///< [OUT] \~chinese ??????8??????        \~english Reserved, 8-byte aligned
    int64_t                 nHostTimeStamp;                         ///< [OUT] \~chinese ?????????????       \~english Host-generated timestamp

    unsigned int            nFrameLen;                              ///< [OUT] \~chinese ??????               \~english The Length of Frame

    /// \~chinese ????????      \~english Device frame-specific time scale
    unsigned int            nSecondCount;                           ///< [OUT] \~chinese ????                   \~english The Seconds
    unsigned int            nCycleCount;                            ///< [OUT] \~chinese ??????                 \~english The Count of Cycle
    unsigned int            nCycleOffset;                           ///< [OUT] \~chinese ?????????             \~english The Offset of Cycle

    float                   fGain;                                  ///< [OUT] \~chinese ????                   \~english Gain
    float                   fExposureTime;                          ///< [OUT] \~chinese ??????               \~english Exposure Time
    unsigned int            nAverageBrightness;                     ///< [OUT] \~chinese ???????               \~english Average brightness

    /// \~chinese ????????        \~english White balance
    unsigned int            nRed;                                   ///< [OUT] \~chinese ???                   \~english Red
    unsigned int            nGreen;                                 ///< [OUT] \~chinese ???                   \~english Green
    unsigned int            nBlue;                                  ///< [OUT] \~chinese ???                   \~english Blue

    unsigned int            nFrameCounter;                          ///< [OUT] \~chinese ?????                 \~english Frame Counter
    unsigned int            nTriggerIndex;                          ///< [OUT] \~chinese ????????               \~english Trigger Counting

    unsigned int            nInput;                                 ///< [OUT] \~chinese ????                   \~english Input
    unsigned int            nOutput;                                ///< [OUT] \~chinese ???                   \~english Output

    /// \~chinese ROI????           \~english ROI Region
    unsigned short          nOffsetX;                               ///< [OUT] \~chinese ???????             \~english OffsetX
    unsigned short          nOffsetY;                               ///< [OUT] \~chinese ????????             \~english OffsetY
    unsigned short          nChunkWidth;                            ///< [OUT] \~chinese Chunk??                \~english The Width of Chunk
    unsigned short          nChunkHeight;                           ///< [OUT] \~chinese Chunk??                \~english The Height of Chunk

    unsigned int            nLostPacket;                            ///< [OUT] \~chinese ?????????             \~english Lost Packet Number In This Frame

    unsigned int            nUnparsedChunkNum;                      ///< [OUT] \~chinese ????????Chunkdata????  \~english Unparsed Chunk Number
    union
    {
        MV_CHUNK_DATA_CONTENT*  pUnparsedChunkContent;              ///< [OUT] \~chinese ????????Chunk          \~english Unparsed Chunk Content
        int64_t                 nAligning;                          ///< [OUT] \~chinese ???                   \~english Aligning
    }UnparsedChunkList;

    unsigned int            nExtendWidth;                           ///< [OUT] \~chinese ????(???????)       \~english Image Width
    unsigned int            nExtendHeight;                          ///< [OUT] \~chinese ????(???????)       \~english Image Height

    unsigned int            nReserved[34];                          ///<       \~chinese ???                   \~english Reserved

}MV_FRAME_OUT_INFO_EX;

/// \~chinese ???????????????????????    \~english Image Struct, output the pointer of Image and the information of the specific image
typedef struct _MV_FRAME_OUT_
{
    unsigned char*          pBufAddr;                               ///< [OUT] \~chinese ????????           \~english  pointer of image
    MV_FRAME_OUT_INFO_EX    stFrameInfo;                            ///< [OUT] \~chinese ??????               \~english information of the specific image

    unsigned int            nRes[16];                               ///<       \~chinese ???                   \~english Reserved

}MV_FRAME_OUT;

/// \~chinese ???????                  \~english The strategy of Grabbing
typedef enum _MV_GRAB_STRATEGY_
{
    MV_GrabStrategy_OneByOne            = 0,                        ///< \~chinese ?????????????????   \~english Grab One By One
    MV_GrabStrategy_LatestImagesOnly    = 1,                        ///< \~chinese ???????????????????     \~english Grab The Latest Image
    MV_GrabStrategy_LatestImages        = 2,                        ///< \~chinese ?????????????????         \~english Grab The Latest Images
    MV_GrabStrategy_UpcomingImage       = 3,                        ///< \~chinese ??????????               \~english Grab The Upcoming Image

}MV_GRAB_STRATEGY;

/// \~chinese ??????????????        \~english Network transmission information
typedef struct _MV_NETTRANS_INFO_
{
    int64_t             nReceiveDataSize;                           ///< [OUT] \~chinese ????????????[Start??Stop???]    \~english Received Data Size
    int                 nThrowFrameCount;                           ///< [OUT] \~chinese ???????                           \~english Throw frame number
    unsigned int        nNetRecvFrameCount;                         ///< [OUT] \~chinese ?????????                       \~english Received Frame Count
    int64_t             nRequestResendPacketCount;                  ///< [OUT] \~chinese ???????????                       \~english Request Resend Packet Count
    int64_t             nResendPacketCount;                         ///< [OUT] \~chinese ???????                           \~english Resend Packet Count

}MV_NETTRANS_INFO;

/// \~chinese ???????                  \~english Information Type
#define MV_MATCH_TYPE_NET_DETECT        0x00000001                  ///< \~chinese ????????????????               \~english Network traffic and packet loss information
#define MV_MATCH_TYPE_USB_DETECT        0x00000002                  ///< \~chinese host?????????U3V????????????  \~english The total number of bytes host received from U3V device

/// \~chinese ???????????????    \~english A fully matched information structure
typedef struct _MV_ALL_MATCH_INFO_
{
    unsigned int        nType;                                      ///< [IN]  \~chinese ????????????????e.g. MV_MATCH_TYPE_NET_DETECT  \~english Information type need to output ,e.g. MV_MATCH_TYPE_NET_DETECT
    void*               pInfo;                                      ///< [OUT] \~chinese ??????????????????????                       \~english Output information cache, which is allocated by the caller
    unsigned int        nInfoSize;                                  ///< [IN]  \~chinese ???????????                                     \~english Information cache size

}MV_ALL_MATCH_INFO;

/// \~chinese ????????????????????????????????? MV_MATCH_TYPE_NET_DETECT     \~english Network traffic and packet loss feedback structure, the corresponding type is MV_MATCH_TYPE_NET_DETECT
typedef struct _MV_MATCH_INFO_NET_DETECT_
{
    int64_t             nReceiveDataSize;                           ///< [OUT] \~chinese ????????????[Start??Stop???]    \~english Received data size 
    int64_t             nLostPacketCount;                           ///< [OUT] \~chinese ??????????                       \~english Number of packets lost
    unsigned int        nLostFrameCount;                            ///< [OUT] \~chinese ???????                           \~english Number of frames lost
    unsigned int        nNetRecvFrameCount;                         ///< [OUT] \~chinese ????                               \~english Received Frame Count
    int64_t             nRequestResendPacketCount;                  ///< [OUT] \~chinese ???????????                       \~english Request Resend Packet Count
    int64_t             nResendPacketCount;                         ///< [OUT] \~chinese ???????                           \~english Resend Packet Count

}MV_MATCH_INFO_NET_DETECT;

/// \~chinese host?????u3v??????????????????????? MV_MATCH_TYPE_USB_DETECT    \~english The total number of bytes host received from the u3v device side, the corresponding type is MV_MATCH_TYPE_USB_DETECT
typedef struct _MV_MATCH_INFO_USB_DETECT_
{
    int64_t             nReceiveDataSize;                           ///< [OUT] \~chinese ???????????? [Open??Close???]   \~english Received data size
    unsigned int        nReceivedFrameCount;                        ///< [OUT] \~chinese ??????????                       \~english Number of frames received
    unsigned int        nErrorFrameCount;                           ///< [OUT] \~chinese ???????                           \~english Number of error frames

    unsigned int        nReserved[2];                               ///<       \~chinese ????                               \~english Reserved

}MV_MATCH_INFO_USB_DETECT;

/// \~chinese ???????                \~english Display frame information
typedef struct _MV_DISPLAY_FRAME_INFO_
{
    void*                   hWnd;                                   ///< [IN] \~chinese ??????                \~english HWND
    unsigned char*          pData;                                  ///< [IN] \~chinese ?????????              \~english Data Buffer
    unsigned int            nDataLen;                               ///< [IN] \~chinese ???????                \~english Data Size
    unsigned short          nWidth;                                 ///< [IN] \~chinese ????                  \~english Width
    unsigned short          nHeight;                                ///< [IN] \~chinese ????                  \~english Height
    enum MvGvspPixelType    enPixelType;                            ///< [IN] \~chinese ??????                \~english Pixel format

    unsigned int            nRes[4];                                ///<      \~chinese ????                    \~english Reserved

}MV_DISPLAY_FRAME_INFO;


typedef struct _MV_DISPLAY_FRAME_INFO_EX_
{
    unsigned int            nWidth;                                 ///< [IN]   \~chinese ????                \~english Width
    unsigned int            nHeight;                                ///< [IN]   \~chinese ????                \~english Height
    enum MvGvspPixelType    enPixelType;                            ///< [IN]   \~chinese ??????              \~english Pixel type

    unsigned char*          pImageBuf;                              ///< [IN]   \~chinese ????????          \~english Input image buffer
    unsigned int            nImageBufLen;                           ///< [IN]   \~chinese ????????          \~english Input image length

    unsigned int            nRes[4];                                ///<      \~chinese ????                    \~english Reserved

}MV_DISPLAY_FRAME_INFO_EX;

/// \~chinese ?????3D??????          \~english The saved format for 3D data
enum MV_SAVE_POINT_CLOUD_FILE_TYPE
{
    MV_PointCloudFile_Undefined         = 0,                        ///< \~chinese ????????????             \~english Undefined point cloud format
    MV_PointCloudFile_PLY               = 1,                        ///< \~chinese PLY??????                  \~english The point cloud format named PLY
    MV_PointCloudFile_CSV               = 2,                        ///< \~chinese CSV??????                  \~english The point cloud format named CSV
    MV_PointCloudFile_OBJ               = 3,                        ///< \~chinese OBJ??????                  \~english The point cloud format named OBJ

};

/// \~chinese ????3D?????????          \~english Save 3D data to buffer
typedef struct _MV_SAVE_POINT_CLOUD_PARAM_
{
    unsigned int                    nLinePntNum;                    ///< [IN]  \~chinese ??????????????       \~english The number of points in each row,which is the width of the image
    unsigned int                    nLineNum;                       ///< [IN]  \~chinese ????????????         \~english The number of rows,which is the height of the image

    enum MvGvspPixelType            enSrcPixelType;                 ///< [IN]  \~chinese ???????????????     \~english The pixel format of the input data
    unsigned char*                  pSrcData;                       ///< [IN]  \~chinese ???????????           \~english Input data buffer
    unsigned int                    nSrcDataLen;                    ///< [IN]  \~chinese ???????????           \~english Input data length

    unsigned char*                  pDstBuf;                        ///< [OUT] \~chinese ??????????????       \~english Output pixel data buffer
    unsigned int                    nDstBufSize;                    ///< [IN]  \~chinese ?????????????????(nLinePntNum * nLineNum * (16*3 + 4) + 2048)   \~english Output buffer size provided(nLinePntNum * nLineNum * (16*3 + 4) + 2048) 
    unsigned int                    nDstBufLen;                     ///< [OUT] \~chinese ????????????????   \~english Output pixel data buffer size
    MV_SAVE_POINT_CLOUD_FILE_TYPE   enPointCloudFileType;           ///< [IN]  \~chinese ????????????????? \~english Output point data file type provided

    unsigned int        nReserved[8];                               ///<       \~chinese ???????               \~english Reserved

}MV_SAVE_POINT_CLOUD_PARAM;

/// \~chinese ?????????              \~english Save image type
enum MV_SAVE_IAMGE_TYPE
{
    MV_Image_Undefined                  = 0,                        ///< \~chinese ????????????             \~english Undefined Image Type
    MV_Image_Bmp                        = 1,                        ///< \~chinese BMP?????                  \~english BMP Image Type
    MV_Image_Jpeg                       = 2,                        ///< \~chinese JPEG?????                 \~english Jpeg Image Type
    MV_Image_Png                        = 3,                        ///< \~chinese PNG?????                  \~english Png  Image Type
    MV_Image_Tif                        = 4,                        ///< \~chinese TIFF?????                 \~english TIFF Image Type

};

/// \~chinese ?????????              \~english Save Image Parameters
typedef struct _MV_SAVE_IMAGE_PARAM_EX3_
{
    unsigned char*          pData;                                  ///< [IN]  \~chinese ???????????           \~english Input Data Buffer
    unsigned int            nDataLen;                               ///< [IN]  \~chinese ???????????           \~english Input Data length
    enum MvGvspPixelType    enPixelType;                            ///< [IN]  \~chinese ???????????????     \~english Input Data Pixel Format
    unsigned int          nWidth;                                   ///< [IN]  \~chinese ????                 \~english Image Width
    unsigned int          nHeight;                                  ///< [IN]  \~chinese ????                 \~english Image Height

    unsigned char*          pImageBuffer;                           ///< [OUT] \~chinese ?????????           \~english Output Image Buffer
    unsigned int            nImageLen;                              ///< [OUT] \~chinese ?????????           \~english Output Image length
    unsigned int            nBufferSize;                            ///< [IN]  \~chinese ?????????????????   \~english Output buffer size provided
    enum MV_SAVE_IAMGE_TYPE enImageType;                            ///< [IN]  \~chinese ????????           \~english Output Image Format
    unsigned int            nJpgQuality;                            ///< [IN]  \~chinese JPG????????(50-99]?????????????   \~english Encoding quality(50-99]??Other formats are invalid


    unsigned int            iMethodValue;                           ///< [IN]  \~chinese ??????? 0-???? 1-???? 2-???????????????????  \~english Bayer interpolation method  0-Fast 1-Equilibrium 2-Optimal

    unsigned int            nReserved[3];                           ///<       \~chinese ???                   \~english Reserved

}MV_SAVE_IMAGE_PARAM_EX3;


// ???????????????
typedef struct _MV_SAVE_IMAGE_TO_FILE_PARAM_EX_
{
    unsigned int        nWidth;             // [IN]     ????
    unsigned int        nHeight;            // [IN]     ????
    MvGvspPixelType     enPixelType;        // [IN]     ???????????????
    unsigned char*      pData;              // [IN]     ???????????
    unsigned int        nDataLen;           // [IN]     ???????????

    MV_SAVE_IAMGE_TYPE  enImageType;        // [IN]     ?????????
    char*               pcImagePath;        // [IN]     ??????????

    unsigned int        nQuality;           // [IN]     JPG????????(50-99]??PNG????????[0-9]
    int                 iMethodValue;       // [IN]     ??????? 0-???? 1-???? 2-??????????????????? 
    unsigned int        nReserved[8];

}MV_SAVE_IMAGE_TO_FILE_PARAM_EX;


/// \~chinese ??????                  \~english Rotation angle
typedef enum _MV_IMG_ROTATION_ANGLE_
{
    MV_IMAGE_ROTATE_90                  = 1,
    MV_IMAGE_ROTATE_180                 = 2,
    MV_IMAGE_ROTATE_270                 = 3,

}MV_IMG_ROTATION_ANGLE;

/// \~chinese ??????????            \~english Rotate image structure
typedef struct _MV_CC_ROTATE_IMAGE_PARAM_T_
{
    enum MvGvspPixelType    enPixelType;                            ///< [IN]  \~chinese ??????               \~english Pixel format
    unsigned int            nWidth;                                 ///< [IN][OUT] \~chinese ????             \~english Width
    unsigned int            nHeight;                                ///< [IN][OUT] \~chinese ????             \~english Height

    unsigned char*          pSrcData;                               ///< [IN]  \~chinese ???????????           \~english Input data buffer
    unsigned int            nSrcDataLen;                            ///< [IN]  \~chinese ???????????           \~english Input data length

    unsigned char*          pDstBuf;                                ///< [OUT] \~chinese ??????????           \~english Output data buffer
    unsigned int            nDstBufLen;                             ///< [OUT] \~chinese ??????????           \~english Output data length
    unsigned int            nDstBufSize;                            ///< [IN]  \~chinese ?????????????????   \~english Provided output buffer size

    MV_IMG_ROTATION_ANGLE   enRotationAngle;                        ///< [IN]  \~chinese ??????               \~english Rotation angle

    unsigned int            nRes[8];                                ///<       \~chinese ???                   \~english Reserved

}MV_CC_ROTATE_IMAGE_PARAM;

/// \~chinese ???????                  \~english Flip type
typedef enum _MV_IMG_FLIP_TYPE_
{
    MV_FLIP_VERTICAL                    = 1,
    MV_FLIP_HORIZONTAL                  = 2,

}MV_IMG_FLIP_TYPE;

/// \~chinese ????????            \~english Flip image structure
typedef struct _MV_CC_FLIP_IMAGE_PARAM_T_
{
    enum MvGvspPixelType    enPixelType;                            ///< [IN]  \~chinese ??????               \~english Pixel format
    unsigned int            nWidth;                                 ///< [IN]  \~chinese ????                 \~english Width
    unsigned int            nHeight;                                ///< [IN]  \~chinese ????                 \~english Height

    unsigned char*          pSrcData;                               ///< [IN]  \~chinese ???????????           \~english Input data buffer
    unsigned int            nSrcDataLen;                            ///< [IN]  \~chinese ???????????           \~english Input data length

    unsigned char*          pDstBuf;                                ///< [OUT] \~chinese ??????????           \~english Output data buffer
    unsigned int            nDstBufLen;                             ///< [OUT] \~chinese ??????????           \~english Output data length
    unsigned int            nDstBufSize;                            ///< [IN]  \~chinese ?????????????????   \~english Provided output buffer size

    MV_IMG_FLIP_TYPE        enFlipType;                             ///< [IN]  \~chinese ???????               \~english Flip type

    unsigned int            nRes[8];                                ///<       \~chinese ???                   \~english Reserved

}MV_CC_FLIP_IMAGE_PARAM;


/// \~chinese ???????????            \~english Pixel convert structure
typedef struct _MV_CC_PIXEL_CONVERT_PARAM_EX_
{
    unsigned int            nWidth;                                 ///< [IN]  \~chinese ????                 \~english Width
    unsigned int            nHeight;                                ///< [IN]  \~chinese ????                 \~english Height

    enum MvGvspPixelType    enSrcPixelType;                         ///< [IN]  \~chinese ???????             \~english Source pixel format
    unsigned char*          pSrcData;                               ///< [IN]  \~chinese ???????????           \~english Input data buffer
    unsigned int            nSrcDataLen;                            ///< [IN]  \~chinese ???????????           \~english Input data length

    enum MvGvspPixelType    enDstPixelType;                         ///< [IN]  \~chinese ?????????           \~english Destination pixel format
    unsigned char*          pDstBuffer;                             ///< [OUT] \~chinese ??????????           \~english Output data buffer
    unsigned int            nDstLen;                                ///< [OUT] \~chinese ??????????           \~english Output data length
    unsigned int            nDstBufferSize;                         ///< [IN]  \~chinese ?????????????????   \~english Provided output buffer size

    unsigned int            nRes[4];                                ///<       \~chinese ???                   \~english Reserved

}MV_CC_PIXEL_CONVERT_PARAM_EX;





/// \~chinese Gamma????                 \~english Gamma type
typedef enum _MV_CC_GAMMA_TYPE_
{
    MV_CC_GAMMA_TYPE_NONE               = 0,                        ///< \~chinese ??????                       \~english Disable
    MV_CC_GAMMA_TYPE_VALUE              = 1,                        ///< \~chinese Gamma?                      \~english Gamma value
    MV_CC_GAMMA_TYPE_USER_CURVE         = 2,                        ///< \~chinese Gamma????                    \~english Gamma curve
                                                                    ///< \~chinese 8??,?????256*sizeof(unsigned char)      \~english 8bit,length:256*sizeof(unsigned char)
                                                                    ///< \~chinese 10??,?????1024*sizeof(unsigned short)   \~english 10bit,length:1024*sizeof(unsigned short)
                                                                    ///< \~chinese 12??,?????4096*sizeof(unsigned short)   \~english 12bit,length:4096*sizeof(unsigned short)
                                                                    ///< \~chinese 16??,?????65536*sizeof(unsigned short)  \~english 16bit,length:65536*sizeof(unsigned short)
    MV_CC_GAMMA_TYPE_LRGB2SRGB          = 3,                        ///< \~chinese linear RGB to sRGB           \~english linear RGB to sRGB
    MV_CC_GAMMA_TYPE_SRGB2LRGB          = 4,                        ///< \~chinese sRGB to linear RGB(????????????????????????) \~english sRGB to linear RGB

}MV_CC_GAMMA_TYPE;

// Gamma???
/// \~chinese Gamma???????           \~english Gamma info structure
typedef struct _MV_CC_GAMMA_PARAM_T_
{
    MV_CC_GAMMA_TYPE    enGammaType;                                ///< [IN]  \~chinese Gamma????              \~english Gamma type
    float               fGammaValue;                                ///< [IN]  \~chinese Gamma?:0.1 ~ 4.0       \~english Gamma value:0.1 ~ 4.0
    unsigned char*      pGammaCurveBuf;                             ///< [IN]  \~chinese Gamma???????          \~english Gamma curve buffer
    unsigned int        nGammaCurveBufLen;                          ///< [IN]  \~chinese Gamma???????          \~english Gamma curve buffer size

    unsigned int        nRes[8];                                    ///<       \~chinese ???                   \~english Reserved

}MV_CC_GAMMA_PARAM;

/// \~chinese CCM????                   \~english CCM param
typedef struct _MV_CC_CCM_PARAM_T_
{
    bool                bCCMEnable;                                 ///< [IN]  \~chinese ???????CCM            \~english CCM enable
    int                 nCCMat[9];                                  ///< [IN]  \~chinese CCM????(-8192~8192)    \~english Color correction matrix(-8192~8192)

    unsigned int        nRes[8];                                    ///<       \~chinese ???                   \~english Reserved

}MV_CC_CCM_PARAM;

/// \~chinese CCM????                   \~english CCM param
typedef struct _MV_CC_CCM_PARAM_EX_T_
{
    bool                bCCMEnable;                                 ///< [IN]  \~chinese ???????CCM            \~english CCM enable
    int                 nCCMat[9];                                  ///< [IN]  \~chinese CCM????(-65536~65536)  \~english Color correction matrix(-65536~65536)
    unsigned int        nCCMScale;                                  ///< [IN]  \~chinese ?????????2????????,???65536??    \~english Quantitative scale(Integer power of 2, <= 65536)

    unsigned int        nRes[8];                                    ///<       \~chinese ???                   \~english Reserved

}MV_CC_CCM_PARAM_EX;

/// \~chinese ??????????          \~english Contrast structure
typedef struct _MV_CC_CONTRAST_PARAM_T_
{
    unsigned int            nWidth;                                 ///< [IN]  \~chinese ??????(????8)        \~english Image Width
    unsigned int            nHeight;                                ///< [IN]  \~chinese ?????(????8)        \~english Image Height
    unsigned char*          pSrcBuf;                                ///< [IN]  \~chinese ???????????           \~english Input data buffer
    unsigned int            nSrcBufLen;                             ///< [IN]  \~chinese ???????????           \~english Input data length
    enum MvGvspPixelType    enPixelType;                            ///< [IN]  \~chinese ??????               \~english Pixel format

    unsigned char*          pDstBuf;                                ///< [OUT] \~chinese ??????????           \~english Output data buffer
    unsigned int            nDstBufSize;                            ///< [IN]  \~chinese ?????????????????   \~english Provided output buffer size
    unsigned int            nDstBufLen;                             ///< [OUT] \~chinese ??????????           \~english Output data length

    unsigned int            nContrastFactor;                        ///< [IN]  \~chinese ???????[1,10000]     \~english Contrast factor,[1,10000]

    unsigned int            nRes[8];                                ///<       \~chinese ???                   \~english Reserved

}MV_CC_CONTRAST_PARAM;

/// \~chinese ?????                  \~english  Frame-specific information
typedef struct _MV_CC_FRAME_SPEC_INFO_
{
    /// \~chinese ????????      \~english Device frame-specific time scale
    unsigned int        nSecondCount;                               ///< [OUT] \~chinese ????                   \~english The Seconds
    unsigned int        nCycleCount;                                ///< [OUT] \~chinese ??????                 \~english The Count of Cycle
    unsigned int        nCycleOffset;                               ///< [OUT] \~chinese ?????????             \~english The Offset of Cycle

    float               fGain;                                      ///< [OUT] \~chinese ????                   \~english Gain
    float               fExposureTime;                              ///< [OUT] \~chinese ??????               \~english Exposure Time
    unsigned int        nAverageBrightness;                         ///< [OUT] \~chinese ???????               \~english Average brightness

    /// \~chinese ????????        \~english White balance
    unsigned int        nRed;                                       ///< [OUT] \~chinese ???                   \~english Red
    unsigned int        nGreen;                                     ///< [OUT] \~chinese ???                   \~english Green
    unsigned int        nBlue;                                      ///< [OUT] \~chinese ???                   \~english Blue

    unsigned int        nFrameCounter;                              ///< [OUT] \~chinese ?????                 \~english Frame Counter
    unsigned int        nTriggerIndex;                              ///< [OUT] \~chinese ????????               \~english Trigger Counting

    unsigned int        nInput;                                     ///< [OUT] \~chinese ????                   \~english Input
    unsigned int        nOutput;                                    ///< [OUT] \~chinese ???                   \~english Output

    /// \~chinese ROI????           \~english ROI Region
    unsigned short      nOffsetX;                                   ///< [OUT] \~chinese ???????             \~english OffsetX
    unsigned short      nOffsetY;                                   ///< [OUT] \~chinese ????????             \~english OffsetY
    unsigned short      nFrameWidth;                                ///< [OUT] \~chinese ????                 \~english The Width of Chunk
    unsigned short      nFrameHeight;                               ///< [OUT] \~chinese ????                 \~english The Height of Chunk

    unsigned int        nReserved[16];                              ///<       \~chinese ???                   \~english Reserved

}MV_CC_FRAME_SPEC_INFO;

/// \~chinese ??????????              \~english High Bandwidth decode structure
typedef struct _MV_CC_HB_DECODE_PARAM_T_
{
    unsigned char*          pSrcBuf;                                ///< [IN]  \~chinese ???????????           \~english Input data buffer
    unsigned int            nSrcLen;                                ///< [IN]  \~chinese ???????????           \~english Input data size

    unsigned int            nWidth;                                 ///< [OUT] \~chinese ????                 \~english Width
    unsigned int            nHeight;                                ///< [OUT] \~chinese ????                 \~english Height
    unsigned char*          pDstBuf;                                ///< [OUT] \~chinese ??????????           \~english Output data buffer
    unsigned int            nDstBufSize;                            ///< [IN]  \~chinese ?????????????????   \~english Provided output buffer size
    unsigned int            nDstBufLen;                             ///< [OUT] \~chinese ??????????           \~english Output data size
    enum MvGvspPixelType    enDstPixelType;                         ///< [OUT] \~chinese ???????????         \~english Output pixel format

    MV_CC_FRAME_SPEC_INFO   stFrameSpecInfo;                        ///< [OUT] \~chinese ?????               \~english Frame Spec Info

    unsigned int            nRes[8];                                ///<       \~chinese ???                   \~english Reserved

}MV_CC_HB_DECODE_PARAM;

/// \~chinese ?????????              \~english Record Format Type
typedef enum _MV_RECORD_FORMAT_TYPE_
{
    MV_FormatType_Undefined             = 0,                        ///< \~chinese ????????????             \~english Undefined Recode Format Type
    MV_FormatType_AVI                   = 1,                        ///< \~chinese AVI?????                  \~english AVI Recode Format Type

}MV_RECORD_FORMAT_TYPE;

/// \~chinese ??????                  \~english Record Parameters
typedef struct _MV_CC_RECORD_PARAM_T_
{
    enum MvGvspPixelType    enPixelType;                            ///< [IN]  \~chinese ???????????????     \~english Pixel Type

    unsigned short          nWidth;                                 ///< [IN]  \~chinese ????(2?????)        \~english Width
    unsigned short          nHeight;                                ///< [IN]  \~chinese ????(2?????)        \~english Height

    float                   fFrameRate;                             ///< [IN]  \~chinese ???fps(????1/16)      \~english The Rate of Frame
    unsigned int            nBitRate;                               ///< [IN]  \~chinese ????kbps(128-16*1024)  \~english The Rate of Bitrate

    MV_RECORD_FORMAT_TYPE   enRecordFmtType;                        ///< [IN]  \~chinese ?????               \~english Recode Format Type

    char*                   strFilePath;                            ///< [IN]  \~chinese ????????????(??????????????????????utf-8)  \~english File Path

    unsigned int            nRes[8];                                ///<       \~chinese ???                   \~english Reserved

}MV_CC_RECORD_PARAM;

/// \~chinese ????????????            \~english Input Data
typedef struct _MV_CC_INPUT_FRAME_INFO_T_
{
    unsigned char*      pData;                                      ///< [IN]  \~chinese ??????????           \~english Record Data
    unsigned int        nDataLen;                                   ///< [IN]  \~chinese ??????               \~english The Length of Record Data

    unsigned int        nRes[8];                                    ///<       \~chinese ???                   \~english Reserved

}MV_CC_INPUT_FRAME_INFO;

/// \~chinese ?????                  \~english Acquisition mode
typedef enum _MV_CAM_ACQUISITION_MODE_
{
    MV_ACQ_MODE_SINGLE                  = 0,                        ///< \~chinese ?????                     \~english Single Mode
    MV_ACQ_MODE_MUTLI                   = 1,                        ///< \~chinese ?????                     \~english Multi Mode
    MV_ACQ_MODE_CONTINUOUS              = 2,                        ///< \~chinese ?????????                 \~english Continuous Mode

}MV_CAM_ACQUISITION_MODE;

/// \~chinese ??????                  \~english Gain Mode
typedef enum _MV_CAM_GAIN_MODE_
{
    MV_GAIN_MODE_OFF                    = 0,                        ///< \~chinese ???                         \~english Single Mode
    MV_GAIN_MODE_ONCE                   = 1,                        ///< \~chinese ???                         \~english Multi Mode
    MV_GAIN_MODE_CONTINUOUS             = 2,                        ///< \~chinese ????                         \~english Continuous Mode

}MV_CAM_GAIN_MODE;

/// \~chinese ?????                  \~english Exposure Mode
typedef enum _MV_CAM_EXPOSURE_MODE_
{
    MV_EXPOSURE_MODE_TIMED              = 0,                        ///< \~chinese ???                         \~english Timed
    MV_EXPOSURE_MODE_TRIGGER_WIDTH      = 1,                        ///< \~chinese ???????????                 \~english TriggerWidth
}MV_CAM_EXPOSURE_MODE;

/// \~chinese ????????              \~english Auto Exposure Mode
typedef enum _MV_CAM_EXPOSURE_AUTO_MODE_
{
    MV_EXPOSURE_AUTO_MODE_OFF           = 0,                        ///< \~chinese ???                         \~english Off
    MV_EXPOSURE_AUTO_MODE_ONCE          = 1,                        ///< \~chinese ???                         \~english Once
    MV_EXPOSURE_AUTO_MODE_CONTINUOUS    = 2,                        ///< \~chinese ????                         \~english Continuous

}MV_CAM_EXPOSURE_AUTO_MODE;

/// \~chinese ??????                  \~english Trigger Mode
typedef enum _MV_CAM_TRIGGER_MODE_
{
    MV_TRIGGER_MODE_OFF                 = 0,                        ///< \~chinese ???                         \~english Off
    MV_TRIGGER_MODE_ON                  = 1,                        ///< \~chinese ??                         \~english ON

}MV_CAM_TRIGGER_MODE;

/// \~chinese Gamma?????               \~english Gamma Selector
typedef enum _MV_CAM_GAMMA_SELECTOR_
{
    MV_GAMMA_SELECTOR_USER              = 1,                        ///< \~chinese ???                         \~english Gamma Selector User
    MV_GAMMA_SELECTOR_SRGB              = 2,                        ///< \~chinese sRGB                         \~english Gamma Selector sRGB

}MV_CAM_GAMMA_SELECTOR;

/// \~chinese ?????                    \~english White Balance
typedef enum _MV_CAM_BALANCEWHITE_AUTO_
{
    MV_BALANCEWHITE_AUTO_OFF            = 0,                        ///< \~chinese ???                         \~english Off
    MV_BALANCEWHITE_AUTO_ONCE           = 2,                        ///< \~chinese ???                         \~english Once
    MV_BALANCEWHITE_AUTO_CONTINUOUS     = 1,                        ///< \~chinese ????                         \~english Continuous

}MV_CAM_BALANCEWHITE_AUTO;

/// \~chinese ?????                    \~english Trigger Source
typedef enum _MV_CAM_TRIGGER_SOURCE_
{
    MV_TRIGGER_SOURCE_LINE0             = 0,                        ///< \~chinese Line0                        \~english Line0
    MV_TRIGGER_SOURCE_LINE1             = 1,                        ///< \~chinese Line1                        \~english Line1
    MV_TRIGGER_SOURCE_LINE2             = 2,                        ///< \~chinese Line2                        \~english Line2
    MV_TRIGGER_SOURCE_LINE3             = 3,                        ///< \~chinese Line3                        \~english Line3
    MV_TRIGGER_SOURCE_COUNTER0          = 4,                        ///< \~chinese Conuter0                     \~english Conuter0

    MV_TRIGGER_SOURCE_SOFTWARE          = 7,                        ///< \~chinese ??????                       \~english Software
    MV_TRIGGER_SOURCE_FrequencyConverter= 8,                        ///< \~chinese ?????                       \~english Frequency Converter

}MV_CAM_TRIGGER_SOURCE;

/// \~chinese GigEVision IP????         \~english GigEVision IP Configuration
#define MV_IP_CFG_STATIC                0x05000000                  ///< \~chinese ???                         \~english Static
#define MV_IP_CFG_DHCP                  0x06000000                  ///< \~chinese DHCP                         \~english DHCP
#define MV_IP_CFG_LLA                   0x04000000                  ///< \~chinese LLA                          \~english LLA

/// \~chinese GigEVision?????????    \~english GigEVision Net Transfer Mode
#define MV_NET_TRANS_DRIVER             0x00000001                  ///< \~chinese ????                         \~english Driver
#define MV_NET_TRANS_SOCKET             0x00000002                  ///< \~chinese Socket                       \~english Socket

/// \~chinese CameraLink??????          \~english CameraLink Baud Rates (CLUINT32)
#define MV_CAML_BAUDRATE_9600           0x00000001                  ///< \~chinese 9600                         \~english 9600
#define MV_CAML_BAUDRATE_19200          0x00000002                  ///< \~chinese 19200                        \~english 19200
#define MV_CAML_BAUDRATE_38400          0x00000004                  ///< \~chinese 38400                        \~english 38400
#define MV_CAML_BAUDRATE_57600          0x00000008                  ///< \~chinese 57600                        \~english 57600
#define MV_CAML_BAUDRATE_115200         0x00000010                  ///< \~chinese 115200                       \~english 115200
#define MV_CAML_BAUDRATE_230400         0x00000020                  ///< \~chinese 230400                       \~english 230400
#define MV_CAML_BAUDRATE_460800         0x00000040                  ///< \~chinese 460800                       \~english 460800
#define MV_CAML_BAUDRATE_921600         0x00000080                  ///< \~chinese 921600                       \~english 921600
#define MV_CAML_BAUDRATE_AUTOMAX        0x40000000                  ///< \~chinese ????                       \~english Auto Max

/// \~chinese ?????????              \~english Exception message type
#define MV_EXCEPTION_DEV_DISCONNECT     0x00008001                  ///< \~chinese ??????????                 \~english The device is disconnected
#define MV_EXCEPTION_VERSION_CHECK      0x00008002                  ///< \~chinese SDK??????????????          \~english SDK does not match the driver version

/// \~chinese U3V????????
typedef enum _MV_CC_STREAM_EXCEPTION_TYPE_
{
    MV_CC_STREAM_EXCEPTION_ABNORMAL_IMAGE   = 0x4001,               ///< \~chinese ???????????????
    MV_CC_STREAM_EXCEPTION_LIST_OVERFLOW    = 0x4002,               ///< \~chinese ??????????????????????
    MV_CC_STREAM_EXCEPTION_LIST_EMPTY       = 0x4003,               ///< \~chinese ?????????????????????
    MV_CC_STREAM_EXCEPTION_RECONNECTION     = 0x4004,               ///< \~chinese ???????
    MV_CC_STREAM_EXCEPTION_DISCONNECTED     = 0x4005,               ///< \~chinese ????,??????,????????
    MV_CC_STREAM_EXCEPTION_DEVICE           = 0x4006,               ///< \~chinese ?????,????????

}MV_CC_STREAM_EXCEPTION_TYPE;

///< \~chinese ???Event???????????    \~english Max length of event name
#define MAX_EVENT_NAME_SIZE             128

/// \~chinese Event?????????\        \~english Event callback infomation
typedef struct _MV_EVENT_OUT_INFO_
{
    char                EventName[MAX_EVENT_NAME_SIZE];             ///< [OUT] \~chinese Event????              \~english Event name

    unsigned short      nEventID;                                   ///< [OUT] \~chinese Event??                \~english Event ID
    unsigned short      nStreamChannel;                             ///< [OUT] \~chinese ????????             \~english Circulation number

    unsigned int        nBlockIdHigh;                               ///< [OUT] \~chinese ??????               \~english BlockId high
    unsigned int        nBlockIdLow;                                ///< [OUT] \~chinese ??????               \~english BlockId low

    unsigned int        nTimestampHigh;                             ///< [OUT] \~chinese ????????             \~english Timestramp high
    unsigned int        nTimestampLow;                              ///< [OUT] \~chinese ????????             \~english Timestramp low

    void*               pEventData;                                 ///< [OUT] \~chinese Event????              \~english Event data
    unsigned int        nEventDataSize;                             ///< [OUT] \~chinese Event???????          \~english Event data len

    unsigned int        nReserved[16];                              ///<       \~chinese ???                   \~english Reserved

}MV_EVENT_OUT_INFO;

/// \~chinese ??????                  \~english File Access
typedef struct _MV_CC_FILE_ACCESS_T
{
    const char*         pUserFileName;                              ///< [IN]  \~chinese ????????             \~english User file name
    const char*         pDevFileName;                               ///< [IN]  \~chinese ????????             \~english Device file name

    unsigned int        nReserved[32];                              ///<       \~chinese ???                   \~english Reserved

}MV_CC_FILE_ACCESS;

/// \~chinese ??????                  \~english File Access
typedef struct _MV_CC_FILE_ACCESS_E
{
    char*               pUserFileBuf;                              ///< [IN]       \~chinese ??????????                                                                 \~english User data Buffer
    unsigned int        pFileBufSize;                              ///< [IN]       \~chinese ?????????????                                                             \~english data buffer size
    unsigned int        pFileBufLen;                               ///< [OUT][IN]  \~chinese ???????????????(???????????????????,?????????????????????)          \~english data buffer len
    const char*         pDevFileName;                              ///< [IN]       \~chinese ????????                                                                    \~english Device file name

    unsigned int        nReserved[32];                              ///<           \~chinese ???                                                                          \~english Reserved
}MV_CC_FILE_ACCESS_EX;

/// \~chinese ??????????              \~english File Access Progress
typedef struct _MV_CC_FILE_ACCESS_PROGRESS_T
{
    int64_t             nCompleted;                                 ///< [OUT] \~chinese ?????????           \~english Completed Length
    int64_t             nTotal;                                     ///< [OUT] \~chinese ?????                 \~english Total Length

    unsigned int        nReserved[8];                               ///<       \~chinese ???                   \~english Reserved

}MV_CC_FILE_ACCESS_PROGRESS;

/// \~chinese Gige?????????            \~english The transmission type of Gige
typedef enum _MV_GIGE_TRANSMISSION_TYPE_
{
    MV_GIGE_TRANSTYPE_UNICAST               = 0x0,                  ///< \~chinese ???????(???)                              \~english Unicast mode
    MV_GIGE_TRANSTYPE_MULTICAST             = 0x1,                  ///< \~chinese ??????(???IP????[224.*.*.*-239.*.*.*])   \~english Multicast mode
    MV_GIGE_TRANSTYPE_LIMITEDBROADCAST      = 0x2,                  ///< \~chinese ????????????????????               \~english Limited broadcast mode,not support
    MV_GIGE_TRANSTYPE_SUBNETBROADCAST       = 0x3,                  ///< \~chinese ??????????????????                 \~english Subnet broadcast mode,not support
    MV_GIGE_TRANSTYPE_CAMERADEFINED         = 0x4,                  ///< \~chinese ???????????????????                 \~english Transtype from camera,not support
    MV_GIGE_TRANSTYPE_UNICAST_DEFINED_PORT  = 0x5,                  ///< \~chinese ?????????????????????????Port??   \~english User Defined Receive Data Port
    MV_GIGE_TRANSTYPE_UNICAST_WITHOUT_RECV  = 0x00010000,           ///< \~chinese ??????????????????????????????????   \~english Unicast without receive data
    MV_GIGE_TRANSTYPE_MULTICAST_WITHOUT_RECV= 0x00010001,           ///< \~chinese ??????????????????????????????     \~english Multicast without receive data

}MV_GIGE_TRANSMISSION_TYPE;

/// \~chinese ?????????              \~english Transmission type
typedef struct _MV_TRANSMISSION_TYPE_T
{
    MV_GIGE_TRANSMISSION_TYPE   enTransmissionType;                 ///< [IN]  \~chinese ??????                   \~english Transmission type
    unsigned int                nDestIp;                            ///< [IN]  \~chinese ???IP???????????????   \~english Destination IP
    unsigned short              nDestPort;                          ///< [IN]  \~chinese ???Port??????????????? \~english Destination port

    unsigned int                nReserved[32];                      ///<       \~chinese ???                       \~english Reserved

}MV_TRANSMISSION_TYPE;

/// \~chinese ???????????              \~english Action Command
typedef struct _MV_ACTION_CMD_INFO_T
{
    unsigned int        nDeviceKey;                                 ///< [IN]  \~chinese ??????                                   \~english Device Key;
    unsigned int        nGroupKey;                                  ///< [IN]  \~chinese ???                                       \~english Group Key
    unsigned int        nGroupMask;                                 ///< [IN]  \~chinese ??????                                     \~english Group Mask

    unsigned int        bActionTimeEnable;                          ///< [IN]  \~chinese ?????????1?Action Time??????????1?????  \~english Action Time Enable
    int64_t             nActionTime;                                ///< [IN]  \~chinese ?????????????????                     \~english Action Time

    const char*         pBroadcastAddress;                          ///< [IN]  \~chinese ???????                                 \~english Broadcast Address
    unsigned int        nTimeOut;                                   ///< [IN]  \~chinese ???ACK???????????0????????ACK    \~english TimeOut

    unsigned int        bSpecialNetEnable;                          ///< [IN]  \~chinese ?????????1??????????IP??????????1????? \~english Special IP Enable
    unsigned int        nSpecialNetIP;                              ///< [IN]  \~chinese ?????????IP                               \~english Special Net IP address

    unsigned int        nReserved[14];                              ///<       \~chinese ???                                       \~english Reserved

}MV_ACTION_CMD_INFO;

/// \~chinese ?????????????          \~english Action Command Result
typedef struct _MV_ACTION_CMD_RESULT_T
{
    unsigned char       strDeviceAddress[12 + 3 + 1];               ///< [OUT] \~chinese ???IP                 \~english IP address of the device

    int                 nStatus;                                    ///< [OUT] \~chinese ????                 \~english status code returned by the device
                                                                    //1.0x0000:success.
                                                                    //2.0x8001:Command is not supported by the device.
                                                                    //3.0x8013:The device is not synchronized to a master clock to be used as time reference.
                                                                    //4.0x8015:A device queue or packet data has overflowed.
                                                                    //5.0x8016:The requested scheduled action command was requested at a time that is already past.

    unsigned int        nReserved[4];                               ///<      \~chinese ???                    \~english Reserved

}MV_ACTION_CMD_RESULT;

/// \~chinese ?????????????????      \~english Action Command Result List
typedef struct _MV_ACTION_CMD_RESULT_LIST_T
{
    unsigned int            nNumResults;                            ///< [OUT] \~chinese ?????????             \~english Number of returned values
    MV_ACTION_CMD_RESULT*   pResults;                               ///< [OUT] \~chinese ??????????           \~english Reslut of action command

}MV_ACTION_CMD_RESULT_LIST;

/// \~chinese ????????????????    \~english Interface type corresponds to each node 
enum MV_XML_InterfaceType
{
    IFT_IValue,                                                     ///< \~chinese Value                        \~english IValue interface
    IFT_IBase,                                                      ///< \~chinese Base                         \~english IBase interface
    IFT_IInteger,                                                   ///< \~chinese Integer                      \~english IInteger interface
    IFT_IBoolean,                                                   ///< \~chinese Boolean                      \~english IBoolean interface
    IFT_ICommand,                                                   ///< \~chinese Command                      \~english ICommand interface
    IFT_IFloat,                                                     ///< \~chinese Float                        \~english IFloat interface
    IFT_IString,                                                    ///< \~chinese String                       \~english IString interface
    IFT_IRegister,                                                  ///< \~chinese Register                     \~english IRegister interface
    IFT_ICategory,                                                  ///< \~chinese Category                     \~english ICategory interface
    IFT_IEnumeration,                                               ///< \~chinese Enumeration                  \~english IEnumeration interface
    IFT_IEnumEntry,                                                 ///< \~chinese EnumEntry                    \~english IEnumEntry interface
    IFT_IPort,                                                      ///< \~chinese Port                         \~english IPort interface
};

/// \~chinese ?????????            \~english Node Access Mode
enum MV_XML_AccessMode
{
    AM_NI,                                                          ///< \~chinese ???????                     \~english Not implemented
    AM_NA,                                                          ///< \~chinese ??????                       \~english Not available
    AM_WO,                                                          ///< \~chinese ???                         \~english Write Only
    AM_RO,                                                          ///< \~chinese ???                         \~english Read Only
    AM_RW,                                                          ///< \~chinese ????                         \~english Read and Write
    AM_Undefined,                                                   ///< \~chinese ??????                       \~english Object is not yet initialized
    AM_CycleDetect,                                                 ///< \~chinese ???????AccessMode??????   \~english used internally for AccessMode cycle detection
};

/// \~chinese ???XML??????             \~english Max XML Symbolic Number 
#define MV_MAX_XML_SYMBOLIC_NUM         64
/// \~chinese ????????                \~english Enumeration Value
typedef struct _MVCC_ENUMVALUE_T
{
    unsigned int        nCurValue;                                  ///< [OUT] \~chinese ????                 \~english Current Value
    unsigned int        nSupportedNum;                              ///< [OUT] \~chinese ????????????????     \~english Number of valid data
    unsigned int        nSupportValue[MV_MAX_XML_SYMBOLIC_NUM];     ///< [OUT] \~chinese ????????           \~english Support Value 

    unsigned int        nReserved[4];                               ///<       \~chinese ???                   \~english Reserved

}MVCC_ENUMVALUE;

/// \~chinese ????????????????????            \~english Max Enum Entry Symbolic Number 
#define MV_MAX_SYMBOLIC_LEN         64
/// \~chinese ??????????                          \~english Enumeration Entry
typedef struct _MVCC_ENUMENTRY_T
{
    unsigned int        nValue;                                     ///< [IN]  \~chinese ????                 \~english Value
    char                chSymbolic[MV_MAX_SYMBOLIC_LEN];            ///< [OUT] \~chinese ????????????       \~english Symbolic

    unsigned int        nReserved[4];                               ///< \~chinese ???                         \~english Reserved

}MVCC_ENUMENTRY;

/// \~chinese Int?????                 \~english Int Value
typedef struct _MVCC_INTVALUE_T
{
    unsigned int        nCurValue;                                  ///< [OUT] \~chinese ????                 \~english Current Value
    unsigned int        nMax;                                       ///< [OUT] \~chinese ????                 \~english Max
    unsigned int        nMin;                                       ///< [OUT] \~chinese ?????                 \~english Min
    unsigned int        nInc;                                       ///< [OUT] \~chinese                        \~english Inc

    unsigned int        nReserved[4];                               ///<       \~chinese ???                   \~english Reserved

}MVCC_INTVALUE;

/// \~chinese Int?????Ex               \~english Int Value Ex
typedef struct _MVCC_INTVALUE_EX_T
{
    int64_t             nCurValue;                                  ///< [OUT] \~chinese ????                 \~english Current Value
    int64_t             nMax;                                       ///< [OUT] \~chinese ????                 \~english Max
    int64_t             nMin;                                       ///< [OUT] \~chinese ?????                 \~english Min
    int64_t             nInc;                                       ///< [OUT] \~chinese Inc                    \~english Inc

    unsigned int        nReserved[16];                              ///<       \~chinese ???                   \~english Reserved

}MVCC_INTVALUE_EX;

/// \~chinese Float?????               \~english Float Value
typedef struct _MVCC_FLOATVALUE_T
{
    float               fCurValue;                                  ///< [OUT] \~chinese ????                 \~english Current Value
    float               fMax;                                       ///< [OUT] \~chinese ????                 \~english Max
    float               fMin;                                       ///< [OUT] \~chinese ?????                 \~english Min

    unsigned int        nReserved[4];                               ///<       \~chinese ???                   \~english Reserved

}MVCC_FLOATVALUE;

/// \~chinese String?????              \~english String Value
typedef struct _MVCC_STRINGVALUE_T
{
    char                chCurValue[256];                            ///< [OUT] \~chinese ????                 \~english Current Value

    int64_t             nMaxLength;                                 ///< [OUT] \~chinese ????               \~english MaxLength
    unsigned int        nReserved[2];                               ///<       \~chinese ???                   \~english Reserved

}MVCC_STRINGVALUE;

/// \~chinese ?????????                \~english Color of Auxiliary Line
typedef struct _MVCC_COLORF
{
	float           fR;             ///< [IN] \~chinese ??????????????????????????????[0.0 , 1.0]????????[0, 255]????????   \~english Red??Range[0.0, 1.0]
    float           fG;             ///< [IN] \~chinese ??????????????????????????????[0.0 , 1.0]????????[0, 255]????????   \~english Green??Range[0.0, 1.0]
    float           fB;             ///< [IN] \~chinese ??????????????????????????????[0.0 , 1.0]????????[0, 255]????????   \~english Blue??Range[0.0, 1.0]
    float           fAlpha;         ///< [IN] \~chinese ?????????????????????????????????[0.0 , 1.0] (???????????????)    \~english Alpha??Range[0.0, 1.0](Not Support)
    unsigned int    nReserved[4];   ///<      \~chinese ???                        \~english Reserved

}MVCC_COLORF;

/// \~chinese ??????                    \~english Point defined
typedef struct _MVCC_POINTF
{
    float           fX;             ///< [IN] \~chinese ??????????????????????????????????????[0.0 , 1.0]   \~english Distance From Left??Range[0.0, 1.0]
    float           fY;             ///< [IN] \~chinese ??????????????????????????????????????[0.0 , 1.0]   \~english Distance From Top??Range[0.0, 1.0]
    unsigned int    nReserved[4];   ///<      \~chinese ???                        \~english Reserved

}MVCC_POINTF;

/// \~chinese ?????????????            \~english Rect Area Info
typedef struct _MVCC_RECT_INFO
{
    float           fTop;           ///< [IN] \~chinese ?????????????????????????????????????????????[0.0 , 1.0]   \~english Distance From Top??Range[0, 1.0]
    float           fBottom;        ///< [IN] \~chinese ??????????????????????????????????????????????[0.0 , 1.0]   \~english Distance From Top??Range[0, 1.0]
    float           fLeft;          ///< [IN] \~chinese ?????????????????????????????????????????????[0.0 , 1.0]   \~english Distance From Left??Range[0, 1.0]
    float           fRight;         ///< [IN] \~chinese ?????????????????????????????????????????????[0.0 , 1.0]   \~english Distance From Left??Range[0, 1.0]

    MVCC_COLORF     stColor;        ///< [IN] \~chinese ?????????                      \~english Color of Auxiliary Line
    unsigned int    nLineWidth;     ///< [IN] \~chinese ???????????????????1??2      \~english Width of Auxiliary Line, width is 1 or 2
    unsigned int    nReserved[4];   ///<      \~chinese ???                            \~english Reserved

}MVCC_RECT_INFO;

/// \~chinese ????????????            \~english Circle Area Info
typedef struct _MVCC_CIRCLE_INFO
{
    MVCC_POINTF     stCenterPoint;  ///< [IN] \~chinese ??????                        \~english Circle Point Info

    float           fR1;            ///< [IN] \~chinese ??????????????????????[0, 1.0]???????????????????????????????????????????????  \~english Windth Radius, Range[0, 1.0]
    float           fR2;            ///< [IN] \~chinese ??????????????????????[0, 1.0]???????????????????????????????????????????????  \~english Height Radius, Range[0, 1.0]

    MVCC_COLORF     stColor;        ///< [IN] \~chinese ????????????                  \~english Color of Auxiliary Line
    unsigned int    nLineWidth;     ///< [IN] \~chinese ???????????????????1??2      \~english Width of Auxiliary Line, width is 1 or 2
    unsigned int    nReserved[4];   ///<      \~chinese ???                            \~english Reserved

}MVCC_CIRCLE_INFO;

/// \~chinese ?????????????    \~english Linear Auxiliary Line Info
typedef struct _MVCC_LINES_INFO
{
    MVCC_POINTF     stStartPoint;   ///< [IN] \~chinese ????????????????????          \~english The Start Point of Auxiliary Line
    MVCC_POINTF     stEndPoint;     ///< [IN] \~chinese ??????????????????            \~english The End Point of Auxiliary Line
    MVCC_COLORF     stColor;        ///< [IN] \~chinese ????????????                  \~english Color of Auxiliary Line
    unsigned int    nLineWidth;     ///< [IN] \~chinese ???????????????????1??2      \~english Width of Auxiliary Line, width is 1 or 2
    unsigned int    nReserved[4];   ///<  \~chinese ???                            \~english Reserved

}MVCC_LINES_INFO;

///< \~chinese ???????????????????? \~english The maximum number of source image to be split in time-division exposure
#define MV_MAX_SPLIT_NUM                  8

/// \~chinese ??????????        \~english Image reconstruction method
typedef enum _MV_IMAGE_RECONSTRUCTION_METHOD_
{
    MV_SPLIT_BY_LINE                   = 1, ///< \~chinese ????????????????         \~english Source image split into multiple images by line

}MV_IMAGE_RECONSTRUCTION_METHOD;

/// \~chinese ????????????????      \~english List of images after image reconstruction
typedef struct _MV_OUTPUT_IMAGE_INFO_
{
    unsigned int                    nWidth;        ///< [OUT]       \~chinese ?????              \~english Source Image Width
    unsigned int                    nHeight;       ///< [OUT]       \~chinese ?????              \~english Source Image Height
    enum MvGvspPixelType            enPixelType;   ///< [OUT]       \~chinese ??????              \~english Pixel format

    unsigned char*                  pBuf;          ///< [IN][OUT]   \~chinese ??????????          \~english Output data buffer
    unsigned int                    nBufLen;       ///< [OUT]       \~chinese ??????????          \~english Output data length
    unsigned int                    nBufSize;      ///< [IN]        \~chinese ?????????????????  \~english Provided output buffer size

    unsigned int                    nRes[8];       ///<             \~chinese ???                  \~english Reserved
}MV_OUTPUT_IMAGE_INFO;

/// \~chinese ????????????      \~english Restructure image parameters
typedef struct _MV_RECONSTRUCT_IMAGE_PARAM_
{
    unsigned int                    nWidth;                             ///< [IN]  \~chinese ?????          \~english Source Image Width
    unsigned int                    nHeight;                            ///< [IN]  \~chinese ?????          \~english Source Image Height
    enum MvGvspPixelType            enPixelType;                        ///< [IN]  \~chinese ??????          \~english Pixel format

    unsigned char*                  pSrcData;                           ///< [IN]  \~chinese ???????????      \~english Input data buffer
    unsigned int                    nSrcDataLen;                        ///< [IN]  \~chinese ???????????      \~english Input data length

    unsigned int                    nExposureNum;                       ///< [IN]  \~chinese ??????(1-8]     \~english Exposure number
    MV_IMAGE_RECONSTRUCTION_METHOD  enReconstructMethod;                ///< [IN]  \~chinese ?????????      \~english Image restructuring method

    MV_OUTPUT_IMAGE_INFO            stDstBufList[MV_MAX_SPLIT_NUM];     ///< [OUT] \~chinese ?????????????  \~english Output data info

    unsigned int                    nRes[4];
}MV_RECONSTRUCT_IMAGE_PARAM;

#endif /* _MV_CAMERA_PARAMS_H_ */
