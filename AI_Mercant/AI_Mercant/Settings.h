#pragma once

class Settings {
	int numberMerchants;
	int numberMerchantsType;
public:
	Settings(int _numberMerchants, int _numberMerchantsType);
	~Settings() {};
	inline int GetNumberMerchants() { return numberMerchants; }
	inline int GetNumberMerchantsType() { return numberMerchantsType; }
};

class settings
{
};

