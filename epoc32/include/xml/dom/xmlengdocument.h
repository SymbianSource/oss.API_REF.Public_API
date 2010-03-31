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
* Description:       Document node functions
*
*/






#ifndef XMLENGINE_DOCUMENT_H_INCLUDED
#define XMLENGINE_DOCUMENT_H_INCLUDED

#include <f32file.h> 

#include "xmlengnode.h"
#include "xmlengserializationoptions.h"

// FORWARD DECLARATION
class RXmlEngDOMImplementation;

/**
 * Instance of RXmlEngDocument class represents an XML document in the DOM tree.
 * 
 * Is a storage all nodes and information about XML data.
 * 
 * @lib XmlEngineDOM.lib
 * @since S60 v3.1
 */
class RXmlEngDocument : public TXmlEngNode
{
public:    
    /**
     * Default constructor.
     *
     * Instance of RXmlEngDocument must be "opened" with one of OpenL() overloads.
     *
     * @since S60 v3.1
	 */
    IMPORT_C RXmlEngDocument();
    
    /** 
     * Opens the document.
     *
	 * @since S60 v3.2
	 * @param aDOMImpl DOM implementation object
     * @return KErrNone if succeed.
     */
    IMPORT_C void OpenL(RXmlEngDOMImplementation& aDOMImpl);
	
	/** 
     * Opens the document.
     *
	 * @since S60 v3.2
	 * @param aDOMImpl DOM implementation object
 	 * @param aInternal Document pointer
     * @return KErrNone if succeed.
     */
    IMPORT_C void OpenL(RXmlEngDOMImplementation& aDOMImpl, void* aInternal);
    
    /** 
     * Opens the document.
     *
	 * @since S60 v3.2
	 * @param aDOMImpl DOM implementation object
 	 * @param aRoot element taht will be root of the DOM tree
     * @return KErrNone if succeed.
     */
    IMPORT_C void OpenL(RXmlEngDOMImplementation& aDOMImpl, TXmlEngElement aRoot);
    
    /**
     * Closes document
     *
     * @since S60 v3.1
	 */
    IMPORT_C  void Close();

    /**
     * Serializes document tree into a file. For nodes containing binary data in the form of BinaryDataContainer,
     * FileContainer or ChunkContainer, client can implement custom serialization by implementing the interface
     * MXmlEngDataSerializer and specify the pointer in iDataSerializer member of aSaveOptions parameter. If no
     * custom serialization is specified, the binary data container nodes are serialized like text nodes.
     *
     * @since S60 v3.2
	 * @param aFileName A file name (with path)
 	 * @param aRoot Root node to be serialized	
	 * @param aSaveOptions Options that control how serialization is performed 
     * @return Number of byte written
     * @leave KErrNoMemory, KErrGeneral, KXmlEngErrWrongEncoding, KErrDiskFull.
     */
    IMPORT_C TInt SaveL( const TDesC& aFileName,
    					 TXmlEngNode aRoot = TXmlEngNode(),
    					 const TXmlEngSerializationOptions& aSaveOptions = TXmlEngSerializationOptions() ) const;
   
    /**
     * Serializes document tree into a file.  For nodes containing binary data in the form of BinaryDataContainer,
     * FileContainer or ChunkContainer, client can implement custom serialization by implementing the interface
     * MXmlEngDataSerializer and specify the pointer in iDataSerializer member of aSaveOptions parameter. If no
     * custom serialization is specified, the binary data container nodes are serialized like text nodes.
     *
     * @since S60 v3.2
	 * @param aRFs File Server session
	 * @param aFileName A file name (with path)	 
 	 * @param aRoot Root node to be serialized	
	 * @param aSaveOptions Options that control how serialization is performed 
     * @return Number of byte written
     * @leave KErrNoMemory, KErrGeneral, KXmlEngErrWrongEncoding, KErrDiskFull.
     */                        
    IMPORT_C TInt SaveL( RFs& aRFs,
                         const TDesC& aFileName,
                         TXmlEngNode aRoot = TXmlEngNode(),
                         const TXmlEngSerializationOptions& aSaveOptions = TXmlEngSerializationOptions() ) const;
    
    /**
     * Serializes a document tree into provided output stream, which supports progressive writing of data.
     * For nodes containing binary data in the form of BinaryDataContainer, FileContainer or ChunkContainer,
     * client can implement custom serialization by implementing the interface MXmlEngDataSerializer and specify
     * the pointer in iDataSerializer member of aSaveOptions parameter. If no custom serialization is specified,
     * the binary data container nodes are serialized like text nodes.
     *
     * @since S60 v3.1
	 * @param aStream  An output stream to write serialized DOM tree
	 * @param aRoot Root node to be serialized
	 * @param aSaveOptions Options that control how serialization is performed	 	 
     * @return Number of byte written
     * @leave KXmlEngErrWrongUseOfAPI or one of general codes (e.g.KErrNoMemory)
     * @see MXmlEngOutputStream
     */
    IMPORT_C TInt SaveL( MXmlEngOutputStream& aStream,
						 TXmlEngNode aRoot = TXmlEngNode(),
						 const TXmlEngSerializationOptions& aSaveOptions = TXmlEngSerializationOptions() ) const;

    /**
     * Saves document tree into memory buffer
     *
     * @since S60 v3.1
	 * @param aBuffer Resulting buffer
     * @param aRoot A "root" of the subtree to serialize
     * @param aSaveOptions Various options to be effective during serialization
     * @return Number of bytes in updated buffer     
     * @leave KErrNoMemory, KErrGeneral, KXmlEngErrWrongEncoding.
     *
     * @note Result returned via aBuffer argument owns the memory buffer; it is up to 
     *      method caller to free it like in this sample:
     *
     * @see TXmlEngSerializationOptions
     */
    IMPORT_C TInt SaveL(RBuf8& aBuffer, 
    					TXmlEngNode aRoot = TXmlEngNode(), 
                        const TXmlEngSerializationOptions& aSaveOptions = TXmlEngSerializationOptions()) const;
   
    /**
     * Creates complete copy of the document
     *
     * @since S60 v3.1
	 * @return Complete copy of the document tree
     */
	IMPORT_C RXmlEngDocument CloneDocumentL() const;

    /**
     * Creates new element from specific namespace to be a root of the document tree.
     * Any existing document element of the document is destroyed
     *
     * @since S60 v3.1
	 * @param aName Element name
     * @param aNamespaceUri Element namespace URI
     * @param aPrefix Element namemespace prefix
     * @return A new root element
     */
    IMPORT_C TXmlEngElement CreateDocumentElementL(const TDesC8& aName, 
                                             const TDesC8& aNamespaceUri = KNullDesC8, 
                                             const TDesC8& aPrefix = KNullDesC8);

    /**
     * Replaces (and destroys) document element with another one
     * New document element is added as the last child to the document node
     *
     * @since S60 v3.1
	 * @param aNewDocElement New document tree
     *
     * @note Use TXmlEngElement::ReconcileNamespacesL() on the new document element
     *      if it or its descendants can contain references to namespace declarations
     *      out of the element
     * @see TXmlEngElement::ReconcileNamespacesL()
     */
    IMPORT_C void SetDocumentElement(TXmlEngElement aNewDocElement);

    /**
     * Get document encoding
     *
     * @since S60 v3.1
	 * @return Encoding of the source XML data.
     */
    IMPORT_C TPtrC8 XmlEncoding() const;

    /**
     * Get xml version
     *
     * @since S60 v3.1
	 * @return Version number of XML taken from XML declaration
     */
    IMPORT_C TPtrC8 XmlVersion() const;
  
    /**
     * Retrieves base URI (if defined) of the document or NULL
     *
     * @since S60 v3.1
	 * @return Document URI
     */
    IMPORT_C TPtrC8 DocumentUri() const;

    /**
     * Check if document is standalone
     *
     * @since S60 v3.1
	 * @return Whether standalone="true" was specified in XML declaration in the source XML file.
     */
    IMPORT_C TBool IsStandalone() const;

    /**
     * Sets XML version number to be shown in XML declaration when document is serialized.
     *
     * @since S60 v3.1
	 * @param aVersion New version
     */
    IMPORT_C void  SetXmlVersionL(const TDesC8& aVersion);

    /**
     * Sets location of the document.
     * Document's URI is used as top-level base URI definition.
     *
     * @since S60 v3.1
	 * @param aUri New document URI
     */
    IMPORT_C void  SetDocumentUriL(const TDesC8& aUri);

    /**
     * Sets 'standalone' attribute of XML declaration for a document
     *
     * @since S60 v3.1
	 * @param aStandalone Is document standalone
     */
    IMPORT_C void  SetStandalone(TBool aStandalone);

    /**
     * Get dom implementation.
     *
     * @since S60 v3.1
	 * @return Object that represents current DOM implementation
     *
     * @note There is no practical use of implementation object in this version
     *      of API other than for creating new RXmlEngDocument instances, but
     *      it will change in the future, when an implementation object 
     *      is used for changing configuration settings at run-time.
     */
    IMPORT_C RXmlEngDOMImplementation Implementation() const;
    
    /**
     * Get document element
     *
     * @since S60 v3.1
	 * @return A document element - the top-most element in the document tree
     */
    IMPORT_C TXmlEngElement DocumentElement() const;

    /**
     * Sets "document" property on the node and all its descendants to be this RXmlEngDocument node 
     *
     * @since S60 v3.1
	 * @param aSource Node that should be added.
     * @return Adopted node
     */
    IMPORT_C TXmlEngNode AdoptNodeL(TXmlEngNode aSource);

    /**
     * Creates new attribute,
     *
     * @since S60 v3.1
	 * @param aName Name of the atribute; no prefix allowed
     * @param aValue Value of the attribute (optional)
     * @return Handler to the newly created attribute 
     * 
     * @note 
     * aValue should represent a correct value of an attribute if it is put as is into XML file
     * (with all characters correctly escaped with entity references when XML spec requires)
     * 
     * TXmlEngElement class provides a rich set of attribute creation methods, which not
     * just create attribute but also link it into element.
     * 
     * There is no way to create attributes with namespace (despite the DOM spec); 
     * you have to use one of the TXmlEngElement::AddNewAttributeL(..) methods instead
     *
     * Returned handler is the only reference to the allocated memory
     * until you have attached the attribute to some element node
     */
    IMPORT_C TXmlEngAttr CreateAttributeL(const TDesC8& aName,
                                    const TDesC8& aValue = KNullDesC8);

    /**
     * Creates new text node and copies the content string into it.
     *
     * @since S60 v3.1
	 * @param aCharacters Text node content
     * @return Created node
     */
    IMPORT_C TXmlEngTextNode CreateTextNodeL(const TDesC8& aCharacters = KNullDesC8);

    /**
     * Creates new binary container and copies the content string into it.
     * Pointer to the container is stored in the document's 
     * data container list that can be fetched using GetDataContainerList().
     * @see GetDataContainerList( RArray<TXmlEngDataContainer>& aList )
     *
     * @since S60 v3.2
	 * @param aCid Content identifier     
	 * @param aData Binary octets
     * @return Created node
     */
    IMPORT_C TXmlEngBinaryContainer CreateBinaryContainerL( const TDesC8& aCid,
    												  const TDesC8& aData );

    /**
     * Creates new chunk container that stores reference to 
     * memory chunk.
     * Pointer to the container is stored in the document's 
     * data container list that can be fetched using GetDataContainerList().
     * @see GetDataContainerList( RArray<TXmlEngDataContainer>& aList )     
     *
     * @since S60 v3.2
	 * @param aCid Content identifier 
	 * @param aChunk RChunk reference
	 * @param aChunkOffset Offset to the binary data in aChunk
	 * @param aDataSize Size of binary data in aChunk
     * @return Created node
     */
    IMPORT_C TXmlEngChunkContainer CreateChunkContainerL( const TDesC8& aCid, 
    												const RChunk& aChunk,
					                                const TInt aChunkOffset,
					                                const TInt aDataSize );

    /**
     * Creates new file container that stores reference to 
     * file in file system.
     * Pointer to the container is stored in the document's 
     * data container list that can be fetched using GetDataContainerList().
     * @see GetDataContainerList( RArray<TXmlEngDataContainer>& aList )     
     *
     * @since S60 v3.2
	 * @param aCid Content identifier
	 * @param aFile RFile reference
     * @return Created node
     */
    IMPORT_C TXmlEngFileContainer CreateFileContainerL( const TDesC8& aCid, 
    											  const RFile& aFile );

    /**
     * Creates new element node that belongs to specific namespace.
     * A namespace declaration node is created on the element.
     *
     * @since S60 v3.1
	 * @param aNamespaceUri Namespace of new element
     * @param aPrefix Prefix to use for namespace binding and QName of the element
     * @param aLocalName Local name of the element 
     * @return Created node
     * @note If null namespace uri is provided element will be created without namespace.
     */  
    IMPORT_C TXmlEngElement CreateElementL(const TDesC8& aLocalName, 
                                     const TDesC8& aNamespaceUri = KNullDesC8, 
                                     const TDesC8& aPrefix = KNullDesC8);

    /**
     * Creates new comment node and copies the content string into it.
     *
     * @since S60 v3.1
	 * @param aText New comment
     * @return Created node
     */
    IMPORT_C TXmlEngComment CreateCommentL(const TDesC8& aText = KNullDesC8);

    /**
     * Creates new CDATA section node and copies the content into it.
     *
     * @since S60 v3.1
	 * @param aContents CDATASection content
     * @return Created node
     */
    IMPORT_C TXmlEngCDATASection CreateCDATASectionL(const TDesC8& aContents = KNullDesC8);

    /**
     * Creates new entity reference node for aEntityName entity
     *
     * @since S60 v3.1
	 * @param aEntityRef is a string in one of the forms:
     *     -  <i>name</i>
     *     -  <b>&</b><i>name</i>
     *     -  <b>&</b><i>name</i><b>;</b>
     * where <i>name</i> is the name of the entity
     * @return Created node
     * 
     * @note &lt; , &gt; , &apos; , &quot; and other <b>predefined</b> entity references
     *      should not be created with this method. These entity refs are rather 
     *      "character references" and encoded/decoded automatically.
     */
    IMPORT_C TXmlEngEntityReference CreateEntityReferenceL(const TDesC8& aEntityRef);

    /**
     * Creates new processing instruction node and set its "target" and "data" values
     *
     * @since S60 v3.1
	 * @param aTarget Target
     * @param aData Data
     * @return Created node
     */
    IMPORT_C TXmlEngProcessingInstruction CreateProcessingInstructionL(const TDesC8& aTarget, 
                                                                 const TDesC8& aData = KNullDesC8);
                                                                 
    /**
     * Registers specified attribute as xml:id.
     * First parametr allows user, to specify sub-tree, not to search whole document.
     * To search whole tree see @see RegisterXmlId(const TDesC8,const TDesC8)
     *
     * @since S60 v3.2
     * @param aStartElement Root of tree to search (should be part of the document)
     * @param aLocalName Name of attribute
	 * @param aNamespaceUri Namespace of new element (default empty)
     */
    IMPORT_C void RegisterXmlIdL(TXmlEngElement aStartElement,
                                 const TDesC8& aLocalName, 
                                 const TDesC8& aNamespaceUri = KNullDesC8);

    /**
     * Registers specified attribute as xml:id.
     * Not to search whole tree see @see RegisterXmlId(TXmlEngElement,const TDesC8,const TDesC8)
     *
     * @since S60 v3.2
     * @param aLocalName Name of attribute
	 * @param aNamespaceUri Namespace of new element (default empty)
     */
    IMPORT_C void RegisterXmlIdL(const TDesC8& aLocalName, 
                                 const TDesC8& aNamespaceUri = KNullDesC8);
       
    /**
     * Looks for element with specified value of xml:id
     *
     * @since S60 v3.2
	 * @param aValue Name of attribute
     * @return found element or null-element.
     */
    IMPORT_C TXmlEngElement FindElementByXmlIdL(const TDesC8& aValue ) const;  

    /**
     * Retrieves an array of data containers owned by this document.
     *
	 * @note The document ceases to be the owner of data container when data container
	 *		 (or one of its predecessors) is removed from the document or data container 
	 * 	 	 (or one of its predecessors) becomes a part of another document.
	 *		 Unlinking data container (or one of its predecessors) doesn't remove
	 *		 ownership of data container from the this document so the list might
	 *		 contain containers that are not linked to this document anymore.    
     * @since S60 v3.2
	 * @param aList Array of data containers
     */
    IMPORT_C void GetDataContainerList( RArray<TXmlEngDataContainer>& aList );         
                                                                 
protected:
    friend class RXmlEngDOMParser;
    friend class TXmlEngNode;
    friend class TXmlEngAttr;
    friend class TXmlEngElement;
    friend class RXmlEngDOMImplementation;

protected:
    /**
     * Constructor
     *
     * @since S60 v3.1
	 * @param aInternal Document pointer
	 */
    inline RXmlEngDocument(void* aInternal);

    /**
     * DISABLED for document; CloneDocumentL() must be used
     *
     * @since S60 v3.1
	 */
    inline TXmlEngNode CopyL() const; 

    /**
     * DISABLED for document; Destroy() must be used
     *
     * @since S60 v3.1
	 */    
    inline void Remove();

    /**
     * DISABLED for document; Destroy() must be used
     *
     * @since S60 v3.1
	 */ 
    inline void ReplaceWith(TXmlEngNode aNode);
private:
    /**
     * Main implementation of SaveL() functions that puts together all common code
     * and serializes to buffer or output stream.
     *
     * @since S60 v3.2
	 * @param aNode Root node to be serialized     
	 * @param aBuffer buffer with serialized data.
	 * @param aOutputStream stream that should be used during serialization
	 * @param aSaveOptions Options that control how serialization is performed
     * @return Number of bytes written
     * @leave KErrNoMemory, KErrGeneral, KXmlEngErrWrongEncoding, KErrDiskFull.     
	 */ 
	TInt SaveNodeL( TXmlEngNode aNode,
					RBuf8& aBuffer,
               	    MXmlEngOutputStream* aOutputStream = NULL,
               	    TXmlEngSerializationOptions aOpt = TXmlEngSerializationOptions()) const;	

    /**
     * "Secondary" constructor that should be called on every newly created document node.
     * Initializes container for nodes owned by the document.
     *
     * The need for such secondary constructor is in the fact that underlying libxml2
     * library knows nothing about ownership of unlinked nodes -- this feature is
     * implemented in C++ DOM wrapper.
     *
     * @since S60 v3.1
	 */ 
    void InitOwnedNodeListL();

    /**
     * Adds aNode to the list of owned nodes - the nodes that are not linked yet into a 
     * document tree, but still destroyed with the document that owns them.
     *
     * @since S60 v3.1
	 * @param aNode Node that should be added to document
     *
     * In case of OOM (during growing node list container) the argument node is freed with
     * xmlFreeNode()
     */ 
    void TakeOwnership(TXmlEngNode aNode);

    /**
     * Remove aNode from the list of owned nodes.
     *
     * @since S60 v3.1
	 * @param aNode Node that should be removed from document
     */
    void RemoveOwnership(TXmlEngNode aNode);

protected:
    /**  Pointer to DOM implementation object */
    RXmlEngDOMImplementation* iImpl;

};// class RXmlEngDocument



#include "xmlengdocument.inl"

#endif /* XMLENGINE_DOCUMENT_H_INCLUDED */
