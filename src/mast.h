/*
 *  MAST: Multicast Audio Streaming Toolkit
 *
 *  By Nicholas J. Humfrey <njh@ecs.soton.ac.uk>
 *
 *  Copyright (C) 2003-2007 University of Southampton
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  $Id:$
 */


#include <ortp/ortp.h>


#ifndef	_MAST_H_
#define	_MAST_H_


// Defaults
#define DEFAULT_RTP_SSRC			(0)
#define DEFAULT_MULTICAST_TTL		(5)
#define DEFAULT_PAYLOAD_LIMIT		(1450)
#define DEFAULT_PAYLOAD_TYPE		"L16"
#define DEFAULT_RTP_PORT			(5004)
#define DEFAULT_TIMEOUT				(10)

// RAT only accepts packets if they contain multiples of 160 samples
#define FRAMES_PER_UNIT				(160)

// Standard string buffer size
#define STR_BUF_SIZE				(255)

// Payload type for MPEG Audio
#define RTP_MPEG_AUDIO_PT			(14)

// GSM codec specifics
#define	GSM_FRAME_SAMPLES	(160)
#define GSM_FRAME_BYTES		(33)
#define GSM_FRAME_SIGNATURE	(0xD0)



#ifndef TRUE
#define TRUE	(1)
#endif

#ifndef FALSE
#define FALSE	(0)
#endif


// Use by gethostname()
#ifndef HOST_NAME_MAX
#ifdef _POSIX_HOST_NAME_MAX
#define HOST_NAME_MAX	_POSIX_HOST_NAME_MAX
#else
#define HOST_NAME_MAX	(256)
#endif
#endif

#ifndef DOMAIN_NAME_MAX
#define DOMAIN_NAME_MAX	(1024)
#endif


// Message levels
#define MSG_LEVEL_DEBUG		(1)
#define MSG_LEVEL_INFO		(2)
#define MSG_LEVEL_WARNING	(3)
#define MSG_LEVEL_ERROR		(4)
#define MSG_LEVEL_FATAL		(5)


// Only display debugging messages if debugging is enabled
#ifdef DEBUGGING
#define MAST_DEBUG(s ...)  mast_message_handler( MSG_LEVEL_DEBUG, __FILE__, __LINE__, s )
#else
#define MAST_DEBUG
#endif

#define MAST_INFO(s ...)  mast_message_handler( MSG_LEVEL_INFO, __FILE__, __LINE__, s )
#define MAST_WARNING(s ...)  mast_message_handler( MSG_LEVEL_WARNING, __FILE__, __LINE__, s )
#define MAST_ERROR(s ...)  mast_message_handler( MSG_LEVEL_ERROR, __FILE__, __LINE__, s )
#define MAST_FATAL(s ...)  mast_message_handler( MSG_LEVEL_FATAL, __FILE__, __LINE__, s )

// In util.c
RtpSession *mast_init_ortp( char* tool_name, int mode );
char* mast_get_tool_name();
void mast_deinit_ortp( RtpSession *session );
char* mast_gethostname();
void mast_set_source_sdes( RtpSession *session );
void mast_message_handler( int level, const char* file, int line, char *fmt, ... );
int mast_still_running();
void mast_setup_signals();
int mast_parse_dscp( const char* value );
mblk_t *mast_wait_for_rtp_packet( RtpSession * session, int seconds );


#endif
