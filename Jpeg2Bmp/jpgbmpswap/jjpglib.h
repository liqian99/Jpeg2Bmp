#ifndef __JJPGLIB_H__
#define __JJPGLIB_H__

#define S_SUCCESS   0
#define S_ERR_PARA  -1        // 参数错误
#define S_ERR_JPGFORMAT   -2  //非JPG文件或文件格式错误
#define S_ERR_MALLOC -3       // 分配内存空间错误
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
*  描述:
*      JPG图像转BMP图像
*  参数:
*      pJpgBuf[in] : JPG图像BUFFER指针
*      ulJpgSize[in] : JPG图像BUFFER大小
*      pBmpBuf[out] : BMP图像BUFFER指针
*      pBmpW[out] : 图像宽度
*      pBmpH[out] : 图像高度
*      pImgMode[out] : 8=灰度图像、24=彩色图像
*  返回:
*      0 代表成功，其它代表失败
*
**/
long jJpgToBmp(unsigned char *pJpgBuf,long ulJpgSize,
			   unsigned char **pBmpBuf,long *pBmpW,long *pBmpH,long *bitCount);

/**
*  描述:
*      清空调用iJpgToBmp函数分配的BUFFER.
*  参数:
*      pBuf[in] : BUFFER指针
*  返回:
*      void
*
**/
void JFreeBmpBuf(unsigned char *pBuf);

#endif