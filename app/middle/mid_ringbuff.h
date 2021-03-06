/*********************************************************************************
*       ring buffer
*										add by zm
*													2011-3-11
**********************************************************************************/
#ifndef __MID_RINGBUFFER_H__
#define __MID_RINGBUFFER_H__


typedef struct _RingBuffer {
	int		writePos;
	int		readPos;
	int		len;
	int		highWater;
	mid_mutex_t	mutex;
	char	*buf;
} ReachRingBuffer;

/*****************************************************************************************
*	 描述：创建ringbuff
*    输入： size    ringbuff总大小  highWater  水位(推荐位95)   ，
*			实际可以使用的buff大小为size*highWater/100
*    返回：ringbuff句柄
******************************************************************************************/
ReachRingBuffer *mid_create_ringbuff(int size, int highWater);

/*****************************************************************************************
*	 描述：销毁ringbuff ,释放资源
*    输入：ringbuff 句柄
*
*    返回：
******************************************************************************************/
void mid_free_ringbuff(ReachRingBuffer *ringBuffer);

/*****************************************************************************************
*	 描述：push buff到ringbuff
*    输入：  buf 需要push的buff指针
*			 len 需要push的buff长度
*    返回： -1 表示ringbuff 的空间小于需要push  0 表示push正常
******************************************************************************************/
int mid_push_ringbuff(ReachRingBuffer *ringBuffer, char *buf, int len);

/*****************************************************************************************
*	 描述：从ringbuff中get buff
*    输入： buf 准备get 的buff指针
* 			needLen  期望获取的buff的长度
*			readLen 实际从ringbuff中读到的buff的长度
*
*    返回： -1 表示没有读到数据  0 表示get正常
******************************************************************************************/
int mid_get_ringbuff(ReachRingBuffer *ringBuffer, char *buf, int needLen, int *readLen);

/*****************************************************************************************
*	 描述：获取ringbuff里面填充的buff长度
*    输入：
*
*    返回： ringbuff里面填充的buff长度
******************************************************************************************/
int mid_get_usesize_ringbuff(ReachRingBuffer *ringBuffer);

/*****************************************************************************************
*	 描述：获取ringbuff里面空闲的buff长度
*    输入：
*
*    返回：  ringbuff里面空闲的buff长度
******************************************************************************************/
int mid_get_freesize_ringbuff(ReachRingBuffer *ringBuffer);

/*****************************************************************************************
*	 描述： 清除ringbuff里面的buff,释放buff空间
*    输入：
*
*    返回：
******************************************************************************************/
void mid_clear_ringbuff(ReachRingBuffer *ringBuffer);

/*****************************************************************************************
*	 描述： 复位ringbuff里面的buff ,不释放buff空间
*    输入：
*
*    返回：  -1 表示失败，需要直接退出
******************************************************************************************/
int mid_reset_ringbuff(ReachRingBuffer *ringBuffer);

/*****************************************************************************************
*	 描述： 获取当前ringbuff是否接近满
*    输入：
*
*    返回： 1 表示满 0 表示未满
******************************************************************************************/
int mid_is_full_ringbuff(ReachRingBuffer *ringBuffer);

/*****************************************************************************************
*	 描述： 获取当前ringbuff是否达到高水位
*    输入：
*
*    返回：  1表示达到 0 表示未达到
******************************************************************************************/
int mid_is_highwater_ringbuff(ReachRingBuffer *ringBuffer);


#endif
