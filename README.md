# SLplayer
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
