#ifndef __SAVEBMP_H__
#define __SAVEBMP_H__

#include "windows.h"
/**
*  描述：生成BMP国像文件头
*  参数：pFileName[in] : BMP图像文件名称
*        lImgW[in]     : 图像宽度
*        lImgH[in]     : 图像高度
*        nBitsPerPixel[in] : 8 = 灰度、24 = 彩色
*        nDPI[in]      : 分辨率
*  返回：0 代表成功，其它代表失败
**/
int lCreateBMPHeader(const char *pFileName,int lImgW,int lImgH,short nBitsPerPixel,int nDPI);
/**
*  描述：写BMP国像文件
*  参数：pImgBuf[in] : BMP图像BUFFER
*        lImgBufSize[in]     : BMP图像BUFFER大小，大小=lImgW*lImgH*nBitsPerPixel/8
*  返回：0 代表成功，其它代表失败
**/
int lWriteBMPFile(unsigned char *pImgBuf,int lImgBufSize);
/**
*  描述：释放写BMP国像文件中产生的BUFFER
*  参数：VOID
*  返回：VOID
**/
void lReleaseBMP();


#endif