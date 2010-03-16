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


#ifndef __HSWIDGET_H__
#define __HSWIDGET_H__

//  Include Files
#include <cctype>
#include <string>
#include <memory>
#include <vector>

namespace Hs {

class HsWidgetItem;

/**
 * Class defining a Homescreen Widget. A widget is identified by
 * its templateName, widgetName, uniqueIdentifier.
 * 
 * @code
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
 * HsWidget& widget =  hsPublisher->createHsWidget( 
 *     "templateName", "widgetName", "uniqueIdentifier" );
 * hsPublisher->publishHsWidget( widget ); 
 * @endcode
 */
class HsWidget
    {
public:
    /**
     * Adds a new widget item to the widget if it wasn't created 
     * previously or set a new value to the existing one.
     * Widget item is identified by the name with the value provided. 
     * The value is a string.
     *
     * @code
     * HsWidgetPublisher* hsPublisher = new HsWidgetPublisher( dataObserver );
     * HsWidget& widget =  hsPublisher->createHsWidget( 
     *     "templateName", "widgetName", "uniqueIdentifier" );
     * // assuming count and values[] are defined
     * while ( count )
     * {
     *    widget->setItem("image", values[count] );
     *    count--;
     * }
     * @endcode
     * @param aItemName, Name of the widget item.
     * @param aValue Integer value of the widget item.
     * @exception HsException
     */
    IMPORT_C void setItem( std::string aItemName, std::string aValue);
    
    /**
     * Adds a new widget item to the widget if it wasn't created previously 
     * or set a new value to the existing one. Widget item is identified by 
     * the name with the value provided. The value is a int.
     *
     * @code
     * HsWidgetPublisher* hsPublisher = new HsWidgetPublisher( dataObserver );
     * HsWidget& widget =  hsPublisher->createHsWidget( 
     *     "templateName", "widgetName", "uniqueIdentifier" );
     * // assuming count and values[] are defined
     * while ( count )
     * {
     *    widget->setItem("image", values[count] );
     *    count--;
     * }
     * @endcode
     * @param aItemName, Name of the widget item.
     * @param aValue Integer value of the widget item.
     * @exception HsException
     */
    IMPORT_C void setItem( std::string aItemName, int aValue );
    
    /**
     * Method removes widget's item.
     * An attempt to remove not existing item causes exception with 
     * KErrNotFound reason;
     *
     * @code
     * HsWidgetPublisher* hsPublisher = new HsWidgetPublisher( dataObserver );
     * HsWidget& widget =  hsPublisher->createHsWidget( 
     *     "templateName", "widgetName", "uniqueIdentifier" );
     * widget.setItem( "myItem", "value" );
     * widget.removeItem( "myItem" );
     * hsPublisher->removeHsWidget(
     *     "templateName", "widgetName", "uniqueIdentifier" );
     * @endcode
     * @param aItemName Name of the Item.
     * @param aWidgetName Name of the Widget
     * @param aIdentifier Unique identification of the content.
     * @exception HsException
     */
    IMPORT_C void removeItem( std::string aItemName );
    
public: 
    
    /**
     */
	HsWidget( std::string& aTemplateName, 
        std::string& aWidgetName,
        std::string& aIdentifier );

    /**
     */
    virtual ~HsWidget();
    
    /**
     */
    HsWidgetItem* getWidgetItem( std::string& aItemName );

    /**
     */
    const std::string& getWidgetName();
    
    /**
     */
    const std::string& getTemplateName();
    
    /**
     */
    const std::string& getIdentifier();
    
    /**
     */
    int itemsCount();
    
    /**
     */
    HsWidgetItem* getWidgetItem( int aIndex );
    
    /**
     */
    bool checkIfWidgetItemExist( std::string& aItemName );
    
private:
    std::string mWidgetName;
    std::string mTemplateName;
    std::string mIdentifier;
    std::vector<HsWidgetItem*> mItems;
    };

}


#endif /*__HSWIDGET_H__*/
