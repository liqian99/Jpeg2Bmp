#include "saveBmp.h"

static PBITMAPINFO lpBmpInfo = NULL;
static HANDLE hBMP = NULL;

PBITMAPINFO CreateBitmapInfoStruct(LONG Width, LONG Height, WORD Planes, WORD BitsPixel,LONG nDPI)
{
	WORD           cClrBits;
	PBITMAPINFO    pbmi;
	int iClrIdx;
	
	cClrBits = (WORD)(Planes * BitsPixel);
	if (cClrBits == 1)
		cClrBits = 1;
	else if (cClrBits <= 4)
		cClrBits = 4;
	else if (cClrBits <= 8)
		cClrBits = 8;
	else if (cClrBits <= 16)
		cClrBits = 16;
	else if (cClrBits <= 24)
		cClrBits = 24;
	else cClrBits = 32;
	
	if (cClrBits < 24){
		int      iColorUse;
		RGBQUAD  *pRGBClr;
		iColorUse = 1 << cClrBits;
		pbmi = (PBITMAPINFO) LocalAlloc(LPTR,sizeof(BITMAPINFOHEADER) + sizeof(RGBQUAD) * iColorUse);
		pRGBClr = (RGBQUAD*)(((BYTE *)pbmi)+sizeof(BITMAPINFOHEADER));
		if (iColorUse>2){
			for (iClrIdx=0;iClrIdx < iColorUse;iClrIdx++){
				pRGBClr->rgbBlue = pRGBClr->rgbGreen = pRGBClr->rgbRed = (BYTE)(iClrIdx&0x00FF);
				pRGBClr->rgbReserved = 0;
				pRGBClr++;
			}
		}else{
			pRGBClr->rgbBlue = pRGBClr->rgbGreen = pRGBClr->rgbRed = 0;
			pRGBClr->rgbReserved = 0;
			pRGBClr++;
			pRGBClr->rgbBlue = pRGBClr->rgbGreen = pRGBClr->rgbRed = 255;
			pRGBClr->rgbReserved = 0;
		}
	} else
		pbmi = (PBITMAPINFO) LocalAlloc(LPTR,sizeof(BITMAPINFOHEADER)); 
	pbmi->bmiHeader.biSize         = sizeof(BITMAPINFOHEADER); 
	pbmi->bmiHeader.biWidth        = Width; 
	pbmi->bmiHeader.biHeight       = Height; 
	pbmi->bmiHeader.biPlanes       = Planes; 
	pbmi->bmiHeader.biBitCount     = BitsPixel; 
	pbmi->bmiHeader.biCompression  = BI_RGB;
	pbmi->bmiHeader.biClrImportant = 0;
	pbmi->bmiHeader.biSizeImage = ((pbmi->bmiHeader.biWidth * cClrBits ) ) /8
		* pbmi->bmiHeader.biHeight;
	if (cClrBits < 24)
		pbmi->bmiHeader.biClrUsed = (1<<cClrBits);
	else
		pbmi->bmiHeader.biClrUsed = 0;
	
	pbmi->bmiHeader.biXPelsPerMeter = nDPI * 10000 / 254;
	pbmi->bmiHeader.biYPelsPerMeter = nDPI * 10000 / 254;
	
	return pbmi;
}

void CloseBMP(PBITMAPINFO lpBmpInfo)
{
	if (lpBmpInfo!=NULL)
		LocalFree(lpBmpInfo);
	lpBmpInfo = NULL;
}

HANDLE CreateBMPFile(LPTSTR pszFile) 
{ 
	HANDLE hf = INVALID_HANDLE_VALUE;   // file handle 
	
	// Create the .BMP file. 
	hf = CreateFile(pszFile, 
		GENERIC_READ | GENERIC_WRITE, 
		(DWORD) 0, 
		NULL, 
		CREATE_ALWAYS, 
		FILE_ATTRIBUTE_NORMAL, 
		(HANDLE) NULL); 
	if (hf == INVALID_HANDLE_VALUE)
		OutputDebugString("CreateFile error");
	
	return hf;
}

int WriteBMPHeader(HANDLE hBMP, PBITMAPINFO pbi)
{
	BITMAPFILEHEADER hdr;               // bitmap file-header 
	PBITMAPINFOHEADER pbih;             // bitmap info-header 
	DWORD dwTmp;                        // total count of bytes 
	
	
	pbih = (PBITMAPINFOHEADER) pbi; 
	
	hdr.bfType = 0x4d42;                // 0x42 = "B" 0x4d = "M" 
	// Compute the size of the entire file. 
	hdr.bfSize = (DWORD) (sizeof(BITMAPFILEHEADER) + 
		pbih->biSize + pbih->biClrUsed 
		* sizeof(RGBQUAD) + pbih->biSizeImage); 
	hdr.bfReserved1 = 0; 
	hdr.bfReserved2 = 0; 
	
	// Compute the offset to the array of color indices. 
	hdr.bfOffBits = (DWORD) sizeof(BITMAPFILEHEADER) + 
		pbih->biSize + pbih->biClrUsed 
		* sizeof (RGBQUAD); 
	
	// Copy the BITMAPFILEHEADER into the .BMP file. 
	if (!WriteFile(hBMP, (LPVOID) &hdr, sizeof(BITMAPFILEHEADER), 
		(LPDWORD) &dwTmp,  NULL)) {
		OutputDebugString("WriteFile error"); 
		return -1;
	}
	
	
	// Copy the BITMAPINFOHEADER and RGBQUAD array into the file. 
	if (!WriteFile(hBMP, (LPVOID) pbih, sizeof(BITMAPINFOHEADER) 
		+ pbih->biClrUsed * sizeof (RGBQUAD), 
		(LPDWORD) &dwTmp, ( NULL))){
		OutputDebugString("WriteFile error"); 
		return -2;
	}
	
	return hdr.bfSize;
}

int lCreateBMPHeader(const char *pFileName,int lImgW,int lImgH,short nBitsPerPixel,int nDPI)
{
    DWORD dwRet = 0;
	DWORD dwFileSize = 0;
    unsigned char AA[2] = {0};

	lpBmpInfo = CreateBitmapInfoStruct((LONG)(lImgW), 
		(LONG)(lImgH),	
		(WORD)1, 
		(WORD)(nBitsPerPixel),nDPI);

	if(!lpBmpInfo) return -1;

	hBMP = CreateBMPFile((char *)pFileName);
	if(hBMP == INVALID_HANDLE_VALUE)
		return -2;
	dwFileSize = WriteBMPHeader(hBMP, lpBmpInfo);
	if(dwFileSize < 0)
		return dwFileSize;
	else
		return 0;
}


/**
*  Description:
*      write bmp image buffer to file
*  Parameters:
*      pFileName[in]      : bmp image buffer
*      lImgBufSize        : bmp image buffer size
*  Return:
*      0 is success,else is faied.
**/
int lWriteBMPFile(unsigned char *pImgBuf,int lImgBufSize)
{
	BOOL bRet = FALSE;
	DWORD dwRet = 0;

    bRet = WriteFile(hBMP, pImgBuf, lImgBufSize, &dwRet, NULL);

	if(bRet)
		return 0;
	else
		return -1;
	
}

void lReleaseBMP()
{
   CloseBMP(lpBmpInfo);

  if(hBMP)
	 CloseHandle(hBMP);
   hBMP = NULL;
		
}