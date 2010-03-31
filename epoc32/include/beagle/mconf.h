// Copyright (c) 1998-2009 Nokia Corporation and/or its subsidiary(-ies).
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
// template\template_variant\inc\mconf.h
// Template Persistent Machine Configuration
// 
//



#ifndef __MCONF_H__
#define __MCONF_H__
#include <kernel.h>

class TDigitizerCalibrateValues
    {
public:
    TInt iR11;
    TInt iR12;
    TInt iR21;
    TInt iR22;
    TInt iTx;
    TInt iTy;
    };

class TTemplateMachineConfig : public TMachineConfig
	{
public:
	TSoundInfoV1 iSoundInfo;
    TOnOffInfoV1 iOnOffInfo;
	TTimeK iMainBatteryInsertionTime;
    Int64 iMainBatteryInUseMicroSeconds;
	Int64 iExternalPowerInUseMicroSeconds;
	Int64 iMainBatteryMilliAmpTicks;
	TDigitizerCalibrateValues iCalibration;
	TDigitizerCalibrateValues iCalibrationSaved;
	TDigitizerCalibrateValues iCalibrationFactory;
	};

typedef TTemplateMachineConfig TActualMachineConfig;

inline TActualMachineConfig& TheActualMachineConfig()
	{return (TActualMachineConfig&)Kern::MachineConfig();}

#endif
