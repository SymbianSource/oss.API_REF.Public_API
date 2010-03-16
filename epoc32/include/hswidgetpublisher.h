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


// This file defines the API for hswidgetpublisher.dll

#ifndef __HSWIDGETPUBLISHER_H__
#define __HSWIDGETPUBLISHER_H__

//  Include Files
#include <cctype>
#include <memory>
#include <string>

namespace Hs {

//  Class Definitions
class HsWidget;
class IHsDataObserver;
class HsWidgetPublisherImpl;

/**
 * Class allowing access to the Homescreen Publishing Api. 
 * Allows creation, update and deletion of widgets, as well as reception of
 * information for the occuring events.
 * 
 * @code
 * class ObserverClass : public IHsDataObserver
 * {
 *      void handleEvent( std::string aWidgetName, 
 *			IHsDataObserver::EEvent aEvent)
 *      {
 *      }
 * 
 *      void handleItemEvent( std::string aWidgetName,
 *        	std::string aWidgetItemName,
 *       	IHsDataObserver::EItemEvent aEvent)
 *      {
 *      }
 * }
 * 
 * ObserverClass* dataObserver = new ObserverClass();
 * HsWidgetPublisher* hsPublisher = new HsWidgetPublisher( dataObserver );
 * HsWidget& widget =  publisher->createHsWidget(
 *     "templateName", "widgetName", "uniqueIdentifier" );
 * // assuming count and values[] exists
 * while (count)
 * {
 *    widget->setItem( "image", values[count] );
 *    count--;
 * }
 * hsPublisher->publishHsWidget( widget ); 
 * @endcode
 */
class HsWidgetPublisher
    {
public:
    /**
     * Constructor of the HsWidgetPublisher. Creates an instance of the 
     * publisher, which is used to manage Widgets and Widget's Items. 
     * Please note that attempt of usage, with aDataObserver = NULL 
     * is asserted.
     *
     * @code
	 * class ObserverClass : public IHsDataObserver
	 * {
	 *      void handleEvent( std::string aWidgetName, 
	 *			IHsDataObserver::EEvent aEvent)
	 *      {
	 *      }
	 * 
	 *      void handleItemEvent( std::string aWidgetName,
	 *        	std::string aWidgetItemName,
	 *       	IHsDataObserver::EItemEvent aEvent)
	 *      {
	 *      }
	 * }       
     * 
     * ObserverClass* dataObserver = new ObserverClass();
     * HsWidgetPublisher* hsPublisher = new HsWidgetPublisher( dataObserver );
     * @endcode
     * 
     * Client should not completely rely on exceptions while creating 
     * the API. Except for exceptions thrown one should check if
     * the memory was allocated properly.
     * @code
     * 
     * ObserverClass* dataObserver = new ObserverClass();
     * 
     * try 
     * {
     *     HsWidgetPublisher* hsPublisher = new HsWidgetPublisher(dataObserver);
     *     if (hsPublisher)
     *     {
     *     // do the operations on the API here
     *     }
     * }
     * catch (HsException& exception)
     * {
     *     int errReason = exception.getReason();
     * }
     * @endcode
     *
     * @param aDataObserver Callback interface for handling actions.
     * @exception HsPException
     */
    IMPORT_C HsWidgetPublisher( IHsDataObserver* aDataObserver );
    
    /**
     * Destructor of the HsWidgetPublisher.
     *
     * @code
     * HsWidgetPublisher* hsPublisher = new HsWidgetPublisher( dataObserver );
     * delete hsPublisher;
     * @endcode
     * @exception HsException
     */
    IMPORT_C ~HsWidgetPublisher();
    
    /**
     * Method creates a new widget.
     * Attempt to create already existing widget will cause exception 
     * with KErrAlreadyExists reason.
     * Other exception reasons are possible and are caused by widget 
     * registration.
     * 
     * @code
     * HsWidgetPublisher* hsPublisher = new HsWidgetPublisher( dataObserver );
     * HsWidget& widget =  hsPublisher->createHsWidget( 
     *     "templateName", "widgetName", "uniqueIdentifier" );
     * @endcode
     * @param aTemplateName Name of the Template.
     * @param aWidgetName Name of the Widget
     * @param aIdentifier Unique identification of the content.
     * @return A widget is returned. If no such widget existed a newly
     * created one.
     * @exception HsException Exception is thrown when with code 
     * KErrAlreadyExists 
     * when attempting to create a widget that already exists. Other cases 
     * when excpetion is thrown include problems with widget registration. 
     */
    IMPORT_C HsWidget& createHsWidget( std::string aTemplateName, 
        std::string aWidgetName,
        std::string aIdentifier );

    /**
     * Method publishes the provided widget. 
     * Widget needs to be published in order for the content 
     * to be seen by the HS.
     *
     * @code
     * HsWidgetPublisher* hsPublisher = new HsWidgetPublisher( dataObserver );
     * HsWidget& widget =  hsPublisher->createHsWidget( 
     *     "templateName", "widgetName", "uniqueIdentifier" );
     * hsPublisher->publishHsWidget( widget ); 
     * @endcode
     * @param aWidget Reference to a widget object.
     * @exception HsException
     */
    IMPORT_C void publishHsWidget( HsWidget& aWidget );

    /**
     * Method removes a widget.
     *
     * @code
     * HsWidgetPublisher* hsPublisher = new HsWidgetPublisher( dataObserver );
     * hsPublisher->createHsWidget( 
     *     "templateName", "widgetName", "uniqueIdentifier" );
     * publisher->removeHsWidget(
     *     "templateName", "widgetName", "uniqueIdentifier" );
     * @endcode
     * @param aTemplateName Name of the Template.
     * @param aWidgetName Name of the Widget
     * @param aIdentifier Unique identification of the content.
     * @exception HsException
     */
    IMPORT_C void removeHsWidget( std::string aTemplateName, 
        std::string aWidgetName,
        std::string aIdentifier );
    
    /**
     * Obtains a Widget from Homescreen Publishing Api.
     * Attempt of obtaining Widget that was not created cause exception 
     * with KErrNotFound rason.
     * 
     *
     * @code
     * HsWidgetPublisher* hsPublisher = new HsWidgetPublisher( dataObserver );
     * hsPublisher->createHsWidget( 
     *     "templateName", "widgetName", "uniqueIdentifier" );
     * HsWidget& widget = hsPublisher->getHsWidget(
     *     "templateName", "widgetName", "uniqueIdentifier" );
     * @endcode
     * @param aTemplateName Name of the Template.
     * @param aWidgetName Name of the Widget
     * @param aIdentifier Unique identification of the content.
     * @return Error code.
     * @exception HsException
     */
    IMPORT_C HsWidget& getHsWidget( std::string aTemplateName, 
        std::string aWidgetName,
        std::string aIdentifier );

    
private: //members

    std::auto_ptr<HsWidgetPublisherImpl> mImpl;

    };
}

#endif  // __HSWIDGETPUBLISHER_H__

