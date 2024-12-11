/*   Copyright 2018-2021 Prebid.org, Inc.

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

 http://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
 */

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class UIView;
@class PBMAbstractCreative;
@class PBMViewExposure;
@class PBMCreativeViewabilityTracker;

typedef void(^PBMViewExposureChangeHandler)(PBMCreativeViewabilityTracker *tracker, PBMViewExposure *viewExposure);

@interface PBMCreativeViewabilityTracker : NSObject

@property (nonatomic, assign) BOOL isViewabilityMode;

- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithView:(UIView *)view pollingTimeInterval:(NSTimeInterval)pollingTimeInterval onExposureChange:(PBMViewExposureChangeHandler)onExposureChange NS_DESIGNATED_INITIALIZER;
- (instancetype)initWithCreative:(PBMAbstractCreative *)creative;

- (void)start;
- (void)stop;

/**
 Checks the current exposure.
 The onExposureChange will be called either exposure changed or isForce is true
 */
- (void)checkExposureWithForce:(BOOL)isForce;

@end

NS_ASSUME_NONNULL_END
