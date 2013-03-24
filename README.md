phonegap-InAppPurchaseARC
=========================

iOS InAppPurchase plugin for PhoneGap ARC project (Tested on Phonegap version 2.1)

This plugin is ARC version of [**InAppPurchaseManager plugin of usmart**](https://github.com/usmart/InAppPurchaseManager-EXAMPLE)

For more informations, [check here](http://ngoclt.me/post/34044184742/inapppurchasemanager-phonegap-2-1-plugin-arc-project): 

# HOW TO USE:

        // request product info
        window.plugins.inAppPurchaseManager.requestProductData("net.ngoclt.ProductExample",
            function(productId, title, description, price) {
                    console.log("productId: " + productId + " title: " + title + " description: " + description + " price: " + price);
                    // purchase product after got info
                    window.plugins.inAppPurchaseManager.makePurchase(productId, 1);
                }, function(id) {
                    console.log("Invalid product id: " + id);
                }
            );
        
        // Callback functions
        window.plugins.inAppPurchaseManager.onPurchased = function(transactionIdentifier, productId, transactionReceipt) {
            console.log('>>>>>>>>>>>>>> purchased: ' + productId);

            // navigator.notificationEx.loadingStop();
        }

        window.plugins.inAppPurchaseManager.onFailed = function(errno, errtext) {
            console.log('failed: ' + errtext);
            // navigator.notificationEx.loadingStop();
        }

        window.plugins.inAppPurchaseManager.onRestored = function(transactionIdentifier, productId, originalTransactionReceipt) {
            console.log('restored: ' + productId);
            // navigator.notificationEx.loadingStop();
        }
