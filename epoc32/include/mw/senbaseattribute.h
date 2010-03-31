/*
* Copyright (c) 2002-2005 Nokia Corporation and/or its subsidiary(-ies). 
* All rights reserved.
* This component and the accompanying materials are made available
* under the terms of "Eclipse Public License v1.0"
* which accompanies this distribution, and is available
* at the URL "http://www.eclipse.org/legal/epl-v10.html".
*
* Initial Contributors:
* Nokia Corporation - initial contribution.
*
* Contributors:
*
* Description:        Class offers basic implementation of an XML attribute
*
*/








#ifndef SEN_BASE_ATTRIBUTE_H
#define SEN_BASE_ATTRIBUTE_H

//  INCLUDES
#include <e32base.h>
#include <s32strm.h>

// CLASS DECLARATION

/**
*  Class offers basic implementation of an XML attribute
*  XML attribute is a name-value pair type value object,
*  which may or may not have a namespace prefix. Note 
*  that both name and value may contain a namespace prefix.
*  @lib SenXML.dll
*  @since Series60 3.0
*/
class CSenBaseAttribute : public CBase
    {
    public:  // Constructors and destructor

        /**
         *  Basic two-phased constructor.
         *  @since Series60 3.0
         *  @param aName:   Name of the attribute
         *  @param aValue:  Attribute's value.
         *  Leave codes:    
         *      KErrSenInvalidCharacters if aName contains illegal characters.      
         *      KErrSenZeroLengthDescriptor if aLocalName or aQName is zero length.
         */
        IMPORT_C static CSenBaseAttribute* NewL(const TDesC8& aName,
                                                const TDesC8& aValue);

        /**
         *  Basic constructor.
         *  @since Series60 3.0
         *  @param aQName:  Qualified name of the attribute
         *  @param aName:   Name of the attribute
         *  @param aValue:  Attribute's value.
         *  Leave codes:    
         *      KErrSenInvalidCharacters if aName or aQName contain 
         *      illegal characters.     
         *      KErrSenZeroLengthDescriptor if aLocalName or aQName is zero length.
         */
        IMPORT_C static CSenBaseAttribute* NewL(const TDesC8& aQName,
                                                const TDesC8& aName,
                                                const TDesC8& aValue);
            
        /**
        * Destructor.
        */
        IMPORT_C virtual ~CSenBaseAttribute();
        
        // New functions
        
        /**
         * Getter for the attribute name.
         * @since Series60 3.0
         * @return the attribute name.
         */
        virtual const TDesC8& Name() const;

        /**
         * Getter for the attribute value.
         * @since Series60 3.0
         * @return the attribute value.
         */
        virtual const TDesC8& Value() const;
        
        /**
         * Setter for the attribute value.
         * @since Series60 3.0
         * @param aValue:   value to be set
         * @return the new value.
         */
        virtual const TDesC8& SetValueL(const TDesC8& aValue);
    
    protected:  
    
        /**
        * C++ default constructor
        * @since Series60 3.0
        */
        IMPORT_C CSenBaseAttribute();
    
        /**
         * Following BaseConstructL methods should be called from the deriving
         * classes ConstructL() methods. Parameter info is found in the
         * corresponding NewL-methods.
         * @since Series60 3.0
         * @param aName is the name of this attribute. Cannot contain characters
         *        that are illegal in XML (like basic entities in decoded form)
         * @param aValue is the value of this attribute. Cannot contain characters
         *        that are illegal in XML (like basic entities in decoded form)
         */
        IMPORT_C void BaseConstructL(const TDesC8& aName,
                                    const TDesC8& aValue);

        /**
        * @since Series60 3.0
        * @param aName is the name of this attribute. Cannot contain characters
        *        that are illegal in XML (like basic entities in decoded form)
        * @param aQName is the qualified, prefixed name of this XML attribute.
        *        Cannot contain characters which are illegal in XML.
        * @param aValue is the value of this attribute. Cannot contain characters
        *        that are illegal in XML (like basic entities in decoded form)
        */
        IMPORT_C void BaseConstructL(const TDesC8& aName,
                                     const TDesC8& aQName,
                                     const TDesC8& aValue);
        
    private:    // Data
        HBufC8* ipName;
        HBufC8* ipValue;
    };

#endif // SEN_BASE_ATTRIBUTE_H

// End of File

