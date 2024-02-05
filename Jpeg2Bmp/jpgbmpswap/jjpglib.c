#include "jjpglib.h"
#include "jpeglib.h"	// include JPEG library declarations
#include "jerror.h"		// JPEG error handler

int jGetJpgInfo(unsigned char *pJpgBuf,long ulJpgSize,long *w,long *h,long *bitCount)
{
	struct jpeg_decompress_struct cinfo; // JPEG image parameters
	struct jpeg_error_mgr jerr;			 // default JPEG error handler
    int iret = 0;

	if(pJpgBuf == NULL || ulJpgSize < 10)
		return S_ERR_PARA;
	
	// Set up the normal JPEG error routines
	cinfo.err = jpeg_std_error(&jerr);
	
	// Initialize the JPEG decompression object with a data source (file).
	jpeg_create_decompress(&cinfo);
	jpeg_stdio_src(&cinfo, pJpgBuf,ulJpgSize);
	
	// Read file parameters with jpeg_read_header()
	iret = jpeg_read_header(&cinfo, TRUE);
	if(iret != JPEG_HEADER_OK)
	{
		jpeg_finish_decompress(&cinfo);
		jpeg_destroy_decompress(&cinfo);
		
		return S_ERR_JPGFORMAT;
	}
	
	if(cinfo.jpeg_color_space < 1 || cinfo.image_width < 1 || cinfo.image_height < 1)
	{
		jpeg_finish_decompress(&cinfo);
		jpeg_destroy_decompress(&cinfo);
		
		return S_ERR_JPGFORMAT;
	}
	
	// Set parameters for decompression, if necessary (not necessary
	// here - the defaults set by jpeg_read_header() is sufficient.
	
	if(cinfo.jpeg_color_space == JCS_GRAYSCALE)
	{
        cinfo.out_color_space = JCS_GRAYSCALE;
		*bitCount = 8;
	}
	else
	{
        cinfo.out_color_space = JCS_RGB;
		*bitCount = 24;
	}

	// Finish decompression and release JPEG compression object
	jpeg_finish_decompress(&cinfo);
	jpeg_destroy_decompress(&cinfo);

	return 0;
}

/**
*  Description:
*      JPG to BMP
*  Parameters:
*      pJpgBuf[in] : Jpg buffer pointer
*      ulJpgSize[in] : Jpg buffer size
*      pBmpBuf[out] : Bmp buffer pointer
*      pBmpW[out] : Bmp image width
*      pBmpH[out] : Bmp image height
*      pImgMode[out] : Color or Grayscale
*  Return values:
*      0 is success,else is failed.
*
**/
long jJpgToBmp(unsigned char *pJpgBuf,long ulJpgSize,
				unsigned char **pBmpBuf,long *pBmpW,long *pBmpH,long *bitCount)
{
	struct jpeg_decompress_struct cinfo; // JPEG image parameters
	struct jpeg_error_mgr jerr;			 // default JPEG error handler
	unsigned char **buffer;			 // points to large array of RGB data
	long row_stride;						 // physical row width in output buffer
    long counter = 0;
	long i, j,k;
    long m_height=0,m_width=0;
	long lRet = 0;
	long m = 0;
	int iRet = -1;
	boolean bRet = FALSE;
	
	
    if(pJpgBuf == NULL || ulJpgSize < 10)
		return S_ERR_PARA;

	// Set up the normal JPEG error routines
	cinfo.err = jpeg_std_error(&jerr);

	// Initialize the JPEG decompression object with a data source (file).
	jpeg_create_decompress(&cinfo);
	jpeg_stdio_src(&cinfo, pJpgBuf,ulJpgSize);

	// Read file parameters with jpeg_read_header()
	iRet = jpeg_read_header(&cinfo, TRUE);
	if(iRet != JPEG_HEADER_OK)
	{
	   	jpeg_finish_decompress(&cinfo);
	    jpeg_destroy_decompress(&cinfo);

	    return S_ERR_JPGFORMAT;
	}
	
	if(cinfo.jpeg_color_space < 1 || cinfo.image_width < 1 || cinfo.image_height < 1)
	{
	   	jpeg_finish_decompress(&cinfo);
	    jpeg_destroy_decompress(&cinfo);

	    return S_ERR_JPGFORMAT;
	}
	
	
	// Set parameters for decompression, if necessary (not necessary
	// here - the defaults set by jpeg_read_header() is sufficient.

	if(cinfo.jpeg_color_space == JCS_GRAYSCALE)
	{
        cinfo.out_color_space = JCS_GRAYSCALE;
		*bitCount = 8;
	}
	else
	{
        cinfo.out_color_space = JCS_RGB;
		*bitCount = 24;
	}

	// Start decompressor
	bRet = jpeg_start_decompress(&cinfo);
	if(bRet == FALSE)
	{
 	   	jpeg_finish_decompress(&cinfo);
	    jpeg_destroy_decompress(&cinfo);

	    return S_ERR_JPGFORMAT;	
	}

	// Decompression complete, so now begin extraction of data
	// row_stride = output pixels per row * number of colours per row
	row_stride = cinfo.output_width * cinfo.output_components;

	// Create data buffer

	buffer = (unsigned char **)diy_malloc(sizeof(unsigned char *) * cinfo.output_height);
	if(!buffer)
	{
	    lRet = S_ERR_MALLOC;
		goto ERR_EXIT;
	}
	
	buffer[0] = (unsigned char *)diy_malloc(cinfo.output_height * row_stride);
    if(!buffer[0])
	{
	    lRet = S_ERR_MALLOC;
		goto ERR_EXIT;
	}
	
	for (k = 0; k < (int)(cinfo.output_height); k++)
	{
		buffer[k] = buffer[0] + row_stride*k;
	}

	// The JPEG decompress parameters (cinfo) contains a counter, the output
	// row counter.  Keep extracting data until the output row is at the end.
	counter = 0;
	while (cinfo.output_scanline < cinfo.output_height)
	{
		counter += jpeg_read_scanlines(&cinfo, &buffer[counter], cinfo.output_height);
		//如果图像不对，提示如：Correct JPG data:premature end of data segment
		if(m>(long)(cinfo.output_height))
		{
			lRet = S_ERR_BMGTOJPG;
		    goto ERR_EXIT;
		}
        m++;
	}

	// initialize this CImg object
	*pBmpW = m_width = cinfo.output_width;
	*pBmpH = m_height = cinfo.output_height;

	// Convert buffer data to Img struct
	switch (cinfo.out_color_space)
	{
	   case JCS_GRAYSCALE:
   		    *pBmpBuf = (unsigned char *)diy_malloc((cinfo.output_width)*(cinfo.output_height));
			if(!(*pBmpBuf))
			{
			    lRet = S_ERR_MALLOC;
        		goto ERR_EXIT;
			}
			for (j = 0; j < m_height; j++)
			{
				for (i = 0; i < m_width; i++)
				{
					//gImage[j][i] = buffer[j][i];
                    (*pBmpBuf)[j*m_width+i] = buffer[m_height-j-1][i]; // 此处可决定图像是否镜像
				}
			}
			break;
	   default://case JCS_RGB:
            *pBmpBuf = (unsigned char *)diy_malloc((cinfo.output_width)*(cinfo.output_height)*3);
			if(!(*pBmpBuf))
			{
			    lRet = S_ERR_MALLOC;
        		goto ERR_EXIT;
			}
			for (j = 0; j < m_height; j++)
			{
				for (i = 0; i < m_width*3; i += 3)
				{
                    (*pBmpBuf)[j*m_width*3+i] = buffer[m_height-j-1][i+2];  // 此处可决定图像是否镜像
					(*pBmpBuf)[j*m_width*3+i+1] = buffer[m_height-j-1][i+1];
					(*pBmpBuf)[j*m_width*3+i+2] = buffer[m_height-j-1][i+0];
				}
			}
			break;
	}


ERR_EXIT:
	// Destroy buffer

	if(buffer[0])
	    diy_free(buffer[0]);
	if(buffer)
	    diy_free(buffer);
	buffer = NULL;

	// Finish decompression and release JPEG compression object
	jpeg_finish_decompress(&cinfo);
	jpeg_destroy_decompress(&cinfo);

	return lRet;
}

/**
*  Description:
*      Release memory and resource. After call "JJpgToBmp",must call this fucntion.
*  Parameters:
*      pBuf: image buffer to be release
*  Return value:
*      void
**/
void JFreeBmpBuf(unsigned char *pBuf)
{
    if(pBuf)
		diy_free(pBuf);
	pBuf = NULL;
}