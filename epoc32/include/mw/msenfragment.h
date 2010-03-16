/*
* Copyright (c) 2002-2005 Nokia Corporation and/or its subsidiary(-ies). 
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
* Description:        This abstract class defines the interface for WSF XML
*                fragment classes.
*
*/








#ifndef M_SEN_FRAGMENT_H
#define M_SEN_FRAGMENT_H

//  INCLUDES
#include <e32base.h>
#include <s32strm.h>
#include <xml/Attribute.h>
#include <SenXmlReader.h>
#include <MSenElement.h>

// FORWARD DECLARATIONS
class CSenElement;

using namespace Xml;


// CLASS DECLARATION

/**
*  This abstract class defines the interface for XML fragment classes.
*  The subclasses are used to extract certain part of XML document into
*  a separate XML subtree, called fragment. This M-class is typically used
*  when a safe reference to some actual implementation is required.
*  Fragment classes are content handlers for SAX callback events received
*  from CSenXmlReader class. They typically inherit MSenContentHandlerClient
*  to achive this.
*  @lib SenXML.dll
*  @since Series60 3.0
*/
class MSenFragment
    {
    public: // New functions
        /**
         *  Getting the fragment as an XML element. This method will panic if 
         *  element has not been initialized (EFragmentElementNotInitialized).
         *  @since Series60 3.0
         *  @return the current object as element. Ownership is not transferred.
         */
        virtual CSenElement& AsElement() = 0;

        /**
         *  Method extracts the root element (whole data) from this fragment.
         *  After calling this method, the fragment does not have any
         *  internal element. Method is often called before fragment is
         *  destroyed, in order to fetch its content and transfer ownership
         *  to that content to some other object.
         *  @since Series60 3.0
         *  @return the current object as element. May return NULL.
         *          Ownership is transferred to the caller.
         */
        virtual CSenElement* ExtractElement() = 0;

        /**
         *  Sets the XML reader to be used for parsing for the fragment.
         *  @since Series60 3.0
         *  @param aReader:     the reader to be used. 
         *                      Ownership is NOT transferred.
         */
        virtual void SetReader(CSenXmlReader& aReader) = 0;

        /**
         *  Gets the XML reader which this fragment uses for parsing.
         *  @since Series60 3.0
         *  @param aReader:     the reader to be used. 
         *                      Ownerships is not transferred.
         *                      May return NULL.
         */
        virtual CSenXmlReader* Reader() = 0;

        /**
         *  Method to invoke parsing of a UTF-8 form XML data.
         *  Note that SetReader() must be called before this 
         *  method can be used.
         *  Parsing is dependent of preset localname or qualifiedname
         *  and possible namespace for this fragment.
         *  @since Series60 3.0
         *  @param aBuf:    The XML to be parsed.
         */
        virtual void ParseL(const TDesC8& aBuf) = 0;

        /**
         *  Same as ParseL() except that it doesn't leave in case of an error. 
         *  Instead errors are trapped and error is returned.
         *  SetReader() must be called before this method can be used.
         *  @since Series60 3.0
         *  @param aBuf:    The XML to be parsed.
         *  @return KErrNone or other system-wide Symbian error codes
         */
        virtual TInt BuildFrom(const TDesC8& aBuf) = 0;

        /**
         *  Let the delegate MSenFragment handle the following SAX events.
         *  This fragment is made the owner of the delegate and the delegate
         *  is expected to make this MSenFragment the receiver of SAX events
         *  once it has seen the end element for itself. This is achieved by
         *  ResumeParsingFromL(), which delegate will call from his parent.
         *  The currently set XML reader is used to parse XML for the delagate,
         *  too.
         *  @since Series60 3.0
         *  @param aDelegate:   the fragment to start handling the SAX events.
         */
        virtual void DelegateParsingL(MSenFragment& aDelegate) = 0;

        /**
         *  Creates a new delegate (fragment) using the given arguments
         *  and lets it handle the SAX events according
         *  to given localname (or qualifiedname) and possible namespace.
         *  This instance is made the owner of the delegate and the delegate 
         *  is expected to resume parsing to this MSenFragment after it has
         *  finished handling the dedicated part of XML document in question.
         *  at the EndElementL().
         *  The currently set XML reader is used to parse XML for the delagate,
         *  too.
         *  @since Series60 3.0
         *  @param aNsUri:      the namespace URI of the new delegate
         *  @param aLocalName:  the local name of the new delegate
         *  @param aQName:      the qualified name of the new delegate
         *  @param aAttrs:      the attributes which to be set for the new delegate
         */
        virtual void DelegateParsingL(  const TDesC8& aNsUri,
                                        const TDesC8& aLocalName,
                                        const TDesC8& aQName,
                                        const RAttributeArray& aAttrs) = 0;

        /**
         *  Method sets the reader for this fragment and sets this to be the 
         *  content handler for the SAX events according to preset localname
         *  (or qualifiedname) and possible namespace.
         *  @since Series60 3.0
         *  @param aReader: Reader to be used.
         */
        virtual void ParseWithL(CSenXmlReader& aReader) = 0;

        /**
         *  Sets a new owner (parent) for this fragment.
         *  @since Series60 3.0
         *  @param aFragment:   the new parent.
         */
        virtual void SetOwner(MSenFragment& aFragment) = 0;

        /**
         *  Resumes the parsing. Usually called by some delegate 
         *  fragment which was parsing itself through DelegateParsingL()
         *  call from this instance.
         *  @since Series60 3.0
         *  @param aNsUri       The namespace URI of the current element
         *  @param aLocalName   The local name of the current element
         *  @param aQName       The qualified name of the current element
         */
        virtual void ResumeParsingFromL(const TDesC8& aNsUri,
                                        const TDesC8& aLocalName,
                                        const TDesC8& aQName) = 0;

        /**
         *  Sets the attributes for the fragment.
         *  @since Series60 3.0
         *  @param aAttrs:  the array of attributes.
         */
        virtual void SetAttributesL(const RAttributeArray& aAttrs) = 0;

        /**
         *  Writes the start element tag to the content stream. 
         *  Subclasses typically override this.
         *  @since Series60 3.0
         *  @param aNsUri       The namespace URI of the current element
         *  @param aLocalName   The local name of the current element
         *  @param aQName       The qualified name of the current element
         *  @param aAttrs:  the array of attributes.
         */
        virtual void WriteStartElementL(const TDesC8& aNsUri,
                                        const TDesC8& aLocalName,
                                        const TDesC8& aQName,
                                        const RAttributeArray& aAttrs) = 0;

        /**
         *  Writes the end element tag to the content stream. 
         *  Subclasses typically override this
         *  @since Series60 3.0
         *  @param aNsUri       The namespace URI of the current element
         *  @param aLocalName   The local name of the current element
         *  @param aQName       The qualified name of the current element
         */
        virtual void WriteEndElementL(const TDesC8& aNsUri,
                                      const TDesC8& aLocalName,
                                      const TDesC8& aQName) = 0;

        /**
        *   Getter for fragment XML local name.
        *   @since Series60 3.0
        *   @return localname or KNullDesC8 if not set.
        */
        virtual const TDesC8& LocalName() const = 0;
        
        /**
        *   Getter for fragment XML namespace URI.
        *   @since Series60 3.0
        *   @return namespace URI or KNullDesC8 if not set.
        */
        virtual const TDesC8& NsUri() const = 0;

        /**
         *  Getter for XML namespace prefix of this fragment.
         *  @since Series60 3.0
         *  @return namespace prefix or KNullDesC8 if not set.
         */
        virtual const TDesC8& NsPrefix() const = 0;

        /**
         *  Fragment writes itself to a write stream using UTF-8 encoding.
         *  @since Series60 3.0
         *  @param aWriteStream:    The stream to write to.
         */
        virtual void WriteAsXMLToL(RWriteStream& aWriteStream) = 0;

        /**
         *  Gets the fragment as Unicode (UCS-2) form XML. 
         *  @since Series60 3.0
         *  @return fragment as XML. Caller takes ownership.
         */
        virtual HBufC* AsXmlUnicodeL() = 0;

        /**
         *  Gets the fragment as a UTF-8 form XML.
         *  @since Series60 3.0
         *  @return fragment as XML. Caller takes ownership.
         */
        virtual HBufC8* AsXmlL() = 0;

        /**
         * Checks if fragment matches to another fragment by its content and 
         * child elements. Fragment can contain more data than the given 
         * candidate.
         * @since Series60 3.0
         * @param aCandidate    The pattern to be matched. Must contain same or 
         *                      less data for match to come true.
         * @return ETrue if content and possible children match exactly 
         *          to given pattern. EFalse otherwise.
         */
        virtual TBool ConsistsOfL(MSenFragment& aCandidate) = 0;
    };

#endif // M_SEN_FRAGMENT_H

// End of File
