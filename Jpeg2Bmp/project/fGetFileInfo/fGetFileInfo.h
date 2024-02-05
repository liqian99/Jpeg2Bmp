#ifndef __FGETFILEINFO_H__
#define __FGETFILEINFO_H__
/**
*  描述：读文件，并返回其大小
*  参数：path[in] : 文件名称
*        start_pos[in] : 文件读取的起始位置
*        buf[out] : 读到的文件BUFFER
*  返回：成功返回文件大小，否则返回负值。
**/
int fReadDiskFile(const char *path, int start_pos, unsigned char **buf);
/**
*  描述：释放调用fReadDiskFile产生的文件BUFFER
*  参数：
*        buf[in] : 文件BUFFER
*  返回：void
**/
void fFreeReadDiskFile(unsigned char *buf);
/**
*  描述：写文件，并返回其大小
*  参数：path[in] : 文件名称
*        start_pos[in] : 文件写的起始位置
*        buf[in] : 写的文件BUFFER
*        buf_len[in] : 写的文件BUFFER大小
*  返回：成功返回文件大小，否则返回负值。
**/
int fWriteDiskFile(const char *path, int start_pos, unsigned char *buf, int buf_len);


#endif