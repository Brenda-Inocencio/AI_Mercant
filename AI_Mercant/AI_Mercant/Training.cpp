#include "Training.h"
#include <numeric>

Training::Training() 
	: m_priceAdjustment(0.f), 
	m_productionAdjustement(0.f), 
	m_orderAdjustment(0.f) 
{}

void Training::addSample(const TrainingAim& sample) {
	m_history.push_back(sample);

	// On limite l’historique pour éviter la dérive
	if (m_history.size() > 30) {
		m_history.erase(m_history.begin());
	}
}

float Training::computeAverageProfit() {
	if (m_history.empty()) return 0.f;
	float sum = 0.f;
	for (auto& s : m_history) sum += s.Profit; 
	return sum / m_history.size();
}

float Training::computeAverageCustomersLose() {
	if (m_history.empty()) return 0.f;
	float sum = 0.f;
	for (auto& s : m_history) sum += s.CustomersLose;
	return sum / m_history.size();
}

float Training::computeAverageStockLose() {
	if (m_history.empty()) return 0.f;
	float sum = 0.f;
	for (auto& s : m_history) sum += s.StockLose;
	return sum / m_history.size();
}


void Training::updateLeaning() {
	float avgProfit = computeAverageProfit();
	float avgCustomersLose = computeAverageCustomersLose();
	float avgStockLose = computeAverageStockLose();
	
	// Too much stock lost ? produce less
	m_productionAdjustement = -avgStockLose * 0.5f;

	// Too many missed sales ? produce more
	m_productionAdjustement += avgStockLose * 0.5f;

	// If the profit is low but there is no shortage ? price too low
	if (avgProfit < 50 && avgCustomersLose == 0) {
		m_priceAdjustment += 0.02f;
	}

	// If prices were too high ? lower them
	for (auto& s : m_history) {
		m_priceAdjustment -= s.ProfitTooHigh * 0.05f;
	}

	// Adjustment of orders based on production
	m_orderAdjustment = m_productionAdjustement * 0.8f;
}




//####################	IN MERCHANT	###################### 
/*								
class Merchant {													
	void endOfDay() {
		TrainingSample sample;										
		sample.profit = todayProfit;								
		sample.wastedStock = wasted;								
		sample.missedSales = missed;								
		sample.priceTooHigh = (customers == 0 ? 1.f : 0.f);

		training.addSample(sample);
		training.updateLearning();

		// appliquer les ajustements
		basePrice *= (1.f + training.getPriceAdjustment());
		productionGoal += training.getProductionAdjustment();
		orderQuantity += training.getOrderAdjustment();
	}

private:
	Training training;
};

*/