/*
Основные функции модуля глубины
*/

#include <LPC23xx.h>                 /* LPC23xx/24xx definitions             */
#include "Counters.h"
#include "Depth.h"

//****************************************************************************
// именованные константы 

//****************************************************************************
// внешние переменные	

//****************************************************************************
// глобальные переменные доступные извне
long korrFactor = KORR_FACTOR_BASE;
long baseDepth = 0;	 // mm
long depthStep = 0;	 // mm
long speed = 0;		 // mm/min
long labelDepth = 0;	// mm
//****************************************************************************
// глобальные переменные внутреннего пользования

//****************************************************************************
// получение откорректированной глубины в сантиметрах
long getDepthInCm (void)
{
	long long temp = getCounterValue();
	// 100 см = 1 м
	return ((baseDepth / 10) + (long)(temp * korrFactor / KORR_FACTOR_MODUL * 100 / PULSE_ON_METER));	
}

// получение откорректированной глубины в милиметрах
long getDepthInMm (void)
{
	long long temp = getCounterValue();
	// 1000 мм = 1 м
	return (baseDepth + (long)(temp * korrFactor / KORR_FACTOR_MODUL * 1000 / PULSE_ON_METER));	
}

// получение откорректированной глубины в милиметрах
void setDepthInMm (long val)
{
	countersReset();
	baseDepth = val;
}

