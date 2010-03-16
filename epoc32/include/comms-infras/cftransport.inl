// Copyright (c) 2005-2009 Nokia Corporation and/or its subsidiary(-ies).
// All rights reserved.
// This component and the accompanying materials are made available
// under the terms of the License "Symbian Foundation License v1.0" to Symbian Foundation members and "Symbian Foundation End User License Agreement v1.0" to non-members
// which accompanies this distribution, and is available
// at the URL "http://www.symbianfoundation.org/legal/licencesv10.html".
//
// Initial Contributors:
// Nokia Corporation - initial contribution.
//
// Contributors:
//
// Description:
// cftransport.inl
// 
//

inline TCookie::TCookie()
: iType(ENull),
  iChipsFollowing(0)
	{
	}

// Cookies are not constructed arbitarily, instead having been generated they are bitwise copied. Consequently we don't trouble to
// provide clever comparison operators or a copy operation, nor to ensure consistent initialisation of padding fields
inline TBool TCookie::operator==(const TCookie& aRHS) const
	{
	ASSERT(iChipsFollowing==0 && aRHS.iChipsFollowing==0); //This is private (transport's use) information which must not be set here.
	return Mem::Compare((const TUint8*) this, sizeof(*this), (const TUint8*) &aRHS, sizeof(*this)) == 0;
	}

inline TCookieAccessor::TCookieAccessor(const TCookie& aCookie)
: iCookie(aCookie)
	{
	}

inline TBool TCookieAccessor::IsNull() const 
	{
	return iCookie.iType == TCookie::ENull;
	}

inline TCookie::TVariety TCookieAccessor::Variety() const 
	{
	return static_cast<TCookie::TVariety>(iCookie.iType);
	}

inline TWorkerId TCookieAccessor::WorkerId() const
	{
	return static_cast<TWorkerId>(iCookie.iWorkerId);
	}

inline TAny* TCookieAccessor::Ptr() const
	{
	return iCookie.iUn.iObjPtr.iPtr;
	}

inline TUint8 TCookieAccessor::PtrSalt() const
	{
	ASSERT(Variety() == TCookie::EDispatchItfPtr || Variety() == TCookie::EDispatchItfPtrListener);
	return iCookie.iSalt;
	}

inline TInt TCookieAccessor::LegacyCode() const
	{
	ASSERT(Variety() == TCookie::ELegacyId);
	return iCookie.iUn.iLegacyCode;
	}


inline TCookieOp::TCookieOp(TCookie& aCookie)
: TCookieAccessor(aCookie),
iCookie(aCookie)
	{
	}

/** Initialise cookie with a pointer to an object interface
*/
inline void TCookieOp::SetInterface(TAny* aDispatchItf, TUint8 aSalt, TWorkerId aWorkerId)
	{
	iCookie.iType = TCookie::EDispatchItfPtr;
	ASSERT(aWorkerId >= 0 && aWorkerId <= 255);
	iCookie.iWorkerId = (TUint8) aWorkerId;
	iCookie.iSalt = aSalt;
	iCookie.iUn.iObjPtr.iPtr = aDispatchItf;
	}

/** Initialise pseudo-cookie for a legacy message message handler
*/
inline void TCookieOp::SetLegacyMessageCode(TWorkerId aWorkerId, TInt aLegacyCode)
	{
	iCookie.iType = TCookie::ELegacyId;
	ASSERT(aWorkerId >= 0 && aWorkerId <= 255);
	iCookie.iWorkerId = (TUint8) aWorkerId;
	iCookie.iUn.iLegacyCode = aLegacyCode;
	}

inline void TCookieOp::SetNull()
	{
	iCookie.iType = TCookie::ENull;
	iCookie.iUn.iObjPtr.iPtr = NULL;	// unnecessary really, but safety net against those who don't validate type
	}

inline TCFMessage2::TCFMessage2()
	{
	}

inline TCFMessage2::TCFMessage2(const TCookie& aCookie, const TDesC8& aData)
	{
	reinterpret_cast<TCookie&>(*RawBlock()) = aCookie;
	__ASSERT_ALWAYS(aData.Size() <= sizeof(*this) - sizeof(TCookie), User::Panic(KCFChannelPanic, ECFChanMsgTooBig));
	TPtr8(const_cast<TUint8*>(RawBlock()) + sizeof(TCookie), sizeof(*this) - sizeof(TCookie)).Copy(aData);
	}

inline const TCookie& TCFMessage2::Cookie() const
	{
	return reinterpret_cast<const TCookie&>(*RawBlock());
	}

inline TPtrC8 TCFMessage2::Data() const
	{
	return TPtrC8(RawBlock() + sizeof(TCookie), sizeof(*this) - sizeof(TCookie));
	}
/*
inline TInt TCFMessage2::MaxEmbeddedMessageSize()
	{
	return MaxRawBlockSize() - sizeof(TCookie);
	}
*/
inline THeapStoredMessage* THeapStoredMessage::New(RAllocator& aHeap, const TCookie& aCookie, const TDesC8& aData)
	{
	THeapStoredMessage* self = reinterpret_cast<THeapStoredMessage*>(aHeap.Alloc(
		sizeof(THeapStoredMessage) + aData.Length() - 1));	// 1 being the sizeof(iSerialiseData); can't ref directly (CW issue)
	if(self)
		{
		self->iCookie = aCookie;
		self->iData.Set(self->iSerialisedData, aData.Length());
		Mem::Copy(self->iSerialisedData, aData.Ptr(), aData.Length());
		}
	return self;		
	}

inline const TCookie& THeapStoredMessage::Cookie() const
	{
	return iCookie;
	}

inline const TPtrC8& THeapStoredMessage::Data() const
	{
	return iData;
	}



//
// Thread knowledge
//

inline TBool TWorkerThreadDataBase::IsValid() const
	{
	return iHeap != 0;
	}

inline CWorkerThreadDataGlobalsBase::CWorkerThreadDataGlobalsBase()
	{
	}

inline CWorkerThreadDataGlobalsBase::~CWorkerThreadDataGlobalsBase()
	{
	User::Free(iWorkers);
	}

inline void CWorkerThreadDataGlobalsBase::ConstructL(TInt aWorkerDataSize, TInt TUpperThreadIdBound)
	{
	iWorkers = reinterpret_cast<TWorkerThreadDataBase*>(User::AllocZL(aWorkerDataSize * (TUpperThreadIdBound + 1)));
	}

template<class TWTD, TInt TUpperThreadIdBound>
inline CWorkerThreadDataGlobals<TWTD, TUpperThreadIdBound>* CWorkerThreadDataGlobals<TWTD, TUpperThreadIdBound>::NewL()
	{
	CWorkerThreadDataGlobals* self = new(ELeave) CWorkerThreadDataGlobals();
	CleanupStack::PushL(self);
	self->ConstructL(sizeof(TWTD), TUpperThreadIdBound);
	CleanupStack::Pop(self);
	return self;
	}

template<class TWTD, TInt TUpperThreadIdBound>
inline void CWorkerThreadDataGlobals<TWTD, TUpperThreadIdBound>::ConstructL(TInt aWorkerDataSize, TWorkerId aUpperBoundId)
	{
	CWorkerThreadDataGlobalsBase::ConstructL(aWorkerDataSize, aUpperBoundId);
	for(TInt i = 0; i <= TUpperThreadIdBound; ++i)
		{
		new(reinterpret_cast<TUint8*>(iWorkers) + i * aWorkerDataSize) TWTD;
		}
	}

template<class TWTD, TInt TUpperThreadIdBound>
inline TWorkerId CWorkerThreadDataGlobals<TWTD, TUpperThreadIdBound>::UpperBoundWorkerId() const
	{
	return TUpperThreadIdBound;
	}

template<class TWTD, TInt TUpperThreadIdBound>
inline TWTD* CWorkerThreadDataGlobals<TWTD, TUpperThreadIdBound>::GetWorkerGlobals(TWorkerId aWorker) const
	{
	__ASSERT_DEBUG(aWorker >= 0 && aWorker <= UpperBoundWorkerId(), Panic(ECFTransInvalidWorkerId));
	return reinterpret_cast<TWTD*>(reinterpret_cast<TUint8*>(iWorkers) + sizeof(TWTD) * aWorker);
	}

template<class TWTD, TInt TUpperThreadIdBound>
inline TBool CWorkerThreadDataGlobals<TWTD, TUpperThreadIdBound>::WorkerPresent(TWorkerId aId) const
	{
	return GetWorkerGlobals(aId)->IsValid();
	}

template<class TWTD, TInt TUpperThreadIdBound>
inline RAllocator& CWorkerThreadDataGlobals<TWTD, TUpperThreadIdBound>::WorkerHeap(TWorkerId aWorkerId) const
	{
	return *(GetWorkerGlobals(aWorkerId)->iHeap);
	}

template<class TWTD, TInt TUpperThreadIdBound>
inline void CWorkerThreadDataGlobals<TWTD, TUpperThreadIdBound>::PanicWorker(TWorkerId aWorkerId, const TDesC& aCategory, TInt aReason) const
	{
	GetWorkerGlobals(aWorkerId)->iThread.Panic(aCategory, aReason);
	}

template<class TWTD, TInt TUpperThreadIdBound>
inline CWorkerThreadDataGlobals<TWTD, TUpperThreadIdBound>::CWorkerThreadDataGlobals()
: CWorkerThreadDataGlobalsBase()
	{
	}

template<class TWTD, TInt TUpperThreadIdBound>
inline CWorkerThreadRegister<TWTD, TUpperThreadIdBound>* CWorkerThreadRegister<TWTD, TUpperThreadIdBound>::NewL(TWorkerId aSelfId, CWorkerThreadDataGlobals<TWTD, TUpperThreadIdBound>* aGlobalThreadRegister)
	{
	return new(ELeave) CWorkerThreadRegister(aSelfId, aGlobalThreadRegister);
	}

template<class TWTD, TInt TUpperThreadIdBound>
inline TWTD* CWorkerThreadRegister<TWTD, TUpperThreadIdBound>::GetWorkerGlobals(TWorkerId aWorker) const
	{
	__ASSERT_DEBUG(iGlobals != NULL, Panic(ECFTransThreadRegisterUnspecified));
	__ASSERT_DEBUG(aWorker >= 0 && aWorker <= TUpperThreadIdBound, Panic(ECFTransInvalidWorkerId));
	return iGlobals->GetWorkerGlobals(aWorker);
	}

template<class TWTD, TInt TUpperThreadIdBound>
inline TWorkerId CWorkerThreadRegister<TWTD, TUpperThreadIdBound>::UpperBoundWorkerId() const
	{
	return TUpperThreadIdBound;
	}

template<class TWTD, TInt TUpperThreadIdBound>
inline TBool CWorkerThreadRegister<TWTD, TUpperThreadIdBound>::WorkerPresent(TWorkerId aWorker) const
	{
	__ASSERT_DEBUG(iGlobals != NULL, Panic(ECFTransThreadRegisterUnspecified));
	__ASSERT_DEBUG(aWorker >= 0 && aWorker <= TUpperThreadIdBound, Panic(ECFTransInvalidWorkerId));
	return iGlobals->WorkerPresent(aWorker);
	}

template<class TWTD, TInt TUpperThreadIdBound>
inline RAllocator& CWorkerThreadRegister<TWTD, TUpperThreadIdBound>::WorkerHeap(TWorkerId aWorker) const
	{
	__ASSERT_DEBUG(iGlobals != NULL, Panic(ECFTransThreadRegisterUnspecified));
	__ASSERT_DEBUG(aWorker >= 0 && aWorker <= TUpperThreadIdBound, Panic(ECFTransInvalidWorkerId));
	return iGlobals->WorkerHeap(aWorker);
	}

template<class TWTD, TInt TUpperThreadIdBound>
inline void CWorkerThreadRegister<TWTD, TUpperThreadIdBound>::PanicWorker(TWorkerId aWorkerId, const TDesC& aCategory, TInt aReason) const
	{
	GetWorkerGlobals(aWorkerId)->iThread.Panic(aCategory, aReason);
	}

template<class TWTD, TInt TUpperThreadIdBound>
inline TWorkerId CWorkerThreadRegister<TWTD, TUpperThreadIdBound>::SelfWorkerId() const
	{
	return iSelfId;
	}

template<class TWTD, TInt TUpperThreadIdBound>
inline TWTD* CWorkerThreadRegister<TWTD, TUpperThreadIdBound>::GetSelfWorkerGlobals() const
	{
	__ASSERT_DEBUG(iGlobals != NULL, Panic(ECFTransThreadRegisterUnspecified));
	return iGlobals->GetWorkerGlobals(iSelfId);
	}

template<class TWTD, TInt TUpperThreadIdBound>
inline void CWorkerThreadRegister<TWTD, TUpperThreadIdBound>::SetGlobalThreadRegister(CWorkerThreadDataGlobals<TWTD, TUpperThreadIdBound>* aGlobalThreadRegister)
	{
	iGlobals = aGlobalThreadRegister;
	}

template<class TWTD, TInt TUpperThreadIdBound>
inline CWorkerThreadRegister<TWTD, TUpperThreadIdBound>::CWorkerThreadRegister(TWorkerId aSelfId, CWorkerThreadDataGlobals<TWTD, TUpperThreadIdBound>* aGlobalThreadRegister)
: iSelfId(aSelfId),
iGlobals(aGlobalThreadRegister)
	{
	}

inline TBool RCFInterfaceBase::IsOpen() const
	{
	return !TCookieAccessor(iRecipient).IsNull();
	}
