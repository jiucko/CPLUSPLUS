#pragma once
#include "CTP_API/ThostFtdcMdApi.h"


class CustomMdSpi : public CThostFtdcMdSpi
{
public:
	CustomMdSpi(Trader& t);
	~CustomMdSpi() = default;

public:
	virtual void OnFrontConnected();
	
private:
	Trader& m_treader;
};