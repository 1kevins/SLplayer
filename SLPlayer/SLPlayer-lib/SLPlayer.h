//
//  SLPlayer.h
//
//  Created by kevin on 17/04/28.
//  Copyright © 2016年 halewinner. All rights reserved.

#import <AvailabilityMacros.h>
#import <AVFoundation/AVFoundation.h>


typedef NS_ENUM(NSUInteger, SLPlayerReadyToPlay) { //播放器准备播放
    SLPlayerReadyToPlayPlayer = 3000,
    SLPlayerReadyToPlayCurrentItem = 3001,
};

typedef NS_ENUM(NSUInteger, SLPlayerFailed) {  //播放失败
    SLPlayerFailedPlayer = 4000,
    SLPlayerFailedCurrentItem = 4001,
};

// 代理
@protocol SLPlayerDelegate <NSObject>

@optional
/**
 *  代理，获取当前播放的index
 */
- (void)SLPlayerWillChangedAtIndex:(NSUInteger)index;


/**
 *  代理，获取当前播放的item
 */
- (void)SLPlayerCurrentItemChanged:(AVPlayerItem *)item;


/**
 *  代理，当前播放状态
 */
- (void)SLPlayerRateChanged:(BOOL)isPlaying;

/**
 *  代理，当前播放结束
 */
- (void)SLPlayerDidReachEnd;

/**
 *  代理，播放预加载时间
 */

- (void)SLPlayerCurrentItemPreloaded:(CMTime)time;
/**
 *  代理，播放失败的状态及原因
 */
- (void)SLPlayerDidFailed:(SLPlayerFailed)identifier error:(NSError *)error;
/**
 *  代理，播放成功
 */
- (void)SLPlayerReadyToPlay:(SLPlayerReadyToPlay)identifier;

@end

@protocol SLPlayerDataSource <NSObject>

@optional

/**
 *  DataSource，return 播放器播放多少item
 */
- (NSUInteger)SLPlayerNumberOfItems;


/**
 *  DataSource，return 播放器播放item的url
 */
- (NSURL *)SLPlayerURLForItemAtIndex:(NSUInteger)index preBuffer:(BOOL)preBuffer;


- (void)SLPlayerAsyncSetUrlForItemAtIndex:(NSUInteger)index preBuffer:(BOOL)preBuffer;

@end

//定义block

typedef void (^ Failed)(SLPlayerFailed identifier, NSError *error) DEPRECATED_MSG_ATTRIBUTE("deprecated since 2.5 version");
typedef void (^ ReadyToPlay)(SLPlayerReadyToPlay identifier) DEPRECATED_MSG_ATTRIBUTE("deprecated since 2.5 version");
typedef void (^ SourceAsyncGetter)(NSUInteger index) DEPRECATED_MSG_ATTRIBUTE("deprecated since 2.5 version");
typedef NSURL * (^ SourceSyncGetter)(NSUInteger index) DEPRECATED_MSG_ATTRIBUTE("deprecated since 2.5 version");

typedef NS_ENUM(NSUInteger, SLPlayerStatus) { //播放状态
    SLPlayerStatusPlaying = 0,
    SLPlayerStatusForcePause,
    SLPlayerStatusBuffering,
    SLPlayerStatusUnknown,
};

typedef NS_ENUM(NSUInteger, SLPlayerRepeatMode) {//播放模式
    SLPlayerRepeatModeOn = 0,
    SLPlayerRepeatModeOnce,
    SLPlayerRepeatModeOff,
};

typedef NS_ENUM(NSUInteger, SLPlayerShuffleMode) {//随机播放模式
    SLPlayerShuffleModeOn = 0,
    SLPlayerShuffleModeOff,
};

@interface SLPlayer : NSObject <AVAudioPlayerDelegate>

@property (nonatomic) id<SLPlayerDelegate> delegate;
@property (nonatomic) id<SLPlayerDataSource> datasource;
@property (nonatomic) NSUInteger itemsCount;
@property (nonatomic) BOOL disableLogs;//打印日志？
@property (nonatomic, strong, readonly) NSArray *playerItems;
@property (nonatomic, readonly) BOOL isInEmptySound; //空音频？
@property (nonatomic) BOOL popAlertWhenError; //提示错误？

+ (SLPlayer *)sharedInstance;

- (void)registerHandlerReadyToPlay:(ReadyToPlay)readyToPlay DEPRECATED_MSG_ATTRIBUTE("use SLPlayerDelegate instead");
- (void)registerHandlerFailed:(Failed)failed DEPRECATED_MSG_ATTRIBUTE("use SLPlayerDelegate instead");


- (void)setupSourceGetter:(SourceSyncGetter)itemBlock ItemsCount:(NSUInteger) count DEPRECATED_MSG_ATTRIBUTE("use SLPlayerDataSource instead.");
- (void)asyncSetupSourceGetter:(SourceAsyncGetter)asyncBlock ItemsCount:(NSUInteger)count DEPRECATED_MSG_ATTRIBUTE("use SLPlayerDataSource instead.");
- (void)setItemsCount:(NSUInteger)count DEPRECATED_MSG_ATTRIBUTE("use SLPlayerDataSource instead.");

/**
 设置url
 
 @param url URL
 @param index 下标
 */
- (void)setupPlayerItemWithUrl:(NSURL *)url index:(NSUInteger)index;

/**
 设置播放第几首
 
 @param startAt 下标
 */

- (void)fetchAndPlayPlayerItem: (NSUInteger )startAt;


/**
  删除全部item
 
 */
- (void)removeAllItems;
- (void)removeQueuesAtPlayer;


/*!
 注意，删除item 时需要同时更新 SLPlayerNumberOfItems
 */

- (void)removeItemAtIndex:(NSUInteger)index;
- (void)moveItemFromIndex:(NSUInteger)from toIndex:(NSUInteger)to;

/**
 设置播放
 */
- (void)play;

/**
 设置暂停
 */
- (void)pause;

/**
 强制暂停
 
 @param forcibly 是否强制暂停
 
 */
- (void)pausePlayerForcibly:(BOOL)forcibly;
/**
   上一首
 
 */
- (void)playPrevious;

/**
 下一首
 
 */
- (void)playNext;
/**
 播放到某一时刻
  @param CMTime 时间
 */
- (void)seekToTime:(double) CMTime;
- (void)seekToTime:(double) CMTime withCompletionBlock:(void (^)(BOOL finished))completionBlock;

/**
 设置播放模式
 @param mode 播放模式
 */
- (void)setPlayerRepeatMode:(SLPlayerRepeatMode)mode;
- (SLPlayerRepeatMode)getPlayerRepeatMode;
/**
 设置随机播放模式
 @param mode 是否随机播放模式
 */

- (void)setPlayerShuffleMode:(SLPlayerShuffleMode)mode;
- (SLPlayerShuffleMode)getPlayerShuffleMode;
/**
 是否正在播放
*/

- (BOOL)isPlaying;

/**
 获取当前item
 
 */
- (AVPlayerItem *)getCurrentItem;

/**
 获取当前播放状态
 */
- (SLPlayerStatus)getSLPlayerStatus;

/**
  添加代理
 */
- (void)addDelegate:(id<SLPlayerDelegate>)delegate DEPRECATED_MSG_ATTRIBUTE("set delegate property instead");
/**
 设置是否缓存歌曲
 @param isMemoryCached 洗牌是否需要缓存歌曲
 */
- (void)enableMemoryCached:(BOOL) isMemoryCached;
- (BOOL)isMemoryCached;

/**
 移除代理
 */
- (void)removeDelegate:(id<SLPlayerDelegate>)delegate DEPRECATED_MSG_ATTRIBUTE("Use delegate property instead");;
/**
 获取当前播放时长
 */
- (float)getPlayingItemCurrentTime;

/**
 获取总时长
 */
- (float)getPlayingItemDurationTime;
- (id)addPeriodicTimeObserverForInterval:(CMTime)interval
                                   queue:(dispatch_queue_t)queue
                              usingBlock:(void (^)(CMTime time))block;



- (NSNumber *)getHysteriaIndex:(AVPlayerItem *)item;

- (void)deprecatePlayer;

@end

