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
* Description:       Element node functions
*
*/







#ifndef XMLENGINE_ELEMENT_H_INCLUDED
#define XMLENGINE_ELEMENT_H_INCLUDED

#include "XmlEngAttr.h"
#include "XmlEngNamespace.h"

template<class T> class RXmlEngNodeList;


/**
 * Instance of TXmlEngElement class represents an XML element in the DOM tree.
 *
 * <b>Namespace handling:</b>
 *
 * Namespace of XML element is an URI that in pair with <i>local part</i> of
 * element's name consistute <b>expanded-name</b> of element. It is said that "the element
 * is of <i>NNN</i> namespace".
 *
 * XML elements are shown as belonging to a specific namespace by using <i>prefixes</i>
 * that previously were bound to some namespace URIs. The scope of a prefix is the
 * element, where it was declared and all its child (sub-)elements.
 *      
 * Namespace declaration is created by using special <b>xmlns:<i>{prefix-name}</i></b>
 * attribute (which is not really considered as attribute in DOM):
 * @code 
 *    <a xmlns:pr="http://some.uri.com/"> ... </a>
 * OR
 *    <pr:a xmlns:pr="http://some.uri.com/"> ... </a>
 *    <a xmlns="http://some.uri.com/"> ... </a>
 * @endcode
 *
 * The latter two examples are equivalent and show the use of <i>default namespace</i>.
 *    
 * Implementation notes:
 *	- Element having no namespace is either presented with a NULL TXmlEngNamespace node 
 *    or a TXmlEngNamespace node that has NULL prefix and namespace URI set to "". 
 *    The former is used by default on all nodes, whereas the latter is for cases
 *    when some node contains undeclaration of the default namespace:
 * @code
 *	   <a xmlns=""> .. </a>
 * @endcode
 *
 * - The prefix of the default attribute is NULL, not "" (zero-length string)
 *	 "" corresponds to  
 *   @code
 *       <a xmlns:="http://some.uri.com/"> ... </a>
 *   @endcode
 *   (it does not contradict XML spec, but you are strongly advised against using this)
 *
 * - Prefix <b>"xml"</b> is reserved by XML Namespace spec for special purposes; it is implicitly bound
 *   to XML's namespace <i>"http://www.w3.org/XML/1998/namespace"</i> and no one is allowed
 *   to use this prefix except as with spec-defined elements and attributes or to rebind this 
 *   prefix to other namespaces
 *
 * - Namespace URI may be "" only for default namespace. In other words,
 *   "" namespace URI may not be bound to non-NULL prefix. 
 *          
 *   Declaration of "" namespace with NULL prefix results in:
 *   @code
 *       <a xmlns=""> ... </a>
 *   @endcode
 *   which <i>undeclares</i> any existing (in some parent element) default namespace
 *   for the scope of element 'a': element, its attributes and all child nodes of DOM tree.
 *   Note, that such "undeclaration" will be added only if neccessary. 
 *        
 * - Unneccessary namespace declaration are ignored. Attemps to add namespace binding 
 *   using same namespace URI and prefix if such binding already exists in the scope
 *   will have no effect.
 *
 * - <b>IMPORTANT!</b> Attributes DO NOT HAVE default namespaces. If an attribute has no
 *   prefix, its namespace is <b>undeclared</b> even if there is some default namespaces for
 *   the scope of the element, which contains the attribute.
 *
 * So, it is wrong to write something like this:
 * @code
 *     <a xmlns="ns_uri"  attr="value"> ... </a>
 * @endcode
 * and assume that the <b>attr</b> belongs to namespace pointed to with <i>ns_uri</i>.
 *    
 * <b>HINTS:</b>
 * - Use namespace declaration nodes as much as possible (but watch out prefix collisions).
 * - Add most referred to namespace declarations (AddNamespaceDeclarationL(uri,pref)) after
 *   any other namespace declarations in a element -- the will be found faster in
 *   namespace lookups.
 *
 * @lib XmlEngineDOM.lib
 * @since S60 v3.1
 */

class TXmlEngElement : public TXmlEngNode
{
  public:
    /**
     * Default constructor for automatic variables (not initialized)
	 *
     * @since S60 v3.1
	 */
    inline TXmlEngElement();

    /**
     * Constructor
     *
     * @since S60 v3.1
	 * @param aInternal element pointer
	 */
    inline TXmlEngElement(void* aInternal);
	
    /** 
    *    @name XmlEngine's non-DOM extensions
    */
    /** @{ */

    /**
     *   Retrieves list of attribute nodes of the element
     *   
     *   @param aList - a node list object to initialize
     *
     *   Passed by reference list of nodes is initialized and after call to
     *   Attributes(..) is ready for use with HasNext() and Next() methods:
     *
     *   @code
     *       ...
     *       TXmlEngElement root = doc.DocumentElement();
     *       RXmlEngNodeList<TXmlEngAttr>    attlist;
     *       root.GetAttributes(attlist);
     *       while (attlist.HasNext())
     *           processAttribute(attlist.Next());
     *       ...
	 *       attlist.Close();
     *   @endcode
	 *
     * @since S60 v3.1
	 */
    IMPORT_C void GetAttributes(RXmlEngNodeList<TXmlEngAttr>& aList) const;

    /**
     * Retrieves list of child elements of the element
     *
     * @since S60 v3.1
	 * @param aList - a node list object to initialize
     *
     * Passed by reference list of nodes is initialized and after the call
     * it is ready for use with HasNext() and Next() methods:
     *   
     * @note Returned list is a "filtered view" of the underlying
     *       list of all element's children (with text nodes, comments
     *       processing instructions, etc.)
	 */ 
    IMPORT_C void GetChildElements(RXmlEngNodeList<TXmlEngElement>& aList) const;

    /**
     * Creates new attribute node out of any namespace (i.e. it has no prefix),
     * sets attribute's value and links it as the last attribute of the current element
     *
     * @since S60 v3.1
	 * @param  aName   A local name of attribute
     * @param  aValue  Value to set for new attribute or NULL (sets value to "")
     * @return         A handler to the newly created attribute node;
     *
     * For adding attribute as the first one, use TXmlEngNode::SetAsFirstSibling() on the attribute:
     * @code
     *     TXmlEngElement el = ... ; // get some element
     *     el.AddNewAttributeL("version","0.1").SetAsFirstSibling();
     * @endcode
     *   
     * @see   SetAsLastSibling(), MoveBeforeSibling(TXmlEngNode) and MoveAfterSibling(TXmlEngNode)
     *
     * @note   - No checks are made that attribute with such name exists
     *           Use this method only on newly created elements!
     *           Otherwise, use TXmlEngElement::SetAttributeL(..)
     *         - Attributes do not inherit default namespace of its element
     *           (http://w3.org/TR/REC-xml-names/#defaulting)
     *         - attribute's value is the second argument in all AddNewAttributeL(..) methods
     *         - Use of NULL as value is more preferrable then "" 
	 */
    IMPORT_C TXmlEngAttr AddNewAttributeL(const TDesC8& aName, const TDesC8& aValue);
    
    /**
     * Creates new attribute node and add it to the element
     *
     * Provided handle to namespace declaration is used to set up
     * attribute's namespace.
     *
     * @since S60 v3.1
	 * @param  aName   A local name of attribute
     * @param  aValue  Value to set for new attribute or NULL (sets value to "")
     * @param  aNsDef  Namespace to add to the attribute
     * @return         A handler to the newly created attribute node;
     *
     * @note If aNsDef is not defined in some of attributes ascendants
     *      (including this element), then
     *      ReconcileNamespacesL() method must be called on
     *      this element later.
	 */
    IMPORT_C TXmlEngAttr AddNewAttributeL(const TDesC8& aName,
                                    const TDesC8& aValue, 
                                    const TXmlEngNamespace aNsDef);

    /**
     * Creates new attribute on the element. Namespace declaration for the attribute namespace is
     * created too.
     *
     * @since S60 v3.1
	 * @param  aName   A local name of attribute
     * @param  aValue  Value to set for new attribute or NULL (sets value to "")
     * @param  aNsUri  Namespace uri
     * @param  aPrefix  Namespace prefix
     * @return         A handler to the newly created attribute node;
     *
     * @note
     *    - Namespace declarations are reused if possible (no redundant ones are created)
     */
    IMPORT_C TXmlEngAttr AddNewAttributeL(const TDesC8& aName, 
                                    const TDesC8& aValue,
                                    const TDesC8& aNsUri, 
                                    const TDesC8& aPrefix);

    /**
     * Creates new attribute node using namespace of its parent element (this element),
     * sets attribute's value and links it as the last attribute of the element
     *
     * @since S60 v3.1
	 * @param aName Local name of attribute 
     * @param aValue Value to set for new attribute or NULL (sets value to "")
     * @return A handler to the newly created attribute node;
     *    
     * For more hints how to use it refer to AddNewAttributeL(const TDesC8&,const TDesC8&)
     *        
     * @note    
     *     - No checks are made that attribute with such name exists
     *     - if namespace of the parent element is default (i.e. bound prefix is NULL),
     *       then temporary prefix will be used and bound to the same namespace URI as elements
     *       (It is due to the fact that default namespaces do not spread on unprefixed attributes,
     *       see http://w3.org/TR/REC-xml-names/#defaulting)
     */
    inline   TXmlEngAttr AddNewAttributeSameNsL(const TDesC8& aName, const TDesC8& aValue);

    /**
     * Creates new attributes using namespace, which is bound to the specified prefix
     *
     * @since S60 v3.1
	 * @param  aLocalName   A local name of attribute
     * @param  aValue  Value to set for new attribute or NULL (sets value to "")
     * @param  aPrefix  Namespace prefix for new attribute
     * @return A handler to the newly created attribute node;
     *
     * Use this mothod only for construction of new parts of DOM tree, where
     * you know for sure that prefix is bound in the given scope.
     * @code
     *     TXmlEngElement el = parent.AddNewAttributeUsePrefixL("property","ObjName","rdf");
     *     el.AddNewAttributeUsePrefixL("type", "xs:integer", "rdf");
     * @endcode
     *
     * Otherwise, you should check that prefix is bound like this example shows:
     * @code
     *     TXmlEngNamespace boundNS = TXmlEngNamespace::LookupByPrefix(thisElement, prefix);
     *     if (boundNS.NotNull()){
     *         thisElement.AddNewAttributeUsePrefixL("name", value, prefix);
     *     }
     * @endcode
     *
     * @note
     *     Use AddNewAttributeNsL(name,value,nsDefNode) as much as you can, because
     *     it is most efficient way to create namespaced DOM elements (no additional
     *     lookups for namespace declarations are required).
     *  
     * @code
     *     // If namespace with given URI is not in the scope, then it will be declared
     *     // and bound to "data" prefix.
     *     TXmlEngNamespace nsDef = elem.FindOrCreateNsDefL("http://../Data", "data");
     *     elem.AddNewAttributeL("location", "...", nsDef);
     *     elem.AddNewElementL("child", nsDef).AddNewAttributeL("attr","...value...");
     *     // the result is
     *         ...
     *      <elem xmlns:data="http://../Data" data:location="...">
     *         <data:child attr="...value..."/>
     *      </elem>
     *         ...
     *     //
     * @endcode    
     */
    IMPORT_C TXmlEngAttr AddNewAttributeUsePrefixL(const TDesC8& aLocalName, 
                                             const TDesC8& aValue, 
                                             const TDesC8& aPrefix);

    /**
     * Creates new attributes using namespace in the scope, which has specified URI
     *   
     * Almost the same as AddNewAttributeUsePrefixL(...) but does lookup by namespace URI
     *
     * @since S60 v3.1
	 * @param  aLocalName   A local name of attribute
     * @param  aValue  Value to set for new attribute or NULL (sets value to "")
     * @param  aNsUri  Namespace uri for new attribute
     * @return - NULL attribute if namespace declaration is not found OR newly added to the end of
     *           attribute list attribute of this element.
     *
     * @see AddNewAttributeUsePrefixL(const TDesC8&,const TDesC8&,const TDesC8&)
     */
    IMPORT_C TXmlEngAttr AddNewAttributeWithNsL(const TDesC8& aLocalName, 
                                          const TDesC8& aValue, 
                                          const TDesC8& aNsUri);
                                          
    /**
     * Add attribute to element that will be used as Xml:Id.
     *
     * No check if such attribute exists are made.
     * 
     * @since S60 v3.2
	 * @param aLocalName Name of attribute that should be add.
	 * @param aValue Value of the attribute
	 * @param aNs Namespace of the attribute
	 * @return Attribute if created. Null attribute if Id exist
     *
     * @note Call RXmlEngDocument.RegisterXmlIdL(aName,aNsUri) first
     *       to register existed id's in the document.
     */
    IMPORT_C TXmlEngAttr AddXmlIdL(const TDesC8& aLocalName,
                                       const TDesC8& aValue,
                                       TXmlEngNamespace aNs = TXmlEngNamespace());
    
    /**
     * Adds child element with no namespace
     *
     * @since S60 v3.1
	 * @param aName name of the element
     * @return A handler to the newly created element node;
     *
     * Results in adding element with aName and no prefix.
     *
     * This method is the best for creation of non-namespace based documents
     * or document fragments, where no default namespace declared.
     *
     * It may be used also as a method for adding element from default namespace,
     * BUT namespace will be assigned ONLY after serialization of the current
     * document and parsing it back into a DOM tree!! If you need that default namespace
     * was inherited by new element immediately use:
     * @code
     *    ...
     *    TXmlEngNamespace defns = element.DefaultNamespace();
     *    TXmlEngElement newEl = element.AddNewElementL("Name",defns);
     *    ...
     * @endcode
     *
     * If truly undefined namespace for the element is required, then <b>DO NOT USE</b>
     * this method if there is a default namespace in the scope!
     */
    IMPORT_C TXmlEngElement AddNewElementL(const TDesC8& aName);

    /**
     * Creates new child element with provided name and namespace declaration
     *
     * @since S60 v3.1
	 * @param aLocalName Name of the element
     * @param aNsDecl Handle of the namespace declaration, that must be retrieved from
     *            one of the ascendant nodes of the new elements (and its prefix
     *            should not be remapped to another namespace URI for the scope
     *            of the new element)
     * @return    Created element node (and added as the last child of its parent)
     */
    IMPORT_C TXmlEngElement AddNewElementL(const TDesC8& aLocalName, TXmlEngNamespace aNsDecl);

    /**
     * Creates new child element with provided name, prefix and namespace URI
     *
     * New namespace declaration will be attached to the parent (this) element and used
     * as namespace for newly created child element. If such binding already exists
     * (same prefix is bound to same URI), it will be reused. If the prefix is already
     * bound to some another namespace URI, it will be rebound by the new namespace
     * declaration node.
     *
     * @since S60 v3.1
	 * @param aLocalName Name of the element
     * @param aNsUri     URI of element's namespace
     * @param aPrefix    Prefix of the element
     * @return Created element node (and added as the last child of its parent)
     */
    IMPORT_C TXmlEngElement AddNewElementL(const TDesC8& aLocalName, 
                                     const TDesC8& aNsUri, 
                                     const TDesC8& aPrefix);

    /**
     * Adds child element with same namespace (and prefix if present) as parent element has
     *
     * @since S60 v3.1
	 * @param aLocalName element's name
     * @return New element that was added to the end of children list of its parent (this element)
     */
    IMPORT_C TXmlEngElement AddNewElementSameNsL(const TDesC8& aLocalName);

    /**
     * Performs lookup for the namespace declaration for specified prefix and
     * adds new child element with found namespace.
     *
     * The assumption is that prefix is bound, otherwise run-time error
     * (Symbian's Leave or exception) occurs
     *
     * @note   Use this method only if there is a binding for the given prefix.
     *
     * @since S60 v3.1
	 * @param aLocalName element's name
     * @param aPrefix    prefix to use
     * @return new TXmlEngElement that was added to the end of children list of its parent (this element)
     */
    IMPORT_C TXmlEngElement AddNewElementUsePrefixL(const TDesC8& aLocalName, const TDesC8& aPrefix);

    /**
     * Performs lookup for the namespace declaration for specified namespace URI and
     * adds new child element with found namespace.
     *
     * The assumption is that namespace with given URI was declared,
     * otherwise run-time error (Symbian' Leave or exception) occurs
     * 
     * @note Use this method only if namespace declaration for the provided URI exists.
     *
     * @since S60 v3.1
	 * @param aLocalName    element's name
     * @param aNsUri        namespace of element
     * @return new TXmlEngElement that was added to the end of children list of its parent (this element)
     */
    IMPORT_C TXmlEngElement AddNewElementWithNsL(const TDesC8& aLocalName, const TDesC8& aNsUri);

    /**
     * Creates new child element; if there is no a prefix binding for new element's namespace,
     * a namespace decaration is created with generated prefix at specified element.
     *
     * @since S60 v3.1
	 * @param aLocalName    Name of the element to create
     * @param aNsUri        Namespace URI of the new element
     * @param aNsDeclTarget An element where namespace declaraton should be placed
     *                     if there is a needed to create new namespace declaration;
     *                     NULL is used to specify the created element itself
     *
     * As aNsDeclTarget any ascendant of the new node may be provided:
     * @code
     *     el.AddNewElementAutoPrefixL(tagName,uri,NULL); // declare on the new element
     *     el.AddNewElementAutoPrefixL(tagName,uri,el);   // declare on the parent element
     *     el.AddNewElementAutoPrefixL(tagName,uri,doc.DocumentElement()); // declare on the root element
     *    ...
     * @endcode
     *
     * @note
     *  The farther namespace declaration up in the document tree,
     *  the longer time namespace declaration lookups take.
     */
    IMPORT_C TXmlEngElement AddNewElementAutoPrefixL(const TDesC8& aLocalName, 
                                               const TDesC8& aNsUri, 
                                               TXmlEngElement aNsDeclTarget);

    /**
     * Get element content.
     * This method may be used in most cases, when element has only simple text content
     * (without entity references embedded).
     * If element's contents is mixed (other types of nodes present), only contents of
     * first child node is returned if it is a TXmlEngTextNode node. For getting mixed contents of the
     * element of contents with entity references, WholeTextValueCopyL() should be used.
     *
     * @since S60 v3.1
	 * @return Basic contents of the element
     * 
     * @see TXmlEngNode::WholeTextContentsCopyL()
     */
    IMPORT_C TPtrC8 Text() const;

    /**
     * Adds text as a child of the element.
     *
     * @since S60 v3.1
	 * @param aString text to be added as element's content.
     * 
     * @note There may be several TXmlEngTextNode and TXmlEngEntityReference nodes added actually,
     *   depending on the aString value
     */
    IMPORT_C void  AddTextL(const TDesC8& aString);

    /**
     * Sets text contents for the element.
     * Any child nodes are removed.
     * Same as TXmlEngNode::SetValueL(TDesC8&)
     *
     * @since S60 v3.1
	 * @param aString text to be set as element's content.
     *
     * @see TXmlEngNode::SetValueL(TDesC8&)
     */
    IMPORT_C void  SetTextL(const TDesC8& aString);

    /**
     * Sets text content of the element from escaped string.
     *
     * @since S60 v3.1
	 * @param aEscapedString New value
     *
     * @see TXmlEngAttr::SetEscapedValueL(TDesC8&)
     */
    IMPORT_C void  SetEscapedTextL(const TDesC8& aEscapedString);
    
    /**
     * Sets new element value exactly as presented in the string.
	 * Predefined entities are not converted into characters they represent.
	 * Any child nodes are removed.     
     *
     * @since S60 v3.2
	 * @param aNotEncText New element value
     *
     * @see TXmlEngAttr::SetValueNoEncL(const TDesC8& aNewValue); 
     */    
    IMPORT_C void SetTextNoEncL(const TDesC8& aNotEncString);

    /**
     * Appends new text node with the value exactly as presented in the string.
	 * Predefined entities are not converted into characters they represent.
	 * Existing child nodes are not removed.    
     *
     * @since S60 v3.2
	 * @param aNotEncText Appended element value
     *
     * @see TXmlEngAttr::SetValueNoEncL(const TDesC8& aNewValue); 
     */  
	IMPORT_C void AppendTextNoEncL(const TDesC8& aNotEncString);   

    /**
     * Adds namespace declaration to the current element, a binding of prefix to namespace URI.
     * 
     * If same namespace declaration exists (same prefix and URI), redundant namespace declaration
     * will not be created.
     * 
     * Both NULL or "" (empty string) may be used for "UNDEFINED URI" and "NO PREFIX" values of arguments. 
     *
     * @since S60 v3.1
	 * @param aNsUri Namespace URI
     * @param aPrefix Namespace prefix
     * @return  A handle to the created (or found, if there is such) namespace declaration node.
     *          If namespace undeclaration is being created, NULL handle is returned -- it can be
     *           used in node-creation methods that take namespace handle as an argument.
     * 
     * @note   Undeclaring of default namespace (xmlns="") is supported by
     *         SetNoDefaultNamespace() method
     * 
     * @see SetNoDefaulNamespace()
     * 
     * @note   By adding namespace declaration that rebinds prefix mapping (or default namespace)
     *         used by nodes lower in the tree, document tree may become
     *         wrongly constructed, because references to namespace declaration are
     *         not updated. However, after serialization the document will have
     *         desired structure.
     *         Use this method with care!
     */ 
    IMPORT_C TXmlEngNamespace AddNamespaceDeclarationL(const TDesC8& aNsUri, const TDesC8& aPrefix);

    /**
     * Adds default namespace declaration.
     *
     * @since S60 v3.1
	 * @param aNsUri   Namespace URI;  both NULL and "" (empty string) are allowed to represent UNDEFINED NAMSPACE
     * @return    Handle to the created namespace declaration (NULL for UNDEFINED NAMESPACE)
     *
     * Same result as with AddNamespaceDeclarationL(aNsUri, NULL), but additionally
     * element's namespace modified (if it has no prefix and there were no default
     * namespace declaration in the scope) to the new default one.
     */
    IMPORT_C TXmlEngNamespace SetDefaultNamespaceL(const TDesC8& aNsUri);

    /**
     * Undeclares any default namespace for current element and its descendants.
     * 
     * If there is already some default namespace,  <i>xmlns=""</i> namespace
     * declaration is added. Otherwise, nothing happens, since element with no
     * prefix in such scope is automaticaly considered as out of any namespace.
     * 
     * The side effect of this method is that namespace of the current element
     * may change from previous <b>default</b> namespace to NULL TXmlEngNamespace, which is
     * considered an absence of namespace.
     * 
     * If the element has prefix (i.e. not having default namespace), 
     * then the only effect for the element is undeclaration of existing default namespace. 
     * 
     * If element is in the scope of another <i>xmlns=""</i> undeclaration, no
     * actions are taken.
     * 
     * @note
     *     Use AddNamespaceDeclarationL(NULL,NULL) to force creation of
     *     xmlns=""  declaration within scope of another such declaration 
     *     (otherwise unneccessary/duplicate declarations are not created)
     * 
     * @note
     *     This method should be called on elements before adding children,
     *     because default namespace undeclaration is not spread into its subtree and 
     *     descedants' default namespaces are not reset to NULL. This should be taken into 
     *     account if later some processing on the subtree occurs.
     *     However, after serialization and deserialization, undeclared default namespace will
     *     affect whole element's subtree correctly.
     *
     * @since S60 v3.1
	 */
    IMPORT_C void SetNoDefaultNamespaceL();

    /**
     * Finds namespace declaration that has specific prefix in the scope for given node
     *
     * Prefix "" or NULL are considered the same, meaning "<b>NO PREFIX</b>".
     * If namespace declaration for "no prefix" is searched, then default namespace is returned. 
     *
     * @since S60 v3.1
	 * @param aPrefix Namespace prefix
     * @return Namespace handler, which may be NULL if prefix is not bound.
     * 
     * NULL result for "no prefix" means that default namespace is undefined.
     */
    IMPORT_C TXmlEngNamespace LookupNamespaceByPrefixL(const TDesC8& aPrefix) const;

    /**
     * Finds namespace declaration that has specific namespace URI
     * in the scope for the given node.
     *
     * @since S60 v3.1
	 * @param aUri  Namespace URI, for which namespace declaration is searched
     * @return Handler to the namespace declaration that binds given namespace URI to some prefix 
     *          or sets it a default namespace.
     * 
     * NULL value of aUri is equivalent to "" and means "<b>UNDEFINED NAMESPACE</b>". 
     * For such URI  a NULL namespace handle is always returned even if there is
     * namespace undeclaration, which has "" URI (and NULL prefix).
     * 
     * <b>Hint:</b><p>
     * Use returned instance of TXmlEngNamespace as aNsDef argument to element's methods
     * that create new element's child elements and attributes. The same handler
     * may be used on more deep descentants of the reference element (and doing
     * this way will generally increase performance of DOM tree construction).<br />
     * <span class="color:red;">However</span>, if namespace bindings are not controlled
     * for element's children and prefix, which is bound to the search namespace, is
     * rebound to some other namespace URI, then reusing namespace may lead to
     * unwanted result.
     * 
     * Consider an example:
     * @code
     *     TXmlEngElement root = doc.DocumentElement();
     *     TXmlEngNamespace targetNs = root.AddNamespaceDeclarationL("http://example.com/","ex");
     *     TXmlEngElement el_1 = root.AddNewElementL("outer", targetNs);
     *     TXmlEngElement el_2 = el_1.AddNewElementL("inner"); // element without prefix
     * 
     *     // NOTE: prefix "ex" is not bound to "http://example.com/" anymore!
     *     el_2.AddNamespaceDeclarationL("http://whatever.com/","ex");
     *     TXmlEngElement el_3 = el_2.AddNewElementL("problem", targetNs);
     *     ...
     * @endcode
     * 
     * The sought result was (showing expanded names of elements):
     * @code
     *     --> "root"
     *         --> {"http://example.com/","outer"}
     *         --> "inner"
     *             -->{"http://example.com/","problem"}
     *                 ...
     *             <--
     *         <-- "inner"
     *         <-- {"http://example.com/","outer"}
     *         ...
     *     <-- </root>
     * @endcode
     * and it may look that it has been achieved. Indeed, if namespace of element "problem"
     * was queried, it would have URI "http://example.com/" and prefix "ex".
     * However, if namespace URI was looked up by "problem"'s prefix, it would be
     * "http://whatever.com/". We have created illegal DOM tree.
     * 
     * The actual DOM tree in serialized form will be:
     * @code
     *     <root>
     *         <ex:outer xmlns:ex="http://example.com/">
     *             <inner xmlns:ex="http://whatever.com/">
     *                 <ex:problem>
     *                 ...
     *                 </ex:problem>
     *             </inner>
     *         </ex:outer>
     *         ...
     *     </root>
     * @endcode
     * 
     * So, reuse of namespace handlers should be performed with special care.
     * 
     * @note
     * At the moment it is possible to retrieve namespace declaration nodes
     * whose prefixes were rebound. Be careful when use returned TXmlEngNamespace object
     * for creation of new elements. In later releases, this method will perform
     * safe lookup. And so far, it is better to make check that prefix of returned
     * namespace declaration has not rebound:
     * @code
     *     TXmlEngNamespace ns = element.LookupNamespaceByUri("a_uri");
     *     if (element.LookupNamespaceByPrefix(ns.Prefix()).IsSameNode(ns)){
     *         ... // now it is safe to create new elements by using "ns"
     *         element.AddNewElementL("product",ns);
     *         ...
     *     }
     * @endcode
     */
    IMPORT_C TXmlEngNamespace LookupNamespaceByUriL(const TDesC8& aUri) const;

    /**
     * Retrieves implicitly declared on every XML infoset binding
     * of 'xml' prefix to XML's namespace URI:
     * "http://www.w3.org/XML/1998/namespace"
     *
     * @since S60 v3.1
	 * @return Handler to {xml,"http://www.w3.org/XML/1998/namespace"} prefix
     *            binding in the current document
     *
     * The result should be used for creating attributes beloging to the XML namespace
     * (xml:lang, xml:space, xml:id , etc.)
     *
     * DO NOT USE methods LookupNamespaceByUriL(const TDesC8&) and LookupNamespaceByPrefixL(const TDesC8&)
     * (with "http://www.w3.org/XML/1998/namespace" and "xml" arguments) for retrieving
     * namespace node, since in a case of [possible] memory allocation fault
     * NULL result is returned (and breaks your program silently)
     * 
     * @note   Normally 'xml' prefix is bound to XML namespace URI in the document
     *        node, BUT if current node is not a part of the document tree yet,
     *        the requested namespace declaration WILL BE ADDED to the current node.
     *        This is the reason why the method may fail in OOM conditions.
     */
    IMPORT_C TXmlEngNamespace TheXMLNamespaceL() const;

    /**
     * Get default namespace for element.
     *
     * @since S60 v3.1
	 * @return Default namespace in the scope of the element
     *
     * NULL TXmlEngNamespace means that element with no prefix have no namespace associated
     * because no default namespace was declared or default namespace was undeclared with <b>xmlns=""</b>
     *
     * Equivalent to LookupNamespaceByPrefixL(const TDesC8&) with NULL (or "") prefix provided
     */
    inline   TXmlEngNamespace DefaultNamespaceL() const;

    /**
     * Performs search of namespace handler in the scope of the element. This method will
     * create new namespace declaration on the element if such namespace is not available.
     *
     * @since S60 v3.1
	 * @param aNsUri   Searched namespace
     * @param aPrefix  Prefix to use for <b>new</b> namespace declaration (if it is to be created)
     * @return    TXmlEngNamespace handler that may be used to create new attributes and child elements of
     *            the element. The namespace may be one of those existed previously or was created
     *
     * @note
     *    Be sure not to use the result of this method for non-descendants of the element or in situations
     *    when prefix overlapping might occur (read also about general general considerations of attributes
     *    and elements creation using namespace handlers)
     */
    IMPORT_C TXmlEngNamespace FindOrCreateNsDeclL(const TDesC8& aNsUri, const TDesC8& aPrefix);

    /**
     * Performs search on the element and its ascendants for any namespace declaration
     * with given URI and create a new namespace declaration with some (unique) prefix
     * if the search was not successful.
     *
     * @since S60 v3.1
	 * @param aNsUri   Searched namespace
     * @return    TXmlEngNamespace handler that may be used to create new attributes and child elements of
     *            the element. The namespace may be one of those existed previously or was created
     */
    IMPORT_C TXmlEngNamespace FindOrCreateNsDeclL(const TDesC8& aNsUri);

    /**
     * Checks whether a prefix has been bound in this element (not in one of its ascendants)
     * 
     * Use this method for preventig prefix-name collision in a element node
     *
     * @since S60 v3.1
	 * @param aPrefix Namespace prefix
     * @return TRUE if there is already namespace declaration that uses aPrefix on this element
     */
    IMPORT_C TBool HasNsDeclarationForPrefixL(const TDesC8& aPrefix) const;
    
    /**
     * Copies the element with its attributes, but not child nodes
     * 
     * If context is preserved, then all namespace declarations that are in the element are
     * writen to element's start tag too.
     *
     * @since S60 v3.1
	 * @param preserveNsContext TRUE if context should be preserved
     * @return handle to copy of element
     */
    IMPORT_C TXmlEngElement ElementCopyNoChildrenL(TBool preserveNsContext) const;
    
    /**
     * Specialized version of TXmlEngNode::CopyL()
     *
     * @since S60 v3.1
	 * @return Deep copy of the element.
     */
    inline   TXmlEngElement CopyL() const;

    /**
     * Resets element's content: all child nodes are removed
     *
     * @since S60 v3.1
	 */
    IMPORT_C void RemoveChildren();

    /**
     * Resets element's attributes
     *
     * @since S60 v3.1
	 */
    IMPORT_C void RemoveAttributes();

    /**
     * Resets all namespace declarations made in the element
     * 
     * @note There can be references to these namespace declaration from elsewhere!
     *      Use ReconcileNamespacesL() to fix that.
     *
     * @since S60 v3.1
	 */
    IMPORT_C void RemoveNamespaceDeclarations();

    /**
     * Removes all element contents: child nodes, attributes and namespace declarations
     *
     * @see RemoveChildren(), RemoveAttributes(), RemoveNamespaceDeclarations();
     *
     * @since S60 v3.1
	 */
    inline   void ClearElement();

    /**
     * Copies attributes from another element
     *
     * It may be a very convenient method for initializing element with a set of predefined attributes.
     *
     * @since S60 v3.1
	 * @param aSrc source element
     * 
     * @note
     *  Namespaces of the this element may need to be reconciled if copied attributes
     *  belong to any namespace that is not declared on some ascendant of this node.
     * @see ReconcileNamespacesL()
     */  
    IMPORT_C void CopyAttributesL(TXmlEngElement aSrc);

    /**
     * Copies a list of elements.
     *
     * Elements are appended to the element's children list.
     *
     * @since S60 v3.1
	 * @param aSrc source element
     *
     * @note Namespaces of the this element may need to be reconciled after copy operation
     * @see  ReconcileNamespacesL()
     */
    IMPORT_C void CopyChildrenL(TXmlEngElement aSrc);

    /**
     * Removes attribute with given name and namespace URI(if such exists).
     * Memory allocated for the attribute is freed.
     *
     * @since S60 v3.1
	 * @param aLocalName Element name
     * @param aNamespaceUri Element namespace
     */
    IMPORT_C void RemoveChildElementsL(const TDesC8& aLocalName,const TDesC8& aNamespaceUri);

    /** @} */

    /** 
    *    @name DOM Level 3 Core methods
    *
    *    @note
    *        Most methods of DOM spec operate with fully-qualified names (QNames)
    *        of elements and attributes. It is different in this API - all methods
    *        instead accept prefix and localName parts of QName.
    */
    /** @{ */
    
    /**
     * Returns value of attribute with given name and namespace URI
     *
     * @since S60 v3.1
	 * @param aLocalName Local name of attribute node
     * @param aNamespaceUri Namespace URI of attribute
     * @return Attribute value
     */
    IMPORT_C TPtrC8 AttributeValueL(const TDesC8& aLocalName, 
                                    const TDesC8& aNamespaceUri = KNullDesC8) const;

    /**
     * Initializes list of child elements with matching name and namespace URI.
     *
     * @since S60 v3.1
	 * @param aList Node list to be initialized
     * @param aLocalName Element name
     * @param aNamespaceUri Namespace URI, default is NULL
     *
     * @note This method does not lists all descedants of the element, only child elements
     */
    IMPORT_C void  GetElementsByTagNameL(RXmlEngNodeList<TXmlEngElement>& aList, 
                                         const TDesC8& aLocalName, 
                                         const TDesC8& aNamespaceUri = KNullDesC8) const;
    
    /**
     * Sets value of attribute; attribute is created if there is no such attribute yet
     *
     * @since S60 v3.1
	 * @param aLocalName Attribute name
     * @param aValue Attribute value
     * @param aNamespaceUri Namespace URI - default is NULL
     * @param aPrefix Namespace prefix - default is NULL
     *
     * @note
     *  If prefix is not NULL (or ""), then namespace URI may not be empty
     *  see http://www.w3.org/TR/REC-xml-names/#ns-decl (Definition #3)
     */
    IMPORT_C void  SetAttributeL(const TDesC8& aLocalName, 
                                 const TDesC8& aValue, 
                                 const TDesC8& aNamespaceUri = KNullDesC8, 
                                 const TDesC8& aPrefix = KNullDesC8);

    /**
     * Removes attribute with given name and namespace URI(if such exists).
     * Memory allocated for the attribute is freed.
     *
     * @since S60 v3.1
	 * @param aLocalName Name of the attribute
     * @param aNamespaceUri Attribute namespace URI, default is NULL
     */
    IMPORT_C void  RemoveAttributeL(const TDesC8& aLocalName, 
                                    const TDesC8& aNamespaceUri = KNullDesC8);

    /**
     * Retrieves attribute node from specific namespace by its name.
     *
     * @since S60 v3.1
	 * @param aLocalName Name of the attribute
     * @param aNamespaceUri Attribute namespace URI, default is NULL
     * @return Attribute node with matching namespace URI and name
     */
    IMPORT_C TXmlEngAttr AttributeNodeL(const TDesC8& aLocalName, 
                                  const TDesC8& aNamespaceUri = KNullDesC8) const;

    /**
     * Check if element has attribute with given parameters.
     *
     * @since S60 v3.1
	 * @param aLocalName Name of attribute
     * @param aNamespaceUri Namespace uri, default is NULL.
     * @return TRUE if the element holds an attribute with such namespace URI and name.
     *
     * Same result gives AttributeNodeL(uri,name).NotNull()
     */
    inline     TBool HasAttributeL(const TDesC8& aLocalName, 
                                   const TDesC8& aNamespaceUri  = KNullDesC8) const;

    /**
     * Links attribute into tree
     *
     * @since S60 v3.1
	 * @param aNewAttr new attribute
     * 
     * The replaced attribute node is not returned and just deleted
     */
    IMPORT_C void  SetAttributeNodeL(TXmlEngAttr aNewAttr);
};



#include "xmlengelement.inl"

#endif /* XMLENGINE_ELEMENT_H_INCLUDED */
