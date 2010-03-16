// Copyright (c) 1995-2009 Nokia Corporation and/or its subsidiary(-ies).
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
// e32\include\d32comm.h
// 
//

//#define _DEBUG_DEVCOMM

/**
@file
@publishedPartner
@released
*/

#ifndef __D32COMM_H__
#define __D32COMM_H__
#include <e32cmn.h>
#include <e32ver.h>

/**
 Enumeration of number of data bits for serial port configuration.
 Typically, these values are used to initialize the iDataBits of 
 TCommConfigV01 before calling DComm::Configure() or any other serial
 comm API to configure the serial port's databits size.
 */
enum TDataBits {EData5,EData6,EData7,EData8};
/**
 Enumeration of number of stop bits for serial port configuration.
 Typically, these values are used to initialize the iStopBits of 
 TCommConfigV01 before calling DComm::Configure() or any other serial
 comm API to configure the serial port's stopbits.
 */
enum TStopBits {EStop1,EStop2};
/**
 Enumeration of types of parity for serial port configuration.
 Typically, these values are used to initialize the iParity of 
 TCommConfigV01 before calling DComm::Configure() or any other serial
 comm API to configure the serial port's parity setting.
 */
enum TParity {EParityNone,EParityEven,EParityOdd,EParityMark,EParitySpace};
/**
 Enumeration of baud rates in bits per second for serial port configuration.
 * e.g EBps115200 is for 115200Bps data rate  
 Typically, these values are used to initialize the iRate of TCommConfigV01 
 before calling DComm::Configure() or any other serial comm API to configure
 the serial port's baud rate.
 */
enum TBps
	{
	EBps50,
	EBps75,
	EBps110,
	EBps134,
	EBps150,
	EBps300,
	EBps600,
	EBps1200,
	EBps1800,
	EBps2000,
	EBps2400,
	EBps3600,
	EBps4800,
	EBps7200,
	EBps9600,
	EBps19200,
	EBps38400,
	EBps57600,
	EBps115200,
	EBps230400,
	EBps460800,
	EBps576000,
	EBps1152000,
	EBps4000000,
	EBps921600,
	EBpsAutobaud=0x40000000,
	EBpsSpecial=0x80000000,
	};
/**
 Enumeration of Fifo status (enable and disable) for serial port configuration.
 Typically, these values are used to initialize the iFifo of TCommConfigV01 
 before calling DComm::Configure() or any other serial comm API to configure
 the serial port's fifo.
 */
enum TFifo
	{
	EFifoEnable,EFifoDisable,
	};
/**
 Enumeration of SIR status (enable and disable) for serial comm configuration.
 Typically, these values are used to initialize the iSIREnable of TCommConfigV01 
 before calling DComm::Configure() or any other serial comm API to configure
 the serial port's SIR (infrared) settings.
 */
enum TSir 
	{
	ESIREnable,ESIRDisable,
	};

enum TFlowControl
	{
	EFlowControlOn,EFlowControlOff
	};
//

const TInt KConfigMaxTerminators=4;
// DTE Constants
const TUint KConfigObeyXoff=0x01;
const TUint KConfigSendXoff=0x02;
const TUint KConfigObeyCTS=0x04;
const TUint KConfigFailCTS=0x08;
const TUint KConfigObeyDSR=0x10;
const TUint KConfigFailDSR=0x20;
const TUint KConfigObeyDCD=0x40;
const TUint KConfigFailDCD=0x80;
const TUint KConfigFreeRTS=0x100;
const TUint KConfigFreeDTR=0x200;
// DCE Constants
const TUint KConfigObeyDTR=0x400;
const TUint KConfigFailDTR=0x800;
const TUint KConfigObeyRTS=0x1000;
const TUint KConfigFailRTS=0x2000;
const TUint KConfigFreeDSR=0x4000;
const TUint KConfigFreeCTS=0x8000;
const TUint KConfigFreeDCD=0x10000;
const TUint KConfigFreeRI=0x20000;
const TUint KConfigWriteBufferedComplete=0x80000000;
//
const TUint KConfigParityErrorFail=0;
const TUint KConfigParityErrorIgnore=0x01;
const TUint KConfigParityErrorReplaceChar=0x02;
const TUint KConfigXonXoffDebug=0x80000000;
//
const TUint KSignalCTS=0x01;
const TUint KSignalDSR=0x02;
const TUint KSignalDCD=0x04;
const TUint KSignalRNG=0x08;
const TUint KSignalRTS=0x10; 
const TUint KSignalDTR=0x20;
const TUint KSignalBreak=0x40;

const TUint KSignalChanged=0x1000;
const TUint KCTSChanged=KSignalCTS*KSignalChanged;
const TUint KDSRChanged=KSignalDSR*KSignalChanged;
const TUint KDCDChanged=KSignalDCD*KSignalChanged;
const TUint KRNGChanged=KSignalRNG*KSignalChanged;
const TUint KRTSChanged=KSignalRTS*KSignalChanged;
const TUint KDTRChanged=KSignalDTR*KSignalChanged;
const TUint KBreakChanged=KSignalBreak*KSignalChanged;

const TUint KSignalDTEOutputs=KSignalRTS|KSignalDTR;
const TUint KSignalDTEInputs=KSignalCTS|KSignalDSR|KSignalDCD|KSignalRNG;
const TUint KSignalDCEInputs=KSignalDTEOutputs;
const TUint KSignalDCEOutputs=KSignalDTEInputs;

const TUint KConfigSIRPulseWidthMaximum=0x01;
const TUint KConfigSIRPulseWidthMinimum=0x02;

// more SIRSettings for selecting the IR range
const TUint KConfigSIRShutDown=0x10;
const TUint KConfigSIRMinimumRange=0x20;
const TUint KConfigSIRMediumRange=0x40;
const TUint KConfigSIRMaximumRange=0x80;

/**
 Comms configuration structure.
 Class to hold the configuration settings for serial comm port
 
 This class provides the serial port configuration block interface of serial comms (c32).
 A serial comm client sets up a serial port before use, by providing a configuration block. 
 TCommConfigV01 is initialized with settings for serial port and used to configure the 
 serial port by calling DComm::Configure(TCommConfigV01 &aConfig) or any other serial comm 
 API to configure the serial port.
 */
class TCommConfigV01
    {
public:
	/** 
	 Data rate in bits per second.
	 @see TBps 	
	 */
	TBps iRate;
	/** 
	 Character width in bits.
	 @see TDataBits
	 */	
	TDataBits iDataBits;
	/**
	 Number of stop bits.
	 @see TStopBits
	 */
	TStopBits iStopBits;
	/**
	 Type of parity.
	 @see TParity 
	 */
	TParity iParity;
	/**
	 Type of Handshaking control.
	 Possible values can be KConfigObeyXXX or KConfigSendXXX or KConfigFailXXX or KConfigFreeXXX
	 */
	TUint iHandshake;
	/**
	 Type of error to generate on a parity failure.
	 Possible values can be KConfigParityErrorFail or KConfigParityErrorIgnore or KConfigParityErrorReplaceChar
	 */
	TUint iParityError;
	/**
	 FIFO status, enabled or disabled.
	 @see TFifo 
	 */
	TUint iFifo;
	/**
	 Special data rate, not listed under TBps. Use this, when iRate is set to EBpsSpecial 
	 */
	TInt iSpecialRate;
	/**
	 Count of number of special characters used as terminators (<=KConfigMaxTerminators) 
	 */				
	TInt iTerminatorCount;
	/**
	 Array of special characters which can be used as terminators 
	 */
	TText8 iTerminator[KConfigMaxTerminators];
	/**
	 Character used to signal the transmitter to resume sending when using XON/XOFF handshaking
	 i.e character used as XON - software flow control
	 */
	TText8 iXonChar;
	/**
	 Character used to signal the transmitter to suspend sending when using XON/XOFF handshaking
	 i.e character used as XOFF - software flow control
	 */
	TText8 iXoffChar;
	/**
	 Character used to replace the characters received with a parity error.
	 This is used when iParityError is set to KConfigParityErrorReplaceChar 
	 */	
	TText8 iParityErrorChar;
	/**
	 Switch the SIR encoding hardware on and off.
	 @see TSir
	 */
	TSir iSIREnable;
	/**
	 SIR hardware control setting. Possible value can be one of KConfigSIRXXX
	 */
	TUint iSIRSettings;
	};
/** 
 Package buffer for a TCommConfigV01 object.
 
 TCommConfig packages the comms configuration structure TCommConfigV01 to a buffer. 
 This is used with API of serial comms like RComm::Config(TDes8 &aConfig) and 
 RComm::SetConfig(TDesC8 &aConfig) where config structure is passed as buffer.
 
 @see TCommConfigV01
 */		
typedef TPckgBuf<TCommConfigV01> TCommConfig;

// TCommConfigV02 is deprecated.
//
class TCommConfigV02: public TCommConfigV01
	{
public:		
	TInt iTxShutdownTimeout;
	};

// TCommConfig2 is deprecated
// 
typedef TPckgBuf<TCommConfigV02> TCommConfig2;

//
const TUint KCapsBps50=0x00000001;
const TUint KCapsBps75=0x00000002;
const TUint KCapsBps110=0x00000004;
const TUint KCapsBps134=0x00000008;
const TUint KCapsBps150=0x00000010;
const TUint KCapsBps300=0x00000020;
const TUint KCapsBps600=0x00000040;
const TUint KCapsBps1200=0x00000080;
const TUint KCapsBps1800=0x00000100;
const TUint KCapsBps2000=0x00000200;
const TUint KCapsBps2400=0x00000400;
const TUint KCapsBps3600=0x00000800;
const TUint KCapsBps4800=0x00001000;
const TUint KCapsBps7200=0x00002000;
const TUint KCapsBps9600=0x00004000;
const TUint KCapsBps19200=0x00008000;
const TUint KCapsBps38400=0x00010000;
const TUint KCapsBps57600=0x00020000;
const TUint KCapsBps115200=0x00040000;
const TUint KCapsBps230400=0x00080000;
const TUint KCapsBps460800=0x00100000;
const TUint KCapsBps576000 =0x00200000;
const TUint KCapsBps1152000=0x00400000;
const TUint KCapsBps4000000=0x00800000;
const TUint KCapsBps921600=0x01000000;
const TUint KCapsBpsAutobaud=0x40000000;
const TUint KCapsBpsSpecial=0x80000000;
//
const TUint KCapsData5=0x01;
const TUint KCapsData6=0x02;
const TUint KCapsData7=0x04;
const TUint KCapsData8=0x08;
//
const TUint KCapsStop1=0x01;
const TUint KCapsStop2=0x02;
//
const TUint KCapsParityNone=0x01;
const TUint KCapsParityEven=0x02;
const TUint KCapsParityOdd=0x04;
const TUint KCapsParityMark=0x08;
const TUint KCapsParitySpace=0x10;
//
const TUint KCapsSignalCTSSupported=0x01;
const TUint KCapsSignalDSRSupported=0x02;
const TUint KCapsSignalDCDSupported=0x04;
const TUint KCapsSignalRNGSupported=0x08;
const TUint KCapsSignalRTSSupported=0x10;
const TUint KCapsSignalDTRSupported=0x20;
//
const TUint KCapsObeyXoffSupported=0x01;
const TUint KCapsSendXoffSupported=0x02;
const TUint KCapsObeyCTSSupported=0x04;
const TUint KCapsFailCTSSupported=0x08;
const TUint KCapsObeyDSRSupported=0x10;
const TUint KCapsFailDSRSupported=0x20;
const TUint KCapsObeyDCDSupported=0x40;
const TUint KCapsFailDCDSupported=0x80;
const TUint KCapsFreeRTSSupported=0x100;
const TUint KCapsFreeDTRSupported=0x200;
// DCE Constants
const TUint KCapsObeyRTSSupported=0x400;
const TUint KCapsObeyDTRSupported=0x800;
//
const TUint KCapsHasFifo=0x01;
//
const TUint KCapsSIR115kbps=0x01;
const TUint KCapsSIR2400bpsOnly=0x02;
const TUint KCapsSIR4Mbs=0x04;
//
const TUint KNotifySignalsChangeSupported=0x01;
const TUint KNotifyRateChangeSupported=0x02;
const TUint KNotifyDataFormatChangeSupported=0x04;
const TUint KNotifyHandshakeChangeSupported=0x08;
const TUint KNotifyBreakSupported=0x10;
const TUint KNotifyFlowControlChangeSupported=0x20;
const TUint KNotifyDataAvailableSupported=0x40;
const TUint KNotifyOutputEmptySupported=0x80;
//
const TUint KCapsRoleSwitchSupported=0x01;
//
const TUint KCapsFlowControlStatusSupported=0x01;
//
const TUint KRateChanged=0x01;
const TUint KDataFormatChanged=0x02;
const TUint KHandshakeChanged=0x04;
//
class TCommCapsV01
	{
public:
	TUint iRate;
	TUint iDataBits;
	TUint iStopBits;
	TUint iParity;
	TUint iHandshake;
	TUint iSignals;
	TUint iFifo;
	TUint iSIR;
	};
typedef TPckgBuf<TCommCapsV01> TCommCaps;

class TCommCapsV02 : public TCommCapsV01
	{
public:
	TUint iNotificationCaps;
	TUint iRoleCaps;
	TUint iFlowControlCaps;
	};
typedef TPckgBuf<TCommCapsV02> TCommCaps2;

class TCommCapsV03 : public TCommCapsV02
	{
public:
	TBool iBreakSupported;
	};
typedef TPckgBuf<TCommCapsV03> TCommCaps3;

//
class TCapsDevCommV01
	{
public:
	TVersion version;
	};

class TCommNotificationV01
	{
public:
	TUint iChangedMembers;
	TBps iRate;
	TDataBits iDataBits;
	TStopBits iStopBits;
	TParity iParity;
	TUint iHandshake;
	};
typedef TPckgBuf<TCommNotificationV01> TCommNotificationPckg;
//
const TUint KDataAvailableNotifyFlag=0x80000000;
//
#ifdef _DEBUG_DEVCOMM
class TCommDebugInfo
	{
public:
	TBool iRxBusy;
	TBool iRxHeld;
	TInt iRxLength;
	TInt iRxOffset;
	TInt iRxIntCount;
	TInt iRxErrCount;
	TInt iRxBufCount;
	TBool iTxBusy;
	TBool iTxHeld;
	TInt iTxLength;
	TInt iTxOffset;
	TInt iTxIntCount;
	TInt iTxErrCount;
	TInt iTxBufCount;
	TBool iDrainingRxBuf;
	TBool iFillingTxBuf;
	TBool iRunningDfc;
	TInt iDfcCount;
	TInt iDfcReqSeq;
	TInt iDfcHandlerSeq;
	TInt iDoDrainSeq;
	TBool iTxDfcPend;
	TBool iRxDfcPend;
	TInt iTxChars, iRxChars;
	TInt iTxXon, iTxXoff, iRxXon, iRxXoff;
	};
typedef TPckgBuf<TCommDebugInfo> TCommDebugInfoPckg;
#endif
//
class RBusDevComm : public RBusLogicalChannel
	{
public:
	enum TVer {EMajorVersionNumber=1,EMinorVersionNumber=0,EBuildVersionNumber=KE32BuildVersionNumber};
	enum TRequest
		{
		ERequestRead=0x0,ERequestReadCancel=0x1,
		ERequestWrite=0x1,ERequestWriteCancel=0x2,
		ERequestBreak=0x2,ERequestBreakCancel=0x4,
		ERequestNotifySignalChange=0x3,ERequestNotifySignalChangeCancel=0x8,
		};
	enum TControl
		{
		EControlConfig,EControlSetConfig,EControlCaps,
		EControlSignals,EControlSetSignals,
		EControlQueryReceiveBuffer,EControlResetBuffers,
		EControlReceiveBufferLength,EControlSetReceiveBufferLength,
		EControlMinTurnaroundTime,EControlSetMinTurnaroundTime,
#ifdef _DEBUG_DEVCOMM
		EControlDebugInfo
#endif
		};
public:
#ifndef __KERNEL_MODE__
	inline TInt Open(TInt aUnit);
	inline TVersion VersionRequired() const;
	inline void Read(TRequestStatus &aStatus,TDes8 &aDes);
	inline void Read(TRequestStatus &aStatus,TDes8 &aDes,TInt aLength);
	inline void ReadOneOrMore(TRequestStatus &aStatus,TDes8 &aDes);
	inline void ReadCancel();
	inline void Write(TRequestStatus &aStatus,const TDesC8 &aDes);
	inline void Write(TRequestStatus &aStatus,const TDesC8 &aDes,TInt aLength);
	inline void WriteCancel();
	inline void Break(TRequestStatus &aStatus,TInt aTime);
	inline void BreakCancel();
	inline void Config(TDes8 &aConfig);
	inline TInt SetConfig(const TDesC8 &aConfig);
	inline void Caps(TDes8 &aCaps);
	inline TUint Signals();
	inline void SetSignals(TUint aSetMask,TUint aClearMask);
	inline TInt QueryReceiveBuffer();
	inline void ResetBuffers();
	inline TInt ReceiveBufferLength();
	inline TInt SetReceiveBufferLength(TInt aLength);
	inline void NotifySignalChange(TRequestStatus& aStatus,TUint& aSignals,TUint aSignalMask=0x3F);
	inline void NotifySignalChangeCancel();
	inline void NotifyReceiveDataAvailable(TRequestStatus& aStatus);
	inline void NotifyReceiveDataAvailableCancel();
	inline TUint MinTurnaroundTime();
	inline TInt SetMinTurnaroundTime(TUint aMicroSeconds);
#ifdef _DEBUG_DEVCOMM
	inline void DebugInfo(TDes8 &aInfo);
#endif
#endif
	};

class RBusDevCommDCE : public RBusLogicalChannel
	{
public:
	enum TVer {EMajorVersionNumber=1,EMinorVersionNumber=0,EBuildVersionNumber=KE32BuildVersionNumber};
	enum TRequest
		{
		ERequestRead=0x0,ERequestReadCancel=0x1,
		ERequestWrite=0x1,ERequestWriteCancel=0x2,
		ERequestBreak=0x2,ERequestBreakCancel=0x4,
		ERequestNotifySignalChange=0x3,ERequestNotifySignalChangeCancel=0x8,
		ERequestNotifyFlowControlChange=0x4,ERequestNotifyFlowControlChangeCancel=0x10,
		ERequestNotifyConfigChange=0x5,ERequestNotifyConfigChangeCancel=0x20
		};
	enum TControl
		{
		EControlConfig,EControlSetConfig,EControlCaps,
		EControlSignals,EControlSetSignals,
		EControlQueryReceiveBuffer,EControlResetBuffers,
		EControlReceiveBufferLength,EControlSetReceiveBufferLength,
		EControlFlowControlStatus,
#ifdef _DEBUG_DEVCOMM
		EControlDebugInfo
#endif
		};
public:
#ifndef __KERNEL_MODE__
	inline TInt Open(TInt aUnit);
	inline TVersion VersionRequired() const;
	inline void Read(TRequestStatus &aStatus,TDes8 &aDes);
	inline void Read(TRequestStatus &aStatus,TDes8 &aDes,TInt aLength);
	inline void ReadOneOrMore(TRequestStatus &aStatus,TDes8 &aDes);
	inline void ReadCancel();
	inline void Write(TRequestStatus &aStatus,const TDesC8 &aDes);
	inline void Write(TRequestStatus &aStatus,const TDesC8 &aDes,TInt aLength);
	inline void WriteCancel();
	inline void Break(TRequestStatus &aStatus,TInt aTime);
	inline void BreakCancel();
	inline void Config(TDes8 &aConfig);
	inline TInt SetConfig(const TDesC8 &aConfig);
	inline void Caps(TDes8 &aCaps);
	inline TUint Signals();
	inline void SetSignals(TUint aSetMask,TUint aClearMask);
	inline TInt QueryReceiveBuffer();
	inline void ResetBuffers();
	inline TInt ReceiveBufferLength();
	inline TInt SetReceiveBufferLength(TInt aLength);
	inline void NotifySignalChange(TRequestStatus& aStatus,TUint& aSignals,TUint aSignalMask=0x3F);
	inline void NotifySignalChangeCancel();
	inline void NotifyReceiveDataAvailable(TRequestStatus& aStatus);
	inline void NotifyReceiveDataAvailableCancel();
	inline void NotifyFlowControlChange(TRequestStatus& aStatus);
	inline void NotifyFlowControlChangeCancel();
	inline void GetFlowControlStatus(TFlowControl& aFlowControl);
	inline void NotifyConfigChange(TRequestStatus& aStatus, TDes8& aNewConfig);
	inline void NotifyConfigChangeCancel();
#ifdef _DEBUG_DEVCOMM
	inline void DebugInfo(TDes8 &aInfo);
#endif
#endif
	};

#include <d32comm.inl>
#endif
