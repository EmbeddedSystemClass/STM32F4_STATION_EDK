/*
�������� ������� ������ �������
*/

#include <LPC23xx.h>                 /* LPC23xx/24xx definitions             */
#include "Counters.h"
#include "Depth.h"

//****************************************************************************
// ����������� ��������� 

//****************************************************************************
// ������� ����������	

//****************************************************************************
// ���������� ���������� ��������� �����
long korrFactor = KORR_FACTOR_BASE;
long baseDepth = 0;	 // mm
long depthStep = 0;	 // mm
long speed = 0;		 // mm/min
long labelDepth = 0;	// mm
//****************************************************************************
// ���������� ���������� ����������� �����������

//****************************************************************************
// ��������� ������������������ ������� � �����������
long getDepthInCm (void)
{
	long long temp = getCounterValue();
	// 100 �� = 1 �
	return ((baseDepth / 10) + (long)(temp * korrFactor / KORR_FACTOR_MODUL * 100 / PULSE_ON_METER));	
}

// ��������� ������������������ ������� � ����������
long getDepthInMm (void)
{
	long long temp = getCounterValue();
	// 1000 �� = 1 �
	return (baseDepth + (long)(temp * korrFactor / KORR_FACTOR_MODUL * 1000 / PULSE_ON_METER));	
}

// ��������� ������������������ ������� � ����������
void setDepthInMm (long val)
{
	countersReset();
	baseDepth = val;
}

