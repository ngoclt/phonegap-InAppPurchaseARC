//
//  InAppPurchaseManager.h
//  beetight
//
//  Created by Matt Kane on 20/02/2011.
//  Copyright 2011 Matt Kane. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <StoreKit/StoreKit.h>

#import <Cordova/CDVPlugin.h>

#import <Cordova/NSData+Base64.h>

#import "SKProduct+LocalizedPrice.h"

@interface InAppPurchaseManager : CDVPlugin <SKPaymentTransactionObserver> {

}
- (void) setup:(NSMutableArray*)arguments withDict:(NSMutableDictionary*)options;
- (void) makePurchase:(NSMutableArray*)arguments withDict:(NSMutableDictionary*)options;
- (void) requestProductData:(NSMutableArray*)arguments withDict:(NSMutableDictionary*)options;
- (void) requestProductsData:(NSMutableArray*)arguments withDict:(NSMutableDictionary*)options;
- (void) paymentQueue:(SKPaymentQueue *)queue updatedTransactions:(NSArray *)transactions;
- (void) paymentQueue:(SKPaymentQueue *)queue restoreCompletedTransactionsFailedWithError:(NSError *)error;
- (void) paymentQueueRestoreCompletedTransactionsFinished:(SKPaymentQueue *)queue;
// - (void) paymentQueue:(SKPaymentQueue *)queue updatedTransactions:(NSArray *)transactions;

+ (NSMutableDictionary *)requestedProduct;

@end

@interface ProductsRequestDelegate : NSObject <SKProductsRequestDelegate>{
	NSString* successCallback;
	NSString* failCallback;

	InAppPurchaseManager* command;
}

@property (nonatomic, copy) NSString* successCallback;
@property (nonatomic, copy) NSString* failCallback;
@property (nonatomic, strong) InAppPurchaseManager* command;

@end;

@interface BatchProductsRequestDelegate : NSObject <SKProductsRequestDelegate> {
	NSString* callback;
	InAppPurchaseManager* command;
}

@property (nonatomic, copy) NSString* callback;
@property (nonatomic, strong) InAppPurchaseManager* command;

@end;
