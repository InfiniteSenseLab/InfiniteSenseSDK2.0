
#ifndef _MV_OBSOLETE_INTERFACES_H_
#define _MV_OBSOLETE_INTERFACES_H_

#include "MvErrorDefine.h"
#include "CameraParams.h"
#include "ObsoleteCamParams.h"

/**
*  @brief  ��̬�⵼�뵼������
*  @brief  Import and export definition of the dynamic library 
*/
#ifndef MV_CAMCTRL_API

    #if (defined (_WIN32) || defined(WIN64))
        #if defined(MV_CAMCTRL_EXPORTS)
            #define MV_CAMCTRL_API __declspec(dllexport)
        #else
            #define MV_CAMCTRL_API __declspec(dllimport)
        #endif
    #else
        #ifndef __stdcall
            #define __stdcall
        #endif

        #ifndef MV_CAMCTRL_API
            #define  MV_CAMCTRL_API
        #endif
    #endif

#endif

#ifndef IN
    #define IN
#endif

#ifndef OUT
    #define OUT
#endif

#ifdef __cplusplus
extern "C" {
#endif 

/************************************************************************/
/* ������ʹ�õĽӿ�                     	                    		*/
/* Interfaces not recommended                                           */
/************************************************************************/
/************************************************************************
 *  @fn     MV_CC_GetImageInfo
 *  @brief  ��ȡͼ�������Ϣ
 *  @param  handle                      [IN]            �豸���
 *  @param  pstInfo                     [IN][OUT]       ���ظ��������й����ͼ�������Ϣ�ṹ��ָ��
 *  @return �ɹ�,����MV_OK,ʧ��,���ش�����
 
 *  @fn     MV_CC_GetImageInfo
 *  @brief  Get basic information of image
 *  @param  handle                      [IN]            Device handle
 *  @param  pstInfo                     [IN][OUT]       Structure pointer of image basic information
 *  @return Success, return MV_OK. Failure, return error code
 ************************************************************************/
MV_CAMCTRL_API int __stdcall MV_CC_GetImageInfo(IN void* handle, IN OUT MV_IMAGE_BASIC_INFO* pstInfo);

/************************************************************************
 *  @fn     MV_CC_GetTlProxy
 *  @brief  ��ȡGenICam����
 *  @param  handle                 [IN]           �����ַ
 *  @return GenICam������ָ�� ����������ֵ��NULL���쳣����NULL
 
 *  @fn     MV_CC_GetTlProxy
 *  @brief  Get GenICam proxy
 *  @param  handle                 [IN]           Handle address
 *  @return GenICam proxy pointer, normal, return non-NULL; exception, return NULL
 ************************************************************************/
MV_CAMCTRL_API void* __stdcall MV_CC_GetTlProxy(IN void* handle);

/***********************************************************************
 *  @fn         MV_XML_GetRootNode
 *  @brief      ��ȡ���ڵ�
 *  @param       handle                 [IN]          ���
 *  @param       pstNode                [OUT]         ���ڵ���Ϣ�ṹ��
 *  @return �ɹ�������MV_OK�����󣬷��ش�����
 
 *  @fn         MV_XML_GetRootNode
 *  @brief      Get root node
 *  @param       handle                 [IN]          Handle
 *  @param       pstNode                [OUT]         Root node information structure
 *  @return Success, return MV_OK. Failure, return error code
 ***********************************************************************/
MV_CAMCTRL_API int __stdcall MV_XML_GetRootNode(IN void* handle, IN OUT MV_XML_NODE_FEATURE* pstNode);

/***********************************************************************
 *  @fn         MV_XML_GetChildren
 *  @brief      ��xml�л�ȡָ���ڵ�������ӽڵ㣬���ڵ�ΪRoot
 *  @param       handle                 [IN]          ���
 *  @param       pstNode                [IN]          ���ڵ���Ϣ�ṹ��
 *  @param       pstNodesList           [OUT]         �ڵ��б��ṹ��
 *  @return �ɹ�������MV_OK�����󣬷��ش�����
 
 *  @fn         MV_XML_GetChildren
 *  @brief      Get all children node of specific node from xml, root node is Root
 *  @param       handle                 [IN]          Handle
 *  @param       pstNode                [IN]          Root node information structure
 *  @param       pstNodesList           [OUT]         Node information structure
 *  @return Success, return MV_OK. Failure, return error code
 ***********************************************************************/
MV_CAMCTRL_API int __stdcall MV_XML_GetChildren(IN void* handle, IN MV_XML_NODE_FEATURE* pstNode, IN OUT MV_XML_NODES_LIST* pstNodesList);

/***********************************************************************
 *  @fn         MV_XML_GetNodeFeature
 *  @brief      ��õ�ǰ�ڵ������
 *  @param       handle                 [IN]          ���
 *  @param       pstNode                [IN]          ���ڵ���Ϣ�ṹ��
 *  @param       pstFeature             [OUT]         ��ǰ�ڵ����Խṹ�壬
                           pstFeature ����ṹ�����ݲο� MV_XML_FEATURE_x
 *  @return �ɹ�������MV_OK�����󣬷��ش�����
 
 *  @fn         MV_XML_GetNodeFeature
 *  @brief      Get current node feature
 *  @param       handle                 [IN]          Handle
 *  @param       pstNode                [IN]          Root node information structure
 *  @param       pstFeature             [OUT]         Current node feature structure
                           Details of pstFeature refer to MV_XML_FEATURE_x
 *  @return Success, return MV_OK. Failure, return error code
 ***********************************************************************/
MV_CAMCTRL_API int __stdcall MV_XML_GetNodeFeature(IN void* handle, IN MV_XML_NODE_FEATURE* pstNode, IN OUT void* pstFeature);

/***********************************************************************
 *  @fn         MV_XML_UpdateNodeFeature
 *  @brief      ���½ڵ�
 *  @param       handle                 [IN]          ���
 *  @param       enType                 [IN]          �ڵ�����
 *  @param       pstFeature             [OUT]         ��ǰ�ڵ����Խṹ��
 *  @return �ɹ�������MV_OK�����󣬷��ش�����
 
 *  @fn         MV_XML_UpdateNodeFeature
 *  @brief      Update node
 *  @param       handle                 [IN]          Handle
 *  @param       enType                 [IN]          Node type
 *  @param       pstFeature             [OUT]         Current node feature structure
 *  @return Success, return MV_OK. Failure, return error code
 ***********************************************************************/
MV_CAMCTRL_API int __stdcall MV_XML_UpdateNodeFeature(IN void* handle, IN enum MV_XML_InterfaceType enType, IN void* pstFeature);

// �нڵ���Ҫ����ʱ�Ļص�����
// ������MV_XML_UpdateNodeFeature�ӿڸ��½ڵ�����ʱ��ע��Ļص�����cbUpdate����pstNodesList�з�����֮������Ľڵ�
/***********************************************************************
 *  @fn         MV_XML_RegisterUpdateCallBack
 *  @brief      ע����»ص�
 *  @param       handle                 [IN]          ���
 *  @param       cbUpdate               [IN]          �ص�����ָ��
 *  @param       pUser                  [IN]          �û��Զ������
 *  @return �ɹ�������MV_OK�����󣬷��ش�����
 
 *  @fn         MV_XML_RegisterUpdateCallBack
 *  @brief      Register update callback
 *  @param       handle                 [IN]          Handle
 *  @param       cbUpdate               [IN]          Callback function pointer
 *  @param       pUser                  [IN]          User defined variable
 *  @return Success, return MV_OK. Failure, return error code
 ***********************************************************************/
MV_CAMCTRL_API int __stdcall MV_XML_RegisterUpdateCallBack(IN void* handle, 
                                                           IN void(__stdcall* cbUpdate)(enum MV_XML_InterfaceType enType, void* pstFeature, MV_XML_NODES_LIST* pstNodesList, void* pUser),
                                                           IN void* pUser);

/************************************************************************/
/* ���õĽӿڣ����ڸ��Ż��Ľӿڿ��滻��                     			*/
/* Abandoned interface                                                  */
/************************************************************************/
/***********************************************************************
 *  @fn         MV_CC_GetOneFrame
 *  @brief      ��ȡһ֡ͼ�񣬴˺���Ϊ��ѯʽ��ȡ��ÿ�ε��ò�ѯ�ڲ�������
                �����ݣ���������Χ���ݣ������ݷ��ش�����
                ���ýӿ������ã�������� MV_CC_GetOneFrameTimeOut�ӿڣ�
 *  @param       handle                 [IN]          ���
 *  @param       pData                  [OUT]         ͼ�����ݽ���ָ��
 *  @param       nDataSize              [IN]          ���ջ����С
 *  @param       pFrameInfo             [OUT]         ͼ����Ϣ�ṹ��
 *  @return �ɹ�������MV_OK�����󣬷��ش�����
 
 *  @fn         MV_CC_GetOneFrame
 *  @brief      Get one frame data, this function is using query to get data, 
                query whether the internal cache has data, return data if there has, return error code if no data
                (This interface is abandoned, it is recommended to use the MV_CC_GetOneFrameTimeOut)
 *  @param       handle                 [IN]          Handle
 *  @param       pData                  [OUT]         Recevied image data pointer
 *  @param       nDataSize              [IN]          Recevied buffer size
 *  @param       pFrameInfo             [OUT]         Image information structure
 *  @return Success, return MV_OK. Failure, return error code
 ***********************************************************************/
MV_CAMCTRL_API int __stdcall MV_CC_GetOneFrame(IN void* handle, IN OUT unsigned char * pData , IN unsigned int nDataSize, IN OUT MV_FRAME_OUT_INFO* pFrameInfo);

/***********************************************************************
 *  @fn         MV_CC_GetOneFrameEx
 *  @brief      ��ȡһ֡trunck���ݣ��˺���Ϊ��ѯʽ��ȡ��ÿ�ε��ò�ѯ�ڲ�
                �����������ݣ���������Χ���ݣ������ݷ��ش�����
                ���ýӿ������ã�������� MV_CC_GetOneFrameTimeOut�ӿڣ�
 *  @param       handle                 [IN]          ���
 *  @param       pData                  [OUT]         ͼ�����ݽ���ָ��
 *  @param       nDataSize              [IN]          ���ջ����С
 *  @param       pFrameInfo             [OUT]         ͼ����Ϣ�ṹ��
 *  @return �ɹ�������MV_OK�����󣬷��ش�����
 
 *  @fn         MV_CC_GetOneFrameEx
 *  @brief      Get one frame of trunck data, this function is using query to get data, 
                query whether the internal cache has data, return data if there has, return error code if no data
                (This interface is abandoned, it is recommended to use the MV_CC_GetOneFrameTimeOut)
 *  @param       handle                 [IN]          Handle
 *  @param       pData                  [OUT]         Recevied image data pointer
 *  @param       nDataSize              [IN]          Recevied buffer size
 *  @param       pFrameInfo             [OUT]         Image information structure
 *  @return Success, return MV_OK. Failure, return error code
 ***********************************************************************/
MV_CAMCTRL_API int __stdcall MV_CC_GetOneFrameEx(IN void* handle, IN OUT unsigned char * pData , IN unsigned int nDataSize, IN OUT MV_FRAME_OUT_INFO_EX* pFrameInfo);

/***********************************************************************
 *  @fn         MV_CC_RegisterImageCallBack
 *  @brief      ע��ͼ�����ݻص����ýӿ������ã�������� MV_CC_RegisterImageCallBackEx�ӿڣ�
 *  @param       handle                 [IN]          ���
 *  @param       cbOutput               [IN]          �ص�����ָ��
 *  @param       pUser                  [IN]          �û��Զ������
 *  @return �ɹ�������MV_OK�����󣬷��ش�����
 
 *  @fn         MV_CC_RegisterImageCallBack
 *  @brief      Register image data callback (This interface is abandoned, it is recommended to use the MV_CC_RegisterImageCallBackEx)
 *  @param       handle                 [IN]          Handle
 *  @param       cbOutput               [IN]          Callback function pointer
 *  @param       pUser                  [IN]          User defined variable
 *  @return Success, return MV_OK. Failure, return error code
 ***********************************************************************/
MV_CAMCTRL_API int __stdcall MV_CC_RegisterImageCallBack(void* handle, 
                                                         void(__stdcall* cbOutput)(unsigned char * pData, MV_FRAME_OUT_INFO* pFrameInfo, void* pUser),
                                                         void* pUser);

/************************************************************************
 *  @fn     MV_CC_SaveImage
 *  @brief  ����ͼƬ���ýӿ������ã�������� MV_CC_SaveImageEx2�ӿڣ�
 *  @param  pSaveParam             [IN][OUT]          ����ͼƬ�����ṹ��
                       pData;              // [IN]     �������ݻ���
                       nDataLen;           // [IN]     �������ݴ�С
                       enPixelType;        // [IN]     �������ݵ����ظ�ʽ
                       nWidth;             // [IN]     ͼ���
                       nHeight;            // [IN]     ͼ���
                       pImageBuffer;       // [OUT]    ���ͼƬ����
                       nImageLen;          // [OUT]    ���ͼƬ��С
                       nBufferSize;        // [IN]     �ṩ�������������С
                       enImageType;        // [IN]     ���ͼƬ��ʽ
 *  @return �ɹ�������MV_OK�����󣬷��ش����� 
 
 *  @fn     MV_CC_SaveImage
 *  @brief  Save image (This interface is abandoned, it is recommended to use the MV_CC_SaveImageEx)
 *  @param  pSaveParam             [IN][OUT]          Save image parameters structure
                       pData;              // [IN]     Input data buffer
                       nDataLen;           // [IN]     Input data size
                       enPixelType;        // [IN]     Input data pixel format
                       nWidth;             // [IN]     Width
                       nHeight;            // [IN]     Height
                       pImageBuffer;       // [OUT]    Output image buffer
                       nImageLen;          // [OUT]    Output image size
                       nBufferSize;        // [IN]     Provided output buffer size
                       enImageType;        // [IN]     Output image type
 *  @return Success, return MV_OK. Failure, return error code
 ************************************************************************/
MV_CAMCTRL_API int __stdcall MV_CC_SaveImage(IN OUT MV_SAVE_IMAGE_PARAM* pSaveParam);

/************************************************************************
 *  @fn     MV_CC_SaveImageEx
 *  @brief  ����ͼƬ��֧��Bmp��Jpeg.����������50-99֮ǰ ���ýӿ������ã�������� MV_CC_SaveImageEx2�ӿڣ�
 *  @param  pSaveParam             [IN][OUT]          ����ͼƬ�����ṹ��
                       pData;              // [IN]     �������ݻ���
                       nDataLen;           // [IN]     �������ݴ�С
                       enPixelType;        // [IN]     �������ݵ����ظ�ʽ
                       nWidth;             // [IN]     ͼ���
                       nHeight;            // [IN]     ͼ���
                       pImageBuffer;       // [OUT]    ���ͼƬ����
                       nImageLen;          // [OUT]    ���ͼƬ��С
                       nBufferSize;        // [IN]     �ṩ�������������С
                       enImageType;        // [IN]     ���ͼƬ��ʽ
                       nJpgQuality;        // [IN]     ��������, (50-99]
                       nReserved[4];
 *  @return �ɹ�������MV_OK�����󣬷��ش����� 
 
 *  @fn     MV_CC_SaveImageEx
 *  @brief  Save image, support Bmp and Jpeg. Encoding quality, (50-99]
 *  @param  pSaveParam             [IN][OUT]           Save image parameters structure
                       pData;              // [IN]     Input data buffer
                       nDataLen;           // [IN]     Input data size
                       enPixelType;        // [IN]     Pixel format of input data
                       nWidth;             // [IN]     Image width
                       nHeight;            // [IN]     Image height
                       pImageBuffer;       // [OUT]    Output image buffer
                       nImageLen;          // [OUT]    Output image size
                       nBufferSize;        // [IN]     Output buffer size provided
                       enImageType;        // [IN]     Output image format
                       nJpgQuality;        // [IN]     Encoding quality, (50-99]
                       nReserved[4];
 *  @return Success, return MV_OK. Failure, return error code
 ************************************************************************/
MV_CAMCTRL_API int __stdcall MV_CC_SaveImageEx(IN OUT MV_SAVE_IMAGE_PARAM_EX* pSaveParam);

/********************************************************************//**
 *  @~chinese
 *  @brief  Bayer�������ƣ��ýӿ������ã��������ISP Tool��ʽ���б궨��
 *  @param  handle                      [IN]            �豸���
 *  @param  pstNoiseEstimateParam       [IN][OUT]       Bayer�������Ʋ����ṹ��
 *  @return �ɹ�������MV_OK�����󣬷��ش����� 
 *  @remarks �ýӿ�ֻ֧��Bayer8/Bayer10/Bayer12��ʽ,����Bayer��ʽ����ת��Bayer8/Bayer10/Bayer12��ʽ��\n
             �ýӿ�ֻ���ڴ���˾�ض���ɫ�����ſ�������ʹ�ã���������Ͽ����ߵ��ߺ󣬼���ʹ�øýӿڻᱨ����
 
 *  @~english
 *  @brief  Noise estimate of Bayer format
 *  @param  handle                      [IN]            Device handle
 *  @param  pstNoiseEstimateParam       [IN][OUT]       Noise estimate parameter structure
 *  @return Success, return MV_OK. Failure, return error code
 *  @remarks This API only support Bayer8/Bayer10/Bayer12 format, other Bayer format must Convert to Bayer8/Bayer10/Bayer12 format.\n
             This API is only available when the camera is turned on, and when the camera is disconnected or disconnected, continuing to use This API will return an error.
 ************************************************************************/
MV_CAMCTRL_API int __stdcall MV_CC_BayerNoiseEstimate(IN void* handle, IN OUT MV_CC_BAYER_NOISE_ESTIMATE_PARAM* pstNoiseEstimateParam);

/********************************************************************//**
 *  @~chinese
 *  @brief  Bayer�����루�ýӿ������ã��������ISP Tool��ʽ���н��룩
 *  @param  handle                      [IN]            �豸���
 *  @param  pstSpatialDenoiseParam      [IN][OUT]       Bayer����������ṹ��
 *  @return �ɹ�������MV_OK�����󣬷��ش����� 
 *  @remarks �ýӿ�ֻ֧��Bayer8/Bayer10/Bayer12��ʽ,����Bayer��ʽ����ת��Bayer8/Bayer10/Bayer12��ʽ��\n
             �ýӿ�ֻ���ڴ���˾�ض���ɫ�����ſ�������ʹ�ã���������Ͽ����ߵ��ߺ󣬼���ʹ�øýӿڻᱨ����
 
 *  @~english
 *  @brief  Spatial Denoise of Bayer format
 *  @param  handle                      [IN]            Device handle
 *  @param  pstSpatialDenoiseParam      [IN][OUT]       Spatial Denoise parameter structure
 *  @return Success, return MV_OK. Failure, return error code
 *  @remarks This API only support Bayer8/Bayer10/Bayer12 format, other Bayer format must Convert to Bayer8/Bayer10/Bayer12 format.\n
             This API is only available when the camera is turned on, and when the camera is disconnected or disconnected, continuing to use This API will return an error.
 ************************************************************************/
MV_CAMCTRL_API int __stdcall MV_CC_BayerSpatialDenoise(IN void* handle, IN OUT MV_CC_BAYER_SPATIAL_DENOISE_PARAM* pstSpatialDenoiseParam);

/********************************************************************//**
 *  @~chinese
 *  @brief  ����Bayer��ʽ��CLUTʹ�ܺ���Ϣ���ýӿ������ã��������ISP Tool��ʽ�������ã�
 *  @param  handle                      [IN]            �豸���
 *  @param  pstCLUTParam                [IN]            CLUT����
 *  @return �ɹ�������MV_OK�����󣬷��ش����� 
 *  @remarks ����CLUT������CLUT��Ϣ���ڵ���MV_CC_ConvertPixelType��MV_CC_SaveImageEx2�ӿڽ�Bayer8/10/12/16��ʽת��RGB24/48�� RGBA32/64��BGR24/48��BGRA32/64ʱ��Ч��

 *  @~english
 *  @brief  Set CLUT param
 *  @param  handle                      [IN]            Device handle
 *  @param  pstCLUTParam                [IN]            CLUT parameter structure
 *  @return Success, return MV_OK. Failure, return error code
 *  @remarks After enable the CLUT and set CLUT, It work in the calling MV_CC_ConvertPixelType\MV_CC_SaveImageEx2 API convert Bayer8/10/12/16 to RGB24/48�� RGBA32/64��BGR24/48��BGRA32/64.
 ************************************************************************/
MV_CAMCTRL_API int __stdcall MV_CC_SetBayerCLUTParam(IN void* handle, IN MV_CC_CLUT_PARAM* pstCLUTParam);

/********************************************************************//**
 *  @~chinese
 *  @brief  ͼ���񻯣��ýӿ������ã��������ISP Tool��ʽ�����񻯣�
 *  @param  handle                      [IN]            �豸���
 *  @param  pstSharpenParam             [IN]            �񻯲���
 *  @return �ɹ�������MV_OK�����󣬷��ش����� 

 *  @~english
 *  @brief  Image sharpen
 *  @param  handle                      [IN]            Device handle
 *  @param  pstSharpenParam             [IN]            Sharpen parameter structure
 *  @return Success, return MV_OK. Failure, return error code
 ************************************************************************/
MV_CAMCTRL_API int __stdcall MV_CC_ImageSharpen(IN void* handle, IN OUT MV_CC_SHARPEN_PARAM* pstSharpenParam);

/********************************************************************//**
 *  @~chinese
 *  @brief  ɫ��У��������CCM��CLUT�����ýӿ������ã��������ISP Tool��ʽ����У����
 *  @param  handle                      [IN]            �豸���
 *  @param  pstColorCorrectParam        [IN]            ɫ��У������
 *  @return �ɹ�������MV_OK�����󣬷��ش����� 
 *  @remarks �ýӿ�֧�ֵ���CCM����CLUT��Ҳ֧��ͬʱ����CCM��CLUT���û�����ͨ��CCM��CLUT��Ϣ�е�ʹ�ܿ��ؽ���ѡ��

 *  @~english
 *  @brief  Color Correct(include CCM and CLUT)
 *  @param  handle                      [IN]            Device handle
 *  @param  pstColorCorrectParam        [IN]            Color Correct parameter structure
 *  @return Success, return MV_OK. Failure, return error code
 *  @remarks This API supports CCM or CLUT alone, as well as CCM and CLUT at the same time. The user can select by means of the enable switch in CCM and CLUT information.
 ************************************************************************/
MV_CAMCTRL_API int __stdcall MV_CC_ColorCorrect(IN void* handle, IN OUT MV_CC_COLOR_CORRECT_PARAM* pstColorCorrectParam);

/********************************************************************//**
 *  @~chinese
 *  @brief  �������ƣ��ýӿ������ã��������ISP Tool��ʽ���б궨��
 *  @param  handle                      [IN]            �豸���
 *  @param  pstNoiseEstimateParam       [IN]            �������Ʋ���
 *  @return �ɹ�������MV_OK�����󣬷��ش����� 
 *  @remarks ����û�ѡ��ȫͼ���������ƣ�nROINum������0��pstROIRect���ÿա�

 *  @~english
 *  @brief  Noise Estimate
 *  @param  handle                      [IN]            Device handle
 *  @param  pstNoiseEstimateParam       [IN]            Noise Estimate parameter structure
 *  @return Success, return MV_OK. Failure, return error code
 *  @remarks If the user selects the full image, nROINum can be typed with 0 and pstROIRect empty.
 ************************************************************************/
MV_CAMCTRL_API int __stdcall MV_CC_NoiseEstimate(IN void* handle, IN OUT MV_CC_NOISE_ESTIMATE_PARAM* pstNoiseEstimateParam);

/********************************************************************//**
 *  @~chinese
 *  @brief  �����루�ýӿ������ã��������ISP Tool��ʽ���н��룩
 *  @param  handle                      [IN]            �豸���
 *  @param  pstSpatialDenoiseParam      [IN]            ���������
 *  @return �ɹ�������MV_OK�����󣬷��ش����� 

 *  @~english
 *  @brief  Spatial Denoise
 *  @param  handle                      [IN]            Device handle
 *  @param  pstSpatialDenoiseParam      [IN]            Spatial Denoise parameter structure
 *  @return Success, return MV_OK. Failure, return error code
 ************************************************************************/
MV_CAMCTRL_API int __stdcall MV_CC_SpatialDenoise(IN void* handle, IN OUT MV_CC_SPATIAL_DENOISE_PARAM* pstSpatialDenoiseParam);


/********************************************************************//**
 *  @~chinese
 *  @brief  LSC�궨
 *  @param  handle                      [IN]            �豸���
 *  @param  pstLSCCalibParam            [IN]            �궨����
 *  @return �ɹ�������MV_OK�����󣬷��ش����� 

 *  @~english
 *  @brief  LSC Calib
 *  @param  handle                      [IN]            Device handle
 *  @param  pstLSCCalibParam            [IN]            LSC Calib parameter structure
 *  @return Success, return MV_OK. Failure, return error code
 ************************************************************************/
MV_CAMCTRL_API int __stdcall MV_CC_LSCCalib(IN void* handle, IN OUT MV_CC_LSC_CALIB_PARAM* pstLSCCalibParam);

/********************************************************************//**
 *  @~chinese
 *  @brief  LSCУ��
 *  @param  handle                      [IN]            �豸���
 *  @param  pstLSCCorrectParam          [IN]            У������
 *  @return �ɹ�������MV_OK�����󣬷��ش����� 

 *  @~english
 *  @brief  LSC Correct
 *  @param  handle                      [IN]            Device handle
 *  @param  pstLSCCorrectParam          [IN]            LSC Correct parameter structure
 *  @return Success, return MV_OK. Failure, return error code
 ************************************************************************/
MV_CAMCTRL_API int __stdcall MV_CC_LSCCorrect(IN void* handle, IN OUT MV_CC_LSC_CORRECT_PARAM* pstLSCCorrectParam);

/************************************************************************
 *  @fn     MV_GIGE_ForceIp
 *  @brief  ǿ��IP���ýӿ������ã�������� MV_GIGE_ForceIpEx�ӿڣ�
 *  @param  handle���豸���
 *  @param  nIP               [IN]      ���õ�IP
 *  @return �����ش�����
 
 *  @fn     MV_GIGE_ForceIp
 *  @brief  Force IP (This interface is abandoned, it is recommended to use the MV_GIGE_ForceIpEx)
 *  @param  handle Handle
 *  @param  nIP               [IN]      IP to set
 *  @return Refer to error code
************************************************************************/
MV_CAMCTRL_API int __stdcall MV_GIGE_ForceIp(IN void* handle, unsigned int nIP);

/************************************************************************
 *  @fn     MV_CC_RegisterEventCallBack
 *  @brief  ע���¼��ص����ýӿ������ã�������� MV_CC_RegisterEventCallBackEx�ӿڣ�
 *  @param  handle���豸���
 *  @param  cbEvent           [IN]      �¼��ص�����ָ��
 *  @param  pUser             [IN]      �û��Զ������
 *  @return �����ش�����
 
 *  @fn     MV_CC_RegisterEventCallBack
 *  @brief  Register event callback (this interface has been deprecated and is recommended to be converted to the MV_CC_RegisterEventCallBackEx interface)
 *  @param  handle���豸���
 *  @param  cbEvent           [IN]      event callback pointer
 *  @param  pUser             [IN]      User defined value
 *  @return �����ش�����
************************************************************************/
MV_CAMCTRL_API int __stdcall MV_CC_RegisterEventCallBack(void* handle, void(__stdcall* cbEvent)(unsigned int nExternalEventId, void* pUser), void* pUser);

/***********************************************************************
 *  @fn         MV_CC_Display
 *  @brief      ��ʾͼ��ע����ʾ���ڣ��ڲ��Զ���ʾ����MV_CC_GetImageBuffer����ͬʱʹ�ã��������MV_CC_DisplayOneFrame�ӿڣ�
 *  @param       handle                 [IN]          ���
 *  @param       hWnd                   [IN]          ��ʾ���ھ��
 *  @return �ɹ�������MV_OK�����󣬷��ش�����
 
 *  @fn         MV_CC_Display
 *  @brief      Display one frame image, register display window, automatic display internally
 *  @param      handle                 [IN]          Handle
 *  @param      hWnd                   [IN]          Display Window Handle
 *  @return     Success, return MV_OK. Failure, return error code
 ***********************************************************************/
MV_CAMCTRL_API int __stdcall MV_CC_Display(IN void* handle, void* hWnd);

/************************************************************************
 *  @fn     MV_CAMCTRL_API int __stdcall MV_CC_GetIntValue(IN void* handle,
                                                           IN const char* strKey,
                                                           OUT MVCC_INTVALUE *pIntValue);
 *  @brief  ��ȡInteger����ֵ���������MV_CC_GetIntValueEx�ӿڣ�
 *  @param  void* handle                [IN]        ������
 *  @param  char* strKey                [IN]        ���Լ�ֵ�����ȡ������Ϣ��Ϊ"Width"
 *  @param  MVCC_INTVALUE* pstValue     [IN][OUT]   ���ظ��������й�������Խṹ��ָ��
 *  @return �ɹ�,����MV_OK,ʧ��,���ش�����
 
 *  @fn     MV_CAMCTRL_API int __stdcall MV_CC_GetIntValue(IN void* handle,
                                                           IN const char* strKey,
                                                           OUT MVCC_INTVALUE *pIntValue);
 *  @brief  Get Integer value
 *  @param  void* handle                [IN]        Handle
 *  @param  char* strKey                [IN]        Key value, for example, using "Width" to get width
 *  @param  MVCC_INTVALUE* pstValue     [IN][OUT]   Structure pointer of camera features
 *  @return Success, return MV_OK. Failure, return error code
 ************************************************************************/
MV_CAMCTRL_API int __stdcall MV_CC_GetIntValue(IN void* handle,IN const char* strKey,OUT MVCC_INTVALUE *pIntValue);

/************************************************************************
 *  @fn     MV_CAMCTRL_API int __stdcall MV_CC_SetIntValue(IN void* handle,
                                                           IN const char* strKey,
                                                           IN unsigned int nValue);
 *  @brief  ����Integer������ֵ���������MV_CC_SetIntValueEx�ӿڣ�
 *  @param  void* handle                [IN]        ������
 *  @param  char* strKey                [IN]        ���Լ�ֵ�����ȡ������Ϣ��Ϊ"Width"
 *          const unsigned int nValue   [IN]        ��Ҫ���õ����������ֵ
 *  @return �ɹ�,����MV_OK,ʧ��,���ش�����
 
 *  @fn     MV_CAMCTRL_API int __stdcall MV_CC_SetIntValue(IN void* handle,
                                                           IN const char* strKey,
                                                           IN unsigned int nValue);
 *  @brief  Set Integer value
 *  @param  void* handle                [IN]        Handle
 *  @param  char* strKey                [IN]        Key value, for example, using "Width" to set width
 *          const unsigned int nValue   [IN]        Feature value to set
 *  @return Success, return MV_OK. Failure, return error code
 ************************************************************************/
MV_CAMCTRL_API int __stdcall MV_CC_SetIntValue(IN void* handle,IN const char* strKey,IN unsigned int nValue);


/************************************************************************/
/* ���������ȡ�����ã���ģ������нӿ��ѷ���������ʹ�����ܽӿڴ���   */
/* Get and set camara parameters, all interfaces of this module will be replaced by general interface*/
/************************************************************************/
/************************************************************************
 *  @fn     MV_CAMCTRL_API int __stdcall MV_CC_GetWidth(IN void* handle, IN OUT MVCC_INTVALUE* pstValue);
 *  @brief  ��ȡͼ�����
 *  @param  void* handle                [IN]        ������
 *  @param  MVCC_INTVALUE* pstValue     [IN][OUT]   ���ظ��������й�������ȵ���Ϣ�ṹ��ָ��
 *          ���ص�pstValue�ṹ�������
 *                  unsigned int    nCurValue;      // ���������ǰ�Ŀ���ֵ
 *                  unsigned int    nMax;           // ��ʾ����������������õĿ���ֵ
 *                  unsigned int    nMin;           // ��ʾ�����������С�����õĿ���ֵ
 *                  unsigned int    nInc;           // ��ʾ������õĿ�������������nInc�ı�����������Ч
 *  @return �ɹ�,����MV_OK,�������Ӧ������Ϣ�Ľṹ��, ʧ��, ���ش�����
 *  
 *          �������ͽṹ������Ľӿڿɲ��մ˽ӿ�
 
 * @fn     MV_CAMCTRL_API int __stdcall MV_CC_GetWidth(IN void* handle, IN OUT MVCC_INTVALUE* pstValue);
 *  @brief  Get image width
 *  @param  void* handle                [IN]        Camera Handle
 *          MVCC_INTVALUE* pstValue     [IN][OUT]   Returns the information structure pointer about the camera's width for the caller
 *          The meaning of returns pstValue structure
 *                  unsigned int    nCurValue;      // Represents the current width value of the camera
 *                  unsigned int    nMax;           // Indicates the maximum settable width value allowed by the camera
 *                  unsigned int    nMin;           // Indicates the minimum settable width value allowed by the camera
 *                  unsigned int    nInc;           // Indicates that the width increment set by the camera must be a multiple of nInc, otherwise it is invalid
 *  @return Success, return MV_OK, and get the structure of the corresponding parameters. Failure, return error code
 *  
 *          Other Integer structure parameters interface can refer to this interface
 ************************************************************************/
MV_CAMCTRL_API int __stdcall MV_CC_GetWidth(IN void* handle, IN OUT MVCC_INTVALUE* pstValue);

/************************************************************************
*  @fn     MV_CAMCTRL_API int __stdcall MV_CC_SetWidth(IN void* handle, IN const unsigned int nValue);
*  @brief  ����ͼ�����
*  @param  void* handle                [IN]        ������
*          const unsigned int nValue   [IN]        ��Ҫ���õ�������ȵ�ֵ,ע��˿���ֵ������MV_CC_GetWidth�ӿڷ��ص�pstValue�е�nInc�ı����������óɹ�
*  @return �ɹ�,����MV_OK,����������Ƚ������Ϊ��Ӧֵ��ʧ��,���ش�����

* @fn     MV_CAMCTRL_API int __stdcall MV_CC_SetWidth(IN void* handle, IN const unsigned int nValue);
 *  @brief  Set image width
 *  @param  void* handle                [IN]        Camera Handle
 *          const unsigned int nValue   [IN]        To set the value of the camera width, note that the width value must be a multiple of nInc in the pstValue returned by the MV_CC_GetWidth interface
 *  @return Success, return MV_OK, and the camera width will change to the corresponding value. Failure, return error code
************************************************************************/
MV_CAMCTRL_API int __stdcall MV_CC_SetWidth(IN void* handle, IN const unsigned int nValue);

/************************************************************************
 *  @fn     MV_CAMCTRL_API int __stdcall MV_CC_GetHeight(IN void* handle, IN OUT MVCC_INTVALUE* pstValue);
 *  @brief  ��ȡͼ��߶�
 *  @param  void* handle                [IN]        ������
 *  @param  MVCC_INTVALUE* pstValue     [IN][OUT]   ���ظ��������й�����߶ȵ���Ϣ�ṹ��ָ��
 *  @return �ɹ�,����MV_OK,�����߶���Ϣ���ص��ṹ���У�ʧ��,���ش�����
 *  
 *          �ɲ��սӿ�MV_CC_GetWidth
 
 *  @fn     MV_CAMCTRL_API int __stdcall MV_CC_GetHeight(IN void* handle, IN OUT MVCC_INTVALUE* pstValue);
 *  @brief  Get image height
 *  @param  void* handle                [IN]        Camera handle
 *  @param  MVCC_INTVALUE* pstValue     [IN][OUT]   Return pointer of information structure related to camera height to user
 *  @return Success, return MV_OK, and return height information to the structure. Failure, return error code
 *  
 *          Refer to MV_CC_GetWidth
 ************************************************************************/
MV_CAMCTRL_API int __stdcall MV_CC_GetHeight(IN void* handle, IN OUT MVCC_INTVALUE* pstValue);

/************************************************************************
 *  @fn     MV_CAMCTRL_API int __stdcall MV_CC_SetHeight(IN void* handle, IN const unsigned int nValue);
 *  @brief  ����ͼ��߶�
 *  @param  void* handle                [IN]        ������
 *          const unsigned int nValue   [IN]        ��Ҫ���õ�������ȵ�ֵ,ע��˿���ֵ������MV_CC_GetWidth�ӿڷ��ص�pstValue�е�nInc�ı����������óɹ�
 *  @return �ɹ�,����MV_OK,��������߶Ƚ������Ϊ��Ӧֵ��ʧ��,���ش�����
 
 *  @fn     MV_CAMCTRL_API int __stdcall MV_CC_SetHeight(IN void* handle, IN const unsigned int nValue);
 *  @brief  Set image height
 *  @param  void* handle                [IN]        Camera Handle
 *          const unsigned int nValue   [IN]        Camera height value to set, note that this value must be times of nInc of pstValue returned by MV_CC_GetWidth
 *  @return Success, return MV_OK, and the camera height will change to the corresponding value. Failure, return error code
 ************************************************************************/
MV_CAMCTRL_API int __stdcall MV_CC_SetHeight(IN void* handle, IN const unsigned int nValue);

/************************************************************************
 *  @fn     MV_CAMCTRL_API int __stdcall MV_CC_GetAOIoffsetX(IN void* handle, IN OUT MVCC_INTVALUE* pstValue);
 *  @brief  ��ȡͼ��Xƫ��
 *  @param  void* handle                [IN]        ������
 *  @param  MVCC_INTVALUE* pstValue     [IN][OUT]   ���ظ��������й����Xƫ�Ƶ���Ϣ�ṹ��ָ��
 *  @return �ɹ�,����MV_OK,ʧ��,���ش�����
 *  
 *          �ɲ��սӿ�MV_CC_GetWidth
 
 *  @fn     MV_CAMCTRL_API int __stdcall MV_CC_GetAOIoffsetX(IN void* handle, IN OUT MVCC_INTVALUE* pstValue);
 *  @brief  Get image X offset
 *  @param  void* handle                [IN]        Camera Handle
 *  @param  MVCC_INTVALUE* pstValue     [IN][OUT]   Return pointer of information structure related to camera X offset to user
 *  @return Success, return MV_OK. Failure, return error code
 *  
 *          Refer to MV_CC_GetWidth
 ************************************************************************/
MV_CAMCTRL_API int __stdcall MV_CC_GetAOIoffsetX(IN void* handle, IN OUT MVCC_INTVALUE* pstValue);

/************************************************************************
 *  @fn     MV_CAMCTRL_API int __stdcall MV_CC_SetAOIoffsetX(IN void* handle, IN const unsigned int nValue);
 *  @brief  ����ͼ��AOIƫ��
 *  @param  void* handle                [IN]        ������
 *          const unsigned int nValue   [IN]        ��Ҫ���õ����AOI��ֵ
 *  @return �ɹ�,����MV_OK,�������AOIƫ�ƽ������Ϊ��Ӧֵ��ʧ��,���ش�����
 
 *  @fn     MV_CAMCTRL_API int __stdcall MV_CC_SetAOIoffsetX(IN void* handle, IN const unsigned int nValue);
 *  @brief  Set image X offset
 *  @param  void* handle                [IN]        Camera Handle
 *          const unsigned int nValue   [IN]        Camera X offset value to set
 *  @return Success, return MV_OK, and the camera X offset will change to the corresponding value. Failure, return error code
 ************************************************************************/
MV_CAMCTRL_API int __stdcall MV_CC_SetAOIoffsetX(IN void* handle, IN const unsigned int nValue);

/************************************************************************
 *  @fn     MV_CAMCTRL_API int __stdcall MV_CC_GetAOIoffsetY(IN void* handle, IN OUT MVCC_INTVALUE* pstValue);
 *  @brief  ��ȡͼ��Yƫ��
 *  @param  void* handle                [IN]        ������
 *  @param  MVCC_INTVALUE* pstValue     [IN][OUT]   ���ظ��������й����Yƫ�Ƶ���Ϣ�ṹ��ָ��
 *  @return �ɹ�,����MV_OK,ʧ��,���ش�����
 *  
 *          �ɲ��սӿ�MV_CC_GetWidth
 
 *  @fn     MV_CAMCTRL_API int __stdcall MV_CC_GetAOIoffsetY(IN void* handle, IN OUT MVCC_INTVALUE* pstValue);
 *  @brief  Get image Y offset
 *  @param  void* handle                [IN]        Camera Handle
 *  @param  MVCC_INTVALUE* pstValue     [IN][OUT]   Return pointer of information structure related to camera Y offset to user
 *  @return Success, return MV_OK. Failure, return error code
 *  
 *          Refer to MV_CC_GetWidth
 ************************************************************************/
MV_CAMCTRL_API int __stdcall MV_CC_GetAOIoffsetY(IN void* handle, IN OUT MVCC_INTVALUE* pstValue);

/************************************************************************
 *  @fn     MV_CAMCTRL_API int __stdcall MV_CC_SetAOIoffsetX(IN void* handle, IN const unsigned int nValue);
 *  @brief  ����ͼ��AOIƫ��
 *  @param  void* handle                [IN]        ������
 *          const unsigned int nValue   [IN]        ��Ҫ���õ����AOI��ֵ
 *  @return �ɹ�,����MV_OK,�������AOIƫ�ƽ������Ϊ��Ӧֵ��ʧ��,���ش�����
 
 *  @fn     MV_CAMCTRL_API int __stdcall MV_CC_SetAOIoffsetY(IN void* handle, IN const unsigned int nValue);
 *  @brief  Set image Y offset
 *  @param  void* handle                [IN]        Camera Handle
 *          const unsigned int nValue   [IN]        Camera Y offset value to set
 *  @return Success, return MV_OK, and the camera Y offset will change to the corresponding value. Failure, return error code
 ************************************************************************/
MV_CAMCTRL_API int __stdcall MV_CC_SetAOIoffsetY(IN void* handle, IN const unsigned int nValue);

/************************************************************************
 *  @fn     MV_CAMCTRL_API int __stdcall MV_CC_GetAutoExposureTimeLower(IN void* handle, IN OUT MVCC_INTVALUE* pstValue);
 *  @brief  ��ȡ�ع�����
 *  @param  void* handle                [IN]        ������
 *  @param  MVCC_INTVALUE* pstValue     [IN][OUT]   ���ظ��������й�����ع�ֵ���޽ṹ��ָ��
 *  @return �ɹ�,����MV_OK,ʧ��,���ش�����
 *  
 *          �ɲ��սӿ�MV_CC_GetWidth
 
 *  @fn     MV_CAMCTRL_API int __stdcall MV_CC_GetAutoExposureTimeLower(IN void* handle, IN OUT MVCC_INTVALUE* pstValue);
 *  @brief  Get exposure lower limit
 *  @param  void* handle                [IN]        Camera Handle
 *  @param  MVCC_INTVALUE* pstValue     [IN][OUT]   Return pointer of information structure related to camera exposure lower to user
 *  @return Success, return MV_OK. Failure, return error code
 *  
 *          Refer to MV_CC_GetWidth
 ************************************************************************/
MV_CAMCTRL_API int __stdcall MV_CC_GetAutoExposureTimeLower(IN void* handle, IN OUT MVCC_INTVALUE* pstValue);

/************************************************************************
 *  @fn     MV_CAMCTRL_API int __stdcall MV_CC_SetAutoExposureTimeLower(IN void* handle, IN const unsigned int nValue);
 *  @brief  �����ع�ֵ����
 *  @param  void* handle                [IN]        ������
 *          const unsigned int nValue   [IN]        ��Ҫ���õ��ع�ֵ����
 *  @return �ɹ�,����MV_OK,��������ع����޽������Ϊ��Ӧֵ��ʧ��,���ش�����
 
 *  @fn     MV_CAMCTRL_API int __stdcall MV_CC_SetAutoExposureTimeLower(IN void* handle, IN const unsigned int nValue);
 *  @brief  Set exposure lower limit
 *  @param  void* handle                [IN]        Camera Handle
 *          const unsigned int nValue   [IN]        Exposure lower to set
 *  @return Success, return MV_OK, and the camera exposure time lower limit value will change to the corresponding value. Failure, return error code
 ************************************************************************/
MV_CAMCTRL_API int __stdcall MV_CC_SetAutoExposureTimeLower(IN void* handle, IN const unsigned int nValue);

/************************************************************************
 *  @fn     MV_CAMCTRL_API int __stdcall MV_CC_GetAutoExposureTimeUpper(IN void* handle, IN OUT MVCC_INTVALUE* pstValue);
 *  @brief  ��ȡ�ع�����
 *  @param  void* handle                [IN]        ������
 *  @param  MVCC_INTVALUE* pstValue     [IN][OUT]   ���ظ��������й�����ع�ֵ���޽ṹ��ָ��
 *  @return �ɹ�,����MV_OK,ʧ��,���ش�����
 *  
 *          �ɲ��սӿ�MV_CC_GetWidth
 
 *  @fn     MV_CAMCTRL_API int __stdcall MV_CC_GetAutoExposureTimeUpper(IN void* handle, IN OUT MVCC_INTVALUE* pstValue);
 *  @brief  Get exposure upper limit
 *  @param  void* handle                [IN]        Camera Handle
 *  @param  MVCC_INTVALUE* pstValue     [IN][OUT]   Return pointer of information structure related to camera exposure upper to user
 *  @return Success, return MV_OK. Failure, return error code
 *  
 *          Refer to MV_CC_GetWidth
 ************************************************************************/
MV_CAMCTRL_API int __stdcall MV_CC_GetAutoExposureTimeUpper(IN void* handle, IN OUT MVCC_INTVALUE* pstValue);

/************************************************************************
 *  @fn     MV_CAMCTRL_API int __stdcall MV_CC_SetAutoExposureTimeUpper(IN void* handle, IN const unsigned int nValue);
 *  @brief  �����ع�ֵ����
 *  @param  void* handle                [IN]        ������
 *          const unsigned int nValue   [IN]        ��Ҫ���õ��ع�ֵ����
 *  @return �ɹ�,����MV_OK,��������ع����޽������Ϊ��Ӧֵ��ʧ��,���ش�����
 
 *  @fn     MV_CAMCTRL_API int __stdcall MV_CC_SetAutoExposureTimeUpper(IN void* handle, IN const unsigned int nValue);
 *  @brief  Set exposure upper limit
 *  @param  void* handle                [IN]        Camera Handle
 *          const unsigned int nValue   [IN]        Exposure upper to set
 *  @return Success, return MV_OK, and the camera exposure time upper limit value will change to the corresponding value. Failure, return error code
 ************************************************************************/
MV_CAMCTRL_API int __stdcall MV_CC_SetAutoExposureTimeUpper(IN void* handle, IN const unsigned int nValue);

/************************************************************************
 *  @fn     MV_CAMCTRL_API int __stdcall MV_CC_GetBrightness(IN void* handle, IN OUT MVCC_INTVALUE* pstValue);
 *  @brief  ��ȡ����ֵ
 *  @param  void* handle                [IN]        ������
 *  @param  MVCC_INTVALUE* pstValue     [IN][OUT]   ���ظ��������й�������Ƚṹ��ָ��
 *  @return �ɹ�,����MV_OK,ʧ��,���ش�����
 *  
 *          �ɲ��սӿ�MV_CC_GetWidth
 
 *  @fn     MV_CAMCTRL_API int __stdcall MV_CC_GetBrightness(IN void* handle, IN OUT MVCC_INTVALUE* pstValue);
 *  @brief  Get brightness
 *  @param  void* handle                [IN]        Camera Handle
 *  @param  MVCC_INTVALUE* pstValue     [IN][OUT]   Return pointer of information structure related to camera brightness to user
 *  @return Success, return MV_OK. Failure, return error code
 *  
 *          Refer to MV_CC_GetWidth
 ************************************************************************/
MV_CAMCTRL_API int __stdcall MV_CC_GetBrightness(IN void* handle, IN OUT MVCC_INTVALUE* pstValue);

/************************************************************************
 *  @fn     MV_CAMCTRL_API int __stdcall MV_CC_SetBrightness(IN void* handle, IN const unsigned int nValue);
 *  @brief  ��������ֵ
 *  @param  void* handle                [IN]        ������
 *          const unsigned int nValue   [IN]        ��Ҫ���õ�����ֵ
 *  @return �ɹ�,����MV_OK,����������Ƚ������Ϊ��Ӧֵ��ʧ��,���ش�����
 
 *  @fn     MV_CAMCTRL_API int __stdcall MV_CC_SetBrightness(IN void* handle, IN const unsigned int nValue);
 *  @brief  Set brightness
 *  @param  void* handle                [IN]        Camera Handle
 *          const unsigned int nValue   [IN]        Brightness upper to set
 *  @return Success, return MV_OK, and the camera brightness value will change to the corresponding value. Failure, return error code
 ************************************************************************/
MV_CAMCTRL_API int __stdcall MV_CC_SetBrightness(IN void* handle, IN const unsigned int nValue);

/************************************************************************
 *  @fn     MV_CAMCTRL_API int __stdcall MV_CC_GetFrameRate(IN void* handle, IN OUT MVCC_FLOATVALUE* pstValue);
 *  @brief  ��ȡ֡��
 *  @param  void* handle                [IN]        ������
 *          MVCC_FLOATVALUE* pstValue   [IN][OUT]   ���ظ��������й����֡�ʵ���Ϣ�ṹ��ָ��
 *          ���ص�pstValue�ṹ�������
 *                                      float           fCurValue;      // ��ʾ�����ǰ��֡��
 *                                      float           fMax;           // ��ʾ����������õ����֡��
 *                                      float           fMin;           // ��ʾ����������õ���С֡��
 *  @return �ɹ�,����MV_OK,�������Ӧ������Ϣ�Ľṹ��, ʧ��, ���ش�����
 *  
 *          ���������ͽṹ������Ľӿڿɲ��մ˽ӿ�
 
 * @fn     MV_CAMCTRL_API int __stdcall MV_CC_GetFrameRate(IN void* handle, IN OUT MVCC_FLOATVALUE* pstValue);
 *  @brief  Get Frame Rate
 *  @param  void* handle                [IN]        Camera Handle
 *          MVCC_FLOATVALUE* pstValue   [IN][OUT]   Return pointer of information structure related to camera frame rate to user
 *          The meaning of returns pstValue structure
 *                                      float           fCurValue;      // Indicates the current frame rate of the camera
 *                                      float           fMax;           // Indicates the maximum frame rate allowed by the camera
 *                                      float           fMin;           // Indicates the minimum frame rate allowed by the camera
 *  @return Success, return MV_OK, and get the structure of the corresponding parameters. Failure, return error code
 *  
 *          Other interface of Float structure parameters can refer to this interface
 ************************************************************************/
MV_CAMCTRL_API int __stdcall MV_CC_GetFrameRate(IN void* handle, IN OUT MVCC_FLOATVALUE* pstValue);

/************************************************************************
 *  @fn     MV_CAMCTRL_API int __stdcall MV_CC_SetFrameRate(IN void* handle, IN const float fValue);
 *  @brief  ����֡��
 *  @param  void* handle                [IN]        ������
 *          const float fValue          [IN]        ��Ҫ���õ����֡��
 *  @return �ɹ�,����MV_OK,�������֡�ʽ������Ϊ��Ӧֵ��ʧ��,���ش�����
 
 * @fn     MV_CAMCTRL_API int __stdcall MV_CC_SetFrameRate(IN void* handle, IN const float fValue);
 *  @brief  Set frame rate
 *  @param  void* handle                [IN]        Camera Handle
 *          const float fValue          [IN]        Camera frame rate to set 
 *  @return Success, return MV_OK, and camera frame rate will be changed to the corresponding value. Failure, return error code
 ************************************************************************/
MV_CAMCTRL_API int __stdcall MV_CC_SetFrameRate(IN void* handle, IN const float fValue);

/************************************************************************
 *  @fn     MV_CAMCTRL_API int __stdcall MV_CC_GetGain(IN void* handle, IN OUT MVCC_FLOATVALUE* pstValue);
 *  @brief  ��ȡ����
 *  @param  void* handle                [IN]        ������
 *          MVCC_FLOATVALUE* pstValue   [IN][OUT]   ���ظ��������й�����������Ϣ�ṹ��ָ��
 *          ���ص�pstValue�ṹ�������
 *                                      float           fCurValue;      // ��ʾ�����ǰ��֡��
 *                                      float           fMax;           // ��ʾ����������õ����֡��
 *                                      float           fMin;           // ��ʾ����������õ���С֡��
 *  @return �ɹ�,����MV_OK,�������Ӧ������Ϣ�Ľṹ��, ʧ��, ���ش�����
 *  
 *          ���������ͽṹ������Ľӿڿɲ��մ˽ӿ�
 
 *  @fn     MV_CAMCTRL_API int __stdcall MV_CC_GetGain(IN void* handle, IN OUT MVCC_FLOATVALUE* pstValue);
 *  @brief  Get Gain
 *  @param  void* handle                [IN]        Camera Handle
 *          MVCC_FLOATVALUE* pstValue   [IN][OUT]   Return pointer of information structure related to gain to user
 *  @return Success, return MV_OK, and get the structure of the corresponding parameters. Failure, return error code
 *                                      float           fCurValue;      // Camera current gain
 *                                      float           fMax;           // The maximum gain camera allowed
 *                                      float           fMin;           // The minimum gain camera allowed
 *  @return Success, return MV_OK, and get the structure of the corresponding parameters. Failure, return error code
 *  
 *          Other interface of Float structure parameters can refer to this interface
 ************************************************************************/
MV_CAMCTRL_API int __stdcall MV_CC_GetGain(IN void* handle, IN OUT MVCC_FLOATVALUE* pstValue);

/************************************************************************
 *  @fn     MV_CAMCTRL_API int __stdcall MV_CC_SetGain(IN void* handle, IN const float fValue);
 *  @brief  ����֡��
 *  @param  void* handle                [IN]        ������
 *          const float fValue          [IN]        ��Ҫ���õ����֡��
 *  @return �ɹ�,����MV_OK,�������֡�ʽ������Ϊ��Ӧֵ��ʧ��,���ش�����
 
 *  @fn     MV_CAMCTRL_API int __stdcall MV_CC_SetGain(IN void* handle, IN const float fValue);
 *  @brief  Set Gain
 *  @param  void* handle                [IN]        Camera Handle
 *          const float fValue          [IN]        Gain value to set
 *  @return Success, return MV_OK, and the camera gain value will change to the corresponding value. Failure, return error code
 ************************************************************************/
MV_CAMCTRL_API int __stdcall MV_CC_SetGain(IN void* handle, IN const float fValue);

/************************************************************************
 *  @fn     MV_CAMCTRL_API int __stdcall MV_CC_GetExposureTime(IN void* handle, IN OUT MVCC_FLOATVALUE* pstValue);
 *  @brief  ��ȡ�ع�ʱ��
 *  @param  void* handle                [IN]        ������
 *          MVCC_FLOATVALUE* pstValue   [IN][OUT]   ���ظ��������й�����ع�ʱ�����Ϣ�ṹ��ָ��
 *          ���ص�pstValue�ṹ�������
 *                                      float           fCurValue;      // ��ʾ�����ǰ��֡��
 *                                      float           fMax;           // ��ʾ����������õ����֡��
 *                                      float           fMin;           // ��ʾ����������õ���С֡��
 *  @return �ɹ�,����MV_OK,�������Ӧ������Ϣ�Ľṹ��, ʧ��, ���ش�����
 *  
 *          ���������ͽṹ������Ľӿڿɲ��մ˽ӿ�
 
 *  @fn     MV_CAMCTRL_API int __stdcall MV_CC_GetExposureTime(IN void* handle, IN OUT MVCC_FLOATVALUE* pstValue);
 *  @brief  Get exposure time
 *  @param  void* handle                [IN]        Camera Handle
 *          MVCC_FLOATVALUE* pstValue   [IN][OUT]   Return pointer of information structure related to exposure time to user
 *  @return Success, return MV_OK, and get the structure of the corresponding parameters. Failure, return error code
 *                                      float           fCurValue;      // Camera current exposure time
 *                                      float           fMax;           // The maximum exposure time camera allowed
 *                                      float           fMin;           // The minimum exposure time camera allowed
 *  @return Success, return MV_OK, and get the structure of the corresponding parameters. Failure, return error code
 *  
 *          Other interface of Float structure parameters can refer to this interface
 ************************************************************************/
MV_CAMCTRL_API int __stdcall MV_CC_GetExposureTime(IN void* handle, IN OUT MVCC_FLOATVALUE* pstValue);

/************************************************************************
 *  @fn     MV_CAMCTRL_API int __stdcall MV_CC_SetExposureTime(IN void* handle, IN const float fValue);
 *  @brief  �����ع�ʱ��
 *  @param  void* handle                [IN]        ������
 *          const float fValue          [IN]        ��Ҫ���õ����֡��
 *  @return �ɹ�,����MV_OK,�������֡�ʽ������Ϊ��Ӧֵ��ʧ��,���ش�����
 
 *  @fn     MV_CAMCTRL_API int __stdcall MV_CC_SetExposureTime(IN void* handle, IN const float fValue);
 *  @brief  Set exposure time
 *  @param  void* handle                [IN]        Camera Handle
 *          const float fValue          [IN]        Exposure time to set
 *  @return Success, return MV_OK, and the camera exposure time value will change to the corresponding value. Failure, return error code
 ************************************************************************/
MV_CAMCTRL_API int __stdcall MV_CC_SetExposureTime(IN void* handle, IN const float fValue);

/************************************************************************
 *  @fn     MV_CAMCTRL_API int __stdcall MV_CC_GetPixelFormat(IN void* handle, IN OUT MVCC_ENUMVALUE* pstValue);
 *  @brief  ��ȡ���ظ�ʽ
 *  @param  void* handle                [IN]        ������
 *          MVCC_ENUMVALUE* pstValue    [IN][OUT]   ���ظ������ߵ��й����ظ�ʽ����Ϣ�ṹ��ָ��
 *          ���ص�pstValue�ṹ�������
 *          unsigned int    nCurValue;                              //  �����ǰ�����ظ�ʽ����ö������,����˵PixelType_Gvsp_Mono8, �����õ���������ֵ,������ֵ����PixelType.h��MvGvspPixelTypeö������
 *          unsigned int    nSupportedNum;                          //  ���֧�ֵ����ظ�ʽ�ĸ���
 *          unsigned int    nSupportValue[MV_MAX_XML_SYMBOLIC_NUM]; //  �������֧�ֵ����ظ�ʽ��Ӧ������ֵ�б�������Ҫ�������ظ�ʽʱ��������������������е�һ�֣�������Ч
 *  @return �ɹ�,����MV_OK,�������Ӧ������Ϣ�Ľṹ��, ʧ��, ���ش�����
 *  
            ����ö�����Ͳ����ӿڿɲ��մ˽ӿڣ��й���Ӧ������ö�����Ͷ�Ӧ������ֵ�����PixelType.h �� CameraParams.h����Ӧ�Ķ���
 
 * @fn     MV_CAMCTRL_API int __stdcall MV_CC_GetPixelFormat(IN void* handle, IN OUT MVCC_ENUMVALUE* pstValue);
 *  @brief  Get Pixel Format
 *  @param  void* handle                [IN]        Camera Handle
 *          MVCC_ENUMVALUE* pstValue    [IN][OUT]   Returns the information structure pointer about pixel format for the caller
 *          The meaning of returns pstValue structure
 *          unsigned int    nCurValue;                              //  The current pixel format of the camera, is the enumeration type, such as PixelType_Gvsp_Mono8, here is the integer value, the specific value please refer to MvGvspPixelType enumeration type in PixelType.h
 *          unsigned int    nSupportedNum;                          //  Number of pixel formats supported by the camera
 *          unsigned int    nSupportValue[MV_MAX_XML_SYMBOLIC_NUM]; //  The integer values list correspond to all supported pixel formats of the camera, followed by when set the pixel format, the parameter must be one of this list, otherwise invalid
 *  @return Success, return MV_OK, and get the structure of the corresponding parameters. Failure, return error code
 *  
            Other interface of Enumeration structure parameters can refer to this interface, look for the corresponding definition in PixelType.h and CameraParams.h for the integer values of the enum type parameter
 ************************************************************************/
MV_CAMCTRL_API int __stdcall MV_CC_GetPixelFormat(IN void* handle, IN OUT MVCC_ENUMVALUE* pstValue);

/************************************************************************
 *  @fn     MV_CAMCTRL_API int __stdcall MV_CC_SetPixelFormat(IN void* handle, IN const unsigned int nValue);
 *  @brief  �������ظ�ʽ
 *  @param  void* handle                [IN]        ������
 *          const unsigned int nValue   [IN]        Ҫ���õ����ظ�ʽ��Ӧ������ֵ�����ô˽ӿ�ʱ����ֱ����дö��ֵ����MV_CC_SetPixelFormat(m_handle, PixelType_Gvsp_RGB8_Packed);
 *  @return �ɹ�,����MV_OK,����������ظ�ʽ�������Ϊ��Ӧֵ��ʧ��,���ش�����
 *  
 *          Ҫ���õ�ö�����ͱ�����Get�ӿڷ��ص�nSupportValue[MV_MAX_XML_SYMBOLIC_NUM]�е�һ�֣������ʧ��
 
 * @fn     MV_CAMCTRL_API int __stdcall MV_CC_SetPixelFormat(IN void* handle, IN const unsigned int nValue);
 *  @brief  Set Pixel Format
 *  @param  void* handle                [IN]        Camera Handle
 *          const unsigned int nValue   [IN]        The corresponding integer value for pixel format to be set, when calling this interface can be directly filled in enumeration values, such as MV_CC_SetPixelFormat(m_handle, PixelType_Gvsp_RGB8_Packed);
 *  @return Success, return MV_OK, and the camera pixel format will change to the corresponding value. Failure, return error code
 *  
 *          Other interface of Enumeration structure parameters can refer to this interface, the enumeration type to be set must be one of the nSupportValue [MV_MAX_XML_SYMBOLIC_NUM] returned by the Get interface, otherwise it will fail
 ************************************************************************/
MV_CAMCTRL_API int __stdcall MV_CC_SetPixelFormat(IN void* handle, IN const unsigned int nValue);

/************************************************************************
 *  @fn     MV_CAMCTRL_API int __stdcall MV_CC_GetAcquisitionMode(IN void* handle, IN OUT MVCC_ENUMVALUE* pstValue);
 *  @brief  ��ȡ�ɼ�ģʽ
 *  @param  void* handle                [IN]        ������
 *          MVCC_ENUMVALUE* pstValue    [IN][OUT]   ���ظ������ߵ��йزɼ�ģʽ����Ϣ�ṹ��ָ��
 *  @return �ɹ�,����MV_OK,�������Ӧ������Ϣ�Ľṹ��, ʧ��, ���ش�����
 *  
            �ɲ��սӿ�MV_CC_GetPixelFormat���ο� CameraParam.h �е� MV_CAM_ACQUISITION_MODE ����
 
 *  @fn     MV_CAMCTRL_API int __stdcall MV_CC_GetAcquisitionMode(IN void* handle, IN OUT MVCC_ENUMVALUE* pstValue);
 *  @brief  Get acquisition mode
 *  @param  void* handle                [IN]        Handle
 *          MVCC_ENUMVALUE* pstValue    [IN][OUT]   Structure pointer of acquisition mode
 *  @return Success, return MV_OK, and get the structure of the corresponding parameters. Failure, return error code
 *  
            Refer to MV_CC_GetPixelFormat and definition of MV_CAM_ACQUISITION_MODE in CameraParam.h
 ************************************************************************/
MV_CAMCTRL_API int __stdcall MV_CC_GetAcquisitionMode(IN void* handle, IN OUT MVCC_ENUMVALUE* pstValue);

/************************************************************************
 *  @fn     MV_CAMCTRL_API int __stdcall MV_CC_SetAcquisitionMode(IN void* handle, IN const unsigned int nValue);
 *  @brief  �������ظ�ʽ
 *  @param  void* handle                [IN]        ������
 *          const unsigned int nValue   [IN]        Ҫ���õĲɼ�ģʽ��Ӧ������ֵ
 *  @return �ɹ�,����MV_OK,��������ɼ�ģʽ�������Ϊ��Ӧֵ��ʧ��,���ش�����
 
 *  @fn     MV_CAMCTRL_API int __stdcall MV_CC_SetAcquisitionMode(IN void* handle, IN const unsigned int nValue);
 *  @brief  Set acquisition mode
 *  @param  void* handle                [IN]        Handle
 *          const unsigned int nValue   [IN]        Integer value to set corresponding to acquisition mode
 *  @return Success, return MV_OK, and the camera acquisition mode will change to the corresponding value. Failure, return error code
 ************************************************************************/
MV_CAMCTRL_API int __stdcall MV_CC_SetAcquisitionMode(IN void* handle, IN const unsigned int nValue);

/************************************************************************
 *  @fn     MV_CAMCTRL_API int __stdcall MV_CC_GetGainMode(IN void* handle, IN OUT MVCC_ENUMVALUE* pstValue);
 *  @brief  ��ȡ����ģʽ
 *  @param  void* handle                [IN]        ������
 *          MVCC_ENUMVALUE* pstValue    [IN][OUT]   ���ظ������ߵ��й�����ģʽ����Ϣ�ṹ��ָ��
 *  @return �ɹ�,����MV_OK,�������Ӧ������Ϣ�Ľṹ��, ʧ��, ���ش�����
 *  
            �ɲ��սӿ�MV_CC_GetPixelFormat���ο� CameraParam.h �е� MV_CAM_GAIN_MODE ����
 
 *  @fn     MV_CAMCTRL_API int __stdcall MV_CC_GetGainMode(IN void* handle, IN OUT MVCC_ENUMVALUE* pstValue);
 *  @brief  Get gain mode
 *  @param  void* handle                [IN]        Handle
 *          MVCC_ENUMVALUE* pstValue    [IN][OUT]    Structure pointer of gain mode
 *  @return Success, return MV_OK, and get the structure of the corresponding parameters. Failure, return error code
 *  
            Refer to MV_CC_GetPixelFormat and definition of MV_CAM_GAIN_MODE in CameraParam.h
 ************************************************************************/
MV_CAMCTRL_API int __stdcall MV_CC_GetGainMode(IN void* handle, IN OUT MVCC_ENUMVALUE* pstValue);

/************************************************************************
 *  @fn     MV_CAMCTRL_API int __stdcall MV_CC_SetGainMode(IN void* handle, IN const unsigned int nValue);
 *  @brief  ��������ģʽ
 *  @param  void* handle                [IN]        ������
 *          const unsigned int nValue   [IN]        Ҫ���õ�����ģʽ��Ӧ������ֵ
 *  @return �ɹ�,����MV_OK,�����������ģʽ�������Ϊ��Ӧֵ��ʧ��,���ش�����
 
 *  @fn     MV_CAMCTRL_API int __stdcall MV_CC_SetGainMode(IN void* handle, IN const unsigned int nValue);
 *  @brief  Set gain mode
 *  @param  void* handle                [IN]        Handle
 *          const unsigned int nValue   [IN]        Integer value to set corresponding to gain mode
 *  @return Success, return MV_OK, and the camera gain mode will change to the corresponding value. Failure, return error code
 ************************************************************************/
MV_CAMCTRL_API int __stdcall MV_CC_SetGainMode(IN void* handle, IN const unsigned int nValue);

/************************************************************************
 *  @fn     MV_CAMCTRL_API int __stdcall MV_CC_GetExposureAutoMode(IN void* handle, IN OUT MVCC_ENUMVALUE* pstValue);
 *  @brief  ��ȡ�Զ��ع�ģʽ
 *  @param  void* handle                [IN]        ������
 *          MVCC_ENUMVALUE* pstValue    [IN][OUT]   ���ظ������ߵ��й��Զ��ع�ģʽ����Ϣ�ṹ��ָ��
 *  @return �ɹ�,����MV_OK,�������Ӧ������Ϣ�Ľṹ��, ʧ��, ���ش�����
 *  
            �ɲ��սӿ�MV_CC_GetPixelFormat���ο� CameraParam.h �е� MV_CAM_EXPOSURE_AUTO_MODE ����
 
 *  @fn     MV_CAMCTRL_API int __stdcall MV_CC_GetExposureAutoMode(IN void* handle, IN OUT MVCC_ENUMVALUE* pstValue);
 *  @brief  Get auto exposure mode
 *  @param  void* handle                [IN]        Handle
 *          MVCC_ENUMVALUE* pstValue    [IN][OUT]   Structure pointer of auto exposure mode
 *  @return Success, return MV_OK, and get the structure of the corresponding parameters. Failure, return error code
 *  
            Refer to MV_CC_GetPixelFormat and definition of MV_CAM_EXPOSURE_AUTO_MODE in CameraParam.h
 ************************************************************************/
MV_CAMCTRL_API int __stdcall MV_CC_GetExposureAutoMode(IN void* handle, IN OUT MVCC_ENUMVALUE* pstValue);

/************************************************************************
 *  @fn     MV_CAMCTRL_API int __stdcall MV_CC_SetExposureAutoMode(IN void* handle, IN const unsigned int nValue);
 *  @brief  �����Զ��ع�ģʽ
 *  @param  void* handle                [IN]        ������
 *          const unsigned int nValue   [IN]        Ҫ���õ��Զ��ع�ģʽ��Ӧ������ֵ
 *  @return �ɹ�,����MV_OK,��������Զ��ع�ģʽ�������Ϊ��Ӧֵ��ʧ��,���ش�����
 
 *  @fn     MV_CAMCTRL_API int __stdcall MV_CC_SetExposureAutoMode(IN void* handle, IN const unsigned int nValue);
 *  @brief  Set auto exposure mode
 *  @param  void* handle                [IN]        Handle
 *          const unsigned int nValue   [IN]        Integer value to set corresponding to auto exposure mode
 *  @return Success, return MV_OK, and the camera auto exposure mode will change to the corresponding value. Failure, return error code
 ************************************************************************/
MV_CAMCTRL_API int __stdcall MV_CC_SetExposureAutoMode(IN void* handle, IN const unsigned int nValue);

/************************************************************************
 *  @fn     MV_CAMCTRL_API int __stdcall MV_CC_GetTriggerMode(IN void* handle, IN OUT MVCC_ENUMVALUE* pstValue);
 *  @brief  ��ȡ����ģʽ
 *  @param  void* handle                [IN]        ������
 *          MVCC_ENUMVALUE* pstValue    [IN][OUT]   ���ظ������ߵ��йش���ģʽ����Ϣ�ṹ��ָ��
 *  @return �ɹ�,����MV_OK,�������Ӧ������Ϣ�Ľṹ��, ʧ��, ���ش�����
 *  
            �ɲ��սӿ�MV_CC_GetPixelFormat���ο� CameraParam.h �е� MV_CAM_TRIGGER_MODE ����
 
 *  @fn     MV_CAMCTRL_API int __stdcall MV_CC_GetTriggerMode(IN void* handle, IN OUT MVCC_ENUMVALUE* pstValue);
 *  @brief  Get trigger mode
 *  @param  void* handle                [IN]        Handle
 *          MVCC_ENUMVALUE* pstValue    [IN][OUT]   Structure pointer of trigger mode
 *  @return Success, return MV_OK, and get the structure of the corresponding parameters. Failure, return error code
 *  
            Refer to MV_CC_GetPixelFormat and definition of MV_CAM_TRIGGER_MODE in CameraParam.h
 ************************************************************************/
MV_CAMCTRL_API int __stdcall MV_CC_GetTriggerMode(IN void* handle, IN OUT MVCC_ENUMVALUE* pstValue);

/************************************************************************
 *  @fn     MV_CAMCTRL_API int __stdcall MV_CC_SetTriggerMode(IN void* handle, IN const unsigned int nValue);
 *  @brief  ���ô���ģʽ
 *  @param  void* handle                [IN]        ������
 *          const unsigned int nValue   [IN]        Ҫ���õĴ���ģʽ��Ӧ������ֵ
 *  @return �ɹ�,����MV_OK,�����������ģʽ�������Ϊ��Ӧֵ��ʧ��,���ش�����
 
 *  @fn     MV_CAMCTRL_API int __stdcall MV_CC_SetTriggerMode(IN void* handle, IN const unsigned int nValue);
 *  @brief  Set trigger mode
 *  @param  void* handle                [IN]        Handle
 *          const unsigned int nValue   [IN]        Integer value to set corresponding to trigger mode
 *  @return Success, return MV_OK, and the camera trigger mode will change to the corresponding value. Failure, return error code
 ************************************************************************/
MV_CAMCTRL_API int __stdcall MV_CC_SetTriggerMode(IN void* handle, IN const unsigned int nValue);

/************************************************************************
 *  @fn     MV_CAMCTRL_API int __stdcall MV_CC_GetTriggerDelay(IN void* handle, IN OUT MVCC_FLOATVALUE* pstValue);
 *  @brief  ��ȡ������ʱ
 *  @param  void* handle                [IN]        ������
 *          MVCC_FLOATVALUE* pstValue   [IN][OUT]   ���ظ��������й����������ʱ����Ϣ�ṹ��ָ��
 *  @return �ɹ�,����MV_OK,�������Ӧ������Ϣ�Ľṹ��, ʧ��, ���ش�����
 *  
 *          �ɲ��սӿ�MV_CC_GetFrameRate
 
 *  @fn     MV_CAMCTRL_API int __stdcall MV_CC_GetTriggerDelay(IN void* handle, IN OUT MVCC_FLOATVALUE* pstValue);
 *  @brief  Get tigger delay
 *  @param  void* handle                [IN]        Handle
 *          MVCC_FLOATVALUE* pstValue   [IN][OUT]   Structure pointer of trigger delay
 *  @return Success, return MV_OK, and get the structure of the corresponding parameters. Failure, return error code
 *  
 *          Refer to MV_CC_GetFrameRate
 ************************************************************************/
MV_CAMCTRL_API int __stdcall MV_CC_GetTriggerDelay(IN void* handle, IN OUT MVCC_FLOATVALUE* pstValue);

/************************************************************************
 *  @fn     MV_CAMCTRL_API int __stdcall MV_CC_SetTriggerDelay(IN void* handle, IN const float fValue);
 *  @brief  ���ô�����ʱ
 *  @param  void* handle                [IN]        ������
 *          const float fValue          [IN]        ��Ҫ���õ����������ʱ
 *  @return �ɹ�,����MV_OK,�������������ʱ�������Ϊ��Ӧֵ��ʧ��,���ش�����
 
 *  @fn     MV_CAMCTRL_API int __stdcall MV_CC_SetTriggerDelay(IN void* handle, IN const float fValue);
 *  @brief  Set tigger delay
 *  @param  void* handle                [IN]        Handle
 *          const float fValue          [IN]        Trigger delay to set
 *  @return Success, return MV_OK, and the camera trigger delay will change to the corresponding value. Failure, return error code
 ************************************************************************/
MV_CAMCTRL_API int __stdcall MV_CC_SetTriggerDelay(IN void* handle, IN const float fValue);

/************************************************************************
 *  @fn     MV_CAMCTRL_API int __stdcall MV_CC_GetTriggerSource(IN void* handle, IN OUT MVCC_ENUMVALUE* pstValue);
 *  @brief  ��ȡ����Դ
 *  @param  void* handle                [IN]        ������
 *          MVCC_ENUMVALUE* pstValue    [IN][OUT]   ���ظ������ߵ��йش���Դ����Ϣ�ṹ��ָ��
 *  @return �ɹ�,����MV_OK,�������Ӧ������Ϣ�Ľṹ��, ʧ��, ���ش�����
 *  
            �ɲ��սӿ�MV_CC_GetPixelFormat���ο� CameraParam.h �е� MV_CAM_TRIGGER_SOURCE ����
 
 *  @fn     MV_CAMCTRL_API int __stdcall MV_CC_GetTriggerSource(IN void* handle, IN OUT MVCC_ENUMVALUE* pstValue);
 *  @brief  Get trigger source
 *  @param  void* handle                [IN]        Handle
 *          MVCC_ENUMVALUE* pstValue    [IN][OUT]   Structure pointer of trigger source
 *  @return Success, return MV_OK, and get the structure of the corresponding parameters. Failure, return error code
 *  
            Refer to MV_CC_GetPixelFormat and definition of MV_CAM_TRIGGER_SOURCE in CameraParam.h
 ************************************************************************/
MV_CAMCTRL_API int __stdcall MV_CC_GetTriggerSource(IN void* handle, IN OUT MVCC_ENUMVALUE* pstValue);

/************************************************************************
 *  @fn     MV_CAMCTRL_API int __stdcall MV_CC_SetTriggerSource(IN void* handle, IN const unsigned int nValue);
 *  @brief  ���ô���Դ
 *  @param  void* handle                [IN]        ������
 *          const unsigned int nValue   [IN]        Ҫ���õĴ���Դ��Ӧ������ֵ
 *  @return �ɹ�,����MV_OK,�����������Դ�������Ϊ��Ӧֵ��ʧ��,���ش�����
 
 *  @fn     MV_CAMCTRL_API int __stdcall MV_CC_SetTriggerSource(IN void* handle, IN const unsigned int nValue);
 *  @brief  Set trigger source
 *  @param  void* handle                [IN]        Handle
 *          const unsigned int nValue   [IN]        Integer value to set corresponding to trigger source
 *  @return Success, return MV_OK, and the camera trigger source will change to the corresponding value. Failure, return error code
 ************************************************************************/
MV_CAMCTRL_API int __stdcall MV_CC_SetTriggerSource(IN void* handle, IN const unsigned int nValue);

/************************************************************************
 *  @fn     MV_CAMCTRL_API int __stdcall MV_CC_TriggerSoftwareExecute(IN void* handle);
 *  @brief  ������һ�Σ��ӿڽ�����ѡ��Ĵ���ԴΪ��������ʱ��Ч��
 *  @param  void* handle                [IN]        ������
 *  @return �ɹ�,����MV_OK, ʧ��,���ش�����
 
 *  @fn     MV_CAMCTRL_API int __stdcall MV_CC_TriggerSoftwareExecute(IN void* handle);
 *  @brief  Execute software trigger once (this interface only valid when the trigger source is set to software)
 *  @param  void* handle                [IN]        Handle
 *  @return Success, return MV_OK. Failure, return error code
 ************************************************************************/
MV_CAMCTRL_API int __stdcall MV_CC_TriggerSoftwareExecute(IN void* handle);

/************************************************************************
 *  @fn     MV_CAMCTRL_API int __stdcall MV_CC_GetGammaSelector(IN void* handle, IN OUT MVCC_ENUMVALUE* pstValue);
 *  @brief  ��ȡGamma����
 *  @param  void* handle                [IN]        ������
 *          MVCC_ENUMVALUE* pstValue    [IN][OUT]   ���ظ������ߵ��й�Gamma���͵���Ϣ�ṹ��ָ��
 *  @return �ɹ�,����MV_OK,�������Ӧ������Ϣ�Ľṹ��, ʧ��, ���ش�����
 *  
            �ɲ��սӿ�MV_CC_GetPixelFormat���ο� CameraParam.h �е� MV_CAM_GAMMA_SELECTOR ����
 
 *  @fn     MV_CAMCTRL_API int __stdcall MV_CC_GetGammaSelector(IN void* handle, IN OUT MVCC_ENUMVALUE* pstValue);
 *  @brief  Get Gamma mode
 *  @param  void* handle                [IN]        Handle
 *          MVCC_ENUMVALUE* pstValue    [IN][OUT]   Structure pointer of gamma mode
 *  @return Success, return MV_OK, and get the structure of the corresponding parameters. Failure, return error code
 *  
            Refer to MV_CC_GetPixelFormat and definition of MV_CAM_GAMMA_SELECTOR in CameraParam.h
 ************************************************************************/
MV_CAMCTRL_API int __stdcall MV_CC_GetGammaSelector(IN void* handle, IN OUT MVCC_ENUMVALUE* pstValue);

/************************************************************************
 *  @fn     MV_CAMCTRL_API int __stdcall MV_CC_SetGammaSelector(IN void* handle, IN const unsigned int nValue);
 *  @brief  ����Gamma����
 *  @param  void* handle                [IN]        ������
 *          const unsigned int nValue   [IN]        Ҫ���õ�Gamma���Ͷ�Ӧ������ֵ
 *  @return �ɹ�,����MV_OK,�������Gamma���ͽ������Ϊ��Ӧֵ��ʧ��,���ش�����
 
 *  @fn     MV_CAMCTRL_API int __stdcall MV_CC_SetGammaSelector(IN void* handle, IN const unsigned int nValue);
 *  @brief  Set Gamma mode
 *  @param  void* handle                [IN]        Handle
 *          const unsigned int nValue   [IN]        Integer value to set corresponding to gamma mode
 *  @return Success, return MV_OK, and the camera gamma mode will change to the corresponding value. Failure, return error code
 ************************************************************************/
MV_CAMCTRL_API int __stdcall MV_CC_SetGammaSelector(IN void* handle, IN const unsigned int nValue);

/************************************************************************
 *  @fn     MV_CAMCTRL_API int __stdcall MV_CC_GetGamma(IN void* handle, IN OUT MVCC_FLOATVALUE* pstValue);
 *  @brief  ��ȡGammaֵ
 *  @param  void* handle                [IN]        ������
 *          MVCC_FLOATVALUE* pstValue   [IN][OUT]   ���ظ��������й����Gammaֵ����Ϣ�ṹ��ָ��
 *  @return �ɹ�,����MV_OK,�������Ӧ������Ϣ�Ľṹ��, ʧ��, ���ش�����
 *  
 *          �ɲ��սӿ�MV_CC_GetFrameRate
 
 *  @fn     MV_CAMCTRL_API int __stdcall MV_CC_GetGamma(IN void* handle, IN OUT MVCC_FLOATVALUE* pstValue);
 *  @brief  Get Gamma value
 *  @param  void* handle                [IN]        Handle
 *          MVCC_FLOATVALUE* pstValue   [IN][OUT]   Structure pointer of gamma value
 *  @return Success, return MV_OK, and get the structure of the corresponding parameters. Failure, return error code
 *  
 *          Refer to MV_CC_GetFrameRate
 ************************************************************************/
MV_CAMCTRL_API int __stdcall MV_CC_GetGamma(IN void* handle, IN OUT MVCC_FLOATVALUE* pstValue);

/************************************************************************
 *  @fn     MV_CAMCTRL_API int __stdcall MV_CC_SetGamma(IN void* handle, IN const float fValue);
 *  @brief  ����Gammaֵ
 *  @param  void* handle                [IN]        ������
 *          const float fValue          [IN]        ��Ҫ���õ����Gammaֵ
 *  @return �ɹ�,����MV_OK,�������Gammaֵ�������Ϊ��Ӧֵ��ʧ��,���ش�����
 
 *  @fn     MV_CAMCTRL_API int __stdcall MV_CC_SetGamma(IN void* handle, IN const float fValue);
 *  @brief  Set Gamma value
 *  @param  void* handle                [IN]        Handle
 *          const float fValue          [IN]        Gamma value to set
 *  @return Success, return MV_OK, and the camera gamma value will change to the corresponding value. Failure, return error code
 ************************************************************************/
MV_CAMCTRL_API int __stdcall MV_CC_SetGamma(IN void* handle, IN const float fValue);

/************************************************************************
 *  @fn     MV_CAMCTRL_API int __stdcall MV_CC_GetSharpness(IN void* handle, IN OUT MVCC_INTVALUE* pstValue);
 *  @brief  ��ȡ���
 *  @param  void* handle                [IN]        ������
 *  @param  MVCC_INTVALUE* pstValue     [IN][OUT]   ���ظ��������й������Ƚṹ��ָ��
 *  @return �ɹ�,����MV_OK,ʧ��,���ش�����
 *  
 *          �ɲ��սӿ�MV_CC_GetWidth
 
 *  @fn     MV_CAMCTRL_API int __stdcall MV_CC_GetSharpness(IN void* handle, IN OUT MVCC_INTVALUE* pstValue);
 *  @brief  Get sharpness
 *  @param  void* handle                [IN]        Handle
 *  @param  MVCC_INTVALUE* pstValue     [IN][OUT]   Structure pointer of sharpness
 *  @return Success, return MV_OK. Failure, return error code
 *  
 *          Refer to MV_CC_GetWidth
 ************************************************************************/
MV_CAMCTRL_API int __stdcall MV_CC_GetSharpness(IN void* handle, IN OUT MVCC_INTVALUE* pstValue);

/************************************************************************
 *  @fn     MV_CAMCTRL_API int __stdcall MV_CC_SetSharpness(IN void* handle, IN const unsigned int nValue);
 *  @brief  �������
 *  @param  void* handle                [IN]        ������
 *          const unsigned int nValue   [IN]        ��Ҫ���õ����
 *  @return �ɹ�,����MV_OK,���������Ƚ������Ϊ��Ӧֵ��ʧ��,���ش�����
 
 *  @fn     MV_CAMCTRL_API int __stdcall MV_CC_SetSharpness(IN void* handle, IN const unsigned int nValue);
 *  @brief  Set sharpness
 *  @param  void* handle                [IN]        Handle
 *          const unsigned int nValue   [IN]        Sharpness to set
 *  @return Success, return MV_OK, and the camera sharpness will change to the corresponding value. Failure, return error code
 ************************************************************************/
MV_CAMCTRL_API int __stdcall MV_CC_SetSharpness(IN void* handle, IN const unsigned int nValue);

/************************************************************************
 *  @fn     MV_CAMCTRL_API int __stdcall MV_CC_GetHue(IN void* handle, IN OUT MVCC_INTVALUE* pstValue);
 *  @brief  ��ȡ�Ҷ�
 *  @param  void* handle                [IN]        ������
 *  @param  MVCC_INTVALUE* pstValue     [IN][OUT]   ���ظ��������й�����ҶȽṹ��ָ��
 *  @return �ɹ�,����MV_OK,ʧ��,���ش�����
 *  
 *          �ɲ��սӿ�MV_CC_GetWidth
 
 *  @fn     MV_CAMCTRL_API int __stdcall MV_CC_GetHue(IN void* handle, IN OUT MVCC_INTVALUE* pstValue);
 *  @brief  Get Hue
 *  @param  void* handle                [IN]        Handle
 *  @param  MVCC_INTVALUE* pstValue     [IN][OUT]   Structure pointer of Hue
 *  @return Success, return MV_OK. Failure, return error code
 *  
 *          Refer to MV_CC_GetWidth
 ************************************************************************/
MV_CAMCTRL_API int __stdcall MV_CC_GetHue(IN void* handle, IN OUT MVCC_INTVALUE* pstValue);

/************************************************************************
 *  @fn     MV_CAMCTRL_API int __stdcall MV_CC_SetHue(IN void* handle, IN const unsigned int nValue);
 *  @brief  ���ûҶ�
 *  @param  void* handle                [IN]        ������
 *          const unsigned int nValue   [IN]        ��Ҫ���õĻҶ�
 *  @return �ɹ�,����MV_OK,��������ҶȽ������Ϊ��Ӧֵ��ʧ��,���ش�����
 
 *  @fn     MV_CAMCTRL_API int __stdcall MV_CC_SetHue(IN void* handle, IN const unsigned int nValue);
 *  @brief  Set Hue
 *  @param  void* handle                [IN]        Handle
 *          const unsigned int nValue   [IN]        Hue to set
 *  @return Success, return MV_OK, and the camera Hue will change to the corresponding value. Failure, return error code
 ************************************************************************/
MV_CAMCTRL_API int __stdcall MV_CC_SetHue(IN void* handle, IN const unsigned int nValue);

/************************************************************************
 *  @fn     MV_CAMCTRL_API int __stdcall MV_CC_GetSaturation(IN void* handle, IN OUT MVCC_INTVALUE* pstValue);
 *  @brief  ��ȡ���Ͷ�
 *  @param  void* handle                [IN]        ������
 *  @param  MVCC_INTVALUE* pstValue     [IN][OUT]   ���ظ��������й�������ͶȽṹ��ָ��
 *  @return �ɹ�,����MV_OK,ʧ��,���ش�����
 *  
 *          �ɲ��սӿ�MV_CC_GetWidth
 
  *  @fn     MV_CAMCTRL_API int __stdcall MV_CC_GetSaturation(IN void* handle, IN OUT MVCC_INTVALUE* pstValue);
 *  @brief  Get Saturation
 *  @param  void* handle                [IN]        Handle
 *  @param  MVCC_INTVALUE* pstValue     [IN][OUT]   Structure pointer of Saturation
 *  @return Success, return MV_OK. Failure, return error code
 *  
 *          Refer to MV_CC_GetWidth
 ************************************************************************/
MV_CAMCTRL_API int __stdcall MV_CC_GetSaturation(IN void* handle, IN OUT MVCC_INTVALUE* pstValue);

/************************************************************************
 *  @fn     MV_CAMCTRL_API int __stdcall MV_CC_SetSaturation(IN void* handle, IN const unsigned int nValue);
 *  @brief  ���ñ��Ͷ�
 *  @param  void* handle                [IN]        ������
 *          const unsigned int nValue   [IN]        ��Ҫ���õı��Ͷ�
 *  @return �ɹ�,����MV_OK,����������ͶȽ������Ϊ��Ӧֵ��ʧ��,���ش�����
 
*  @fn     MV_CAMCTRL_API int __stdcall MV_CC_SetSaturation(IN void* handle, IN const unsigned int nValue);
 *  @brief  Set Saturation
 *  @param  void* handle                [IN]        Handle
 *          const unsigned int nValue   [IN]        Saturation to set
 *  @return Success, return MV_OK, and the camera Saturation will change to the corresponding value. Failure, return error code
 ************************************************************************/
MV_CAMCTRL_API int __stdcall MV_CC_SetSaturation(IN void* handle, IN const unsigned int nValue);

/************************************************************************
 *  @fn     MV_CAMCTRL_API int __stdcall MV_CC_GetBalanceWhiteAuto(IN void* handle, IN OUT MVCC_ENUMVALUE* pstValue);
 *  @brief  ��ȡ�Զ���ƽ��
 *  @param  void* handle                [IN]        ������
 *          MVCC_ENUMVALUE* pstValue    [IN][OUT]   ���ظ������ߵ��й��Զ���ƽ�����Ϣ�ṹ��ָ��
 *  @return �ɹ�,����MV_OK,�������Ӧ������Ϣ�Ľṹ��, ʧ��, ���ش�����
 *  
            �ɲ��սӿ�MV_CC_GetPixelFormat���ο� CameraParam.h �е� MV_CAM_BALANCEWHITE_AUTO ����
 
 *  @fn     MV_CAMCTRL_API int __stdcall MV_CC_GetBalanceWhiteAuto(IN void* handle, IN OUT MVCC_ENUMVALUE* pstValue);
 *  @brief  Get Auto white balance
 *  @param  void* handle                [IN]        Handle
 *          MVCC_ENUMVALUE* pstValue    [IN][OUT]   Structure pointer of auto white balance
 *  @return Success, return MV_OK, and get the structure of the corresponding parameters. Failure, return error code
 *  
            Refer to MV_CC_GetPixelFormat and definition of MV_CAM_BALANCEWHITE_AUTO in CameraParam.h
 ************************************************************************/
MV_CAMCTRL_API int __stdcall MV_CC_GetBalanceWhiteAuto(IN void* handle, IN OUT MVCC_ENUMVALUE* pstValue);

/************************************************************************
 *  @fn     MV_CAMCTRL_API int __stdcall MV_CC_SetBalanceWhiteAuto(IN void* handle, IN const unsigned int nValue);
 *  @brief  �����Զ���ƽ��
 *  @param  void* handle                [IN]        ������
 *          const unsigned int nValue   [IN]        Ҫ���õ��Զ���ƽ���Ӧ������ֵ
 *  @return �ɹ�,����MV_OK,��������Զ���ƽ�⽫�����Ϊ��Ӧֵ��ʧ��,���ش�����
 
 *  @fn     MV_CAMCTRL_API int __stdcall MV_CC_SetBalanceWhiteAuto(IN void* handle, IN const unsigned int nValue);
 *  @brief  Set Auto white balance
 *  @param  void* handle                [IN]        Handle
 *          const unsigned int nValue   [IN]        Integer value to set corresponding to auto white balance
 *  @return Success, return MV_OK, and the camera auto white balance will change to the corresponding value. Failure, return error code
 ************************************************************************/
MV_CAMCTRL_API int __stdcall MV_CC_SetBalanceWhiteAuto(IN void* handle, IN const unsigned int nValue);

/************************************************************************
 *  @fn     MV_CAMCTRL_API int __stdcall MV_CC_GetBalanceRatioRed(IN void* handle, IN OUT MVCC_INTVALUE* pstValue);
 *  @brief  ��ȡ��ƽ�� ��
 *  @param  void* handle                [IN]        ������
 *  @param  MVCC_INTVALUE* pstValue     [IN][OUT]   ���ظ��������й������ƽ�� ��ṹ��ָ��
 *  @return �ɹ�,����MV_OK,ʧ��,���ش�����
 *  
 *          �ɲ��սӿ�MV_CC_GetWidth
 
 *  @fn     MV_CAMCTRL_API int __stdcall MV_CC_GetBalanceRatioRed(IN void* handle, IN OUT MVCC_INTVALUE* pstValue);
 *  @brief  Get white balance red
 *  @param  void* handle                [IN]        Handle
 *  @param  MVCC_INTVALUE* pstValue     [IN][OUT]   Structure pointer of white balance red
 *  @return Success, return MV_OK. Failure, return error code
 *  
 *          Refer to MV_CC_GetWidth
 ************************************************************************/
MV_CAMCTRL_API int __stdcall MV_CC_GetBalanceRatioRed(IN void* handle, IN OUT MVCC_INTVALUE* pstValue);

/************************************************************************
 *  @fn     MV_CAMCTRL_API int __stdcall MV_CC_SetBalanceRatioRed(IN void* handle, IN const unsigned int nValue);
 *  @brief  ���ð�ƽ�� ��
 *  @param  void* handle                [IN]        ������
 *          const unsigned int nValue   [IN]        ��Ҫ���õİ�ƽ�� ��
 *  @return �ɹ�,����MV_OK,���������ƽ�� �콫�����Ϊ��Ӧֵ��ʧ��,���ش�����
 
 *  @fn     MV_CAMCTRL_API int __stdcall MV_CC_SetBalanceRatioRed(IN void* handle, IN const unsigned int nValue);
 *  @brief  Set white balance red
 *  @param  void* handle                [IN]        Handle
 *          const unsigned int nValue   [IN]        White balance red to set
 *  @return Success, return MV_OK, and the camera white balance red will change to the corresponding value. Failure, return error code
 ************************************************************************/
MV_CAMCTRL_API int __stdcall MV_CC_SetBalanceRatioRed(IN void* handle, IN const unsigned int nValue);

/************************************************************************
 *  @fn     MV_CAMCTRL_API int __stdcall MV_CC_GetBalanceRatioGreen(IN void* handle, IN OUT MVCC_INTVALUE* pstValue);
 *  @brief  ��ȡ��ƽ�� ��
 *  @param  void* handle                [IN]        ������
 *  @param  MVCC_INTVALUE* pstValue     [IN][OUT]   ���ظ��������й������ƽ�� �̽ṹ��ָ��
 *  @return �ɹ�,����MV_OK,ʧ��,���ش�����
 *  
 *          �ɲ��սӿ�MV_CC_GetWidth
 
 *  @fn     MV_CAMCTRL_API int __stdcall MV_CC_GetBalanceRatioGreen(IN void* handle, IN OUT MVCC_INTVALUE* pstValue);
 *  @brief  Get white balance green
 *  @param  void* handle                [IN]        Handle
 *  @param  MVCC_INTVALUE* pstValue     [IN][OUT]   Structure pointer of white balance green
 *  @return Success, return MV_OK. Failure, return error code
 *  
 *          Refer to MV_CC_GetWidth
 ************************************************************************/
MV_CAMCTRL_API int __stdcall MV_CC_GetBalanceRatioGreen(IN void* handle, IN OUT MVCC_INTVALUE* pstValue);

/************************************************************************
 *  @fn     MV_CAMCTRL_API int __stdcall MV_CC_SetBalanceRatioGreen(IN void* handle, IN const unsigned int nValue);
 *  @brief  ���ð�ƽ�� ��
 *  @param  void* handle                [IN]        ������
 *          const unsigned int nValue   [IN]        ��Ҫ���õİ�ƽ�� ��
 *  @return �ɹ�,����MV_OK,���������ƽ�� �̽������Ϊ��Ӧֵ��ʧ��,���ش�����
 
 *  @fn     MV_CAMCTRL_API int __stdcall MV_CC_SetBalanceRatioGreen(IN void* handle, IN const unsigned int nValue);
 *  @brief  Set white balance green
 *  @param  void* handle                [IN]        Handle
 *          const unsigned int nValue   [IN]        White balance green to set
 *  @return Success, return MV_OK, and the camera white balance green will change to the corresponding value. Failure, return error code
 ************************************************************************/
MV_CAMCTRL_API int __stdcall MV_CC_SetBalanceRatioGreen(IN void* handle, IN const unsigned int nValue);

/************************************************************************
 *  @fn     MV_CAMCTRL_API int __stdcall MV_CC_GetBalanceRatioBlue(IN void* handle, IN OUT MVCC_INTVALUE* pstValue);
 *  @brief  ��ȡ��ƽ�� ��
 *  @param  void* handle                [IN]        ������
 *  @param  MVCC_INTVALUE* pstValue     [IN][OUT]   ���ظ��������й������ƽ�� ���ṹ��ָ��
 *  @return �ɹ�,����MV_OK,ʧ��,���ش�����
 *  
 *          �ɲ��սӿ�MV_CC_GetWidth
 
 *  @fn     MV_CAMCTRL_API int __stdcall MV_CC_GetBalanceRatioBlue(IN void* handle, IN OUT MVCC_INTVALUE* pstValue);
 *  @brief  Get white balance blue
 *  @param  void* handle                [IN]        Handle
 *  @param  MVCC_INTVALUE* pstValue     [IN][OUT]   Structure pointer of white balance blue
 *  @return Success, return MV_OK. Failure, return error code
 *  
 *          Refer to MV_CC_GetWidth
 ************************************************************************/
MV_CAMCTRL_API int __stdcall MV_CC_GetBalanceRatioBlue(IN void* handle, IN OUT MVCC_INTVALUE* pstValue);

/************************************************************************
 *  @fn     MV_CAMCTRL_API int __stdcall MV_CC_SetBalanceRatioBlue(IN void* handle, IN const unsigned int nValue);
 *  @brief  ���ð�ƽ�� ��
 *  @param  void* handle                [IN]        ������
 *          const unsigned int nValue   [IN]        ��Ҫ���õİ�ƽ�� ��
 *  @return �ɹ�,����MV_OK,���������ƽ�� ���������Ϊ��Ӧֵ��ʧ��,���ش�����
 
 *  @fn     MV_CAMCTRL_API int __stdcall MV_CC_SetBalanceRatioBlue(IN void* handle, IN const unsigned int nValue);
 *  @brief  Set white balance blue
 *  @param  void* handle                [IN]        Handle
 *          const unsigned int nValue   [IN]        White balance blue to set
 *  @return Success, return MV_OK, and the camera white balance blue will change to the corresponding value. Failure, return error code
 ************************************************************************/
MV_CAMCTRL_API int __stdcall MV_CC_SetBalanceRatioBlue(IN void* handle, IN const unsigned int nValue);

/************************************************************************
 *  @fn     MV_CAMCTRL_API int __stdcall MV_CC_GetFrameSpecInfoAbility(IN void* handle, IN OUT MVCC_INTVALUE* pstValue);
 *  @brief  ��ȡˮӡ��Ϣ�ڰ�������Ϣ����
 *  @param  void* handle                [IN]        ������
 *  @param  MVCC_INTVALUE* pstValue     [IN][OUT]   ���ظ��������й����ˮӡ��Ϣ�ڰ�������Ϣ���ͽṹ��ָ��
 *  @return �ɹ�,����MV_OK,ʧ��,���ش�����
 *  
 *          �ɲ��սӿ�MV_CC_GetWidth
 
 *  @fn     MV_CAMCTRL_API int __stdcall MV_CC_GetFrameSpecInfoAbility(IN void* handle, IN OUT MVCC_INTVALUE* pstValue);
 *  @brief  Get information type included by frame stamp
 *  @param  void* handle                [IN]        Handle
 *  @param  MVCC_INTVALUE* pstValue     [IN][OUT]   Structure pointer of information type included by frame stamp
 *  @return Success, return MV_OK. Failure, return error code
 *  
 *          Refer to MV_CC_GetWidth
 ************************************************************************/
MV_CAMCTRL_API int __stdcall MV_CC_GetFrameSpecInfoAbility(IN void* handle, IN OUT MVCC_INTVALUE* pstValue);

/************************************************************************
 *  @fn     MV_CAMCTRL_API int __stdcall MV_CC_SetFrameSpecInfoAbility(IN void* handle, IN const unsigned int nValue);
 *  @brief  ����ˮӡ��Ϣ�ڰ�������Ϣ����
 *  @param  void* handle                [IN]        ������
 *          const unsigned int nValue   [IN]        ��Ҫ���õ�ˮӡ��Ϣ�ڰ�������Ϣ����
 *  @return �ɹ�,����MV_OK,�������ˮӡ��Ϣ�ڰ�������Ϣ���ͻ����Ϊ��Ӧֵ��ʧ��,���ش�����
 
 *  @fn     MV_CAMCTRL_API int __stdcall MV_CC_SetFrameSpecInfoAbility(IN void* handle, IN const unsigned int nValue);
 *  @brief  Set information type included by frame stamp
 *  @param  void* handle                [IN]        Handle
 *          const unsigned int nValue   [IN]        Information type included by frame stamp to set
 *  @return Success, return MV_OK, and the camera information type included by frame stamp will change to the corresponding value. Failure, return error code
 ************************************************************************/
MV_CAMCTRL_API int __stdcall MV_CC_SetFrameSpecInfoAbility(IN void* handle, IN const unsigned int nValue);

/************************************************************************
 *  @fn     MV_CAMCTRL_API int __stdcall MV_CC_GetDeviceUserID(IN void* handle, IN OUT MVCC_STRINGVALUE* pstValue);
 *  @brief  ��ȡ�豸�Զ�������
 *  @param  void* handle                [IN]        ������
 *          MVCC_STRINGVALUE* pstValue  [IN OUT]    ���ظ��������й�������ֽṹ��ָ��
 *  @return �ɹ�,����MV_OK,���һ�ȡ��������Զ������֣�ʧ��,���ش�����
 
 *  @fn     MV_CAMCTRL_API int __stdcall MV_CC_GetDeviceUserID(IN void* handle, IN OUT MVCC_STRINGVALUE* pstValue);
 *  @brief  Get device user defined name
 *  @param  void* handle                [IN]        Handle
 *          MVCC_STRINGVALUE* pstValue  [IN OUT]    Structure pointer of device name
 *  @return Success, return MV_OK, and get the camera user defined name. Failure, return error code
 ************************************************************************/
MV_CAMCTRL_API int __stdcall MV_CC_GetDeviceUserID(IN void* handle, IN OUT MVCC_STRINGVALUE* pstValue);

/************************************************************************
 *  @fn     MV_CAMCTRL_API int __stdcall MV_CC_SetDeviceUserID(IN void* handle, IN const char* chValue);
 *  @brief  �����豸�Զ�������
 *  @param  void* handle                [IN]        ������
 *          IN const char* chValue      [IN]        �豸����
 *  @return �ɹ�,����MV_OK,���������豸�Զ������֣�ʧ��,���ش�����
 
 *  @fn     MV_CAMCTRL_API int __stdcall MV_CC_SetDeviceUserID(IN void* handle, IN const char* chValue);
 *  @brief  Set device user defined name
 *  @param  void* handle                [IN]        Handle
 *          IN const char* chValue      [IN]        Device name
 *  @return Success, return MV_OK, and set the camera user defined name. Failure, return error code
 ************************************************************************/
MV_CAMCTRL_API int __stdcall MV_CC_SetDeviceUserID(IN void* handle, IN const char* chValue);

/************************************************************************
 *  @fn     MV_CAMCTRL_API int __stdcall MV_CC_GetBurstFrameCount(IN void* handle, IN OUT MVCC_INTVALUE* pstValue);
 *  @brief  ��ȡһ�δ�����֡��
 *  @param  void* handle                [IN]        ������
 *  @param  MVCC_INTVALUE* pstValue     [IN][OUT]   ���ظ��������й����һ�δ�����֡���ṹ��ָ��
 *  @return �ɹ�,����MV_OK,ʧ��,���ش�����
 *  
 *          �ɲ��սӿ�MV_CC_GetWidth
 
 *  @fn     MV_CAMCTRL_API int __stdcall MV_CC_GetBurstFrameCount(IN void* handle, IN OUT MVCC_INTVALUE* pstValue);
 *  @brief  Get frame number trigger by once
 *  @param  void* handle                [IN]        Handle
 *  @param  MVCC_INTVALUE* pstValue     [IN][OUT]   Structure pointer of frame number trigger by once
 *  @return Success, return MV_OK. Failure, return error code
 *  
 *          Refer to MV_CC_GetWidth
 ************************************************************************/
MV_CAMCTRL_API int __stdcall MV_CC_GetBurstFrameCount(IN void* handle, IN OUT MVCC_INTVALUE* pstValue);

/************************************************************************
 *  @fn     MV_CAMCTRL_API int __stdcall MV_CC_SetBurstFrameCount(IN void* handle, IN const unsigned int nValue);
 *  @brief  ����һ�δ�����֡��
 *  @param  void* handle                [IN]        ������
 *          const unsigned int nValue   [IN]        ��Ҫ���õ�һ�δ�����֡��
 *  @return �ɹ�,����MV_OK,�������һ�δ�����֡�������Ϊ��Ӧֵ��ʧ��,���ش�����
 
 *  @fn     MV_CAMCTRL_API int __stdcall MV_CC_SetBurstFrameCount(IN void* handle, IN const unsigned int nValue);
 *  @brief  Set frame number trigger by once
 *  @param  void* handle                [IN]        Handle
 *          const unsigned int nValue   [IN]        Frame number trigger by once to set
 *  @return Success, return MV_OK, and the camera frame number trigger by once will change to the corresponding value. Failure, return error code
 ************************************************************************/
MV_CAMCTRL_API int __stdcall MV_CC_SetBurstFrameCount(IN void* handle, IN const unsigned int nValue);

/************************************************************************
 *  @fn     MV_CAMCTRL_API int __stdcall MV_CC_GetAcquisitionLineRate(IN void* handle, IN OUT MVCC_INTVALUE* pstValue);
 *  @brief  ��ȡ��Ƶ
 *  @param  void* handle                [IN]        ������
 *  @param  MVCC_INTVALUE* pstValue     [IN][OUT]   ���ظ��������й������Ƶ�ṹ��ָ��
 *  @return �ɹ�,����MV_OK,ʧ��,���ش�����
 *  
 *          �ɲ��սӿ�MV_CC_GetWidth
 
 *  @fn     MV_CAMCTRL_API int __stdcall MV_CC_GetAcquisitionLineRate(IN void* handle, IN OUT MVCC_INTVALUE* pstValue);
 *  @brief  Get line rate
 *  @param  void* handle                [IN]        Handle
 *  @param  MVCC_INTVALUE* pstValue     [IN][OUT]   Structure pointer of line rate
 *  @return Success, return MV_OK. Failure, return error code
 *  
 *          Refer to MV_CC_GetWidth
 ************************************************************************/
MV_CAMCTRL_API int __stdcall MV_CC_GetAcquisitionLineRate(IN void* handle, IN OUT MVCC_INTVALUE* pstValue);

/************************************************************************
 *  @fn     MV_CAMCTRL_API int __stdcall MV_CC_SetAcquisitionLineRate(IN void* handle, IN const unsigned int nValue);
 *  @brief  ������Ƶ
 *  @param  void* handle                [IN]        ������
 *          const unsigned int nValue   [IN]        ��Ҫ���õ���Ƶ
 *  @return �ɹ�,����MV_OK,���������Ƶ�����Ϊ��Ӧֵ��ʧ��,���ش�����
 
 *  @fn     MV_CAMCTRL_API int __stdcall MV_CC_SetAcquisitionLineRate(IN void* handle, IN const unsigned int nValue);
 *  @brief  Set line rate
 *  @param  void* handle                [IN]        Handle
 *          const unsigned int nValue   [IN]        Line rate to set
 *  @return Success, return MV_OK, and the camera line rate will change to the corresponding value. Failure, return error code
 ************************************************************************/
MV_CAMCTRL_API int __stdcall MV_CC_SetAcquisitionLineRate(IN void* handle, IN const unsigned int nValue);

/************************************************************************
 *  @fn     MV_CAMCTRL_API int __stdcall MV_CC_GetHeartBeatTimeout(IN void* handle, IN OUT MVCC_INTVALUE* pstValue);
 *  @brief  ��ȡ������Ϣ
 *  @param  void* handle                [IN]        ������
 *  @param  MVCC_INTVALUE* pstValue     [IN][OUT]   ���ظ��������й����������Ϣ�ṹ��ָ��
 *  @return �ɹ�,����MV_OK,ʧ��,���ش�����
 *  
 *          �ɲ��սӿ�MV_CC_GetWidth
 
 *  @fn     MV_CAMCTRL_API int __stdcall MV_CC_GetHeartBeatTimeout(IN void* handle, IN OUT MVCC_INTVALUE* pstValue);
 *  @brief  Get heartbeat information
 *  @param  void* handle                [IN]        Handle
 *  @param  MVCC_INTVALUE* pstValue     [IN][OUT]   Structure pointer of heartbeat information
 *  @return Success, return MV_OK. Failure, return error code
 *  
 *          Refer to MV_CC_GetWidth
 ************************************************************************/
MV_CAMCTRL_API int __stdcall MV_CC_GetHeartBeatTimeout(IN void* handle, IN OUT MVCC_INTVALUE* pstValue);

/************************************************************************
 *  @fn     MV_CAMCTRL_API int __stdcall MV_CC_SetHeartBeatTimeout(IN void* handle, IN const unsigned int nValue);
 *  @brief  ����������Ϣ
 *  @param  void* handle                [IN]        ������
 *          const unsigned int nValue   [IN]        ��Ҫ���õ�������Ϣ
 *  @return �ɹ�,����MV_OK,�������������Ϣ�����Ϊ��Ӧֵ��ʧ��,���ش�����
 
 *  @fn     MV_CAMCTRL_API int __stdcall MV_CC_SetHeartBeatTimeout(IN void* handle, IN const unsigned int nValue);
 *  @brief  Set heartbeat information
 *  @param  void* handle                [IN]        Handle
 *          const unsigned int nValue   [IN]        Heartbeat information to set
 *  @return Success, return MV_OK, and the camera heartbeat information will change to the corresponding value. Failure, return error code
 ************************************************************************/
MV_CAMCTRL_API int __stdcall MV_CC_SetHeartBeatTimeout(IN void* handle, IN const unsigned int nValue);

/************************************************************************
 *  @fn     MV_CAMCTRL_API int __stdcall MV_GIGE_GetGevSCPSPacketSize(IN void* handle, IN OUT MVCC_INTVALUE* pstValue);
 *  @brief  ��ȡ�������С
 *  @param  void* handle                [IN]        ������
 *  @param  MVCC_INTVALUE* pstValue     [IN][OUT]   ���ظ��������й�����������С�ṹ��ָ��
 *  @return �ɹ�,����MV_OK,ʧ��,���ش�����
 *  
 *          �ɲ��սӿ�MV_CC_GetWidth
 
 *  @fn     MV_CAMCTRL_API int __stdcall MV_GIGE_GetGevSCPSPacketSize(IN void* handle, IN OUT MVCC_INTVALUE* pstValue);
 *  @brief  Get network packet size
 *  @param  void* handle                [IN]        Handle
 *  @param  MVCC_INTVALUE* pstValue     [IN][OUT]   Structure pointer of network packet size
 *  @return Success, return MV_OK. Failure, return error code
 *  
 *          Refer to MV_CC_GetWidth
 ************************************************************************/
MV_CAMCTRL_API int __stdcall MV_GIGE_GetGevSCPSPacketSize(IN void* handle, IN OUT MVCC_INTVALUE* pstValue);

/************************************************************************
 *  @fn     MV_CAMCTRL_API int __stdcall MV_GIGE_SetGevSCPSPacketSize(IN void* handle, IN const unsigned int nValue);
 *  @brief  �����������С
 *  @param  void* handle                [IN]        ������
 *          const unsigned int nValue   [IN]        ��Ҫ���õ��������С
 *  @return �ɹ�,����MV_OK,��������������С�����Ϊ��Ӧֵ��ʧ��,���ش�����
 
 *  @fn     MV_CAMCTRL_API int __stdcall MV_GIGE_SetGevSCPSPacketSize(IN void* handle, IN const unsigned int nValue);
 *  @brief  Set network packet size
 *  @param  void* handle                [IN]        Handle
 *          const unsigned int nValue   [IN]        Packet size to set
 *  @return Success, return MV_OK, and change packet size to setting value. Failure, return error code
 ************************************************************************/
MV_CAMCTRL_API int __stdcall MV_GIGE_SetGevSCPSPacketSize(IN void* handle, IN const unsigned int nValue);

/************************************************************************
 *  @fn     MV_CAMCTRL_API int __stdcall MV_GIGE_GetGevSCPD(IN void* handle, IN OUT MVCC_INTVALUE* pstValue);
 *  @brief  ��ȡ��������ͼ��
 *  @param  void* handle                [IN]        ������
 *  @param  MVCC_INTVALUE* pstValue     [IN][OUT]   ���ظ��������й������������ͼ���ṹ��ָ��
 *  @return �ɹ�,����MV_OK,ʧ��,���ش�����
 *  
 *          �ɲ��սӿ�MV_CC_GetWidth
 
 *  @fn     MV_CAMCTRL_API int __stdcall MV_GIGE_GetGevSCPD(IN void* handle, IN OUT MVCC_INTVALUE* pstValue);
 *  @brief  Get network packet sending delay
 *  @param  void* handle                [IN]        Handle
 *  @param  MVCC_INTVALUE* pstValue     [IN][OUT]   Structure pointer of network packet sending delay
 *  @return Success, return MV_OK. Failure, return error code
 *  
 *          Refer to MV_CC_GetWidth
 ************************************************************************/
MV_CAMCTRL_API int __stdcall MV_GIGE_GetGevSCPD(IN void* handle, IN OUT MVCC_INTVALUE* pstValue);

/************************************************************************
 *  @fn     MV_CAMCTRL_API int __stdcall MV_GIGE_SetGevSCPD(IN void* handle, IN const unsigned int nValue);
 *  @brief  ������������ͼ��
 *  @param  void* handle                [IN]        ������
 *          const unsigned int nValue   [IN]        ��Ҫ���õ���������ͼ��
 *  @return �ɹ�,����MV_OK,���������������ͼ�������Ϊ��Ӧֵ��ʧ��,���ش�����
 
 *  @fn     MV_CAMCTRL_API int __stdcall MV_GIGE_SetGevSCPD(IN void* handle, IN const unsigned int nValue);
 *  @brief  Set network packet sending delay
 *  @param  void* handle                [IN]        Handle
 *          const unsigned int nValue   [IN]        Packet delay to set
 *  @return Success, return MV_OK, and change packet delay to setting value. Failure, return error code
 ************************************************************************/
MV_CAMCTRL_API int __stdcall MV_GIGE_SetGevSCPD(IN void* handle, IN const unsigned int nValue);

/************************************************************************
 *  @fn     MV_CAMCTRL_API int __stdcall MV_GIGE_GetGevSCDA(IN void* handle, unsigned int* pnIP);
 *  @brief  ��ȡ���ն�IP��ַ��0xa9fe0102 ��ʾ 169.254.1.2
 *  @param  void* handle                [IN]        ������
 *  @param  unsigned int* pnIP          [IN][OUT]   ���ظ������߽��ն�IP��ַ
 *  @return �ɹ�,����MV_OK,ʧ��,���ش�����
 
 *  @fn     MV_CAMCTRL_API int __stdcall MV_GIGE_GetGevSCDA(IN void* handle, unsigned int* pnIP);
 *  @brief  Get receiver IP address, 0xa9fe0102 indicates 169.254.1.2
 *  @param  void* handle                [IN]        Handle
 *  @param  unsigned int* pnIP          [IN][OUT]   Receiver IP address
 *  @return Success, return MV_OK. Failure, return error code
 ************************************************************************/
MV_CAMCTRL_API int __stdcall MV_GIGE_GetGevSCDA(IN void* handle, unsigned int* pnIP);

/************************************************************************
 *  @fn     MV_CAMCTRL_API int __stdcall MV_GIGE_SetGevSCDA(IN void* handle, unsigned int nIP);
 *  @brief  ���ý��ն�IP��ַ
 *  @param  void* handle                [IN]        ������
 *          unsigned int nIP            [IN]        ��Ҫ���õĽ��ն�IP��ַ
 *  @return �ɹ�,����MV_OK,����������ն�IP��ַ�����Ϊ��Ӧֵ��ʧ��,���ش�����
 
 *  @fn     MV_CAMCTRL_API int __stdcall MV_GIGE_SetGevSCDA(IN void* handle, unsigned int nIP);
 *  @brief  Set receiver IP address
 *  @param  void* handle                [IN]        Handel
 *          unsigned int nIP            [IN]        Receiver IP address to set
 *  @return Success, return MV_OK, and change receiver IP address to setting value. Failure, return error code
 ************************************************************************/
MV_CAMCTRL_API int __stdcall MV_GIGE_SetGevSCDA(IN void* handle, unsigned int nIP);

/************************************************************************
 *  @fn     MV_CAMCTRL_API int __stdcall MV_GIGE_GetGevSCSP(IN void* handle, unsigned int* pnPort);
 *  @brief  ��ȡ���Ͷ˵Ķ˿ں�
 *  @param  void* handle                [IN]        ������
 *  @param  unsigned int* pnPort        [IN][OUT]   ���ظ������߷��Ͷ˵Ķ˿ں�
 *  @return �ɹ�,����MV_OK,ʧ��,���ش�����
 
 *  @fn     MV_CAMCTRL_API int __stdcall MV_GIGE_GetGevSCSP(IN void* handle, unsigned int* pnPort);
 *  @brief  Get transmitter port number
 *  @param  void* handle                [IN]        Handle
 *  @param  unsigned int* pnPort        [IN][OUT]   Transmitter port number
 *  @return Success, return MV_OK. Failure, return error code
 ************************************************************************/
MV_CAMCTRL_API int __stdcall MV_GIGE_GetGevSCSP(IN void* handle, unsigned int* pnPort);

/************************************************************************
 *  @fn     MV_CAMCTRL_API int __stdcall MV_GIGE_SetGevSCSP(IN void* handle, unsigned int nPort);
 *  @brief  ���÷��Ͷ˵Ķ˿ں�
 *  @param  void* handle                [IN]        ������
 *          unsigned int nPort          [IN]        ��Ҫ���õķ��Ͷ˵Ķ˿ں�
 *  @return �ɹ�,����MV_OK,����������Ͷ˵Ķ˿ںŻ����Ϊ��Ӧֵ��ʧ��,���ش�����
 
 *  @fn     MV_CAMCTRL_API int __stdcall MV_GIGE_SetGevSCSP(IN void* handle, unsigned int nPort);
 *  @brief  Set transmitter port number
 *  @param  void* handle                [IN]        Handle
 *          unsigned int nPort          [IN]        Transmitter port number to set
 *  @return Success, return MV_OK, and change transmitter port number to setting value. Failure, return error code
 ************************************************************************/
MV_CAMCTRL_API int __stdcall MV_GIGE_SetGevSCSP(IN void* handle, unsigned int nPort);

/********************************************************************//**
 *  @~chinese
 *  @brief  �����豸������
 *  @param  handle                      [IN]            �豸���
 *  @param  nBaudrate                   [IN]            ���õĲ�����ֵ����ֵ�ο�CameraParams.h�к궨�壬��#define MV_CAML_BAUDRATE_9600  0x00000001
 *  @return �ɹ�,����MV_OK,ʧ��,���ش�����
 *  @remarks ���ýӿ������ã�������� MV_CAML_SetDeviceBaudrate�ӿڣ�
 
 *  @~english
 *  @brief  Set device baudrate using one of the CL_BAUDRATE_XXXX value
 *  @param  handle                      [IN]            Device handle
 *  @param  nBaudrate                   [IN]            baud rate to set. Refer to the 'CameraParams.h' for parameter definitions, for example, #define MV_CAML_BAUDRATE_9600  0x00000001
 *  @return Success, return MV_OK. Failure, return error code 
 *  @remarks (This interface is abandoned, it is recommended to use the MV_CAML_SetDeviceBaudrate)
************************************************************************/
MV_CAMCTRL_API int __stdcall MV_CAML_SetDeviceBauderate(IN void* handle, unsigned int nBaudrate);

/********************************************************************//**
 *  @~chinese
 *  @brief  ��ȡ�豸������
 *  @param  handle                      [IN]            �豸���
 *  @param  pnCurrentBaudrate           [OUT]           ��������Ϣָ�룬��ֵ�ο�CameraParams.h�к궨�壬��#define MV_CAML_BAUDRATE_9600  0x00000001
 *  @return �ɹ�,����MV_OK,ʧ��,���ش�����
 *  @remarks ���ýӿ������ã�������� MV_CAML_GetDeviceBaudrate�ӿڣ�
 
 *  @~english
 *  @brief  Returns the current device baudrate, using one of the CL_BAUDRATE_XXXX value
 *  @param  handle                      [IN]            Device handle
 *  @param  pnCurrentBaudrate           [OUT]           Return pointer of baud rate to user. Refer to the 'CameraParams.h' for parameter definitions, for example, #define MV_CAML_BAUDRATE_9600  0x00000001
 *  @return Success, return MV_OK. Failure, return error code 
 *  @remarks (This interface is abandoned, it is recommended to use the MV_CAML_GetDeviceBaudrate)
************************************************************************/
MV_CAMCTRL_API int __stdcall MV_CAML_GetDeviceBauderate(IN void* handle,unsigned int* pnCurrentBaudrate);

/********************************************************************//**
 *  @~chinese
 *  @brief  ��ȡ�豸������������֧�ֵĲ�����
 *  @param  handle                      [IN]            �豸���
 *  @param  pnBaudrateAblity            [OUT]           ֧�ֵĲ�������Ϣ��ָ�롣��֧�ֲ����ʵĻ���������������ֵ�ο�CameraParams.h�к궨�壬��MV_CAML_BAUDRATE_9600  0x00000001
 *  @return �ɹ�,����MV_OK,ʧ��,���ش�����
 *  @remarks ���ýӿ������ã�������� MV_CAML_GetSupportBaudrates�ӿڣ�
 
 *  @~english
 *  @brief  Returns supported baudrates of the combined device and host interface
 *  @param  handle                      [IN]            Device handle
 *  @param  pnBaudrateAblity            [OUT]           Return pointer of the supported baudrates to user. 'OR' operation results of the supported baudrates. Refer to the 'CameraParams.h' for single value definitions, for example, MV_CAML_BAUDRATE_9600  0x00000001
 *  @return Success, return MV_OK. Failure, return error code 
 *  @remarks (This interface is abandoned, it is recommended to use the MV_CAML_GetSupportBaudrates)
************************************************************************/
MV_CAMCTRL_API int __stdcall MV_CAML_GetSupportBauderates(IN void* handle,unsigned int* pnBaudrateAblity);



/********************************************************************//**
 *  @~chinese
 *  @brief  ����ͼƬ��֧��Bmp��Jpeg.
 *  @param  handle                      [IN]            �豸���
 *  @param  pstSaveParam                [IN][OUT]       ����ͼƬ�����ṹ��
 *  @return �ɹ�������MV_OK�����󣬷��ش����� 
 *  @remarks ͨ�����ӿڿ��Խ����豸�ɼ�����ԭʼͼ������ת����JPEG����BMP�ȸ�ʽ�������ָ���ڴ��У�Ȼ���û����Խ�ת��֮�������ֱ�ӱ����ͼƬ�ļ���
             �ýӿڵ����޽ӿ�˳��Ҫ����ͼ��Դ���ݾͿ��Խ���ת���������ȵ���MV_CC_GetOneFrameTimeout����MV_CC_RegisterImageCallBackEx���ûص���������ȡһ֡ͼ�����ݣ�Ȼ����ͨ���ýӿ�ת����ʽ��
             MV_CC_SaveImageEx2��MV_CC_SaveImageEx���Ӳ���handle��Ϊ�˱�֤�������ӿڵ�ͳһ��
 
 *  @~english
 *  @brief  Save image, support Bmp and Jpeg.
 *  @param  handle                      [IN]            Device handle
 *  @param  pstSaveParam                [IN][OUT]       Save image parameters structure
 *  @return Success, return MV_OK. Failure, return error code
 *  @remarks Once there is image data, you can call this API to convert the data.
             You can also call MV_CC_GetOneFrameTimeout or MV_CC_RegisterImageCallBackEx or MV_CC_GetImageBuffer to get one image frame and set the callback function, and then call this API to convert the format.
             Comparing with the API MV_CC_SaveImageEx, this API added the parameter handle to ensure the unity with other API. 
 ************************************************************************/
MV_CAMCTRL_API int __stdcall MV_CC_SaveImageEx2(IN void* handle, MV_SAVE_IMAGE_PARAM_EX* pstSaveParam);


/********************************************************************//**
 *  @~chinese
 *  @brief  ����ͼ���ļ�
 *  @param  handle                      [IN]            �豸���
 *  @param  pstSaveFileParam            [IN][OUT]       ����ͼƬ�ļ������ṹ��
 *  @return �ɹ�������MV_OK�����󣬷��ش����� 
 *  @remarks �ýӿ�֧��BMP/JPEG/PNG/TIFF��
 
 *  @~english
 *  @brief  Save the image file.
 *  @param  handle                      [IN]            Device handle
 *  @param  pstSaveFileParam            [IN][OUT]       Save the image file parameter structure
 *  @return Success, return MV_OK. Failure, return error code
 *  @remarks This API support BMP/JPEG/PNG/TIFF.
 ************************************************************************/
MV_CAMCTRL_API int __stdcall MV_CC_SaveImageToFile(IN void* handle, MV_SAVE_IMG_TO_FILE_PARAM* pstSaveFileParam);


/********************************************************************//**
 *  @~chinese
 *  @brief  ���ظ�ʽת��
 *  @param  handle                      [IN]            �豸���
 *  @param  pstCvtParam                 [IN][OUT]       ���ظ�ʽת�������ṹ��
 *  @return �ɹ�������MV_OK�����󣬷��ش����� 
 *  @remarks ͨ�����ӿڿ��Խ����豸�ɼ�����ԭʼͼ������ת�����û���������ظ�ʽ�������ָ���ڴ��С�
             �ýӿڵ����޽ӿ�˳��Ҫ����ͼ��Դ���ݾͿ��Խ���ת���������ȵ���MV_CC_GetOneFrameTimeout����MV_CC_RegisterImageCallBackEx���ûص�������
             ��ȡһ֡ͼ�����ݣ�Ȼ����ͨ���ýӿ�ת����ʽ������豸��ǰ�ɼ�ͼ����JPEGѹ���ĸ�ʽ����֧�ֵ��øýӿڽ���ת����
 
 *  @~english
 *  @brief  Pixel format conversion
 *  @param  handle                      [IN]            Device handle
 *  @param  pstCvtParam                 [IN][OUT]       Convert Pixel Type parameter structure
 *  @return Success, return MV_OK. Failure, return error code
 *  @remarks This API is used to transform the collected original data to pixel format and save to specified memory. 
             There is no order requirement to call this API, the transformation will execute when there is image data. 
             First call MV_CC_GetOneFrameTimeout or MV_CC_RegisterImageCallBackEx to set callback function, and get a frame of image data,
             then call this API to transform the format.
 ************************************************************************/
MV_CAMCTRL_API int __stdcall MV_CC_ConvertPixelType(IN void* handle, IN OUT MV_CC_PIXEL_CONVERT_PARAM* pstCvtParam);




#ifdef __cplusplus
}
#endif 

#endif //_MV_OBSOLETE_INTERFACES_H_
