/*
* Copyright (c) 2003-2005 Nokia Corporation and/or its subsidiary(-ies).
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
* Description:     Inline function implementations of class TAiwGenericParam.
*
*/





inline TAiwGenericParam::TAiwGenericParam() :
    iSemanticId(EGenericParamUnspecified), iValue()
    {
    }

inline TAiwGenericParam::TAiwGenericParam(TGenericParamId aSemanticId) :
    iSemanticId(aSemanticId), iValue()
    {
    }

inline TAiwGenericParam::TAiwGenericParam(TGenericParamId aSemanticId, 
    const TAiwVariant& aValue) : 
    iSemanticId(aSemanticId), iValue(aValue)
    {
    }

inline void TAiwGenericParam::SetSemanticId(TGenericParamId aSemanticId)
    {
    iSemanticId = aSemanticId;
    }

inline TGenericParamId TAiwGenericParam::SemanticId() const
    {
    return iSemanticId;
    }

inline TAiwVariant& TAiwGenericParam::Value()
    {
    return iValue;
    }

inline const TAiwVariant& TAiwGenericParam::Value() const
    {
    return iValue;
    }

inline void TAiwGenericParam::Reset()
    {
    iSemanticId = EGenericParamUnspecified;
    iValue.Reset();
    }

inline TBool operator!=(const TAiwGenericParam& aLhs, 
    const TAiwGenericParam& aRhs)
    {
    return !(aLhs == aRhs);
    }

// End of file

