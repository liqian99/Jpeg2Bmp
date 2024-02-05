#ifndef __SAVEBMP_H__
#define __SAVEBMP_H__

#include "windows.h"
/**
*  ����������BMP�����ļ�ͷ
*  ������pFileName[in] : BMPͼ���ļ�����
*        lImgW[in]     : ͼ����
*        lImgH[in]     : ͼ��߶�
*        nBitsPerPixel[in] : 8 = �Ҷȡ�24 = ��ɫ
*        nDPI[in]      : �ֱ���
*  ���أ�0 ����ɹ�����������ʧ��
**/
int lCreateBMPHeader(const char *pFileName,int lImgW,int lImgH,short nBitsPerPixel,int nDPI);
/**
*  ������дBMP�����ļ�
*  ������pImgBuf[in] : BMPͼ��BUFFER
*        lImgBufSize[in]     : BMPͼ��BUFFER��С����С=lImgW*lImgH*nBitsPerPixel/8
*  ���أ�0 ����ɹ�����������ʧ��
**/
int lWriteBMPFile(unsigned char *pImgBuf,int lImgBufSize);
/**
*  �������ͷ�дBMP�����ļ��в�����BUFFER
*  ������VOID
*  ���أ�VOID
**/
void lReleaseBMP();


#endif