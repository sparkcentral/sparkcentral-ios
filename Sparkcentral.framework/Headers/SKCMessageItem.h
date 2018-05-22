//
//  SKCMessageItem.h
//  Sparkcentral
//

#import <Foundation/Foundation.h>

@interface SKCMessageItem : NSObject

/**
 *  @abstract The title of the item
 */
@property(copy, nullable) NSString *title;

/**
 *  @abstract Array of `SKCMessageAction` buttons
 *
 *  @see SKCMessageAction
 */
@property(nullable) NSArray *actions;

/**
 *  @abstract The text description, or subtitle
 */
@property(copy, nullable) NSString *itemDescription;

/**
 *  @abstract The image URL to be shown in the item
 */
@property(copy, nullable) NSString *mediaUrl;

/**
 *  @abstract The mediaType of the `mediaUrl`
 */
@property(copy, nullable) NSString *mediaType;

@end