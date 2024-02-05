#ifndef __JJPGLIB_H__
#define __JJPGLIB_H__

#define S_SUCCESS   0
#define S_ERR_PARA  -1        // ��������
#define S_ERR_JPGFORMAT   -2  //��JPG�ļ����ļ���ʽ����
#define S_ERR_MALLOC -3       // �����ڴ�ռ����
#define S_ERR_BMGTOJPG -4

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define diy_malloc(size) malloc(size)
#define diy_free(memblock) free(memblock)
#define diy_realloc(p,size) realloc(p,size)
#define diy_memset(dest,c,count)		memset(dest,c,count)
#define	diy_memcpy(dest,src,count)	memcpy(dest,src,count)
#define diy_memmove(dest,src,count)	memmove(dest,src,count)

/**
*  ����:
*      JPGͼ��תBMPͼ��
*  ����:
*      pJpgBuf[in] : JPGͼ��BUFFERָ��
*      ulJpgSize[in] : JPGͼ��BUFFER��С
*      pBmpBuf[out] : BMPͼ��BUFFERָ��
*      pBmpW[out] : ͼ����
*      pBmpH[out] : ͼ��߶�
*      pImgMode[out] : 8=�Ҷ�ͼ��24=��ɫͼ��
*  ����:
*      0 ����ɹ�����������ʧ��
*
**/
long jJpgToBmp(unsigned char *pJpgBuf,long ulJpgSize,
			   unsigned char **pBmpBuf,long *pBmpW,long *pBmpH,long *bitCount);

/**
*  ����:
*      ��յ���iJpgToBmp���������BUFFER.
*  ����:
*      pBuf[in] : BUFFERָ��
*  ����:
*      void
*
**/
void JFreeBmpBuf(unsigned char *pBuf);

#endif