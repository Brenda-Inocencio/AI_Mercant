#ifndef IA_TRAINING_
#define IA_TRAINING_


#include <iostream>
#include <cmath>
#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>

struct TrainingAim {
	float Profit;			// Bénéfice du jour
	float CustomersWin;		// Nombre de client gagné (par jour) 
	float CustomersLose;	// Nombre de client perdu (par jour) 
	float StockLose;		// Stock perdu
	float ProfitTooHigh;	// Prix trop haut
};

class Training{
private:
	std::vector<TrainingAim> m_history;

	// Setting know
	float m_priceAdjustment;		// Influence on price
	float m_productionAdjustement;	// Influence on production
	float m_orderAdjustment;		//Influence on order

	// Methode interne
	float computeAverageProfit();			// Compute Profit
	float computeAverageCustomersLose();	// Compute CustomersLose
	float computeAverageStockLose();		// Compute StockLose
		
public:
	Training();

	// Call every evening for record the day
	void addSample(const TrainingAim& sample);

	// Update AI setting ( price, command, production, ...) 
	void updateLeaning();

	//
	void getPriceAdjustment() const { std::cout << m_priceAdjustment; }
	void getProductionAdjustment() const { std::cout << m_productionAdjustement; }
	void getOrderAdjustemnt() const { std::cout << m_orderAdjustment; }

	~Training();
};

#endif // 