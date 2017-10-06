//
//  SKCConversationActivity.h
//  Sparkcentral
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 *  @abstract An activity type indicating that the appMaker started typing a response
 */
extern NSString const *SKCConversationActivityTypeTypingStart;

/**
 *  @abstract An activity type indicating that the appMaker stopped typing a response
 */
extern NSString const *SKCConversationActivityTypeTypingStop;

/**
 *  @abstract A key whose value is an NSString representing the appMaker name.
 *
 *  @discussion This key is used in the SKCConversationActivity data object.
 */
extern NSString const *SKCConversationActivityDataNameKey;

/**
 *  @abstract A key whose value is an NSString representing the URL of the appMaker avatar.
 *
 *  @discussion This key is used in the SKCConversationActivity data object.
 */
extern NSString const *SKCConversationActivityDataAvatarUrlKey;

@interface SKCConversationActivity : NSObject

/**
 *  @abstract the role of who is performing the typing activity
 */
@property(readonly) NSString *role;

/**
 *  @abstract the type of activity that is being triggered. Could be either SKCConversationActivityTypeTypingStart or SKCConversationActivityTypeTypingStop
 */
@property(readonly) NSString *type;

/**
 *  @abstract additional data for this activity. Posible values are the appMaker's 'name' and/or 'avatarUrl'
 */
@property(readonly, nullable) NSDictionary *data;

@end
NS_ASSUME_NONNULL_END
