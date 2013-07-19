//
//  NSString+TLStringUtils.m
//  NSString addition
//
//  Created by Terry Lewis II on 7/18/13.
//  Copyright (c) 2013 Terry Lewis. All rights reserved.
//

#import "NSString+TLStringUtils.h"

@implementation NSString (TLStringUtils)
- (BOOL)isUppercaseString {
    return [self isEqualToString:self.uppercaseString];
}

- (BOOL)isLowerCaseString {
    return [self isEqualToString:self.lowercaseString];
}

- (BOOL)isCamelCaseString {
    BOOL success = YES; ///adad
    NSArray *stringArray = [self componentsSeparatedByString:@" "];
    for(NSString *string in stringArray) {
        if(![string substringWithRange:NSMakeRange(0, 1)].isUppercaseString) {
            success = NO;
            break;
        }
    }
    return success;
}

- (BOOL)isValidEmail {
    BOOL firstCheck = ([self rangeOfString:@"@"].location != NSNotFound);
    BOOL secondCheck = ([self rangeOfString:@"."].location != NSNotFound);
    return (firstCheck && secondCheck);
}

- (NSString *)camelCaseString {
    NSMutableString *mutableString = [NSMutableString new];
    NSArray *stringArray = [self componentsSeparatedByString:@" "];
    for(NSString *string in stringArray) {
        [mutableString appendString:[string substringToIndex:1].uppercaseString];
        [mutableString appendString:[string substringFromIndex:1]];
        [mutableString appendString:@" "];
    }
    return [NSString stringWithString:mutableString];
}

- (NSString *)concat:(NSString *)string {
    return [self stringByAppendingString:string];
}

- (NSMutableString *)mutableString {
    return [NSMutableString stringWithString:self];
}

- (NSArray *)toWordArray {
    return [self ArrayWithDelimiter:@" "];
}

-(NSArray *)toCharacterArray {
    NSMutableArray *characterArray = [NSMutableArray arrayWithCapacity:self.length];
    for(NSUInteger i = 0; i < self.length; i++) {
        NSString *subString = [self substringWithRange:NSMakeRange(i, 1)];
        characterArray[i] = subString;
    }
    return [NSArray arrayWithArray:characterArray];
}

- (NSArray *)ArrayWithDelimiter:(NSString *)delimiter {
    return [self componentsSeparatedByString:delimiter];
}

- (NSString *)filter:(BOOL (^)(NSString *subString, NSUInteger index))block {
    BOOL passedTest = NO;
    NSMutableString *mutableString = [NSMutableString string];
    for(NSUInteger i = 0; i < self.length; i++) {
        NSString *subString = [self substringWithRange:NSMakeRange(i, 1)];
        passedTest = block(subString, i);
        if(passedTest) [mutableString appendString:subString];
    }
    return [NSString stringWithString:mutableString];
}

- (NSString *)map:(NSString *(^)(NSString *subString, NSUInteger index, BOOL *stop))block {
    NSMutableString *mutableString = [NSMutableString string];
    BOOL stop = NO;
    for(NSUInteger i = 0; i < self.length; i++) {
        if(stop) break;
        NSString *subString = [self substringWithRange:NSMakeRange(i, 1)];
        [mutableString appendString:block(subString, i, &stop)];
    }
    return [NSString stringWithString:mutableString];
}

- (id)objectAtIndexedSubscript:(NSUInteger)index {
    return [self substringWithRange:NSMakeRange(index, 1)];
}

@end
