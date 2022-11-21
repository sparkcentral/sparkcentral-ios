//
//  SKCMessage.h
//  Sparkcentral
//

#import <UIKit/UIKit.h>
#import "SKCCoordinates.h"
#import "SKCDisplaySettings.h"

/**
 *  @abstract Notification that is fired when a message fails to upload.
 */
extern NSString* _Nonnull const SKCMessageUploadFailedNotification;

/**
 *  @abstract Notification that is fired when a message uploads successfully.
 */
extern NSString* _Nonnull const SKCMessageUploadCompletedNotification;

/**
 *  @abstract A type of message that contains an image, text, and/or action buttons
 */
extern NSString* _Nonnull const SKCMessageTypeImage;

/**
 *  @abstract A type of message that contains text and/or action buttons
 */
extern NSString* _Nonnull const SKCMessageTypeText;

/**
 *  @abstract A type of message that contains a location
 */
extern NSString* _Nonnull const SKCMessageTypeLocation;

/**
 *  @abstract A type of message that contains a file and/or text
 */
extern NSString* _Nonnull const SKCMessageTypeFile;

/**
 *  @abstract A type of message that contains a horizontally scrollable set of items
 */
extern NSString* _Nonnull const SKCMessageTypeCarousel;

/**
 *  @abstract A type of message that contains a vertically scrollable set of items
 */
extern NSString* _Nonnull const SKCMessageTypeList;

/**
 *  @discussion Upload status of an SKCMessage.
 *
 *  @see SKCMessage
 */
typedef NS_ENUM(NSInteger, SKCMessageUploadStatus) {
    /**
     *  A user message that has not yet finished uploading.
     */
    SKCMessageUploadStatusUnsent,
    /**
     *  A user message that failed to upload.
     */
    SKCMessageUploadStatusFailed,
    /**
     *  A user message that was successfully uploaded.
     */
    SKCMessageUploadStatusSent,
    /**
     *  A message that did not originate from the current user.
     */
    SKCMessageUploadStatusNotUserMessage
};

/// A class representing a message.
@interface SKCMessage : NSObject <NSSecureCoding>

/**
 *  @abstract Create a message with the given text. The message will be owned by the current user.
 */
-(nonnull instancetype)initWithText:(nonnull NSString*)text;

/**
 *  @abstract Create a message with the given text, payload, and metadata. The message will be owned by the current user
 */
-(nonnull instancetype)initWithText:(nonnull NSString *)text payload:(nullable NSString *)payload metadata:(nullable NSDictionary *)metadata;

/**
 *  @abstract Create a message with the given coordinates, payload, and metadata. The message will be owned by the current user
 */
-(nonnull instancetype)initWithCoordinates:(nonnull SKCCoordinates *)coordinates payload:(nullable NSString *)payload metadata:(nullable NSDictionary *)metadata;

/**
 *  @abstract The unique identifier of the message. May be nil if a unique identifier has not been generated for this message
 */
@property(readonly, nullable) NSString* messageId;

/**
 *  @abstract The text content of the message. May be nil if mediaUrl or actions are provided
 */
@property(nullable) NSString* text;

/**
 *  @abstract The text fallback to display for message types not supported by the SDK. May be nil
 */
@property(nullable) NSString* textFallback;

/**
 *  @abstract The displayName of the author. This property may be nil if no displayName could be determined.
 */
@property(nullable) NSString* displayName;

/**
 *  @abstract The url for the author's avatar image. May be nil
 */
@property(nullable) NSString* avatarUrl;

/**
 *  @abstract The date and time the message was sent
 */
@property(nullable) NSDate *date;

/**
 *  @abstract Returns YES if the message originated from the user, or NO if the message comes from the app team.
 */
@property (nonatomic) BOOL isFromCurrentUser;

/**
 *  @abstract The upload status of the message.
 *
 *  @see SKCMessageStatus
 */
@property(readonly) SKCMessageUploadStatus uploadStatus;

/**
 *  @abstract An array of SKCMessageAction objects representing the actions associated with this message (if any)
 *
 *  @discussion This array may be nil or empty, so check the length of the array to know if a message has actions or not.
 *
 *  @see SKCMessageAction
 */
@property(readonly, nullable) NSArray* actions;

/**
 *  @abstract An array of SKCMessageItem objects representing the items associated with this message
 *
 *  @discussion Only messages of type `SKCMessageTypeCarousel` and `SKCMessageTypeList` contain items.
 *
 *  @see SKCMessageItem
 */
@property(readonly, nullable) NSArray* items;

/**
 *  @abstract The url to the media asset, if applicable. Returns nil if the message is not an image or file message.
 */
@property(nullable) NSString* mediaUrl;

/**
 *  @abstract The size of the media asset in bytes. May be nil.
 */
@property(nullable) NSNumber* mediaSize;

/**
 *  @abstract The type the message.
 *
 *  @discussion Valid types include SKCMessageTypeText, SKCMessageTypeImage, and SKCMessageTypeLocation
 */
@property(nullable) NSString* type;

/**
 *  @abstract Coordinates for a location for a message of type SKCMessageTypeLocation
 */
@property(readonly, nullable) SKCCoordinates *coordinates;

/**
 *  @abstract Settings to adjust the layout of a message of type SKCMessageTypeCarousel
 *
 *  @see SKCDisplaySettings
 */
@property(readonly, nullable) SKCDisplaySettings *displaySettings;

/**
 *  @abstract The role of the message.
 *
 *  @discussion Valid roles include `appUser`, `business`, and `whisper`. Messages created with -initWithText: have role of `appUser`.
 */
@property(readonly, nullable) NSString* role;

/**
 *  @abstract Metadata associated with the message.
 *
 *  @discussion A flat dictionary of metadata set through the REST API. May be nil.
 */
@property(nullable) NSDictionary* metadata;

/**
 *  @abstract The payload of an action with type SKCMessageActionTypeReply
 *
 *  @discussion The payload of a SKCMessageActionTypeReply, if applicable. May be nil
 */
@property(nullable) NSString* payload;

@end
