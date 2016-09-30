#ifndef _DEPTH_H__INCLUDED_
#define _DEPTH_H__INCLUDED_

#define PULSE_ON_METER		500		// ���������� ��������� ������� �� ���� �������

// ������� �������� ���������-������� (* 100000)
// ��� ��������� ��������� �������� ���� ��������� �� 100000! 
//(������� ��� ������ � ������������� ���������� � ��� ������������� �� ������ ������)
#define KORR_FACTOR_MODUL	100000 
#define KORR_FACTOR_BASE	1 * KORR_FACTOR_MODUL	

long getDepthInCm (void);
long getDepthInMm (void);
void setDepthInMm (long val);

#endif
