/*
* Copyright (c) 2006 Nokia Corporation and/or its subsidiary(-ies).
* All rights reserved.
* This component and the accompanying materials are made available
* under the terms of the License "Eclipse Public License v1.0"
* which accompanies this distribution, and is available
* at the URL "http://www.eclipse.org/legal/epl-v10.html".
*
* Initial Contributors:
* Nokia Corporation - initial contribution.
*
* Contributors:
*
* Description:  
*
*/
#ifndef _MEMORYMANAGER_H_
#define _MEMORYMANAGER_H_

//  INCLUDES
#include <e32std.h>
#include <e32base.h>

// CONSTANTS

// MACROS
//

// DATA TYPES
enum TOOMCheckResult
    {
    ENoOOM          = 0x0000,   // no oom
    ECheckOOM       = 0x0001,   // last memory check failed
    EUserAllocOOM   = 0x0002,   // system heap allocation failed
    ERescueOOM      = 0x0004,   // rescue buffer allocation failed
    ECollecting     = 0x0010,   // memory manager is collecting memory
    EStopping       = 0x0020    // memory menager is stopping operations 
    };

// simulate OOM, for debugging purpose
enum TOOMType
    {
    EOOM_None   =   0x0000,
    EOOM_Heap1 =    0x0001, // fail the first heap allocation
    EOOM_Heap2 =    0x0003, // fail the second heap allocation, after collection
    EOOM_Rescue =   0x0007  // fail the rescue allocation
    };

enum TOOMPriority
    {
    EOOM_PriorityLow    = 0,
    EOOM_PriorityMiddle,
    EOOM_PriorityHigh,
    EOOM_PriorityCritical
    };

// FUNCTION PROTOTYPES

// FORWARD DECLARATIONS
class CAllocator;
class FunctionLogger;

// CLASS DECLARATION

/**
*
*  @lib memman.lib
*  @since 3.1
*/
class MMemoryCollector
    {
    public: // New functions
        /**
        * Collect free memory, this function is called when allocation from 
        * System heap fails
        * @since 3.1
        * @param amount of memory needs to be collected
        * @return amount of memory collected
        */
        virtual TUint Collect(TUint aRequired) = 0;
        
        /**
        * restore the entity controlled memory collector when there is enough memory
        * System heap fails
        * @since 3.1
        * @param
        * @return
        */
        virtual void Restore() = 0;
        
        /**
        * Priority of this collector, 0 - lowest, 10 - highest;
        * the lower the priority, the earlier this collector is executed.
        * @since 3.1
        * @param
        * @return
        */
        virtual TOOMPriority Priority() = 0;
    };

/**
*
*  @lib memman.lib
*  @since 3.1
*/
class MOOMStopper
    {
    public:  // New functions
        /**
        * Stop currently on-going operations, called by the allocator
        * @since 3.1
        * @param
        * @return
        */  
        virtual void Stop() = 0;
        
        /**
        * return the priority of this stopper (1-100), allocator expects this value 
        * to determine the stopping order.  The higher the priority is, the sooner
        * this stopper will be called.
        * @since 3.1
        * @param 
        * @return
        */  
        virtual TOOMPriority Priority() = 0;
    };

/**
*
*  @lib memman.lib
*  @since 3.1
*/
class MOOMNotifier
    {
    public: // New functions
        /**
        * client provided notifying utility function, called by the allocator 
        * to inform the user
        * @since 3.1
        * @param
        * @return
        */
        virtual TInt Notify() = 0;
    };

/**
*  A class handles all memory operations and OOM issues
*  @lib memman.lib
*  @since 3.1
*/
class MemoryManager
    {
    public:           
        /**
        * register a memory collector, memory manager doesn't own this collector
        * @since 3.1
        * @param aCollector the collector to be registered
        * @param 
        * @return 
        */
        IMPORT_C static void AddCollector( MMemoryCollector* aCollector );
    
        /**
        * unregister a memory collector
        * @since 3.1
        * @param aCollector the collector to be unregistered
        * @param 
        * @return 
        */
        IMPORT_C static void RemoveCollector( MMemoryCollector* aCollector );
        
        /**
        * register a stopper, memory manager doesn't own this stopper.
        * @since 3.1
        * @param aStopper the stopper to be registered
        * @param 
        * @return 
        */
        IMPORT_C static void AddStopper( MOOMStopper* aStopper );
    
        /**
        * unregister a stopper
        * @since 3.1
        * @param aStopper the stopper to be unregistered
        * @param 
        * @return 
        */
        IMPORT_C static void RemoveStopper( MOOMStopper* aStopper );
        
        /**
        * set the OOM notifier, memory manager doesn't own this notifier
        * @since 3.1
        * @param aNotifier the notifier
        * @param 
        * @return 
        */
        IMPORT_C static void SetNotifier( MOOMNotifier* aNotifier );
            
        /**
        * check if the memory manager is able to reserve enough memory for the coming operation.
        * @since 3.1
        * @param aTotalSize total amount of memory
        * @param aMaxBufSizse the biggest contiguous memory buffer
        * @param aChecker the name of operation
        * @return result of prechecking, ETrue = successful
        */
        IMPORT_C static TBool PreCheck( TUint aTotalSize, TUint aMaxBufSize, const TDesC8& aChecker=KNullDesC8 );
    
        /**
        * An additional check after an operation is completed. 
        * @since 3.1
        * @param 
        * @param
        * @return the status of memory during this operation.
        */
        IMPORT_C static TUint PostCheck();
    
        /**
        * Get the status of memory manager, specific state could be retrieve by AND (&) operator
        * with TOOMCheckResult enum
        * @since 3.1
        * @param 
        * @param
        * @return the status of memory during this operation.
        */
        IMPORT_C static TUint Status();
                
        /**
        * Trigger an OOM event, this function is only for debugging purpose
        * @since 3.1
        * @param aType defines where memory allocation fails
        * @param
        * @return
        */
        IMPORT_C static void SetStatus( TOOMCheckResult aType = ENoOOM );

        /**
        * Prepare Memory manager for the coming application exit.
        * @since 3.1
        * @param
        * @param
        * @return
        */
        IMPORT_C static void PrepareForExit();

        /**
        * Free some RAM. Calls collect on registered collectors
        * @since 3.1
        * @param
        * @param
        * @return
        */
        IMPORT_C static void FreeRam();

        /**
        * Called when application is no longer in OOM situation.
        * @since 3.1
        * @param
        * @param
        * @return
        */
        IMPORT_C static void RestoreCollectors();

        /**
        * Called when application wants to change the rescue buffer size
        * @since 3.1
        * @param
        * @param
        * @return
        */
        IMPORT_C static void SetRescueBufferSize(TInt aSize);

        /**
        * retrieve the size of an allocated memory cell
        * @since 3.1
        * @param
        * @param
        * @return
        */
        IMPORT_C static TUint MemorySize(TAny* aPtr);

        /**
        * switch to the allocator using fast dlmalloc
        * @since 3.1
        * @param
        * @param
        * @return
        */
        IMPORT_C static RAllocator* SwitchToFastAllocator();

        /**
        * switch to the default allocator provided by Symbian OS,
        * and close the current fast allocator.
        * @since 3.1
        * @param
        * @param
        * @return
        */
        IMPORT_C static void CloseFastAllocator(RAllocator* aDefaultAllocator);

        /**
        * Create fast allocator and switch as default heap. Special case if fast allocator
        * has to be created from SetupThreadHeap().
        * 
        * @since 9.2
        * @param
        * @return
        */        
        IMPORT_C static void MemoryManager::CreateFastAllocator();

        /**
        * Initialize MemoryManager library. Special case if CreateFastAllocator is
        * called from SetupThreadHeap().
        * 
        * @since 9.2
        * @param
        * @return
        */
        IMPORT_C static void MemoryManager::InitFastAllocator();

        /**
        * initialize the OOM handler in the memorypool
        * @since 9.2
        * @param
        * @param
        * @return
        */
        IMPORT_C static void InitOOMDialog();

        /**
        * Reset the OOM dialog display flag in the memorypool; we want to pop the OOM dialog once per page,
        * so we need to clear this when we are either done with the page (it unloads) or when we load a new one,
        * so that it will display again when we run out of memory
        * @since 9.2
        * @param
        * @param
        * @return
        */
        IMPORT_C static void ResetOOMDialogDisplayed();
        
    };

#endif// !_MEMORYMANAGER_H_
