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
* Description:       Node class declaration
*
*/







#ifndef XMLENGINE_NODE_H_INCLUDED
#define XMLENGINE_NODE_H_INCLUDED

#include <e32base.h>

// forward declaration
class TXmlEngNode;

// Forward declarations
template<class T> class RXmlEngNodeList;

class RXmlEngDocument;
class TXmlEngElement;
class TXmlEngAttr;
class TXmlEngTextNode;
class TXmlEngNamespace;
class TXmlEngComment;
class TXmlEngCDATASection;
class TXmlEngDocumentFragment;
class TXmlEngEntityReference;
class TXmlEngProcessingInstruction;
class MXmlEngUserData;
class TXmlEngBinaryContainer;
class TXmlEngChunkContainer;
class TXmlEngDataContainer;
class TXmlEngFileContainer;
//

/**
 * Instance of TXmlEngNode class represents an XML node in the DOM tree.
 *
 * Class implements methods that are similar for all XML node types
 * i.e. element, attribute.
 * 
 * Sample code for node tree modifications:
 * @code  
 *      RXmlEngDOMImplementation domImpl;
 *      domImpl.OpenL();        ///< opening DOM implementation object 
 *      RXmlEngDocument iDoc; ///< iDoc with created nodes tree
 *      TXmlEngNode tmp = iDoc.DocumentElement();
 *	///< copying first child of iDoc to tmp2 node and appending it
 * 	TXmlEngNode tmp2 = tmp.FirstChild().CopyL();
 *	tmp.AppendChildL(tmp2);
 *	///< copying next node to the first child of iDoc to the last child place
 *	tmp.FirstChild().NextSibling().CopyToL(tmp.LastChild());
 *	///< replasing before last child with second child 
 *	tmp.LastChild().PreviousSibling().ReplaceWith(tmp.FirstChild().NextSibling());
 *	///< moving first child of iDoc to second child childrens
 *	tmp.FirstChild().MoveTo(tmp.FirstChild().NextSibling());	
 *      iDoc.Close();               ///< closing all opened objects
 *      domImpl.Close();
 * @endcode 
 *
 * @lib XmlEngineDOM.lib
 * @since S60 v3.1
 */
class TXmlEngNode
{
public:
   /**
    * The different element types carried by an XML tree.
    *
    * @note This is synchronized with DOM Level 3 values
    *       See http://www.w3.org/TR/DOM-Level-3-Core/
    *
    */
    enum TXmlEngDOMNodeType {
        EElement                =        1,
        EAttribute              =        2,
        EText                   =        3,
        ECDATASection           =        4,
        EEntityReference        =        5,
        EEntity                 =        6,  //> Not supported currently
        EProcessingInstruction  =        7,
        EComment                =        8,
        EDocument               =        9,
        EDocumentType           =        10, //> Not supported currently
        EDocumentFragment       =        11,
        ENotation               =        12, //> Not supported currently
        ENamespaceDeclaration   =        18, //> Not in DOM spec
		EBinaryContainer 		= 		 30, //> Not in DOM spec
		EChunkContainer 		= 		 31, //> Not in DOM spec
		EFileContainer 			= 		 32  //> Not in DOM spec
    };

public:
    /**
     * Default constructor
     *
     * @since S60 v3.1
     */
    inline TXmlEngNode();

    /**
     * Constructor
     *
     * @since S60 v3.1
     * @param aInternal node pointer
     */
    inline TXmlEngNode(void* aInternal);

    /**
     * Check if node is NULL
     *
     * @since S60 v3.1
     * @return TRUE if node is NULL in other case FALSE
     */
    inline TBool IsNull() const;

    /**
     * Check if node is NULL
     *
     * @since S60 v3.1
     * @return TRUE if node is not NULL in other case FALSE
     */
    inline TBool NotNull()const;

    /**
     * Cast node to attribute node.
     *
     * @since S60 v3.1
     * @return Attribute node
     *
     * @note
     *      - Never cast nodes to a wrong node type!
     *      - Casting removes const'ness of the node
     */
    inline    TXmlEngAttr&                    AsAttr() const;

    /**
     * Cast node to text node.
     *
     * @since S60 v3.1
     * @return Text node
     *
     * @note
     *     - Never cast nodes to a wrong node type!
     *     - Casting removes const'ness of the node
     */
    inline    TXmlEngTextNode&                AsText() const;

    /**
     * Cast node to binary data container
     *
     * @since S60 v3.2
     * @return Binary container
     *
     * @note
     *     - Never cast nodes to a wrong node type!
     *     - Casting removes const'ness of the node
     */
    inline    TXmlEngBinaryContainer&		 AsBinaryContainer() const;

    /**
     * Cast node to memory chunk container
     *
     * @since S60 v3.2
     * @return Chunk container
     *
     * @note
     *     - Never cast nodes to a wrong node type!
     *     - Casting removes const'ness of the node
     */
    inline    TXmlEngChunkContainer&		 AsChunkContainer() const;

    /**
     * Cast node to file container
     *
     * @since S60 v3.2
     * @return File container
     *
     * @note
     *     - Never cast nodes to a wrong node type!
     *     - Casting removes const'ness of the node
     */
    inline    TXmlEngFileContainer&		 AsFileContainer() const;

    /**
     * Cast node to memory chunk container
     *
     * @since S60 v3.1
     * @return Chunk container
     *
     * @note
     *     - Never cast nodes to a wrong node type!
     *     - Casting removes const'ness of the node
     */
    inline    TXmlEngDataContainer&		 AsDataContainer() const;

    /**
     * Cast node to element node.
     *
     * @since S60 v3.1
     * @return Element node
     *
     * @note
     *     - Never cast nodes to a wrong node type!
     *     - Casting removes const'ness of the node
     */
    inline TXmlEngElement& AsElement() const;

    /**
     * Cast node to comment node.
     *
     * @since S60 v3.1
     * @return Comment node
     *
     * @note
     *     - Never cast nodes to a wrong node type!
     *     - Casting removes const'ness of the node
     */
    inline TXmlEngComment& AsComment() const;

    /**
     * Cast node to namespace node.
     *
     * @since S60 v3.1
     * @return Namespace node
     *
     * @note
     *     - Never cast nodes to a wrong node type!
     *     - Casting removes const'ness of the node
     */
    inline TXmlEngNamespace& AsNamespace() const;

    /**
     * Cast node to CDATA section node.
     *
     * @since S60 v3.1
     * @return CDATA section node
     *
     * @note
     *     - Never cast nodes to a wrong node type!
     *     - Casting removes const'ness of the node
     */
    inline TXmlEngCDATASection& AsCDATASection() const;

    /**
     * Cast node to entity reference node.
     *
     * @since S60 v3.1
     * @return Entity reference node
     *
     * @note
     *     - Never cast nodes to a wrong node type!
     *     - Casting removes const'ness of the node
     */
    inline TXmlEngEntityReference& AsEntityReference() const;

    /**
     * Cast node to processing instruction node.
     *
     * @since S60 v3.1
     * @return Processing instruction node
     *
     * @note
     *     - Never cast nodes to a wrong node type!
     *     - Casting removes const'ness of the node
     */
    inline TXmlEngProcessingInstruction& AsProcessingInstruction() const;

    /**
     * Get innerXML string. This method returns all content of the node.
     * Output text does not include node markup.
     *
     * @since S60 v3.1
     * @param aBuffer RBuf8 in which output should be save
     * @return Size of output buffer
     * @note Returned RBuf8 should be freed
     */
    IMPORT_C TInt InnerXmlL(RBuf8& aBuffer);
    
    /**
     * Get outerXML string. This method returns all content of the node.
     * Output text includes node markup.
     *
     * @since S60 v3.1
     * @param aBuffer RBuf8 in which output should be save
     * @return Size of output buffer
     * @note Returned RBuf8 should be freed
     */
    IMPORT_C TInt OuterXmlL(RBuf8& aBuffer);

    /**
     * Moves the node to become the first in the list of its siblings
     * Node is expected to have a parent.
     *
     * @since S60 v3.1
     */
    IMPORT_C void SetAsFirstSibling();

    /**
     * Moves the node to become the last in the list of its siblings
     * Node is expected to have a parent.
     *
     * @since S60 v3.1
     */
    IMPORT_C void SetAsLastSibling();

    /**
     * Moves the node in the list of sibling nodes before another node
     * Node is expected to have a parent.
     * Do nothing if aSiblingNode is not one of node's siblings
     *
     * @since S60 v3.1
	 * @param aSiblingNode Node that should be after current node 
     */
    IMPORT_C void MoveBeforeSibling(TXmlEngNode aSiblingNode);

    /**
     * Moves the node in the list of sibling nodes after another node
     * Node is expected to have a parent.
     * Do nothing if aSiblingNode is not one of the node's siblings
     *
     * @since S60 v3.1
	 * @param aSiblingNode Node that should be after current node 
     */    
    IMPORT_C void MoveAfterSibling(TXmlEngNode aSiblingNode);

    /**
     * Moves the node to another part of the tree or another document
     * The node is unliked from current postion (if any) and appended
     * to the its new parent.
     *
     * @since S60 v3.1
     * @param aParent Parent node
     * @return Node handle
     *
     * @note 
     * In many cases this method call should be followed by ReconcileNamespacesL() on the moved node
     */
    inline  TXmlEngNode MoveTo(TXmlEngNode aParent);

    /**
     * Detaches a node from document tree
     *
     * @since S60 v3.1
     * @return This node, which is already not a part of any document
     * @note    Remember to use ReconcileNamespacesL() later, if extracted node (subtree)
     *          contains references to namespace declarations outside of the subtree.
     * @see     ReconcileNamespacesL()
     * @note    The document, from which the is being unlinked, becomes an owner of the node
     *          until it is linked elsewhere.
     */
    IMPORT_C TXmlEngNode Unlink();

    /**
     * Ensures that namespaces referred to in the node and its descendants are
     * in the scope the node.
     *
     * This method checks that all the namespaces declared within the given
     * tree are properly declared. This is needed for example after Copy or Unlink
     * and then Append operations. The subtree may still hold pointers to
     * namespace declarations outside the subtree or they may be invalid/masked. As much
     * as possible the function try to reuse the existing namespaces found in
     * the new environment. If not possible, the new namespaces are redeclared
     * on the top of the subtree.
     *
     * This method should be used after unlinking nodes and inserting to another
     * document tree or to a another part of the original tree, if some nodes of the subtree
     * are remove from the scope of a namespace declaration they refer to.
     *
     * When node is unlinked, it may still refer to namespace declarations from the previous location.
     * It is important to reconcile subtree's namespaces if previous parent tree is to be destroyed.
     * On the other hand, if the parent tree is not changed before pasting its unlinked part into another
     * tree, then reconciliation is needed only after paste operation.
     *
     * @since S60 v3.1
     */
    IMPORT_C void ReconcileNamespacesL();

    /**
     * Unlinks the node and destroys it; all child nodes are destroyed as well and all memory is freed
     *
     * @note  Document nodes cannot be "removed" with this method, uses RXmlEngDocument-specific methods.
     *
     * @since S60 v3.1
     */
    IMPORT_C void Remove();

    /**
     * Current node is replaced with another node (subtree).
     *
     * The replacement node is linked into document tree instead of this node.
     * The replaced node is destroyed.
     *
     * @since S60 v3.1
     * @param aNode Node that repleace current node
     *
     * @see SubstituteFor(TXmlEngNode)
     *
     * In both cases the argument node is unlinked from its previous location
     * (which can be NONE, i.e. not linked; SAME or ANOTHER document tree).
     *
     * @note Replacement of a node with NULL TXmlEngNode is legal and equivalent to removing the node.
     * @note Not applicable to document nodes
     */
    IMPORT_C void ReplaceWith(TXmlEngNode aNode);

    /**
     * Another node is put instead of the current node.
     *
     * Does the same as ReplaceWith(TXmlEngNode) but does not free node and just returns it.
     *
     * @since S60 v3.1
     * @param aNode Node that repleace current node
     * @return Current node after unlinking it from document tree
     * @see ReplaceWith(TXmlEngNode)
     *
     * In both cases the argument node is unlinked from its previous location
     * (which can be NONE, i.e. not linked; SAME or ANOTHER document tree)
     *
     * It is possible to use NULL TXmlEngNode object as an argument. In such case
     * no new node will be put instead of unlinked one.
     *
     * @note Not applicable to document nodes
     */
    IMPORT_C TXmlEngNode SubstituteForL(TXmlEngNode aNode);

    /**
     * Retrieves a "handle" for namespace declaration that applies to the node's namespace
     * Note: DOM specs do not consider namespace declarations as a kind of nodes
     * This API adds TXmlEngNamespace type of nodes, which is derived from TXmlEngNode.
     *
     * @since S60 v3.1
     * @return    Object that represents namespace declaration and prefix binding that
     *             act on the node; returns NULL object (check using TXmlEngNamespace.IsNull()
     *             or TXmlEngNamespace.NotNull()) if no namespace associated
     */
    IMPORT_C TXmlEngNamespace NamespaceDeclaration() const;

    /**
     * Attaches a user data object to this node. The ownership of the object is transferred.
     * When the (underlying) node is deleted the Destroy method of the MXmlEngUserData class will be
     * called. If there already is a user data object associated with this node, it will be
     * deleted before attaching the new object.
     *
     * @since S60 v3.1
     * @param aData Pointer to the data object.
     * @return true if successful, false if for example underlying node type doesn't support
     * attaching user data.
     * @note Only TXmlEngElement and Attribute nodes currently support this feature.
     *             User data is not copied, when node is copied.
     */
    IMPORT_C TBool AddUserData(MXmlEngUserData* aData);

    /**
     * Returns the user data object attached to this node. Ownership is not transferred.
     *
     * @since S60 v3.1
     * @return Pointer to data object or NULL if it doesn't exist.
     */
    IMPORT_C MXmlEngUserData* UserData() const;

    /**
     * Removes the user data onject attached to this node. Ownership is transferred
     * (the object is not deleted).
     *
     * @since S60 v3.1
     * @return Pointer to data object or NULL if it doesn't exist.
     */
    IMPORT_C MXmlEngUserData* RemoveUserData();

    /**
     * Clones the node completely: all attributes and namespace declarations (for TXmlEngElement nodes),
     * values and children nodes are copied as well.
     *
     * Document nodes cannot be copied with this method: RXmlEngDocument::CloneDocumentL() must be used.
     *
     * @since S60 v3.1
     * @return Complete copy of a node or leaves.
     * @note    The node should not be NULL!
     */
    IMPORT_C TXmlEngNode CopyL() const;

    /**
     * Creates a deep copy of the node and appends the subtree as a new child
     * to the provided parent node.
     *
     * @since S60 v3.1
     * @return Created copy of the node after linking it into the target document tree.
     * @note Document nodes cannot be copied with this method; use RXmlEngDocument::CloneDocumentL()
     */
    IMPORT_C TXmlEngNode CopyToL(TXmlEngNode aParent) const;

    /**
     * Append a child node.
     *
     * This is universal operation for any types of nodes.
     * Note, that some types of nodes cannot have children and
     * some types of nodes are not allowed to be children of some other types.
     *
     * @since S60 v3.1
     * @param aNewChild Child node that should be added
     * @return Appended node, which could changed as a result of adding it to
     * list of child nodes (e.g. text nodes can coalesce together)
     */
    IMPORT_C TXmlEngNode AppendChildL(TXmlEngNode aNewChild);

    /**
     * Initializes a node list with all children of the node
     *
     * @since S60 v3.1
     * @param aList node list that should be initialized
     */
    IMPORT_C void GetChildNodes(RXmlEngNodeList<TXmlEngNode>& aList) const;

    /**
     * Get parent node of current node.
     *
     * @since S60 v3.1
     * @return Parent node of the node or NULL if no parent
     */
    IMPORT_C TXmlEngNode ParentNode() const;

    /**
     * Get first child of current node
     *
     * @since S60 v3.1
     * @return The first child node or NULL if no children
     */
    IMPORT_C TXmlEngNode FirstChild() const;

    /**
     * Get last child of current node
     *
     * @since S60 v3.1
     * @return The last child node or NULL if no children
     */
    IMPORT_C TXmlEngNode LastChild() const;

    /**
     * Get previous node of current node
     *
     * @since S60 v3.1
     * @return Previous node in a child list or NULL if no sibling before
     */
    IMPORT_C TXmlEngNode PreviousSibling() const;

    /**
     * Get fallowing node of current node
     *
     * @since S60 v3.1
     * @return Following node in a child list or NULL if no sibling after
     */
    IMPORT_C TXmlEngNode NextSibling() const;

    /**
     * Get document handle
     *
     * @since S60 v3.1
     * @return A document node of the DOM tree this node belongs to
     *
     * @note An instance of RXmlEngDocument class returns itself
     */
    IMPORT_C RXmlEngDocument OwnerDocument() const;

    /**
     * Fetches value of this node, depending on its type.
     *
     * @note It is better to always cast nodes to specific type and then use specific
     *       method for getting "node value"
     *
     * @since S60 v3.1
     * @return Node value
     */
    IMPORT_C TPtrC8 Value() const;

    /**
     * Get copy of node's text content
     * What is returned depends on the node type.
     * Method caller is responsible for freeing returned string.
     *
     * @since S60 v3.1
     * @return   the content of the node
     */
    IMPORT_C void WholeTextContentsCopyL(RBuf8& aOutput) const;

    /**
     * Sets value of this node.
     *
     * @since S60 v3.1
     * @param aValue New value
     */
    IMPORT_C void SetValueL(const TDesC8& aValue);

    /**
     * Check if node content is "simple text".
     *
     * @since S60 v3.1
     * @return Whether the value of the node is presented by only one TXmlEngTextNode node
     *
     * If the value is <i>"simple text"</i> then it is possible to access it as TDOMString
     * without making copy, which combines values of all text nodes and entity reference nodes.
     *
     * @see TXmlEngNode::Value(), TXmlEngAttr::Value(), TXmlEngElement::Text()
     *
     * This method is applicable to TXmlEngElement and TXmlEngAttr nodes. On other nodes FALSE is returned.
     *
     * @note
     *  Values (contents) of TXmlEngComment, TXmlEngCDATASection, TXmlEngTextNode, ProcessingInstuction data are
     *  always "simple".
     *
     * When the returned result is FALSE, getting value of the node would not returned
     * whole contents because of either entity references present in the contents or
     * the contents is mixed (for TXmlEngElement node). In this case WholeTextContentsCopyL()
     * should be used.
     *
     * @see TXmlEngNode::WholeTextContentsCopyL()
     */
    IMPORT_C TBool IsSimpleTextContents() const;

    /**
     * Use NodeType() to find out the type of the node prior to casting object
     * of TXmlEngNode class to one of its derived subclasses (TXmlEngElement, TXmlEngAttr, TXmlEngTextNode, etc.)
     *
     * @since S60 v3.1
     * @return Type of the node
     *
     * @see TXmlEngDOMNodeType
     */
    IMPORT_C TXmlEngDOMNodeType NodeType() const;

    /**
     * Get node name
     *
     * @since S60 v3.1
     * @return Name of the node
     *
     * This method generally follows DOM spec :
     * -------------------------------------------------------------------------------
     * The values of nodeName, nodeValue, and attributes vary according to the node
     * type as follows:
     *
     * interface              nodeName                nodeValue            attributes
     * -------------------------------------------------------------------------------
     * Attr                   = Attr.name              = Attr.value             = null
     * CDATASection           = "#cdata-section"       = CharacterData.data     = null
     * Comment                = "#comment"             = CharacterData.data     = null
     * Document               = "#document"            = null                   = null
     * DocumentFragment       = "#document-fragment"   = null                   = null
     * DocumentType           = DocumentType.name      = null                   = null
     * Element                = Element.tagName        = null           = NamedNodeMap
     * Entity                 = entity name            = null                   = null
     * EntityReference        = name of entity referenced  = null               = null
     * Notation               = notation name          = null                   = null
     * ProcessingInstruction  = target                 = data                   = null
     * Text                   = "#text"                = CharacterData.data     = null
     * -------------------------------------------------------------------------------
     */
    IMPORT_C TPtrC8 Name() const;


    /**
     * Check if node has child nodes.
     *
     * @since S60 v3.1
     * @return True if the node is TXmlEngElement and has at least one child node
     */
    IMPORT_C TBool HasChildNodes() const;

    /**
     * Check if node has attributes.
     *
     * @since S60 v3.1
     * @return True if the node is TXmlEngElement and has at least one attribute
     *
     * @note Namespace-to-prefix bindings are not attributes.
     */
    IMPORT_C TBool HasAttributes() const;

    /**
     * Evaluates active base URI for the node by processing xml:base attributes of parents
     *
     * @since S60 v3.1
     * @return A copy of effective base URI for the node
     * @note It's up to the caller to free the string
     */
    IMPORT_C void BaseUriL(RBuf8& aBaseUri) const;

    /**
     * Compares nodes.
     *
     * The nodes are the same if they are referring to the same in-memory
     * data structure.
     *
     * @since S60 v3.1
     * @param aOther Node to compare
     * @return TRUE if the same
     */
    inline TBool IsSameNode(TXmlEngNode aOther) const;

    /**
     * Get namespace uri.
     *
     * @since S60 v3.1
     * @return  Namespace URI of a node
     *           - NULL is returned for elements and attributes that do not
     *             belong to any namespace.
     *           - bound namespace URI is returned for namespace declaration nodes (instances of TXmlEngNamespace).
     *           - NULL is returned to all other types of node.
     *
     * @note use IsNull() and NotNull() for testing returned result on the subject
     *      of having some URI
     */
    IMPORT_C TPtrC8 NamespaceUri() const;

    /**
     * Get namespace prefix.
     *
     * @since S60 v3.1
     * @return  Prefix of a node
     * Returns NULL for elements and attributes that do not have prefix
     * (node belongs to the default namespace or does not belong to any namespace)
     * NULL is also returned for all types of node other than TXmlEngElement or TXmlEngAttr
     */
    IMPORT_C TPtrC8 Prefix() const;

    /**
     * Check if nemespace is default for this node
     *
     * @since S60 v3.1
     * @param aNamespaceUri Namespace URI
     * @return True if given namespace URI is a default one for the node (applicable to elements only)
     *
     * @note "" or NULL can be used to denote undefined namespace
     */
    IMPORT_C TBool IsDefaultNamespaceL(const TDesC8& aNamespaceUri) const;

    /**
     * Searches the prefix that is bound to the given aNamespaceUri and
     * applicable in the scope of this TXmlEngNode.
     *
     * @since S60 v3.1
     * @param aNamespaceUri Namespace Uri that should be found
     * @return A sought prefix or NULL if not found or aNamespaceUri is the default namespace
     *
     * @see TXmlEngElement::LookupNamespaceByUriL(const TDesC8&)
     */
    IMPORT_C TPtrC8 LookupPrefixL(const TDesC8& aNamespaceUri) const;

    /**
     * Searches the namespace URI that is bound to the given prefix.
     * 
     * @since S60 v3.1
     * @param aPrefix Namespace prefix that should be found
     * @return A sought URI or NULL if the prefix is not bound
     *
     * @see TXmlEngElement::LookupNamespaceByPrefixL(const TDesC8&)
     */
    IMPORT_C TPtrC8 LookupNamespaceUriL(const TDesC8& aPrefix) const;

protected:
    /**
     * Unlinks the internal libxml2's node from double-linked list.
     * Relinks neighbour nodes.The node stays virtually linked to its old neighbours! Use with care!!
     *
     * No checks are made; nor parent's, nor node's properties updated
     *
     * @since S60 v3.1
     */
    void DoUnlinkNode();

    /**
     * Inserts the node in a double-linked list of nodes before specified node.
     *
     * No checks are made; nor parent's, nor node's properties updated (except prev/next)
     *
     * @since S60 v3.1
     * @param aNode Target node
     */
    void LinkBefore(TXmlEngNode aNode);

protected:
	/** Node pointer */
    void* iInternal;

};

#include "xmlengnode.inl"

#endif /* XMLENGINE_NODE_H_INCLUDED */
