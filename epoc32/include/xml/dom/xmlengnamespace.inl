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
* Description:       Namespace node functions
*
*/









// -----------------------------------------------------------------------------
// Default constructor
// -----------------------------------------------------------------------------
//
inline TXmlEngNamespace::TXmlEngNamespace():TXmlEngNode(NULL)
    {
    }
    
// -----------------------------------------------------------------------------
// Workaround to avoid misuse of TXmlEngNode::NamespaceUri() method, which should not 
// be applied to TXmlEngNamespace node. Since the name of the inherited method from 
// TXmlEngNode is too similar to TXmlEngNamespace::Uri(), NamespaceUri() is disabled for 
// direct use. 
//		
// If NamespaceUri() is called on the TXmlEngNamespace object that is downcasted to 
// TXmlEngNode, then NamespaceUri()'s result equals to result of Uri() method.
// -----------------------------------------------------------------------------
//
inline TPtrC8 TXmlEngNamespace::NamespaceUri()
    {
    return KNullDesC8();
    }    

// -----------------------------------------------------------------------------
// Constructor
// -----------------------------------------------------------------------------
//
inline TXmlEngNamespace::TXmlEngNamespace(void* aPtr):TXmlEngNode(aPtr)
    {
    }
    
