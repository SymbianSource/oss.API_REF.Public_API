/*
* Copyright (c) 2005 Nokia Corporation and/or its subsidiary(-ies). 
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
* Description:  Transport and Xml properies interface declaration     
*
*/

#ifndef M_SEN_PROPERTIES_H
#define M_SEN_PROPERTIES_H

const TInt KErrSenOmitted = 10;

// INCLUDES
#include <e32std.h>

// FORWARD DECLARATIONS
class RWriteStream;
class CSenXmlReader;

class MSenProperties
    {
    public:
        /**
        * PropertiesClassType enumeration. 
        */
        enum TSenPropertiesClassType
        	{
        	ENotInUse                           = 0,
        	ESenXmlProperties                   = 1,
        	ESenTransportProperties             = 2,
        	ESenHttpTransportProperties         = 3,    
            ESenVtcpTransportProperties         = 4,    
        	ESenLayeredXmlProperties            = 5,
        	ESenLayeredTransportProperties      = 6,
        	ESenLayeredHttpTransportProperties  = 7,
        	ESenLayeredVtcpTransportProperties  = 8
        	};

        /**
        *  Sets the XML reader to be used for parsing.
        *  @param aReader:     the reader to be used. 
        *                      Ownership is NOT transferred.
        */
        virtual void SetReader(CSenXmlReader& aReader) = 0;
             
        /**
        * Get an integer identifying properties class type.
        * All subclasses MUST return use unique integer value.
        * @return unique TInt identifying this properties class type
        */
        virtual TSenPropertiesClassType PropertiesClassType() = 0;

        /**
        * Writes this properties object as descriptor into a stream.
        * UTF-8 charset encoding will be used.
        * @since Series60
        * @param aWriteStream The stream to write to.
        */
        virtual void WriteToL(RWriteStream& aWriteStream) = 0;

        /**
        * Reads this properties object from the descriptor.
        * UTF-8 charset encoding should be used.
        * @since Series60
        * @param aBuffer The buffer to read from.
        */
        virtual void ReadFromL(const TDesC8& aBuffer) = 0;

        /**
        * Get these properties as UTF-8 charset encoded descriptor.
        * @since Series60
        * @return a pointer to UTF-8 encoded descriptor.
        * Caller takes ownership.
        */
        virtual HBufC8* AsUtf8L() = 0;

        /**
        * Get these properties as UTF-8 charset encoded descriptor.
        * @since Series60
        * @return a pointer to UTF-8 encoded descriptor, which is
        * has been left on cleanup stack.
        * Caller takes ownership.
        */
        virtual HBufC8* AsUtf8LC() = 0;
        
        /**
        * Sets new property. 
        *
        * If property with given name does not exist, 
        * new property with given value will be added. Otherwise the value of 
        * existing property will be updated.
        *
        * @since Series60
        * @param aName         Name of the property, which can be later used to
        *                      refer the given value.
        * @param aValue        Is the value of this property.
        * @return              KErrNone if no error, or some of the system wide
        *                      error codes.
        * Leave codes:
        *                      According to implementing classes. 
        */
        virtual TInt SetPropertyL(const TDesC8& aName,
                                  const TDesC8& aValue) = 0;
        
        /**
        * Gets the value of the property behind certain name.
        * @since Series60
        * @param aName    The name identifying this property.
        * @param aValue   The value of the property, or KNullDesC8 if
        *                 property is not found.
        * @return KErrNone on success, KErrSenOmitted if property
        * has been omitted, or some of the system-wide error codes
        * otherwise.                  
        */
        virtual TInt PropertyL(const TDesC8& aName, TPtrC8& aValue) = 0;
        
        /**
        * Sets new integer property.
        *
        * If property with given name does not exist, 
        * new property with given value will be added. Otherwise the value of
        * existing property will be updated.
        *
        * @since Series60
        * @param aName         Name of the property, which can be later used
        *                      to refer the given value.
        * @param aValue        Is the integer value of this property.
        * @return              KErrNone if no error, or some of the system wide
        *                      error codes.
        * Leave codes:
        *                      According to implementing classes. 
        */
        virtual TInt SetIntPropertyL(const TDesC8& aName,
                                     const TInt aValue) = 0;
        
        /**
        * Gets the integer value of the property behind certain name.
        * @since Series60
        * @param aName    The name identifying this property.
        * @param aValue   A TInt reference to be filled in with the value of
        *                 the property.
        * @return KErrNone on success, KErrSenOmitted if property
        * has been omitted, or some of the system-wide error codes
        * otherwise.                  
        */
        virtual TInt IntPropertyL(const TDesC8& aName,
                                  TInt& aValue) = 0;
        
        /**
        * Sets new boolean property.
        *
        * If property with given name does not exist, 
        * new property with given value will be added. Otherwise the value of
        * existing property will be updated.
        *
        * @since Series60
        * @param aName         Name of the property, which can be later used
        *                      to refer the given value.
        * @param aValue        The boolean value of this property.
        * @return              KErrNone if no error, or some of the system wide
        *                      error codes.
        * Leave codes:
        *                      According to implementing classes. 
        */
        virtual TInt SetBoolPropertyL(const TDesC8& aName,
                                      const TBool aValue) = 0;
        
        /**
        * Gets the boolean value of the property behind certain name.
        * @since Series60
        * @param aName    The name identifying this property.
        * @param aValue   A TBool reference to be filled in with the value of
        *                 the property.
        * @return KErrNone on success, KErrSenOmitted if property
        * has been omitted, or some of the system-wide error codes
        * otherwise.                  
        */
        virtual TInt BoolPropertyL(const TDesC8& aName,
                                   TBool& aValue) = 0;
                                   
        /**
        * Method creates exact copy of the properties, preserving
        * the real, concrete subclass type (this can be resolved
        * via PropertiesClassType() method. Furthermore, the
        * IsSafeToCast() method can be used to reflect the returned
        * pointer to a concrete class. NOTE: one must cast the
        * returned pointer to concrete class in order to safely
        * de-allocate any memory allocated by this method.
        * @param aOkOrError is KErrNone when clone is successfully
        * allocated, or some system-wide error otherwise.
        * @return pointer to *concrete* properties object, which
        * MUST be class cast to known subclass(!).
        */                                   
		virtual MSenProperties* Clone(TInt& aOkOrError) const = 0;

        /**
        * Method provies reflection support for properties classes,
        * enabling safe class-casts to concrete subclass objects.
        * @return ETrue, if object is of a known subclass type
        *         EFalse, if the object cannot be cast to given type.
        */
        virtual TBool IsSafeToCast(TSenPropertiesClassType aClass) = 0;
        
        /**
        * Method creates exact copy of the properties, preserving
        * the real, concrete subclass type (this can be resolved
        * via PropertiesClassType() method. Furthermore, the
        * IsSafeToCast() method can be used to reflect the returned
        * pointer to a concrete class. NOTE: one must cast the
        * returned pointer to concrete class in order to safely
        * de-allocate any memory allocated by this method.
        * @return pointer to *concrete* properties object, which
        * MUST be class cast to known subclass(!).
        */                                   
        virtual MSenProperties* CloneL() const = 0;
    };

#endif // M_SEN_PROPERTIES_H
