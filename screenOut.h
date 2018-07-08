/* Name : scrrenOut.h ver 1.0
 * Content : Declaration for console output
 * Imlemetation : CHOI WOOSUK
 *
 * Last modified : 2018/07/06
 */

#ifndef SCREENOUT_H_INCLUDED
#define SCREENOUT_H_INCLUDED
#include "phoneData.h"

void ShowMenu(void);
void ShowPhoneInfo(phoneData phone);
void ShowPhoneInfoByPtr(phoneData* pPhone);

#endif // SCREENOUT_H_INCLUDED
