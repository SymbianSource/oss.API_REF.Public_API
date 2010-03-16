/*
* Copyright (c) 2007 Nokia Corporation and/or its subsidiary(-ies). 
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
* Description:  Updates applications and icons in Operator Tile.
*
*/


#ifndef __HSEXCEPTION_H__
#define __HSEXCEPTION_H__

#include <exception>

namespace Hs {

/**
 * Class used to encapsulate error information thrown in exceptions by the
 * Homescreen Publishing Api.
 * @code
 * 
 * ObserverClass* dataObserver = new ObserverClass();
 * try 
 * {
 *     HsWidgetPublisher* hsPublisher = new HsWidgetPublisher( dataObserver );
 *     if ( hsPublisher )
 *     {
 *         HsWidget& widget =  hsPublisher->createHsWidget( 
 *             "templateName", "widgetName", "uniqueIdentifier" );
 *         //attempt to create the widget again (with the same information) 
 *         //will cause an exception
 *         hsPublisher->createHsWidget( 
 *             "templateName", "widgetName", "uniqueIdentifier" );
 *     }
 * }
 * catch (HsException& exception)
 * {
 *     int errReason = exception.getReason();
 *     //if the exception is thrown, becasue the widget attempted to
 *     //be created already exists the errReason will be KErrAlreadyExists
 * }
 * @endcode
 */
class HsException : public std::exception
    {
public:
	
    /**
     * Constructor of the HsException.
     */
	IMPORT_C HsException( int aLeaveCode );

    /**
     * Destructor of the HsException.
     */
	IMPORT_C virtual ~HsException();
    
    /**
     * Method retrieves the error information contained in the 
     * excpetion object.
     *
     * @code
     * ObserverClass* dataObserver = new ObserverClass();
     * try 
     * {
     *     HsWidgetPublisher* hsPublisher = new HsWidgetPublisher(dataObserver);
     *     hsPublisher->createHsWidget( 
     *         "templateName", "widgetName", "uniqueIdentifier" );
     * }
     * catch (HsException& exception)
     * {
     *      int errReason = exception.getReason();
     * }
     * @endcode
     * @return Error code.
     */
	IMPORT_C int getReason();

private:

	int mLeaveCode;
    
    };
}

#endif /*__HSEXCEPTION_H__*/
