/*
* Copyright (c) 2006-2009 Nokia Corporation and/or its subsidiary(-ies).
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
* Description:
* Name        : sipparameterheaderbase.h
* Part of     : SIP Codec
* Interface   : SDK API, SIP Codec API
* Version     : SIP/4.0
*
*/




#ifndef CSIPPARAMETERHEADERBASE_H
#define CSIPPARAMETERHEADERBASE_H

//  INCLUDES
#include "sipheaderbase.h"
#include "_sipcodecdefs.h"

// FORWARD DECLARATIONS
class CSIPParamContainerBase;

// CLASS DECLARATION
/**
* @publishedAll
* @released
*
* A base class for SIP headers that have structure
*        "mandatory part"delimiter"parameters"
*
* This is an abstract class and cannot be instantiated.
*
*  @lib sipcodec.lib
*/
class CSIPParameterHeaderBase : public CSIPHeaderBase
    {
    public:    // Constructors and destructor

        /**
        * Destructor, deletes the resources of CSIPParameterHeaderBase.
        */
        IMPORT_C virtual ~CSIPParameterHeaderBase();


    public: // New functions

        /**
        * Checks if a parameter is present
        * @param aName the name of the parameter
        * @return ETrue if present, otherwise EFalse
        */
        IMPORT_C TBool HasParam(RStringF aName) const;

        /**
        * Gets a parameter value
        * @pre HasParam(aName) == ETrue
        * @param aName the name of the parameter
        * @return the parameter value if present,
        *         otherwise a zero-length length value.
        */
        IMPORT_C RStringF ParamValue(RStringF aName) const;

        /**
        * Sets a parameter with a value. 
        * Takes copies of the name and value,
        * so if the RStringFs have been dynamically allocated,
        * they can be closed if necessary after the function returns.
        * @pre HasParam(aName) == EFalse
        * @param aName the name of the parameter
        * @param aValue the parameter value to set
        */
        IMPORT_C void SetParamL(RStringF aName, RStringF aValue);

        /**
        * Sets a parameter without a value
        * Takes copy of the name,
        * so if the RStringF has been dynamically allocated,
        * it can be closed if necessary after the function returns.
        * @pre HasParam(aName) == EFalse
        * @param aName the parameter name to set
        */
        IMPORT_C void SetParamL(RStringF aName);

        /**
        * Deletes a parameter
        * @param aName the parameter name to delete
        */
        IMPORT_C void DeleteParam(RStringF aName);

        /**
        * Gets the count of header parameters
        * @return count of header parameters
        */
        IMPORT_C TInt ParamCount() const;

        /**
        * Gets a header parameter name by index.
        * This function can be used when looping through
        * all the header parameters.
        * @param aIndex the index of the parameter
        * @param aName copy of the parameter name that must be 
        *        closed by the caller.       
        * @return KErrNotFound if aIndex is invalid. Otherwise EFalse.
        */
        IMPORT_C TInt Param(TInt aIndex, RStringF& aName) const;

    public: // From CSIPHeaderBase

        /**
        * From CSIPHeaderBase ToTextValueL
        */
        IMPORT_C HBufC8* ToTextValueL() const;


    protected: // Contructors

        CSIPParameterHeaderBase(const TChar& aSeparator);        

    protected: // New functions

        void ParseL(const TDesC8& aValue, 
        				  TBool aIgnoreParenthesis=ETrue, 
        				  TBool aSkipSeparatorsBeforeAt=EFalse);

    protected: // Virtual functions

        /**
        * @internalComponent
        */    
        virtual TBool ParamInsertionAllowed() const;

    protected: // Pure virtual functions

        /**
        * @internalComponent
        */
        virtual HBufC8* ToTextMandatoryPartLC() const = 0;
        
        /**
        * @internalComponent
        */        
        virtual void ParseMandatoryPartL(const TDesC8& aMandatoryPart) = 0;
        
        /**
        * @internalComponent
        */        
        virtual const CSIPParamContainerBase& Params() const = 0;
        
        /**
        * @internalComponent
        */        
        virtual CSIPParamContainerBase& Params() = 0;

    private: // Contructors

        CSIPParameterHeaderBase();

    private: // Data
    
        TChar iSeparator;

    private: // For testing purposes
    
        UNIT_TEST(CSIPParameterHeaderBaseTest)
    };

#endif // CSIPPARAMETERHEADERBASE_H

// End of File
