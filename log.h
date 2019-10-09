enum {
    LOG_LVL_LOG, // 0
    LOG_LVL_DEBUG, // 1
};

const char * log_level_strings [] = {
        "LOG", // 0
        "DEBUG", // 1
};


#define LOG_ENABLE 1

#define LL_DEBUG( fmt, arg...) LOG( LOG_LVL_DEBUG, fmt, ##arg)
#define LL_LOG( fmt, arg ... ) LOG( LOG_LVL_LOG, fmt, ##arg )


#define LOG(level, fmt, arg...) do {	\
	if ( LOG_ENABLE ) { \
		fprintf(stdout, "[%s] %s:%d: " fmt "\n", log_level_strings[level], __FUNCTION__,__LINE__, ##arg); \
		fflush( stdout ); \
	} \
} while(0)

