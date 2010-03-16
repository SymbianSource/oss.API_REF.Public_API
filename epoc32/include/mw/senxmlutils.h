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
* Description:        This class offers a set of utility functions for XML data
*
*/









#ifndef SEN_XML_UTILS_H
#define SEN_XML_UTILS_H

//  INCLUDES
#include <e32base.h>
#include <stringpool.h>


namespace Xml
    {
    // FORWARD DECLARES
    class RAttribute;

    // TYPE DEFINITIONS
    typedef RArray<RAttribute> RAttributeArray;
    }

using namespace Xml;

class CSenElement;
class CSenBaseAttribute;


// CONSTANTS
namespace
    {
    const TInt KMaxEscapedLength = 8;

/*
    // Moved to SenXmlConstants.hß

    // Five basic entities as descriptors
    _LIT8(KSenEscapedApos,     "&apos;");
    _LIT8(KSenEscapedDblQuot,  "&quot;");
    _LIT8(KSenEscapedGt,       "&gt;");
    _LIT8(KSenEscapedLt,       "&lt;");
    _LIT8(KSenEscapedAmp,      "&amp;");

    // XML-escaping chars as descriptors
    _LIT8(KSenAmpersandDesC8,  "&");
    _LIT8(KSenAposDesC8,       "\'");
    _LIT8(KSenDblQuotDesC8,    "\"");
    _LIT8(KSenGtDesC8,         ">");
    _LIT8(KSenLtDesC8,         "<");
*/    
    }
    
// CLASS DECLARATION

/**
*  This class offers a set of utility functions for XML data
*  The helper methods include Unicode (UCS2) and UTF-8 encoding
*  and decoding as well as convenience methods to encode and
*  decode the five basic XML entities. There are functions
*  for extracting XML prefixes and building of qualifiedname
*  and a functionality for checking if an element name value 
*  is illegal or not.
*  @lib SenXML.dll
*  @since Series60 3.0
*/
class SenXmlUtils
    {
    public: // New functions
        /**
         * Helper function to convert unicode string to UTF-8 encoded.
         * @since Series60 3.0
         * @param aUnicodeString    string to be converted.
         * @return buffer as UTF-8, caller takes ownership.
        */
        IMPORT_C static HBufC8* ToUtf8LC(const TDesC16& aUnicodeString);

        /**
         * Helper function to convert UTF-8 string to unicode encoded.
         * @since Series60 3.0
         * @param aUtf8String   string to be converted.
         * @return buffer as unicode, caller takes ownership.
         */
        IMPORT_C static HBufC16* ToUnicodeLC(const TDesC8& aUtf8String);

        /**
         * Helper function to determine if a string starts with another string.
         * @since Series60 3.0
         * @param aDes  string to be searched from.
         * @param aPrefix   the prefix to be searched.
         * @return ETrue if given string starts with given prefix, 
         *          otherwise EFalse.
         */
        IMPORT_C static TBool StartsWith(const TDesC8& aDes,
                                         const TDesC8& aPrefix);

        /**
         * Helper function to determine if a string ends with another string.
         * @since Series60 3.0
         * @param aDes  string to be searched from.
         * @param aPrefix   the prefix to be searched.
         * @return ETrue if given string ends with given prefix, 
         *          otherwise EFalse.
         */
        IMPORT_C static TBool EndsWith(const TDesC8& aDes, const TDesC8& aPostfix);

        /**
         * Helper function to find a value of a given attribute.
         * @since Series60 3.0
         * @param aAttributes   Array which contains the attributes.
         * @param aAttrName The name of the attribute which value is asked.
         * @return The value of the wanted attribute, or KNullDesC8 if given
         *          attribute name was not found.
         */
        IMPORT_C static TPtrC8  AttrValue(  const RAttributeArray& aAttributes,
                                            const TDesC8& aAttrName);

        /**
         * Get a newly allocated copy of the attribute.
         * @since Series60 3.0
         * @param apAttrs       Array which contains the attributes.
         * @param aAttrName The name of the attribute which value is asked.
         * @return A buffer containing the value of the wanted attribute.
         *          Buffer is newly allocated and ownership is transferred 
         *          to the caller. Can be NULL if attribute was not found.
         */
        IMPORT_C static HBufC8* AllocAttrValueL(const RAttributeArray& apAttrs,
                                                const TDesC8& aAttrName);

        /**
         * Helper function to construct a qualified name.
         * @since Series60 3.0
         * @param aPrefix       the prefix to be used.
         * @param aLocalName    the local name to be used.
         * @param   aQName      a ref-to-pointer which will contain the allocated
         *                      qualified name. This param should be NULL when
         *                      passed, otherwise memory leak will occur.
         *                      Caller has the ownership of this buffer.
         */
        IMPORT_C static void BuildQNameL(   const TDesC8& aPrefix, 
                                            const TDesC8& aLocalName,
                                            HBufC8*& aQName);

        /**
         * Encodes XML-escaping characters found from aOriginal 
         * to XML Basic Entities. 
         * Note, that aEncoded is not re-assigned IF there were NO
         * XML-escaping characters - '&', ''', '"', '<' or '>' -found.   
         * Otherwise, when encoding has been done, the aEncoded points
         * to newly allocated descriptor, which ownership belongs to
         * the caller (who should have given aEncoded pointer as NULL
         * in any case).
         * @since Series60 3.0
         * @param aOriginal the original descriptor.
         * @param aEncoded      a ref-to-pointer which will contain the allocated
         *                      encoded string. This param should be NULL when
         *                      passed, otherwise memory leak will occur.
         *                      Caller has the ownership of this buffer.
         */
        IMPORT_C static TBool EncodeHttpCharactersL(const TDesC8& aOriginal,
                                                    HBufC8*& aEncoded);
        /**
         * Method leaves if aCandidate contains illegal, XML-escaping characters.
         * Those characters, which will cause a leave are:
         *                           '&', ''', '"', '<' and '>'
         * @since Series60 3.0
         * @param   aCandidate  string to be checked.
         * Leave codes:
         *      KErrSenInvalidCharacters    if contains invalid characters.
         */
        IMPORT_C static void LeaveOnXmlEscapesL(const TDesC8& aCandidate); 
 
        /**
         * Method leaves if aCandidate contains illegal, XML-escaping characters
         * or is an empty descriptor.
         * Those characters, which will cause a leave are:
         *                           '&', ''', '"', '<' and '>'
         * @since Series60 3.0
         * @param   aCandidate  string to be checked.
         * Leave codes:
         *      KErrSenInvalidCharacters    if contains invalid characters.
         *      KErrSenZeroLengthDescriptor if aCandidate is zero length
         */
        static void LeaveOnInvalidElementNameL(const TDesC8& aCandidate);
        
        /**
         * Encodes XML-escaping characters found from aOriginal 
         * to XML Basic Entities. 
         *          Example: '&' -> '&amp;'
         * Note! Function returns a copy of aOriginal descriptor,
         * even if not a single illegal, XML-escaping character
         * was encoded.
         * The returned pointer to heap allocated descriptor is
         * pushed to the cleanup stack.
         * @since Series60 3.0
         * @param   aOriginal   the string to be encoded.
         * @return  a buffer containing the encoded string. 
         *          Ownership is transferred to the caller.
         */
        IMPORT_C static HBufC8* EncodeHttpCharactersLC(const TDesC8& aOriginal);

        /**
         * Method to provide functionality for decoding HTTP characters into
         * XML escaping characters.
         * @since Series60 3.0
         * @param   aOriginal   the string to be decoded.
         * @param   aDecoded    the buffer that will contain the decoded string
         *                      on return. Caller has the ownership of this.
         *                      Will be similar as aOriginal if nothing was 
         *                      replaced.
         * @return ETrue if any XML escaping (some Basic Entity) 
         *                  character-sequence was decoded.
         */
        IMPORT_C static TBool DecodeHttpCharactersL(const TDesC8& aOriginal,
                                                HBufC8*& aDecoded);
        
        /**
         * Same as DecodeHttpCharactersL(), but the decoded string OR
         * exact copy of the aOriginal descriptor is returned and pushed
         * to cleanup stack.
         * @since Series60 3.0
         * @param   aOriginal   the string to be decoded.
         * @return buffer located in the cleanup stack containing the decoded 
         *          string
         */
        IMPORT_C static HBufC8* DecodeHttpCharactersLC(const TDesC8& aOriginal);

        /**
         * Helper function to get a prefix from a qualified name.
         * @since Series60 3.0
         * @param   aQName  the qualified name
         * @return the namespace prefix for the element, e.g. 'soap' for
         *      'soap:Body'. The returned pointer is empty if there is no prefix.
         */
        IMPORT_C static TPtrC8 NsPrefix(const TDesC8& aQName);

        /**
         *  Helper function to get a local name from a qualified name.
         *  @since Series60 3.0
         *  @param  aQName  the qualified name
         *  @return the local name for the element, e.g. 'Body' for
         *      'soap:Body'.
         */
        IMPORT_C static TPtrC8 LocalName(const TDesC8& aQName);

        /**
        * Removes certain attribute from given element. May also be used when
        * removing namespaces from the element.
        * @param aElement   Element from which attribute will be removed.
        * @param aAttrName  Attribute's local name
        * @return pointer to removed attribute, which ownership is transferred to
        * caller or NULL, if no matching attribute was found from this element. 
        */
        IMPORT_C static CSenBaseAttribute* RemoveAttributeL(CSenElement& aElement,
                                                            const TDesC8& aAttrName);

        /** 
        * Removes attribute from this element.
        * @param aElement       Element from which attribute will be removed.
        * @param apAttribute    is the attribute to be removed.
        * transferred to this element.
        * @return pointer to removed attribute, which ownership is transferred to
        * caller or NULL, if no matching attribute was found from this element. 
        */
        IMPORT_C static CSenBaseAttribute* RemoveAttributeL(CSenElement& aElement,
                                                            CSenBaseAttribute* apAttribute);

        /**
        * Adds an attribute into this element. Used also adding new namespaces
        * into the element.
        * @param aQName     Attribute's qualified name
        * @param aLocalName Attribute's local name
        * @param aValue     Attribute's value
        * @return value of the attribute as string (TDesC&)
        * Leave codes:  
        *       KErrSenInvalidCharacters if aLocalName or aQName contain illegal 
        *       characters.     
        *       KErrSenZeroLengthDescriptor if aLocalName or aQName is zero length.
        */
        IMPORT_C static const TDesC8& AddAttributeL(CSenElement& aElement,
                                                    const TDesC8& aQName,
                                                    const TDesC8& aLocalName,
                                                    const TDesC8& aValue);

        /**
        * Adds an attribute into this element. Used also adding new namespaces
        * into the element.
        * @param aLocalName Attribute's local name
        * @param aValue     Attribute's value
        * @return value of the attribute as string (TDesC&)
        * Leave codes:  
        *       KErrSenInvalidCharacters if aLocalName contains illegal characters.     
        *       KErrSenZeroLengthDescriptor if aAttrName is zero length, or
        *       if the local name part of it is zero length.
        */
        IMPORT_C static const TDesC8& AddAttributeL(CSenElement& aElement,
                                                    const TDesC8& aAttrName,
                                                    const TDesC8& aValue);
        /** 
        * Adds an attribute into this element.
        * @param apAttribute    Attribute to be added. Ownership is transferred
        *                       to this element.
        * @return attribute value as a string (TDesC8&)
        */
        IMPORT_C static const TDesC8& AddAttributeL(CSenElement& aElement,
                                                    CSenBaseAttribute* apAttribute);
        
    private:
        
        /**
        * C++ default constructor.
        */
        SenXmlUtils() { }

        /**
        * Prohibit copy constructor if not deriving from CBase.
        */
        SenXmlUtils( const SenXmlUtils& );
        
        /** 
        * Prohibit assignment operator if not deriving from CBase.
        */
        SenXmlUtils& operator=( const SenXmlUtils& );

        /**
        * Replaces the destination with the given values
        */
        static TBool ReplaceAll( TPtr8 aDestination, 
                                 const TDesC8& aFrom,
                                 const TDesC8& aTo );        

		/**
		* Finds the attribute with the given name
		*/
        static CSenBaseAttribute* FindAttrL( CSenElement& aElement,
                                             const TDesC8& aName );
    };

#endif // SEN_XML_UTILS_H

// End of File

