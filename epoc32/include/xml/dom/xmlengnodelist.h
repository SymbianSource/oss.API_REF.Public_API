/*
* Copyright (c) 2006-2006 Nokia Corporation and/or its subsidiary(-ies). 
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
* Description:       Node list inline functions
*
*/







#ifndef XMLENGINE_NODELIST_H_INCLUDED
#define XMLENGINE_NODELIST_H_INCLUDED

#include "xmlengnode.h"
#include "xmlengnodelist_impl.h"



/**
 * Template implements list container.
 *
 * List may contain different types of nodes.
 * Node pointer is casted to specify node type when
 * is returned by Next() method.
 *
 * @lib XmlEngineDOM.lib
 * @since S60 v3.2
 */
template<class T> 
class RXmlEngNodeList
{
public:
    /**
     * Get list length.
     *
     * @since S60 v3.2
     * @return Number of nodes in a node list
     */
	inline TInt Count() const;

    /**
     * Checks whether next node exists in a node list
     *
     * @since S60 v3.2
     * @return TRUE if next node exists, FALSE otherwise
     */
	inline TBool HasNext() const;

    /**
     * Retrieves next node from a node list
     *
     * @since S60 v3.2
     * @return Next node 
     */
	inline T Next();

    /**
     * Closes a node list
     *
     * @since S60 v3.2
     */
	inline void Close();

private:
    friend class TXmlEngNode;
    friend class TXmlEngElement;

    /*
     * Opens node.
     *
     * @since S60 v3.2
     * @param aHead node pointer to the node from which the searching 
            of list elements is started
     * @param aType type of list elements
     * @param aName name of list elements 
     * @param aNs namespace of list elements
     *
     * @note If aType is NULL, aName and aNs are ignored
     */
    void OpenL( 
			void* aHead,
			TXmlEngNode::TXmlEngDOMNodeType aType,
			const TDesC8&	aName = KNullDesC8,
			const TDesC8&	aNs = KNullDesC8);

    /** 
     * Opens node.
     *
     * @since S60 v3.2
     * @param aHead node pointer to the node from which the searching 
            of list elements is started
     * @param aType type of list elements
     */
    void Open( 
			void* aHead,
			TXmlEngNode::TXmlEngDOMNodeType aType);

    /** List with nodes */
	RXmlEngNodeListImpl iList;
};

/**
 * Template implements list container for nodes.
 *
 * Specialization for trivial case: list of TXmlEngNode objects
 * No "thin wrapper" pattern needed, operate directly on NodeListImpl
 *
 * @lib XmlEngineDOM.lib
 * @since S60 v3.1
 */
template<>
class RXmlEngNodeList<TXmlEngNode>: public RXmlEngNodeListImpl {};



#include "xmlengnodelist.inl"

#endif /* XMLENGINE_NODELIST_H_INCLUDED */
