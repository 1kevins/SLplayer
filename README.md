# SLplayer
## SLPlayer使用： pod 'SLPlayer'
###SLPlayer 是一个多功能的音乐播放器，持播放语音队列，播放单个音频，播放，暂停，上一首，下一首，快进，快退，缓存音频，下载音频等功能

## SLPlayerDelegate 
```object-c

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
```

## SLPlayerDataSource 

```object-c

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
```

## SLPlayer methods

```object-c
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
 @param isMemoryCached 是否需要缓存歌曲
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


```


## contact me  
1.[博客](http://christmascat.lofter.com)<br />  
2.[微博](http://weibo.com/3388333772/profile?topnav=1&wvr=6)<br />  
