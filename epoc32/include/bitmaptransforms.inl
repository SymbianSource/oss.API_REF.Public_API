// Copyright (c) 2002-2009 Nokia Corporation and/or its subsidiary(-ies).
// All rights reserved.
// This component and the accompanying materials are made available
// under the terms of "Eclipse Public License v1.0"
// which accompanies this distribution, and is available
// at the URL "http://www.eclipse.org/legal/epl-v10.html".
//
// Initial Contributors:
// Nokia Corporation - initial contribution.
//
// Contributors:
//
// Description:
//

#ifndef __BitmapTransforms_inl
#define __BitmapTransforms_inl

#include <bitmaptransforms.h>

const TUid KICLUidPostProcessCommand = { 0x101F7C18 };
const TUid KICLUidUseLowMemoryAlgorithmCommand = { 0x101F7C42 };
const TUid KICLUidSetQualityAlgorithmCommand = { 0x101F7C4C }; 


/**
@publishedAll

SetPostProcessing

@param 	aState
		a boolean flag which if true will set post processing on
		(Note by defualt the scaler has post processing on)

@released
*/
inline TInt CBitmapScaler::DisablePostProcessing( TBool aState )
	{
	return CustomCommand( KICLUidPostProcessCommand,&aState);
	}

/**
@publishedAll

UseLowMemory

@param 	aState
		a boolean flag which if true will enable the low memory algorithm
		(Note by defualt the scaler does not use the low memory algorithm)

@released
*/
inline TInt CBitmapScaler::UseLowMemoryAlgorithm( TBool aState )
	{
	return CustomCommand( KICLUidUseLowMemoryAlgorithmCommand, &aState);
	}

/**
@publishedAll

SetQualityAlgorithm

@param 	aQualityLevel
		an enumeration which sets the quality algorithm

@released
*/
inline TInt CBitmapScaler::SetQualityAlgorithm( TQualityAlgorithm aQualityLevel )
	{
	return CustomCommand( KICLUidSetQualityAlgorithmCommand, &aQualityLevel );
	}

#endif // __BitmapTransforms_inl
