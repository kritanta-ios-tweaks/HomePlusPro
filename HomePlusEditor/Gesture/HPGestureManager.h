//
// Created by Kritanta on 6/24/21.
//

@import Foundation;
@import UIKit;
#import <objc/NSObject.h>

@class HPHitboxView;
@class HPHitboxWindow;
@class UISystemGestureView;

#ifndef HOMEPLUS_HPGESTURERECOGNIZERVIEW_H
#define HOMEPLUS_HPGESTURERECOGNIZERVIEW_H

@interface SBMainDisplaySystemGestureRecognizer : NSObject
+(SBMainDisplaySystemGestureRecognizer *)mainDisplayManager;
-(void)addGestureRecognizer:(UIGestureRecognizer *)recognizer withType:(NSUInteger)type;
@end
// _UISystemGestureManager addGestureRecognizer:toDisplayWithIdentity:
@class FBSDisplayIdentity;
@interface FBSDisplayConfiguration : NSObject
@property (nonatomic, retain) FBSDisplayIdentity *identity;
@end
@interface UIScreen (priv)
@property (nonatomic, retain) FBSDisplayConfiguration *displayConfiguration;
@end
@interface _UISystemGestureManager : NSObject
+(_UISystemGestureManager *)sharedInstance;
-(void)addGestureRecognizer:(UIGestureRecognizer *)recognizer toDisplayWithIdentity:(FBSDisplayIdentity *)identity;
@end


@interface HPGestureManager : NSObject

@property (nonatomic, assign) BOOL editorOpened;
@property (nonatomic, strong) UIPinchGestureRecognizer *inactiveGestureRecognizer;
@property (nonatomic, assign) CGFloat panAmount;
@property (nonatomic, assign) BOOL editorActivated;
@property (nonatomic, assign) BOOL hitboxMaxed;
@property (nonatomic, retain) HPHitboxView *hp_larger_hitbox;
@property (nonatomic, retain) HPHitboxWindow *hp_larger_window;
@property (nonatomic, retain) HPHitboxView *hp_hitbox;
@property (nonatomic, retain) HPHitboxWindow *hp_hitbox_window;

@property (nonatomic, retain) UISystemGestureView *systemGestureView;

@property (nonatomic, strong) UIPinchGestureRecognizer *activeGestureRecognizer;

+ (instancetype)sharedInstance;

- (void)insertGestureRecognizers:(UISystemGestureView *)systemGestureView;

- (void)handlePinchGesture:(UIPinchGestureRecognizer *)gestureRecognizer;
@end

// can we do both of these differently?

#define kMaxAmt 80

static CGFloat lastAmount = 1;

#endif //HOMEPLUS_HPGESTURERECOGNIZERVIEW_H