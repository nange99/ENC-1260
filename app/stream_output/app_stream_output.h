#ifndef _APP_STREAM_OUTPUT_H__
#define _APP_STREAM_OUTPUT_H__

typedef struct APP_VIDEO_INFO_T {
	int width;
	int height;
	unsigned int timestamp;

	int IsIframe;
	unsigned int rtp_time;
} APP_VIDEO_DATA_INFO;

typedef struct APP_AUDIO_INFO_T {
	int channel;
	int samplerate;
	unsigned int timestamp;

	int recreate; /*表示重建编码器，需要刷新  audio sdp info*/
		unsigned int rtp_time;
} APP_AUDIO_DATA_INFO;




void app_stream_output_init(unsigned int localip);
int app_stream_video_output(unsigned char *buff, int len, APP_VIDEO_DATA_INFO *info);
int app_stream_audio_output(unsigned char *buff, int len, APP_AUDIO_DATA_INFO *info);

//void app_build_reset_time();



#endif
