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
* Description:        Central place for debug-type macros
*
*/








#ifndef SEN_FRAGMENT_H
#define SEN_FRAGMENT_H

//  INCLUDES
#include <e32base.h>
#include <s32strm.h>
#include <xml/Attribute.h>
#include <SenXmlReader.h>
#include <SenElement.h>
#include <MSenFragment.h>
// CLASS DECLARATION

/**
* Abstract base class declaring XML fragment interface.
* @lib SenXML.dll
* @since Series60 3.0
*/
class CSenFragment : public CBase, public MSenFragment
    {
    public: // New functions

        /**
         * Getting the fragment as an XML element. This method will panic if 
         * element has not been initialized for any reason.
         * @return the current object as element. Ownership is not transferred.
         */
        virtual CSenElement& AsElement() = 0;

        /**
         * @return the current object as element. May return NULL.
         *          Caller takes ownership.
         *
         * Note(!): the return value (CSenElement) STRONGLY suggests that
         * subclasses INHERIT CSenFragment in order properly comply the
         * requirement of the ExtractElement() implementation.
         */
        virtual CSenElement* ExtractElement() = 0;

        /**
         * Sets the XML reader to be used for parsing for the fragment.
         * @param aReader:      the reader to be used. 
         *                      Ownership is NOT transferred.
         */
        virtual void SetReader(CSenXmlReader& aReader) = 0;

        /**
         * Gets the XML reader which this fragment uses for parsing.
         * @param aReader:      the reader to be used. 
         *                      Ownerships is not transferred.
         */
        virtual CSenXmlReader* Reader() = 0;

        /**
         * Method to invoke parsing of a XML data.
         * Note: SetReader() must be called before this method can be used.
         * @param aXml: The XML data to be parsed.
         */
        virtual void ParseL(const TDesC8& aXml) = 0;

        /**
         * Same as ParseL() except that it doesn't leave in case of an error. 
         * Instead errors are trapped and error is returned.
         * SetReader() must be called before this method can be used.
         * @return KErrNone or other system-wide Symbian error codes.
         */
        virtual TInt BuildFrom(const TDesC8& aBuf) = 0;

        /**
         * Let the delegate MSenFragment handle the following SAX events.
         * This fragment is made the owner of the delegate and
         * the delegate is expected to make this MSenFragment the receiver
         * of SAX events once it has seen the end element for itself.
         * @param aDelegate:    the fragment to start handling the SAX events.
         */
        virtual void DelegateParsingL(MSenFragment& aDelegate) = 0;

        /**
         * Creates a new fragment and lets the created MSenFragment handle 
         * the following SAX events.
         * This fragment is made the owner of the delegate and
         * the delegate is expected to make this MSenFragment the receiver
         * of SAX events once it has seen the end element for itself.
         * @param aNsUri:       the namespace URI of the new delegate
         * @param aLocalName:   the local name of the new delegate
         * @param aQName:       the qualified name of the new delegate
         * @param aAttrs:       the attributes which to be set for the new delegate
         */
        virtual void DelegateParsingL(const TDesC8& aNsUri,
                                      const TDesC8& aLocalName,
                                      const TDesC8& aQName,
                                      const RAttributeArray& aAttrs) = 0;

        /**
         * Sets the reader for this fragment and sets this to be the 
         * content handler of the following SAX events.
         * @param aReader:  Reader to be used.
         */
        virtual void ParseWithL(CSenXmlReader& aReader) = 0;

        /**
         * Sets a new parent for this fragment.
         * @param aFragment:    the new parent.
         */
        virtual void SetOwner(MSenFragment& aFragment) = 0;

        /**
         * Resumes the parsing. Usually called by the delegate fragment which was
         * parsing itself after DelegateParsingL().
         * @param aNsUri        The namespace URI of the current element
         * @param aLocalName    The local name of the current element
         * @param aQName        The qualified name of the current element
         */
        virtual void ResumeParsingFromL(const TDesC8& aNsUri,
                                        const TDesC8& aLocalName,
                                        const TDesC8& aQName) = 0;

        /**
         * Sets the attributes for the fragment.
         * @param aAttrs:   the array of attributes.
         */
        virtual void SetAttributesL(const RAttributeArray& aAttrs) = 0;

        /**
         * Writes the start element tag to the content stream. 
         * Derivants can override the basic usage used in BaseFragment.
         * @param aNsUri        The namespace URI of the current element
         * @param aLocalName    The local name of the current element
         * @param aQName        The qualified name of the current element
         * @param aAttrs:       the array of attributes.
         */
        virtual void WriteStartElementL(const TDesC8& aNsUri,
                                        const TDesC8& aLocalName,
                                        const TDesC8& aQName,
                                        const RAttributeArray& aAttrs) = 0;

        /**
         * Writes the end element tag to the content stream. 
         * Derivants can override the basic usage used in BaseFragment.
         * @param aNsUri        The namespace URI of the current element
         * @param aLocalName    The local name of the current element
         * @param aQName        The qualified name of the current element
         */
        virtual void WriteEndElementL(const TDesC8& aNsUri,
                                      const TDesC8& aLocalName,
                                      const TDesC8& aQName) = 0;

        /**
        * Getter for Fragment's local name.
        * @return Localname or KNullDesC if not set.
        */
        virtual const TDesC8& LocalName() const = 0;

        /**
        * Getter for Fragment's namespace URI.
        * @return Namespace URI or KNullDesC if not set.
        */
        virtual const TDesC8& NsUri() const = 0;

        /**
         * Getter for namespace prefix of this fragment.
         * @return namespace prefix or KNullDesC if not set.
         */
        virtual const TDesC8& NsPrefix() const = 0;

        /**
         * Fragment writes itself to a write stream using UTF-8 charset encoding.
         * @param aWriteStream: The stream to write to.
         */
        virtual void WriteAsXMLToL(RWriteStream& aWriteStream) = 0;

        /**
         * Gets the fragment as an unicode XML buffer. 
         * Buffer will contain all the childs etc.
         * @return  fragment as XML. Caller takes ownership.
         */
        virtual HBufC* AsXmlUnicodeL() = 0;

        /**
         * Gets the fragment as an XML buffer.
         * @return  fragment as XML. Caller takes ownership.
         */
        virtual HBufC8* AsXmlL() = 0;

        /**
         * Getter for the content. Returns content namespaces if there are any.
         * @return Content.
         */
        virtual TPtrC8 Content() = 0;

        /**
         * Checks if fragment matches to another fragment 
         * by its content and child elements. 
         * Fragment can contain more data than the given candidate.
         * @since Series60 3.0
         * @param aCandidate    The pattern to be matched. Must contain same or 
         *                      less data for match to come true.
         * @return ETrue if content and possible children match exactly 
         *          to given pattern. EFalse otherwise.
         */
        virtual TBool ConsistsOfL(MSenFragment& aCandidate) = 0;
    };

#endif // SEN_FRAGMENT_H

// End of File


