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
* Description: Pointermap class declaration        
*
*/

#ifndef POINTERMAP_H
#define POINTERMAP_H

// INCLUDES
#include <e32std.h>

// CLASS DECLARATION
template <typename K, typename V>
class RSenPointerMap
    {
    public: // Constructors and destructor
        
    RSenPointerMap(TBool aTakeOwnershipKey, TBool aTakeOwnershipValue)
        :
        iTakeOwnershipKey(aTakeOwnershipKey),
        iTakeOwnershipValue(aTakeOwnershipValue)
        {}

    ~RSenPointerMap()
        {
        Reset();
        }

        // New functions
        
    TInt Append(const K* aKey, const V* aValue)
        {
        TInt err = iKeys.Append(aKey);
        if (err == KErrNone)
            {
            err = iValues.Append(aValue);
            if (err != KErrNone)
                {
                // last element of iKeys should be removed
                TInt lastElementIndex = iKeys.Count() - 1;
                iKeys.Remove(lastElementIndex);
                }
            }
        return err;
        }

    TInt Find(const K& aKey) const
        {
        TInt index = KErrNotFound;
        for (int i = 0; i < iKeys.Count(); i++)
            {
            if (*iKeys[i] == aKey)
                {
                index = i;
                break;
                }
            }
        return index;
        }

    // @return the index of removed key-value pair, or
    // KErrNotFound, if such key was not found
    TInt RemoveByKey(const K& aKey)
        {
        TInt index = Find(aKey);
        if (index != KErrNotFound)
            {
            if(iTakeOwnershipKey)
                {
                K* key = KeyAt(index);
                delete key;
                }
            if(iTakeOwnershipValue)
                {
                V* value = iValues[index];
                delete value;
                }
            iKeys.Remove(index);
            iValues.Remove(index);
            }
        return index;
        }

    // @return the index of removed key-value pair, or
    // KErrNotFound, if such key was not found
    TInt Remove(const V& aValue)
        {
        TInt index = FindValue(aValue);
        if (index != KErrNotFound)
            {
            if (iTakeOwnershipValue)
                {
                V* value = iValues[index];
                delete value;
                }
            if (iTakeOwnershipKey)
                {
                K* key = iKeys[index];
                delete key;
                }
            iValues.Remove(index);
            iKeys.Remove(index);
            }
        return index; 
        }

    TInt FindValue(const V& aValue) const
        {
        TInt index = KErrNotFound;
        for (int i = 0; i < iValues.Count(); i++)
            {
            if ((iValues[i]) && (*iValues[i] == aValue))
                {
                index = i;
                break;
                }
            }
        return index;
        }


    // Note: deletes the current value of this key
    TInt UpdateValue(const K* aKey, const V* aValue)
        {
        TInt index=Find(*aKey);
        if (index==KErrNotFound)
            {
            return Append(aKey, aValue);
            }

        V* bValue=iValues[index];
        if (iTakeOwnershipValue)
            {
            // Since OWNED value is going to be replaced with aValue,
            // destroy old value instance first:
            delete bValue;  
            }

        iValues[index]=(V*)aValue;
        return KErrNone;
        }


    K* KeyAt(TInt aIndex)
        {
        return iKeys[aIndex];
        }

    const V* ValueAt(TInt aIndex) const
        {
        return iValues[aIndex];
        }

    TInt Count() const
        {
        return iKeys.Count();
        }

    void Reset()
        {
        if ( iTakeOwnershipKey )
            {
            iKeys.ResetAndDestroy();
            }
        else
            {
            iKeys.Reset();
            }

        if ( iTakeOwnershipValue )
            {
            iValues.ResetAndDestroy();
            }
        else
            {
            iValues.Reset();
            }
        }
        
    TInt Insert(const K* aKey, const V* aValue)
        {
        TInt count=iKeys.Count();
        TInt err=KErrNone;
		TBool inserted=EFalse;

        for(TInt i=0; i<count; i++)
        	{
        	 if(*iKeys[i] >= *aKey)
        	 {
	        err = iKeys.Insert(aKey, i);
	        if (err == KErrNone)
	            {
	            err = iValues.Insert(aValue, i);
	            if (err != KErrNone)
	                {
	                // inserted element of iKeys should be removed
	                iKeys.Remove(i);
	                }
				    else
					{
					inserted=ETrue;
					}
            	}
			break;  	 	
        	 }
			}

        if(!inserted)
        	{
	        err = iKeys.Append(aKey);
	        if (err == KErrNone)
	            {
	            err = iValues.Append(aValue);
	            if (err != KErrNone)
	                {
	                // last element of iKeys should be removed
	                TInt lastElementIndex = iKeys.Count() - 1;
	                iKeys.Remove(lastElementIndex);
	                }
            	}
        	}
	return err;
        }
        
    private: // Data
    TBool iTakeOwnershipKey;
    TBool iTakeOwnershipValue;
    RPointerArray<K> iKeys;
    RPointerArray<V> iValues;
    };

#endif // POINTERMAP_H

// End of File

