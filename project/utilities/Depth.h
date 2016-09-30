#ifndef _DEPTH_H__INCLUDED_
#define _DEPTH_H__INCLUDED_

#define PULSE_ON_METER		500		// количество импульсов датчика на метр глубины

// базовое значение корректор-фактора (* 100000)
// для получения истинного значения надо разделить на 100000! 
//(сделано для работы в целочисленной арифметике и для совместимости со старым блоком)
#define KORR_FACTOR_MODUL	100000 
#define KORR_FACTOR_BASE	1 * KORR_FACTOR_MODUL	

long getDepthInCm (void);
long getDepthInMm (void);
void setDepthInMm (long val);

#endif
