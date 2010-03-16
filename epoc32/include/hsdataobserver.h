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


#ifndef __HSDATAOBSERVER_H__
#define __HSDATAOBSERVER_H__

#include <string>

namespace Hs {
/**
 * An observer interface. 
 * Client must implement it to be able to get information
 * about occuring Execute actions from the Homescreen Publishing API.
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
 * ObserverClass* dataObserver = new ObserverClass();
 * HsWidgetPublisher* hsPublisher = new HsWidgetPublisher( dataObserver );
 * @endcode
 */
class IHsDataObserver
    {
public:
    
	/**
	 * Defines the events that may take place for a homescreen widget.
	 */
	enum EEvent
	    {
	    EUnknown    = 0, ///< Unknown event: Means that event has not been defined.
	    EActivate   = 1, ///< Activation event: Means that widget has been added to HS as content.
	    EDeactivate = 2, ///< Deactivation event: Means that widget has been removed frm.
	    ESuspend    = 3, ///< Suspension event: Means that HS reading widget data is suspended.
	    EResume     = 4  ///< Resume event. Means that HS reading widget data is resumed.
	    };
    
	/**
	 * Defines the events that may take place for a homescreen widget item.
	 */
	enum EItemEvent
	    {
	    EUnknownItemEvent = 0, ///< Unknown event: Means that event has note been defined.
	    ESelect           = 1  ///< Selection event: Means that the widget item has been selected.
	    };
    
public:

	/**
	 * Intended to handle an event that occured on a widget.
	 * This would include EActivate, EDeactivate, ESuspend, EReusume.
	 *
	 * @param aWidgetName Name of the widget that event is envoked for.
	 * @param aEvent Event type that has taken place.
	 */
	virtual void handleEvent( std::string aWidgetName, 
			IHsDataObserver::EEvent aEvent) = 0;
	
	/**
	 * Intended to handle an event that occured on a widget's item.
	 * This would include ESelection.
	 *
	 * @param aWidgetName Name of the widget that event is envoked for.
	 * @param awidgetItemName Name of the item that event is envoked for.
	 * @param aAEvent Event type that has taken place
	 */    
	virtual void handleItemEvent( std::string aWidgetName,
			std::string aWidgetItemName,
			IHsDataObserver::EItemEvent aEvent) = 0;
    };
}

#endif /*__HSDATAOBSERVER_H__*/
