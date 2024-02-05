#ifndef __FGETFILEINFO_H__
#define __FGETFILEINFO_H__
/**
*  ���������ļ������������С
*  ������path[in] : �ļ�����
*        start_pos[in] : �ļ���ȡ����ʼλ��
*        buf[out] : �������ļ�BUFFER
*  ���أ��ɹ������ļ���С�����򷵻ظ�ֵ��
**/
int fReadDiskFile(const char *path, int start_pos, unsigned char **buf);
/**
*  �������ͷŵ���fReadDiskFile�������ļ�BUFFER
*  ������
*        buf[in] : �ļ�BUFFER
*  ���أ�void
**/
void fFreeReadDiskFile(unsigned char *buf);
/**
*  ������д�ļ������������С
*  ������path[in] : �ļ�����
*        start_pos[in] : �ļ�д����ʼλ��
*        buf[in] : д���ļ�BUFFER
*        buf_len[in] : д���ļ�BUFFER��С
*  ���أ��ɹ������ļ���С�����򷵻ظ�ֵ��
**/
int fWriteDiskFile(const char *path, int start_pos, unsigned char *buf, int buf_len);


#endif