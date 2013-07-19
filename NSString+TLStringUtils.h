//
//  NSString+Utilities.h
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
@property(nonatomic, readonly) BOOL isCamelCaseString;
///Checks if the string is a valid email address.
@property(nonatomic, readonly) BOOL isValidEmail;

///Makes the string a Camel Case String, such as this: "Camel Case String".
- (NSString *)camelCaseString;

///Shorter method for concatenating a string.
- (NSString *)concat:(NSString *)string;

///Returns a mutable version of the receiver.
- (NSMutableString *)mutableString;

///Returns an array of strings seperated by spaces.
- (NSArray *)toArray;

///Retuns an array of strings seperated by delimiter.
- (NSArray *)toArrayWithDelimiter:(NSString *)delimiter;

///Provides subsript access to substrings by index.
- (id)objectAtIndexedSubscript:(NSUInteger)index;

/*!
 *Iterates over the receiver and returns only the values that pass the test of `YES` within the block.
 */
- (NSString *)filter:(BOOL (^)(NSString *subString, NSUInteger index))block;

/*!
 *Returns a new string with the changes applied in `block`. *stop is initially set to NO, if it is set to YES, the sequence will stop.
 */
- (NSString *)map:(NSString *(^)(NSString *subString, NSUInteger index, BOOL *stop))block;

@end
