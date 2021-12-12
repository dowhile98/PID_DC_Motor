
#include "getBuffPtr.h"

/*******************************************************************************
* Function Name  : getBuffPtr
* Description    : Return buffer address. This function is called from MATLAB script
*                  using coder.ceval('getBuffPtr',coder.rref(buffer))
*                  to get buffer address to send
* Input          : buffPtr
*******************************************************************************/
uint32_t getBuffPtr(const void * buffPtr)
{
    return ((uint32_t)buffPtr);
}
