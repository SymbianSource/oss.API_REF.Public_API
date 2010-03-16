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
* Description:       Node filter interface
*
*/







#ifndef XMLENGINE_NODEFILTER_H_INCLUDED
#define XMLENGINE_NODEFILTER_H_INCLUDED

#include <e32base.h>

class TXmlEngNode;

/** 
 * Results that can be returned by node filter
 */
enum TXmlEngNodeFilterResult
    {
    EAccept = 1,
    EReject = 2,
    ESkip = 3,
    ESkipContents = 4  /** non-standard feature */
    }; 

/** 
 * Interface of nodes filter class
 *
 * @see http://www.w3.org/TR/2000/REC-DOM-Level-2-Traversal-Range-20001113/traversal.html#Traversal-NodeFilter
 *
 * @since S60 v3.1
 */
class MXmlEngNodeFilter
    {
public:
    /** 
     * Check if node is accepted.
     *
     * @since S60 v3.1
     * @param aNode Node to check
     * @return Node filter result
     */ 
    virtual TXmlEngNodeFilterResult AcceptNode(TXmlEngNode aNode) = 0;    
    };


#endif /* XMLENGINE_NODEFILTER_H_INCLUDED */  
