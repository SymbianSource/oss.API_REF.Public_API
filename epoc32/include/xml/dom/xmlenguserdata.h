/*
* Copyright (c) 2004-2005 Nokia Corporation and/or its subsidiary(-ies). 
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
* Description:       Interface class describing class that may contains user
 *                 data aded to node
 *
*/







#ifndef XMLENGINE_USERDATA_H_INCLUDED
#define XMLENGINE_USERDATA_H_INCLUDED

#include <e32def.h>

/**
 * MXmlEngUserData is an abstract base class (interface) for user data that can be
 * stored in the DOM tree. Applications that wish to store user data in the 
 * DOM tree must wrap the user data in a class that implemens this interface.
 *
 * @lib XmlEngineDOM.lib
 * @since S60 v3.1
 */
class MXmlEngUserData {
public:
    /**
     * Free memory that is allocated and do other case specific cleanup.
     *
     * @since S60 v3.1
     */
    virtual void Destroy() = 0;
    
    /**
     * Make a copy of the the object. Note that if reference counting is used or
     * the same pointer can be safely copied to other places the implementation
     * of this method may just return a pointer to self.
     *
     * Copying user data when copying nodes has not been implemented
     * so this method is for future use (though there's no harm in implementing 
     * it, of course).
     *
     * @since S60 v3.1
     * @return Pointer to a copy of this object.
     */
    virtual MXmlEngUserData* CloneL() = 0;

    /**
     * Get id of the object. It is up to user-data provider what the result is.
     * Such a "user data identification" may be in use if several types of
     * MXmlEngUserData objects are used.
     *
     * @since S60 v3.1
     * @return Pointer that somehow identifies the type of MXmlEngUserData (NULL by default)
     */
    virtual void* ID() {return NULL;}
};



#endif /* XMLENGINE_USERDATA_H_INCLUDED*/
