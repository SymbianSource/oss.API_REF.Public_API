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
// e32\include\kernel\arm\vfpsupport.h
// 
//

#ifndef __VFPSUPPORT_H__
#define __VFPSUPPORT_H__

#include <e32def.h>

#define MAXVFPOPERATIONCOUNT 16
class TVFPComputationDescription
	{
public:
	TUint32 count;
	TUint32 flags;
	struct
		{
		TUint32 op;
		TUint32 op_dbg;
		} desc[MAXVFPOPERATIONCOUNT];
	};

extern TBool VFPIsComputeException(TUint32 instr);
extern TBool VFPCollectTrapDescription(TVFPComputationDescription& aDesc, TUint32 aInstr);
extern "C" void _VFP_Computation_Engine(TVFPComputationDescription& aDesc);
extern "C" void _vfp_fp_trap();

#endif
