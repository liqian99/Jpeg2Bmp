#include <stdlib.h>
#include <stdio.h>
#include "fGetFileInfo.h"

int fGetFileSize(FILE *fp)
{
	int pos;
	int pos_cur;
	
	pos_cur=ftell(fp);
	if(pos_cur < 0) return pos_cur;
	if(fseek(fp, 0, SEEK_END) == 0)
	{
		pos=ftell(fp);
		if(pos < 0) return pos;
		if(fseek(fp, pos_cur, SEEK_SET) !=0)
		   return -1;
	}

	return pos;
}

int fGetDiskFileSize(const char *path)
{
	FILE *fp = NULL;
	int len = 0;
	fp = fopen(path, "rb");
	if (fp == NULL)
		return 0;
	
	len = fGetFileSize(fp);
	fclose(fp);

	return len;
}

int fReadDiskFile(const char *path, int start_pos, unsigned char **buf)
{
	FILE *fp = NULL;
	int len = 0, ret;
	
	fp = fopen(path, "rb");
	if (fp == NULL)
		return -1;
	
	len = fGetFileSize(fp);
	len -= start_pos;
	if(len <=0)
	{
		fclose(fp);
		return -1;
	}

	*buf = (unsigned char *)malloc(len);
	if(*buf == NULL){
		fclose(fp);
		return -1;
	}
	
	if(fseek(fp, start_pos, SEEK_SET) == 0)
	{
		ret = fread(*buf,1,len,fp);
	}
	
	fclose(fp);
	if(ret==len)
		return len;
	else
		return -1;
}


void fFreeReadDiskFile(unsigned char *buf)
{
	free(buf);
}

int fWriteDiskFile(const char *path, int start_pos, unsigned char *buf, int buf_len)
{
	FILE *fp;
	int ret;
	int len = 0;

	fp = fopen(path, "ab");
	if (fp == NULL)
		return -1;
	len = buf_len;
	if(fseek(fp, start_pos, SEEK_SET) == 0)
	{
      	ret = fwrite(buf, 1, len, fp);
	}

	fclose(fp);
	if(ret == len)
		return len;
	else
		return -1;
}

