//
//  ASPINRemoteImageDownloader.h
//  AsyncDisplayKit
//
//  Created by Garrett Moon on 2/5/16.
//
//  Copyright (c) 2014-present, Facebook, Inc.  All rights reserved.
//  This source code is licensed under the BSD-style license found in the
//  LICENSE file in the root directory of this source tree. An additional grant
//  of patent rights can be found in the PATENTS file in the same directory.
//

#if PIN_REMOTE_IMAGE

#import <Foundation/Foundation.h>
#import "ASImageProtocols.h"
#import <PINRemoteImage/PINRemoteImageManager.h>

NS_ASSUME_NONNULL_BEGIN

@interface ASPINRemoteImageDownloader : NSObject <ASImageCacheProtocol, ASImageDownloaderProtocol>

/**
 * A shared image downloader which can be used by @c ASNetworkImageNodes and @c ASMultiplexImageNodes
 *
 * This is the default downloader used by network backed image nodes if PINRemoteImage and PINCache are
 * available. It uses PINRemoteImage's features to provide caching and progressive image downloads.
 */
+ (ASPINRemoteImageDownloader *)sharedDownloader;

/**
 * The shared instance of a @c PINRemoteImageManager used by all @c ASPINRemoteImageDownloaders
 *
 * @discussion you can use this method to access the shared manager. This is useful to share a cache
 * and resources if you need to download images outside of an @c ASNetworkImageNode or 
 * @c ASMultiplexImageNode. It's also useful to access the memoryCache and diskCache to set limits
 * or handle authentication challenges.
 *
 * @return An instance of a @c PINRemoteImageManager
 */
- (PINRemoteImageManager *)sharedPINRemoteImageManager;

@end

NS_ASSUME_NONNULL_END

#endif
