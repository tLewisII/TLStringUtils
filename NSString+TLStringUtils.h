//
//  NSString+TLStringUtils.h
//  NSString addition
//
//  Created by Terry Lewis II on 7/18/13.
//  Copyright (c) 2013 Terry Lewis. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSString (TLStringUtils)
///Returns a BOOL indicating if the entire string is uppercase.
@property(nonatomic, readonly) BOOL isUppercaseString;
///Returns a BOOL indicating if the entire string is lowercase.
@property(nonatomic, readonly) BOOL isLowerCaseString;
///Returns a BOOL indicating if the string entire string is camelcase, such as This: "This Is A Camel Case String".
@property(nonatomic, readonly) BOOL isCapitalizedString;
///Checks if the string is a valid email address.
@property(nonatomic, readonly) BOOL isValidEmail;

///Shorter method for concatenating a string.
- (NSString *)concat:(NSString *)string;

///Returns a mutable version of the receiver.
- (NSMutableString *)mutableString;

///Returns an array of strings seperated by spaces.
- (NSArray *)toWordArray;

///Returns an array of all the characters in the string.
-(NSArray *)toCharacterArray;

///Retuns an array of strings seperated by delimiter.
- (NSArray *)ArrayWithDelimiter:(NSString *)delimiter;

///Provides subsript access to substrings by index.
- (id)objectAtIndexedSubscript:(NSUInteger)index;

/*!
 *Iterates over the receiver and returns only the values that pass the test of `YES` within the block.
 @param block, a block that contains a string and an index
 @returns A new NSString that only contains characters with passes the test in `block`
 */
- (NSString *)filter:(BOOL (^)(NSString *subString, NSUInteger index))block;

/*!
 *Returns a new string with the changes applied in `block`. *stop is initially set to NO, if it is set to YES, the sequence will stop.
 @param block, a block that contains a string, an index and a BOOL that can indicate that the fuction should stop
 @returns A new NSString that results from the transform applied in `block`
 */
- (NSString *)map:(NSString *(^)(NSString *subString, NSUInteger index, BOOL *stop))block;

/*!
 *Returns YES if any character in the string passes the test in `block`, returns NO otherwise.
 @param block, a block that contains a string and an index
 @returns A BOOL value indicating if the test was passed
 */
-(BOOL)anyCharacter:(BOOL (^)(NSString *subString, NSUInteger index))block;

/*!
 *Returns YES if any word in the string passes the test in `block`, returns NO otherwise. A word here is defined as being seperated by a space, such as: @" ";.
 @param block, a block that contains a string and an index
 @returns A BOOL value indicating if the test was passed
 */
-(BOOL)anyWord:(BOOL (^)(NSString *subString, NSUInteger index))block;

/*!
 *Returns YES if all character in the string pass the test in `block`, returns NO otherwise.
 @param block, a block that contains a string and an index
 @returns A BOOL value indicating if the test was passed
 */
-(BOOL)allCharacters:(BOOL (^)(NSString *subString, NSUInteger index))block;

/*!
 *Returns YES if all words in the string pass the test in `block`, returns NO otherwise. A word here is defined as being seperated by a space, such as: @" ";.
 @param block, a block that contains a string and an index
 @returns A BOOL value indicating if the test was passed
 */
-(BOOL)allWords:(BOOL (^)(NSString *subString, NSUInteger index))block;

@end
