//
//  SKCMessageAction.h
//  Sparkcentral
//

#import <Foundation/Foundation.h>

/**
 *  @abstract Type for a link action.
 */
extern NSString* _Nonnull const SKCMessageActionTypeLink;

/**
 *  @abstract Type for a buy action.
 */
extern NSString* _Nonnull const SKCMessageActionTypeBuy;

/**
 *  @abstract Type for a postback action.
 */
extern NSString* _Nonnull const SKCMessageActionTypePostback;

/**
 *  @abstract Type for a reply action
 */
extern NSString* _Nonnull const SKCMessageActionTypeReply;

/**
 *  @abstract Type for a location request
 */
extern NSString* _Nonnull const SKCMessageActionTypeLocationRequest;

/**
 *  @abstract Offered state for a buy message. The user has not yet completed the transaction.
 */
extern NSString* _Nonnull const SKCMessageActionStateOffered;

/**
 *  @abstract Paid state for a buy message. The user has completed the transaction and payment was successful.
 */
extern NSString* _Nonnull const SKCMessageActionStatePaid;

/**
 *  @abstract An action associated to a particular SKCMessage.
 *
 *  Actions are rendered as buttons in the Sparkcentral conversation screen, and may be of type `SKCMessageActionTypeLink`, `SKCMessageActionTypeBuy` or `SKCMessageActionTypePostback`.
 *
 *  @see SKCMessage
 */
@interface SKCMessageAction : NSObject

/**
 *  @abstract The unique identifier representing the action.
 */
@property(readonly, nullable) NSString* actionId;

/**
 *  @abstract The type of action.
 *
 *  @discussion Valid types include `SKCMessageActionTypeLink` for regular actions, and `SKCMessageActionTypeBuy` for buy actions.
 */
@property(nullable) NSString* type;

/**
 *  @abstract The text to display as a descriptor for the action.
 *
 *  @discussion May not be nil.
 */
@property(nullable) NSString* text;

/**
 *  @abstract The URI to navigate to if the user interacts with the action.
 *
 *  @discussion May not be nil if message is of type `SKCMessageActionTypeLink`
 */
@property(nullable) NSURL* uri;

/**
 *  @abstract Metadata associated with the action.
 *
 *  @discussion A flat dictionary of metadata set through the REST API. May be nil.
 */
@property(nullable) NSDictionary* metadata;

/**
 *  @abstract Icon to display with a reply
 *
 *  @discussion An icon to render next to the reply option
 */
@property(nullable) NSString* iconUrl;

/**
 *  @abstract The payload of actions with type SKCMessageActionTypeReply or SKCMessageActionTypePostback
 *
 *  @discussion The payload of actions with type SKCMessageActionTypeReply or SKCMessageActionTypePostback, if applicable. May be nil
 */
@property(nullable) NSString* payload;

#pragma mark - Buy actions

/**
 *  @abstract The purchase state of the action
 *
 *  @discussion This property is only non-nil for actions of type `SKCMessageActionTypeBuy`. Valid states include `SKCMessageActionStateOffered` and `SKCMessageActionStatePaid`.
 */
@property(nullable) NSString* state;

/**
 *  @abstract The amount of money to charge for the action.
 *
 *  @discussion This property is only valid for actions of type `SKCMessageActionTypeBuy`. For USD, this value is in cents.
 */
@property long amount;

/**
 *  @abstract The currency in which the `amount` is expressed.
 *
 *  @discussion This property is only valid for actions of type `SKCMessageActionTypeBuy`.
 */
@property(nullable) NSString* currency;

@end
