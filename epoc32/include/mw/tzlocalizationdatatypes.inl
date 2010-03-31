// Copyright (c) 2004-2009 Nokia Corporation and/or its subsidiary(-ies).
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

#ifndef __TZLOCAL_DATATYPES_INL__
#define __TZLOCAL_DATATYPES_INL__

//==================================================================
// TTzLocalizedId inline Functions
//==================================================================
/**
Returns the time zone ID.
@return The time zone ID.
*/
inline TUint16 TTzLocalizedId::TimeZoneId() const
	{
	return iTzId;
	}

/**
Returns the resource ID.
@return The resource ID.
*/
inline TUint TTzLocalizedId::ResourceId() const
	{
	return iResourceId;
	}

//==================================================================
// CTzLocalizedArray's inline functions
//==================================================================
/**
Destructor
@internalTechnology
*/
template <class T>
inline CTzLocalizedArray<T>::~CTzLocalizedArray()
	{
	iArray.ResetAndDestroy();
	}

/**
Default constructor
@internalTechnology
*/
template <class T>
inline CTzLocalizedArray<T>::CTzLocalizedArray()
	{
	}
/**
Returns the element at the specified index.
@param aIndex Index of the element to get.
@return The element at aIndex.
@internalTechnology
*/
template <class T>
inline T& CTzLocalizedArray<T>::At(TInt aIndex) const
	{
	return *(iArray[aIndex]);
	}

/**
Returns the number of elements in the array.
@return The number of elements in the array.
@internalTechnology
*/
template <class T>
inline TInt CTzLocalizedArray<T>::Count() const
	{
	return iArray.Count();
	}

/**
Appends aElement to this array.
@param aElement The element to add.
@internalTechnology
*/
template <class T>
inline void CTzLocalizedArray<T>::AppendL(T* aElement)
	{
	iArray.AppendL(aElement);
	}

/**
Removes the element at the specified index.
@param aIndex The index of the element to remove.
@internalTechnology
*/
template <class T>
inline void CTzLocalizedArray<T>::Remove(TInt aIndex)
	{
	iArray.Remove(aIndex);
	}

/**
Sorts this array.
@param aOrder The sorting function to use.
@internalTechnology
*/
template <class T>
inline void CTzLocalizedArray<T>::Sort(TLinearOrder<T> aOrder)
	{
	iArray.Sort(aOrder);
	}

/**
Finds an element in this array.
@param aIdentityRelation finding function to use.
@internalTechnology
*/
template <class T>
inline TInt CTzLocalizedArray<T>::Find(T* aEntry,TIdentityRelation<T> aIdentityRelation)
	{
	return iArray.Find(aEntry,aIdentityRelation);
	}

template <class T>
inline void CTzLocalizedArray<T>::ReserveL(TInt aCount)
	{
	iArray.ReserveL(aCount);
	}

#endif //__TZLOCAL_DATATYPES_INL__
