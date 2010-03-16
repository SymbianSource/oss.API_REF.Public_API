/*
* Copyright (c) 2004-2006 Nokia Corporation and/or its subsidiary(-ies). 
* All rights reserved.
* This component and the accompanying materials are made available
* under the terms of the License "Symbian Foundation License v1.0" to Symbian Foundation members and "Symbian Foundation End User License Agreement v1.0" to non-members
* which accompanies this distribution, and is available
* at the URL "http://www.symbianfoundation.org/legal/licencesv10.html".
*
* Initial Contributors:
* Nokia Corporation - initial contribution.
*
* Contributors:
*
* Description:  Offers functionality for querying whether a feature is 
*                supported in the current environment.
*
*/


#ifndef FEATUREDISCOVERY_H
#define FEATUREDISCOVERY_H

//  INCLUDES
#include <e32std.h>


/**
* Class used to query which features are suppported in the environment. 
* Feature Discovery API provides methods which are used to query which
* features are supported in the environment. A feature is a functionality that
* can be optionally left out of some product configurations. Features often 
* depend on the underlying hardware. For example, MMC support or USB support
* can be features. The API consist of the CFeatureDiscovery class which is 
* used together with feature IDs defined in the featureinfo.h file.
*
*
* Usage:
*
* @code
*  #include <FeatDiscovery.h>
*  #include <featureinfo.h> // for feature definitions
*
*  // If querying only one feature, it is more efficient to use the class
*  // via the static method, IsFeatureSupportedL().
*  // When querying more than one feature, it is more efficient to use the 
*  // class by creating an instance and calling the IsSupported() method.
*
*  // Static way of using the class:
*  TBool isSupported = CFeatureDiscovery::IsFeatureSupportedL(KFeatureIdUsb);
*
*  // Dynamic way of using the class using NewL():
*  
*  // Call NewL() to create an instance of CFeatureDiscovery. 
*  CFeatureDiscovery* testA = CFeatureDiscovery::NewL();
* 
*  // Call the exported IsSupported() method to query whether features 
*  // are supported in the current environment or not.
*  TBool usbSupported = testA->IsSupported(KFeatureIdUsb);
*  TBool mmcSupported = testA->IsSupported(KFeatureIdMmc);
*
*  // Delete the created instance of CFeatureDiscovery.
*  delete testA;
*
*  // Dynamic way of using the class using NewLC():
* 
*  // Call NewLC() to create an instance of CFeatureDiscovery.
*  // The method leaves the instance of the object on the cleanup stack.
*  CFeatureDiscovery* testB = CFeatureDiscovery::NewLC();
*
*  // Call the exported IsSupported() method to query whether features 
*  // are supported in the current environment or not. 
*  TBool wcdmaSupported = testB->IsSupported(KFeatureIdProtocolWcdma);
*  TBool gsmSupported = testB->IsSupported(KFeatureIdProtocolGsm);
*
*  // Pop and delete the created instance of CFeatureDiscovery.
*  CleanupStack::PopAndDestroy();
* @endcode
*
* @lib featdiscovery.lib
* @since S60 2.8
*/

class CFeatureDiscovery : public CBase
    {
    public:

        /**
        * This is a two-phase constructor method that is used to create
        * a new instance of the CFeatureDiscovery class.
        *
        * @return a pointer to a new instance of the CFeatureDiscovery class.
        *
        * @leave One of the Symbian OS error codes
        */
		IMPORT_C static CFeatureDiscovery* NewL();

        /**
        * This is a two-phase constructor method that is used to create
        * a new instance of the CFeatureDiscovery class. This method leaves
        * the instance of the object on the cleanup stack.
        *
        * @return a pointer to a new instance of the CFeatureDiscovery class.
        *
        * @leave One of the Symbian OS error codes
        */
		IMPORT_C static CFeatureDiscovery* NewLC();

        /**
        * Destructor.
        */
		virtual ~CFeatureDiscovery();

		/**
        * Static way to fetch information whether a certain feature is 
        * supported in the current envinronment. There is no need to create
        * an instance of the class when using this method.
        *
        * @param aFeature is the feature ID of the feature that is queried.
        * @return a TBool indicating whether the feature is supported (ETrue)
        * or not (EFalse). If the feature does not exist, the return value is 
        * EFalse.
        *
        * @leave One of the Symbian OS error codes.
        */
		IMPORT_C static TBool IsFeatureSupportedL(TInt aFeature);

		/**
        * Dynamic way to fetch information whether a certain feature is 
        * supported in the current environment. Before calling the method 
        * an instance of the CFeatureDiscovery class need to be created by 
        * using one of the factory methods, NewL() or NewLC(). The created 
        * instance must be deleted after use.
        *
        * @param aFeature is the feature ID of the feature that is queried.
        * @return a TBool indicating whether the feature is supported (ETrue)
        * or not (EFalse). If the feature does not exist, the return value is 
        * EFalse.
        */
		IMPORT_C TBool IsSupported(TInt aFeature) const ;

    private:

        /**
        * C++ default constructor.
        */
		CFeatureDiscovery();

        /**
        * By default Symbian OS constructor is private.
        */
        void ConstructL();
    } ;


#endif  // FEATUREDISCOVERY_H

// EOF
